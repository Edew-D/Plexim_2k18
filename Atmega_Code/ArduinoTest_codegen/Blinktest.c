/*
 * Implementation file for: ArduinoTest/Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 17 Jul 2018 10:41:47
 */
#include "Blinktest.h"
#ifndef PLECS_HEADER_Blinktest_h_
#error The wrong header file "Blinktest.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Blinktest_h_ */
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
#include "setup.h"
#define PLECSRunTimeError(msg) Blinktest_errorStatus = msg
static const uint32_t Blinktest_taskPeriod[1]= {
   /* [1, 0] */
   1000
};
static uint32_t Blinktest_taskTick[1];
static char Blinktest_taskHit[1];
Blinktest_BlockOutputs Blinktest_B;
Blinktest_ModelStates Blinktest_X _ALIGN;
const char * Blinktest_errorStatus;
const double Blinktest_sampleTime = 0.00100000000000000002;
const char * const Blinktest_checksum =
   "82269781b9b9a110a8f41229c333aaed2b177526";
void Blinktest_initialize(double time)
{
   uint32_t Blinktest_tickLo;
   int32_t Blinktest_tickHi;
   double remainder;
   Blinktest_errorStatus = NULL;
   Blinktest_tickHi = floor(time/(4294967296.0*Blinktest_sampleTime));
   remainder = time - Blinktest_tickHi*4294967296.0*Blinktest_sampleTime;
   Blinktest_tickLo = floor(remainder/Blinktest_sampleTime + .5);
   remainder -= Blinktest_tickLo*Blinktest_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Blinktest_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Blinktest_taskTick[0] = 0;       /* [1, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Blinktest_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -Blinktest_taskPeriod[i];
         delta %= Blinktest_taskPeriod[i];
         if (Blinktest_tickHi < 0)
         {
            delta = Blinktest_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Blinktest_taskTick[i] =
               (Blinktest_taskTick[i] + delta) % Blinktest_taskPeriod[i];
         }
         Blinktest_taskTick[i] =
            (Blinktest_taskTick[i] + Blinktest_tickLo %
          Blinktest_taskPeriod[i]) % Blinktest_taskPeriod[i];
      }
   }

   /* Initialization for Delay : 'Blink/Delay1' */
   Blinktest_X.Delay1 = 0.;

   /* Initialization for Digital Out : 'Blink/Digital Out2' */
   configDout(0, 6);

   /* Initialization for Digital In : 'Blink/Digital In2' */
   configDin(1, 13);

   /* Initialization for Digital Out : 'Blink/Digital Out3' */
   configDout(2, 9);
}

void Blinktest_step()
{
   if (Blinktest_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Blinktest_taskHit[i] = (Blinktest_taskTick[i] == 0);
      }
   }
   if (Blinktest_taskHit[0])
   {
      /* Delay : 'Blink/Delay1' */
      Blinktest_B.Delay1 = Blinktest_X.Delay1;

      /* Logical Operator : 'Blink/Logical\nOperator1' */
      Blinktest_B.LogicalOperator1 = !Blinktest_B.Delay1;
   }

   /* Digital Out : 'Blink/Digital Out2' */
   setDout(0, Blinktest_B.LogicalOperator1);
   /* Digital Out : 'Blink/Digital Out3' */
   setDout(2, getDin(1));
   if (Blinktest_errorStatus)
   {
      return;
   }
   if (Blinktest_taskHit[0])
   {
      /* Update for Delay : 'Blink/Delay1' */
      Blinktest_X.Delay1 = Blinktest_B.LogicalOperator1;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Blinktest_taskTick[i]++;
         if (Blinktest_taskTick[i] >= Blinktest_taskPeriod[i])
         {
            Blinktest_taskTick[i] = 0;
         }
      }
   }
}

void Blinktest_terminate()
{
}
