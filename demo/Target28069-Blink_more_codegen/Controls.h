/*
 * Header file for: Target28069-Blink_more/Controls
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 25 May 2018 10:10:15
 */
#ifndef PLECS_HEADER_Controls_h_
#define PLECS_HEADER_Controls_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Controls_FloatType;

/* Model checksum */
extern const char * const Controls_checksum;

/* Model error status */
extern const char * Controls_errorStatus;


/* Model sample time */
extern const double Controls_sampleTime;


/*
 * Model states */
typedef struct
{
   bool Delay1;                     /* Controls/Delay1 */
} Controls_ModelStates;
extern Controls_ModelStates Controls_X;


/* Block outputs */
typedef struct
{
   bool Delay1;                     /* Controls/Delay1 */
   bool LogicalOperator1;           /* Controls/Logical Operator1 */
   double C_Script;                 /* Controls/C-Script */
} Controls_BlockOutputs;
extern Controls_BlockOutputs Controls_B;

/* Entry point functions */
void Controls_initialize(double time);
void Controls_step(void);
void Controls_terminate(void);

#endif /* PLECS_HEADER_Controls_h_ */
