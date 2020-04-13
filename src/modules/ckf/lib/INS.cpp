//
// File: INS.cpp
//
// Code generated for Simulink model 'INS'.
//
// Model version                  : 1.1588
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Wed Jan  8 16:03:19 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "INS.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#include "stdio.h"
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

// #if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
// #error Code was generated for compiler with different sized ulong/long. \
// Consider adjusting Test hardware word size settings on the \
// Hardware Implementation pane to match your compiler word sizes as \
// defined in limits.h of the compiler. Alternatively, you can \
// select the Test hardware is the same as production hardware option and \
// select the Enable portable word sizes option on the Code Generation > \
// Verification pane for ERT based targets, which will disable the \
// preprocessor word size checks.
// #endif

const INS_Out_Bus INS_rtZINS_Out_Bus = {
  0U,                                  // timestamp_ms
  0.0F,                                // phi
  0.0F,                                // theta
  0.0F,                                // psi
  0.0F,                                // p
  0.0F,                                // q
  0.0F,                                // r
  0.0F,                                // sfor_x
  0.0F,                                // sfor_y
  0.0F,                                // sfor_z
  0.0F,                                // velN
  0.0F,                                // velE
  0.0F,                                // velD
  0.0,                                 // longitude
  0.0,                                 // latitude
  0.0,                                 // altitude
  0.0F,                                // x_R_m
  0.0F,                                // y_R_m
  0.0F,                                // h_R_m
  0U,                                  // flags
  0U                                   // status
} ;                                    // INS_Out_Bus ground

// Exported block parameters
struct_PIzSmHmAxSAly6VhISTBDD INS_PARAMS = {
  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  180.0F,
  0.0F
} ;                                    // Variable: INS_PARAMS
                                       //  Referenced by:
                                       //    '<S319>/Acc_Bias'
                                       //    '<S319>/Acc_RotMatrix'
                                       //    '<S319>/Gyro_Bias'
                                       //    '<S319>/Gyro_RotMatrix'
                                       //    '<S326>/Mag_ScaleFactor1'
                                       //    '<S326>/Mag_ScaleFactor3'


