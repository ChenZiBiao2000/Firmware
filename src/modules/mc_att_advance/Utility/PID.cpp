//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PID.cpp
//
// Code generated for Simulink model 'PID'.
//
// Model version                  : 1.40
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Sun Apr 21 22:57:45 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PID.h"
#include "PID_private.h"

const Control_Output PID_rtZControl_Output = {
	0.0F,                                // u_x
	0.0F,                                // u_y
	0.0F                                 // u_z
} ;                                    // Control_Output ground

// Exported block parameters
Model_Param_T Model_Param = {
	0.15F,
	0.15F,
	0.15F,
	0.1F,
	0.1F,
	0.2F,
	0.05F,
	0.05F,
	0.05F,
	0.2F,
	-0.2F,
	0.0004F,
	0.0004F,
	0.0005F,
	0.2F,
	-0.2F
} ;                                    // Variable: Model_Param
//  Referenced by:
//    '<S6>/p_kd'
//    '<S6>/q_kd'
//    '<S6>/r_kd'
//    '<S6>/Saturation'
//    '<S7>/p_ki'
//    '<S7>/q_ki'
//    '<S7>/r_ki'
//    '<S7>/Saturation'
//    '<S8>/p_kp'
//    '<S8>/q_kp'
//    '<S8>/r_kp'
//    '<S12>/Kp_phi '
//    '<S12>/Kp_psi'
//    '<S12>/Kp_theta'


