/*
 * Implementation file for: Buck_codegen/H-Bridge and Inductive Load
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 9 Jul 2018 11:47:43
 */
#include "H_Bridge_and_Inductive_Load.h"
#ifndef PLECS_HEADER_H_Bridge_and_Inductive_Load_h_
#error The wrong header file "H_Bridge_and_Inductive_Load.h" was included.
#error Please check your include path to see whether this file name
#error conflicts with the name of another header file.
#endif /* PLECS_HEADER_H_Bridge_and_Inductive_Load_h_ */
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
#include "AnalogOut.h"
#include "DigitalOut.h"
#include "hw_wrapper.h"
#include "SFP.h"
#include "HIL_Framework.h"
#include "DataCapture.h"
#include "DataCaptureDefs.h"
#include "ProgrammableValue.h"
#include "ProgrammableValueDefs.h"
#define PLECSRunTimeError(msg) H_Bridge_and_Inductive_Load_errorStatus = msg
static const uint32_t H_Bridge_and_Inductive_Load_taskPeriod[1]= {
   /* [0.5, 0] */
   125000
};
static uint32_t H_Bridge_and_Inductive_Load_taskTick[1];
static char H_Bridge_and_Inductive_Load_taskHit[1];
static double H_Bridge_and_Inductive_Load_PM0_u[3] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM0_prevU[3] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM0_y[3] _ALIGN;
static size_t H_Bridge_and_Inductive_Load_PM0_topoIdx;
static char H_Bridge_and_Inductive_Load_PM0_withDiracs;
static size_t H_Bridge_and_Inductive_Load_PM0_topologies[1]={
   0
};
static double * _RESTRICT H_Bridge_and_Inductive_Load_PM1_x;
static double H_Bridge_and_Inductive_Load_PM1_tmpX[1] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM1_prevX[1] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM1_u[4] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM1_prevU[4] _ALIGN;
static double H_Bridge_and_Inductive_Load_PM1_y[5] _ALIGN;
static size_t H_Bridge_and_Inductive_Load_PM1_topoIdx;
static char H_Bridge_and_Inductive_Load_PM1_withDiracs;
static const size_t PM1_A_0_rowPtr[] = {
   0,0
};
static const size_t PM1_A_0_colIdx[] = {
   0
};
static const double PM1_A_0_data[] _ALIGN = {
   0
};
static const size_t PM1_B0_0_rowPtr[] = {
   0,0
};
static const size_t PM1_B0_0_colIdx[] = {
   0
};
static const double PM1_B0_0_data[] _ALIGN = {
   0
};
static const size_t PM1_B1_0_rowPtr[] = {
   0,0
};
static const size_t PM1_B1_0_colIdx[] = {
   0
};
static const double PM1_B1_0_data[] _ALIGN = {
   0
};
static const size_t PM1_C_0_0_rowPtr[] = {
   0,0,0,0,0,0
};
static const size_t PM1_C_0_0_colIdx[] = {
   0
};
static const double PM1_C_0_0_data[] _ALIGN = {
   0
};
static const size_t PM1_D_0_0_rowPtr[] = {
   0,0,0,0,0,0
};
static const size_t PM1_D_0_0_colIdx[] = {
   0
};
static const double PM1_D_0_0_data[] _ALIGN = {
   0
};
static void PM1_collision_0()
{
   double * _RESTRICT x = H_Bridge_and_Inductive_Load_PM1_x;
   x[0] = 0.;
}
static size_t PM1_natPreComm_0()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   if (-u[0]-3.*u[1]-u[2]+u[3] >= 0)
   {
      if (u[0]+0.333333333333333315*u[1]-0.333333333333333315*u[2]+
          0.333333333333333315*u[3] > 0)
      {
         if (u[0]-u[1]+u[2]+3.*u[3] > 0)
         {
            if (u[0]-u[1]-3.*u[2]-u[3] >= 0)
            {
               return 1; /* 6 */
            }
         }
      }
   }
   else
   {
      if (-u[0]-0.333333333333333315*u[1]+0.333333333333333315*u[2]-
          0.333333333333333315*u[3] >= 0)
      {
         if (-u[0]+u[1]-u[2]-3.*u[3] >= 0)
         {
            if (-u[0]+u[1]+3.*u[2]+u[3] > 0)
            {
               return 2; /* 9 */
            }
         }
      }
   }
   return 0; /* 0 */
}
static size_t PM1_natPostComm_0()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   if (u[0]+u[3] > 0)
   {
      return 1; /* 6 */
   }
   if (u[1]+u[2] > 0)
   {
      return 2; /* 9 */
   }
   return 0; /* 0 */
}
static size_t PM1_forcedComm_0()
{
   return 0;                                /* 0 */
}
static const size_t PM1_A_6_rowPtr[] = {
   0,1
};
static const size_t PM1_A_6_colIdx[] = {
   0
};
static const double PM1_A_6_data[] _ALIGN = {
   0.984127320055260713
};
static const size_t PM1_B0_6_rowPtr[] = {
   0,2
};
static const size_t PM1_B0_6_colIdx[] = {
   0,3
};
static const double PM1_B0_6_data[] _ALIGN = {
   0.0079151764909425968,0.0079151764909425968
};
static const size_t PM1_B1_6_rowPtr[] = {
   0,2
};
static const size_t PM1_B1_6_colIdx[] = {
   0,3
};
static const double PM1_B1_6_data[] _ALIGN = {
   0.00795750345379665595,0.00795750345379665595
};
static const size_t PM1_C_0_6_rowPtr[] = {
   0,0,1,2,2,3
};
static const size_t PM1_C_0_6_colIdx[] = {
   0,0,0
};
static const double PM1_C_0_6_data[] _ALIGN = {
   1.,1.,1.
};
static const size_t PM1_D_0_6_rowPtr[] = {
   0,0,0,0,0,0
};
static const size_t PM1_D_0_6_colIdx[] = {
   0
};
static const double PM1_D_0_6_data[] _ALIGN = {
   0
};
static void PM1_collision_6()
{
}
static size_t PM1_natPreComm_6()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   if (-x[0] >= 0)
   {
      return 0; /* 0 */
   }
   return 1; /* 6 */
}
static size_t PM1_natPostComm_6()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   return 1; /* 6 */
}
static size_t PM1_forcedComm_6()
{
   return 1;                                /* 6 */
}
static const size_t PM1_A_9_rowPtr[] = {
   0,1
};
static const size_t PM1_A_9_colIdx[] = {
   0
};
static const double PM1_A_9_data[] _ALIGN = {
   0.984127320055260713
};
static const size_t PM1_B0_9_rowPtr[] = {
   0,2
};
static const size_t PM1_B0_9_colIdx[] = {
   1,2
};
static const double PM1_B0_9_data[] _ALIGN = {
   -0.0079151764909425968,-0.0079151764909425968
};
static const size_t PM1_B1_9_rowPtr[] = {
   0,2
};
static const size_t PM1_B1_9_colIdx[] = {
   1,2
};
static const double PM1_B1_9_data[] _ALIGN = {
   -0.00795750345379665595,-0.00795750345379665595
};
static const size_t PM1_C_0_9_rowPtr[] = {
   0,1,1,1,2,3
};
static const size_t PM1_C_0_9_colIdx[] = {
   0,0,0
};
static const double PM1_C_0_9_data[] _ALIGN = {
   -1.,-1.,1.
};
static const size_t PM1_D_0_9_rowPtr[] = {
   0,0,0,0,0,0
};
static const size_t PM1_D_0_9_colIdx[] = {
   0
};
static const double PM1_D_0_9_data[] _ALIGN = {
   0
};
static void PM1_collision_9()
{
}
static size_t PM1_natPreComm_9()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   if (x[0] >= 0)
   {
      return 0; /* 0 */
   }
   return 2; /* 9 */
}
static size_t PM1_natPostComm_9()
{
   const double * const x = H_Bridge_and_Inductive_Load_PM1_x;
   const double * const u = H_Bridge_and_Inductive_Load_PM1_u;
   return 2; /* 9 */
}
static size_t PM1_forcedComm_9()
{
   return 2;                                /* 9 */
}
static const size_t * const PM1_A_rowPtr[] = {
   PM1_A_0_rowPtr,PM1_A_6_rowPtr,PM1_A_9_rowPtr
};
static const size_t * const PM1_A_colIdx[] = {
   PM1_A_0_colIdx,PM1_A_6_colIdx,PM1_A_9_colIdx
};
static const double * const H_Bridge_and_Inductive_Load_PM1_A_data[] = {
   PM1_A_0_data,PM1_A_6_data,PM1_A_9_data
};
static const size_t * const PM1_B0_rowPtr[] = {
   PM1_B0_0_rowPtr,PM1_B0_6_rowPtr,PM1_B0_9_rowPtr
};
static const size_t * const PM1_B0_colIdx[] = {
   PM1_B0_0_colIdx,PM1_B0_6_colIdx,PM1_B0_9_colIdx
};
static const double * const H_Bridge_and_Inductive_Load_PM1_B0_data[] = {
   PM1_B0_0_data,PM1_B0_6_data,PM1_B0_9_data
};
static const size_t * const PM1_B1_rowPtr[] = {
   PM1_B1_0_rowPtr,PM1_B1_6_rowPtr,PM1_B1_9_rowPtr
};
static const size_t * const PM1_B1_colIdx[] = {
   PM1_B1_0_colIdx,PM1_B1_6_colIdx,PM1_B1_9_colIdx
};
static const double * const H_Bridge_and_Inductive_Load_PM1_B1_data[] = {
   PM1_B1_0_data,PM1_B1_6_data,PM1_B1_9_data
};
static const size_t * const PM1_C_0_rowPtr[] = {
   PM1_C_0_0_rowPtr,PM1_C_0_6_rowPtr,PM1_C_0_9_rowPtr
};
static const size_t * const PM1_C_0_colIdx[] = {
   PM1_C_0_0_colIdx,PM1_C_0_6_colIdx,PM1_C_0_9_colIdx
};
static const double * const H_Bridge_and_Inductive_Load_PM1_C_0_data[] = {
   PM1_C_0_0_data,PM1_C_0_6_data,PM1_C_0_9_data
};
static const size_t * const PM1_D_0_rowPtr[] = {
   PM1_D_0_0_rowPtr,PM1_D_0_6_rowPtr,PM1_D_0_9_rowPtr
};
static const size_t * const PM1_D_0_colIdx[] = {
   PM1_D_0_0_colIdx,PM1_D_0_6_colIdx,PM1_D_0_9_colIdx
};
static const double * const H_Bridge_and_Inductive_Load_PM1_D_0_data[] = {
   PM1_D_0_0_data,PM1_D_0_6_data,PM1_D_0_9_data
};
static void (*const PM1_collision[3]) () = {
   PM1_collision_0,PM1_collision_6,PM1_collision_9
};
static size_t (*const PM1_natPreComm[3]) () = {
   PM1_natPreComm_0,PM1_natPreComm_6,PM1_natPreComm_9
};
static size_t (*const PM1_natPostComm[3]) () = {
   PM1_natPostComm_0,PM1_natPostComm_6,PM1_natPostComm_9
};
static size_t (*const PM1_forcedComm[3]) () = {
   PM1_forcedComm_0,PM1_forcedComm_6,PM1_forcedComm_9
};
static size_t H_Bridge_and_Inductive_Load_PM1_topologies[3]={
   0,6,9
};
static void H_Bridge_and_Inductive_Load_PM1_natComm()
{
   size_t oldTopo = H_Bridge_and_Inductive_Load_PM1_topoIdx;
   size_t midTopo = H_Bridge_and_Inductive_Load_PM1_topoIdx;
   size_t midToggleMask = 0;
   H_Bridge_and_Inductive_Load_PM1_topoIdx =
      PM1_natPreComm[H_Bridge_and_Inductive_Load_PM1_topoIdx]();
   midTopo = H_Bridge_and_Inductive_Load_PM1_topoIdx;
   H_Bridge_and_Inductive_Load_PM1_topoIdx =
      PM1_natPostComm[H_Bridge_and_Inductive_Load_PM1_topoIdx]();
   midToggleMask = H_Bridge_and_Inductive_Load_PM1_topologies[midTopo] ^
                   H_Bridge_and_Inductive_Load_PM1_topologies[oldTopo];
   if (midToggleMask)
   {
      if ((H_Bridge_and_Inductive_Load_PM1_topologies[
              H_Bridge_and_Inductive_Load_PM1_topoIdx] ^
           H_Bridge_and_Inductive_Load_PM1_topologies[midTopo]) &
          ~midToggleMask)
      {
         PM1_collision[H_Bridge_and_Inductive_Load_PM1_topoIdx]();
      }
      else
      {
         PM1_collision[midTopo]();
      }
   }
}
static void H_Bridge_and_Inductive_Load_PM1_forcedComm()
{
   H_Bridge_and_Inductive_Load_PM1_topoIdx =
      PM1_forcedComm[H_Bridge_and_Inductive_Load_PM1_topoIdx]();
}
static void H_Bridge_and_Inductive_Load_PM1_output_0()
{
   const double * _RESTRICT C_0_data = _ASSUME_ALIGNED(
                                                       H_Bridge_and_Inductive_Load_PM1_C_0_data[
                                                          H_Bridge_and_Inductive_Load_PM1_topoIdx]);
   const double * _RESTRICT D_0_data = _ASSUME_ALIGNED(
                                                       H_Bridge_and_Inductive_Load_PM1_D_0_data[
                                                          H_Bridge_and_Inductive_Load_PM1_topoIdx]);
   const size_t meterIdx[]={
      0,1,2,3,4
   };
   double y[5] _ALIGN;
   size_t i;
   for (i = 0; i < 5; ++i)
   {
      y[i] = 0;
      {
         const size_t *rowPtr =
            PM1_C_0_rowPtr[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         const size_t *colIdx =
            PM1_C_0_colIdx[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(y+
              i) += C_0_data[j]*H_Bridge_and_Inductive_Load_PM1_x[colIdx[j]];
      }
      {
         const size_t *rowPtr =
            PM1_D_0_rowPtr[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         const size_t *colIdx =
            PM1_D_0_colIdx[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(y+
              i) += D_0_data[j]*H_Bridge_and_Inductive_Load_PM1_u[colIdx[j]];
      }
   }
   for (i = 0; i < 5; ++i)
   {
      H_Bridge_and_Inductive_Load_PM1_y[meterIdx[i]] = y[i];
   }
}
static void H_Bridge_and_Inductive_Load_PM1_update(
                                                   const double * _RESTRICT aA_data, const double * _RESTRICT aB0_data, const double * _RESTRICT aB1_data,
                                                   double * _RESTRICT x)
{
   const double * _RESTRICT A_data = _ASSUME_ALIGNED(aA_data);
   const double * _RESTRICT B0_data = _ASSUME_ALIGNED(aB0_data);
   const double * _RESTRICT B1_data = _ASSUME_ALIGNED(aB1_data);
   const double * _RESTRICT prevX = H_Bridge_and_Inductive_Load_PM1_prevX;
   size_t i;
   for (i = 0; i < 1; ++i)
   {
      x[i] = 0;
      {
         const size_t *rowPtr =
            PM1_A_rowPtr[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         const size_t *colIdx =
            PM1_A_colIdx[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += A_data[j]*prevX[colIdx[j]];
      }
      {
         const size_t *rowPtr =
            PM1_B0_rowPtr[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         const size_t *colIdx =
            PM1_B0_colIdx[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+
              i) += B0_data[j]*
                    H_Bridge_and_Inductive_Load_PM1_prevU[colIdx[j]];

      }
      {
         const size_t *rowPtr =
            PM1_B1_rowPtr[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         const size_t *colIdx =
            PM1_B1_colIdx[H_Bridge_and_Inductive_Load_PM1_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += B1_data[j]*H_Bridge_and_Inductive_Load_PM1_u[colIdx[j]];

      }
   }
}
static char H_Bridge_and_Inductive_Load_first;
H_Bridge_and_Inductive_Load_BlockOutputs H_Bridge_and_Inductive_Load_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const H_Bridge_and_Inductive_Load_ExtModeSignals[] = {
   &H_Bridge_and_Inductive_Load_PM1_y[4],
   &H_Bridge_and_Inductive_Load_PM1_y[4]
};
#endif /* defined(EXTERNAL_MODE) */
H_Bridge_and_Inductive_Load_Parameters H_Bridge_and_Inductive_Load_P = {
   /* Parameter 'Value' of
    *  Constant : 'H-Bridge and Inductive Load/Constant'
    */
   24.
};
H_Bridge_and_Inductive_Load_ModelStates H_Bridge_and_Inductive_Load_X _ALIGN;
const char * H_Bridge_and_Inductive_Load_errorStatus;
const double H_Bridge_and_Inductive_Load_sampleTime = 3.99999999999999982e-6;
const char * const H_Bridge_and_Inductive_Load_checksum =
   "e00971e6942ca2d8ebacdc04ccdb51c7733e94f3";
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

void H_Bridge_and_Inductive_Load_initialize(double time)
{
   uint32_t H_Bridge_and_Inductive_Load_tickLo;
   int32_t H_Bridge_and_Inductive_Load_tickHi;
   double remainder;
   H_Bridge_and_Inductive_Load_errorStatus = NULL;
   H_Bridge_and_Inductive_Load_tickHi =
      floor(time/(4294967296.0*H_Bridge_and_Inductive_Load_sampleTime));
   remainder = time - H_Bridge_and_Inductive_Load_tickHi*4294967296.0*
               H_Bridge_and_Inductive_Load_sampleTime;
   H_Bridge_and_Inductive_Load_tickLo = floor(
                                              remainder/H_Bridge_and_Inductive_Load_sampleTime +
                                              .5);
   remainder -= H_Bridge_and_Inductive_Load_tickLo*
                H_Bridge_and_Inductive_Load_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      H_Bridge_and_Inductive_Load_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   H_Bridge_and_Inductive_Load_taskTick[0] = 0; /* [0.5, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(H_Bridge_and_Inductive_Load_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -H_Bridge_and_Inductive_Load_taskPeriod[i];
         delta %= H_Bridge_and_Inductive_Load_taskPeriod[i];
         if (H_Bridge_and_Inductive_Load_tickHi < 0)
         {
            delta = H_Bridge_and_Inductive_Load_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            H_Bridge_and_Inductive_Load_taskTick[i] =
               (H_Bridge_and_Inductive_Load_taskTick[i] +
                delta) % H_Bridge_and_Inductive_Load_taskPeriod[i];
         }
         H_Bridge_and_Inductive_Load_taskTick[i] =
            (H_Bridge_and_Inductive_Load_taskTick[i] +
             H_Bridge_and_Inductive_Load_tickLo %
             H_Bridge_and_Inductive_Load_taskPeriod[i]) %
            H_Bridge_and_Inductive_Load_taskPeriod[i];
      }
   }

   /* Target pre-initialization */
   setAnalogInputVoltage(0);
   setupDACs(0);
   setDigitalOutVoltage(0);
   initDigitalOut();
   initPWMCapture();
   plxSetMaxNumConsecutiveOverruns(5);
   setupSFPSyncMaster(0, 0, 0, 0);
   setupSFPSyncSlave(0, 0, 0);
   plxSetupAnalogSampling(1, 0, 3.99999999999999982e-06);


   /* Initialization for PWM Capture : 'H-Bridge and Inductive Load/Switch Signals' */
   setupPWMCaptureChannel(0,1);
   setupPWMCaptureChannel(1,1);
   setupPWMCaptureChannel(2,1);
   setupPWMCaptureChannel(3,1);

   /* Initialization for Subsystem : 'H-Bridge and Inductive Load' */
   H_Bridge_and_Inductive_Load_PM0_topoIdx = 0;

   /* Initialization for Subsystem : 'H-Bridge and Inductive Load' */
   H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_s[0] = 0;
   H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_s[1] = 0;
   H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_s[2] = 0;
   H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_s[3] = 0;
   H_Bridge_and_Inductive_Load_PM1_topoIdx = 0;
   H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_x = 0;
   H_Bridge_and_Inductive_Load_PM1_x =
      &H_Bridge_and_Inductive_Load_X.H_BridgeAndInductiveLoad_PM1_x;

   /* Initialization for Analog Out : 'H-Bridge and Inductive Load/Io'' */
   setupAnalogOut(12, -7.000000000e-02f, 1.650000000e+00f, 0.000000000e+00,
                  3.300000000e+00);

   /* Initialization for Analog Out : 'H-Bridge and Inductive Load/Vdc'' */
   setupAnalogOut(11, 7.448872966e-02f, 0.000000000e+00f, 0.000000000e+00,
                  3.300000000e+00);

   /* Initialization for Delay : 'H-Bridge and Inductive Load/Delay1' */
   H_Bridge_and_Inductive_Load_X.Delay1 = 0.;

   /* Initialization for Digital Out : 'H-Bridge and Inductive Load/LED 31: Blinking' */
   setupDigitalOut(31, DO_GPIO, DO_NINV);

   /* Initialization for Digital Out : 'H-Bridge and Inductive Load/LED 28: Switching Enabled' */
   setupDigitalOut(28, DO_GPIO, DO_NINV);

   /* Initialization for Analog Out : 'H-Bridge and Inductive Load/AOUT 4' */
   setupAnalogOut(4, 7.448872966e-02f, 0.000000000e+00f, 0.000000000e+00,
                  3.300000000e+00);

   /* Initialization for Digital Out : 'H-Bridge and Inductive Load/Enable DCDC (MCU)' */
   setupDigitalOut(4, DO_GPIO, DO_NINV);
   H_Bridge_and_Inductive_Load_first = 1;
}

void H_Bridge_and_Inductive_Load_step()
{
   if (H_Bridge_and_Inductive_Load_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         H_Bridge_and_Inductive_Load_taskHit[i] =
            (H_Bridge_and_Inductive_Load_taskTick[i] == 0);
      }
   }

   /* Signal Switch : 'H-Bridge and Inductive Load/GD/Switch'
    * incorporates
    *  Digital In : 'H-Bridge and Inductive Load/Disable Switching'
    */
   H_Bridge_and_Inductive_Load_B.Switch = (getDigitalIn(22)) > 0.;

   /* Signal Switch : 'H-Bridge and Inductive Load/GD/Switch'
    * incorporates
    *  Constant : 'H-Bridge and Inductive Load/GD/Constant2'
    *  PWM Capture : 'H-Bridge and Inductive Load/Switch Signals'
    */
   H_Bridge_and_Inductive_Load_B.Switch_i1[0] =
      H_Bridge_and_Inductive_Load_B.Switch ? 0. : (getDigitalInAveraged(0));
   H_Bridge_and_Inductive_Load_B.Switch_i1[1] =
      H_Bridge_and_Inductive_Load_B.Switch ? 0. : (getDigitalInAveraged(1));
   H_Bridge_and_Inductive_Load_B.Switch_i1[2] =
      H_Bridge_and_Inductive_Load_B.Switch ? 0. : (getDigitalInAveraged(2));
   H_Bridge_and_Inductive_Load_B.Switch_i1[3] =
      H_Bridge_and_Inductive_Load_B.Switch ? 0. : (getDigitalInAveraged(3));

   /* Offset : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Offset' */
   H_Bridge_and_Inductive_Load_B.Offset = -1. +
                                          H_Bridge_and_Inductive_Load_B.
                                          Switch_i1[3];

   /* Electrical model */


   /* Electrical model input */
   /* Voltage Source (Controlled) : 'H-Bridge and Inductive Load/V'
    * incorporates
    *  Constant : 'H-Bridge and Inductive Load/Constant'
    */
   H_Bridge_and_Inductive_Load_PM0_u[0]=
      H_Bridge_and_Inductive_Load_P.Constant_Value;
   /* End of electrical model input */


   /* Voltmeter : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/v_dc' */
   H_Bridge_and_Inductive_Load_B.v_dc = 1.*
                                        H_Bridge_and_Inductive_Load_PM0_u[0];

   /* Voltmeter : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/v_dc' */
   H_Bridge_and_Inductive_Load_B.v_dc_1 = 1.*
                                          H_Bridge_and_Inductive_Load_PM0_u[0];
   /* End of electrical model */
   /* Offset : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Offset' */
   H_Bridge_and_Inductive_Load_B.Offset_1 = -1. +
                                            H_Bridge_and_Inductive_Load_B.
                                            Switch_i1[1];

   /* Electrical model */
   if (!H_Bridge_and_Inductive_Load_first)
   {
      memcpy(H_Bridge_and_Inductive_Load_PM1_prevX,
             H_Bridge_and_Inductive_Load_PM1_x,1*sizeof(double));
      H_Bridge_and_Inductive_Load_PM1_update(
                                             H_Bridge_and_Inductive_Load_PM1_A_data[
                                                H_Bridge_and_Inductive_Load_PM1_topoIdx],
                                             H_Bridge_and_Inductive_Load_PM1_B0_data[
                                                H_Bridge_and_Inductive_Load_PM1_topoIdx],
                                             H_Bridge_and_Inductive_Load_PM1_B1_data[
                                                H_Bridge_and_Inductive_Load_PM1_topoIdx],
                                             H_Bridge_and_Inductive_Load_PM1_x);
   }


   /* Electrical model input */
   /* Voltage Source (Controlled) : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/V2'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Product3'
    */
   H_Bridge_and_Inductive_Load_PM1_u[0]=H_Bridge_and_Inductive_Load_B.v_dc_1 *
                                         H_Bridge_and_Inductive_Load_B.
                                         Switch_i1[0];
   /* Voltage Source (Controlled) : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/V1'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Product1'
    */
   H_Bridge_and_Inductive_Load_PM1_u[1]=
      H_Bridge_and_Inductive_Load_B.Offset_1 *
      H_Bridge_and_Inductive_Load_B.v_dc_1;
   /* Voltage Source (Controlled) : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/V2'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Product3'
    */
   H_Bridge_and_Inductive_Load_PM1_u[2]=H_Bridge_and_Inductive_Load_B.v_dc *
                                         H_Bridge_and_Inductive_Load_B.
                                         Switch_i1[2];
   /* Voltage Source (Controlled) : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/V1'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Product1'
    */
   H_Bridge_and_Inductive_Load_PM1_u[3]=H_Bridge_and_Inductive_Load_B.Offset *
                                         H_Bridge_and_Inductive_Load_B.v_dc;
   /* End of electrical model input */


   /* Commutation */
   H_Bridge_and_Inductive_Load_PM1_natComm();
   H_Bridge_and_Inductive_Load_PM1_forcedComm();

   /* Electrical model output */
   H_Bridge_and_Inductive_Load_PM1_output_0();
   /* End of electrical model output */

   /* End of electrical model */

   /* Analog Out : 'H-Bridge and Inductive Load/Io''
    * incorporates
    *  Ammeter : 'H-Bridge and Inductive Load/Am1'
    */
   setAnalogOut(12, H_Bridge_and_Inductive_Load_PM1_y[4]);

   /* Analog Out : 'H-Bridge and Inductive Load/Vdc''
    * incorporates
    *  Voltmeter : 'H-Bridge and Inductive Load/Vm1'
    */
   setAnalogOut(11, 1.*H_Bridge_and_Inductive_Load_PM0_u[0]);
   if (H_Bridge_and_Inductive_Load_taskHit[0])
   {
      /* Delay : 'H-Bridge and Inductive Load/Delay1' */
      H_Bridge_and_Inductive_Load_B.Delay1 =
         H_Bridge_and_Inductive_Load_X.Delay1;

      /* Logical Operator : 'H-Bridge and Inductive Load/Logical\nOperator1' */
      H_Bridge_and_Inductive_Load_B.LogicalOperator1 =
         !H_Bridge_and_Inductive_Load_B.Delay1;
   }

   /* Digital Out : 'H-Bridge and Inductive Load/LED 31: Blinking' */
   writeDigitalOut(31, H_Bridge_and_Inductive_Load_B.LogicalOperator1);

   /* Digital Out : 'H-Bridge and Inductive Load/LED 28: Switching Enabled'
    * incorporates
    *  Logical Operator : 'H-Bridge and Inductive Load/Logical\nOperator2'
    *  Digital In : 'H-Bridge and Inductive Load/Disable Switching'
    */
   writeDigitalOut(28, !(getDigitalIn(22)));

   /* Analog Out : 'H-Bridge and Inductive Load/AOUT 4'
    * incorporates
    *  Ammeter : 'H-Bridge and Inductive Load/Am1'
    */
   setAnalogOut(4, H_Bridge_and_Inductive_Load_PM1_y[4]);

   /* Digital Out : 'H-Bridge and Inductive Load/Enable DCDC (MCU)'
    * incorporates
    *  Digital In : 'H-Bridge and Inductive Load/Switch 28: Enable DCDC'
    */
   writeDigitalOut(4, getDigitalIn(28));
   H_Bridge_and_Inductive_Load_first = 0;
   if (H_Bridge_and_Inductive_Load_errorStatus)
   {
      return;
   }

   /* Update for Subsystem : 'H-Bridge and Inductive Load' */


   /* Electrical model input */
   /* Current Source (Controlled) : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/i_dc'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Product2'
    *  Ammeter : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Am1'
    *  Product : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Product4'
    *  Ammeter : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Am2'
    *  Sum : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Sum'
    */
   H_Bridge_and_Inductive_Load_PM0_u[1]=
      (H_Bridge_and_Inductive_Load_B.Offset_1 *
       H_Bridge_and_Inductive_Load_PM1_y[0]) +
      (H_Bridge_and_Inductive_Load_B.Switch_i1[0] *
       H_Bridge_and_Inductive_Load_PM1_y[1]);
   /* Current Source (Controlled) : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/i_dc'
    * incorporates
    *  Product : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Product2'
    *  Ammeter : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Am1'
    *  Product : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Product4'
    *  Ammeter : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Am2'
    *  Sum : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Sum'
    */
   H_Bridge_and_Inductive_Load_PM0_u[2]=
      (H_Bridge_and_Inductive_Load_B.Offset *
       H_Bridge_and_Inductive_Load_PM1_y[2]) +
      (H_Bridge_and_Inductive_Load_B.Switch_i1[2] *
       H_Bridge_and_Inductive_Load_PM1_y[3]);
   /* End of electrical model input */
   memcpy(H_Bridge_and_Inductive_Load_PM0_prevU,
          H_Bridge_and_Inductive_Load_PM0_u,3*sizeof(double));

   /* Update for Subsystem : 'H-Bridge and Inductive Load' */
   memcpy(H_Bridge_and_Inductive_Load_PM1_prevU,
          H_Bridge_and_Inductive_Load_PM1_u,4*sizeof(double));

   /* Update for Assertion : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Assertion/Assert/Assertion'
    * incorporates
    *  Compare to Constant : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Assertion/Assert/Relational\nOperator\n(Constant)'
    *  Sum : 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Assertion/Assert/Sum1'
    */
   if (!((H_Bridge_and_Inductive_Load_B.Switch_i1[1] +
          H_Bridge_and_Inductive_Load_B.Switch_i1[0]) < 1.00000099999999992))
   {
      H_Bridge_and_Inductive_Load_errorStatus =
         "Assertion failed in 'H-Bridge and Inductive Load/HB1/Sub-cycle average/Assertion/Assert/Assertion': Half-bridge shoot-through.";
   }

   /* Update for Assertion : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Assertion/Assert/Assertion'
    * incorporates
    *  Compare to Constant : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Assertion/Assert/Relational\nOperator\n(Constant)'
    *  Sum : 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Assertion/Assert/Sum1'
    */
   if (!((H_Bridge_and_Inductive_Load_B.Switch_i1[3] +
          H_Bridge_and_Inductive_Load_B.Switch_i1[2]) < 1.00000099999999992))
   {
      H_Bridge_and_Inductive_Load_errorStatus =
         "Assertion failed in 'H-Bridge and Inductive Load/HB2/Sub-cycle average/Assertion/Assert/Assertion': Half-bridge shoot-through.";
   }
   if (H_Bridge_and_Inductive_Load_taskHit[0])
   {
      /* Update for Delay : 'H-Bridge and Inductive Load/Delay1' */
      H_Bridge_and_Inductive_Load_X.Delay1 =
         H_Bridge_and_Inductive_Load_B.LogicalOperator1;
   }

   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         H_Bridge_and_Inductive_Load_taskTick[i]++;
         if (H_Bridge_and_Inductive_Load_taskTick[i] >=
             H_Bridge_and_Inductive_Load_taskPeriod[i])
         {
            H_Bridge_and_Inductive_Load_taskTick[i] = 0;
         }
      }
   }
}

void H_Bridge_and_Inductive_Load_terminate()
{
}