// Model step function
void INSModelClass::step()
{
  int32_T j;
  boolean_T rtb_LogicalOperator1_fk;
  int32_T rtb_Saturation_e;
  boolean_T rtb_Compare_pp;
  boolean_T rtb_LogicalOperator_f;
  real32_T rtb_Product3_n;
  real32_T rtb_Product12_k;
  real32_T rtb_Product15;
  real32_T rtb_Product14;
  real32_T rtb_MatrixConcatenate3[9];
  real32_T rtb_raw_gyro[3];
  real32_T rtb_h_vz;
  uint8_T rtb_Compare;
  uint8_T rtb_Compare_cl;
  real32_T rtb_Multiply_ki;
  boolean_T rtb_mag_init_valid;
  boolean_T rtb_Memory_c;
  boolean_T rtb_Memory_d;
  boolean_T rtb_LogicalOperator4_c;
  boolean_T rtb_Compare_pf;
  boolean_T rtb_LogicalOperator2;
  real_T rtb_mue_rad;
  real_T rtb_lambda_rad;
  real_T rtb_height_m;
  boolean_T rtb_Compare_e;
  boolean_T rtb_FixPtRelationalOperator_if;
  boolean_T rtb_LogicalOperator_l;
  boolean_T rtb_LogicalOperator3_e;
  real32_T rtb_Product1_m;
  uint8_T rtb_Switch_ol;
  boolean_T rtb_FixPtRelationalOperator_l;
  real32_T rtb_Double;
  boolean_T rtb_Compare_df;
  boolean_T rtb_Compare_kf;
  real32_T rtb_VectorConcatenate2[3];
  uint32_T rtb_DiscreteTimeIntegrator_od;
  boolean_T rtb_LogicalOperator4;
  real32_T rtb_SumofElements;
  real32_T rtb_vel_E;
  real32_T rtb_vel_D;
  real32_T rtb_az_bias;
  real32_T rtb_Sum2_g[3];
  boolean_T rtb_Compare_ea;
  real_T rtb_N;
  real32_T rtb_sample_sum;
  real32_T rtb_M_BO[9];
  real32_T rtb_Product3_p[3];
  real32_T rtb_Transpose2[9];
  real32_T rtb_Product2_k[3];
  boolean_T rtb_AND_k2[3];
  real32_T rtb_DiscreteFIRFilter[3];
  real32_T rtb_MathFunction_mj[9];
  real32_T rtb_MathFunction_cp[3];
  real32_T rtb_MatrixConcatenate1_idx_0;
  real32_T rtb_MatrixConcatenate1_idx_1;
  real32_T rtb_MatrixConcatenate1_idx_2;
  real_T rtb_Switch_idx_0;
  real_T rtb_WGS84_pos_ref_idx_0;
  real_T rtb_WGS84_pos_ref_idx_1;
  real32_T rtb_gps_pos_R_m_idx_0;
  real32_T rtb_gps_pos_R_m_idx_1;
  real_T rtb_Switch_idx_1;
  real32_T rtb_DiscreteTimeIntegrator1_h_i;
  real32_T rtb_DiscreteTimeIntegrator1_h_0;
  real32_T rtb_DiscreteTimeIntegrator1_h_1;
  real32_T rtb_MathFunction_k_idx_1;
  real32_T rtb_MathFunction_k_idx_2;
  real32_T rtb_MathFunction_k_idx_0;
  real32_T rtb_raw_acc_idx_0;
  real32_T rtb_raw_acc_idx_1;
  real32_T rtb_raw_acc_idx_2;
  real32_T rtb_pos_est_R_m_idx_0;
  real32_T rtb_pos_est_R_m_idx_1;
  real32_T rtb_MathFunction_e_idx_0;
  real32_T rtb_MathFunction_e_idx_1;
  real32_T rtb_MathFunction_e_idx_2;
  real32_T rtb_Gain_p_idx_1;
  real32_T rtb_Gain_p_idx_2;
  uint32_T qY;
  int32_T q0;
  uint32_T qY_0;
  real32_T u0;
  real_T rtb_Abs_idx_0_tmp;
  real_T rtb_Abs_idx_1_tmp;
  int_T Delay_DSTATE_c_tmp;
  int_T Delay_DSTATE_c_tmp_0;

  // Sum: '<S319>/Sum1' incorporates:
  //   Constant: '<S319>/Acc_Bias'
  //   Inport: '<Root>/IMU'
  //   SignalConversion: '<S319>/ConcatBufferAtVector Concatenate1In1'
  //   SignalConversion: '<S319>/ConcatBufferAtVector Concatenate1In2'
  //   SignalConversion: '<S319>/ConcatBufferAtVector Concatenate1In3'

  rtb_raw_acc_idx_0 = INS_U.IMU.acc_x_mPs2_B - INS_PARAMS.AccBias[0];
  rtb_raw_acc_idx_1 = INS_U.IMU.acc_y_mPs2_B - INS_PARAMS.AccBias[1];
  rtb_raw_acc_idx_2 = INS_U.IMU.acc_z_mPs2_B - INS_PARAMS.AccBias[2];
  for (q0 = 0; q0 < 3; q0++) {
    // Product: '<S319>/Product3' incorporates:
    //   Constant: '<S319>/Acc_RotMatrix'
    //   Constant: '<S319>/Acc_ScaleFactor'
    //   Product: '<S319>/Product5'

    rtb_Product3_p[q0] = INS_P.Conf.AccScaleFactor * (INS_PARAMS.AccRotMat[q0 +
      6] * rtb_raw_acc_idx_2 + (INS_PARAMS.AccRotMat[q0 + 3] * rtb_raw_acc_idx_1
      + INS_PARAMS.AccRotMat[q0] * rtb_raw_acc_idx_0));
  }

  // DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Product3_p[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Product3_p[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] = rtb_Product3_p[2];
  }

  rtb_raw_acc_idx_0 = INS_DWork.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_raw_acc_idx_1 = INS_DWork.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_raw_acc_idx_2 = INS_DWork.DiscreteTimeIntegrator1_DSTATE[2];

  // DiscreteIntegrator: '<S320>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/IMU'
  //   RelationalOperator: '<S324>/FixPt Relational Operator'
  //   UnitDelay: '<S324>/Delay Input1'

  if (INS_U.IMU.timestamp_ms != INS_DWork.DelayInput1_DSTATE) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_oe =
      INS_P.DiscreteTimeIntegrator_IC_o;
  }

  // RelationalOperator: '<S323>/Compare' incorporates:
  //   Constant: '<S323>/Constant'
  //   DiscreteIntegrator: '<S320>/Discrete-Time Integrator'

  rtb_LogicalOperator1_fk = (INS_DWork.DiscreteTimeIntegrator_DSTAT_oe <
    INS_P.IMU_Valid_Time_out);

  // Sum: '<S10>/Sum3' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Logic: '<S10>/Logical Operator3'
  //   Memory: '<S10>/Memory1'
  //   Product: '<S10>/Multiply'

  rtb_Saturation_e = ((INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] != 0.0F) &&
                      (INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] != 0.0F) &&
                      (INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] != 0.0F) ?
                      (int32_T)rtb_LogicalOperator1_fk : 0) +
    INS_DWork.Memory1_PreviousInput_c;

  // Saturate: '<S10>/Saturation'
  if (rtb_Saturation_e > INS_P.Saturation_UpperSat_k) {
    rtb_Saturation_e = INS_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Saturation_e < INS_P.Saturation_LowerSat) {
      rtb_Saturation_e = INS_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S10>/Saturation'

  // RelationalOperator: '<S33>/Compare' incorporates:
  //   Constant: '<S31>/Constant'
  //   Constant: '<S33>/Constant'
  //   RelationalOperator: '<S31>/Compare'

  rtb_Compare_pp = ((int32_T)(rtb_Saturation_e > INS_P.CompareToConstant_const_k)
                    > (int32_T)INS_P.Constant_Value_af);

  // Logic: '<S10>/Logical Operator' incorporates:
  //   Constant: '<S4>/Constant'
  //   RelationalOperator: '<S32>/FixPt Relational Operator'
  //   UnitDelay: '<S32>/Delay Input1'

  rtb_LogicalOperator_f = (((int32_T)rtb_Compare_pp > (int32_T)
    INS_DWork.DelayInput1_DSTATE_p) || (INS_P.Constant_Value_ohi != 0));

  // DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
  //   Memory: '<S5>/Memory'

  if (INS_DWork.DiscreteTimeIntegrator_IC_LOADI != 0) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] = INS_DWork.Memory_PreviousInput
      [0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] = INS_DWork.Memory_PreviousInput
      [1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] = INS_DWork.Memory_PreviousInput
      [2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] = INS_DWork.Memory_PreviousInput
      [3];
  }

  if (rtb_LogicalOperator_f || (INS_DWork.DiscreteTimeIntegrator_PrevRese != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] = INS_DWork.Memory_PreviousInput
      [0];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] = INS_DWork.Memory_PreviousInput
      [1];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] = INS_DWork.Memory_PreviousInput
      [2];
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] = INS_DWork.Memory_PreviousInput
      [3];
  }

  // Sqrt: '<S61>/sqrt' incorporates:
  //   DiscreteIntegrator: '<S54>/Discrete-Time Integrator'
  //   Product: '<S62>/Product'
  //   Product: '<S62>/Product1'
  //   Product: '<S62>/Product2'
  //   Product: '<S62>/Product3'
  //   Sum: '<S62>/Sum'

  rtb_Product3_n = std::sqrt(((INS_DWork.DiscreteTimeIntegrator_DSTATE[0] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[1]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[2]) +
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3] *
    INS_DWork.DiscreteTimeIntegrator_DSTATE[3]);

  // Product: '<S60>/Product' incorporates:
  //   DiscreteIntegrator: '<S54>/Discrete-Time Integrator'

  rtb_Product14 = INS_DWork.DiscreteTimeIntegrator_DSTATE[0] / rtb_Product3_n;

  // Product: '<S60>/Product1' incorporates:
  //   DiscreteIntegrator: '<S54>/Discrete-Time Integrator'

  rtb_Product15 = INS_DWork.DiscreteTimeIntegrator_DSTATE[1] / rtb_Product3_n;

  // Product: '<S60>/Product2' incorporates:
  //   DiscreteIntegrator: '<S54>/Discrete-Time Integrator'

  rtb_Product12_k = INS_DWork.DiscreteTimeIntegrator_DSTATE[2] / rtb_Product3_n;

  // Product: '<S60>/Product3' incorporates:
  //   DiscreteIntegrator: '<S54>/Discrete-Time Integrator'

  rtb_Product3_n = INS_DWork.DiscreteTimeIntegrator_DSTATE[3] / rtb_Product3_n;

  // Product: '<S59>/Product' incorporates:
  //   Product: '<S65>/Product'

  rtb_MatrixConcatenate1_idx_0 = rtb_Product14 * rtb_Product14;
  rtb_MatrixConcatenate1_idx_1 = rtb_Product15 * rtb_Product15;
  rtb_MatrixConcatenate1_idx_2 = rtb_Product12_k * rtb_Product12_k;
  rtb_az_bias = rtb_Product3_n * rtb_Product3_n;

  // Sum: '<S59>/Add' incorporates:
  //   Product: '<S59>/Product'
  //   Sum: '<S65>/Add'

  rtb_DiscreteTimeIntegrator1_h_i = ((rtb_MatrixConcatenate1_idx_0 +
    rtb_MatrixConcatenate1_idx_1) - rtb_MatrixConcatenate1_idx_2) - rtb_az_bias;
  rtb_MatrixConcatenate3[0] = rtb_DiscreteTimeIntegrator1_h_i;

  // Product: '<S59>/Product1' incorporates:
  //   Product: '<S59>/Product5'

  rtb_gps_pos_R_m_idx_0 = rtb_Product15 * rtb_Product12_k;

  // Product: '<S59>/Product2' incorporates:
  //   Product: '<S59>/Product6'

  rtb_gps_pos_R_m_idx_1 = rtb_Product14 * rtb_Product3_n;

  // Sum: '<S59>/Add1' incorporates:
  //   Product: '<S59>/Product1'
  //   Product: '<S59>/Product2'
  //   Sum: '<S65>/Add1'

  rtb_DiscreteTimeIntegrator1_h_0 = rtb_gps_pos_R_m_idx_0 +
    rtb_gps_pos_R_m_idx_1;

  // Gain: '<S59>/Gain' incorporates:
  //   Sum: '<S59>/Add1'

  rtb_MatrixConcatenate3[1] = rtb_DiscreteTimeIntegrator1_h_0 *
    INS_P.Gain_Gain_aw;

  // Product: '<S59>/Product3' incorporates:
  //   Product: '<S59>/Product9'

  rtb_pos_est_R_m_idx_0 = rtb_Product15 * rtb_Product3_n;

  // Product: '<S59>/Product4' incorporates:
  //   Product: '<S59>/Product10'

  rtb_pos_est_R_m_idx_1 = rtb_Product14 * rtb_Product12_k;

  // Gain: '<S59>/Gain1' incorporates:
  //   Product: '<S59>/Product3'
  //   Product: '<S59>/Product4'
  //   Sum: '<S59>/Add2'

  rtb_MatrixConcatenate3[2] = (rtb_pos_est_R_m_idx_0 - rtb_pos_est_R_m_idx_1) *
    INS_P.Gain1_Gain_ju;

  // Gain: '<S59>/Gain2' incorporates:
  //   Sum: '<S59>/Add3'

  rtb_MatrixConcatenate3[3] = (rtb_gps_pos_R_m_idx_0 - rtb_gps_pos_R_m_idx_1) *
    INS_P.Gain2_Gain_m;

  // Sum: '<S59>/Add5' incorporates:
  //   Product: '<S59>/Product'
  //   Sum: '<S59>/Add8'

  rtb_gps_pos_R_m_idx_0 = rtb_MatrixConcatenate1_idx_0 -
    rtb_MatrixConcatenate1_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_gps_pos_R_m_idx_0 +
    rtb_MatrixConcatenate1_idx_2) - rtb_az_bias;

  // Product: '<S59>/Product7' incorporates:
  //   Product: '<S59>/Product12'

  rtb_gps_pos_R_m_idx_1 = rtb_Product12_k * rtb_Product3_n;

  // Product: '<S59>/Product8' incorporates:
  //   Product: '<S59>/Product11'

  rtb_sample_sum = rtb_Product14 * rtb_Product15;

  // Gain: '<S59>/Gain3' incorporates:
  //   Product: '<S59>/Product7'
  //   Product: '<S59>/Product8'
  //   Sum: '<S59>/Add4'

  rtb_MatrixConcatenate3[5] = (rtb_gps_pos_R_m_idx_1 + rtb_sample_sum) *
    INS_P.Gain3_Gain_e;

  // Gain: '<S59>/Gain4' incorporates:
  //   Sum: '<S59>/Add6'

  rtb_MatrixConcatenate3[6] = (rtb_pos_est_R_m_idx_0 + rtb_pos_est_R_m_idx_1) *
    INS_P.Gain4_Gain_f;

  // Gain: '<S59>/Gain5' incorporates:
  //   Sum: '<S59>/Add7'

  rtb_MatrixConcatenate3[7] = (rtb_gps_pos_R_m_idx_1 - rtb_sample_sum) *
    INS_P.Gain5_Gain;

  // Sum: '<S59>/Add8' incorporates:
  //   Product: '<S59>/Product'

  rtb_MatrixConcatenate3[8] = (rtb_gps_pos_R_m_idx_0 -
    rtb_MatrixConcatenate1_idx_2) + rtb_az_bias;

  // SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn1' incorporates:
  //   Inport: '<Root>/IMU'

  rtb_raw_gyro[0] = INS_U.IMU.gyr_x_radPs_B;

  // SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn2' incorporates:
  //   Inport: '<Root>/IMU'

  rtb_raw_gyro[1] = INS_U.IMU.gyr_y_radPs_B;

  // SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' incorporates:
  //   Inport: '<Root>/IMU'

  rtb_raw_gyro[2] = INS_U.IMU.gyr_z_radPs_B;
  for (q0 = 0; q0 < 3; q0++) {
    // Math: '<S54>/Transpose2'
    rtb_Transpose2[3 * q0] = rtb_MatrixConcatenate3[q0];
    rtb_Transpose2[1 + 3 * q0] = rtb_MatrixConcatenate3[q0 + 3];
    rtb_Transpose2[2 + 3 * q0] = rtb_MatrixConcatenate3[q0 + 6];

    // Sum: '<S319>/Sum2' incorporates:
    //   Constant: '<S319>/Gyro_Bias'

    rtb_VectorConcatenate2[q0] = rtb_raw_gyro[q0] - INS_PARAMS.GyroBias[q0];
  }

  for (q0 = 0; q0 < 3; q0++) {
    // Product: '<S319>/Product2' incorporates:
    //   Constant: '<S319>/Gyro_RotMatrix'
    //   Constant: '<S319>/Gyro_ScaleFactor'
    //   Product: '<S319>/Product4'

    rtb_Product2_k[q0] = INS_P.Conf.GyroScaleFactor * (INS_PARAMS.GyroRotMat[q0
      + 6] * rtb_VectorConcatenate2[2] + (INS_PARAMS.GyroRotMat[q0 + 3] *
      rtb_VectorConcatenate2[1] + INS_PARAMS.GyroRotMat[q0] *
      rtb_VectorConcatenate2[0]));
  }

  // DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_f != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[0] = rtb_Product2_k[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[1] = rtb_Product2_k[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[2] = rtb_Product2_k[2];
  }

  // Sum: '<S55>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S55>/Discrete-Time Integrator2'

  rtb_raw_gyro[0] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[0];
  rtb_raw_gyro[1] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[1];
  rtb_raw_gyro[2] = INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[2];

  // Rounding: '<S312>/Rounding Function' incorporates:
  //   Gain: '<S312>/Gain1'
  //   UnitDelay: '<S312>/Unit Delay'

  rtb_h_vz = std::floor((real32_T)INS_P.Gain1_Gain * 9.09494702E-13F * (real32_T)
                        INS_DWork.UnitDelay_DSTATE);

  // RelationalOperator: '<S316>/Compare' incorporates:
  //   Constant: '<S316>/Constant'
  //   Inport: '<Root>/GPS_uBlox'

  rtb_Compare = (INS_U.GPS_uBlox.fixType == INS_P.CompareToConstant1_const_n4);

  // DiscreteIntegrator: '<S305>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/GPS_uBlox'
  //   RelationalOperator: '<S310>/FixPt Relational Operator'
  //   UnitDelay: '<S310>/Delay Input1'

  if (INS_U.GPS_uBlox.timestamp_ms != INS_DWork.DelayInput1_DSTATE_i) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_po;
  }

  // RelationalOperator: '<S317>/Compare' incorporates:
  //   Constant: '<S317>/Constant'
  //   DiscreteIntegrator: '<S305>/Discrete-Time Integrator'

  rtb_Compare_cl = (INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
                    INS_P.CompareToConstant2_const_ag);

  // Sum: '<S312>/Sum1' incorporates:
  //   Logic: '<S312>/Logical Operator1'

  rtb_Multiply_ki = (real32_T)((rtb_h_vz != 0.0F) && (rtb_Compare != 0) &&
    (rtb_Compare_cl != 0)) + rtb_h_vz;

  // RelationalOperator: '<S304>/Compare' incorporates:
  //   Constant: '<S304>/Constant'

  rtb_mag_init_valid = (rtb_Multiply_ki == INS_P.CompareToConstant1_const);

  // RelationalOperator: '<S309>/Compare' incorporates:
  //   Constant: '<S309>/Constant'
  //   DiscreteIntegrator: '<S305>/Discrete-Time Integrator'

  rtb_Memory_c = (INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
                  INS_P.CompareToConstant4_const);

  // RelationalOperator: '<S308>/Compare' incorporates:
  //   Constant: '<S308>/Constant'

  rtb_Memory_d = (rtb_Multiply_ki > INS_P.CompareToConstant2_const);

  // Gain: '<S305>/Gain2' incorporates:
  //   Constant: '<S305>/Constant1'
  //   Gain: '<S305>/Gain1'
  //   Inport: '<Root>/GPS_uBlox'
  //   Sum: '<S305>/Sum1'

  u0 = (INS_P.Constant1_Value - (real32_T)INS_P.Gain1_Gain_p * 4.54747351E-13F *
        (real32_T)INS_U.GPS_uBlox.hAcc) * INS_P.Gain2_Gain_p;

  // Product: '<S305>/Double1' incorporates:
  //   Saturate: '<S305>/Saturation1'

  rtb_h_vz = rtb_Memory_d ? rtb_Memory_c ? u0 > INS_P.Saturation1_UpperSat_m ?
    INS_P.Saturation1_UpperSat_m : u0 < INS_P.Saturation1_LowerSat_d ?
    INS_P.Saturation1_LowerSat_d : u0 : 0.0F : 0.0F;

  // Logic: '<S146>/Logical Operator' incorporates:
  //   Constant: '<S148>/Constant'
  //   RelationalOperator: '<S148>/Compare'

  rtb_LogicalOperator4_c = (rtb_mag_init_valid && (rtb_h_vz >
    INS_P.Constant_Value_o0));

  // RelationalOperator: '<S134>/Compare' incorporates:
  //   Constant: '<S134>/Constant'

  rtb_Compare_pf = ((int32_T)rtb_LogicalOperator4_c > (int32_T)
                    INS_P.Constant_Value_g);

  // Logic: '<S130>/Logical Operator2' incorporates:
  //   Constant: '<S4>/Constant'
  //   RelationalOperator: '<S133>/FixPt Relational Operator'
  //   UnitDelay: '<S133>/Delay Input1'

  rtb_LogicalOperator2 = (((int32_T)rtb_Compare_pf > (int32_T)
    INS_DWork.DelayInput1_DSTATE_o) || (INS_P.Constant_Value_ohi != 0));

  // DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  if (rtb_LogicalOperator2 || (INS_DWork.DiscreteTimeIntegrator_PrevRe_h != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0] =
      INS_P.DiscreteTimeIntegrator_IC;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1] =
      INS_P.DiscreteTimeIntegrator_IC;
  }

  // DiscreteIntegrator: '<S117>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S109>/Constant'

  if ((INS_P.Constant_Value_m5 != 0) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevRes != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_p = INS_P.DiscreteTimeIntegrator1_IC;
  }

  // Gain: '<S306>/Scalefactor1' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_mue_rad = (real_T)INS_P.Scalefactor1_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lat;

  // Gain: '<S306>/Scalefactor2' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_lambda_rad = (real_T)INS_P.Scalefactor2_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lon;

  // Gain: '<S306>/Scalefactor3' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_height_m = (real_T)INS_P.Scalefactor3_Gain * 9.0949470177292824E-13 *
    (real_T)INS_U.GPS_uBlox.height;

  // RelationalOperator: '<S303>/Compare' incorporates:
  //   Constant: '<S303>/Constant'

  rtb_Compare_e = (rtb_Multiply_ki > INS_P.CompareToConstant_const_i);

  // Outputs for Triggered SubSystem: '<S286>/WGS_Linearization' incorporates:
  //   TriggerPort: '<S307>/Trigger'

  if (rtb_Compare_e && (INS_PrevZCSigState.WGS_Linearization_Trig_ZCE !=
                        POS_ZCSIG)) {
    // SignalConversion: '<S307>/OutportBufferFordz_dh' incorporates:
    //   Constant: '<S318>/constant1'

    INS_B.dz_dh = INS_P.constant1_Value;

    // Trigonometry: '<S318>/Trigonometric Function1' incorporates:
    //   Trigonometry: '<S318>/Trigonometric Function2'

    rtb_Switch_idx_0 = std::cos(rtb_mue_rad);

    // Product: '<S318>/Product1' incorporates:
    //   Constant: '<S318>/constant'
    //   Constant: '<S318>/f'
    //   Sum: '<S318>/Subtract1'

    rtb_Switch_idx_1 = (INS_P.constant_Value - INS_P.f_Value) * INS_P.f_Value;

    // Trigonometry: '<S318>/Trigonometric Function'
    rtb_N = std::sin(rtb_mue_rad);

    // Sum: '<S318>/Subtract' incorporates:
    //   Constant: '<S318>/a1'
    //   Math: '<S318>/u^2'
    //   Product: '<S318>/Product'

    rtb_N = INS_P.a1_Value - rtb_N * rtb_N * rtb_Switch_idx_1;

    // Math: '<S318>/sqrt'
    //
    //  About '<S318>/sqrt':
    //   Operator: sqrt

    if (rtb_N < 0.0) {
      rtb_N = -std::sqrt(std::abs(rtb_N));
    } else {
      rtb_N = std::sqrt(rtb_N);
    }

    // End of Math: '<S318>/sqrt'

    // Product: '<S318>/Divide' incorporates:
    //   Constant: '<S318>/a'

    rtb_N = INS_P.a_Value / rtb_N;

    // Sum: '<S318>/Add' incorporates:
    //   Constant: '<S318>/constant2'
    //   Math: '<S318>/u^1'
    //   Product: '<S318>/Product2'
    //   Product: '<S318>/Product3'
    //   Sum: '<S318>/Subtract2'
    //   Trigonometry: '<S318>/Trigonometric Function1'

    INS_B.Add = (INS_P.constant2_Value - rtb_Switch_idx_0 * rtb_Switch_idx_0 *
                 rtb_Switch_idx_1) * rtb_N + rtb_height_m;

    // Product: '<S318>/Product4' incorporates:
    //   Sum: '<S318>/Add1'

    INS_B.Product4 = (rtb_N + rtb_height_m) * rtb_Switch_idx_0;
  }

  INS_PrevZCSigState.WGS_Linearization_Trig_ZCE = rtb_Compare_e;

  // End of Outputs for SubSystem: '<S286>/WGS_Linearization'

  // RelationalOperator: '<S139>/Compare' incorporates:
  //   Constant: '<S139>/Constant'

  rtb_Compare_e = ((int32_T)rtb_LogicalOperator4_c > (int32_T)
                   INS_P.Constant_Value_pt);

  // Abs: '<S136>/Abs' incorporates:
  //   Memory: '<S136>/memory2'

  rtb_Switch_idx_0 = std::abs(INS_DWork.memory2_PreviousInput[0]);
  rtb_Switch_idx_1 = std::abs(INS_DWork.memory2_PreviousInput[1]);
  rtb_N = std::abs(INS_DWork.memory2_PreviousInput[2]);

  // MinMax: '<S136>/Max'
  if (rtb_Switch_idx_0 > rtb_Switch_idx_1) {
    rtb_Switch_idx_1 = rtb_Switch_idx_0;
  }

  if (rtb_Switch_idx_1 <= rtb_N) {
    rtb_Switch_idx_1 = rtb_N;
  }

  // Logic: '<S136>/Logical Operator' incorporates:
  //   Constant: '<S137>/Constant'
  //   MinMax: '<S136>/Max'
  //   RelationalOperator: '<S137>/Compare'
  //   RelationalOperator: '<S138>/FixPt Relational Operator'
  //   UnitDelay: '<S138>/Delay Input1'

  rtb_LogicalOperator4_c = (((int32_T)rtb_Compare_e > (int32_T)
    INS_DWork.DelayInput1_DSTATE_m) && (rtb_Switch_idx_1 <=
    INS_P.CompareToConstant_const));

  // Switch: '<S136>/Switch5' incorporates:
  //   Memory: '<S136>/memory2'
  //   Memory: '<S136>/memory3'
  //   Switch: '<S136>/Switch4'

  if (rtb_LogicalOperator4_c) {
    rtb_Switch_idx_1 = INS_B.Add;
    rtb_Switch_idx_0 = INS_B.Product4;
    rtb_N = INS_B.dz_dh;
    rtb_WGS84_pos_ref_idx_0 = rtb_mue_rad;
    rtb_WGS84_pos_ref_idx_1 = rtb_lambda_rad;
  } else {
    rtb_Switch_idx_1 = INS_DWork.memory3_PreviousInput[0];
    rtb_Switch_idx_0 = INS_DWork.memory3_PreviousInput[1];
    rtb_N = INS_DWork.memory3_PreviousInput[2];
    rtb_WGS84_pos_ref_idx_0 = INS_DWork.memory2_PreviousInput[0];
    rtb_WGS84_pos_ref_idx_1 = INS_DWork.memory2_PreviousInput[1];
    rtb_height_m = INS_DWork.memory2_PreviousInput[2];
  }

  // End of Switch: '<S136>/Switch5'

  // Abs: '<S114>/Abs' incorporates:
  //   Abs: '<S116>/Abs'

  rtb_Abs_idx_0_tmp = std::abs(rtb_Switch_idx_1);
  rtb_Abs_idx_1_tmp = std::abs(rtb_Switch_idx_0);

  // DataTypeConversion: '<S110>/Data Type Conversion4' incorporates:
  //   Product: '<S110>/Product1'
  //   Sum: '<S110>/Sum1'

  rtb_gps_pos_R_m_idx_0 = (real32_T)((rtb_mue_rad - rtb_WGS84_pos_ref_idx_0) *
    rtb_Switch_idx_1);
  rtb_gps_pos_R_m_idx_1 = (real32_T)((rtb_lambda_rad - rtb_WGS84_pos_ref_idx_1) *
    rtb_Switch_idx_0);

  // DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
  if (INS_DWork.DiscreteTimeIntegrator_IC_LOA_a != 0) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] = rtb_gps_pos_R_m_idx_0;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] = rtb_gps_pos_R_m_idx_1;
  }

  if (rtb_LogicalOperator2 || (INS_DWork.DiscreteTimeIntegrator_PrevRe_o != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] = rtb_gps_pos_R_m_idx_0;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] = rtb_gps_pos_R_m_idx_1;
  }

  rtb_pos_est_R_m_idx_0 = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0];
  rtb_pos_est_R_m_idx_1 = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1];

  // Logic: '<S292>/Logical Operator' incorporates:
  //   Constant: '<S300>/Lower Limit'
  //   Constant: '<S300>/Upper Limit'
  //   Constant: '<S301>/Lower Limit'
  //   Constant: '<S301>/Upper Limit'
  //   Inport: '<Root>/MS5611'
  //   Logic: '<S300>/AND'
  //   Logic: '<S301>/AND'
  //   RelationalOperator: '<S300>/Lower Test'
  //   RelationalOperator: '<S300>/Upper Test'
  //   RelationalOperator: '<S301>/Lower Test'
  //   RelationalOperator: '<S301>/Upper Test'
  //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_1'

  rtb_LogicalOperator4_c = ((INS_P.Delta_Height_pressure_min <
    INS_U.MS5611.pressure_pa) && (INS_U.MS5611.pressure_pa <
    INS_P.Delta_Height_pressure_max) && ((INS_P.Delta_Height_temp_min <
    INS_U.MS5611.temperature_deg) && (INS_U.MS5611.temperature_deg <
    INS_P.Delta_Height_temp_max)));

  // RelationalOperator: '<S299>/FixPt Relational Operator' incorporates:
  //   Inport: '<Root>/MS5611'
  //   UnitDelay: '<S299>/Delay Input1'

  rtb_FixPtRelationalOperator_if = (INS_U.MS5611.timestamp_ms !=
    INS_DWork.DelayInput1_DSTATE_g);

  // Sum: '<S292>/Sum1' incorporates:
  //   Constant: '<S293>/Constant'
  //   Constant: '<S298>/Constant'
  //   Logic: '<S292>/Logical Operator1'
  //   Logic: '<S292>/Logical Operator2'
  //   Logic: '<S292>/Logical Operator5'
  //   Memory: '<S292>/Memory2'
  //   RelationalOperator: '<S293>/Compare'
  //   RelationalOperator: '<S298>/Compare'

  q0 = (((rtb_LogicalOperator4_c && rtb_FixPtRelationalOperator_if) ||
         (INS_DWork.Memory2_PreviousInput > INS_P.Constant_Value_in)) &&
        (INS_DWork.Memory2_PreviousInput < INS_P.CompareToConstant_const_p));
  qY_0 = q0 + INS_DWork.Memory2_PreviousInput;
  if (qY_0 < (uint32_T)q0) {
    qY_0 = MAX_uint32_T;
  }

  // DiscreteIntegrator: '<S292>/Discrete-Time Integrator'
  if (rtb_FixPtRelationalOperator_if) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_dv;
  }

  // Logic: '<S292>/Logical Operator4' incorporates:
  //   Constant: '<S295>/Constant'
  //   Constant: '<S297>/Constant'
  //   DiscreteIntegrator: '<S292>/Discrete-Time Integrator'
  //   RelationalOperator: '<S295>/Compare'
  //   RelationalOperator: '<S297>/Compare'
  //   Sum: '<S292>/Sum1'

  rtb_LogicalOperator4_c = ((qY_0 > INS_P.Delta_Height_s_last) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_e <
     INS_P.CompareToConstant4_const_i) && rtb_LogicalOperator4_c);

  // RelationalOperator: '<S119>/Compare' incorporates:
  //   Constant: '<S119>/Constant'

  rtb_FixPtRelationalOperator_if = ((int32_T)rtb_LogicalOperator4_c > (int32_T)
    INS_P.Constant_Value_k);

  // Logic: '<S117>/Logical Operator' incorporates:
  //   Constant: '<S109>/Constant'
  //   RelationalOperator: '<S118>/FixPt Relational Operator'
  //   UnitDelay: '<S118>/Delay Input1'

  rtb_LogicalOperator_l = (((int32_T)rtb_FixPtRelationalOperator_if > (int32_T)
    INS_DWork.DelayInput1_DSTATE_h) || (INS_P.Constant_Value_m5 != 0));

  // Logic: '<S292>/Logical Operator3' incorporates:
  //   Constant: '<S294>/Constant'
  //   Constant: '<S296>/Constant'
  //   RelationalOperator: '<S294>/Compare'
  //   RelationalOperator: '<S296>/Compare'
  //   Sum: '<S292>/Sum1'

  rtb_LogicalOperator3_e = ((qY_0 >= INS_P.Delta_Height_s_first) && (qY_0 <=
    INS_P.Delta_Height_s_last));

  // Outputs for Enabled SubSystem: '<S289>/Reference_and_Gradient' incorporates:
  //   EnablePort: '<S291>/Enable'

  if (rtb_LogicalOperator3_e) {
    if (!INS_DWork.Reference_and_Gradient_MODE) {
      // InitializeConditions for Memory: '<S291>/Memory'
      INS_DWork.Memory_PreviousInput_f = INS_P.Memory_InitialCondition;

      // InitializeConditions for Memory: '<S291>/Memory2'
      INS_DWork.Memory2_PreviousInput_b = INS_P.Memory2_InitialCondition;

      // InitializeConditions for Memory: '<S291>/Memory1'
      INS_DWork.Memory1_PreviousInput = INS_P.Memory1_InitialCondition_g;
      INS_DWork.Reference_and_Gradient_MODE = true;
    }

    // Sum: '<S291>/Sum2' incorporates:
    //   Inport: '<Root>/MS5611'
    //   Memory: '<S291>/Memory'
    //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_0'

    rtb_sample_sum = INS_U.MS5611.pressure_pa + INS_DWork.Memory_PreviousInput_f;

    // Sum: '<S291>/Sum1' incorporates:
    //   Constant: '<S291>/Constant1'
    //   Memory: '<S291>/Memory2'

    qY = INS_P.Constant1_Value_f + INS_DWork.Memory2_PreviousInput_b;
    if (qY < INS_P.Constant1_Value_f) {
      qY = MAX_uint32_T;
    }

    // Saturate: '<S291>/Saturation1' incorporates:
    //   Sum: '<S291>/Sum1'

    if (qY > INS_P.Saturation1_UpperSat_n) {
      rtb_DiscreteTimeIntegrator_od = INS_P.Saturation1_UpperSat_n;
    } else if (qY < INS_P.Saturation1_LowerSat_m) {
      rtb_DiscreteTimeIntegrator_od = INS_P.Saturation1_LowerSat_m;
    } else {
      rtb_DiscreteTimeIntegrator_od = qY;
    }

    // End of Saturate: '<S291>/Saturation1'

    // Product: '<S291>/Divide'
    INS_B.Divide = rtb_sample_sum / (real32_T)rtb_DiscreteTimeIntegrator_od;

    // Sum: '<S291>/Sum4' incorporates:
    //   Constant: '<S291>/Constant2'
    //   Inport: '<Root>/MS5611'
    //   Memory: '<S291>/Memory1'
    //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
    //   Sum: '<S291>/Sum3'

    rtb_Multiply_ki = (INS_P.Constant2_Value_p + INS_U.MS5611.temperature_deg) +
      INS_DWork.Memory1_PreviousInput;

    // Saturate: '<S291>/Saturation'
    if (INS_B.Divide > INS_P.Saturation_UpperSat_m) {
      u0 = INS_P.Saturation_UpperSat_m;
    } else if (INS_B.Divide < INS_P.Saturation_LowerSat_h) {
      u0 = INS_P.Saturation_LowerSat_h;
    } else {
      u0 = INS_B.Divide;
    }

    // End of Saturate: '<S291>/Saturation'

    // Gain: '<S291>/g_M_d_R' incorporates:
    //   Product: '<S291>/Divide1'
    //   Product: '<S291>/Product'

    INS_B.g_M_d_R = rtb_Multiply_ki / (real32_T)rtb_DiscreteTimeIntegrator_od /
      u0 * INS_P.g_M_d_R_Gain;

    // Update for Memory: '<S291>/Memory'
    INS_DWork.Memory_PreviousInput_f = rtb_sample_sum;

    // Update for Memory: '<S291>/Memory2' incorporates:
    //   Sum: '<S291>/Sum1'

    INS_DWork.Memory2_PreviousInput_b = qY;

    // Update for Memory: '<S291>/Memory1'
    INS_DWork.Memory1_PreviousInput = rtb_Multiply_ki;
  } else {
    if (INS_DWork.Reference_and_Gradient_MODE) {
      INS_DWork.Reference_and_Gradient_MODE = false;
    }
  }

  // End of Outputs for SubSystem: '<S289>/Reference_and_Gradient'

  // Switch: '<S289>/Switch' incorporates:
  //   Inport: '<Root>/MS5611'
  //   Logic: '<S289>/Logical Operator1'
  //   Logic: '<S289>/Logical Operator2'
  //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_0'

  if (rtb_LogicalOperator3_e || (!rtb_LogicalOperator4_c)) {
    rtb_sample_sum = INS_U.MS5611.pressure_pa;
  } else {
    rtb_sample_sum = INS_B.Divide;
  }

  // End of Switch: '<S289>/Switch'

  // Product: '<S289>/Product1' incorporates:
  //   Inport: '<Root>/MS5611'
  //   SignalConversion: '<S289>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  //   Sum: '<S289>/Sum2'

  rtb_Product1_m = (INS_U.MS5611.pressure_pa - rtb_sample_sum) * INS_B.g_M_d_R;

  // DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
  if (INS_DWork.DiscreteTimeIntegrator2_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator2_DSTAT_k = rtb_Product1_m;
  }

  if (rtb_LogicalOperator_l || (INS_DWork.DiscreteTimeIntegrator2_PrevRes != 0))
  {
    INS_DWork.DiscreteTimeIntegrator2_DSTAT_k = rtb_Product1_m;
  }

  // MinMax: '<S114>/Min' incorporates:
  //   Abs: '<S114>/Abs'

  if (rtb_Abs_idx_0_tmp < rtb_Abs_idx_1_tmp) {
    rtb_mue_rad = rtb_Abs_idx_0_tmp;
  } else {
    rtb_mue_rad = rtb_Abs_idx_1_tmp;
  }

  // End of MinMax: '<S114>/Min'

  // Switch: '<S114>/Switch' incorporates:
  //   Constant: '<S115>/Constant'
  //   RelationalOperator: '<S115>/Compare'
  //   Signum: '<S116>/Sign'

  if (rtb_mue_rad < INS_P.CompareToConstant_const_f) {
    // BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
    //   Constant: '<S114>/Constant'
    //   Outport: '<Root>/INS_Out'

    INS_Y.INS_Out.latitude = INS_P.Constant_Value_o[0];
    INS_Y.INS_Out.longitude = INS_P.Constant_Value_o[1];
    INS_Y.INS_Out.altitude = INS_P.Constant_Value_o[2];
  } else {
    if (rtb_Switch_idx_1 < 0.0) {
      // Signum: '<S116>/Sign'
      rtb_mue_rad = -1.0;
    } else if (rtb_Switch_idx_1 > 0.0) {
      // Signum: '<S116>/Sign'
      rtb_mue_rad = 1.0;
    } else {
      // Signum: '<S116>/Sign'
      rtb_mue_rad = rtb_Switch_idx_1;
    }

    // Switch: '<S116>/Switch' incorporates:
    //   Constant: '<S116>/Constant'
    //   Signum: '<S116>/Sign'

    if (rtb_mue_rad == 0.0) {
      rtb_mue_rad = INS_P.Constant_Value;
    }

    // Saturate: '<S116>/Saturation'
    if (rtb_Abs_idx_0_tmp > INS_P.Saturation_UpperSat) {
      rtb_Abs_idx_0_tmp = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Abs_idx_0_tmp < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Abs_idx_0_tmp = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    // BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
    //   DataTypeConversion: '<S114>/Data Type Conversion'
    //   DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
    //   Outport: '<Root>/INS_Out'
    //   Product: '<S114>/Divide'
    //   Product: '<S116>/Product'
    //   Sum: '<S114>/Sum'

    INS_Y.INS_Out.latitude = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] /
      (rtb_Abs_idx_0_tmp * rtb_mue_rad) + rtb_WGS84_pos_ref_idx_0;

    // Signum: '<S116>/Sign'
    if (rtb_Switch_idx_0 < 0.0) {
      rtb_mue_rad = -1.0;
    } else if (rtb_Switch_idx_0 > 0.0) {
      rtb_mue_rad = 1.0;
    } else {
      rtb_mue_rad = rtb_Switch_idx_0;
    }

    // Switch: '<S116>/Switch' incorporates:
    //   Constant: '<S116>/Constant'

    if (rtb_mue_rad == 0.0) {
      rtb_mue_rad = INS_P.Constant_Value;
    }

    // Saturate: '<S116>/Saturation'
    if (rtb_Abs_idx_1_tmp > INS_P.Saturation_UpperSat) {
      rtb_Abs_idx_1_tmp = INS_P.Saturation_UpperSat;
    } else {
      if (rtb_Abs_idx_1_tmp < INS_P.Zero_Value_Exclusion_thr) {
        rtb_Abs_idx_1_tmp = INS_P.Zero_Value_Exclusion_thr;
      }
    }

    // BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
    //   DataTypeConversion: '<S114>/Data Type Conversion'
    //   DataTypeConversion: '<S114>/Data Type Conversion1'
    //   DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
    //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
    //   Outport: '<Root>/INS_Out'
    //   Product: '<S114>/Divide'
    //   Product: '<S116>/Product'
    //   Sum: '<S114>/Sum'

    INS_Y.INS_Out.longitude = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] /
      (rtb_Abs_idx_1_tmp * rtb_mue_rad) + rtb_WGS84_pos_ref_idx_1;
    INS_Y.INS_Out.altitude = INS_DWork.DiscreteTimeIntegrator2_DSTAT_k +
      rtb_height_m;
  }

  // End of Switch: '<S114>/Switch'

  // Switch: '<S53>/Switch' incorporates:
  //   Constant: '<S53>/Constant'
  //   Memory: '<S53>/Memory'
  //   RelationalOperator: '<S57>/FixPt Relational Operator'
  //   UnitDelay: '<S57>/Delay Input1'

  if ((int32_T)rtb_LogicalOperator_f > (int32_T)INS_DWork.DelayInput1_DSTATE_d)
  {
    rtb_Switch_ol = INS_P.Constant_Value_mm;
  } else {
    rtb_Switch_ol = INS_DWork.Memory_PreviousInput_l;
  }

  // End of Switch: '<S53>/Switch'

  // RelationalOperator: '<S314>/Compare' incorporates:
  //   Constant: '<S314>/Constant'

  rtb_LogicalOperator3_e = ((int32_T)rtb_Memory_d > (int32_T)
    INS_P.Constant_Value_px);

  // RelationalOperator: '<S311>/FixPt Relational Operator' incorporates:
  //   UnitDelay: '<S311>/Delay Input1'

  rtb_FixPtRelationalOperator_l = ((int32_T)rtb_LogicalOperator3_e > (int32_T)
    INS_DWork.DelayInput1_DSTATE_l);

  // Gain: '<S305>/Gain3' incorporates:
  //   Constant: '<S305>/Constant7'
  //   Gain: '<S305>/Gain5'
  //   Inport: '<Root>/GPS_uBlox'
  //   Sum: '<S305>/Sum'

  rtb_sample_sum = (INS_P.Constant7_Value - (real32_T)INS_P.Gain5_Gain_a *
                    4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.sAcc) *
    INS_P.Gain3_Gain_l;

  // DiscreteIntegrator: '<S313>/Discrete-Time Integrator5'
  if (INS_DWork.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator5_DSTATE = rtb_sample_sum;
  }

  if (rtb_FixPtRelationalOperator_l ||
      (INS_DWork.DiscreteTimeIntegrator5_PrevRes != 0)) {
    INS_DWork.DiscreteTimeIntegrator5_DSTATE = rtb_sample_sum;
  }

  // Product: '<S305>/Double' incorporates:
  //   Saturate: '<S305>/Saturation'

  rtb_Double = rtb_Memory_d ? rtb_Memory_c ?
    INS_DWork.DiscreteTimeIntegrator5_DSTATE > INS_P.Saturation_UpperSat_l ?
    INS_P.Saturation_UpperSat_l : INS_DWork.DiscreteTimeIntegrator5_DSTATE <
    INS_P.Saturation_LowerSat_k ? INS_P.Saturation_LowerSat_k :
    INS_DWork.DiscreteTimeIntegrator5_DSTATE : 0.0F : 0.0F;

  // Product: '<S74>/Multiply' incorporates:
  //   Memory: '<S74>/Memory'

  rtb_Multiply_ki = INS_DWork.Memory_PreviousInput_c ? rtb_Double : 0.0F;

  // RelationalOperator: '<S90>/Compare' incorporates:
  //   Constant: '<S90>/Constant'

  rtb_Memory_c = (rtb_Multiply_ki > INS_P.CompareToConstant1_const_n);

  // DiscreteIntegrator: '<S81>/Discrete-Time Integrator'
  if (rtb_Memory_c || (INS_DWork.DiscreteTimeIntegrator_PrevR_os != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_i;
  }

  // RelationalOperator: '<S85>/Compare' incorporates:
  //   Constant: '<S85>/Constant'

  rtb_Memory_d = (rtb_Double > INS_P.CompareToConstant1_const_p);

  // DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
  if (rtb_Memory_d || (INS_DWork.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o =
      INS_P.DiscreteTimeIntegrator_IC_l;
  }

  // RelationalOperator: '<S95>/Compare' incorporates:
  //   Constant: '<S95>/Constant'

  rtb_Compare_df = (rtb_h_vz > INS_P.CompareToConstant1_const_g);

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  if (rtb_Compare_df || (INS_DWork.DiscreteTimeIntegrator_PrevR_or != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_jj =
      INS_P.DiscreteTimeIntegrator_IC_d;
  }

  // RelationalOperator: '<S100>/Compare' incorporates:
  //   Constant: '<S100>/Constant'

  rtb_Compare_kf = ((int32_T)rtb_LogicalOperator4_c > (int32_T)
                    INS_P.CompareToConstant1_const_b);

  // DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  if (rtb_Compare_kf || (INS_DWork.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_p;
  }

  // Sum: '<S73>/Sum2' incorporates:
  //   Constant: '<S84>/Constant'
  //   Constant: '<S89>/Constant'
  //   Constant: '<S94>/Constant'
  //   Constant: '<S99>/Constant'
  //   DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S81>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
  //   Gain: '<S73>/Gain1'
  //   Gain: '<S73>/Gain10'
  //   Gain: '<S73>/Gain11'
  //   Gain: '<S73>/Gain12'
  //   Gain: '<S73>/Gain13'
  //   Gain: '<S73>/Gain9'
  //   Logic: '<S80>/Logical Operator'
  //   Logic: '<S81>/Logical Operator'
  //   Logic: '<S82>/Logical Operator'
  //   Logic: '<S83>/Logical Operator'
  //   Memory: '<S80>/Memory'
  //   Memory: '<S81>/Memory'
  //   Memory: '<S82>/Memory'
  //   Memory: '<S83>/Memory'
  //   Product: '<S80>/Multiply'
  //   Product: '<S81>/Multiply'
  //   Product: '<S82>/Multiply'
  //   Product: '<S83>/Multiply'
  //   RelationalOperator: '<S84>/Compare'
  //   RelationalOperator: '<S89>/Compare'
  //   RelationalOperator: '<S94>/Compare'
  //   RelationalOperator: '<S99>/Compare'

  INS_Y.INS_Out.flags = (uint16_T)((((((((uint32_T)INS_P.Gain9_Gain *
    rtb_Switch_ol) >> 7) + (rtb_LogicalOperator1_fk ? (int32_T)((uint32_T)
    INS_P.Gain10_Gain >> 6) : 0)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_c < INS_P.valid_check2_time_out ?
     (int32_T)INS_DWork.Memory_PreviousInput_m : 0) * INS_P.Gain11_Gain) >> 13))
    + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_o <
                   INS_P.valid_check1_time_out ? (int32_T)
                   INS_DWork.Memory_PreviousInput_e : 0) * INS_P.Gain12_Gain) >>
       12)) + (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_jj <
    INS_P.valid_check3_time_out ? (int32_T)INS_DWork.Memory_PreviousInput_cb : 0)
                * INS_P.Gain13_Gain) >> 11)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_ca < INS_P.valid_check4_time_out ?
     (int32_T)INS_DWork.Memory_PreviousInput_o : 0) * INS_P.Gain1_Gain_kq) >> 10));

  // Sum: '<S326>/Sum2' incorporates:
  //   Constant: '<S326>/Mag_ScaleFactor1'
  //   Inport: '<Root>/Mag'
  //   SignalConversion: '<S288>/ConcatBufferAtVector Concatenate2In1'
  //   SignalConversion: '<S288>/ConcatBufferAtVector Concatenate2In2'
  //   SignalConversion: '<S288>/ConcatBufferAtVector Concatenate2In3'

  rtb_DiscreteTimeIntegrator1_h_1 = INS_U.Mag.mag_x_ga_B - INS_PARAMS.MagBias[0];
  rtb_MatrixConcatenate1_idx_2 = INS_U.Mag.mag_y_ga_B - INS_PARAMS.MagBias[1];
  rtb_vel_E = INS_U.Mag.mag_z_ga_B - INS_PARAMS.MagBias[2];
  for (q0 = 0; q0 < 3; q0++) {
    // Product: '<S326>/Product2' incorporates:
    //   Constant: '<S326>/Mag_ScaleFactor3'
    //   Constant: '<S326>/Mag_ScaleFactor4'
    //   Product: '<S326>/Product1'

    rtb_az_bias = INS_P.Conf.MagScaleFactor * (INS_PARAMS.MagRotMat[q0 + 6] *
      rtb_vel_E + (INS_PARAMS.MagRotMat[q0 + 3] * rtb_MatrixConcatenate1_idx_2 +
                   INS_PARAMS.MagRotMat[q0] * rtb_DiscreteTimeIntegrator1_h_1));

    // Logic: '<S329>/AND' incorporates:
    //   Constant: '<S329>/Lower Limit'
    //   Constant: '<S329>/Upper Limit'
    //   RelationalOperator: '<S329>/Lower Test'
    //   RelationalOperator: '<S329>/Upper Test'

    rtb_AND_k2[q0] = ((INS_P.Mag_Valid_min < rtb_az_bias) && (rtb_az_bias <
      INS_P.Mag_Valid_max));

    // Product: '<S326>/Product2'
    rtb_Sum2_g[q0] = rtb_az_bias;
  }

  // DiscreteIntegrator: '<S325>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/Mag'
  //   RelationalOperator: '<S328>/FixPt Relational Operator'
  //   UnitDelay: '<S328>/Delay Input1'

  if (INS_U.Mag.timestamp_ms != INS_DWork.DelayInput1_DSTATE_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;
  }

  // Logic: '<S325>/Logical Operator4' incorporates:
  //   Constant: '<S325>/Constant1'
  //   Constant: '<S327>/Constant'
  //   DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
  //   Logic: '<S325>/Logical Operator'
  //   Logic: '<S325>/Logical Operator1'
  //   RelationalOperator: '<S327>/Compare'

  rtb_LogicalOperator4 = (rtb_AND_k2[0] && rtb_AND_k2[1] && rtb_AND_k2[2] &&
    (INS_P.Constant1_Value_i != 0.0F) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_lg < INS_P.Mag_Valid_Time_out));

  // MinMax: '<S72>/Max'
  if (rtb_Double > rtb_h_vz) {
    rtb_az_bias = rtb_Double;
  } else {
    rtb_az_bias = rtb_h_vz;
  }

  // End of MinMax: '<S72>/Max'

  // Sum: '<S72>/Sum' incorporates:
  //   Constant: '<S79>/Constant'
  //   Gain: '<S72>/Gain2'
  //   Gain: '<S72>/Gain4'
  //   Gain: '<S72>/Gain5'
  //   RelationalOperator: '<S79>/Compare'

  INS_Y.INS_Out.status = (uint16_T)((((uint32_T)(rtb_LogicalOperator4 ? (int32_T)
    ((uint32_T)INS_P.Gain2_Gain_h >> 6) : 0) + rtb_LogicalOperator1_fk) +
    (rtb_LogicalOperator4_c ? (int32_T)((uint32_T)INS_P.Gain4_Gain_p >> 5) : 0))
    + (rtb_az_bias > INS_P.Constant_Value_jj ? (int32_T)((uint32_T)
    INS_P.Gain5_Gain_o >> 4) : 0));

  // DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
  //   UnitDelay: '<S66>/Output'

  u0 = std::fmod(std::floor(INS_DWork.Output_DSTATE), 4.2949673E+9F);

  // BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
  //   DataTypeConversion: '<S66>/Data Type Conversion'
  //   Outport: '<Root>/INS_Out'
  //   Selector: '<S56>/Selector2'
  //   Trigonometry: '<S63>/Trigonometric Function1'

  INS_Y.INS_Out.timestamp_ms = u0 < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-u0 :
    (uint32_T)u0;
  INS_Y.INS_Out.phi = std::atan2(rtb_Transpose2[7], rtb_Transpose2[8]);

  // Gain: '<S63>/Gain5' incorporates:
  //   Selector: '<S56>/Selector2'

  u0 = INS_P.Gain5_Gain_d * rtb_Transpose2[6];

  // Saturate: '<S63>/Saturation1'
  if (u0 > INS_P.Saturation1_UpperSat) {
    u0 = INS_P.Saturation1_UpperSat;
  } else {
    if (u0 < INS_P.Saturation1_LowerSat) {
      u0 = INS_P.Saturation1_LowerSat;
    }
  }

  // End of Saturate: '<S63>/Saturation1'

  // Trigonometry: '<S63>/Trigonometric Function'
  if (u0 > 1.0F) {
    u0 = 1.0F;
  } else {
    if (u0 < -1.0F) {
      u0 = -1.0F;
    }
  }

  // BusCreator: '<Root>/BusConversion_InsertedFor_INS_Out_at_inport_0' incorporates:
  //   DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Gain: '<S117>/Gain'
  //   Gain: '<S65>/Gain'
  //   Outport: '<Root>/INS_Out'
  //   Trigonometry: '<S63>/Trigonometric Function'
  //   Trigonometry: '<S65>/Trigonometric Function1'

  INS_Y.INS_Out.theta = std::asin(u0);
  INS_Y.INS_Out.psi = std::atan2(rtb_DiscreteTimeIntegrator1_h_0 *
    INS_P.Gain_Gain_h, rtb_DiscreteTimeIntegrator1_h_i);
  INS_Y.INS_Out.p = rtb_raw_gyro[0];
  INS_Y.INS_Out.q = rtb_raw_gyro[1];
  INS_Y.INS_Out.r = rtb_raw_gyro[2];
  INS_Y.INS_Out.sfor_x = INS_DWork.DiscreteTimeIntegrator1_DSTATE[0];
  INS_Y.INS_Out.sfor_y = INS_DWork.DiscreteTimeIntegrator1_DSTATE[1];
  INS_Y.INS_Out.sfor_z = INS_DWork.DiscreteTimeIntegrator1_DSTATE[2];
  INS_Y.INS_Out.velN = INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0];
  INS_Y.INS_Out.velE = INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1];
  INS_Y.INS_Out.velD = INS_P.Gain_Gain_m *
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_p;
  INS_Y.INS_Out.x_R_m = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0];
  INS_Y.INS_Out.y_R_m = INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1];
  INS_Y.INS_Out.h_R_m = INS_DWork.DiscreteTimeIntegrator2_DSTAT_k;

  // DiscreteFir: '<S5>/Discrete FIR Filter' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'

  rtb_vel_E = INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] *
    INS_P.DiscreteFIRFilter_Coefficients[0];
  q0 = 1;
  for (j = INS_DWork.DiscreteFIRFilter_circBuf; j < 3; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  for (j = 0; j < INS_DWork.DiscreteFIRFilter_circBuf; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  rtb_DiscreteFIRFilter[0] = rtb_vel_E;
  rtb_vel_E = INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] *
    INS_P.DiscreteFIRFilter_Coefficients[0];
  q0 = 1;
  for (j = INS_DWork.DiscreteFIRFilter_circBuf; j < 3; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[3 + j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  for (j = 0; j < INS_DWork.DiscreteFIRFilter_circBuf; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[3 + j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  rtb_DiscreteFIRFilter[1] = rtb_vel_E;
  rtb_vel_E = INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] *
    INS_P.DiscreteFIRFilter_Coefficients[0];
  q0 = 1;
  for (j = INS_DWork.DiscreteFIRFilter_circBuf; j < 3; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[6 + j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  for (j = 0; j < INS_DWork.DiscreteFIRFilter_circBuf; j++) {
    rtb_vel_E += INS_DWork.DiscreteFIRFilter_states[6 + j] *
      INS_P.DiscreteFIRFilter_Coefficients[q0];
    q0++;
  }

  // Switch: '<S12>/Switch' incorporates:
  //   Constant: '<S12>/Constant3'
  //   Constant: '<S38>/Constant'
  //   Math: '<S12>/Math Function'
  //   RelationalOperator: '<S38>/Compare'
  //   Sum: '<S12>/Sum of Elements'

  if ((rtb_Sum2_g[0] * rtb_Sum2_g[0] + rtb_Sum2_g[1] * rtb_Sum2_g[1]) +
      rtb_Sum2_g[2] * rtb_Sum2_g[2] > INS_P.CompareToConstant_const_a) {
    rtb_VectorConcatenate2[0] = rtb_Sum2_g[0];
    rtb_VectorConcatenate2[1] = rtb_Sum2_g[1];
    rtb_VectorConcatenate2[2] = rtb_Sum2_g[2];
  } else {
    rtb_VectorConcatenate2[0] = INS_P.Constant3_Value[0];
    rtb_VectorConcatenate2[1] = INS_P.Constant3_Value[1];
    rtb_VectorConcatenate2[2] = INS_P.Constant3_Value[2];
  }

  // End of Switch: '<S12>/Switch'

  // Outputs for Enabled SubSystem: '<S5>/Attitude_Init' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (rtb_LogicalOperator_f) {
    // Gain: '<S8>/Gain'
    rtb_MatrixConcatenate1_idx_2 = INS_P.Gain_Gain_d * rtb_DiscreteFIRFilter[0];

    // Math: '<S22>/Math Function'
    rtb_MathFunction_e_idx_0 = rtb_MatrixConcatenate1_idx_2 *
      rtb_MatrixConcatenate1_idx_2;

    // Gain: '<S8>/Gain'
    rtb_DiscreteFIRFilter[0] = rtb_MatrixConcatenate1_idx_2;
    rtb_MatrixConcatenate1_idx_2 = INS_P.Gain_Gain_d * rtb_DiscreteFIRFilter[1];

    // Math: '<S22>/Math Function'
    rtb_MathFunction_e_idx_1 = rtb_MatrixConcatenate1_idx_2 *
      rtb_MatrixConcatenate1_idx_2;

    // Gain: '<S8>/Gain' incorporates:
    //   DiscreteFir: '<S5>/Discrete FIR Filter'

    rtb_DiscreteFIRFilter[1] = rtb_MatrixConcatenate1_idx_2;
    rtb_MatrixConcatenate1_idx_2 = INS_P.Gain_Gain_d * rtb_vel_E;

    // Sqrt: '<S22>/Sqrt' incorporates:
    //   Math: '<S22>/Math Function'
    //   Sum: '<S22>/Sum of Elements'

    rtb_az_bias = std::sqrt((rtb_MathFunction_e_idx_0 + rtb_MathFunction_e_idx_1)
      + rtb_MatrixConcatenate1_idx_2 * rtb_MatrixConcatenate1_idx_2);

    // MinMax: '<S16>/Max' incorporates:
    //   Constant: '<S16>/Constant2'

    if (rtb_az_bias <= INS_P.Constant2_Value) {
      rtb_az_bias = INS_P.Constant2_Value;
    }

    // End of MinMax: '<S16>/Max'

    // Product: '<S16>/Divide'
    rtb_DiscreteFIRFilter[0] /= rtb_az_bias;
    rtb_DiscreteFIRFilter[1] /= rtb_az_bias;
    rtb_MatrixConcatenate1_idx_2 /= rtb_az_bias;

    // SignalConversion: '<S23>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
    //   Product: '<S13>/Product'
    //   Product: '<S13>/Product1'
    //   Product: '<S13>/Product2'
    //   Product: '<S13>/Product3'
    //   Product: '<S13>/Product4'
    //   Product: '<S13>/Product5'
    //   Sum: '<S13>/Subtract'
    //   Sum: '<S13>/Subtract1'
    //   Sum: '<S13>/Subtract2'

    rtb_DiscreteTimeIntegrator1_h_i = rtb_DiscreteFIRFilter[1] *
      rtb_VectorConcatenate2[2] - rtb_MatrixConcatenate1_idx_2 *
      rtb_VectorConcatenate2[1];
    rtb_DiscreteTimeIntegrator1_h_0 = rtb_MatrixConcatenate1_idx_2 *
      rtb_VectorConcatenate2[0] - rtb_DiscreteFIRFilter[0] *
      rtb_VectorConcatenate2[2];
    rtb_DiscreteTimeIntegrator1_h_1 = rtb_DiscreteFIRFilter[0] *
      rtb_VectorConcatenate2[1] - rtb_DiscreteFIRFilter[1] *
      rtb_VectorConcatenate2[0];

    // Sqrt: '<S23>/Sqrt' incorporates:
    //   Math: '<S23>/Math Function'
    //   Sum: '<S23>/Sum of Elements'

    rtb_az_bias = std::sqrt((rtb_DiscreteTimeIntegrator1_h_i *
      rtb_DiscreteTimeIntegrator1_h_i + rtb_DiscreteTimeIntegrator1_h_0 *
      rtb_DiscreteTimeIntegrator1_h_0) + rtb_DiscreteTimeIntegrator1_h_1 *
      rtb_DiscreteTimeIntegrator1_h_1);

    // MinMax: '<S17>/Max' incorporates:
    //   Constant: '<S17>/Constant2'

    if (rtb_az_bias <= INS_P.Constant2_Value_m) {
      rtb_az_bias = INS_P.Constant2_Value_m;
    }

    // End of MinMax: '<S17>/Max'

    // Product: '<S17>/Divide'
    rtb_vel_E = rtb_DiscreteTimeIntegrator1_h_i / rtb_az_bias;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn2'
    rtb_M_BO[3] = rtb_vel_E;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn3'
    rtb_M_BO[6] = rtb_DiscreteFIRFilter[0];

    // Product: '<S17>/Divide'
    rtb_DiscreteTimeIntegrator1_h_i = rtb_vel_E;
    rtb_vel_E = rtb_DiscreteTimeIntegrator1_h_0 / rtb_az_bias;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn2'
    rtb_M_BO[4] = rtb_vel_E;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn3'
    rtb_M_BO[7] = rtb_DiscreteFIRFilter[1];

    // Product: '<S17>/Divide'
    rtb_DiscreteTimeIntegrator1_h_0 = rtb_vel_E;
    rtb_vel_E = rtb_DiscreteTimeIntegrator1_h_1 / rtb_az_bias;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn2'
    rtb_M_BO[5] = rtb_vel_E;

    // SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn3'
    rtb_M_BO[8] = rtb_MatrixConcatenate1_idx_2;

    // Reshape: '<S14>/Column Vector' incorporates:
    //   Product: '<S14>/Product'
    //   Product: '<S14>/Product1'
    //   Product: '<S14>/Product2'
    //   Product: '<S14>/Product3'
    //   Product: '<S14>/Product4'
    //   Product: '<S14>/Product5'
    //   Sum: '<S14>/Subtract'
    //   Sum: '<S14>/Subtract1'
    //   Sum: '<S14>/Subtract2'

    rtb_M_BO[0] = rtb_DiscreteTimeIntegrator1_h_0 * rtb_MatrixConcatenate1_idx_2
      - rtb_vel_E * rtb_DiscreteFIRFilter[1];
    rtb_M_BO[1] = rtb_vel_E * rtb_DiscreteFIRFilter[0] -
      rtb_DiscreteTimeIntegrator1_h_i * rtb_MatrixConcatenate1_idx_2;
    rtb_M_BO[2] = rtb_DiscreteTimeIntegrator1_h_i * rtb_DiscreteFIRFilter[1] -
      rtb_DiscreteTimeIntegrator1_h_0 * rtb_DiscreteFIRFilter[0];

    // Math: '<S8>/Math Function'
    for (q0 = 0; q0 < 3; q0++) {
      rtb_MathFunction_mj[3 * q0] = rtb_M_BO[q0];
      rtb_MathFunction_mj[1 + 3 * q0] = rtb_M_BO[q0 + 3];
      rtb_MathFunction_mj[2 + 3 * q0] = rtb_M_BO[q0 + 6];
    }

    // End of Math: '<S8>/Math Function'

    // If: '<S15>/If' incorporates:
    //   Selector: '<S15>/Selector'
    //   Selector: '<S15>/Selector1'
    //   Selector: '<S15>/Selector2'
    //   Sum: '<S15>/Sum'
    //   Sum: '<S15>/Sum1'
    //   Sum: '<S15>/Sum2'

    if ((rtb_MathFunction_mj[0] + rtb_MathFunction_mj[4]) + rtb_MathFunction_mj
        [8] >= 0.0F) {
      // Outputs for IfAction SubSystem: '<S15>/If Action Subsystem' incorporates:
      //   ActionPort: '<S18>/Action Port'

      // Gain: '<S18>/Gain' incorporates:
      //   Constant: '<S18>/Constant'
      //   Selector: '<S18>/Selector'
      //   Selector: '<S18>/Selector1'
      //   Selector: '<S18>/Selector2'
      //   Sum: '<S18>/Add'

      rtb_az_bias = (((INS_P.Constant_Value_i + rtb_MathFunction_mj[0]) +
                      rtb_MathFunction_mj[4]) + rtb_MathFunction_mj[8]) *
        INS_P.Gain_Gain_a;

      // MinMax: '<S18>/MinMax' incorporates:
      //   Constant: '<S18>/Protection'

      if (INS_P.Protection_Value > rtb_az_bias) {
        rtb_az_bias = INS_P.Protection_Value;
      }

      // End of MinMax: '<S18>/MinMax'

      // Sqrt: '<S18>/Sqrt'
      rtb_az_bias = std::sqrt(rtb_az_bias);

      // SignalConversion: '<S18>/ConcatBufferAtVector ConcatenateIn1' incorporates:
      //   SignalConversion: '<S8>/OutportBufferForq_OB'

      INS_B.OutportBufferForq_OB[0] = rtb_az_bias;

      // Product: '<S18>/Divide' incorporates:
      //   Gain: '<S18>/Gain1'
      //   Selector: '<S18>/Selector3'
      //   Selector: '<S18>/Selector4'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S18>/Add1'

      INS_B.OutportBufferForq_OB[3] = (rtb_MathFunction_mj[1] -
        rtb_MathFunction_mj[3]) * INS_P.Gain1_Gain_l / rtb_az_bias;

      // Product: '<S18>/Divide1' incorporates:
      //   Gain: '<S18>/Gain2'
      //   Selector: '<S18>/Selector5'
      //   Selector: '<S18>/Selector6'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S18>/Add2'

      INS_B.OutportBufferForq_OB[1] = (rtb_MathFunction_mj[5] -
        rtb_MathFunction_mj[7]) * INS_P.Gain2_Gain_j / rtb_az_bias;

      // Product: '<S18>/Divide2' incorporates:
      //   Gain: '<S18>/Gain3'
      //   Selector: '<S18>/Selector7'
      //   Selector: '<S18>/Selector8'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S18>/Add3'

      INS_B.OutportBufferForq_OB[2] = (rtb_MathFunction_mj[6] -
        rtb_MathFunction_mj[2]) * INS_P.Gain3_Gain / rtb_az_bias;

      // End of Outputs for SubSystem: '<S15>/If Action Subsystem'
    } else if ((rtb_MathFunction_mj[0] - rtb_MathFunction_mj[4]) -
               rtb_MathFunction_mj[8] >= 0.0F) {
      // Outputs for IfAction SubSystem: '<S15>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S19>/Action Port'

      // Gain: '<S19>/Gain' incorporates:
      //   Constant: '<S19>/Constant'
      //   Selector: '<S19>/Selector'
      //   Selector: '<S19>/Selector1'
      //   Selector: '<S19>/Selector2'
      //   Sum: '<S19>/Add'

      rtb_az_bias = (((INS_P.Constant_Value_d + rtb_MathFunction_mj[0]) -
                      rtb_MathFunction_mj[4]) - rtb_MathFunction_mj[8]) *
        INS_P.Gain_Gain_p;

      // MinMax: '<S19>/MinMax' incorporates:
      //   Constant: '<S19>/Protection'

      if (INS_P.Protection_Value_j > rtb_az_bias) {
        rtb_az_bias = INS_P.Protection_Value_j;
      }

      // End of MinMax: '<S19>/MinMax'

      // Sqrt: '<S19>/Sqrt'
      rtb_az_bias = std::sqrt(rtb_az_bias);

      // SignalConversion: '<S19>/ConcatBufferAtVector ConcatenateIn2' incorporates:
      //   SignalConversion: '<S8>/OutportBufferForq_OB'

      INS_B.OutportBufferForq_OB[1] = rtb_az_bias;

      // Product: '<S19>/Divide' incorporates:
      //   Gain: '<S19>/Gain1'
      //   Selector: '<S19>/Selector3'
      //   Selector: '<S19>/Selector4'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S19>/Add1'

      INS_B.OutportBufferForq_OB[2] = (rtb_MathFunction_mj[3] +
        rtb_MathFunction_mj[1]) * INS_P.Gain1_Gain_h / rtb_az_bias;

      // Product: '<S19>/Divide1' incorporates:
      //   Gain: '<S19>/Gain2'
      //   Selector: '<S19>/Selector5'
      //   Selector: '<S19>/Selector6'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S19>/Add2'

      INS_B.OutportBufferForq_OB[0] = (rtb_MathFunction_mj[5] -
        rtb_MathFunction_mj[7]) * INS_P.Gain2_Gain_o / rtb_az_bias;

      // Product: '<S19>/Divide2' incorporates:
      //   Gain: '<S19>/Gain3'
      //   Selector: '<S19>/Selector7'
      //   Selector: '<S19>/Selector8'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S19>/Add3'

      INS_B.OutportBufferForq_OB[3] = (rtb_MathFunction_mj[6] +
        rtb_MathFunction_mj[2]) * INS_P.Gain3_Gain_j / rtb_az_bias;

      // End of Outputs for SubSystem: '<S15>/If Action Subsystem1'
    } else if ((rtb_MathFunction_mj[4] - rtb_MathFunction_mj[0]) -
               rtb_MathFunction_mj[8] >= 0.0F) {
      // Outputs for IfAction SubSystem: '<S15>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S20>/Action Port'

      // Gain: '<S20>/Gain4' incorporates:
      //   Constant: '<S20>/Constant'
      //   Selector: '<S20>/Selector'
      //   Selector: '<S20>/Selector1'
      //   Selector: '<S20>/Selector2'
      //   Sum: '<S20>/Add'

      rtb_az_bias = (((INS_P.Constant_Value_j - rtb_MathFunction_mj[0]) +
                      rtb_MathFunction_mj[4]) - rtb_MathFunction_mj[8]) *
        INS_P.Gain4_Gain;

      // MinMax: '<S20>/MinMax1' incorporates:
      //   Constant: '<S20>/Protection'

      if (INS_P.Protection_Value_i > rtb_az_bias) {
        rtb_az_bias = INS_P.Protection_Value_i;
      }

      // End of MinMax: '<S20>/MinMax1'

      // Sqrt: '<S20>/Sqrt1'
      rtb_az_bias = std::sqrt(rtb_az_bias);

      // SignalConversion: '<S20>/ConcatBufferAtVector ConcatenateIn3' incorporates:
      //   SignalConversion: '<S8>/OutportBufferForq_OB'

      INS_B.OutportBufferForq_OB[2] = rtb_az_bias;

      // Product: '<S20>/Divide' incorporates:
      //   Gain: '<S20>/Gain1'
      //   Selector: '<S20>/Selector3'
      //   Selector: '<S20>/Selector4'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S20>/Add1'

      INS_B.OutportBufferForq_OB[1] = (rtb_MathFunction_mj[3] +
        rtb_MathFunction_mj[1]) * INS_P.Gain1_Gain_j / rtb_az_bias;

      // Product: '<S20>/Divide1' incorporates:
      //   Gain: '<S20>/Gain2'
      //   Selector: '<S20>/Selector5'
      //   Selector: '<S20>/Selector6'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S20>/Add2'

      INS_B.OutportBufferForq_OB[3] = (rtb_MathFunction_mj[7] +
        rtb_MathFunction_mj[5]) * INS_P.Gain2_Gain_l / rtb_az_bias;

      // Product: '<S20>/Divide2' incorporates:
      //   Gain: '<S20>/Gain3'
      //   Selector: '<S20>/Selector7'
      //   Selector: '<S20>/Selector8'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S20>/Add3'

      INS_B.OutportBufferForq_OB[0] = (rtb_MathFunction_mj[6] -
        rtb_MathFunction_mj[2]) * INS_P.Gain3_Gain_c / rtb_az_bias;

      // End of Outputs for SubSystem: '<S15>/If Action Subsystem2'
    } else {
      // Outputs for IfAction SubSystem: '<S15>/If Action Subsystem3' incorporates:
      //   ActionPort: '<S21>/Action Port'

      // Gain: '<S21>/Gain' incorporates:
      //   Constant: '<S21>/Constant'
      //   Selector: '<S21>/Selector'
      //   Selector: '<S21>/Selector1'
      //   Selector: '<S21>/Selector2'
      //   Sum: '<S21>/Add'

      rtb_az_bias = (((INS_P.Constant_Value_i0 - rtb_MathFunction_mj[0]) -
                      rtb_MathFunction_mj[4]) + rtb_MathFunction_mj[8]) *
        INS_P.Gain_Gain_c;

      // MinMax: '<S21>/MinMax' incorporates:
      //   Constant: '<S21>/Protection'

      if (INS_P.Protection_Value_a > rtb_az_bias) {
        rtb_az_bias = INS_P.Protection_Value_a;
      }

      // End of MinMax: '<S21>/MinMax'

      // Sqrt: '<S21>/Sqrt'
      rtb_az_bias = std::sqrt(rtb_az_bias);

      // SignalConversion: '<S21>/ConcatBufferAtVector ConcatenateIn4' incorporates:
      //   SignalConversion: '<S8>/OutportBufferForq_OB'

      INS_B.OutportBufferForq_OB[3] = rtb_az_bias;

      // Product: '<S21>/Divide' incorporates:
      //   Gain: '<S21>/Gain1'
      //   Selector: '<S21>/Selector3'
      //   Selector: '<S21>/Selector4'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S21>/Add1'

      INS_B.OutportBufferForq_OB[0] = (rtb_MathFunction_mj[1] -
        rtb_MathFunction_mj[3]) * INS_P.Gain1_Gain_k / rtb_az_bias;

      // Product: '<S21>/Divide1' incorporates:
      //   Gain: '<S21>/Gain2'
      //   Selector: '<S21>/Selector5'
      //   Selector: '<S21>/Selector6'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S21>/Add2'

      INS_B.OutportBufferForq_OB[2] = (rtb_MathFunction_mj[7] +
        rtb_MathFunction_mj[5]) * INS_P.Gain2_Gain_ju / rtb_az_bias;

      // Product: '<S21>/Divide2' incorporates:
      //   Gain: '<S21>/Gain3'
      //   Selector: '<S21>/Selector7'
      //   Selector: '<S21>/Selector8'
      //   SignalConversion: '<S8>/OutportBufferForq_OB'
      //   Sum: '<S21>/Add3'

      INS_B.OutportBufferForq_OB[1] = (rtb_MathFunction_mj[6] +
        rtb_MathFunction_mj[2]) * INS_P.Gain3_Gain_h / rtb_az_bias;

      // End of Outputs for SubSystem: '<S15>/If Action Subsystem3'
    }

    // End of If: '<S15>/If'
  }

  // End of Outputs for SubSystem: '<S5>/Attitude_Init'
  for (q0 = 0; q0 < 3; q0++) {
    // Product: '<S44>/Multiply' incorporates:
    //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
    //   Product: '<S111>/Multiply'

    rtb_VectorConcatenate2[q0] = rtb_MatrixConcatenate3[q0 + 6] *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] + (rtb_MatrixConcatenate3[q0 +
      3] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +
      rtb_MatrixConcatenate3[q0] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]);
  }

  // DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
  //   Product: '<S44>/Multiply'

  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_o != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[0] = rtb_VectorConcatenate2[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[1] = rtb_VectorConcatenate2[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[2] = rtb_VectorConcatenate2[2];
  }

  rtb_MathFunction_e_idx_0 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[0];
  rtb_MathFunction_e_idx_1 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[1];
  rtb_MathFunction_e_idx_2 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[2];

  // Relay: '<S43>/Relay'
  if (rtb_Double >= INS_P.Relay_OnVal) {
    INS_DWork.Relay_Mode = true;
  } else {
    if (rtb_Double <= INS_P.Relay_OffVal) {
      INS_DWork.Relay_Mode = false;
    }
  }

  if (INS_DWork.Relay_Mode) {
    u0 = INS_P.Relay_YOn;
  } else {
    u0 = INS_P.Relay_YOff;
  }

  // End of Relay: '<S43>/Relay'

  // Logic: '<S43>/Logical Operator1'
  rtb_LogicalOperator1_fk = (rtb_mag_init_valid && (u0 != 0.0F));

  // Product: '<S43>/Multiply2' incorporates:
  //   Constant: '<S43>/GPS_Delay'

  rtb_az_bias = rtb_LogicalOperator1_fk ? (real32_T)INS_P.GPS_Delay_Value : 0.0F;

  // Delay: '<S39>/Delay' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'

  if (rtb_az_bias < 1.0F) {
    rtb_DiscreteFIRFilter[0] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[0];
    rtb_DiscreteFIRFilter[1] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[1];
    rtb_DiscreteFIRFilter[2] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[2];
  } else {
    if (rtb_az_bias > 200.0F) {
      q0 = 200;
    } else {
      q0 = (int32_T)std::fmod(rtb_az_bias, 4.2949673E+9F);
    }

    q0 = (int32_T)(200U - q0) * 3;
    rtb_DiscreteFIRFilter[0] = INS_DWork.Delay_DSTATE[q0];
    rtb_DiscreteFIRFilter[1] = INS_DWork.Delay_DSTATE[1 + q0];
    rtb_DiscreteFIRFilter[2] = INS_DWork.Delay_DSTATE[2 + q0];
  }

  // End of Delay: '<S39>/Delay'

  // Sum: '<S46>/Sum of Elements' incorporates:
  //   Math: '<S46>/Math Function'

  rtb_az_bias = (rtb_DiscreteFIRFilter[0] * rtb_DiscreteFIRFilter[0] +
                 rtb_DiscreteFIRFilter[1] * rtb_DiscreteFIRFilter[1]) +
    rtb_DiscreteFIRFilter[2] * rtb_DiscreteFIRFilter[2];

  // Math: '<S46>/Math Function1'
  //
  //  About '<S46>/Math Function1':
  //   Operator: sqrt

  if (rtb_az_bias < 0.0F) {
    rtb_az_bias = -std::sqrt(std::abs(rtb_az_bias));
  } else {
    rtb_az_bias = std::sqrt(rtb_az_bias);
  }

  // End of Math: '<S46>/Math Function1'

  // Switch: '<S46>/Switch' incorporates:
  //   Constant: '<S46>/Constant'
  //   Product: '<S46>/Product'

  if (rtb_az_bias > INS_P.Switch_Threshold) {
    rtb_MatrixConcatenate1_idx_0 = rtb_DiscreteFIRFilter[0];
    rtb_MatrixConcatenate1_idx_1 = rtb_DiscreteFIRFilter[1];
    rtb_MatrixConcatenate1_idx_2 = rtb_DiscreteFIRFilter[2];
  } else {
    rtb_MatrixConcatenate1_idx_0 = 0.0F;
    rtb_MatrixConcatenate1_idx_1 = 0.0F;
    rtb_MatrixConcatenate1_idx_2 = 0.0F;
    rtb_az_bias = INS_P.Constant_Value_f;
  }

  // End of Switch: '<S46>/Switch'

  // Product: '<S46>/Divide1'
  rtb_MathFunction_k_idx_0 = rtb_MatrixConcatenate1_idx_0 / rtb_az_bias;
  rtb_MathFunction_k_idx_1 = rtb_MatrixConcatenate1_idx_1 / rtb_az_bias;
  rtb_MathFunction_k_idx_2 = rtb_MatrixConcatenate1_idx_2 / rtb_az_bias;

  // Gain: '<S306>/Gain' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_SumofElements = (real32_T)INS_P.Gain_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velN;

  // Gain: '<S306>/Gain1' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_vel_E = (real32_T)INS_P.Gain1_Gain_c * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velE;

  // Gain: '<S306>/Gain2' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  rtb_vel_D = (real32_T)INS_P.Gain2_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velD;

  // DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  if (INS_DWork.DiscreteTimeIntegrator_IC_LOA_e != 0) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_p[0] = rtb_SumofElements;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_p[1] = rtb_vel_E;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_p[2] = rtb_vel_D;
  }

  // Sum: '<S39>/Sum' incorporates:
  //   Constant: '<S39>/Constant'
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Product: '<S43>/Multiply'

  rtb_MatrixConcatenate1_idx_2 = INS_P.Constant_Value_e[0] +
    (rtb_LogicalOperator1_fk ? INS_DWork.DiscreteTimeIntegrator_DSTATE_p[0] :
     0.0F);

  // Math: '<S47>/Math Function'
  rtb_DiscreteTimeIntegrator1_h_i = rtb_MatrixConcatenate1_idx_2 *
    rtb_MatrixConcatenate1_idx_2;

  // Sum: '<S39>/Sum' incorporates:
  //   Constant: '<S39>/Constant'
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Product: '<S43>/Multiply'

  rtb_DiscreteFIRFilter[0] = rtb_MatrixConcatenate1_idx_2;
  rtb_MatrixConcatenate1_idx_2 = INS_P.Constant_Value_e[1] +
    (rtb_LogicalOperator1_fk ? INS_DWork.DiscreteTimeIntegrator_DSTATE_p[1] :
     0.0F);

  // Math: '<S47>/Math Function'
  rtb_DiscreteTimeIntegrator1_h_0 = rtb_MatrixConcatenate1_idx_2 *
    rtb_MatrixConcatenate1_idx_2;

  // Sum: '<S39>/Sum' incorporates:
  //   Constant: '<S39>/Constant'
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Product: '<S43>/Multiply'

  rtb_DiscreteFIRFilter[1] = rtb_MatrixConcatenate1_idx_2;
  rtb_MatrixConcatenate1_idx_2 = INS_P.Constant_Value_e[2] +
    (rtb_LogicalOperator1_fk ? INS_DWork.DiscreteTimeIntegrator_DSTATE_p[2] :
     0.0F);

  // Sum: '<S47>/Sum of Elements' incorporates:
  //   Math: '<S47>/Math Function'

  rtb_az_bias = (rtb_DiscreteTimeIntegrator1_h_i +
                 rtb_DiscreteTimeIntegrator1_h_0) + rtb_MatrixConcatenate1_idx_2
    * rtb_MatrixConcatenate1_idx_2;

  // Math: '<S47>/Math Function1'
  //
  //  About '<S47>/Math Function1':
  //   Operator: sqrt

  if (rtb_az_bias < 0.0F) {
    rtb_az_bias = -std::sqrt(std::abs(rtb_az_bias));
  } else {
    rtb_az_bias = std::sqrt(rtb_az_bias);
  }

  // End of Math: '<S47>/Math Function1'

  // Switch: '<S47>/Switch' incorporates:
  //   Constant: '<S47>/Constant'
  //   Product: '<S47>/Product'

  if (rtb_az_bias > INS_P.Switch_Threshold_b) {
    rtb_MatrixConcatenate1_idx_0 = rtb_DiscreteFIRFilter[0];
    rtb_MatrixConcatenate1_idx_1 = rtb_DiscreteFIRFilter[1];
  } else {
    rtb_MatrixConcatenate1_idx_0 = 0.0F;
    rtb_MatrixConcatenate1_idx_1 = 0.0F;
    rtb_MatrixConcatenate1_idx_2 = 0.0F;
    rtb_az_bias = INS_P.Constant_Value_a;
  }

  // End of Switch: '<S47>/Switch'

  // Product: '<S47>/Divide1'
  rtb_DiscreteTimeIntegrator1_h_i = rtb_MatrixConcatenate1_idx_0 / rtb_az_bias;
  rtb_DiscreteTimeIntegrator1_h_0 = rtb_MatrixConcatenate1_idx_1 / rtb_az_bias;
  rtb_DiscreteTimeIntegrator1_h_1 = rtb_MatrixConcatenate1_idx_2 / rtb_az_bias;

  // Sum: '<S45>/Subtract' incorporates:
  //   Product: '<S45>/Product'
  //   Product: '<S45>/Product1'

  u0 = rtb_MathFunction_k_idx_1 * rtb_DiscreteTimeIntegrator1_h_1 -
    rtb_MathFunction_k_idx_2 * rtb_DiscreteTimeIntegrator1_h_0;

  // Saturate: '<S42>/Saturation'
  if (u0 > INS_P.Saturation_UpperSat_c) {
    u0 = INS_P.Saturation_UpperSat_c;
  } else {
    if (u0 < INS_P.Saturation_LowerSat_d) {
      u0 = INS_P.Saturation_LowerSat_d;
    }
  }

  // Sum: '<S45>/Subtract1' incorporates:
  //   Product: '<S45>/Product2'
  //   Product: '<S45>/Product3'

  rtb_MatrixConcatenate1_idx_1 = rtb_MathFunction_k_idx_2 *
    rtb_DiscreteTimeIntegrator1_h_i - rtb_MathFunction_k_idx_0 *
    rtb_DiscreteTimeIntegrator1_h_1;

  // Saturate: '<S42>/Saturation'
  if (rtb_MatrixConcatenate1_idx_1 > INS_P.Saturation_UpperSat_c) {
    rtb_MatrixConcatenate1_idx_1 = INS_P.Saturation_UpperSat_c;
  } else {
    if (rtb_MatrixConcatenate1_idx_1 < INS_P.Saturation_LowerSat_d) {
      rtb_MatrixConcatenate1_idx_1 = INS_P.Saturation_LowerSat_d;
    }
  }

  // Sum: '<S45>/Subtract2' incorporates:
  //   Product: '<S45>/Product4'
  //   Product: '<S45>/Product5'

  rtb_MatrixConcatenate1_idx_0 = rtb_MathFunction_k_idx_0 *
    rtb_DiscreteTimeIntegrator1_h_0 - rtb_MathFunction_k_idx_1 *
    rtb_DiscreteTimeIntegrator1_h_i;

  // Saturate: '<S42>/Saturation'
  if (rtb_MatrixConcatenate1_idx_0 > INS_P.Saturation_UpperSat_c) {
    rtb_MatrixConcatenate1_idx_0 = INS_P.Saturation_UpperSat_c;
  } else {
    if (rtb_MatrixConcatenate1_idx_0 < INS_P.Saturation_LowerSat_d) {
      rtb_MatrixConcatenate1_idx_0 = INS_P.Saturation_LowerSat_d;
    }
  }

  // Sum: '<S48>/Subtract' incorporates:
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'

  rtb_MathFunction_k_idx_0 = rtb_SumofElements -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0];
  rtb_MathFunction_k_idx_1 = rtb_vel_E -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1];
  rtb_MathFunction_k_idx_2 = rtb_vel_D -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2];

  // Sum: '<S48>/Add' incorporates:
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Gain: '<S48>/Gain2'

  rtb_DiscreteTimeIntegrator1_h_i = INS_P.Gain2_Gain_k *
    rtb_MathFunction_k_idx_0 + INS_DWork.DiscreteTimeIntegrator_DSTATE_p[0];

  // Gain: '<S49>/Gain' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
  //   Product: '<S44>/Multiply'
  //   Sum: '<S49>/Sum'

  rtb_vel_D = (rtb_VectorConcatenate2[0] -
               INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[0]) * INS_P.Gain_Gain_j;

  // Sum: '<S48>/Add' incorporates:
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Gain: '<S48>/Gain2'

  rtb_DiscreteTimeIntegrator1_h_0 = INS_P.Gain2_Gain_k *
    rtb_MathFunction_k_idx_1 + INS_DWork.DiscreteTimeIntegrator_DSTATE_p[1];

  // Gain: '<S49>/Gain' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
  //   Product: '<S44>/Multiply'
  //   Sum: '<S49>/Sum'

  rtb_Gain_p_idx_1 = (rtb_VectorConcatenate2[1] -
                      INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[1]) *
    INS_P.Gain_Gain_j;

  // Sum: '<S48>/Add' incorporates:
  //   DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  //   Gain: '<S48>/Gain2'

  rtb_DiscreteTimeIntegrator1_h_1 = INS_P.Gain2_Gain_k *
    rtb_MathFunction_k_idx_2 + INS_DWork.DiscreteTimeIntegrator_DSTATE_p[2];

  // Gain: '<S49>/Gain' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
  //   Product: '<S44>/Multiply'
  //   Sum: '<S49>/Sum'

  rtb_Gain_p_idx_2 = (rtb_VectorConcatenate2[2] -
                      INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[2]) *
    INS_P.Gain_Gain_j;

  // RelationalOperator: '<S50>/Compare' incorporates:
  //   Constant: '<S50>/Constant'
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Math: '<S51>/Math Function'
  //   Sqrt: '<S51>/Sqrt'
  //   Sum: '<S51>/Sum of Elements'

  rtb_mag_init_valid = (std::sqrt((INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] +
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[1]) +
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] *
    INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]) >
                        INS_P.CompareToConstant_const_n);

  // Gain: '<S52>/mag_gain' incorporates:
  //   Product: '<S52>/MX Product4'
  //   Selector: '<S52>/Selector4'

  rtb_az_bias = ((rtb_MatrixConcatenate3[1] * rtb_Sum2_g[0] +
                  rtb_MatrixConcatenate3[4] * rtb_Sum2_g[1]) +
                 rtb_MatrixConcatenate3[7] * rtb_Sum2_g[2]) *
    INS_P.mag_gain_Gain;

  // Sum: '<S6>/Sum' incorporates:
  //   Gain: '<S42>/Gain'
  //   Product: '<S52>/MX Product3'
  //   Selector: '<S52>/Selector2'

  rtb_MatrixConcatenate1_idx_2 = (rtb_LogicalOperator4 ? rtb_MatrixConcatenate3
    [2] * rtb_az_bias : 0.0F) + INS_P.Gain_Gain_o[0] * u0;
  rtb_MatrixConcatenate1_idx_1 = (rtb_LogicalOperator4 ? rtb_MatrixConcatenate3
    [5] * rtb_az_bias : 0.0F) + INS_P.Gain_Gain_o[1] *
    rtb_MatrixConcatenate1_idx_1;
  rtb_MatrixConcatenate1_idx_0 = (rtb_LogicalOperator4 ? rtb_MatrixConcatenate3
    [8] * rtb_az_bias : 0.0F) + INS_P.Gain_Gain_o[2] *
    rtb_MatrixConcatenate1_idx_0;
  for (q0 = 0; q0 < 3; q0++) {
    // Product: '<S6>/Multiply'
    rtb_az_bias = rtb_Transpose2[q0 + 6] * rtb_MatrixConcatenate1_idx_0 +
      (rtb_Transpose2[q0 + 3] * rtb_MatrixConcatenate1_idx_1 + rtb_Transpose2[q0]
       * rtb_MatrixConcatenate1_idx_2);

    // Gain: '<S40>/Gain1' incorporates:
    //   Product: '<S40>/MX Product1'

    u0 = INS_P.Gain1_Gain_o * (rtb_mag_init_valid ? rtb_az_bias : 0.0F);

    // Saturate: '<S40>/Saturation2'
    if (u0 > INS_P.Saturation2_UpperSat) {
      rtb_MathFunction_cp[q0] = INS_P.Saturation2_UpperSat;
    } else if (u0 < INS_P.Saturation2_LowerSat) {
      rtb_MathFunction_cp[q0] = INS_P.Saturation2_LowerSat;
    } else {
      rtb_MathFunction_cp[q0] = u0;
    }

    // End of Saturate: '<S40>/Saturation2'

    // Sum: '<S7>/Sum2'
    rtb_az_bias += rtb_raw_gyro[q0];

    // Product: '<S6>/Multiply'
    rtb_Sum2_g[q0] = rtb_az_bias;
  }

  // Sum: '<S58>/Add' incorporates:
  //   Constant: '<S54>/Constant'
  //   Product: '<S58>/Product'
  //   Product: '<S58>/Product1'
  //   Product: '<S58>/Product2'
  //   Product: '<S58>/Product3'

  rtb_MatrixConcatenate1_idx_0 = ((rtb_Product14 * INS_P.Constant_Value_c -
    rtb_Product15 * rtb_Sum2_g[0]) - rtb_Product12_k * rtb_Sum2_g[1]) -
    rtb_Product3_n * rtb_Sum2_g[2];

  // Sum: '<S58>/Add1' incorporates:
  //   Constant: '<S54>/Constant'
  //   Product: '<S58>/Product4'
  //   Product: '<S58>/Product5'
  //   Product: '<S58>/Product6'
  //   Product: '<S58>/Product7'

  rtb_MatrixConcatenate1_idx_1 = ((rtb_Product14 * rtb_Sum2_g[0] + rtb_Product15
    * INS_P.Constant_Value_c) + rtb_Product12_k * rtb_Sum2_g[2]) -
    rtb_Product3_n * rtb_Sum2_g[1];

  // Sum: '<S58>/Add2' incorporates:
  //   Constant: '<S54>/Constant'
  //   Product: '<S58>/Product10'
  //   Product: '<S58>/Product11'
  //   Product: '<S58>/Product8'
  //   Product: '<S58>/Product9'

  rtb_MatrixConcatenate1_idx_2 = ((rtb_Product14 * rtb_Sum2_g[1] - rtb_Product15
    * rtb_Sum2_g[2]) + rtb_Product12_k * INS_P.Constant_Value_c) +
    rtb_Product3_n * rtb_Sum2_g[0];

  // Product: '<S58>/Product14'
  rtb_Product14 *= rtb_Sum2_g[2];

  // Product: '<S58>/Product15'
  rtb_Product15 *= rtb_Sum2_g[1];

  // Product: '<S58>/Product12'
  rtb_Product12_k *= rtb_Sum2_g[0];

  // Sum: '<S58>/Add3' incorporates:
  //   Constant: '<S54>/Constant'
  //   Product: '<S58>/Product13'

  rtb_az_bias = ((rtb_Product14 + rtb_Product15) - rtb_Product12_k) +
    rtb_Product3_n * INS_P.Constant_Value_c;

  // Outputs for Enabled SubSystem: '<S74>/Subsystem' incorporates:
  //   EnablePort: '<S77>/Enable'

  if (rtb_LogicalOperator_f) {
    // RelationalOperator: '<S78>/Compare' incorporates:
    //   Constant: '<S78>/Constant'

    INS_B.Compare = ((int32_T)rtb_LogicalOperator4 >= (int32_T)
                     INS_P.CompareToConstant_const_kb);
  }

  // End of Outputs for SubSystem: '<S74>/Subsystem'

  // RelationalOperator: '<S88>/Compare' incorporates:
  //   Constant: '<S86>/Constant'
  //   Constant: '<S88>/Constant'
  //   RelationalOperator: '<S86>/Compare'

  rtb_mag_init_valid = ((int32_T)(rtb_Double > INS_P.CompareToConstant2_const_a)
                        > (int32_T)INS_P.Constant_Value_f4);

  // RelationalOperator: '<S93>/Compare' incorporates:
  //   Constant: '<S91>/Constant'
  //   Constant: '<S93>/Constant'
  //   RelationalOperator: '<S91>/Compare'

  rtb_LogicalOperator1_fk = ((int32_T)(rtb_Multiply_ki >
    INS_P.CompareToConstant2_const_j) > (int32_T)INS_P.Constant_Value_nl);

  // RelationalOperator: '<S98>/Compare' incorporates:
  //   Constant: '<S96>/Constant'
  //   Constant: '<S98>/Constant'
  //   RelationalOperator: '<S96>/Compare'

  rtb_LogicalOperator4 = ((int32_T)(rtb_h_vz > INS_P.CompareToConstant2_const_e)
    > (int32_T)INS_P.Constant_Value_pn);

  // RelationalOperator: '<S103>/Compare' incorporates:
  //   Constant: '<S101>/Constant'
  //   Constant: '<S103>/Constant'
  //   RelationalOperator: '<S101>/Compare'

  rtb_Compare_ea = ((int32_T)((int32_T)rtb_LogicalOperator4_c > (int32_T)
    INS_P.CompareToConstant2_const_l) > (int32_T)INS_P.Constant_Value_cd);

  // Saturate: '<S110>/Saturation2' incorporates:
  //   Delay: '<S110>/Delay'
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   Sum: '<S110>/Sum'

  u0 = rtb_gps_pos_R_m_idx_0 - INS_DWork.Delay_DSTATE_c[0];
  if (u0 > INS_P.Saturation2_UpperSat_l) {
    u0 = INS_P.Saturation2_UpperSat_l;
  } else {
    if (u0 < INS_P.Saturation2_LowerSat_n) {
      u0 = INS_P.Saturation2_LowerSat_n;
    }
  }

  // Sum: '<S110>/Add' incorporates:
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   Gain: '<S110>/Gain'

  rtb_Product15 = INS_P.Gain_Gain_g * u0 +
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0];

  // Saturate: '<S110>/Saturation2' incorporates:
  //   Delay: '<S110>/Delay'
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   Sum: '<S110>/Sum'

  u0 = rtb_gps_pos_R_m_idx_1 - INS_DWork.Delay_DSTATE_c[1];
  if (u0 > INS_P.Saturation2_UpperSat_l) {
    u0 = INS_P.Saturation2_UpperSat_l;
  } else {
    if (u0 < INS_P.Saturation2_LowerSat_n) {
      u0 = INS_P.Saturation2_LowerSat_n;
    }
  }

  // Sum: '<S110>/Add' incorporates:
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   Gain: '<S110>/Gain'

  rtb_Product12_k = INS_P.Gain_Gain_g * u0 +
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1];

  // Switch: '<S111>/Switch' incorporates:
  //   Delay: '<S111>/Delay'
  //   DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
  //   Inport: '<Root>/GPS_uBlox'
  //   Memory: '<S111>/Memory'
  //   RelationalOperator: '<S112>/FixPt Relational Operator'
  //   Sum: '<S111>/Sum'
  //   UnitDelay: '<S112>/Delay Input1'

  if (INS_U.GPS_uBlox.timestamp_ms > INS_DWork.DelayInput1_DSTATE_j) {
    rtb_gps_pos_R_m_idx_0 = INS_DWork.Delay_DSTATE_m[0] -
      INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0];
    rtb_gps_pos_R_m_idx_1 = INS_DWork.Delay_DSTATE_m[1] -
      INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1];
  } else {
    rtb_gps_pos_R_m_idx_0 = INS_DWork.Memory_PreviousInput_b[0];
    rtb_gps_pos_R_m_idx_1 = INS_DWork.Memory_PreviousInput_b[1];
  }

  // End of Switch: '<S111>/Switch'

  // Product: '<S117>/Multiply' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'

  for (q0 = 0; q0 < 3; q0++) {
    rtb_DiscreteFIRFilter[q0] = rtb_MatrixConcatenate3[q0 + 6] *
      INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] + (rtb_MatrixConcatenate3[q0 +
      3] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +
      rtb_MatrixConcatenate3[q0] * INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]);
  }

  // End of Product: '<S117>/Multiply'

  // DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S109>/Constant'

  if ((INS_P.Constant_Value_m5 != 0) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_ll;
  }

  // Product: '<S117>/Multiply1' incorporates:
  //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
  //   Sum: '<S117>/Sum'

  rtb_Product3_n = rtb_LogicalOperator4_c ? rtb_Product1_m -
    INS_DWork.DiscreteTimeIntegrator2_DSTAT_k : 0.0F;

  // Sum: '<S117>/Sum1' incorporates:
  //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator1'
  //   Gain: '<S117>/beta1'

  rtb_Product14 = INS_P.beta1_Gain * rtb_Product3_n -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_p;

  // Update for UnitDelay: '<S66>/Output' incorporates:
  //   Constant: '<S70>/FixPt Constant'
  //   Sum: '<S70>/FixPt Sum1'

  INS_DWork.Output_DSTATE += INS_P.FixPtConstant_Value;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  // Gain: '<S322>/Gain' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Sum: '<S322>/Sum'

  rtb_Product3_p[0] = (rtb_Product3_p[0] -
                       INS_DWork.DiscreteTimeIntegrator1_DSTATE[0]) *
    INS_P.Gain_Gain_dt;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTATE[0] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[0];

  // Gain: '<S321>/Gain' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
  //   Sum: '<S321>/Sum'

  rtb_Product2_k[0] = (rtb_Product2_k[0] -
                       INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[0]) *
    INS_P.Gain_Gain_dc;

  // Gain: '<S322>/Gain' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Sum: '<S322>/Sum'

  rtb_Product3_p[1] = (rtb_Product3_p[1] -
                       INS_DWork.DiscreteTimeIntegrator1_DSTATE[1]) *
    INS_P.Gain_Gain_dt;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTATE[1] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[1];

  // Gain: '<S321>/Gain' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
  //   Sum: '<S321>/Sum'

  rtb_Product2_k[1] = (rtb_Product2_k[1] -
                       INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[1]) *
    INS_P.Gain_Gain_dc;
  rtb_Product1_m = (rtb_Product2_k[2] -
                    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[2]) *
    INS_P.Gain_Gain_dc;

  // Gain: '<S322>/Gain' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
  //   Sum: '<S322>/Sum'

  rtb_h_vz = (rtb_Product3_p[2] - INS_DWork.DiscreteTimeIntegrator1_DSTATE[2]) *
    INS_P.Gain_Gain_dt;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S322>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTATE[2] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[2];

  // Update for UnitDelay: '<S324>/Delay Input1' incorporates:
  //   Inport: '<Root>/IMU'

  INS_DWork.DelayInput1_DSTATE = INS_U.IMU.timestamp_ms;

  // Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S320>/Constant'

  u0 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_oe +
    INS_P.Constant_Value_d2;
  if (u0 < 4.2949673E+9F) {
    if (u0 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_oe = (uint32_T)u0;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_oe = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_oe = MAX_uint32_T;
  }

  // End of Update for DiscreteIntegrator: '<S320>/Discrete-Time Integrator'

  // Update for Memory: '<S10>/Memory1'
  INS_DWork.Memory1_PreviousInput_c = rtb_Saturation_e;

  // Update for UnitDelay: '<S32>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_p = rtb_Compare_pp;

  // Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator'
  INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 0U;

  // Update for Memory: '<S5>/Memory'
  INS_DWork.Memory_PreviousInput[0] = INS_B.OutportBufferForq_OB[0];

  // Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S54>/Gain2'

  INS_DWork.DiscreteTimeIntegrator_DSTATE[0] += INS_P.Gain2_Gain_i *
    rtb_MatrixConcatenate1_idx_0 * INS_P.DiscreteTimeIntegrator_gainval;

  // Update for Memory: '<S5>/Memory'
  INS_DWork.Memory_PreviousInput[1] = INS_B.OutportBufferForq_OB[1];

  // Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S54>/Gain2'

  INS_DWork.DiscreteTimeIntegrator_DSTATE[1] += INS_P.Gain2_Gain_i *
    rtb_MatrixConcatenate1_idx_1 * INS_P.DiscreteTimeIntegrator_gainval;

  // Update for Memory: '<S5>/Memory'
  INS_DWork.Memory_PreviousInput[2] = INS_B.OutportBufferForq_OB[2];

  // Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S54>/Gain2'

  INS_DWork.DiscreteTimeIntegrator_DSTATE[2] += INS_P.Gain2_Gain_i *
    rtb_MatrixConcatenate1_idx_2 * INS_P.DiscreteTimeIntegrator_gainval;

  // Update for Memory: '<S5>/Memory'
  INS_DWork.Memory_PreviousInput[3] = INS_B.OutportBufferForq_OB[3];

  // Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S54>/Gain2'

  INS_DWork.DiscreteTimeIntegrator_DSTATE[3] += INS_P.Gain2_Gain_i * rtb_az_bias
    * INS_P.DiscreteTimeIntegrator_gainval;
  INS_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_LogicalOperator_f;

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_f = 0U;

  // Sum: '<S312>/Sum' incorporates:
  //   Constant: '<S315>/Constant'
  //   Inport: '<Root>/GPS_uBlox'
  //   Logic: '<S312>/Logical Operator'
  //   RelationalOperator: '<S315>/Compare'
  //   UnitDelay: '<S312>/Unit Delay'

  rtb_Saturation_e = ((INS_U.GPS_uBlox.hAcc < INS_P.CompareToConstant_const_d) &&
                      (rtb_Compare != 0) && (rtb_Compare_cl != 0)) +
    INS_DWork.UnitDelay_DSTATE;

  // Saturate: '<S312>/Saturation'
  if (rtb_Saturation_e > INS_P.Saturation_UpperSat_a) {
    // Update for UnitDelay: '<S312>/Unit Delay'
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_UpperSat_a;
  } else if (rtb_Saturation_e < INS_P.Saturation_LowerSat_f) {
    // Update for UnitDelay: '<S312>/Unit Delay'
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_LowerSat_f;
  } else {
    // Update for UnitDelay: '<S312>/Unit Delay'
    INS_DWork.UnitDelay_DSTATE = rtb_Saturation_e;
  }

  // End of Saturate: '<S312>/Saturation'

  // Update for UnitDelay: '<S310>/Delay Input1' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  INS_DWork.DelayInput1_DSTATE_i = INS_U.GPS_uBlox.timestamp_ms;

  // Update for DiscreteIntegrator: '<S305>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S305>/Constant'

  u0 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_i +
    INS_P.Constant_Value_oh;
  if (u0 < 4.2949673E+9F) {
    if (u0 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_i = (uint32_T)u0;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_i = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i = MAX_uint32_T;
  }

  // End of Update for DiscreteIntegrator: '<S305>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S133>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_o = rtb_Compare_pf;

  // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator2'
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_MathFunction_cp[0];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[0];

  // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator2'
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_MathFunction_cp[1];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[1];

  // Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator2'
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +=
    INS_P.DiscreteTimeIntegrator2_gainval * rtb_MathFunction_cp[2];
  if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] >=
      INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else {
    if (INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] <=
        INS_P.DiscreteTimeIntegrator2_LowerSa) {
      INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
        INS_P.DiscreteTimeIntegrator2_LowerSa;
    }
  }

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S321>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_g[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[2];

  // Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S111>/Constant'
  //   Gain: '<S111>/Gain'
  //   Memory: '<S111>/Memory'
  //   Product: '<S111>/Multiply'
  //   Sum: '<S111>/Add'
  //   Sum: '<S111>/Sum1'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0] += ((rtb_VectorConcatenate2[0] -
    INS_P.Constant_Value_l5[0]) + INS_P.Gain_Gain_i *
    INS_DWork.Memory_PreviousInput_b[0]) * INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1] += ((rtb_VectorConcatenate2[1] -
    INS_P.Constant_Value_l5[1]) + INS_P.Gain_Gain_i *
    INS_DWork.Memory_PreviousInput_b[1]) * INS_P.DiscreteTimeIntegrator_gainva_j;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_h = (int8_T)rtb_LogicalOperator2;

  // Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S109>/Constant'
  //   Constant: '<S117>/Constant'
  //   DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
  //   Gain: '<S117>/beta2'
  //   Sum: '<S117>/Add'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_p += (((rtb_DiscreteFIRFilter[2] +
    INS_P.Constant_Value_nw) + INS_DWork.DiscreteTimeIntegrator_DSTATE_h) +
    INS_P.beta2_Gain * rtb_Product3_n) * INS_P.DiscreteTimeIntegrator1_gainv_d;
  INS_DWork.DiscreteTimeIntegrator1_PrevRes = (int8_T)(INS_P.Constant_Value_m5 >
    0);

  // Update for UnitDelay: '<S138>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_m = rtb_Compare_e;

  // Update for Memory: '<S136>/memory2'
  INS_DWork.memory2_PreviousInput[0] = rtb_WGS84_pos_ref_idx_0;

  // Update for Memory: '<S136>/memory3'
  INS_DWork.memory3_PreviousInput[0] = rtb_Switch_idx_1;

  // Update for Memory: '<S136>/memory2'
  INS_DWork.memory2_PreviousInput[1] = rtb_WGS84_pos_ref_idx_1;

  // Update for Memory: '<S136>/memory3'
  INS_DWork.memory3_PreviousInput[1] = rtb_Switch_idx_0;

  // Update for Memory: '<S136>/memory2'
  INS_DWork.memory2_PreviousInput[2] = rtb_height_m;

  // Update for Memory: '<S136>/memory3'
  INS_DWork.memory3_PreviousInput[2] = rtb_N;

  // Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
  INS_DWork.DiscreteTimeIntegrator_IC_LOA_a = 0U;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n[0] +=
    INS_P.DiscreteTimeIntegrator_gainva_n * rtb_Product15;
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n[1] +=
    INS_P.DiscreteTimeIntegrator_gainva_n * rtb_Product12_k;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_LogicalOperator2;

  // Update for UnitDelay: '<S299>/Delay Input1' incorporates:
  //   Inport: '<Root>/MS5611'

  INS_DWork.DelayInput1_DSTATE_g = INS_U.MS5611.timestamp_ms;

  // Update for Memory: '<S292>/Memory2' incorporates:
  //   Sum: '<S292>/Sum1'

  INS_DWork.Memory2_PreviousInput = qY_0;

  // Update for DiscreteIntegrator: '<S292>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S292>/Constant'

  u0 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTATE_e +
    INS_P.Constant_Value_n3;
  if (u0 < 4.2949673E+9F) {
    if (u0 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_e = (uint32_T)u0;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTATE_e = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e = MAX_uint32_T;
  }

  // End of Update for DiscreteIntegrator: '<S292>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S118>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_h = rtb_FixPtRelationalOperator_if;

  // Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
  INS_DWork.DiscreteTimeIntegrator2_IC_LOAD = 0U;
  INS_DWork.DiscreteTimeIntegrator2_DSTAT_k +=
    INS_P.DiscreteTimeIntegrator2_gainv_i * rtb_Product14;
  INS_DWork.DiscreteTimeIntegrator2_PrevRes = (int8_T)rtb_LogicalOperator_l;

  // Update for UnitDelay: '<S57>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_d = rtb_LogicalOperator_f;

  // Update for Memory: '<S53>/Memory'
  INS_DWork.Memory_PreviousInput_l = rtb_Switch_ol;

  // Update for UnitDelay: '<S311>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_l = rtb_LogicalOperator3_e;

  // Update for DiscreteIntegrator: '<S313>/Discrete-Time Integrator5' incorporates:
  //   Gain: '<S313>/Gain2'
  //   Sum: '<S313>/Sum9'

  INS_DWork.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  INS_DWork.DiscreteTimeIntegrator5_DSTATE += (rtb_sample_sum -
    INS_DWork.DiscreteTimeIntegrator5_DSTATE) * INS_P.Gain2_Gain_ii *
    INS_P.DiscreteTimeIntegrator5_gainval;
  INS_DWork.DiscreteTimeIntegrator5_PrevRes = (int8_T)
    rtb_FixPtRelationalOperator_l;

  // Update for Memory: '<S74>/Memory' incorporates:
  //   Logic: '<S74>/Logical Operator'
  //   Memory: '<S74>/Memory1'

  INS_DWork.Memory_PreviousInput_c = (INS_DWork.Memory1_PreviousInput_b ||
    INS_DWork.Memory_PreviousInput_c);

  // Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S81>/Constant'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_c +=
    INS_P.DiscreteTimeIntegrator_gainva_p * INS_P.Constant_Value_m;
  INS_DWork.DiscreteTimeIntegrator_PrevR_os = (int8_T)rtb_Memory_c;

  // Update for Memory: '<S81>/Memory' incorporates:
  //   Logic: '<S81>/Logical Operator1'
  //   RelationalOperator: '<S92>/FixPt Relational Operator'
  //   UnitDelay: '<S92>/Delay Input1'

  INS_DWork.Memory_PreviousInput_m = (((int32_T)rtb_LogicalOperator1_fk >
    (int32_T)INS_DWork.DelayInput1_DSTATE_of) ||
    INS_DWork.Memory_PreviousInput_m);

  // Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S80>/Constant'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_o +=
    INS_P.DiscreteTimeIntegrator_gainva_b * INS_P.Constant_Value_l;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_Memory_d;

  // Update for Memory: '<S80>/Memory' incorporates:
  //   Logic: '<S80>/Logical Operator1'
  //   RelationalOperator: '<S87>/FixPt Relational Operator'
  //   UnitDelay: '<S87>/Delay Input1'

  INS_DWork.Memory_PreviousInput_e = (((int32_T)rtb_mag_init_valid > (int32_T)
    INS_DWork.DelayInput1_DSTATE_b) || INS_DWork.Memory_PreviousInput_e);

  // Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S82>/Constant'

  INS_DWork.DiscreteTimeIntegrator_DSTAT_jj +=
    INS_P.DiscreteTimeIntegrator_gainva_l * INS_P.Constant_Value_p;
  INS_DWork.DiscreteTimeIntegrator_PrevR_or = (int8_T)rtb_Compare_df;

  // Update for Memory: '<S82>/Memory' incorporates:
  //   Logic: '<S82>/Logical Operator1'
  //   RelationalOperator: '<S97>/FixPt Relational Operator'
  //   UnitDelay: '<S97>/Delay Input1'

  INS_DWork.Memory_PreviousInput_cb = (((int32_T)rtb_LogicalOperator4 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_o1) || INS_DWork.Memory_PreviousInput_cb);

  // Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S83>/Constant'

  INS_DWork.DiscreteTimeIntegrator_DSTAT_ca +=
    INS_P.DiscreteTimeIntegrator_gainv_nk * INS_P.Constant_Value_df;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_Compare_kf;

  // Update for Memory: '<S83>/Memory' incorporates:
  //   Logic: '<S83>/Logical Operator1'
  //   RelationalOperator: '<S102>/FixPt Relational Operator'
  //   UnitDelay: '<S102>/Delay Input1'

  INS_DWork.Memory_PreviousInput_o = (((int32_T)rtb_Compare_ea > (int32_T)
    INS_DWork.DelayInput1_DSTATE_py) || INS_DWork.Memory_PreviousInput_o);

  // Update for UnitDelay: '<S328>/Delay Input1' incorporates:
  //   Inport: '<Root>/Mag'

  INS_DWork.DelayInput1_DSTATE_n = INS_U.Mag.timestamp_ms;

  // Update for DiscreteIntegrator: '<S325>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S325>/Constant'

  u0 = (real32_T)INS_DWork.DiscreteTimeIntegrator_DSTAT_lg +
    INS_P.Constant_Value_et;
  if (u0 < 4.2949673E+9F) {
    if (u0 >= 0.0F) {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = (uint32_T)u0;
    } else {
      INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = 0U;
    }
  } else {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = MAX_uint32_T;
  }

  // End of Update for DiscreteIntegrator: '<S325>/Discrete-Time Integrator'

  // Update for DiscreteFir: '<S5>/Discrete FIR Filter'
  // Update circular buffer index
  INS_DWork.DiscreteFIRFilter_circBuf--;
  if (INS_DWork.DiscreteFIRFilter_circBuf < 0) {
    INS_DWork.DiscreteFIRFilter_circBuf = 2;
  }

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
  // Update circular buffer
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 0U;

  // Update for DiscreteFir: '<S5>/Discrete FIR Filter'
  INS_DWork.DiscreteFIRFilter_states[INS_DWork.DiscreteFIRFilter_circBuf] =
    rtb_raw_acc_idx_0;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[0] +=
    INS_P.DiscreteTimeIntegrator1_gain_dj *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0];

  // Update for DiscreteFir: '<S5>/Discrete FIR Filter'
  INS_DWork.DiscreteFIRFilter_states[INS_DWork.DiscreteFIRFilter_circBuf + 3] =
    rtb_raw_acc_idx_1;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[1] +=
    INS_P.DiscreteTimeIntegrator1_gain_dj *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1];

  // Update for DiscreteFir: '<S5>/Discrete FIR Filter'
  INS_DWork.DiscreteFIRFilter_states[INS_DWork.DiscreteFIRFilter_circBuf + 6] =
    rtb_raw_acc_idx_2;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S49>/Discrete-Time Integrator'

  INS_DWork.DiscreteTimeIntegrator1_DSTAT_i[2] +=
    INS_P.DiscreteTimeIntegrator1_gain_dj *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2];

  // Update for Delay: '<S39>/Delay'
  for (rtb_Saturation_e = 0; rtb_Saturation_e < 199; rtb_Saturation_e++) {
    q0 = (rtb_Saturation_e + 1) * 3;
    INS_DWork.Delay_DSTATE[rtb_Saturation_e * 3] = INS_DWork.Delay_DSTATE[q0];
    INS_DWork.Delay_DSTATE[rtb_Saturation_e * 3 + 1] = INS_DWork.Delay_DSTATE[q0
      + 1];
    INS_DWork.Delay_DSTATE[rtb_Saturation_e * 3 + 2] = INS_DWork.Delay_DSTATE[q0
      + 2];
  }

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
  INS_DWork.DiscreteTimeIntegrator_IC_LOA_e = 0U;

  // Update for Delay: '<S39>/Delay'
  INS_DWork.Delay_DSTATE[597] = rtb_MathFunction_e_idx_0;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S48>/Gain3'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_p[0] += INS_P.Gain3_Gain_g *
    rtb_MathFunction_k_idx_0 * INS_P.DiscreteTimeIntegrator_gainva_f;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator1_h_i;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S49>/Gain1'
  //   Sum: '<S49>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] += (INS_P.Gain1_Gain_hi *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] + rtb_vel_D) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  // Update for Delay: '<S39>/Delay'
  INS_DWork.Delay_DSTATE[598] = rtb_MathFunction_e_idx_1;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S48>/Gain3'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_p[1] += INS_P.Gain3_Gain_g *
    rtb_MathFunction_k_idx_1 * INS_P.DiscreteTimeIntegrator_gainva_f;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator1_h_0;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S49>/Gain1'
  //   Sum: '<S49>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] += (INS_P.Gain1_Gain_hi *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] + rtb_Gain_p_idx_1) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  // Update for Delay: '<S39>/Delay'
  INS_DWork.Delay_DSTATE[599] = rtb_MathFunction_e_idx_2;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S48>/Gain3'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_p[2] += INS_P.Gain3_Gain_g *
    rtb_MathFunction_k_idx_2 * INS_P.DiscreteTimeIntegrator_gainva_f;

  // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_p * rtb_DiscreteTimeIntegrator1_h_1;

  // Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S49>/Gain1'
  //   Sum: '<S49>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] += (INS_P.Gain1_Gain_hi *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] + rtb_Gain_p_idx_2) *
    INS_P.DiscreteTimeIntegrator_gainva_o;

  // Update for Memory: '<S74>/Memory1'
  INS_DWork.Memory1_PreviousInput_b = INS_B.Compare;

  // Update for UnitDelay: '<S87>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_b = rtb_mag_init_valid;

  // Update for UnitDelay: '<S92>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_of = rtb_LogicalOperator1_fk;

  // Update for UnitDelay: '<S97>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_o1 = rtb_LogicalOperator4;

  // Update for UnitDelay: '<S102>/Delay Input1'
  INS_DWork.DelayInput1_DSTATE_py = rtb_Compare_ea;
  for (rtb_Saturation_e = 0; rtb_Saturation_e < 24; rtb_Saturation_e++) {
    // Update for Delay: '<S110>/Delay' incorporates:
    //   Delay: '<S111>/Delay'

    q0 = (rtb_Saturation_e + 1) << 1;
    j = rtb_Saturation_e << 1;
    INS_DWork.Delay_DSTATE_c[j] = INS_DWork.Delay_DSTATE_c[q0];
    Delay_DSTATE_c_tmp = q0 + 1;
    Delay_DSTATE_c_tmp_0 = j + 1;
    INS_DWork.Delay_DSTATE_c[Delay_DSTATE_c_tmp_0] =
      INS_DWork.Delay_DSTATE_c[Delay_DSTATE_c_tmp];

    // Update for Delay: '<S111>/Delay'
    INS_DWork.Delay_DSTATE_m[j] = INS_DWork.Delay_DSTATE_m[q0];
    INS_DWork.Delay_DSTATE_m[Delay_DSTATE_c_tmp_0] =
      INS_DWork.Delay_DSTATE_m[Delay_DSTATE_c_tmp];
  }

  // Update for Delay: '<S110>/Delay'
  INS_DWork.Delay_DSTATE_c[48] = rtb_pos_est_R_m_idx_0;

  // Update for Memory: '<S111>/Memory'
  INS_DWork.Memory_PreviousInput_b[0] = rtb_gps_pos_R_m_idx_0;

  // Update for Delay: '<S110>/Delay'
  INS_DWork.Delay_DSTATE_c[49] = rtb_pos_est_R_m_idx_1;

  // Update for Memory: '<S111>/Memory'
  INS_DWork.Memory_PreviousInput_b[1] = rtb_gps_pos_R_m_idx_1;

  // Update for Delay: '<S111>/Delay' incorporates:
  //   SignalConversion: '<S111>/TmpSignal ConversionAtDelayInport1'

  INS_DWork.Delay_DSTATE_m[48] = rtb_SumofElements;
  INS_DWork.Delay_DSTATE_m[49] = rtb_vel_E;

  // Update for UnitDelay: '<S112>/Delay Input1' incorporates:
  //   Inport: '<Root>/GPS_uBlox'

  INS_DWork.DelayInput1_DSTATE_j = INS_U.GPS_uBlox.timestamp_ms;

  // Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S109>/Constant'
  //   Gain: '<S117>/beta3'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_h += INS_P.beta3_Gain * rtb_Product3_n
    * INS_P.DiscreteTimeIntegrator_gainva_d;
  INS_DWork.DiscreteTimeIntegrator_PrevRe_n = (int8_T)(INS_P.Constant_Value_m5 >
    0);

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S321>/Gain1'
  //   Sum: '<S321>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_l[0] += (INS_P.Gain1_Gain_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[0] + rtb_Product2_k[0]) *
    INS_P.DiscreteTimeIntegrator_gainv_l2;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S322>/Gain1'
  //   Sum: '<S322>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_d[0] += (INS_P.Gain1_Gain_le *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[0] + rtb_Product3_p[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_c;

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S321>/Gain1'
  //   Sum: '<S321>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_l[1] += (INS_P.Gain1_Gain_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[1] + rtb_Product2_k[1]) *
    INS_P.DiscreteTimeIntegrator_gainv_l2;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S322>/Gain1'
  //   Sum: '<S322>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_d[1] += (INS_P.Gain1_Gain_le *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[1] + rtb_Product3_p[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_c;

  // Update for DiscreteIntegrator: '<S321>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S321>/Gain1'
  //   Sum: '<S321>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_l[2] += (INS_P.Gain1_Gain_n *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[2] + rtb_Product1_m) *
    INS_P.DiscreteTimeIntegrator_gainv_l2;

  // Update for DiscreteIntegrator: '<S322>/Discrete-Time Integrator' incorporates:
  //   Gain: '<S322>/Gain1'
  //   Sum: '<S322>/Add'

  INS_DWork.DiscreteTimeIntegrator_DSTATE_d[2] += (INS_P.Gain1_Gain_le *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[2] + rtb_h_vz) *
    INS_P.DiscreteTimeIntegrator_gainva_c;
}

