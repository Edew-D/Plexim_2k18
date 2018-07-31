/*
 * Implementation file for: ArduinoTest/Blink
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 31 Jul 2018 08:49:46
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
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "portConfig.h"
#include "analog_Config.h"
#define PLECSRunTimeError(msg) Blink_errorStatus = msg
const char * Blink_errorStatus;
const double Blink_sampleTime = 0.00100000000000000002;
const char * const Blink_checksum =
   "842ded2e8b79f6a67f357bedc3944c270e181095";
void Blink_initialize(double time)
{
   Blink_errorStatus = NULL;

   /* Initialization for Digital Out : 'Blink/Digital Out2' */
   configDout(0, 7);

   /* Initialization for Digital In : 'Blink/Digital In2' */
   configDin(1, 13);

   /* Initialization for Digital Out : 'Blink/Digital Out3' */
   configDout(2, 8);

   /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)' */
   configDout(3, 5);
   analogOut_init(3, 4, 0);

   /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)1' */
   configDout(4, 3);
   analogOut_init(4, 4, 0);

   /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)2' */
   configDout(5, 9);
   analogOut_init(5, 3, 0);

   /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)3' */
   configDout(6, 10);
   analogOut_init(6, 3, 0);
}

void Blink_step()
{
   if (Blink_errorStatus)
   {
      return;
   }
   /* Digital Out : 'Blink/Digital Out2' */
   setDout(0, 1.);
   /* Digital Out : 'Blink/Digital Out3' */
   setDout(2, getDin(1));
   /* PWM Out : 'Blink/PWM Out (ePWM0)' */
   set_analogOut(3, 0.5, 0);
   /* PWM Out : 'Blink/PWM Out (ePWM0)1' */
   set_analogOut(4, 0.5, 0);
   /* PWM Out : 'Blink/PWM Out (ePWM0)2' */
   set_analogOut(5, 0.5, 0);
   /* PWM Out : 'Blink/PWM Out (ePWM0)3' */
   set_analogOut(6, 0.5, 0);
   if (Blink_errorStatus)
   {
      return;
   }
}

void Blink_terminate()
{
}
