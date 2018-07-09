/*
 * Header file for: Buck Test
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 6 Jul 2018 10:19:07
 */
#ifndef PLECS_HEADER_Buck_Test_h_
#define PLECS_HEADER_Buck_Test_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Buck_Test_FloatType;

/* Model checksum */
extern const char * const Buck_Test_checksum;

/* Model error status */
extern const char * Buck_Test_errorStatus;


/* Model sample time */
extern const double Buck_Test_sampleTime;


/*
 * Model states */
typedef struct
{
   double BuckTest_PM0_x[2];        /* Buck Test */
   double BuckTest_PM0_s[2];        /* Buck Test */
} Buck_Test_ModelStates;
extern Buck_Test_ModelStates Buck_Test_X;


/* Block outputs */
typedef struct
{
   double BuckTest;                 /* Buck Test */
   double PulseGenerator;           /* Buck Test/Pulse Generator */
   double Vm1;                      /* Buck Test/Sub/Vm1 */
} Buck_Test_BlockOutputs;
extern Buck_Test_BlockOutputs Buck_Test_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Buck_Test_NumExtModeSignals 2
extern const double * const Buck_Test_ExtModeSignals[];
/* Tunable parameters */
#define Buck_Test_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Buck_Test_initialize(double time);
void Buck_Test_step(void);
void Buck_Test_terminate(void);

#endif /* PLECS_HEADER_Buck_Test_h_ */