// Model initialize function
void INSModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(getRTM(), (NULL));

  // block I/O
  (void) memset(((void *) &INS_B), 0,
                sizeof(BlockIO_INS_T));

  // states (dwork)
  (void) memset((void *)&INS_DWork, 0,
                sizeof(D_Work_INS_T));

  // external inputs
  (void)memset(&INS_U, 0, sizeof(ExternalInputs_INS_T));

  // external outputs
  INS_Y.INS_Out = INS_rtZINS_Out_Bus;

  {
    int32_T i;
    INS_PrevZCSigState.WGS_Linearization_Trig_ZCE = POS_ZCSIG;

    // InitializeConditions for UnitDelay: '<S66>/Output'
    INS_DWork.Output_DSTATE = INS_P.Output_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S322>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    // InitializeConditions for UnitDelay: '<S324>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE = INS_P.DetectChange_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S320>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTAT_oe =
      INS_P.DiscreteTimeIntegrator_IC_o;

    // InitializeConditions for Memory: '<S10>/Memory1'
    INS_DWork.Memory1_PreviousInput_c = INS_P.Memory1_InitialCondition;

    // InitializeConditions for UnitDelay: '<S32>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_p = INS_P.DetectRisePositive_vinit;

    // InitializeConditions for Memory: '<S5>/Memory'
    INS_DWork.Memory_PreviousInput[0] = INS_P.Memory_InitialCondition_g[0];
    INS_DWork.Memory_PreviousInput[1] = INS_P.Memory_InitialCondition_g[1];
    INS_DWork.Memory_PreviousInput[2] = INS_P.Memory_InitialCondition_g[2];
    INS_DWork.Memory_PreviousInput[3] = INS_P.Memory_InitialCondition_g[3];

    // InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_IC_LOADI = 1U;
    INS_DWork.DiscreteTimeIntegrator_PrevRese = 0;

    // InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator2'
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_IC;
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_IC;
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_f = 1U;

    // InitializeConditions for UnitDelay: '<S312>/Unit Delay'
    INS_DWork.UnitDelay_DSTATE = INS_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S310>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_i = INS_P.DetectChange_vinit_e;

    // InitializeConditions for DiscreteIntegrator: '<S305>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_po;

    // InitializeConditions for UnitDelay: '<S133>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_o = INS_P.DetectRisePositive_vinit_m;

    // InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[0] =
      INS_P.DiscreteTimeIntegrator_IC;
    INS_DWork.DiscreteTimeIntegrator_DSTATE_j[1] =
      INS_P.DiscreteTimeIntegrator_IC;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 0;

    // InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_p = INS_P.DiscreteTimeIntegrator1_IC;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;

    // InitializeConditions for UnitDelay: '<S138>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_m = INS_P.DetectRisePositive3_vinit;

    // InitializeConditions for Memory: '<S136>/memory2'
    INS_DWork.memory2_PreviousInput[0] = INS_P.memory2_InitialCondition;

    // InitializeConditions for Memory: '<S136>/memory3'
    INS_DWork.memory3_PreviousInput[0] = INS_P.memory3_InitialCondition;

    // InitializeConditions for Memory: '<S136>/memory2'
    INS_DWork.memory2_PreviousInput[1] = INS_P.memory2_InitialCondition;

    // InitializeConditions for Memory: '<S136>/memory3'
    INS_DWork.memory3_PreviousInput[1] = INS_P.memory3_InitialCondition;

    // InitializeConditions for Memory: '<S136>/memory2'
    INS_DWork.memory2_PreviousInput[2] = INS_P.memory2_InitialCondition;

    // InitializeConditions for Memory: '<S136>/memory3'
    INS_DWork.memory3_PreviousInput[2] = INS_P.memory3_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_a = 1U;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_o = 0;

    // InitializeConditions for UnitDelay: '<S299>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_g = INS_P.DetectChange_vinit_d;

    // InitializeConditions for Memory: '<S292>/Memory2'
    INS_DWork.Memory2_PreviousInput = INS_P.Memory2_InitialCondition_a;

    // InitializeConditions for DiscreteIntegrator: '<S292>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_dv;

    // InitializeConditions for UnitDelay: '<S118>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_h = INS_P.DetectRisePositive_vinit_f;

    // InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator2'
    INS_DWork.DiscreteTimeIntegrator2_IC_LOAD = 1U;
    INS_DWork.DiscreteTimeIntegrator2_PrevRes = 0;

    // InitializeConditions for UnitDelay: '<S57>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_d = INS_P.DetectIncrease_vinit_d;

    // InitializeConditions for Memory: '<S53>/Memory'
    INS_DWork.Memory_PreviousInput_l = INS_P.Memory_InitialCondition_gc;

    // InitializeConditions for UnitDelay: '<S311>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_l = INS_P.DetectRisePositive_vinit_o;

    // InitializeConditions for DiscreteIntegrator: '<S313>/Discrete-Time Integrator5'
    INS_DWork.DiscreteTimeIntegrator5_IC_LOAD = 1U;
    INS_DWork.DiscreteTimeIntegrator5_PrevRes = 0;

    // InitializeConditions for Memory: '<S74>/Memory'
    INS_DWork.Memory_PreviousInput_c = INS_P.Memory_InitialCondition_p;

    // InitializeConditions for DiscreteIntegrator: '<S81>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_i;
    INS_DWork.DiscreteTimeIntegrator_PrevR_os = 0;

    // InitializeConditions for Memory: '<S81>/Memory'
    INS_DWork.Memory_PreviousInput_m = INS_P.Memory_InitialCondition_b;

    // InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_o =
      INS_P.DiscreteTimeIntegrator_IC_l;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 0;

    // InitializeConditions for Memory: '<S80>/Memory'
    INS_DWork.Memory_PreviousInput_e = INS_P.Memory_InitialCondition_j;

    // InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTAT_jj =
      INS_P.DiscreteTimeIntegrator_IC_d;
    INS_DWork.DiscreteTimeIntegrator_PrevR_or = 0;

    // InitializeConditions for Memory: '<S82>/Memory'
    INS_DWork.Memory_PreviousInput_cb = INS_P.Memory_InitialCondition_m;

    // InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_p;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_d = 0;

    // InitializeConditions for Memory: '<S83>/Memory'
    INS_DWork.Memory_PreviousInput_o = INS_P.Memory_InitialCondition_pp;

    // InitializeConditions for UnitDelay: '<S328>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_n = INS_P.DetectChange_vinit_l;

    // InitializeConditions for DiscreteIntegrator: '<S325>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;

    // InitializeConditions for DiscreteFir: '<S5>/Discrete FIR Filter'
    INS_DWork.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 9; i++) {
      INS_DWork.DiscreteFIRFilter_states[i] =
        INS_P.DiscreteFIRFilter_InitialStates;
    }

    // End of InitializeConditions for DiscreteFir: '<S5>/Discrete FIR Filter'

    // InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_o = 1U;

    // InitializeConditions for Delay: '<S39>/Delay'
    for (i = 0; i < 600; i++) {
      INS_DWork.Delay_DSTATE[i] = INS_P.Delay_InitialCondition;
    }

    // End of InitializeConditions for Delay: '<S39>/Delay'

    // InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_IC_LOA_e = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[0] =
      INS_P.DiscreteTimeIntegrator1_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[0] =
      INS_P.DiscreteTimeIntegrator_IC_g;

    // InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[1] =
      INS_P.DiscreteTimeIntegrator1_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[1] =
      INS_P.DiscreteTimeIntegrator_IC_g;

    // InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_l[2] =
      INS_P.DiscreteTimeIntegrator1_IC_m;

    // InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k[2] =
      INS_P.DiscreteTimeIntegrator_IC_g;

    // InitializeConditions for Memory: '<S74>/Memory1'
    INS_DWork.Memory1_PreviousInput_b = INS_P.Memory1_InitialCondition_n;

    // InitializeConditions for UnitDelay: '<S87>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_b = INS_P.DetectRisePositive_vinit_a;

    // InitializeConditions for UnitDelay: '<S92>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_of = INS_P.DetectRisePositive_vinit_k;

    // InitializeConditions for UnitDelay: '<S97>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_o1 = INS_P.DetectRisePositive_vinit_n;

    // InitializeConditions for UnitDelay: '<S102>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_py = INS_P.DetectRisePositive_vinit_j;

    // InitializeConditions for Memory: '<S111>/Memory'
    INS_DWork.Memory_PreviousInput_b[0] = INS_P.Memory_InitialCondition_l;
    INS_DWork.Memory_PreviousInput_b[1] = INS_P.Memory_InitialCondition_l;
    for (i = 0; i < 50; i++) {
      // InitializeConditions for Delay: '<S110>/Delay'
      INS_DWork.Delay_DSTATE_c[i] = INS_P.Delay_InitialCondition_h;

      // InitializeConditions for Delay: '<S111>/Delay'
      INS_DWork.Delay_DSTATE_m[i] = INS_P.Delay_InitialCondition_a;
    }

    // InitializeConditions for UnitDelay: '<S112>/Delay Input1'
    INS_DWork.DelayInput1_DSTATE_j = INS_P.DetectIncrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_ll;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_n = 0;

    // InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[0] =
      INS_P.DiscreteTimeIntegrator_IC_lj;

    // InitializeConditions for DiscreteIntegrator: '<S322>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[0] =
      INS_P.DiscreteTimeIntegrator_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[1] =
      INS_P.DiscreteTimeIntegrator_IC_lj;

    // InitializeConditions for DiscreteIntegrator: '<S322>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[1] =
      INS_P.DiscreteTimeIntegrator_IC_j;

    // InitializeConditions for DiscreteIntegrator: '<S321>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l[2] =
      INS_P.DiscreteTimeIntegrator_IC_lj;

    // InitializeConditions for DiscreteIntegrator: '<S322>/Discrete-Time Integrator'
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d[2] =
      INS_P.DiscreteTimeIntegrator_IC_j;

    // SystemInitialize for Triggered SubSystem: '<S286>/WGS_Linearization'
    // SystemInitialize for Outport: '<S307>/dx_dmue'
    INS_B.Add = INS_P.dx_dmue_Y0;

    // SystemInitialize for Outport: '<S307>/dy_dlambda'
    INS_B.Product4 = INS_P.dy_dlambda_Y0;

    // SystemInitialize for Outport: '<S307>/dz_dh'
    INS_B.dz_dh = INS_P.dz_dh_Y0;

    // End of SystemInitialize for SubSystem: '<S286>/WGS_Linearization'

    // SystemInitialize for Enabled SubSystem: '<S289>/Reference_and_Gradient'
    // InitializeConditions for Memory: '<S291>/Memory'
    INS_DWork.Memory_PreviousInput_f = INS_P.Memory_InitialCondition;

    // InitializeConditions for Memory: '<S291>/Memory2'
    INS_DWork.Memory2_PreviousInput_b = INS_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S291>/Memory1'
    INS_DWork.Memory1_PreviousInput = INS_P.Memory1_InitialCondition_g;

    // SystemInitialize for Outport: '<S291>/p_ref'
    INS_B.Divide = INS_P.p_ref_Y0;

    // SystemInitialize for Outport: '<S291>/dh_dp'
    INS_B.g_M_d_R = INS_P.dh_dp_Y0;

    // End of SystemInitialize for SubSystem: '<S289>/Reference_and_Gradient'

    // SystemInitialize for Enabled SubSystem: '<S5>/Attitude_Init'
    // SystemInitialize for Outport: '<S8>/q_OB'
    INS_B.OutportBufferForq_OB[0] = INS_P.q_OB_Y0[0];
    INS_B.OutportBufferForq_OB[1] = INS_P.q_OB_Y0[1];
    INS_B.OutportBufferForq_OB[2] = INS_P.q_OB_Y0[2];
    INS_B.OutportBufferForq_OB[3] = INS_P.q_OB_Y0[3];

    // End of SystemInitialize for SubSystem: '<S5>/Attitude_Init'

    // SystemInitialize for Enabled SubSystem: '<S74>/Subsystem'
    // SystemInitialize for Outport: '<S77>/mag_init_valid'
    INS_B.Compare = INS_P.mag_init_valid_Y0;

    // End of SystemInitialize for SubSystem: '<S74>/Subsystem'
  }
}

