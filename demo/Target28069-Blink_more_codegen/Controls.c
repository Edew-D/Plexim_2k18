/*
 * Implementation file for: Target28069-Blink_more/Controls
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 25 May 2018 10:10:15
 */
#include "Controls.h"
#ifndef PLECS_HEADER_Controls_h_
#error The wrong header file "Controls.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Controls_h_ */
#if defined(__GNUC__) && (__GNUC__ > 3)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hal.h"
#define PLECSRunTimeError(msg) Controls_errorStatus = msg
struct CScriptStruct
{
   int numInputTerminals;
   int numOutputTerminals;
   int* numInputSignals;
   int* numOutputSignals;
   int numContStates;
   int numDiscStates;
   int numZCSignals;
   int numSampleTimes;
   int numParameters;
   int isMajorTimeStep;
   double time;
   const double ***inputs;
   double ***outputs;
   double *contStates;
   double *contDerivs;
   double *discStates;
   double *zCSignals;
   const int *paramNumDims;
   const int **paramDims;
   const int *paramNumElements;
   const double **paramRealData;
   const char **paramStringData;
   const char * const *sampleHits;
   const double *sampleTimePeriods;
   const double *sampleTimeOffsets;
   double *nextSampleHit;
   const char** errorStatus;
   const char** warningStatus;
   const char** rangeErrorMsg;
   int* rangeErrorLine;
};
static struct CScriptStruct Controls_cScriptStruct[1];
static const uint32_t Controls_taskPeriod[2]= {
   /* [0.5, 0] */
   5000,
   /* [0.001, 0] */
   10
};
static uint32_t Controls_taskTick[2];
static char Controls_taskHit[2];
void Controls_0_cScriptStart(const struct CScriptStruct *cScriptStruct);
void Controls_0_cScriptOutput(const struct CScriptStruct *cScriptStruct);
void Controls_0_cScriptUpdate(const struct CScriptStruct *cScriptStruct);
void Controls_0_cScriptDerivative(const struct CScriptStruct *cScriptStruct);
void Controls_0_cScriptTerminate(const struct CScriptStruct *cScriptStruct);
Controls_BlockOutputs Controls_B;
Controls_ModelStates Controls_X _ALIGN;
const char * Controls_errorStatus;
const double Controls_sampleTime = 0.000100000000000000005;
const char * const Controls_checksum =
   "604fe95a1cb288a19ce07f0b6754c0ea17d0fb40";
