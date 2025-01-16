//
// File: pll.h
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
#ifndef RTW_HEADER_pll_h_
#define RTW_HEADER_pll_h_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "pll_types.h"

extern "C" {

#include "rtGetInf.h"

}
  extern "C"
{

#include "rt_nonfinite.h"

}

#include <cstring>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

// Class declaration for model pll
class pll final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Integ4;                     // '<S16>/Integ4'
    real_T Delay;                      // '<S16>/Gain'
    real_T SFunction;                  // '<S18>/S-Function'
    real_T Integ4_o;                   // '<S10>/Integ4'
    real_T Delay_a;                    // '<S10>/Gain'
    real_T SFunction_n;                // '<S12>/S-Function'
    real_T Integ4_d;                   // '<S13>/Integ4'
    real_T Delay_aq;                   // '<S13>/Gain'
    real_T SFunction_c;                // '<S15>/S-Function'
    real_T MathFunction;               // '<S3>/Math Function'
    real_T UnitDelay_DSTATE;           // '<S2>/Unit Delay'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S2>/Discrete-Time Integrator'
    real_T Integ4_DSTATE;              // '<S16>/Integ4'
    real_T UnitDelay_DSTATE_e;         // '<S17>/Unit Delay'
    real_T UnitDelay1_DSTATE;          // '<S16>/Unit Delay1'
    real_T DiscreteDerivative_states;  // '<S4>/Discrete Derivative '
    real_T DiscreteTimeIntegrator_DSTATE_l;// '<S4>/Discrete-Time Integrator'
    real_T Delay_x1_DSTATE;            // '<S19>/Delay_x1'
    real_T Delay_x2_DSTATE;            // '<S19>/Delay_x2'
    real_T Integ4_DSTATE_p;            // '<S10>/Integ4'
    real_T UnitDelay_DSTATE_l;         // '<S11>/Unit Delay'
    real_T UnitDelay1_DSTATE_l;        // '<S10>/Unit Delay1'
    real_T Integ4_DSTATE_l;            // '<S13>/Integ4'
    real_T UnitDelay_DSTATE_k;         // '<S14>/Unit Delay'
    real_T UnitDelay1_DSTATE_b;        // '<S13>/Unit Delay1'
    real_T PrevY;                      // '<S2>/Rate Limiter'
    real_T SFunction_RWORK;            // '<S18>/S-Function'
    real_T SFunction_RWORK_a;          // '<S12>/S-Function'
    real_T SFunction_RWORK_i;          // '<S15>/S-Function'
    void *SFunction_PWORK[2];          // '<S18>/S-Function'
    void *SFunction_PWORK_h[2];        // '<S12>/S-Function'
    void *SFunction_PWORK_l[2];        // '<S15>/S-Function'
    int8_T DiscreteTimeIntegrator_PrevRese;// '<S2>/Discrete-Time Integrator'
    uint8_T Integ4_SYSTEM_ENABLE;      // '<S16>/Integ4'
    uint8_T Integ4_SYSTEM_ENABLE_b;    // '<S10>/Integ4'
    uint8_T Integ4_SYSTEM_ENABLE_f;    // '<S13>/Integ4'
    boolean_T Initial_FirstOutputTime; // '<S2>/Initial'
    boolean_T AutomaticGainControl_MODE;// '<S2>/Automatic Gain Control'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T SFunction_P1_Size[2];

    // Pooled Parameter (Expression: MaxDelay)
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T pooled9;

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T SFunction_P2_Size[2];

    // Pooled Parameter (Expression: Ts)
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T pooled10;

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T SFunction_P3_Size[2];

    // Pooled Parameter (Expression: InitialValue)
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T pooled11;

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T SFunction_P4_Size[2];

    // Pooled Parameter (Expression: DFT)
    //  Referenced by:
    //    '<S18>/S-Function'
    //    '<S12>/S-Function'
    //    '<S15>/S-Function'

    real_T pooled12;
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T pll_input;                  // '<Root>/pll_input'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Freq;                       // '<Root>/Freq'
    real_T wt;                         // '<Root>/wt'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    struct SimStruct_tag * *childSfunctions;
    const char_T *errorStatus;
    SS_SimMode simMode;
    RTWSolverInfo solverInfo;
    RTWSolverInfo *solverInfoPtr;
    void *sfcnInfo;

    //
    //  NonInlinedSFcns:
    //  The following substructure contains information regarding
    //  non-inlined s-functions used in the model.

    struct {
      RTWSfcnInfo sfcnInfo;
      time_T *taskTimePtrs[1];
      SimStruct childSFunctions[3];
      SimStruct *childSFunctionPtrs[3];
      struct _ssBlkInfo2 blkInfo2[3];
      struct _ssBlkInfoSLSize blkInfoSLSize[3];
      struct _ssSFcnModelMethods2 methods2[3];
      struct _ssSFcnModelMethods3 methods3[3];
      struct _ssSFcnModelMethods4 methods4[3];
      struct _ssStatesInfo2 statesInfo2[3];
      ssPeriodicStatesInfo periodicStatesInfo[3];
      struct _ssPortInfo2 inputOutputPortInfo2[3];
      struct {
        time_T sfcnPeriod[1];
        time_T sfcnOffset[1];
        int_T sfcnTsMap[1];
        struct _ssPortInputs inputPortInfo[2];
        struct _ssPortInputsSLSize inputPortInfoSLSize[2];
        struct _ssInPortUnit inputPortUnits[2];
        struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
        real_T const *UPtrs0[1];
        real_T const *UPtrs1[1];
        struct _ssPortOutputs outputPortInfo[1];
        struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
        struct _ssOutPortUnit outputPortUnits[1];
        struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
        uint_T attribs[4];
        mxArray *params[4];
        struct _ssDWorkRecord dWork[2];
        struct _ssDWorkAuxRecord dWorkAux[2];
      } Sfcn0;

      struct {
        time_T sfcnPeriod[1];
        time_T sfcnOffset[1];
        int_T sfcnTsMap[1];
        struct _ssPortInputs inputPortInfo[2];
        struct _ssPortInputsSLSize inputPortInfoSLSize[2];
        struct _ssInPortUnit inputPortUnits[2];
        struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
        real_T const *UPtrs0[1];
        real_T const *UPtrs1[1];
        struct _ssPortOutputs outputPortInfo[1];
        struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
        struct _ssOutPortUnit outputPortUnits[1];
        struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
        uint_T attribs[4];
        mxArray *params[4];
        struct _ssDWorkRecord dWork[2];
        struct _ssDWorkAuxRecord dWorkAux[2];
      } Sfcn1;

      struct {
        time_T sfcnPeriod[1];
        time_T sfcnOffset[1];
        int_T sfcnTsMap[1];
        struct _ssPortInputs inputPortInfo[2];
        struct _ssPortInputsSLSize inputPortInfoSLSize[2];
        struct _ssInPortUnit inputPortUnits[2];
        struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
        real_T const *UPtrs0[1];
        real_T const *UPtrs1[1];
        struct _ssPortOutputs outputPortInfo[1];
        struct _ssPortOutputsSLSize outputPortInfoSLSize[1];
        struct _ssOutPortUnit outputPortUnits[1];
        struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
        uint_T attribs[4];
        mxArray *params[4];
        struct _ssDWorkRecord dWork[2];
        struct _ssDWorkAuxRecord dWorkAux[2];
      } Sfcn2;
    } NonInlinedSFcns;

    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;

    //
    //  Sizes:
    //  The following substructure contains sizes information
    //  for many of the model attributes such as inputs, outputs,
    //  dwork, sample times, etc.

    struct {
      uint32_T options;
      int_T numContStates;
      int_T numU;
      int_T numY;
      int_T numSampTimes;
      int_T numBlocks;
      int_T numBlockIO;
      int_T numBlockPrms;
      int_T numDwork;
      int_T numSFcnPrms;
      int_T numSFcns;
      int_T numIports;
      int_T numOports;
      int_T numNonSampZCs;
      int_T sysDirFeedThru;
      int_T rtwGenSfcn;
    } Sizes;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      time_T stepSize;
      uint32_T clockTick0;
      uint32_T clockTickH0;
      time_T stepSize0;
      time_T tStart;
      time_T tFinal;
      time_T timeOfLastOutput;
      boolean_T stopRequestedFlag;
      time_T *sampleTimes;
      time_T *offsetTimes;
      int_T *sampleTimeTaskIDPtr;
      int_T *sampleHits;
      int_T *perTaskSampleHits;
      time_T *t;
      time_T sampleTimesArray[1];
      time_T offsetTimesArray[1];
      int_T sampleTimeTaskIDArray[1];
      int_T sampleHitArray[1];
      int_T perTaskSampleHitsArray[1];
      time_T tArray[1];
    } Timing;
  };

  // Copy Constructor
  pll(pll const&) = delete;

  // Assignment Operator
  pll& operator= (pll const&) & = delete;

  // Move Constructor
  pll(pll &&) = delete;

  // Move Assignment Operator
  pll& operator= (pll &&) = delete;

  // Real-Time Model get method
  pll::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  pll();

  // Destructor
  ~pll();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const pll::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Rad->Deg.' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'pll'
