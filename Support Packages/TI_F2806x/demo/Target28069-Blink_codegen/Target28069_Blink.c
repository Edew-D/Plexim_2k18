/*
 * Implementation file for: Target28069-Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 24 May 2018 11:23:35
 */
#include "Target28069_Blink.h"
#ifndef PLECS_HEADER_Target28069_Blink_h_
#error The wrong header file "Target28069_Blink.h" was included. Please
#error check your include path to see whether this file name conflicts with
#error the name of another header file.
#endif /* PLECS_HEADER_Target28069_Blink_h_ */
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
#define PLECSRunTimeError(msg) Target28069_Blink_errorStatus = msg
Target28069_Blink_ModelStates Target28069_Blink_X _ALIGN;
const char * Target28069_Blink_errorStatus;
const double Target28069_Blink_sampleTime = 0.00100000000000000002;
const char * const Target28069_Blink_checksum =
   "09f1b0541c10cac2014517f8d77ed976c94aa01b";
void Target28069_Blink_initialize(double time)
{
   Target28069_Blink_errorStatus = NULL;
}

void Target28069_Blink_step()
{
   if (Target28069_Blink_errorStatus)
   {
      return;
   }
   if (Target28069_Blink_errorStatus)
   {
      return;
   }
}

void Target28069_Blink_terminate()
{
}