// Model step function
void PIDModelClass::step()
{
	real32_T rtb_Sum_h_idx_0;
	real32_T rtb_Sum_h_idx_1;
	real32_T rtb_Sum_h_idx_2;
	real32_T rtb_k_pt_idx_0;
	real32_T rtb_k_pt_idx_1;
	real32_T rtb_k_pt_idx_2;
	real32_T u0;
	real32_T u0_0;
	real32_T u0_1;
	real32_T tmp;

	// Switch: '<S3>/Switch' incorporates:
	//   Constant: '<S12>/Kp_phi '
	//   Constant: '<S12>/Kp_psi'
	//   Constant: '<S12>/Kp_theta'
	//   Inport: '<Root>/Command'
	//   Inport: '<Root>/Reference'
	//   Inport: '<Root>/States'
	//   Product: '<S12>/Multiply'
	//   Sum: '<S10>/Sum'

	if (PID_U.Command_m.mode > 0) {
		rtb_Sum_h_idx_0 = PID_U.States_i.p_radDs;
		rtb_Sum_h_idx_1 = PID_U.States_i.q_radDs;
		rtb_Sum_h_idx_2 = PID_U.States_i.r_radDs;

	} else {
		rtb_Sum_h_idx_0 = (PID_U.Reference_e.phi_ref_rad - PID_U.States_i.phi_rad) *
				  Model_Param.Kp_phi;
		rtb_Sum_h_idx_1 = (PID_U.Reference_e.theta_ref_rad -
				   PID_U.States_i.theta_rad) * Model_Param.Kp_theta;
		rtb_Sum_h_idx_2 = (PID_U.Reference_e.psi_ref_rad - PID_U.States_i.psi_rad) *
				  Model_Param.Kp_psi;
	}

	// End of Switch: '<S3>/Switch'

	// Sum: '<S4>/Sum' incorporates:
	//   Inport: '<Root>/States'

	rtb_Sum_h_idx_0 -= PID_U.States_i.p_radDs;
	rtb_Sum_h_idx_1 -= PID_U.States_i.q_radDs;
	rtb_Sum_h_idx_2 -= PID_U.States_i.r_radDs;

	// DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
	//   Inport: '<Root>/Command'

	if ((PID_U.Command_m.reset != 0) || (PID_DW.DiscreteTimeIntegrator_PrevRese !=
					     0)) {
		PID_DW.DiscreteTimeIntegrator_DSTATE[0] = PID_ConstB.Constant[0];
		PID_DW.DiscreteTimeIntegrator_DSTATE[1] = PID_ConstB.Constant[1];
		PID_DW.DiscreteTimeIntegrator_DSTATE[2] = PID_ConstB.Constant[2];
	}

	// DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' incorporates:
	//   Inport: '<Root>/Command'

	if ((PID_U.Command_m.reset != 0) || (PID_DW.DiscreteTimeIntegrator1_PrevRes !=
					     0)) {
		PID_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
		PID_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
		PID_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
	}

	// Gain: '<S9>/k_pt' incorporates:
	//   DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
	//   Sum: '<S9>/Sum5'

	rtb_k_pt_idx_0 = (rtb_Sum_h_idx_0 - PID_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
			 10.0F;
	rtb_k_pt_idx_1 = (rtb_Sum_h_idx_1 - PID_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
			 10.0F;
	rtb_k_pt_idx_2 = (rtb_Sum_h_idx_2 - PID_DW.DiscreteTimeIntegrator1_DSTATE[2]) *
			 10.0F;

	// Product: '<S6>/Multiply' incorporates:
	//   Constant: '<S6>/r_kd'

	u0 = Model_Param.Kd_r * rtb_k_pt_idx_0;

	// Saturate: '<S7>/Saturation' incorporates:
	//   DiscreteIntegrator: '<S7>/Discrete-Time Integrator'

	if (PID_DW.DiscreteTimeIntegrator_DSTATE[0] > Model_Param.Ki_Max) {
		tmp = Model_Param.Ki_Max;

	} else if (PID_DW.DiscreteTimeIntegrator_DSTATE[0] < Model_Param.Ki_Min) {
		tmp = Model_Param.Ki_Min;

	} else {
		tmp = PID_DW.DiscreteTimeIntegrator_DSTATE[0];
	}

	// Saturate: '<S6>/Saturation'
	if (u0 > Model_Param.Kd_Max) {
		u0 = Model_Param.Kd_Max;

	} else {
		if (u0 < Model_Param.Kd_Min) {
			u0 = Model_Param.Kd_Min;
		}
	}

	// Sum: '<S5>/Add' incorporates:
	//   Constant: '<S8>/r_kp'
	//   Product: '<S8>/Multiply'

	u0 += Model_Param.Kp_r * rtb_Sum_h_idx_0 + tmp;

	// Product: '<S6>/Multiply' incorporates:
	//   Constant: '<S6>/p_kd'

	u0_0 = Model_Param.Kd_p * rtb_k_pt_idx_1;

	// Saturate: '<S7>/Saturation' incorporates:
	//   DiscreteIntegrator: '<S7>/Discrete-Time Integrator'

	if (PID_DW.DiscreteTimeIntegrator_DSTATE[1] > Model_Param.Ki_Max) {
		tmp = Model_Param.Ki_Max;

	} else if (PID_DW.DiscreteTimeIntegrator_DSTATE[1] < Model_Param.Ki_Min) {
		tmp = Model_Param.Ki_Min;

	} else {
		tmp = PID_DW.DiscreteTimeIntegrator_DSTATE[1];
	}

	// Saturate: '<S6>/Saturation'
	if (u0_0 > Model_Param.Kd_Max) {
		u0_0 = Model_Param.Kd_Max;

	} else {
		if (u0_0 < Model_Param.Kd_Min) {
			u0_0 = Model_Param.Kd_Min;
		}
	}

	// Sum: '<S5>/Add' incorporates:
	//   Constant: '<S8>/p_kp'
	//   Product: '<S8>/Multiply'

	u0_0 += Model_Param.Kp_q * rtb_Sum_h_idx_1 + tmp;

	// Product: '<S6>/Multiply' incorporates:
	//   Constant: '<S6>/q_kd'

	u0_1 = Model_Param.Kd_q * rtb_k_pt_idx_2;

	// Saturate: '<S7>/Saturation' incorporates:
	//   DiscreteIntegrator: '<S7>/Discrete-Time Integrator'

	if (PID_DW.DiscreteTimeIntegrator_DSTATE[2] > Model_Param.Ki_Max) {
		tmp = Model_Param.Ki_Max;

	} else if (PID_DW.DiscreteTimeIntegrator_DSTATE[2] < Model_Param.Ki_Min) {
		tmp = Model_Param.Ki_Min;

	} else {
		tmp = PID_DW.DiscreteTimeIntegrator_DSTATE[2];
	}

	// Saturate: '<S6>/Saturation'
	if (u0_1 > Model_Param.Kd_Max) {
		u0_1 = Model_Param.Kd_Max;

	} else {
		if (u0_1 < Model_Param.Kd_Min) {
			u0_1 = Model_Param.Kd_Min;
		}
	}

	// Sum: '<S5>/Add' incorporates:
	//   Constant: '<S8>/q_kp'
	//   Product: '<S8>/Multiply'

	u0_1 += Model_Param.Kp_q * rtb_Sum_h_idx_2 + tmp;

	// Saturate: '<S5>/Saturation'
	if (u0 > 1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_x = 1.0F;

	} else if (u0 < -1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_x = -1.0F;

	} else {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_x = u0;
	}

	if (u0_0 > 1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_y = 1.0F;

	} else if (u0_0 < -1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_y = -1.0F;

	} else {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_y = u0_0;
	}

	if (u0_1 > 1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_z = 1.0F;

	} else if (u0_1 < -1.0F) {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_z = -1.0F;

	} else {
		// Outport: '<Root>/Control_Output'
		PID_Y.Control_Output_e.u_z = u0_1;
	}

	// End of Saturate: '<S5>/Saturation'

	// Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
	//   Constant: '<S7>/r_ki'
	//   Inport: '<Root>/Command'
	//   Product: '<S7>/Multiply'

	PID_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)(PID_U.Command_m.reset > 0);
	PID_DW.DiscreteTimeIntegrator_DSTATE[0] += Model_Param.Ki_r * rtb_Sum_h_idx_0 *
			0.004F;

	// Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
	PID_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.004F * rtb_k_pt_idx_0;

	// Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
	//   Constant: '<S7>/p_ki'
	//   Product: '<S7>/Multiply'

	PID_DW.DiscreteTimeIntegrator_DSTATE[1] += Model_Param.Ki_q * rtb_Sum_h_idx_1 *
			0.004F;

	// Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
	PID_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.004F * rtb_k_pt_idx_1;

	// Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
	//   Constant: '<S7>/q_ki'
	//   Product: '<S7>/Multiply'

	PID_DW.DiscreteTimeIntegrator_DSTATE[2] += Model_Param.Ki_q * rtb_Sum_h_idx_2 *
			0.004F;

	// Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' incorporates:
	//   Inport: '<Root>/Command'

	PID_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.004F * rtb_k_pt_idx_2;
	PID_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)(PID_U.Command_m.reset > 0);
}

