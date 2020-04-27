/****************************************************************************
 *
 *   Copyright (c) 2015-2020 Amov Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file ckf.cpp
 * Implementation of the attitude and position estimator.
 *
 * @author Abner
 */

#include <float.h>

/*add the head file about ckf lib*/
#include "lib/INS.h"

#include <drivers/drv_hrt.h>
#include <px4_defines.h>
#include <px4_module.h>
#include <px4_module_params.h>
#include <px4_posix.h>
#include <px4_platform_common/px4_work_queue/ScheduledWorkItem.hpp>
#include <px4_time.h>
#include <matrix/math.hpp>
#include <uORB/Publication.hpp>
#include <uORB/PublicationMulti.hpp>
#include <uORB/Subscription.hpp>
#include <uORB/SubscriptionCallback.hpp>
#include <uORB/topics/airspeed.h>
#include <uORB/topics/distance_sensor.h>
#include <uORB/topics/ekf2_innovations.h>
#include <uORB/topics/ekf2_timestamps.h>
#include <uORB/topics/ekf_gps_position.h>
#include <uORB/topics/estimator_status.h>
#include <uORB/topics/ekf_gps_drift.h>
#include <uORB/topics/landing_target_pose.h>
#include <uORB/topics/optical_flow.h>
#include <uORB/topics/parameter_update.h>
#include <uORB/topics/sensor_bias.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/sensor_selection.h>
#include <uORB/topics/vehicle_air_data.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_global_position.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_land_detected.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_magnetometer.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/vehicle_status.h>
#include <uORB/topics/wind_estimate.h>

using matrix::Quatf;
using matrix::Vector3f;

#define RAD2DEG  (57.2957795131f)
#define DEG2RAD  (0.01745329252f)

extern "C" __EXPORT int ckf_main(int argc, char *argv[]);

// define max number of GPS receivers supported and 0 base instance used to access virtual 'blended' GPS solution
#define GPS_MAX_RECEIVERS 2
#define GPS_BLENDED_INSTANCE 2

class cKF final : public ModuleBase<cKF>, public ModuleParams, public px4::WorkItem
{
public:
	cKF();
	~cKF();
	/** @see ModuleBase */
	static int task_spawn(int argc, char *argv[]);

	/** @see ModuleBase */
	static int custom_command(int argc, char *argv[]);

	/** @see ModuleBase */
	static int print_usage(const char *reason = nullptr);

	void Run() override;

	bool init();

	int print_status() override;

private:
	void setGpsValue(uBlox_PVT_Bus *gpsData);
	void setImuValue(IMU_Bus *imuData);
	void setBaroValue(MS5611_Bus *baroData);
	void setCompassValue(Mag_Bus *magData);
	void getCkfOutPuts(ExternalOutputs_INS_T *output);
	perf_counter_t _ckf_update_perf;

	uint8_t _arm_last_state = 0;

       /*baro data*/
	float _amov_balt_data_sum = 0.0f;			///< summed pressure altitude readings (m)
	float _amov_balt_data_pressure = 0.0f;
	uint64_t _amov_balt_time_sum_ms = 0;		///< summed pressure altitude time stamps (mSec)
	uint8_t _amov_balt_sample_count = 0;		///< number of barometric altitude measurements summed
	uint32_t _amov_balt_time_ms_last_used = 0;

       /*compass data*/
	float _amov_mag_data_sum[3] = {};			///< summed magnetometer readings (Gauss)
	uint64_t _amov_mag_time_sum_ms = 0;		///< summed magnetoemter time stamps (mSec)
	uint8_t _amov_mag_sample_count = 0;		///< number of magnetometer measurements summed during downsampling
	int32_t _amov_mag_time_ms_last_used = 0;

	INSModelClass ckfInsFilter = {};
	uORB::SubscriptionCallbackWorkItem _sensors_sub{this, ORB_ID(sensor_combined)};
	uORB::Subscription _magnetometer_sub{ORB_ID(vehicle_magnetometer)};
	uORB::Subscription _airdata_sub{ORB_ID(vehicle_air_data)};
	// because we can have multiple GPS instances
	uORB::Subscription _gps_subs[GPS_MAX_RECEIVERS] {{ORB_ID(vehicle_gps_position), 0}, {ORB_ID(vehicle_gps_position), 1}};
	uORB::Subscription _status_sub{ORB_ID(vehicle_status)};

	vehicle_status_s		_vehicle_status{};
	vehicle_global_position_s 	_global_pos{};
	vehicle_local_position_s 	_lpos{};

