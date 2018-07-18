/*
 * Implementation file for: ArduinoTest/Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 18 Jul 2018 11:07:08
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
#include "portConfig.h"
#define PLECSRunTimeError(msg) Blink_errorStatus = msg
static const uint32_t Blink_taskPeriod[1]= {
   /* [0.5, 0] */
   500
};
static uint32_t Blink_taskTick[1];
static char Blink_taskHit[1];
Blink_BlockOutputs Blink_B;
Blink_ModelStates Blink_X _ALIGN;
const char * Blink_errorStatus;
const double Blink_sampleTime = 0.00100000000000000002;
const char * const Blink_checksum =
   "5a83c61a3ea68836c34a946e9b3e1dde6702281d";
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
   Blink_taskTick[0] = 0;           /* [0.5, 0] */


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

   /* Initialization for Delay : 'Blink/Delay1' */
   Blink_X.Delay1 = 0.;

   /* Initialization for Digital Out : 'Blink/Digital Out2' */
   configDout(0, 6);

   /* Initialization for Digital In : 'Blink/Digital In2' */
   configDin(1, 13);

   /* Initialization for Digital Out : 'Blink/Digital Out3' */
   configDout(2, 9);
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
      /* Delay : 'Blink/Delay1' */
      Blink_B.Delay1 = Blink_X.Delay1;

      /* Logical Operator : 'Blink/Logical\nOperator1' */
      Blink_B.LogicalOperator1 = !Blink_B.Delay1;
   }

   /* Digital Out : 'Blink/Digital Out2' */
   setDout(0, Blink_B.LogicalOperator1);
   /* Digital Out : 'Blink/Digital Out3' */
   setDout(2, getDin(1));
   if (Blink_errorStatus)
   {
      return;
   }
   if (Blink_taskHit[0])
   {
      /* Update for Delay : 'Blink/Delay1' */
      Blink_X.Delay1 = Blink_B.LogicalOperator1;
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