void Controls_initialize(double time)
{
   uint32_t Controls_tickLo;
   int32_t Controls_tickHi;
   double remainder;
   Controls_errorStatus = NULL;
   Controls_tickHi = floor(time/(4294967296.0*Controls_sampleTime));
   remainder = time - Controls_tickHi*4294967296.0*Controls_sampleTime;
   Controls_tickLo = floor(remainder/Controls_sampleTime + .5);
   remainder -= Controls_tickLo*Controls_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Controls_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Controls_taskTick[0] = 0;        /* [0.5, 0] */
   Controls_taskTick[1] = 0;        /* [0.001, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Controls_tickHi);
      for (i = 0; i < 2; ++i)
      {
         delta = -Controls_taskPeriod[i];
         delta %= Controls_taskPeriod[i];
         if (Controls_tickHi < 0)
         {
            delta = Controls_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Controls_taskTick[i] =
               (Controls_taskTick[i] + delta) % Controls_taskPeriod[i];
         }
         Controls_taskTick[i] =
            (Controls_taskTick[i] + Controls_tickLo %
          Controls_taskPeriod[i]) % Controls_taskPeriod[i];
      }
   }

   /* Initialization for Analog In : 'Controls/Analog In (ADC0)' */
   {
      AIN_AdcParams_t *paramsAdc = HAL_getDefaultAdcParams();
      HAL_setupAdc(0, 7, paramsAdc);
   }
   {
      AIN_ChannelParams_t *paramsChannel = HAL_getDefaultAinChannelParams();
      paramsChannel->ADCSOCxCTL.bit.TRIGSEL = 5;
      HAL_setupAnalogInF(0, 0, 0, paramsChannel, 1.000000000e+00f,
                         0.000000000e+00f);
   }
   {
      AIN_ChannelParams_t *paramsChannel = HAL_getDefaultAinChannelParams();
      paramsChannel->ADCSOCxCTL.bit.TRIGSEL = 5;
      HAL_setupAnalogInF(0, 7, 0, paramsChannel, 1.000000000e+00f,
                         0.000000000e+00f);
   }

   /* Initialization for Analog In : 'Controls/Analog In (ADC0)1' */
   {
      AIN_AdcParams_t *paramsAdc = HAL_getDefaultAdcParams();
      HAL_setupAdc(1, 1, paramsAdc);
   }
   {
      AIN_ChannelParams_t *paramsChannel = HAL_getDefaultAinChannelParams();
      paramsChannel->ADCSOCxCTL.bit.TRIGSEL = 5;
      HAL_setupAnalogInF(1, 0, 0, paramsChannel, 1.000000000e+00f,
                         0.000000000e+00f);
   }
   {
      AIN_ChannelParams_t *paramsChannel = HAL_getDefaultAinChannelParams();
      paramsChannel->ADCSOCxCTL.bit.TRIGSEL = 5;
      HAL_setupAnalogInF(1, 1, 0, paramsChannel, 1.000000000e+00f,
                         0.000000000e+00f);
   }

   /* Initialization for Delay : 'Controls/Delay1' */
   Controls_X.Delay1 = 0.;

   /* Initialization for C-Script : 'Controls/C-Script' */
   {
      static int numInputSignals[] = {
         1
      };
      static const double* inputPtrs[] = {
         &Controls_B.LogicalOperator1
      };
      static const double** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static double* outputPtrs[] = {
         &Controls_B.C_Script
      };
      static double** outputs[] = {
         &outputPtrs[0]
      };
      static double nextSampleHit;
      static const char * sampleHits[] = {
         &Controls_taskHit[1]
      };
      static double sampleTimePeriods[] = {
         0.001
      };
      static double sampleTimeOffsets[] = {
         0
      };
      static const char* errorStatus = NULL;
      static const char* warningStatus = NULL;
      static const char* rangeErrorMsg = NULL;
      Controls_cScriptStruct[0].isMajorTimeStep = 1;
      Controls_cScriptStruct[0].numInputTerminals = 1;
      Controls_cScriptStruct[0].numInputSignals = numInputSignals;
      Controls_cScriptStruct[0].inputs = inputs;
      Controls_cScriptStruct[0].numOutputTerminals = 1;
      Controls_cScriptStruct[0].numOutputSignals = numOutputSignals;
      Controls_cScriptStruct[0].outputs = outputs;
      Controls_cScriptStruct[0].numContStates = 0;
      Controls_cScriptStruct[0].contStates = NULL;
      Controls_cScriptStruct[0].contDerivs = NULL;
      Controls_cScriptStruct[0].numDiscStates = 0;
      Controls_cScriptStruct[0].discStates = NULL;
      Controls_cScriptStruct[0].numZCSignals = 0;
      Controls_cScriptStruct[0].numParameters = 0;
      Controls_cScriptStruct[0].paramNumDims = NULL;
      Controls_cScriptStruct[0].paramDims = NULL;
      Controls_cScriptStruct[0].paramNumElements = NULL;
      Controls_cScriptStruct[0].paramRealData = NULL;
      Controls_cScriptStruct[0].paramStringData = NULL;
      Controls_cScriptStruct[0].numSampleTimes = 1;
      Controls_cScriptStruct[0].sampleTimePeriods = sampleTimePeriods;
      Controls_cScriptStruct[0].sampleTimeOffsets = sampleTimeOffsets;
      Controls_cScriptStruct[0].numSampleTimes = 1;
      Controls_cScriptStruct[0].sampleHits = sampleHits;
      Controls_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      Controls_cScriptStruct[0].errorStatus = &errorStatus;
      Controls_cScriptStruct[0].warningStatus = &warningStatus;
      Controls_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      Controls_0_cScriptStart(&Controls_cScriptStruct[0]);
      if (*Controls_cScriptStruct[0].errorStatus)
         Controls_errorStatus = *Controls_cScriptStruct[0].errorStatus;
   }

   /* Initialization for Digital Out : 'Controls/Digital Out (LED)' */
   HAL_setupDigitalOut(0, 11, false);

   /* Initialization for Digital In : 'Controls/Digital In1' */
   HAL_setupDigitalIn(0, 13);
   HAL_setupDigitalIn(1, 14);

   /* Initialization for PWM Out : 'Controls/PWM Out (ePWM0)' */
   {
      PWM_Params_t *params = HAL_getDefaultPwmParams(2250, 50);
      HAL_setupPwmOut(0, 1, params);
   }
   {
      PWM_Params_t *params = HAL_getDefaultPwmParams(2250, 50);
      HAL_setupPwmOut(1, 2, params);
   }

   /* Initialization for Digital Out : 'Controls/Digital Out (LED)1' */
   HAL_setupDigitalOut(1, 35, false);
   HAL_setupDigitalOut(2, 36, false);

   /* Initialization for PWM Out : 'Controls/PWM Out (ePWM0)1' */
   {
      PWM_Params_t *params = HAL_getDefaultPwmParams(2250, 50);
      HAL_setupPwmOut(2, 3, params);
   }
   {
      PWM_Params_t *params = HAL_getDefaultPwmParams(2250, 50);
      HAL_setupPwmOut(3, 4, params);
   }
}

