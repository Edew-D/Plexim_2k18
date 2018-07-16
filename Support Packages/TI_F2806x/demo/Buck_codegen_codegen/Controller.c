/*
 * Implementation file for: Buck_codegen/Controller
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 10 Jul 2018 09:37:10
 */
#include "Controller.h"
#ifndef PLECS_HEADER_Controller_h_
#error The wrong header file "Controller.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Controller_h_ */
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
#include "hal.h"
#define PLECSRunTimeError(msg) Controller_errorStatus = msg
static const uint32_t Controller_taskPeriod[1]= {
   /* [0.5, 0] */
   5000
};
static uint32_t Controller_taskTick[1];
static char Controller_taskHit[1];
Controller_BlockOutputs Controller_B;
Controller_ModelStates Controller_X _ALIGN;
const char * Controller_errorStatus;
const double Controller_sampleTime = 0.000100000000000000005;
const char * const Controller_checksum =
   "7e9f99d39ec2b309c39879af55afda8b32aa1226";
void Controller_initialize(double time)
{
   uint32_t Controller_tickLo;
   int32_t Controller_tickHi;
   double remainder;
   Controller_errorStatus = NULL;
   Controller_tickHi = floor(time/(4294967296.0*Controller_sampleTime));
   remainder = time - Controller_tickHi*4294967296.0*Controller_sampleTime;
   Controller_tickLo = floor(remainder/Controller_sampleTime + .5);
   remainder -= Controller_tickLo*Controller_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Controller_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Controller_taskTick[0] = 0;      /* [0.5, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Controller_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -Controller_taskPeriod[i];
         delta %= Controller_taskPeriod[i];
         if (Controller_tickHi < 0)
         {
            delta = Controller_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Controller_taskTick[i] =
               (Controller_taskTick[i] + delta) % Controller_taskPeriod[i];
         }
         Controller_taskTick[i] =
            (Controller_taskTick[i] + Controller_tickLo %
          Controller_taskPeriod[i]) % Controller_taskPeriod[i];
      }
   }

   /* Initialization for Delay : 'Controller/Delay1' */
   Controller_X.Delay1 = 0.;

   /* Initialization for Digital Out : 'Controller/Digital Out (LED)' */
   HAL_setupDigitalOut(0, 34, false);
}

void Controller_step()
{
   if (Controller_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Controller_taskHit[i] = (Controller_taskTick[i] == 0);
      }
   }
   if (Controller_taskHit[0])
   {
      /* Delay : 'Controller/Delay1' */
      Controller_B.Delay1 = Controller_X.Delay1;

      /* Logical Operator : 'Controller/Logical\nOperator1' */
      Controller_B.LogicalOperator1 = !Controller_B.Delay1;
   }

   /* Digital Out : 'Controller/Digital Out (LED)' */
   HAL_setDigitalOut(0, Controller_B.LogicalOperator1);
   if (Controller_errorStatus)
   {
      return;
   }
   if (Controller_taskHit[0])
   {
      /* Update for Delay : 'Controller/Delay1' */
      Controller_X.Delay1 = Controller_B.LogicalOperator1;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Controller_taskTick[i]++;
         if (Controller_taskTick[i] >= Controller_taskPeriod[i])
         {
            Controller_taskTick[i] = 0;
         }
      }
   }
}

void Controller_terminate()
{
}
