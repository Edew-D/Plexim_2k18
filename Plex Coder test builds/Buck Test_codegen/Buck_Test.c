/*
 * Implementation file for: Buck Test
 * Generated with         : PLECS 4.2.0-DEV
 * Generated on           : 6 Jul 2018 10:19:07
 */
#include "Buck_Test.h"
#ifndef PLECS_HEADER_Buck_Test_h_
#error The wrong header file "Buck_Test.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_Buck_Test_h_ */
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
#include "DigitalOut.h"
#include "hw_wrapper.h"
#include "DigitalIn.h"
#include "AnalogOut.h"
#include "SFP.h"
#include "HIL_Framework.h"
#include "DataCapture.h"
#include "DataCaptureDefs.h"
#include "ProgrammableValue.h"
#include "ProgrammableValueDefs.h"
#define PLECSRunTimeError(msg) Buck_Test_errorStatus = msg
static const uint32_t Buck_Test_taskPeriod[1]= {
   /* [0.5, 0] */
   500
};
static uint32_t Buck_Test_taskTick[1];
static char Buck_Test_taskHit[1];
static uint32_t Buck_Test_D_uint32_t[1];
static double * _RESTRICT Buck_Test_PM0_x;
static double Buck_Test_PM0_tmpX[2] _ALIGN;
static double Buck_Test_PM0_prevX[2] _ALIGN;
static double Buck_Test_PM0_u[1] _ALIGN;
static double Buck_Test_PM0_prevU[1] _ALIGN;
static double Buck_Test_PM0_y[2] _ALIGN;
static double Buck_Test_PM0_gateSignalBuffer[1] _ALIGN;
static size_t Buck_Test_PM0_topoIdx;
static char Buck_Test_PM0_withDiracs;
static const size_t PM0_A_0_rowPtr[] = {
   0,0,1
};
static const size_t PM0_A_0_colIdx[] = {
   1
};
static const double PM0_A_0_data[] _ALIGN = {
   0.102357704724256926
};
static const size_t PM0_B0_0_rowPtr[] = {
   0,0,0
};
static const size_t PM0_B0_0_colIdx[] = {
   0
};
static const double PM0_B0_0_data[] _ALIGN = {
   0
};
static const size_t PM0_B1_0_rowPtr[] = {
   0,0,0
};
static const size_t PM0_B1_0_colIdx[] = {
   0
};
static const double PM0_B1_0_data[] _ALIGN = {
   0
};
static void PM0_collision_0()
{
   double * _RESTRICT x = Buck_Test_PM0_x;
   x[0] = 0.;
}
static size_t PM0_natPreComm_0()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (-x[1] > 0)
   {
      return 2; /* 2 */
   }
   return 0; /* 0 */
}
static size_t PM0_natPostComm_0()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (-x[1] > 0)
   {
      return 2; /* 2 */
   }
   return 0; /* 0 */
}
static size_t PM0_forcedComm_0()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (!Buck_Test_PM0_gateSignalBuffer[0])
   {
      return 0; /* 0 */
   }
   else
   {
      if (u[0] >= 0)
      {
         return 1; /* 1 */
      }
   }
   Buck_Test_errorStatus =
      "Illegal transition conditions in forced commutation for topology 0";
   return 0; /* 0 */
}
static const size_t PM0_A_1_rowPtr[] = {
   0,2,4
};
static const size_t PM0_A_1_colIdx[] = {
   0,1,0,1
};
static const double PM0_A_1_data[] _ALIGN = {
   0.952204379397085798,-0.015359644294706782,1.74541412439849775,
   0.0794973171978368837
};
static const size_t PM0_B0_1_rowPtr[] = {
   0,1,2
};
static const size_t PM0_B0_1_colIdx[] = {
   0,0
};
static const double PM0_B0_1_data[] _ALIGN = {
   0.0194606005155715175,0.0292319855070117401
};
static const size_t PM0_B1_1_rowPtr[] = {
   0,1,2
};
static const size_t PM0_B1_1_colIdx[] = {
   0,0
};
static const double PM0_B1_1_data[] _ALIGN = {
   0.0197968540805923826,0.0185636350959024962
};
static void PM0_collision_1()
{
}
static size_t PM0_natPreComm_1()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   return 1; /* 1 */
}
static size_t PM0_natPostComm_1()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   return 1; /* 1 */
}
static size_t PM0_forcedComm_1()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (Buck_Test_PM0_gateSignalBuffer[0])
   {
      return 1; /* 1 */
   }
   else
   {
      if (x[0] > 0)
      {
         return 2; /* 2 */
      }
   }
   Buck_Test_errorStatus =
      "Illegal transition conditions in forced commutation for topology 1";
   return 1; /* 1 */
}
static const size_t PM0_A_2_rowPtr[] = {
   0,2,4
};
static const size_t PM0_A_2_colIdx[] = {
   0,1,0,1
};
static const double PM0_A_2_data[] _ALIGN = {
   0.952204379397085798,-0.015359644294706782,1.74541412439849775,
   0.0794973171978368837
};
static const size_t PM0_B0_2_rowPtr[] = {
   0,0,0
};
static const size_t PM0_B0_2_colIdx[] = {
   0
};
static const double PM0_B0_2_data[] _ALIGN = {
   0
};
static const size_t PM0_B1_2_rowPtr[] = {
   0,0,0
};
static const size_t PM0_B1_2_colIdx[] = {
   0
};
static const double PM0_B1_2_data[] _ALIGN = {
   0
};
static void PM0_collision_2()
{
}
static size_t PM0_natPreComm_2()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (-x[0] >= 0)
   {
      return 0; /* 0 */
   }
   return 2; /* 2 */
}
static size_t PM0_natPostComm_2()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   return 2; /* 2 */
}
static size_t PM0_forcedComm_2()
{
   const double * const x = Buck_Test_PM0_x;
   const double * const u = Buck_Test_PM0_u;
   if (!Buck_Test_PM0_gateSignalBuffer[0])
   {
      return 2; /* 2 */
   }
   else
   {
      if (u[0] >= 0)
      {
         return 1; /* 1 */
      }
   }
   Buck_Test_errorStatus =
      "Illegal transition conditions in forced commutation for topology 2";
   return 2; /* 2 */
}
static const size_t * const PM0_A_rowPtr[] = {
   PM0_A_0_rowPtr,PM0_A_1_rowPtr,PM0_A_2_rowPtr
};
static const size_t * const PM0_A_colIdx[] = {
   PM0_A_0_colIdx,PM0_A_1_colIdx,PM0_A_2_colIdx
};
static const double * const Buck_Test_PM0_A_data[] = {
   PM0_A_0_data,PM0_A_1_data,PM0_A_2_data
};
static const size_t * const PM0_B0_rowPtr[] = {
   PM0_B0_0_rowPtr,PM0_B0_1_rowPtr,PM0_B0_2_rowPtr
};
static const size_t * const PM0_B0_colIdx[] = {
   PM0_B0_0_colIdx,PM0_B0_1_colIdx,PM0_B0_2_colIdx
};
static const double * const Buck_Test_PM0_B0_data[] = {
   PM0_B0_0_data,PM0_B0_1_data,PM0_B0_2_data
};
static const size_t * const PM0_B1_rowPtr[] = {
   PM0_B1_0_rowPtr,PM0_B1_1_rowPtr,PM0_B1_2_rowPtr
};
static const size_t * const PM0_B1_colIdx[] = {
   PM0_B1_0_colIdx,PM0_B1_1_colIdx,PM0_B1_2_colIdx
};
static const double * const Buck_Test_PM0_B1_data[] = {
   PM0_B1_0_data,PM0_B1_1_data,PM0_B1_2_data
};
static void (*const PM0_collision[3]) () = {
   PM0_collision_0,PM0_collision_1,PM0_collision_2
};
static size_t (*const PM0_natPreComm[3]) () = {
   PM0_natPreComm_0,PM0_natPreComm_1,PM0_natPreComm_2
};
static size_t (*const PM0_natPostComm[3]) () = {
   PM0_natPostComm_0,PM0_natPostComm_1,PM0_natPostComm_2
};
static size_t (*const PM0_forcedComm[3]) () = {
   PM0_forcedComm_0,PM0_forcedComm_1,PM0_forcedComm_2
};
static size_t Buck_Test_PM0_topologies[3]={
   0,1,2
};
static void Buck_Test_PM0_natComm()
{
   uint32_t oldTopo = Buck_Test_PM0_topoIdx;
   Buck_Test_PM0_topoIdx = PM0_natPreComm[Buck_Test_PM0_topoIdx]();
   Buck_Test_PM0_topoIdx = PM0_natPostComm[Buck_Test_PM0_topoIdx]();
   if (Buck_Test_PM0_topoIdx != oldTopo)
   {
      PM0_collision[Buck_Test_PM0_topoIdx]();
   }
}
static void Buck_Test_PM0_forcedComm()
{
   Buck_Test_PM0_topoIdx = PM0_forcedComm[Buck_Test_PM0_topoIdx]();
}
static void Buck_Test_PM0_update(const double * _RESTRICT aA_data,
                                 const double * _RESTRICT aB0_data,
                                 const double * _RESTRICT aB1_data,
                                 double * _RESTRICT x)
{
   const double * _RESTRICT A_data = _ASSUME_ALIGNED(aA_data);
   const double * _RESTRICT B0_data = _ASSUME_ALIGNED(aB0_data);
   const double * _RESTRICT B1_data = _ASSUME_ALIGNED(aB1_data);
   const double * _RESTRICT prevX = Buck_Test_PM0_prevX;
   size_t i;
   for (i = 0; i < 2; ++i)
   {
      x[i] = 0;
      {
         const size_t *rowPtr = PM0_A_rowPtr[Buck_Test_PM0_topoIdx];
         const size_t *colIdx = PM0_A_colIdx[Buck_Test_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += A_data[j]*prevX[colIdx[j]];
      }
      {
         const size_t *rowPtr = PM0_B0_rowPtr[Buck_Test_PM0_topoIdx];
         const size_t *colIdx = PM0_B0_colIdx[Buck_Test_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += B0_data[j]*Buck_Test_PM0_prevU[colIdx[j]];
      }
      {
         const size_t *rowPtr = PM0_B1_rowPtr[Buck_Test_PM0_topoIdx];
         const size_t *colIdx = PM0_B1_colIdx[Buck_Test_PM0_topoIdx];
         size_t j;
         for (j = rowPtr[i]; j < rowPtr[i+1]; ++j)
            *(x+i) += B1_data[j]*Buck_Test_PM0_u[colIdx[j]];
      }
   }
}
static char Buck_Test_first;
Buck_Test_BlockOutputs Buck_Test_B;
#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
const double * const Buck_Test_ExtModeSignals[] = {
   &Buck_Test_B.BuckTest,
   &Buck_Test_B.Vm1
};
#endif /* defined(EXTERNAL_MODE) */
Buck_Test_ModelStates Buck_Test_X _ALIGN;
const char * Buck_Test_errorStatus;
const double Buck_Test_sampleTime = 0.00100000000000000002;
const char * const Buck_Test_checksum =
   "35dad6aef0d6576da657b801d139d30a77aee6b9";
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

void Buck_Test_initialize(double time)
{
   uint32_t Buck_Test_tickLo;
   int32_t Buck_Test_tickHi;
   double remainder;
   Buck_Test_errorStatus = NULL;
   Buck_Test_tickHi = floor(time/(4294967296.0*Buck_Test_sampleTime));
   remainder = time - Buck_Test_tickHi*4294967296.0*Buck_Test_sampleTime;
   Buck_Test_tickLo = floor(remainder/Buck_Test_sampleTime + .5);
   remainder -= Buck_Test_tickLo*Buck_Test_sampleTime;
   if (fabs(remainder) > 1e-6*fabs(time))
   {
      Buck_Test_errorStatus =
         "Start time must be an integer multiple of the base sample time.";
   }
   /* Initialize sub-task tick counters */
   Buck_Test_taskTick[0] = 0;       /* [0.5, 0] */


   /* Offset sub-task tick counters */
   {
      uint32_t i, n, N, delta;
      N = abs(Buck_Test_tickHi);
      for (i = 0; i < 1; ++i)
      {
         delta = -Buck_Test_taskPeriod[i];
         delta %= Buck_Test_taskPeriod[i];
         if (Buck_Test_tickHi < 0)
         {
            delta = Buck_Test_taskPeriod[i] - delta;
         }
         for (n = 0; n < N; ++n)
         {
            Buck_Test_taskTick[i] =
               (Buck_Test_taskTick[i] + delta) % Buck_Test_taskPeriod[i];
         }
         Buck_Test_taskTick[i] =
            (Buck_Test_taskTick[i] + Buck_Test_tickLo %
          Buck_Test_taskPeriod[i]) % Buck_Test_taskPeriod[i];
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
   plxSetupAnalogSampling(1, 0, 1.00000000000000002e-03);


   /* Initialization for Pulse Generator : 'Buck Test/Pulse\nGenerator' */
   Buck_Test_D_uint32_t[0] = (((int32_t) floor(time/0.5+.5) - 0) % 2 + 2) % 2;

   /* Initialization for Subsystem : 'Buck Test' */
   Buck_Test_X.BuckTest_PM0_s[0] = 1;
   Buck_Test_X.BuckTest_PM0_s[1] = 0;
   Buck_Test_PM0_topoIdx = 1;
   Buck_Test_X.BuckTest_PM0_x[0] = 0;
   Buck_Test_X.BuckTest_PM0_x[1] = 0;
   Buck_Test_PM0_x = &Buck_Test_X.BuckTest_PM0_x[0];

   /* Initialization for Digital Out : 'Buck Test/Digital Out1' */
   setupDigitalOut(31, DO_GPIO, DO_NINV);
   Buck_Test_first = 1;
}

void Buck_Test_step()
{
   if (Buck_Test_errorStatus)
   {
      return;
   }
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Buck_Test_taskHit[i] = (Buck_Test_taskTick[i] == 0);
      }
   }

   /* Subsystem : 'Buck Test' */
   Buck_Test_B.BuckTest = 0.;
   if (Buck_Test_taskHit[0])
   {
      /* Pulse Generator : 'Buck Test/Pulse\nGenerator' */
      Buck_Test_B.PulseGenerator = Buck_Test_D_uint32_t[0] < 1 ? 1. : 0.;
   }


   /* Electrical model */


   /* Electrical model input */
   /* Voltage Source (Controlled) : 'Buck Test/Sub/V'
    * incorporates
    *  Constant : 'Buck Test/Constant'
    */
   Buck_Test_PM0_u[0]=12.;
   /* End of electrical model input */
   if (!Buck_Test_first)
   {
      memcpy(Buck_Test_PM0_prevX,Buck_Test_PM0_x,2*sizeof(double));
      Buck_Test_PM0_update(Buck_Test_PM0_A_data[Buck_Test_PM0_topoIdx],
                           Buck_Test_PM0_B0_data[Buck_Test_PM0_topoIdx],
                           Buck_Test_PM0_B1_data[Buck_Test_PM0_topoIdx],
                           Buck_Test_PM0_x);
   }


   /* Commutation */
   Buck_Test_PM0_natComm();
   Buck_Test_PM0_gateSignalBuffer[0] = Buck_Test_B.PulseGenerator;
   Buck_Test_PM0_forcedComm();

   /* Voltmeter : 'Buck Test/Sub/Vm1' */
   Buck_Test_B.Vm1 = 1.*Buck_Test_PM0_x[1];
   /* End of electrical model */

   /* Digital Out : 'Buck Test/Digital Out1' */
   writeDigitalOut(31, Buck_Test_B.PulseGenerator);
   Buck_Test_first = 0;
   if (Buck_Test_errorStatus)
   {
      return;
   }
   if (Buck_Test_taskHit[0])
   {
      /* Update for Pulse Generator : 'Buck Test/Pulse\nGenerator' */
      Buck_Test_D_uint32_t[0] += 1;
      if (Buck_Test_D_uint32_t[0] > 1)
      {
         Buck_Test_D_uint32_t[0] = 0;
      }
   }
   /* Update for Subsystem : 'Buck Test' */
   memcpy(Buck_Test_PM0_prevU,Buck_Test_PM0_u,1*sizeof(double));
   /* Increment sub-task tick counters */
   {
      uint32_t i;
      for (i = 0; i < 1; ++i)
      {
         Buck_Test_taskTick[i]++;
         if (Buck_Test_taskTick[i] >= Buck_Test_taskPeriod[i])
         {
            Buck_Test_taskTick[i] = 0;
         }
      }
   }
}

void Buck_Test_terminate()
{
}
