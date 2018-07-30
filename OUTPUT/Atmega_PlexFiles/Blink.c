/*
 * Implementation file for: ArduinoTest/Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 10 Jul 2018 11:46:42
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
#include "hal.h"
#define PLECSRunTimeError(msg) Blink_errorStatus = msg
const char * Blink_errorStatus;
const double Blink_sampleTime = 0.00100000000000000002;
const char * const Blink_checksum =
   "10ed98013a9315fb9729bb9039f21cc5521995ed";
void Blink_initialize(double time)
{
   Blink_errorStatus = NULL;

   /* Initialization for Digital Out : 'Blink/Digital Out1' */
   HAL_setupDigitalOut(0, 1, false);
}

void Blink_step()
{
   if (Blink_errorStatus)
   {
      return;
   }
   /* Digital Out : 'Blink/Digital Out1' */
   HAL_setDigitalOut(0, 1);
   if (Blink_errorStatus)
   {
      return;
   }
}

void Blink_terminate()
{
}
