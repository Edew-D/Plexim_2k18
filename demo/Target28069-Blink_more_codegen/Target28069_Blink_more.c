/*
 * Implementation file for: Target28069-Blink_more
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 30 Jul 2018 08:56:01
 */
#include "Target28069_Blink_more.h"
#ifndef PLECS_HEADER_Target28069_Blink_more_h_
#error The wrong header file "Target28069_Blink_more.h" was included.
#error Please check your include path to see whether this file name
#error conflicts with the name of another header file.
#endif /* PLECS_HEADER_Target28069_Blink_more_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
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
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define PLECSRunTimeError(msg) Target28069_Blink_more_errorStatus = msg
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
static struct CScriptStruct Target28069_Blink_more_cScriptStruct[1];
static char Target28069_Blink_more_isMajorStep = '\001';
static const uint32_t Target28069_Blink_more_taskPeriod[1]= {
   /* [0.5, 0] */
   500
};
static uint32_t Target28069_Blink_more_taskTick[1];
static char Target28069_Blink_more_taskHit[1];
static double Target28069_Blink_more_D_double[1];
void Target28069_Blink_more_0_cScriptStart(
                                           const struct CScriptStruct *cScriptStruct);
void Target28069_Blink_more_0_cScriptOutput(
                                            const struct CScriptStruct *cScriptStruct);
void Target28069_Blink_more_0_cScriptUpdate(
                                            const struct CScriptStruct *cScriptStruct);
void Target28069_Blink_more_0_cScriptDerivative(
                                                const struct CScriptStruct *cScriptStruct);
void Target28069_Blink_more_0_cScriptTerminate(
                                               const struct CScriptStruct *cScriptStruct);
Target28069_Blink_more_BlockOutputs Target28069_Blink_more_B;
Target28069_Blink_more_ModelStates Target28069_Blink_more_X _ALIGN;
const char * Target28069_Blink_more_errorStatus;
const double Target28069_Blink_more_sampleTime = 0.00100000000000000002;
const char * const Target28069_Blink_more_checksum =
   "5bec76bd0f6caa4f5ffa0acc9daed62f31129144";
