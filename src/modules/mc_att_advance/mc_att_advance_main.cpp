
/**
 * @file mc_att_advance_main.cpp
 * Multicopter attitude controller.
 *
 * @author abner		<huangwenfuture@sina.com>
 *
 */
#include "mc_att_advance.hpp"
#include <drivers/drv_hrt.h>
#include <lib/ecl/geo/geo.h>
#include <mathlib/math/Functions.hpp>

using namespace matrix;

MulticopterAttitudeAdvanceControl::MulticopterAttitudeAdvanceControl() :
	_loop_perf(perf_alloc(PC_ELAPSED, "mc_att_advance"))
{
	for (uint8_t i = 0; i < MAX_GYRO_COUNT; i++) {
		_sensor_gyro_sub[i] = -1;
	}

	_thrust_sp = 0.0f;
}

int MulticopterAttitudeAdvanceControl::print_usage(const char *reason)
{
	if (reason) {
		PX4_WARN("%s\n", reason);
	}

	PRINT_MODULE_USAGE_NAME("mc_att_advance", "controller");
	PRINT_MODULE_USAGE_COMMAND("start");
	PRINT_MODULE_USAGE_DEFAULT_COMMANDS();

	return 0;
}

void
MulticopterAttitudeAdvanceControl::vehicle_attitude_poll()
{
	/* check if there is a new message */
	bool updated;
	orb_check(_v_att_sub, &updated);

	if (updated) {
		orb_copy(ORB_ID(vehicle_attitude), _v_att_sub, &_v_att);
	}
}

void
MulticopterAttitudeAdvanceControl::vehicle_control_mode_poll()
{
	bool updated;

	/* Check if vehicle control mode has changed */
	orb_check(_v_control_mode_sub, &updated);

	if (updated) {
		orb_copy(ORB_ID(vehicle_control_mode), _v_control_mode_sub, &_v_control_mode);
	}
}

void
MulticopterAttitudeAdvanceControl::vehicle_attitude_setpoint_poll()
{
	/* check if there is a new setpoint */
	bool updated;
	orb_check(_v_att_sp_sub, &updated);

	if (updated) {
		orb_copy(ORB_ID(vehicle_attitude_setpoint), _v_att_sp_sub, &_v_att_sp);
	}
}
void
MulticopterAttitudeAdvanceControl::sensor_correction_poll()
{
	/* check if there is a new message */
	bool updated;
	orb_check(_sensor_correction_sub, &updated);

	if (updated) {
		orb_copy(ORB_ID(sensor_correction), _sensor_correction_sub, &_sensor_correction);
	}

	/* update the latest gyro selection */
	if (_sensor_correction.selected_gyro_instance < _gyro_count) {
		_selected_gyro = _sensor_correction.selected_gyro_instance;
	}
}

Vector3f
MulticopterAttitudeAdvanceControl::get_rates_pid()
{
	Vector3f rates_pid(pid_control.PID_Y.Control_Output_e.u_x, pid_control.PID_Y.Control_Output_e.u_y,
			   pid_control.PID_Y.Control_Output_e.u_z);
	return rates_pid;
}

void
MulticopterAttitudeAdvanceControl::actuator_controls_publish()
{

	Vector3f _actuators_PID =  get_rates_pid();
	_actuators.control[0] = (PX4_ISFINITE(_actuators_PID(0))) ? _actuators_PID(0) : 0.0f;
	_actuators.control[1] = (PX4_ISFINITE(_actuators_PID(1))) ? _actuators_PID(1) : 0.0f;
	_actuators.control[2] = (PX4_ISFINITE(_actuators_PID(2))) ? _actuators_PID(2) : 0.0f;
	_actuators.control[3] = (PX4_ISFINITE(_thrust_sp)) ? _thrust_sp : 0.0f;
	_actuators.control[7] = _v_att_sp.landing_gear;
	_actuators.timestamp = hrt_absolute_time();
	_actuators.timestamp_sample = _sensor_gyro.timestamp;

	if (_actuator_controls_pub != nullptr) {
		orb_publish(ORB_ID(actuator_controls_0), _actuator_controls_pub, &_actuators);

	} else if (_actuator_controls_pub == nullptr) {
		_actuator_controls_pub = orb_advertise(ORB_ID(actuator_controls_0), &_actuators);
	}
}

void
MulticopterAttitudeAdvanceControl::att_and_rates_conrtol()
{
	att_rates_input_control(_v_att, _v_att_sp);
	_thrust_sp = _v_att_sp.thrust;
	pid_control.step();
	actuator_controls_publish();
}

