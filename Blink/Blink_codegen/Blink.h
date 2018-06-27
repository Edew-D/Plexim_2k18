/*
 * Header file for: Blink
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 25 Jun 2018 12:07:01
 */
#ifndef PLECS_HEADER_Blink_h_
#define PLECS_HEADER_Blink_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Blink_FloatType;

/* Model checksum */
extern const char * const Blink_checksum;

/* Model error status */
extern const char * Blink_errorStatus;


/* Model sample time */
extern const double Blink_sampleTime;


/*
 * Model states */
typedef struct
{
   double Delay;                    /* Blink/Delay */
} Blink_ModelStates;
extern Blink_ModelStates Blink_X;


/* Block outputs */
typedef struct
{
   double Delay;                    /* Blink/Delay */
   bool LogicalOperator;            /* Blink/Logical Operator */
} Blink_BlockOutputs;
extern Blink_BlockOutputs Blink_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define Blink_NumExtModeSignals 1
extern const double * const Blink_ExtModeSignals[];
/* Tunable parameters */
#define Blink_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void Blink_initialize(double time);
void Blink_step(void);
void Blink_terminate(void);

#endif /* PLECS_HEADER_Blink_h_ */