	// publish the output msg
	// uORB::Publication<estimator_status_s>			_estimator_status_pub{ORB_ID(estimator_status)};
	uORB::Publication<vehicle_attitude_s>			_att_pub{ORB_ID(vehicle_attitude)};
	uORB::PublicationData<vehicle_global_position_s>	_vehicle_global_position_pub{ORB_ID(vehicle_global_position)};
	uORB::PublicationData<vehicle_local_position_s>		_vehicle_local_position_pub{ORB_ID(vehicle_local_position)};
};

cKF::cKF():
	ModuleParams(nullptr),
	WorkItem(MODULE_NAME, px4::wq_configurations::att_pos_ctrl),
	_ckf_update_perf(perf_alloc_once(PC_ELAPSED, MODULE_NAME": update"))
{
	// initialise parameter cache
	updateParams();
	ckfInsFilter.initialize();
}

cKF::~cKF()
{
	perf_free(_ckf_update_perf);
}

int cKF::print_status()
{
	// PX4_INFO("local position: %s", (_ekf.local_position_is_valid()) ? "valid" : "invalid");
	// PX4_INFO("global position: %s", (_ekf.global_position_is_valid()) ? "valid" : "invalid");

	// PX4_INFO("time slip: %" PRId64 " us", _last_time_slip_us);
	PX4_INFO("ckf print_status");
	perf_print_counter(_ckf_update_perf);

	return 0;
}

int cKF::custom_command(int argc, char *argv[])
{
	return print_usage("unknown command");
}

int cKF::print_usage(const char *reason)
{
	if (reason) {
		PX4_WARN("%s\n", reason);
	}

	PRINT_MODULE_DESCRIPTION(
		R"DESCR_STR(
### Description
Attitude and position estimator using an Compensation Kalman Filter. It is used for Multirotors")DESCR_STR");

	PRINT_MODULE_USAGE_NAME("ckf", "estimator");
	PRINT_MODULE_USAGE_COMMAND("start");
	PRINT_MODULE_USAGE_DEFAULT_COMMANDS();
	return 0;
}

int cKF::task_spawn(int argc, char *argv[])
{
	cKF *instance = new cKF();

	if (instance) {
		_object.store(instance);
		_task_id = task_id_is_work_queue;

		if (instance->init()) {
			return PX4_OK;
		}

	} else {
		PX4_ERR("alloc failed");
	}

	delete instance;
	_object.store(nullptr);
	_task_id = -1;

	return PX4_ERROR;
}

bool cKF::init()
{
	if (!_sensors_sub.registerCallback()) {
		PX4_ERR("sensor combined callback registration failed!");
		return false;
	}

	return true;
}

