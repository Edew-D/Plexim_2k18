/*
 * Header file for: switch
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 5 Jul 2018 11:07:22
 */
#ifndef PLECS_HEADER_switch_h_
#define PLECS_HEADER_switch_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double switch_FloatType;

/* Model checksum */
extern const char * const switch_checksum;

/* Model error status */
extern const char * switch_errorStatus;


/* Model sample time */
extern const double switch_sampleTime;


#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define switch_NumExtModeSignals 0
extern const double * const switch_ExtModeSignals[];
/* Tunable parameters */
#define switch_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void switch_initialize(double time);
void switch_step(void);
void switch_terminate(void);

#endif /* PLECS_HEADER_switch_h_ */
