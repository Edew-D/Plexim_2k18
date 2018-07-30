/*
 * Header file for: plecs test
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 26 Jul 2018 08:27:05
 */
#ifndef PLECS_HEADER_plecs_test_h_
#define PLECS_HEADER_plecs_test_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double plecs_test_FloatType;

/* Model checksum */
extern const char * const plecs_test_checksum;

/* Model error status */
extern const char * plecs_test_errorStatus;


/* Model sample time */
extern const double plecs_test_sampleTime;


/*
 * Model states */
typedef struct
{
} plecs_test_ModelStates;
extern plecs_test_ModelStates plecs_test_X;


/* External inputs */
typedef struct
{
   double DigitalIn2;               /* Digital In2 */
} plecs_test_ExternalInputs;
extern plecs_test_ExternalInputs plecs_test_U;


/* External outputs */
typedef struct
{
   double DigitalOut2;              /* Digital Out2 */
   double DigitalOut3;              /* Digital Out3 */
   double PWMOut_ePWM0_;            /* PWM Out (ePWM0) */
   double PWMOut_ePWM0_1;           /* PWM Out (ePWM0)1 */
} plecs_test_ExternalOutputs;
extern plecs_test_ExternalOutputs plecs_test_Y;


/* Entry point functions */
void plecs_test_initialize(double time);
void plecs_test_step(void);
void plecs_test_terminate(void);

#endif /* PLECS_HEADER_plecs_test_h_ */
