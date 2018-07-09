/*
 * Implementation file for: ArduinoTest
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 9 Jul 2018 14:24:49
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
const char * ArduinoTest_errorStatus;
const double ArduinoTest_sampleTime = 0.00100000000000000002;
const char * const ArduinoTest_checksum =
   "f55c3ec8f79b2d3c43e750653ffd728a22008799";
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
