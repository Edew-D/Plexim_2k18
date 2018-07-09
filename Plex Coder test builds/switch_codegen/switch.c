/*
 * Implementation file for: switch
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 5 Jul 2018 11:07:22
 */
#include "switch.h"
#ifndef PLECS_HEADER_switch_h_
#error The wrong header file "switch.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_switch_h_ */
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
#include "DigitalIn.h"
#include "DigitalOut.h"
#include "hw_wrapper.h"
#include "AnalogOut.h"
#include "SFP.h"
#include "HIL_Framework.h"
#include "DataCapture.h"
#include "DataCaptureDefs.h"
#include "ProgrammableValue.h"
#include "ProgrammableValueDefs.h"
#define PLECSRunTimeError(msg) switch_errorStatus = msg

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const switch_ExtModeSignals[] = {

};
#endif /* defined(EXTERNAL_MODE) */
const char * switch_errorStatus;
const double switch_sampleTime = 0.00100000000000000002;
const char * const switch_checksum =
   "7c739e87bb28fb9957e8024c54a2c852c553bd22";
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

void switch_initialize(double time)
{
   switch_errorStatus = NULL;

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(0);
   setDigitalOutVoltage(0);
   initDigitalOut();
   initPWMCapture();
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);
   plxSetupAnalogSampling(1, 0, 1.00000000000000002e-03);


   /* Initialization for Digital Out : 'switch/Digital Out2' */
   setupDigitalOut(29, DO_GPIO, DO_NINV);

   /* Initialization for Digital Out : 'switch/Digital Out3' */
   setupDigitalOut(28, DO_GPIO, DO_NINV);

   /* Initialization for Digital Out : 'switch/Digital Out5' */
   setupDigitalOut(30, DO_GPIO, DO_NINV);
}

void switch_step()
{
   if (switch_errorStatus)
   {
      return;
   }
   /* Digital Out : 'switch/Digital Out2'
    * incorporates
    *  Logical Operator : 'switch/Logical\nOperator'
    *  Digital In : 'switch/Digital In2'
    *  Digital In : 'switch/Digital In3'
    */
   writeDigitalOut(29, (getDigitalIn(31)) && (getDigitalIn(30)));

   /* Digital Out : 'switch/Digital Out3'
    * incorporates
    *  Digital In : 'switch/Digital In2'
    */
   writeDigitalOut(28, getDigitalIn(31));

   /* Digital Out : 'switch/Digital Out5'
    * incorporates
    *  Digital In : 'switch/Digital In3'
    */
   writeDigitalOut(30, getDigitalIn(30));
   if (switch_errorStatus)
   {
      return;
   }
}

void switch_terminate()
{
}