// Constructor
INSModelClass::INSModelClass()
{
  static const Parameters_INS_T INS_P_temp = {
    // Variable: Conf
    //  Referenced by:
    //    '<S319>/Acc_ScaleFactor'
    //    '<S319>/Gyro_ScaleFactor'
    //    '<S326>/Mag_ScaleFactor4'

    {
      1.0F,
      1.0F,

      { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

      { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
      0.01F,

      { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

      { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

      { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

      { 0.0F, 0.0F, 0.0F },

      { 0.0F, 0.0F, 0.0F },

      { 0.0F, 0.0F, 0.0F }
    },

    // Mask Parameter: CompareToConstant_const
    //  Referenced by: '<S137>/Constant'

    1.0E-6,

    // Mask Parameter: CompareToConstant_const_f
    //  Referenced by: '<S115>/Constant'

    1.0E-6,

    // Mask Parameter: Zero_Value_Exclusion_thr
    //  Referenced by: '<S116>/Saturation'

    1.0E-6,

    // Mask Parameter: CompareToConstant_const_k
    //  Referenced by: '<S31>/Constant'

    100,

    // Mask Parameter: CompareToConstant1_const
    //  Referenced by: '<S304>/Constant'

    2.0F,

    // Mask Parameter: CompareToConstant2_const
    //  Referenced by: '<S308>/Constant'

    1.0F,

    // Mask Parameter: CompareToConstant_const_i
    //  Referenced by: '<S303>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant1_const_n
    //  Referenced by: '<S90>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant1_const_p
    //  Referenced by: '<S85>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant1_const_g
    //  Referenced by: '<S95>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant_const_a
    //  Referenced by: '<S38>/Constant'

    0.01F,

    // Mask Parameter: CompareToConstant_const_n
    //  Referenced by: '<S50>/Constant'

    8.0F,

    // Mask Parameter: CompareToConstant2_const_a
    //  Referenced by: '<S86>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant2_const_j
    //  Referenced by: '<S91>/Constant'

    0.0F,

    // Mask Parameter: CompareToConstant2_const_e
    //  Referenced by: '<S96>/Constant'

    0.0F,

    // Mask Parameter: Mag_Valid_max
    //  Referenced by: '<S329>/Upper Limit'

    30000.0F,

    // Mask Parameter: Mag_Valid_min
    //  Referenced by: '<S329>/Lower Limit'

    -30000.0F,

    // Mask Parameter: Delta_Height_pressure_max
    //  Referenced by: '<S300>/Upper Limit'

    110000.0F,

    // Mask Parameter: Delta_Height_pressure_min
    //  Referenced by: '<S300>/Lower Limit'

    30000.0F,

    // Mask Parameter: Delta_Height_temp_max
    //  Referenced by: '<S301>/Upper Limit'

    80.0F,

    // Mask Parameter: Delta_Height_temp_min
    //  Referenced by: '<S301>/Lower Limit'

    -30.0F,

    // Mask Parameter: valid_check2_time_out
    //  Referenced by: '<S89>/Constant'

    1000.0F,

    // Mask Parameter: valid_check1_time_out
    //  Referenced by: '<S84>/Constant'

    1000.0F,

    // Mask Parameter: valid_check3_time_out
    //  Referenced by: '<S94>/Constant'

    1000.0F,

    // Mask Parameter: valid_check4_time_out
    //  Referenced by: '<S99>/Constant'

    1000.0F,

    // Mask Parameter: IMU_Valid_Time_out
    //  Referenced by: '<S323>/Constant'

    100U,

    // Mask Parameter: Mag_Valid_Time_out
    //  Referenced by: '<S327>/Constant'

    1000U,

    // Mask Parameter: CompareToConstant2_const_ag
    //  Referenced by: '<S317>/Constant'

    500U,

    // Mask Parameter: CompareToConstant4_const
    //  Referenced by: '<S309>/Constant'

    1000U,

    // Mask Parameter: CompareToConstant_const_p
    //  Referenced by: '<S293>/Constant'

    1000000U,

    // Mask Parameter: CompareToConstant4_const_i
    //  Referenced by: '<S297>/Constant'

    200U,

    // Mask Parameter: CompareToConstant_const_d
    //  Referenced by: '<S315>/Constant'

    5000U,

    // Mask Parameter: Delta_Height_s_first
    //  Referenced by: '<S294>/Constant'

    1500U,

    // Mask Parameter: Delta_Height_s_last
    //  Referenced by:
    //    '<S295>/Constant'
    //    '<S296>/Constant'

    2000U,

    // Mask Parameter: DetectChange_vinit
    //  Referenced by: '<S324>/Delay Input1'

    0U,

    // Mask Parameter: DetectChange_vinit_e
    //  Referenced by: '<S310>/Delay Input1'

    0U,

    // Mask Parameter: DetectChange_vinit_d
    //  Referenced by: '<S299>/Delay Input1'

    0U,

    // Mask Parameter: DetectChange_vinit_l
    //  Referenced by: '<S328>/Delay Input1'

    0U,

    // Mask Parameter: DetectIncrease_vinit
    //  Referenced by: '<S112>/Delay Input1'

    0U,

    // Mask Parameter: CompareToConstant_const_kb
    //  Referenced by: '<S78>/Constant'

    1,

    // Mask Parameter: CompareToConstant1_const_b
    //  Referenced by: '<S100>/Constant'

    0,

    // Mask Parameter: CompareToConstant2_const_l
    //  Referenced by: '<S101>/Constant'

    0,

    // Mask Parameter: DetectRisePositive_vinit
    //  Referenced by: '<S32>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_m
    //  Referenced by: '<S133>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive3_vinit
    //  Referenced by: '<S138>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_f
    //  Referenced by: '<S118>/Delay Input1'

    0,

    // Mask Parameter: DetectIncrease_vinit_d
    //  Referenced by: '<S57>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_o
    //  Referenced by: '<S311>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_a
    //  Referenced by: '<S87>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_k
    //  Referenced by: '<S92>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_n
    //  Referenced by: '<S97>/Delay Input1'

    0,

    // Mask Parameter: DetectRisePositive_vinit_j
    //  Referenced by: '<S102>/Delay Input1'

    0,

    // Mask Parameter: CompareToConstant1_const_n4
    //  Referenced by: '<S316>/Constant'

    3U,

    // Expression: 1
    //  Referenced by: '<S116>/Constant'

    1.0,

    // Expression: [0;0;0]
    //  Referenced by: '<S114>/Constant'

    { 0.0, 0.0, 0.0 },

    // Expression: 1
    //  Referenced by: '<S307>/dx_dmue'

    1.0,

    // Expression: 1
    //  Referenced by: '<S307>/dy_dlambda'

    1.0,

    // Expression: 1
    //  Referenced by: '<S307>/dz_dh'

    1.0,

    // Expression: 1
    //  Referenced by: '<S318>/constant1'

    1.0,

    // Expression: 1
    //  Referenced by: '<S318>/constant2'

    1.0,

    // Expression: 1/298.257
    //  Referenced by: '<S318>/f'

    0.0033528131778969143,

    // Expression: 2
    //  Referenced by: '<S318>/constant'

    2.0,

    // Expression: 6378137
    //  Referenced by: '<S318>/a'

    6.378137E+6,

    // Expression: 1
    //  Referenced by: '<S318>/a1'

    1.0,

    // Expression: 0
    //  Referenced by: '<S136>/memory2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S136>/memory3'

    0.0,

    // Expression: 10e7
    //  Referenced by: '<S116>/Saturation'

    1.0E+8,

    // Computed Parameter: Memory1_InitialCondition
    //  Referenced by: '<S10>/Memory1'

    0,

    // Computed Parameter: Saturation_UpperSat_k
    //  Referenced by: '<S10>/Saturation'

    100000,

    // Computed Parameter: Saturation_LowerSat
    //  Referenced by: '<S10>/Saturation'

    0,

    // Computed Parameter: UnitDelay_InitialCondition
    //  Referenced by: '<S312>/Unit Delay'

    0,

    // Computed Parameter: Saturation_UpperSat_a
    //  Referenced by: '<S312>/Saturation'

    1111,

    // Computed Parameter: Saturation_LowerSat_f
    //  Referenced by: '<S312>/Saturation'

    0,

    // Computed Parameter: Gain1_Gain
    //  Referenced by: '<S312>/Gain1'

    1099511628,

    // Computed Parameter: Scalefactor3_Gain
    //  Referenced by: '<S306>/Scalefactor3'

    1099511628,

    // Computed Parameter: Gain_Gain
    //  Referenced by: '<S306>/Gain'

    1099511628,

    // Computed Parameter: Gain1_Gain_c
    //  Referenced by: '<S306>/Gain1'

    1099511628,

    // Computed Parameter: Gain2_Gain
    //  Referenced by: '<S306>/Gain2'

    1099511628,

    // Computed Parameter: Scalefactor1_Gain
    //  Referenced by: '<S306>/Scalefactor1'

    2012227627,

    // Computed Parameter: Scalefactor2_Gain
    //  Referenced by: '<S306>/Scalefactor2'

    2012227627,

    // Computed Parameter: Constant_Value_i
    //  Referenced by: '<S18>/Constant'

    1.0F,

    // Computed Parameter: Protection_Value
    //  Referenced by: '<S18>/Protection'

    1.0E-6F,

    // Computed Parameter: Gain_Gain_a
    //  Referenced by: '<S18>/Gain'

    0.25F,

    // Computed Parameter: Gain1_Gain_l
    //  Referenced by: '<S18>/Gain1'

    0.25F,

    // Computed Parameter: Gain2_Gain_j
    //  Referenced by: '<S18>/Gain2'

    0.25F,

    // Computed Parameter: Gain3_Gain
    //  Referenced by: '<S18>/Gain3'

    0.25F,

    // Computed Parameter: Constant_Value_d
    //  Referenced by: '<S19>/Constant'

    1.0F,

    // Computed Parameter: Protection_Value_j
    //  Referenced by: '<S19>/Protection'

    1.0E-6F,

    // Computed Parameter: Gain_Gain_p
    //  Referenced by: '<S19>/Gain'

    0.25F,

    // Computed Parameter: Gain1_Gain_h
    //  Referenced by: '<S19>/Gain1'

    0.25F,

    // Computed Parameter: Gain2_Gain_o
    //  Referenced by: '<S19>/Gain2'

    0.25F,

    // Computed Parameter: Gain3_Gain_j
    //  Referenced by: '<S19>/Gain3'

    0.25F,

    // Computed Parameter: Constant_Value_j
    //  Referenced by: '<S20>/Constant'

    1.0F,

    // Computed Parameter: Protection_Value_i
    //  Referenced by: '<S20>/Protection'

    1.0E-6F,

    // Computed Parameter: Gain4_Gain
    //  Referenced by: '<S20>/Gain4'

    0.25F,

    // Computed Parameter: Gain1_Gain_j
    //  Referenced by: '<S20>/Gain1'

    0.25F,

    // Computed Parameter: Gain2_Gain_l
    //  Referenced by: '<S20>/Gain2'

    0.25F,

    // Computed Parameter: Gain3_Gain_c
    //  Referenced by: '<S20>/Gain3'

    0.25F,

    // Computed Parameter: Constant_Value_i0
    //  Referenced by: '<S21>/Constant'

    1.0F,

    // Computed Parameter: Protection_Value_a
    //  Referenced by: '<S21>/Protection'

    1.0E-6F,

    // Computed Parameter: Gain_Gain_c
    //  Referenced by: '<S21>/Gain'

    0.25F,

    // Computed Parameter: Gain1_Gain_k
    //  Referenced by: '<S21>/Gain1'

    0.25F,

    // Computed Parameter: Gain2_Gain_ju
    //  Referenced by: '<S21>/Gain2'

    0.25F,

    // Computed Parameter: Gain3_Gain_h
    //  Referenced by: '<S21>/Gain3'

    0.25F,

    // Computed Parameter: q_OB_Y0
    //  Referenced by: '<S8>/q_OB'

    { 1.0F, 0.0F, 0.0F, 0.0F },

    // Computed Parameter: Gain_Gain_d
    //  Referenced by: '<S8>/Gain'

    -1.0F,

    // Computed Parameter: Constant2_Value
    //  Referenced by: '<S16>/Constant2'

    0.001F,

    // Computed Parameter: Constant2_Value_m
    //  Referenced by: '<S17>/Constant2'

    0.001F,

    // Computed Parameter: Constant3_Value
    //  Referenced by: '<S12>/Constant3'

    { 1.0F, 0.0F, 0.0F },

    // Computed Parameter: Constant_Value_f
    //  Referenced by: '<S46>/Constant'

    1.0F,

    // Computed Parameter: Constant_Value_a
    //  Referenced by: '<S47>/Constant'

    1.0F,

    // Computed Parameter: p_ref_Y0
    //  Referenced by: '<S291>/p_ref'

    0.0F,

    // Computed Parameter: dh_dp_Y0
    //  Referenced by: '<S291>/dh_dp'

    0.0F,

    // Computed Parameter: Constant2_Value_p
    //  Referenced by: '<S291>/Constant2'

    273.15F,

    // Computed Parameter: Memory_InitialCondition
    //  Referenced by: '<S291>/Memory'

    0.0F,

    // Computed Parameter: Memory1_InitialCondition_g
    //  Referenced by: '<S291>/Memory1'

    0.0F,

    // Computed Parameter: Saturation_UpperSat_m
    //  Referenced by: '<S291>/Saturation'

    120000.0F,

    // Computed Parameter: Saturation_LowerSat_h
    //  Referenced by: '<S291>/Saturation'

    500.0F,

    // Computed Parameter: g_M_d_R_Gain
    //  Referenced by: '<S291>/g_M_d_R'

    -29.2692909F,

    // Computed Parameter: Output_InitialCondition
    //  Referenced by: '<S66>/Output'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator1_gainval
    //  Referenced by: '<S322>/Discrete-Time Integrator1'

    0.004F,

    // Computed Parameter: Memory_InitialCondition_g
    //  Referenced by: '<S5>/Memory'

    { 1.0F, 0.0F, 0.0F, 0.0F },

    // Computed Parameter: DiscreteTimeIntegrator_gainval
    //  Referenced by: '<S54>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: Gain_Gain_aw
    //  Referenced by: '<S59>/Gain'

    2.0F,

    // Computed Parameter: Gain1_Gain_ju
    //  Referenced by: '<S59>/Gain1'

    2.0F,

    // Computed Parameter: Gain2_Gain_m
    //  Referenced by: '<S59>/Gain2'

    2.0F,

    // Computed Parameter: Gain3_Gain_e
    //  Referenced by: '<S59>/Gain3'

    2.0F,

    // Computed Parameter: Gain4_Gain_f
    //  Referenced by: '<S59>/Gain4'

    2.0F,

    // Computed Parameter: Gain5_Gain
    //  Referenced by: '<S59>/Gain5'

    2.0F,

    // Computed Parameter: Gain5_Gain_d
    //  Referenced by: '<S63>/Gain5'

    -1.0F,

    // Computed Parameter: Saturation1_UpperSat
    //  Referenced by: '<S63>/Saturation1'

    0.999F,

    // Computed Parameter: Saturation1_LowerSat
    //  Referenced by: '<S63>/Saturation1'

    -0.999F,

    // Computed Parameter: Gain_Gain_h
    //  Referenced by: '<S65>/Gain'

    2.0F,

    // Computed Parameter: DiscreteTimeIntegrator2_gainval
    //  Referenced by: '<S55>/Discrete-Time Integrator2'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator2_IC
    //  Referenced by: '<S55>/Discrete-Time Integrator2'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator2_UpperSa
    //  Referenced by: '<S55>/Discrete-Time Integrator2'

    0.87266463F,

    // Computed Parameter: DiscreteTimeIntegrator2_LowerSa
    //  Referenced by: '<S55>/Discrete-Time Integrator2'

    -0.87266463F,

    // Computed Parameter: DiscreteTimeIntegrator1_gainv_n
    //  Referenced by: '<S321>/Discrete-Time Integrator1'

    0.004F,

    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S305>/Constant1'

    3.0F,

    // Computed Parameter: Gain2_Gain_p
    //  Referenced by: '<S305>/Gain2'

    0.4F,

    // Computed Parameter: Saturation1_UpperSat_m
    //  Referenced by: '<S305>/Saturation1'

    1.0F,

    // Computed Parameter: Saturation1_LowerSat_d
    //  Referenced by: '<S305>/Saturation1'

    0.0F,

    // Computed Parameter: Constant_Value_o0
    //  Referenced by: '<S148>/Constant'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_j
    //  Referenced by: '<S111>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator_IC
    //  Referenced by: '<S111>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator1_gainv_d
    //  Referenced by: '<S117>/Discrete-Time Integrator1'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator1_IC
    //  Referenced by: '<S117>/Discrete-Time Integrator1'

    0.0F,

    // Computed Parameter: Gain_Gain_m
    //  Referenced by: '<S117>/Gain'

    -1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_n
    //  Referenced by: '<S110>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator2_gainv_i
    //  Referenced by: '<S117>/Discrete-Time Integrator2'

    0.004F,

    // Computed Parameter: Constant7_Value
    //  Referenced by: '<S305>/Constant7'

    0.7F,

    // Computed Parameter: Gain3_Gain_l
    //  Referenced by: '<S305>/Gain3'

    2.5F,

    // Computed Parameter: DiscreteTimeIntegrator5_gainval
    //  Referenced by: '<S313>/Discrete-Time Integrator5'

    0.004F,

    // Computed Parameter: Saturation_UpperSat_l
    //  Referenced by: '<S305>/Saturation'

    1.0F,

    // Computed Parameter: Saturation_LowerSat_k
    //  Referenced by: '<S305>/Saturation'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_p
    //  Referenced by: '<S81>/Discrete-Time Integrator'

    1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_i
    //  Referenced by: '<S81>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_b
    //  Referenced by: '<S80>/Discrete-Time Integrator'

    1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_l
    //  Referenced by: '<S80>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_l
    //  Referenced by: '<S82>/Discrete-Time Integrator'

    1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_d
    //  Referenced by: '<S82>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainv_nk
    //  Referenced by: '<S83>/Discrete-Time Integrator'

    1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_p
    //  Referenced by: '<S83>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: Constant1_Value_i
    //  Referenced by: '<S325>/Constant1'

    1.0F,

    // Computed Parameter: Constant_Value_jj
    //  Referenced by: '<S79>/Constant'

    0.0F,

    // Computed Parameter: DiscreteFIRFilter_InitialStates
    //  Referenced by: '<S5>/Discrete FIR Filter'

    0.0F,

    // Computed Parameter: DiscreteFIRFilter_Coefficients
    //  Referenced by: '<S5>/Discrete FIR Filter'

    { 0.25F, 0.25F, 0.25F, 0.25F },

    // Computed Parameter: DiscreteTimeIntegrator1_gain_dj
    //  Referenced by: '<S49>/Discrete-Time Integrator1'

    0.004F,

    // Computed Parameter: Relay_OnVal
    //  Referenced by: '<S43>/Relay'

    0.2F,

    // Computed Parameter: Relay_OffVal
    //  Referenced by: '<S43>/Relay'

    0.1F,

    // Computed Parameter: Relay_YOn
    //  Referenced by: '<S43>/Relay'

    1.0F,

    // Computed Parameter: Relay_YOff
    //  Referenced by: '<S43>/Relay'

    0.0F,

    // Computed Parameter: Delay_InitialCondition
    //  Referenced by: '<S39>/Delay'

    0.0F,

    // Computed Parameter: Switch_Threshold
    //  Referenced by: '<S46>/Switch'

    0.0F,

    // Computed Parameter: Constant_Value_e
    //  Referenced by: '<S39>/Constant'

    { 0.0F, 0.0F, -9.81F },

    // Computed Parameter: DiscreteTimeIntegrator_gainva_f
    //  Referenced by: '<S48>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: Switch_Threshold_b
    //  Referenced by: '<S47>/Switch'

    0.0F,

    // Computed Parameter: Saturation_UpperSat_c
    //  Referenced by: '<S42>/Saturation'

    0.17453292F,

    // Computed Parameter: Saturation_LowerSat_d
    //  Referenced by: '<S42>/Saturation'

    -0.17453292F,

    // Computed Parameter: Gain_Gain_o
    //  Referenced by: '<S42>/Gain'

    { 0.2F, 0.2F, 0.1F },

    // Computed Parameter: DiscreteTimeIntegrator1_gainv_p
    //  Referenced by: '<S48>/Discrete-Time Integrator1'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator1_IC_m
    //  Referenced by: '<S48>/Discrete-Time Integrator1'

    0.0F,

    // Computed Parameter: Gain2_Gain_k
    //  Referenced by: '<S48>/Gain2'

    14.14F,

    // Computed Parameter: Gain3_Gain_g
    //  Referenced by: '<S48>/Gain3'

    100.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_o
    //  Referenced by: '<S49>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_g
    //  Referenced by: '<S49>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: Gain1_Gain_hi
    //  Referenced by: '<S49>/Gain1'

    -44.4221191F,

    // Computed Parameter: Gain_Gain_j
    //  Referenced by: '<S49>/Gain'

    986.960449F,

    // Computed Parameter: mag_gain_Gain
    //  Referenced by: '<S52>/mag_gain'

    -0.1F,

    // Computed Parameter: Gain1_Gain_o
    //  Referenced by: '<S40>/Gain1'

    0.2F,

    // Computed Parameter: Saturation2_UpperSat
    //  Referenced by: '<S40>/Saturation2'

    0.00174532924F,

    // Computed Parameter: Saturation2_LowerSat
    //  Referenced by: '<S40>/Saturation2'

    -0.00174532924F,

    // Computed Parameter: Constant_Value_c
    //  Referenced by: '<S54>/Constant'

    0.0F,

    // Computed Parameter: Gain2_Gain_i
    //  Referenced by: '<S54>/Gain2'

    0.5F,

    // Expression: single(0)
    //  Referenced by: '<S64>/Constant1'

    0.0F,

    // Expression: single(1)
    //  Referenced by: '<S64>/Constant'

    1.0F,

    // Expression: single(-1)
    //  Referenced by: '<S64>/Gain'

    -1.0F,

    // Computed Parameter: FixPtConstant_Value
    //  Referenced by: '<S70>/FixPt Constant'

    1.0F,

    // Computed Parameter: Constant_Value_l
    //  Referenced by: '<S80>/Constant'

    1.0F,

    // Computed Parameter: Constant_Value_m
    //  Referenced by: '<S81>/Constant'

    1.0F,

    // Computed Parameter: Constant_Value_p
    //  Referenced by: '<S82>/Constant'

    1.0F,

    // Computed Parameter: Constant_Value_df
    //  Referenced by: '<S83>/Constant'

    1.0F,

    // Computed Parameter: Delay_InitialCondition_h
    //  Referenced by: '<S110>/Delay'

    0.0F,

    // Computed Parameter: Saturation2_UpperSat_l
    //  Referenced by: '<S110>/Saturation2'

    500.0F,

    // Computed Parameter: Saturation2_LowerSat_n
    //  Referenced by: '<S110>/Saturation2'

    -500.0F,

    // Computed Parameter: Gain_Gain_g
    //  Referenced by: '<S110>/Gain'

    2.8F,

    // Computed Parameter: Constant_Value_l5
    //  Referenced by: '<S111>/Constant'

    { 0.0F, 0.0F, -9.805F },

    // Computed Parameter: Memory_InitialCondition_l
    //  Referenced by: '<S111>/Memory'

    0.0F,

    // Computed Parameter: Gain_Gain_i
    //  Referenced by: '<S111>/Gain'

    1.5F,

    // Computed Parameter: Delay_InitialCondition_a
    //  Referenced by: '<S111>/Delay'

    0.0F,

    // Computed Parameter: Constant_Value_nw
    //  Referenced by: '<S117>/Constant'

    9.806F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_d
    //  Referenced by: '<S117>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_ll
    //  Referenced by: '<S117>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: beta2_Gain
    //  Referenced by: '<S117>/beta2'

    -1.499547F,

    // Computed Parameter: beta1_Gain
    //  Referenced by: '<S117>/beta1'

    2.121F,

    // Computed Parameter: beta3_Gain
    //  Referenced by: '<S117>/beta3'

    -0.353393257F,

    // Computed Parameter: Constant_Value_n3
    //  Referenced by: '<S292>/Constant'

    1.0F,

    // Computed Parameter: Constant_Value_oh
    //  Referenced by: '<S305>/Constant'

    1.0F,

    // Computed Parameter: Gain2_Gain_ii
    //  Referenced by: '<S313>/Gain2'

    2.0F,

    // Computed Parameter: Constant_Value_d2
    //  Referenced by: '<S320>/Constant'

    1.0F,

    // Computed Parameter: DiscreteTimeIntegrator_gainv_l2
    //  Referenced by: '<S321>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_lj
    //  Referenced by: '<S321>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: Gain1_Gain_n
    //  Referenced by: '<S321>/Gain1'

    -88.8442383F,

    // Computed Parameter: Gain_Gain_dc
    //  Referenced by: '<S321>/Gain'

    3947.8418F,

    // Computed Parameter: DiscreteTimeIntegrator_gainva_c
    //  Referenced by: '<S322>/Discrete-Time Integrator'

    0.004F,

    // Computed Parameter: DiscreteTimeIntegrator_IC_j
    //  Referenced by: '<S322>/Discrete-Time Integrator'

    0.0F,

    // Computed Parameter: Gain1_Gain_le
    //  Referenced by: '<S322>/Gain1'

    -88.8442383F,

    // Computed Parameter: Gain_Gain_dt
    //  Referenced by: '<S322>/Gain'

    3947.8418F,

    // Computed Parameter: Constant_Value_et
    //  Referenced by: '<S325>/Constant'

    1.0F,

    // Computed Parameter: Gain1_Gain_p
    //  Referenced by: '<S305>/Gain1'

    2199023256U,

    // Computed Parameter: Gain5_Gain_a
    //  Referenced by: '<S305>/Gain5'

    2199023256U,

    // Computed Parameter: Constant1_Value_f
    //  Referenced by: '<S291>/Constant1'

    1U,

    // Computed Parameter: Memory2_InitialCondition
    //  Referenced by: '<S291>/Memory2'

    0U,

    // Computed Parameter: Saturation1_UpperSat_n
    //  Referenced by: '<S291>/Saturation1'

    4294967295U,

    // Computed Parameter: Saturation1_LowerSat_m
    //  Referenced by: '<S291>/Saturation1'

    1U,

    // Computed Parameter: DiscreteTimeIntegrator_IC_o
    //  Referenced by: '<S320>/Discrete-Time Integrator'

    0U,

    // Computed Parameter: DiscreteTimeIntegrator_IC_po
    //  Referenced by: '<S305>/Discrete-Time Integrator'

    0U,

    // Computed Parameter: Memory2_InitialCondition_a
    //  Referenced by: '<S292>/Memory2'

    0U,

    // Computed Parameter: Constant_Value_in
    //  Referenced by: '<S298>/Constant'

    0U,

    // Computed Parameter: DiscreteTimeIntegrator_IC_dv
    //  Referenced by: '<S292>/Discrete-Time Integrator'

    0U,

    // Computed Parameter: DiscreteTimeIntegrator_IC_k
    //  Referenced by: '<S325>/Discrete-Time Integrator'

    0U,

    // Computed Parameter: Delay_DelayLength
    //  Referenced by: '<S110>/Delay'

    25U,

    // Computed Parameter: Delay_DelayLength_m
    //  Referenced by: '<S111>/Delay'

    25U,

    // Computed Parameter: Gain1_Gain_kq
    //  Referenced by: '<S73>/Gain1'

    32768U,

    // Computed Parameter: Gain13_Gain
    //  Referenced by: '<S73>/Gain13'

    32768U,

    // Computed Parameter: Gain12_Gain
    //  Referenced by: '<S73>/Gain12'

    32768U,

    // Computed Parameter: Gain11_Gain
    //  Referenced by: '<S73>/Gain11'

    32768U,

    // Computed Parameter: GPS_Delay_Value
    //  Referenced by: '<S43>/GPS_Delay'

    63U,

    // Computed Parameter: mag_init_valid_Y0
    //  Referenced by: '<S77>/mag_init_valid'

    0,

    // Computed Parameter: Constant_Value_af
    //  Referenced by: '<S33>/Constant'

    0,

    // Computed Parameter: Constant_Value_g
    //  Referenced by: '<S134>/Constant'

    0,

    // Computed Parameter: Constant_Value_pt
    //  Referenced by: '<S139>/Constant'

    0,

    // Computed Parameter: Constant_Value_k
    //  Referenced by: '<S119>/Constant'

    0,

    // Computed Parameter: Constant_Value_px
    //  Referenced by: '<S314>/Constant'

    0,

    // Computed Parameter: Memory_InitialCondition_p
    //  Referenced by: '<S74>/Memory'

    0,

    // Computed Parameter: Memory_InitialCondition_b
    //  Referenced by: '<S81>/Memory'

    0,

    // Computed Parameter: Memory_InitialCondition_j
    //  Referenced by: '<S80>/Memory'

    0,

    // Computed Parameter: Memory_InitialCondition_m
    //  Referenced by: '<S82>/Memory'

    0,

    // Computed Parameter: Memory_InitialCondition_pp
    //  Referenced by: '<S83>/Memory'

    0,

    // Computed Parameter: Memory1_InitialCondition_n
    //  Referenced by: '<S74>/Memory1'

    0,

    // Computed Parameter: Constant_Value_f4
    //  Referenced by: '<S88>/Constant'

    0,

    // Computed Parameter: Constant_Value_nl
    //  Referenced by: '<S93>/Constant'

    0,

    // Computed Parameter: Constant_Value_pn
    //  Referenced by: '<S98>/Constant'

    0,

    // Computed Parameter: Constant_Value_cd
    //  Referenced by: '<S103>/Constant'

    0,

    // Computed Parameter: Gain5_Gain_o
    //  Referenced by: '<S72>/Gain5'

    128U,

    // Computed Parameter: Gain4_Gain_p
    //  Referenced by: '<S72>/Gain4'

    128U,

    // Computed Parameter: Gain10_Gain
    //  Referenced by: '<S73>/Gain10'

    128U,

    // Computed Parameter: Gain2_Gain_h
    //  Referenced by: '<S72>/Gain2'

    128U,

    // Computed Parameter: Gain9_Gain
    //  Referenced by: '<S73>/Gain9'

    128U,

    // Computed Parameter: Constant_Value_mm
    //  Referenced by: '<S53>/Constant'

    1U,

    // Computed Parameter: Constant_Value_ohi
    //  Referenced by: '<S4>/Constant'

    0U,

    // Computed Parameter: Constant_Value_m5
    //  Referenced by: '<S109>/Constant'

    0U,

    // Computed Parameter: Memory_InitialCondition_gc
    //  Referenced by: '<S53>/Memory'

    0U
  };                                   // Modifiable parameters

  // Initialize tunable parameters
  INS_P = INS_P_temp;
}

// Destructor
INSModelClass::~INSModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_INS_T * INSModelClass::getRTM()
{
  return (&INS_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
