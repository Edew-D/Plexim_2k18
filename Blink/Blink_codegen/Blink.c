/*
 * Implementation file for: Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 25 Jun 2018 12:07:01
 */
#include "Blink.h"
#ifndef PLECS_HEADER_Blink_h_
#error The wrong header file "Blink.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Blink_h_ */
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
#include <math.h>
#include <string.h>
#include "DigitalOut.h"
#include "hw_wrapper.h"
#include "DigitalIn.h"
#include "AnalogOut.h"
#include "SFP.h"
#include "HIL_Framework.h"
#include "DataCapture.h"
#include "DataCaptureDefs.h"
#include "ProgrammableValue.h"
#include "ProgrammableValueDefs.h"
#define PLECSRunTimeError(msg) Blink_errorStatus = msg
static const uint32_t Blink_taskPeriod[1]= {
   /* [1, 0] */
   1000
};
static uint32_t Blink_taskTick[1];
static char Blink_taskHit[1];
Blink_BlockOutputs Blink_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
static double Blink_ExtModeBuffer[1];
const double * const Blink_ExtModeSignals[] = {
   &Blink_ExtModeBuffer[0]
};
#endif /* defined(EXTERNAL_MODE) */
Blink_ModelStates Blink_X _ALIGN;
const char * Blink_errorStatus;
const double Blink_sampleTime = 0.00100000000000000002;
const char * const Blink_checksum =
   "db5c106b726122c8b0427bb4e17a77285ece03b9";
/* Target declarations */
#if NUM_DATA_CAPTURE_BLOCKS > 0
struct PlxDataCaptureRegistry plxDataCaptureRegistry[NUM_DATA_CAPTURE_BLOCKS];
#else
   struct PlxDataCaptureRegistry plxDataCaptureRegistry[1];
#endif                                                            /* NUM_DATA_CAPTURE_BLOCKS */
#if NUM_PROGRAMMABLE_VALUE_BLOCKS > 0
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[
   NUM_PROGRAMMABLE_VALUE_BLOCKS];
#else
   struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[1];
#endif                                                                        /* NUM_PROGRAMMABLE_VALUE_BLOCKS */

void Blink_initialize(double time)
{
   uint32_t Blink_tickLo;
   int32_t Blink_tickHi;
   double remainder;
   Blink_errorStatus = NULL;
   Blink_tickHi = floor(time/(4294967296.0*Blink_sampleTime));
   remainder = time - Blink_tickHi*4294967296.0*Blink_sampleTime;
   Blink_tickLo = floor(remainder/Blink_sampleTime + .5);
   remainder -= Blink_tickLo*Blink_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Blink_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Blink_taskTick[0] = 0;           /* [1, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Blink_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -Blink_taskPeriod[i];
         delta %= Blink_taskPeriod[i];
         if (Blink_tickHi < 0)
         {
            delta = Blink_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Blink_taskTick[i] =
               (Blink_taskTick[i] + delta) % Blink_taskPeriod[i];
         }
         Blink_taskTick[i] =
            (Blink_taskTick[i] + Blink_tickLo %
          Blink_taskPeriod[i]) % Blink_taskPeriod[i];
      }
   }

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(0);
   setDigitalOutVoltage(0);
   initDigitalOut();
   initPWMCapture();
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);
   plxSetupAnalogSampling(1, 0, 1.00000000000000002e-03);


   /* Initialization for Delay : 'Blink/Delay' */
   Blink_X.Delay = 0.;

   /* Initialization for Digital Out : 'Blink/Digital Out1' */
   setupDigitalOut(0, DO_GPIO, DO_NINV);
}

void Blink_step()
{
   if (Blink_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Blink_taskHit[i] = (Blink_taskTick[i] == 0);
      }
   }
   if (Blink_taskHit[0])
   {
      /* Delay : 'Blink/Delay' */
      Blink_B.Delay = Blink_X.Delay;

      /* Logical Operator : 'Blink/Logical\nOperator' */
      Blink_B.LogicalOperator = !Blink_B.Delay;
   }

   /* Digital Out : 'Blink/Digital Out1' */
   writeDigitalOut(0, Blink_B.LogicalOperator);

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
   Blink_ExtModeBuffer[0] = Blink_B.LogicalOperator;
#endif /* defined(EXTERNAL_MODE) */

   if (Blink_errorStatus)
   {
      return;
   }
   if (Blink_taskHit[0])
   {
      /* Update for Delay : 'Blink/Delay'
       * incorporates
       *  Gain : 'Blink/Gain'
       */
      Blink_X.Delay = 1. * Blink_B.LogicalOperator;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Blink_taskTick[i]++;
         if (Blink_taskTick[i] >= Blink_taskPeriod[i])
         {
            Blink_taskTick[i] = 0;
         }
      }
   }
}

void Blink_terminate()
{
}
