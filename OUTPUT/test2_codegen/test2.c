/*
 * Implementation file for: test2
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 30 Jul 2018 08:23:50
 */
#include "test2.h"
#ifndef PLECS_HEADER_test2_h_
#error The wrong header file "test2.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_test2_h_ */
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
#include "portConfig.h"
#define PLECSRunTimeError(msg) test2_errorStatus = msg
const char * test2_errorStatus;
const double test2_sampleTime = 0.00100000000000000002;
const char * const test2_checksum =
   "f0e9cae8a34a38eef46b4e126986b9f07f2d7b6f";
void test2_initialize(double time)
{
   test2_errorStatus = NULL;

   /* Initialization for Digital Out : 'test2/Digital Out2' */
   configDout(0, 7);
}

void test2_step()
{
   if (test2_errorStatus)
   {
      return;
   }
   /* Digital Out : 'test2/Digital Out2' */
   setDout(0, 0.);
   if (test2_errorStatus)
   {
      return;
   }
}

void test2_terminate()
{
}
