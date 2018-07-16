/*
 * Implementation file for: ArduinoTest
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 16 Jul 2018 12:02:38
 */
#include "ArduinoTest.h"
#ifndef PLECS_HEADER_ArduinoTest_h_
#error The wrong header file "ArduinoTest.h" was included. Please check
#error your include path to see whether this file name conflicts with the
#error name of another header file.
#endif /* PLECS_HEADER_ArduinoTest_h_ */
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
#define PLECSRunTimeError(msg) ArduinoTest_errorStatus = msg
ArduinoTest_ModelStates ArduinoTest_X _ALIGN;
const char * ArduinoTest_errorStatus;
const double ArduinoTest_sampleTime = 0.00100000000000000002;
const char * const ArduinoTest_checksum =
   "03bdab7a009ef777d7cc4578af1d936aa84ca3e8";
void ArduinoTest_initialize(double time)
{
   ArduinoTest_errorStatus = NULL;
}

void ArduinoTest_step()
{
   if (ArduinoTest_errorStatus)
   {
      return;
   }
   if (ArduinoTest_errorStatus)
   {
      return;
   }
}

void ArduinoTest_terminate()
{
}
