//
// File: pll.cpp
//
// Code generated for Simulink model 'pll'.
//
// Model version                  : 1.23
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Jan 13 16:59:10 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Emulation hardware selection:
//    Differs from embedded hardware (MATLAB Host)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "pll.h"
#include "rtwtypes.h"
#include <cmath>
#include "pll_private.h"

extern "C" {

#include "rt_nonfinite.h"

}
  real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = std::sqrt(y * y + 1.0) * a;
  } else if (!std::isnan(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Model step function
void pll::step()
{
  real_T Initial;
  real_T rtb_Numberofsamplespercycle_c;
  real_T rtb_Numberofsamplespercycle_p;
  real_T rtb_Product1_e;
  real_T rtb_RoundingFunction_c_tmp;
  real_T rtb_RoundingFunction_d;
  real_T rtb_RoundingFunction_g;
  real_T rtb_sum3;
  boolean_T rtb_RelationalOperator;

  // Outport: '<Root>/Freq' incorporates:
  //   UnitDelay: '<S2>/Unit Delay'

  rtY.Freq = rtDW.UnitDelay_DSTATE;

  // RelationalOperator: '<S2>/Relational Operator' incorporates:
  //   Constant: '<S2>/Constant2'

  rtb_RelationalOperator = (rtDW.DiscreteTimeIntegrator_DSTATE >
    6.2831853071795862);

  // InitialCondition: '<S2>/Initial'
  if (rtDW.Initial_FirstOutputTime) {
    rtDW.Initial_FirstOutputTime = false;

    // InitialCondition: '<S2>/Initial'
    Initial = 0.0;
  } else {
    // InitialCondition: '<S2>/Initial' incorporates:
    //   Constant: '<S2>/Constant2'
    //   Sum: '<S2>/Subtract'

    Initial = rtDW.DiscreteTimeIntegrator_DSTATE - 6.2831853071795862;
  }

  // End of InitialCondition: '<S2>/Initial'

  // DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  if (rtb_RelationalOperator && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE = Initial;
  }

  // Outport: '<Root>/wt' incorporates:
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

  rtY.wt = rtDW.DiscreteTimeIntegrator_DSTATE;

  // Outputs for Enabled SubSystem: '<S2>/Automatic Gain Control' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (!rtDW.AutomaticGainControl_MODE) {
    // Enable for DiscreteIntegrator: '<S10>/Integ4'
    rtDW.Integ4_SYSTEM_ENABLE_b = 1U;

    // Enable for DiscreteIntegrator: '<S13>/Integ4'
    rtDW.Integ4_SYSTEM_ENABLE_f = 1U;
    rtDW.AutomaticGainControl_MODE = true;
  }

  // Product: '<S7>/Product1' incorporates:
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  //   Gain: '<S7>/Gain1'
  //   Inport: '<Root>/pll_input'
  //   Trigonometry: '<S7>/Trigonometric Function'

  rtb_Product1_e = 2.0 * std::sin(rtDW.DiscreteTimeIntegrator_DSTATE) *
    rtU.pll_input;

  // DiscreteIntegrator: '<S10>/Integ4'
  if (rtDW.Integ4_SYSTEM_ENABLE_b != 0) {
    // DiscreteIntegrator: '<S10>/Integ4'
    rtDW.Integ4_o = rtDW.Integ4_DSTATE_p;
  } else {
    // DiscreteIntegrator: '<S10>/Integ4'
    rtDW.Integ4_o = 5.0E-6 * rtb_Product1_e + rtDW.Integ4_DSTATE_p;
  }

  // End of DiscreteIntegrator: '<S10>/Integ4'

  // Saturate: '<S10>/To avoid division  by zero' incorporates:
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtDW.UnitDelay_DSTATE > 1.0E+6) {
    Initial = 1.0E+6;
  } else if (rtDW.UnitDelay_DSTATE < 2.2204460492503131E-16) {
    Initial = 2.2204460492503131E-16;
  } else {
    Initial = rtDW.UnitDelay_DSTATE;
  }

  // End of Saturate: '<S10>/To avoid division  by zero'

  // Fcn: '<S10>/Number of samples per cycle'
  rtb_Numberofsamplespercycle_p = 1.0 / Initial / 1.0e-5;

  // Rounding: '<S10>/Rounding Function'
  rtb_RoundingFunction_d = std::ceil(rtb_Numberofsamplespercycle_p);

  // Gain: '<S10>/Gain'
  rtDW.Delay_a = 1.0E-5 * rtb_RoundingFunction_d;

  // S-Function (sfun_discreteVariableDelay): '<S12>/S-Function'

  // Level2 S-Function Block: '<S12>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  // DigitalClock: '<S10>/Digital  Clock' incorporates:
  //   DigitalClock: '<S16>/Digital  Clock'

  rtb_sum3 = (&rtM)->Timing.t[0];

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/Constant'
  //   DigitalClock: '<S10>/Digital  Clock'
  //   Gain: '<S11>/Gain1'
  //   Product: '<S10>/Product'
  //   Product: '<S11>/Product2'
  //   Product: '<S11>/Product4'
  //   Product: '<S11>/Product5'
  //   RelationalOperator: '<S10>/Relational Operator'
  //   Sum: '<S10>/Sum5'
  //   Sum: '<S10>/Sum7'
  //   Sum: '<S11>/Sum1'
  //   Sum: '<S11>/Sum4'
  //   UnitDelay: '<S10>/Unit Delay1'
  //   UnitDelay: '<S11>/Unit Delay'
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtb_sum3 >= 0.016666666666666666) {
    // Sum: '<S11>/Sum5'
    rtb_RoundingFunction_d = rtb_Numberofsamplespercycle_p -
      rtb_RoundingFunction_d;
    rtb_Numberofsamplespercycle_p = ((rtb_Product1_e - rtDW.UnitDelay_DSTATE_l) *
      rtb_RoundingFunction_d * 0.5 + rtb_Product1_e) * (rtb_RoundingFunction_d /
      rtb_Numberofsamplespercycle_p) + (rtDW.Integ4_o - rtDW.SFunction_n) *
      rtDW.UnitDelay_DSTATE;
  } else {
    rtb_Numberofsamplespercycle_p = rtDW.UnitDelay1_DSTATE_l;
  }

  // End of Switch: '<S10>/Switch'

  // Trigonometry: '<S7>/Trigonometric Function' incorporates:
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  //   Trigonometry: '<S2>/Trigonometric Function2'

  rtb_RoundingFunction_c_tmp = std::cos(rtDW.DiscreteTimeIntegrator_DSTATE);

  // Product: '<S7>/Product2' incorporates:
  //   Gain: '<S7>/Gain3'
  //   Inport: '<Root>/pll_input'
  //   Trigonometry: '<S7>/Trigonometric Function'

  rtb_RoundingFunction_d = 2.0 * rtb_RoundingFunction_c_tmp * rtU.pll_input;

  // DiscreteIntegrator: '<S13>/Integ4'
  if (rtDW.Integ4_SYSTEM_ENABLE_f != 0) {
    // DiscreteIntegrator: '<S13>/Integ4'
    rtDW.Integ4_d = rtDW.Integ4_DSTATE_l;
  } else {
    // DiscreteIntegrator: '<S13>/Integ4'
    rtDW.Integ4_d = 5.0E-6 * rtb_RoundingFunction_d + rtDW.Integ4_DSTATE_l;
  }

  // End of DiscreteIntegrator: '<S13>/Integ4'

  // Saturate: '<S13>/To avoid division  by zero' incorporates:
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtDW.UnitDelay_DSTATE > 1.0E+6) {
    Initial = 1.0E+6;
  } else if (rtDW.UnitDelay_DSTATE < 2.2204460492503131E-16) {
    Initial = 2.2204460492503131E-16;
  } else {
    Initial = rtDW.UnitDelay_DSTATE;
  }

  // End of Saturate: '<S13>/To avoid division  by zero'

  // Fcn: '<S13>/Number of samples per cycle'
  rtb_Numberofsamplespercycle_c = 1.0 / Initial / 1.0e-5;

  // Rounding: '<S13>/Rounding Function'
  rtb_RoundingFunction_g = std::ceil(rtb_Numberofsamplespercycle_c);

  // Gain: '<S13>/Gain'
  rtDW.Delay_aq = 1.0E-5 * rtb_RoundingFunction_g;

  // S-Function (sfun_discreteVariableDelay): '<S15>/S-Function'

  // Level2 S-Function Block: '<S15>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  // Switch: '<S13>/Switch' incorporates:
  //   Constant: '<S13>/Constant'
  //   DigitalClock: '<S10>/Digital  Clock'
  //   Gain: '<S14>/Gain1'
  //   Product: '<S13>/Product'
  //   Product: '<S14>/Product2'
  //   Product: '<S14>/Product4'
  //   Product: '<S14>/Product5'
  //   RelationalOperator: '<S13>/Relational Operator'
  //   Sum: '<S13>/Sum5'
  //   Sum: '<S13>/Sum7'
  //   Sum: '<S14>/Sum1'
  //   Sum: '<S14>/Sum4'
  //   UnitDelay: '<S13>/Unit Delay1'
  //   UnitDelay: '<S14>/Unit Delay'
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtb_sum3 >= 0.016666666666666666) {
    // Sum: '<S14>/Sum5'
    Initial = rtb_Numberofsamplespercycle_c - rtb_RoundingFunction_g;
    rtb_Numberofsamplespercycle_c = ((rtb_RoundingFunction_d -
      rtDW.UnitDelay_DSTATE_k) * Initial * 0.5 + rtb_RoundingFunction_d) *
      (Initial / rtb_Numberofsamplespercycle_c) + (rtDW.Integ4_d -
      rtDW.SFunction_c) * rtDW.UnitDelay_DSTATE;
  } else {
    rtb_Numberofsamplespercycle_c = rtDW.UnitDelay1_DSTATE_b;
  }

  // End of Switch: '<S13>/Switch'

  // ComplexToMagnitudeAngle: '<S7>/Complex to Magnitude-Angle' incorporates:
  //   RealImagToComplex: '<S7>/Real-Imag to Complex'

  Initial = rt_hypotd_snf(rtb_Numberofsamplespercycle_p,
    rtb_Numberofsamplespercycle_c);

  // Saturate: '<S3>/Saturation'
  if (Initial <= 2.2204460492503131E-16) {
    Initial = 2.2204460492503131E-16;
  }

  // End of Saturate: '<S3>/Saturation'

  // Math: '<S3>/Math Function'
  //
  //  About '<S3>/Math Function':
  //   Operator: reciprocal

  rtDW.MathFunction = 1.0 / Initial;

  // Update for DiscreteIntegrator: '<S10>/Integ4'
  rtDW.Integ4_SYSTEM_ENABLE_b = 0U;
  rtDW.Integ4_DSTATE_p = 5.0E-6 * rtb_Product1_e + rtDW.Integ4_o;

  // Update for S-Function (sfun_discreteVariableDelay): '<S12>/S-Function'
  // Level2 S-Function Block: '<S12>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[0];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // Update for UnitDelay: '<S11>/Unit Delay'
  rtDW.UnitDelay_DSTATE_l = rtb_Product1_e;

  // Update for UnitDelay: '<S10>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE_l = rtb_Numberofsamplespercycle_p;

  // Update for DiscreteIntegrator: '<S13>/Integ4'
  rtDW.Integ4_SYSTEM_ENABLE_f = 0U;
  rtDW.Integ4_DSTATE_l = 5.0E-6 * rtb_RoundingFunction_d + rtDW.Integ4_d;

  // Update for S-Function (sfun_discreteVariableDelay): '<S15>/S-Function'
  // Level2 S-Function Block: '<S15>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[1];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // Update for UnitDelay: '<S14>/Unit Delay'
  rtDW.UnitDelay_DSTATE_k = rtb_RoundingFunction_d;

  // Update for UnitDelay: '<S13>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE_b = rtb_Numberofsamplespercycle_c;

  // End of Outputs for SubSystem: '<S2>/Automatic Gain Control'

  // Product: '<S2>/Product1' incorporates:
  //   Inport: '<Root>/pll_input'

  rtb_Product1_e = rtU.pll_input * rtb_RoundingFunction_c_tmp;

  // DiscreteIntegrator: '<S16>/Integ4'
  if (rtDW.Integ4_SYSTEM_ENABLE != 0) {
    // DiscreteIntegrator: '<S16>/Integ4'
    rtDW.Integ4 = rtDW.Integ4_DSTATE;
  } else {
    // DiscreteIntegrator: '<S16>/Integ4'
    rtDW.Integ4 = 5.0E-6 * rtb_Product1_e + rtDW.Integ4_DSTATE;
  }

  // End of DiscreteIntegrator: '<S16>/Integ4'

  // Saturate: '<S16>/To avoid division  by zero' incorporates:
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtDW.UnitDelay_DSTATE > 1.0E+6) {
    Initial = 1.0E+6;
  } else if (rtDW.UnitDelay_DSTATE < 2.2204460492503131E-16) {
    Initial = 2.2204460492503131E-16;
  } else {
    Initial = rtDW.UnitDelay_DSTATE;
  }

  // End of Saturate: '<S16>/To avoid division  by zero'

  // Fcn: '<S16>/Number of samples per cycle'
  rtb_Numberofsamplespercycle_p = 1.0 / Initial / 1.0e-5;

  // Rounding: '<S16>/Rounding Function'
  rtb_RoundingFunction_d = std::ceil(rtb_Numberofsamplespercycle_p);

  // Gain: '<S16>/Gain'
  rtDW.Delay = 1.0E-5 * rtb_RoundingFunction_d;

  // S-Function (sfun_discreteVariableDelay): '<S18>/S-Function'

  // Level2 S-Function Block: '<S18>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  // Switch: '<S16>/Switch' incorporates:
  //   Constant: '<S16>/Constant'
  //   Gain: '<S17>/Gain1'
  //   Product: '<S16>/Product'
  //   Product: '<S17>/Product2'
  //   Product: '<S17>/Product4'
  //   Product: '<S17>/Product5'
  //   RelationalOperator: '<S16>/Relational Operator'
  //   Sum: '<S16>/Sum5'
  //   Sum: '<S16>/Sum7'
  //   Sum: '<S17>/Sum1'
  //   Sum: '<S17>/Sum4'
  //   UnitDelay: '<S16>/Unit Delay1'
  //   UnitDelay: '<S17>/Unit Delay'
  //   UnitDelay: '<S2>/Unit Delay'

  if (rtb_sum3 >= 0.016666666666666666) {
    // Sum: '<S17>/Sum5'
    rtb_RoundingFunction_d = rtb_Numberofsamplespercycle_p -
      rtb_RoundingFunction_d;
    rtb_Numberofsamplespercycle_p = ((rtb_Product1_e - rtDW.UnitDelay_DSTATE_e) *
      rtb_RoundingFunction_d * 0.5 + rtb_Product1_e) * (rtb_RoundingFunction_d /
      rtb_Numberofsamplespercycle_p) + (rtDW.Integ4 - rtDW.SFunction) *
      rtDW.UnitDelay_DSTATE;
  } else {
    rtb_Numberofsamplespercycle_p = rtDW.UnitDelay1_DSTATE;
  }

  // End of Switch: '<S16>/Switch'

  // Product: '<S2>/Divide'
  rtb_RoundingFunction_d = rtb_Numberofsamplespercycle_p * rtDW.MathFunction;

  // DiscreteTransferFcn: '<S4>/Discrete Derivative '
  rtb_Numberofsamplespercycle_c = (rtb_RoundingFunction_d - -9.0E-5 *
    rtDW.DiscreteDerivative_states) / 0.0001;

  // Sum: '<S4>/Sum6' incorporates:
  //   DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  //   DiscreteTransferFcn: '<S4>/Discrete Derivative '
  //   Gain: '<S4>/Kp4'

  Initial = (180.0 * rtb_RoundingFunction_d +
             rtDW.DiscreteTimeIntegrator_DSTATE_l) +
    (rtb_Numberofsamplespercycle_c + -rtDW.DiscreteDerivative_states);

  // Saturate: '<S4>/Saturation1'
  if (Initial <= 0.0) {
    rtb_RoundingFunction_g = 0.0;
  } else {
    rtb_RoundingFunction_g = Initial;
  }

  // End of Saturate: '<S4>/Saturation1'

  // Gain: '<S2>/Gain10'
  Initial = 0.15915494309189535 * rtb_RoundingFunction_g;

  // RateLimiter: '<S2>/Rate Limiter'
  rtb_sum3 = Initial - rtDW.PrevY;
  if (rtb_sum3 > 0.00012000000000000002) {
    Initial = rtDW.PrevY + 0.00012000000000000002;
  } else if (rtb_sum3 < -0.00012000000000000002) {
    Initial = rtDW.PrevY + -0.00012000000000000002;
  }

  rtDW.PrevY = Initial;

  // End of RateLimiter: '<S2>/Rate Limiter'

  // Sum: '<S20>/sum3' incorporates:
  //   Gain: '<S20>/A21'
  //   Gain: '<S20>/A22'
  //   UnitDelay: '<S19>/Delay_x1'
  //   UnitDelay: '<S19>/Delay_x2'

  rtb_sum3 = -0.24646634546579055 * rtDW.Delay_x1_DSTATE + 0.99778012649318426 *
    rtDW.Delay_x2_DSTATE;

  // Update for UnitDelay: '<S2>/Unit Delay' incorporates:
  //   Gain: '<S19>/D*u(k)'
  //   Gain: '<S22>/C11'
  //   Gain: '<S22>/C12'
  //   Sum: '<S19>/C*X(k)+D*u(k)'
  //   Sum: '<S22>/sum2'
  //   UnitDelay: '<S19>/Delay_x1'
  //   UnitDelay: '<S19>/Delay_x2'

  rtDW.UnitDelay_DSTATE = (0.24674005946217703 * rtDW.Delay_x1_DSTATE +
    1.2323317273289529E-6 * rtDW.Delay_x2_DSTATE) + 6.1616586366447646E-7 *
    Initial;

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE += 1.0E-5 * rtb_RoundingFunction_g;
  rtDW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
    (rtb_RelationalOperator);

  // Update for DiscreteIntegrator: '<S16>/Integ4'
  rtDW.Integ4_SYSTEM_ENABLE = 0U;
  rtDW.Integ4_DSTATE = 5.0E-6 * rtb_Product1_e + rtDW.Integ4;

  // Update for S-Function (sfun_discreteVariableDelay): '<S18>/S-Function'
  // Level2 S-Function Block: '<S18>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[2];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // Update for UnitDelay: '<S17>/Unit Delay'
  rtDW.UnitDelay_DSTATE_e = rtb_Product1_e;

  // Update for UnitDelay: '<S16>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE = rtb_Numberofsamplespercycle_p;

  // Update for DiscreteTransferFcn: '<S4>/Discrete Derivative '
  rtDW.DiscreteDerivative_states = rtb_Numberofsamplespercycle_c;

  // Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator_DSTATE_l += 0.032 * rtb_RoundingFunction_d;
  if ((!(rtDW.DiscreteTimeIntegrator_DSTATE_l >= (rtInf))) &&
      (rtDW.DiscreteTimeIntegrator_DSTATE_l <= 0.0)) {
    rtDW.DiscreteTimeIntegrator_DSTATE_l = 0.0;
  }

  // End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator'

  // Update for UnitDelay: '<S19>/Delay_x1' incorporates:
  //   Gain: '<S20>/A11'
  //   Gain: '<S20>/A12'
  //   Gain: '<S21>/B11'
  //   Sum: '<S19>/A*x1(k) + B*u1(k) '
  //   Sum: '<S20>/sum2'
  //   UnitDelay: '<S19>/Delay_x2'

  rtDW.Delay_x1_DSTATE = (0.99999876766827267 * rtDW.Delay_x1_DSTATE +
    9.9889006324659223E-6 * rtDW.Delay_x2_DSTATE) + 4.9944503162329611E-6 *
    Initial;

  // Update for UnitDelay: '<S19>/Delay_x2' incorporates:
  //   Gain: '<S21>/B21'
  //   Sum: '<S19>/A*x2(k) + B*u2(k)'

  rtDW.Delay_x2_DSTATE = 0.99889006324659213 * Initial + rtb_sum3;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.
  //  Timer of this task consists of two 32 bit unsigned integers.
  //  The two integers represent the low bits Timing.clockTick0 and the high bits
  //  Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.

  if (!(++(&rtM)->Timing.clockTick0)) {
    ++(&rtM)->Timing.clockTickH0;
  }

  (&rtM)->Timing.t[0] = (&rtM)->Timing.clockTick0 * (&rtM)->Timing.stepSize0 + (
    &rtM)->Timing.clockTickH0 * (&rtM)->Timing.stepSize0 * 4294967296.0;
}