void Controls_step()
{
   if (Controls_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 2; ++i)
      {
         Controls_taskHit[i] = (Controls_taskTick[i] == 0);
      }
   }
   if (Controls_taskHit[0])
   {
      /* Delay : 'Controls/Delay1' */
      Controls_B.Delay1 = Controls_X.Delay1;

      /* Logical Operator : 'Controls/Logical\nOperator1' */
      Controls_B.LogicalOperator1 = !Controls_B.Delay1;
   }
   if (Controls_taskHit[1])
   {
      /* C-Script : 'Controls/C-Script' */
      Controls_0_cScriptOutput(&Controls_cScriptStruct[0]);
      if (*Controls_cScriptStruct[0].errorStatus)
         Controls_errorStatus = *Controls_cScriptStruct[0].errorStatus;
   }

   /* Digital Out : 'Controls/Digital Out (LED)' */
   HAL_setDigitalOut(0, Controls_B.C_Script);
   /* PWM Out : 'Controls/PWM Out (ePWM0)' */
   HAL_setPwmOutF(0, 0.5);
   HAL_setPwmOutF(1, 0.100000000000000006);
   /* Digital Out : 'Controls/Digital Out (LED)1' */
   HAL_setDigitalOut(1, HAL_getDigitalIn(0));
   HAL_setDigitalOut(2, HAL_getDigitalIn(1));
   /* PWM Out : 'Controls/PWM Out (ePWM0)1' */
   HAL_setPwmOutF(2, 0.5);
   HAL_setPwmOutF(3, 0.100000000000000006);
   if (Controls_errorStatus)
   {
      return;
   }
   if (Controls_taskHit[0])
   {
      /* Update for Delay : 'Controls/Delay1' */
      Controls_X.Delay1 = Controls_B.LogicalOperator1;
   }
   if (Controls_taskHit[1])
   {
      /* Update for C-Script : 'Controls/C-Script' */
      Controls_0_cScriptUpdate(&Controls_cScriptStruct[0]);
      if (*Controls_cScriptStruct[0].errorStatus)
         Controls_errorStatus = *Controls_cScriptStruct[0].errorStatus;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 2; ++i)
      {
         Controls_taskTick[i]++;
         if (Controls_taskTick[i] >= Controls_taskPeriod[i])
         {
            Controls_taskTick[i] = 0;
         }
      }
   }
}

void Controls_terminate()
{
   /* Termination for C-Script : 'Controls/C-Script' */
   Controls_0_cScriptTerminate(&Controls_cScriptStruct[0]);
   if (*Controls_cScriptStruct[0].errorStatus)
      Controls_errorStatus = *Controls_cScriptStruct[0].errorStatus;
}
