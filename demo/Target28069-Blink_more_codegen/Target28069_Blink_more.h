/*
 * Header file for: Target28069-Blink_more
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 30 Jul 2018 08:56:01
 */
#ifndef PLECS_HEADER_Target28069_Blink_more_h_
#define PLECS_HEADER_Target28069_Blink_more_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Target28069_Blink_more_FloatType;

/* Model checksum */
extern const char * const Target28069_Blink_more_checksum;

/* Model error status */
extern const char * Target28069_Blink_more_errorStatus;


/* Model sample time */
extern const double Target28069_Blink_more_sampleTime;


/*
 * Model states */
typedef struct
{
   double Controls;                 /* Target28069-Blink_more/Controls */
   bool Delay1;                     /* Target28069-Blink_more/Controls/Delay1 */
} Target28069_Blink_more_ModelStates;
extern Target28069_Blink_more_ModelStates Target28069_Blink_more_X;


/* Block outputs */
typedef struct
{
   double Controls[7];              /* Target28069-Blink_more/Controls */
   bool Delay1;                     /* Target28069-Blink_more/Controls/Delay1 */
   bool LogicalOperator1;           /* Target28069-Blink_more/Controls/Logical Operator1 */
   double C_Script;                 /* Target28069-Blink_more/Controls/C-Script */
} Target28069_Blink_more_BlockOutputs;
extern Target28069_Blink_more_BlockOutputs Target28069_Blink_more_B;

/* Entry point functions */
void Target28069_Blink_more_initialize(double time);
void Target28069_Blink_more_step(void);
void Target28069_Blink_more_terminate(void);

#endif /* PLECS_HEADER_Target28069_Blink_more_h_ */