//  '<S1>'   : 'pll/PLL'
//  '<S2>'   : 'pll/PLL/Model'
//  '<S3>'   : 'pll/PLL/Model/Automatic Gain Control'
//  '<S4>'   : 'pll/PLL/Model/Discrete'
//  '<S5>'   : 'pll/PLL/Model/Mean (Variable Frequency)'
//  '<S6>'   : 'pll/PLL/Model/Second-Order Filter'
//  '<S7>'   : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)'
//  '<S8>'   : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
//  '<S9>'   : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
//  '<S10>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
//  '<S11>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
//  '<S12>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
//  '<S13>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
//  '<S14>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
//  '<S15>'  : 'pll/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
//  '<S16>'  : 'pll/PLL/Model/Mean (Variable Frequency)/Model'
//  '<S17>'  : 'pll/PLL/Model/Mean (Variable Frequency)/Model/Correction subsystem'
//  '<S18>'  : 'pll/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay'
//  '<S19>'  : 'pll/PLL/Model/Second-Order Filter/Model'
//  '<S20>'  : 'pll/PLL/Model/Second-Order Filter/Model/A*k(k-1)'
//  '<S21>'  : 'pll/PLL/Model/Second-Order Filter/Model/B*(u(k)+u(k-1))'
//  '<S22>'  : 'pll/PLL/Model/Second-Order Filter/Model/C*x(k)'

#endif                                 // RTW_HEADER_pll_h_

//
// File trailer for generated code.
//
// [EOF]
//