// Model initialize function
void PIDModelClass::initialize()
{
	// Registration code

	// initialize error status
	rtmSetErrorStatus(getRTM(), (NULL));

	// states (dwork)
	(void) memset((void *)&PID_DW, 0,
		      sizeof(DW_PID_T));

	// external inputs
	(void)memset(&PID_U, 0, sizeof(ExtU_PID_T));

	// external outputs
	PID_Y.Control_Output_e = PID_rtZControl_Output;

	// InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator'
	PID_DW.DiscreteTimeIntegrator_DSTATE[0] = PID_ConstB.Constant[0];
	PID_DW.DiscreteTimeIntegrator_DSTATE[1] = PID_ConstB.Constant[1];
	PID_DW.DiscreteTimeIntegrator_DSTATE[2] = PID_ConstB.Constant[2];
	PID_DW.DiscreteTimeIntegrator_PrevRese = 0;

	// InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
	PID_DW.DiscreteTimeIntegrator1_PrevRes = 0;
}

// Model terminate function
void PIDModelClass::terminate()
{
	// (no terminate code required)
}

// Constructor
PIDModelClass::PIDModelClass()
{
	// Currently there is no constructor body generated.
}

// Destructor
PIDModelClass::~PIDModelClass()
{
	// Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_PID_T *PIDModelClass::getRTM()
{
	return (&PID_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