// Model initialize function
void pll::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&(&rtM)->solverInfo,"FixedStepDiscrete");
  (&rtM)->solverInfoPtr = (&(&rtM)->solverInfo);

  // Initialize timing info
  {
    int_T *mdlTsMap { (&rtM)->Timing.sampleTimeTaskIDArray };

    mdlTsMap[0] = 0;

    // polyspace +2 MISRA2012:D4.1 [Justified:Low] "(&rtM) points to
    // static memory which is guaranteed to be non-NULL"
    (&rtM)->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    (&rtM)->Timing.sampleTimes = (&(&rtM)->Timing.sampleTimesArray[0]);
    (&rtM)->Timing.offsetTimes = (&(&rtM)->Timing.offsetTimesArray[0]);

    // task periods
    (&rtM)->Timing.sampleTimes[0] = (1.0E-5);

    // task offsets
    (&rtM)->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr((&rtM), &(&rtM)->Timing.tArray[0]);

  {
    int_T *mdlSampleHits{ (&rtM)->Timing.sampleHitArray };

    mdlSampleHits[0] = 1;
    (&rtM)->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal((&rtM), -1);
  (&rtM)->Timing.stepSize0 = 1.0E-5;
  (&rtM)->solverInfoPtr = (&(&rtM)->solverInfo);
  (&rtM)->Timing.stepSize = (1.0E-5);
  rtsiSetFixedStepSize(&(&rtM)->solverInfo, 1.0E-5);
  rtsiSetSolverMode(&(&rtM)->solverInfo, SOLVER_MODE_SINGLETASKING);

  // child S-Function registration
  {
    RTWSfcnInfo *sfcnInfo{ &(&rtM)->NonInlinedSFcns.sfcnInfo };

    (&rtM)->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus((&rtM))));
    (&rtM)->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &(&rtM)->Sizes.numSampTimes);
    (&rtM)->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr((&rtM))[0]);
    rtssSetTPtrPtr(sfcnInfo,(&rtM)->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart((&rtM)));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal((&rtM)));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput((&rtM)));
    rtssSetStepSizePtr(sfcnInfo, &(&rtM)->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested((&rtM)));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &(&rtM)->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &(&rtM)->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo, &(&rtM)
      ->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &(&rtM)->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &(&rtM)->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &(&rtM)->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &(&rtM)->solverInfoPtr);
  }

  (&rtM)->Sizes.numSFcns = (3);

  // register each child
  {
    (void) std::memset(static_cast<void *>(&(&rtM)
      ->NonInlinedSFcns.childSFunctions[0]), 0,
                       3*sizeof(SimStruct));
    (&rtM)->childSfunctions = (&(&rtM)->NonInlinedSFcns.childSFunctionPtrs[0]);
    (&rtM)->childSfunctions[0] = (&(&rtM)->NonInlinedSFcns.childSFunctions[0]);
    (&rtM)->childSfunctions[1] = (&(&rtM)->NonInlinedSFcns.childSFunctions[1]);
    (&rtM)->childSfunctions[2] = (&(&rtM)->NonInlinedSFcns.childSFunctions[2]);

    // Level2 S-Function Block: pll/<S12>/S-Function (sfun_discreteVariableDelay) 
    {
      SimStruct *rts = (&rtM)->childSfunctions[0];

      // timing info
      time_T *sfcnPeriod = (&rtM)->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = (&rtM)->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = (&rtM)->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &(&rtM)->NonInlinedSFcns.blkInfo2[0]);
        ssSetBlkInfoSLSizePtr(rts, &(&rtM)->NonInlinedSFcns.blkInfoSLSize[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &(&rtM)
        ->NonInlinedSFcns.inputOutputPortInfo2[0]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, (&rtM)->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &(&rtM)->NonInlinedSFcns.methods2[0]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &(&rtM)->NonInlinedSFcns.methods3[0]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &(&rtM)->NonInlinedSFcns.methods4[0]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &(&rtM)->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts, &(&rtM)->
          NonInlinedSFcns.periodicStatesInfo[0]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &(&rtM)->
          NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn0.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        // port 0
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &rtDW.Integ4_o;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        // port 1
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &rtDW.Delay_a;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      // outputs
      {
        ssSetPortInfoForOutputs(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn0.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtDW.SFunction_n));
        }
      }

      // path info
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,(&rtM));
      ssSetParentSS(rts, (nullptr));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **) &(&rtM)
          ->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtConstP.SFunction_P4_Size);
      }

      // work vectors
      ssSetRWork(rts, (real_T *) &rtDW.SFunction_RWORK_a);
      ssSetPWork(rts, (void **) &rtDW.SFunction_PWORK_h[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *) &(&rtM)
          ->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &(&rtM)->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        // RWORK
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDW.SFunction_RWORK_a);

        // PWORK
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rtDW.SFunction_PWORK_h[0]);
      }

      // registration
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 1.0E-5);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    // Level2 S-Function Block: pll/<S15>/S-Function (sfun_discreteVariableDelay) 
    {
      SimStruct *rts = (&rtM)->childSfunctions[1];

      // timing info
      time_T *sfcnPeriod = (&rtM)->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = (&rtM)->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = (&rtM)->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &(&rtM)->NonInlinedSFcns.blkInfo2[1]);
        ssSetBlkInfoSLSizePtr(rts, &(&rtM)->NonInlinedSFcns.blkInfoSLSize[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &(&rtM)
        ->NonInlinedSFcns.inputOutputPortInfo2[1]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, (&rtM)->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &(&rtM)->NonInlinedSFcns.methods2[1]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &(&rtM)->NonInlinedSFcns.methods3[1]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &(&rtM)->NonInlinedSFcns.methods4[1]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &(&rtM)->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts, &(&rtM)->
          NonInlinedSFcns.periodicStatesInfo[1]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &(&rtM)->
          NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn1.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        // port 0
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &rtDW.Integ4_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        // port 1
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &rtDW.Delay_aq;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      // outputs
      {
        ssSetPortInfoForOutputs(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn1.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtDW.SFunction_c));
        }
      }

      // path info
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,(&rtM));
      ssSetParentSS(rts, (nullptr));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **) &(&rtM)
          ->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtConstP.SFunction_P4_Size);
      }

      // work vectors
      ssSetRWork(rts, (real_T *) &rtDW.SFunction_RWORK_i);
      ssSetPWork(rts, (void **) &rtDW.SFunction_PWORK_l[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *) &(&rtM)
          ->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &(&rtM)->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        // RWORK
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDW.SFunction_RWORK_i);

        // PWORK
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rtDW.SFunction_PWORK_l[0]);
      }

      // registration
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 1.0E-5);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    // Level2 S-Function Block: pll/<S18>/S-Function (sfun_discreteVariableDelay) 
    {
      SimStruct *rts = (&rtM)->childSfunctions[2];

      // timing info
      time_T *sfcnPeriod = (&rtM)->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = (&rtM)->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = (&rtM)->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) std::memset(static_cast<void*>(sfcnPeriod), 0,
                         sizeof(time_T)*1);
      (void) std::memset(static_cast<void*>(sfcnOffset), 0,
                         sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &(&rtM)->NonInlinedSFcns.blkInfo2[2]);
        ssSetBlkInfoSLSizePtr(rts, &(&rtM)->NonInlinedSFcns.blkInfoSLSize[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &(&rtM)
        ->NonInlinedSFcns.inputOutputPortInfo2[2]);

      // Set up the mdlInfo pointer
      ssSetRTWSfcnInfo(rts, (&rtM)->sfcnInfo);

      // Allocate memory of model methods 2
      {
        ssSetModelMethods2(rts, &(&rtM)->NonInlinedSFcns.methods2[2]);
      }

      // Allocate memory of model methods 3
      {
        ssSetModelMethods3(rts, &(&rtM)->NonInlinedSFcns.methods3[2]);
      }

      // Allocate memory of model methods 4
      {
        ssSetModelMethods4(rts, &(&rtM)->NonInlinedSFcns.methods4[2]);
      }

      // Allocate memory for states auxilliary information
      {
        ssSetStatesInfo2(rts, &(&rtM)->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts, &(&rtM)->
          NonInlinedSFcns.periodicStatesInfo[2]);
      }

      // inputs
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &(&rtM)->
          NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->inputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn2.inputPortInfoSLSize[0];
        _ssSetPortInfo2ForInputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        // port 0
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &rtDW.Integ4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        // port 1
        {
          real_T const **sfcnUPtrs = (real_T const **) &(&rtM)
            ->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &rtDW.Delay;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      // outputs
      {
        ssSetPortInfoForOutputs(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        rts->blkInfo.blkInfo2->blkInfoSLSize->outputs = &(&rtM)
          ->NonInlinedSFcns.Sfcn2.outputPortInfoSLSize[0];
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts, &(&rtM)
          ->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        // port 0
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtDW.SFunction));
        }
      }

      // path info
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "pll/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,(&rtM));
      ssSetParentSS(rts, (nullptr));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      // parameters
      {
        mxArray **sfcnParams = (mxArray **) &(&rtM)
          ->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtConstP.SFunction_P4_Size);
      }

      // work vectors
      ssSetRWork(rts, (real_T *) &rtDW.SFunction_RWORK);
      ssSetPWork(rts, (void **) &rtDW.SFunction_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *) &(&rtM)
          ->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &(&rtM)->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        // RWORK
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDW.SFunction_RWORK);

        // PWORK
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rtDW.SFunction_PWORK[0]);
      }

      // registration
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      // adjust sample time
      ssSetSampleTime(rts, 0, 1.0E-5);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      // set compiled values of dynamic vector attributes
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      // Update connectivity flags for each port
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      // Update the BufferDstPort flags for each input port
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  // Start for InitialCondition: '<S2>/Initial'
  rtDW.Initial_FirstOutputTime = true;

  // Start for S-Function (sfun_discreteVariableDelay): '<S18>/S-Function'
  // Level2 S-Function Block: '<S18>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // InitializeConditions for UnitDelay: '<S2>/Unit Delay'
  rtDW.UnitDelay_DSTATE = 60.0;

  // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_PrevRese = 2;

  // InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S18>/S-Function' 
  // Level2 S-Function Block: '<S18>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' 
  rtDW.DiscreteTimeIntegrator_DSTATE_l = 376.99111843077515;

  // InitializeConditions for RateLimiter: '<S2>/Rate Limiter'
  rtDW.PrevY = 60.0;

  // InitializeConditions for UnitDelay: '<S19>/Delay_x1'
  rtDW.Delay_x1_DSTATE = 243.17074074161684;

  // InitializeConditions for UnitDelay: '<S19>/Delay_x2'
  rtDW.Delay_x2_DSTATE = -3.5527136788005009E-15;

  // Start for S-Function (sfun_discreteVariableDelay): '<S12>/S-Function'
  // Level2 S-Function Block: '<S12>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // Start for S-Function (sfun_discreteVariableDelay): '<S15>/S-Function'
  // Level2 S-Function Block: '<S15>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S12>/S-Function' 
  // Level2 S-Function Block: '<S12>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // InitializeConditions for UnitDelay: '<S10>/Unit Delay1'
  rtDW.UnitDelay1_DSTATE_l = 1.0;

  // InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S15>/S-Function' 
  // Level2 S-Function Block: '<S15>/S-Function' (sfun_discreteVariableDelay)
  {
    SimStruct *rts = (&rtM)->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (nullptr))
      return;
  }

  // SystemInitialize for Math: '<S3>/Math Function' incorporates:
  //   Outport: '<S3>/Gain'
  //
  //  About '<S3>/Math Function':
  //   Operator: reciprocal

  rtDW.MathFunction = 1.0;

  // End of SystemInitialize for SubSystem: '<S2>/Automatic Gain Control'

  // Enable for DiscreteIntegrator: '<S16>/Integ4'
  rtDW.Integ4_SYSTEM_ENABLE = 1U;
}

// Constructor
pll::pll() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
pll::~pll()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
pll::RT_MODEL * pll::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
