/*
 * Header file for: ArduinoTest/Blink
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 18 Jul 2018 09:14:56
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
   bool Delay1;                     /* Blink/Delay1 */
} Blink_ModelStates;
extern Blink_ModelStates Blink_X;


/* Block outputs */
typedef struct
{
   bool Delay1;                     /* Blink/Delay1 */
   bool LogicalOperator1;           /* Blink/Logical Operator1 */
} Blink_BlockOutputs;
extern Blink_BlockOutputs Blink_B;

/* Entry point functions */
void Blink_initialize(double time);
void Blink_step(void);
void Blink_terminate(void);

#endif /* PLECS_HEADER_Blink_h_ */
