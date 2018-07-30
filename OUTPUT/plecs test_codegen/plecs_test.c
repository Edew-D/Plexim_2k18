/*
 * Implementation file for: plecs test
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 26 Jul 2018 08:27:05
 */
#include "plecs_test.h"
#ifndef PLECS_HEADER_plecs_test_h_
#error The wrong header file "plecs_test.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_plecs_test_h_ */
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
#define PLECSRunTimeError(msg) plecs_test_errorStatus = msg
plecs_test_ExternalInputs plecs_test_U;
plecs_test_ExternalOutputs plecs_test_Y;
plecs_test_ModelStates plecs_test_X _ALIGN;
const char * plecs_test_errorStatus;
const double plecs_test_sampleTime = 0.00100000000000000002;
const char * const plecs_test_checksum =
   "c800eddc37ea1977ee5967e74e20aa6e7758b83d";
void plecs_test_initialize(double time)
{
   plecs_test_errorStatus = NULL;
}

void plecs_test_step()
{
   if (plecs_test_errorStatus)
   {
      return;
   }

   /* Global output signals */
   plecs_test_Y.DigitalOut2 = 1.;
   plecs_test_Y.DigitalOut3 = plecs_test_U.DigitalIn2;
   plecs_test_Y.PWMOut_ePWM0_ = 0.800000000000000044;
   plecs_test_Y.PWMOut_ePWM0_1 = 0.800000000000000044;
   if (plecs_test_errorStatus)
   {
      return;
   }
}

void plecs_test_terminate()
{
}