void cKF::Run()
{
	if (should_exit()) {
		_sensors_sub.unregisterCallback();
		exit_and_cleanup();
		return;
	}

	sensor_combined_s sensors;
	ExternalOutputs_INS_T ckfOutPutValue;

	if (_sensors_sub.update(&sensors)) {

		IMU_Bus IMU_Data{};
		/*Update 250 HZ*/
		IMU_Data.timestamp_ms = sensors.timestamp * 1E-3;
		IMU_Data.acc_x_mPs2_B = sensors.accelerometer_m_s2[0];
		IMU_Data.acc_y_mPs2_B = sensors.accelerometer_m_s2[1];
		IMU_Data.acc_z_mPs2_B = sensors.accelerometer_m_s2[2];

		IMU_Data.gyr_x_radPs_B = sensors.gyro_rad[0];
		IMU_Data.gyr_y_radPs_B = sensors.gyro_rad[1];
		IMU_Data.gyr_z_radPs_B = sensors.gyro_rad[2];

                setImuValue(&IMU_Data);

		const hrt_abstime now = sensors.timestamp;

                // read mag data
		if (_magnetometer_sub.updated()) {
                       vehicle_magnetometer_s magnetometer;
			if (_magnetometer_sub.copy(&magnetometer)) {
	                        /*update the mag data, 100hz*/
				_amov_mag_time_sum_ms += magnetometer.timestamp / 1000;
				_amov_mag_sample_count++;
				_amov_mag_data_sum[0] += magnetometer.magnetometer_ga[0];
				_amov_mag_data_sum[1] += magnetometer.magnetometer_ga[1];
				_amov_mag_data_sum[2] += magnetometer.magnetometer_ga[2];
				int32_t amov_mag_time_ms = _amov_mag_time_sum_ms / _amov_mag_sample_count;

				if ((amov_mag_time_ms - _amov_mag_time_ms_last_used) >= 10) {
					float mag_sample_count_inv = 1.0f / _amov_mag_sample_count;
					Mag_Bus amovMagData{};
					amovMagData.timestamp_ms  = hrt_absolute_time() * 1E-3;
					amovMagData.mag_x_ga_B = _amov_mag_data_sum[0] * mag_sample_count_inv;
					amovMagData.mag_y_ga_B = _amov_mag_data_sum[1] * mag_sample_count_inv;
					amovMagData.mag_z_ga_B = _amov_mag_data_sum[2] * mag_sample_count_inv;

					setCompassValue(&amovMagData);

					_amov_mag_time_ms_last_used = amov_mag_time_ms;
					_amov_mag_time_sum_ms = 0;
					_amov_mag_sample_count = 0;
					_amov_mag_data_sum[0] = 0.0f;
					_amov_mag_data_sum[1] = 0.0f;
					_amov_mag_data_sum[2] = 0.0f;
				}
			}

		}

		if (_airdata_sub.updated()) {
			vehicle_air_data_s airdata;
			if (_airdata_sub.copy(&airdata)) {
				/*update the baro data, 100hz*/
				_amov_balt_time_sum_ms += airdata.timestamp / 1000;
				_amov_balt_sample_count ++;
				_amov_balt_data_sum += airdata.baro_alt_meter;
				_amov_balt_data_pressure += airdata.baro_pressure_pa;
				uint32_t amov_balt_time_ms = _amov_balt_time_sum_ms / _amov_balt_sample_count;

				if (amov_balt_time_ms - _amov_balt_time_ms_last_used >= (uint32_t)10) {
					// float amov_balt_data_avg = _amov_balt_data_sum/(float)_amov_balt_sample_count;
					float amov_balt_data_pressure_avg = _amov_balt_data_pressure/(float)_amov_balt_sample_count;

					MS5611_Bus amovBaroData{};

					amovBaroData.timestamp_ms   = hrt_absolute_time() * 1E-3;
					amovBaroData.pressure_pa = amov_balt_data_pressure_avg;
					amovBaroData.temperature_deg    = airdata.baro_temp_celcius;

					setBaroValue(&amovBaroData);

					_amov_balt_time_ms_last_used = amov_balt_time_ms;
					_amov_balt_time_sum_ms = 0;
					_amov_balt_sample_count = 0;
					_amov_balt_data_sum = 0.0f;
					_amov_balt_data_pressure = 0.0;
				}
			}
		}

		// read gps1 data if available
		bool gps1_updated = _gps_subs[0].updated();
		static vehicle_gps_position_s gps{};
		if (gps1_updated)
		{
			if (_gps_subs[0].copy(&gps)) {
				/*amov record gps info 10hz*/
				uBlox_PVT_Bus amovGpsData{};
				amovGpsData.timestamp_ms = hrt_absolute_time() * 1E-3;
				amovGpsData.valid   = (gps.fix_type > 3)&& (gps.satellites_used > 7);
				amovGpsData.fixType = gps.fix_type;
				amovGpsData.flags   = (gps.fix_type > 3)&& (gps.satellites_used > 7) && (gps.noise_per_ms < 10);
				amovGpsData.numSV   = gps.satellites_used;
				amovGpsData.lon     = gps.lon;
				amovGpsData.lat     = gps.lat;
				amovGpsData.height  = gps.alt;
				amovGpsData.velN    = gps.vel_n_m_s;
				amovGpsData.velE    = gps.vel_e_m_s;
				amovGpsData.velD    = gps.vel_d_m_s;
				amovGpsData.pDOP    = gps.hdop;
				amovGpsData.hAcc    = gps.eph * 1000.0f;
				amovGpsData.vAcc    = gps.epv * 1000.0f;
				amovGpsData.sAcc    = gps.s_variance_m_s * 1000.0f;
				setGpsValue(&amovGpsData);

			}

		}

		// run the cKF update and output
		perf_begin(_ckf_update_perf);
		ckfInsFilter.step();
		perf_end(_ckf_update_perf);

		// get the ckf outputs
		getCkfOutPuts(&ckfOutPutValue);

		bool status_updated = _status_sub.updated();
		if (status_updated)
		{
			_status_sub.copy(&_vehicle_status);
		}

		// // publish estimator status
		// estimator_status_s status;
		// status.timestamp = now;
		// status.n_states = 24;
		// status.pre_flt_fail_innov_heading = false;
		// status.pre_flt_fail_innov_vel_horiz = false;
		// status.pre_flt_fail_innov_vel_vert = false;
		// status.pre_flt_fail_innov_height = false;
		// status.health_flags = 0.0f; // unused
		// status.timeout_flags = 0.0f; // unused
		// _estimator_status_pub.publish(status);


		//publish attitude
		vehicle_attitude_s att;
		att.timestamp = now;
		Quatf q = Quatf(1.0f, 0.0f, 0.0f, 0.0f);
		q.from_axis_angle(Vector3f(ckfOutPutValue.INS_Out.phi,ckfOutPutValue.INS_Out.theta,ckfOutPutValue.INS_Out.psi));
		q.copyTo(att.q);
		_att_pub.publish(att);

		// publish global position
		_global_pos.timestamp = now;
		_global_pos.lat = ckfOutPutValue.INS_Out.latitude * RAD2DEG;
		_global_pos.lon = ckfOutPutValue.INS_Out.longitude * RAD2DEG;
		_global_pos.alt = ckfOutPutValue.INS_Out.altitude;

		_global_pos.vel_n = ckfOutPutValue.INS_Out.velN;
		_global_pos.vel_e = ckfOutPutValue.INS_Out.velE;
		_global_pos.vel_d = -ckfOutPutValue.INS_Out.velD;
		_global_pos.yaw = ckfOutPutValue.INS_Out.psi;
		_global_pos.eph = gps.eph;
		_global_pos.epv = gps.epv;

		_vehicle_global_position_pub.publish(_global_pos);


		// generate and publish vehicle's local position data
		_lpos.timestamp = now;
		_lpos.xy_valid = (ckfOutPutValue.INS_Out.flags & (0x1 << 4));
		_lpos.z_valid = (ckfOutPutValue.INS_Out.flags & (0x1 << 5));
		_lpos.v_xy_valid = (ckfOutPutValue.INS_Out.flags & (0x1 << 3));
		_lpos.v_z_valid = (ckfOutPutValue.INS_Out.flags & (0x1 << 5));

		_lpos.x = ckfOutPutValue.INS_Out.x_R_m;
		_lpos.y = ckfOutPutValue.INS_Out.y_R_m;
		_lpos.z = -ckfOutPutValue.INS_Out.h_R_m;

		_lpos.vx = ckfOutPutValue.INS_Out.velN;
		_lpos.vy = ckfOutPutValue.INS_Out.velE;
		_lpos.vz = -ckfOutPutValue.INS_Out.velD;
		_lpos.z_deriv = NAN;

		_lpos.ax = ckfOutPutValue.INS_Out.sfor_x;
		_lpos.ay = ckfOutPutValue.INS_Out.sfor_y;
		_lpos.az = ckfOutPutValue.INS_Out.sfor_z - 9.8f;

		_lpos.yaw = ckfOutPutValue.INS_Out.psi;
		_lpos.xy_global = (ckfOutPutValue.INS_Out.flags & (0x1 << 4));
		_lpos.z_global = (ckfOutPutValue.INS_Out.flags & (0x1 << 5));
			// record the last status on groud
		if ((_vehicle_status.arming_state == vehicle_status_s::ARMING_STATE_ARMED)
		&& (_arm_last_state == vehicle_status_s::ARMING_STATE_INIT))
		{
			_lpos.ref_timestamp = now;
			_lpos.ref_lat = ckfOutPutValue.INS_Out.latitude * RAD2DEG;
			_lpos.ref_lon = ckfOutPutValue.INS_Out.longitude * RAD2DEG;
			_lpos.ref_alt = gps.alt;
		}
		_lpos.eph = gps.eph;
		_lpos.epv = gps.epv;


		_vehicle_local_position_pub.publish(_lpos);
	// printf("_lpos.xy_valid:%d,_lpos.z_valid:%d\n",_lpos.xy_valid,_lpos.z_valid);
	// printf("_lpos.lat:%f lon:%f gps lat:%d lon:%d \n",(double)_global_pos.lat,(double)_global_pos.lon,gps.lat,gps.lon);
		_arm_last_state = _vehicle_status.arming_state;

	}

}

void cKF::setGpsValue(uBlox_PVT_Bus *gpsData)
{
	memcpy(&ckfInsFilter.INS_U.GPS_uBlox,gpsData,sizeof(uBlox_PVT_Bus));
}

void cKF::setImuValue(IMU_Bus *imuData)
{
	memcpy(&ckfInsFilter.INS_U.IMU,imuData,sizeof(IMU_Bus));
}

void cKF::setBaroValue(MS5611_Bus *baroData)
{
	memcpy(&ckfInsFilter.INS_U.MS5611,baroData,sizeof(MS5611_Bus));
}

void cKF::setCompassValue(Mag_Bus *magData)
{
	memcpy(&ckfInsFilter.INS_U.Mag,magData,sizeof(Mag_Bus));
}

void cKF::getCkfOutPuts(ExternalOutputs_INS_T *output)
{
	memcpy(&output->INS_Out.timestamp_ms,&ckfInsFilter.INS_Y.INS_Out.timestamp_ms,sizeof(ExternalOutputs_INS_T));
}

int ckf_main(int argc, char *argv[])
{
	return cKF::main(argc, argv);
}
