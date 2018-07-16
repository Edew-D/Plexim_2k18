/*
 * Header file for: Target28069-Blink
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 24 May 2018 11:23:35
 */
#ifndef PLECS_HEADER_Target28069_Blink_h_
#define PLECS_HEADER_Target28069_Blink_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Target28069_Blink_FloatType;

/* Model checksum */
extern const char * const Target28069_Blink_checksum;

/* Model error status */
extern const char * Target28069_Blink_errorStatus;


/* Model sample time */
extern const double Target28069_Blink_sampleTime;


/*
 * Model states */
typedef struct
{
} Target28069_Blink_ModelStates;
extern Target28069_Blink_ModelStates Target28069_Blink_X;


/* Entry point functions */
void Target28069_Blink_initialize(double time);
void Target28069_Blink_step(void);
void Target28069_Blink_terminate(void);

#endif /* PLECS_HEADER_Target28069_Blink_h_ */
