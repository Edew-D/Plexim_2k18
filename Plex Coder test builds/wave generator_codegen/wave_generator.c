/*
 * Implementation file for: wave generator
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 6 Jul 2018 11:35:28
 */
#include "wave_generator.h"
#ifndef PLECS_HEADER_wave_generator_h_
#error The wrong header file "wave_generator.h" was included. Please check
#error your include path to see whether this file name conflicts with the
#error name of another header file.
#endif /* PLECS_HEADER_wave_generator_h_ */
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
#include "AnalogOut.h"
#include "DigitalOut.h"
#include "hw_wrapper.h"
#include "DigitalIn.h"
#include "SFP.h"
#include "HIL_Framework.h"
#include "DataCapture.h"
#include "DataCaptureDefs.h"
#include "ProgrammableValue.h"
#include "ProgrammableValueDefs.h"
#define PLECSRunTimeError(msg) wave_generator_errorStatus = msg
static double wave_generator_D_double[2];
wave_generator_BlockOutputs wave_generator_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const wave_generator_ExtModeSignals[] = {
   &wave_generator_B.SineWave
};
#endif /* defined(EXTERNAL_MODE) */
const char * wave_generator_errorStatus;
const double wave_generator_sampleTime = 9.99999999999999955e-7;
const char * const wave_generator_checksum =
   "c0a16aa0e344e8fc29859b862d3781de741acfb5";
/* Target declarations */
#if NUM_DATA_CAPTURE_BLOCKS > 0
struct PlxDataCaptureRegistry plxDataCaptureRegistry[NUM_DATA_CAPTURE_BLOCKS];
#else
   struct PlxDataCaptureRegistry plxDataCaptureRegistry[1];
#endif                                                            /* NUM_DATA_CAPTURE_BLOCKS */
#if NUM_PROGRAMMABLE_VALUE_BLOCKS > 0
struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[
   NUM_PROGRAMMABLE_VALUE_BLOCKS];
#else
   struct PlxProgrammableValueRegistry plxProgrammableValueRegistry[1];
#endif                                                                        /* NUM_PROGRAMMABLE_VALUE_BLOCKS */

void wave_generator_initialize(double time)
{
   wave_generator_errorStatus = NULL;

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(3);
   setDigitalOutVoltage(0);
   initDigitalOut();
   initPWMCapture();
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);
   plxSetupAnalogSampling(1, 0, 9.99999999999999955e-07);


   /* Initialization for Sine Wave Generator : 'wave generator/Sine Wave' */
   wave_generator_D_double[0] = sin(376.991118430775145*time);
   wave_generator_D_double[1] = cos(376.991118430775145*time);

   /* Initialization for Analog Out : 'wave generator/Analog Out1' */
   setupAnalogOut(15, 1.000000000e+00f, 1.500000000e+00f, -inf, inf);

   /* Initialization for Digital Out : 'wave generator/Digital Out1' */
   setupDigitalOut(0, DO_GPIO, DO_NINV);
}

void wave_generator_step()
{
   if (wave_generator_errorStatus)
   {
      return;
   }

   /* Sine Wave Generator : 'wave generator/Sine Wave' */
   wave_generator_B.SineWave = 0. + 3. *
                               (1.*wave_generator_D_double[0] + 0.*
                                wave_generator_D_double[1]);
   /* Analog Out : 'wave generator/Analog Out1' */
   setAnalogOut(15, wave_generator_B.SineWave);

   /* Digital Out : 'wave generator/Digital Out1' */
   writeDigitalOut(0, wave_generator_B.SineWave);
   if (wave_generator_errorStatus)
   {
      return;
   }

   /* Update for Sine Wave Generator : 'wave generator/Sine Wave' */
   {
      double scaling, scaledX, scaledY;
      scaling = 1. +
                (0.5 *
                 (wave_generator_D_double[0]*wave_generator_D_double[0] +
        wave_generator_D_double[1]*wave_generator_D_double[1] - 1.));
      scaledX = wave_generator_D_double[0] / scaling;
      scaledY = wave_generator_D_double[1] / scaling;
      wave_generator_D_double[0] = 0.999999928938849147 * scaledX +
                                   0.000376991109500967507 * scaledY;
      wave_generator_D_double[1] = -0.000376991109500967507 * scaledX +
                                   0.999999928938849147 * scaledY;
   }
}

void wave_generator_terminate()
{
}
