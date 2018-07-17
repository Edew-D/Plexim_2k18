/*
 * Header file for: ArduinoTest/Blink
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 17 Jul 2018 10:41:47
 */
#ifndef PLECS_HEADER_Blinktest_h_
#define PLECS_HEADER_Blinktest_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Blinktest_FloatType;

/* Model checksum */
extern const char * const Blinktest_checksum;

/* Model error status */
extern const char * Blinktest_errorStatus;


/* Model sample time */
extern const double Blinktest_sampleTime;


/*
 * Model states */
typedef struct
{
   bool Delay1;                     /* Blink/Delay1 */
} Blinktest_ModelStates;
extern Blinktest_ModelStates Blinktest_X;


/* Block outputs */
typedef struct
{
   bool Delay1;                     /* Blink/Delay1 */
   bool LogicalOperator1;           /* Blink/Logical Operator1 */
} Blinktest_BlockOutputs;
extern Blinktest_BlockOutputs Blinktest_B;

/* Entry point functions */
void Blinktest_initialize(double time);
void Blinktest_step(void);
void Blinktest_terminate(void);

#endif /* PLECS_HEADER_Blinktest_h_ */
