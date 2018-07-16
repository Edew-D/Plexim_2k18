/*
 * Header file for: Buck_codegen/Controller
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 10 Jul 2018 09:37:10
 */
#ifndef PLECS_HEADER_Controller_h_
#define PLECS_HEADER_Controller_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double Controller_FloatType;

/* Model checksum */
extern const char * const Controller_checksum;

/* Model error status */
extern const char * Controller_errorStatus;


/* Model sample time */
extern const double Controller_sampleTime;


/*
 * Model states */
typedef struct
{
   bool Delay1;                     /* Controller/Delay1 */
} Controller_ModelStates;
extern Controller_ModelStates Controller_X;


/* Block outputs */
typedef struct
{
   bool Delay1;                     /* Controller/Delay1 */
   bool LogicalOperator1;           /* Controller/Logical Operator1 */
} Controller_BlockOutputs;
extern Controller_BlockOutputs Controller_B;

/* Entry point functions */
void Controller_initialize(double time);
void Controller_step(void);
void Controller_terminate(void);

#endif /* PLECS_HEADER_Controller_h_ */