void
MulticopterAttitudeAdvanceControl::att_rates_input_control(vehicle_attitude_s vehicle_attitude,
		vehicle_attitude_setpoint_s att_sp)
{
	//assignment the PID_U
	//assignment the att
	if (!_v_control_mode.flag_armed) {
		pid_control.PID_U.Command_m.reset = 1;
	} else {
		pid_control.PID_U.Command_m.reset = 0;
	}
	matrix::Eulerf att_euler(matrix::Quatf(vehicle_attitude.q));
	pid_control.PID_U.States_i.phi_rad = att_euler.phi();
	pid_control.PID_U.States_i.theta_rad = att_euler.theta();
	pid_control.PID_U.States_i.psi_rad = att_euler.psi();

	//assignment the att rates
	pid_control.PID_U.States_i.p_radDs = vehicle_attitude.rollspeed;
	pid_control.PID_U.States_i.q_radDs = vehicle_attitude.pitchspeed;
	pid_control.PID_U.States_i.r_radDs = vehicle_attitude.yawspeed;

	//assignment the att setpointss
	pid_control.PID_U.Reference_e.phi_ref_rad = att_sp.roll_body;
	pid_control.PID_U.Reference_e.theta_ref_rad = att_sp.pitch_body;
	pid_control.PID_U.Reference_e.psi_ref_rad = att_sp.yaw_body;
}

void
MulticopterAttitudeAdvanceControl::run()
{
	/*
	 * do subscriptions
	 */
	_v_att_sub = orb_subscribe(ORB_ID(vehicle_attitude));
	_v_att_sp_sub = orb_subscribe(ORB_ID(vehicle_attitude_setpoint));
	_sensor_correction_sub = orb_subscribe(ORB_ID(sensor_correction));
	_v_control_mode_sub = orb_subscribe(ORB_ID(vehicle_control_mode));

	// sensor correction topic is not being published regularly and we might have missed the first update.
	// so copy it once initially so that we have the latest data. In future this will not be needed anymore as the
	// behavior of the orb_check function will change
	if (_sensor_correction_sub > 0) {
		orb_copy(ORB_ID(sensor_correction), _sensor_correction_sub, &_sensor_correction);
	}

	_gyro_count = math::min(orb_group_count(ORB_ID(sensor_gyro)), MAX_GYRO_COUNT);

	if (_gyro_count == 0) {
		_gyro_count = 1;
	}

	for (unsigned s = 0; s < _gyro_count; s++) {
		_sensor_gyro_sub[s] = orb_subscribe_multi(ORB_ID(sensor_gyro), s);
	}

	/* wakeup source: gyro data from sensor selected by the sensor app */
	px4_pollfd_struct_t poll_fds = {};
	poll_fds.events = POLLIN;

	const hrt_abstime task_start = hrt_absolute_time();
	hrt_abstime last_run = task_start;
	pid_control.initialize();

	while (!should_exit()) {
		// make the choice of the controller, the value is not updated in the air
		int32_t att_controller_choice;
		param_get(param_find("SYS_MC_ATT"), &att_controller_choice);
		if (att_controller_choice != 1 && !_v_control_mode.flag_armed) {
			return;
		}
		poll_fds.fd = _sensor_gyro_sub[_selected_gyro];
		/* wait for up to 100ms for data */
		int pret = px4_poll(&poll_fds, 1, 100);

		/* timed out - periodic check for should_exit() */
		if (pret == 0) {
			continue;
		}

		/* this is undesirable but not much we can do - might want to flag unhappy status */
		if (pret < 0) {
			PX4_ERR("poll error %d, %d", pret, errno);
			/* sleep a bit before next try */
			usleep(100000);
			continue;
		}

		perf_begin(_loop_perf);

		/* run controller on gyro changes */
		if (poll_fds.revents & POLLIN) {

			const hrt_abstime now = hrt_absolute_time();
			float dt = (now - last_run) / 1e6f;
			last_run = now;

			/* guard against too small (< 2ms) and too large (> 20ms) dt's */
			if (dt < 0.002f) {
				dt = 0.002f;

			} else if (dt > 0.02f) {
				dt = 0.02f;
			}

			/* copy gyro data */
			orb_copy(ORB_ID(sensor_gyro), _sensor_gyro_sub[_selected_gyro], &_sensor_gyro);

			// update the data
			vehicle_attitude_poll();
			vehicle_control_mode_poll();
			sensor_correction_poll();
			vehicle_attitude_setpoint_poll();
			att_and_rates_conrtol();
		}

		perf_end(_loop_perf);
	}

	orb_unsubscribe(_v_att_sub);
	orb_unsubscribe(_v_att_sp_sub);
	orb_unsubscribe(_v_control_mode_sub);

	for (unsigned s = 0; s < _gyro_count; s++) {
		orb_unsubscribe(_sensor_gyro_sub[s]);
	}
}

int
MulticopterAttitudeAdvanceControl::task_spawn(int argc, char *argv[])
{
	_task_id = px4_task_spawn_cmd("mc_att_advance",
				      SCHED_DEFAULT,
				      SCHED_PRIORITY_ATTITUDE_CONTROL,
				      1700,
				      (px4_main_t)&run_trampoline,
				      (char *const *)argv);

	if (_task_id < 0) {
		_task_id = -1;
		return -errno;
	}

	return 0;
}

MulticopterAttitudeAdvanceControl *MulticopterAttitudeAdvanceControl::instantiate(int argc, char *argv[])
{
	return new MulticopterAttitudeAdvanceControl();
}

int MulticopterAttitudeAdvanceControl::custom_command(int argc, char *argv[])
{
	return print_usage("unknown command");
}

int mc_att_advance_main(int argc, char *argv[])
{
	return MulticopterAttitudeAdvanceControl::main(argc, argv);
}
