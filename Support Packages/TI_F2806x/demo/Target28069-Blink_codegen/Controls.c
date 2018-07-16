/*
 * Implementation file for: Target28069-Blink/Controls
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 27 Mar 2018 14:57:29
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
static const uint32_t Controls_taskPeriod[1]= {
   /* [0.5, 0] */
   5000
};
static uint32_t Controls_taskTick[1];
static char Controls_taskHit[1];
Controls_BlockOutputs Controls_B;
Controls_ModelStates Controls_X _ALIGN;
const char * Controls_errorStatus;
const double Controls_sampleTime = 0.000100000000000000005;
const char * const Controls_checksum =
   "8419da5fb4862e637b4998c308ed425beed5b810";
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


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Controls_tickHi);
      for (i = 0; i < 1; ++i)
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

   /* Initialization for Delay : 'Controls/Delay1' */
   Controls_X.Delay1 = 0.;

   /* Initialization for Digital Out : 'Controls/Digital Out (LED)' */
   HAL_setupDigitalOut(0, 11, false);
}

void Controls_step()
{
   if (Controls_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
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

   /* Digital Out : 'Controls/Digital Out (LED)' */
   HAL_setDigitalOut(0, Controls_B.LogicalOperator1);
   if (Controls_errorStatus)
   {
      return;
   }
   if (Controls_taskHit[0])
   {
      /* Update for Delay : 'Controls/Delay1' */
      Controls_X.Delay1 = Controls_B.LogicalOperator1;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
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
}
