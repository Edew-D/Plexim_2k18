/*
 * Header file for: wave generator
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 6 Jul 2018 11:35:28
 */
#ifndef PLECS_HEADER_wave_generator_h_
#define PLECS_HEADER_wave_generator_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double wave_generator_FloatType;

/* Model checksum */
extern const char * const wave_generator_checksum;

/* Model error status */
extern const char * wave_generator_errorStatus;


/* Model sample time */
extern const double wave_generator_sampleTime;


/* Block outputs */
typedef struct
{
   double SineWave;                 /* wave generator/Sine Wave */
} wave_generator_BlockOutputs;
extern wave_generator_BlockOutputs wave_generator_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define wave_generator_NumExtModeSignals 1
extern const double * const wave_generator_ExtModeSignals[];
/* Tunable parameters */
#define wave_generator_NumTunableParameters 0
#endif /* defined(EXTERNAL_MODE) */


/* Entry point functions */
void wave_generator_initialize(double time);
void wave_generator_step(void);
void wave_generator_terminate(void);

#endif /* PLECS_HEADER_wave_generator_h_ */
