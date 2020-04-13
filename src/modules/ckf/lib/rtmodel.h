//
// File: rtmodel.h
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
#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_
#include "INS.h"

//
//  ROOT_IO_FORMAT: 0 (Individual arguments)
//  ROOT_IO_FORMAT: 1 (Structure reference)
//  ROOT_IO_FORMAT: 2 (Part of model data structure)

# define ROOT_IO_FORMAT                1

// Macros generated for backwards compatibility
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#if 0

// Example parameter data definition with initial values
static Parameters_INS_T INS_P = {
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
};                                     // Modifiable parameters

#endif

#define MODEL_CLASSNAME                INSModelClass
#define MODEL_STEPNAME                 step
#endif                                 // RTW_HEADER_rtmodel_h_

//
// File trailer for generated code.
//
// [EOF]
//