void Target28069_Blink_more_initialize(double time)
{
   uint32_t Target28069_Blink_more_tickLo;
   int32_t Target28069_Blink_more_tickHi;
   double remainder;
   Target28069_Blink_more_errorStatus = NULL;
   Target28069_Blink_more_tickHi =
      floor(time/(4294967296.0*Target28069_Blink_more_sampleTime));
   remainder = time - Target28069_Blink_more_tickHi*4294967296.0*
               Target28069_Blink_more_sampleTime;
   Target28069_Blink_more_tickLo = floor(
                                         remainder/Target28069_Blink_more_sampleTime +
                                         .5);
   remainder -= Target28069_Blink_more_tickLo*
                Target28069_Blink_more_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Target28069_Blink_more_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Target28069_Blink_more_taskTick[0] = 0; /* [0.5, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Target28069_Blink_more_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -Target28069_Blink_more_taskPeriod[i];
         delta %= Target28069_Blink_more_taskPeriod[i];
         if (Target28069_Blink_more_tickHi < 0)
         {
            delta = Target28069_Blink_more_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Target28069_Blink_more_taskTick[i] =
               (Target28069_Blink_more_taskTick[i] +
                delta) % Target28069_Blink_more_taskPeriod[i];
         }
         Target28069_Blink_more_taskTick[i] =
            (Target28069_Blink_more_taskTick[i] +
             Target28069_Blink_more_tickLo %
             Target28069_Blink_more_taskPeriod[i]) %
            Target28069_Blink_more_taskPeriod[i];
      }
   }

   /* Initialization for Subsystem : 'Target28069-Blink_more/Controls' */
   Target28069_Blink_more_X.Delay1 = 0.;
   {
      static int numInputSignals[] = {
         1
      };
      static const double* inputPtrs[] = {
         &Target28069_Blink_more_D_double[0]
      };
      static const double** inputs[] = {
         &inputPtrs[0]
      };
      static int numOutputSignals[] = {
         1
      };
      static double* outputPtrs[] = {
         &Target28069_Blink_more_B.C_Script
      };
      static double** outputs[] = {
         &outputPtrs[0]
      };
      static double nextSampleHit;
      static const char * sampleHits[] = {
         &Target28069_Blink_more_isMajorStep
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
      Target28069_Blink_more_cScriptStruct[0].isMajorTimeStep = 1;
      Target28069_Blink_more_cScriptStruct[0].numInputTerminals = 1;
      Target28069_Blink_more_cScriptStruct[0].numInputSignals =
         numInputSignals;
      Target28069_Blink_more_cScriptStruct[0].inputs = inputs;
      Target28069_Blink_more_cScriptStruct[0].numOutputTerminals = 1;
      Target28069_Blink_more_cScriptStruct[0].numOutputSignals =
         numOutputSignals;
      Target28069_Blink_more_cScriptStruct[0].outputs = outputs;
      Target28069_Blink_more_cScriptStruct[0].numContStates = 0;
      Target28069_Blink_more_cScriptStruct[0].contStates = NULL;
      Target28069_Blink_more_cScriptStruct[0].contDerivs = NULL;
      Target28069_Blink_more_cScriptStruct[0].numDiscStates = 0;
      Target28069_Blink_more_cScriptStruct[0].discStates = NULL;
      Target28069_Blink_more_cScriptStruct[0].numZCSignals = 0;
      Target28069_Blink_more_cScriptStruct[0].numParameters = 0;
      Target28069_Blink_more_cScriptStruct[0].paramNumDims = NULL;
      Target28069_Blink_more_cScriptStruct[0].paramDims = NULL;
      Target28069_Blink_more_cScriptStruct[0].paramNumElements = NULL;
      Target28069_Blink_more_cScriptStruct[0].paramRealData = NULL;
      Target28069_Blink_more_cScriptStruct[0].paramStringData = NULL;
      Target28069_Blink_more_cScriptStruct[0].numSampleTimes = 1;
      Target28069_Blink_more_cScriptStruct[0].sampleTimePeriods =
         sampleTimePeriods;
      Target28069_Blink_more_cScriptStruct[0].sampleTimeOffsets =
         sampleTimeOffsets;
      Target28069_Blink_more_cScriptStruct[0].numSampleTimes = 1;
      Target28069_Blink_more_cScriptStruct[0].sampleHits = sampleHits;
      Target28069_Blink_more_cScriptStruct[0].nextSampleHit = &nextSampleHit;
      Target28069_Blink_more_cScriptStruct[0].errorStatus = &errorStatus;
      Target28069_Blink_more_cScriptStruct[0].warningStatus = &warningStatus;
      Target28069_Blink_more_cScriptStruct[0].rangeErrorMsg = &rangeErrorMsg;
      Target28069_Blink_more_0_cScriptStart(
                                            &Target28069_Blink_more_cScriptStruct[
                                               0]);
      if (*Target28069_Blink_more_cScriptStruct[0].errorStatus)
         Target28069_Blink_more_errorStatus =
            *Target28069_Blink_more_cScriptStruct[0].errorStatus;
   }
}

void Target28069_Blink_more_step()
{
   if (Target28069_Blink_more_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Target28069_Blink_more_taskHit[i] =
            (Target28069_Blink_more_taskTick[i] == 0);
      }
   }

   /* Subsystem : 'Target28069-Blink_more/Controls'
    * incorporates
    *  Subsystem : 'Target28069-Blink_more'
    */
   {
      if (Target28069_Blink_more_taskHit[0])
      {
         /* Delay : 'Target28069-Blink_more/Controls/Delay1' */
         Target28069_Blink_more_B.Delay1 = Target28069_Blink_more_X.Delay1;

         /* Logical Operator : 'Target28069-Blink_more/Controls/Logical\nOperator1' */
         Target28069_Blink_more_B.LogicalOperator1 =
            !Target28069_Blink_more_B.Delay1;
      }
      /* C-Script : 'Target28069-Blink_more/Controls/C-Script' */
      Target28069_Blink_more_D_double[0] =
         Target28069_Blink_more_B.LogicalOperator1;
      Target28069_Blink_more_0_cScriptOutput(
                                             &Target28069_Blink_more_cScriptStruct[
                                                0]);
      if (*Target28069_Blink_more_cScriptStruct[0].errorStatus)
         Target28069_Blink_more_errorStatus =
            *Target28069_Blink_more_cScriptStruct[0].errorStatus;
      Target28069_Blink_more_B.Controls[0] =
         Target28069_Blink_more_B.C_Script;
      Target28069_Blink_more_B.Controls[1] = 0.5;
      Target28069_Blink_more_B.Controls[2] = 0.100000000000000006;
      Target28069_Blink_more_B.Controls[3] = 0.;
      Target28069_Blink_more_B.Controls[4] = 0.;
      Target28069_Blink_more_B.Controls[5] = 0.5;
      Target28069_Blink_more_B.Controls[6] = 0.100000000000000006;
   }
   if (Target28069_Blink_more_errorStatus)
   {
      return;
   }

   /* Update for Subsystem : 'Target28069-Blink_more/Controls' */
   {
      if (Target28069_Blink_more_taskHit[0])
      {
         /* Update for Delay : 'Target28069-Blink_more/Controls/Delay1' */
         Target28069_Blink_more_X.Delay1 =
            Target28069_Blink_more_B.LogicalOperator1;
      }
      /* Update for C-Script : 'Target28069-Blink_more/Controls/C-Script' */
      Target28069_Blink_more_0_cScriptUpdate(
                                             &Target28069_Blink_more_cScriptStruct[
                                                0]);
      if (*Target28069_Blink_more_cScriptStruct[0].errorStatus)
         Target28069_Blink_more_errorStatus =
            *Target28069_Blink_more_cScriptStruct[0].errorStatus;
   }
   /* Increment sub-task tick counters */
   {
      size_t i;
      for (i = 0; i < 1; ++i)
      {
         Target28069_Blink_more_taskTick[i]++;
         if (Target28069_Blink_more_taskTick[i] >=
             Target28069_Blink_more_taskPeriod[i])
         {
            Target28069_Blink_more_taskTick[i] = 0;
         }
      }
   }
}

void Target28069_Blink_more_terminate()
{
   /* Termination for Subsystem : 'Target28069-Blink_more/Controls' */
   Target28069_Blink_more_0_cScriptTerminate(
                                             &Target28069_Blink_more_cScriptStruct[
                                                0]);
   if (*Target28069_Blink_more_cScriptStruct[0].errorStatus)
      Target28069_Blink_more_errorStatus =
         *Target28069_Blink_more_cScriptStruct[0].errorStatus;
}
