/*
 * Header file for: Buck_codegen/H-Bridge and Inductive Load
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 9 Jul 2018 11:47:43
 */
#ifndef PLECS_HEADER_H_Bridge_and_Inductive_Load_h_
#define PLECS_HEADER_H_Bridge_and_Inductive_Load_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double H_Bridge_and_Inductive_Load_FloatType;

/* Model checksum */
extern const char * const H_Bridge_and_Inductive_Load_checksum;

/* Model error status */
extern const char * H_Bridge_and_Inductive_Load_errorStatus;


/* Model sample time */
extern const double H_Bridge_and_Inductive_Load_sampleTime;


/*
 * Model states */
typedef struct
{
   double H_BridgeAndInductiveLoad_PM1_x; /* H-Bridge and Inductive Load */
   double H_BridgeAndInductiveLoad_PM1_s[4]; /* H-Bridge and Inductive Load */
   double Assertion;                /* H-Bridge and Inductive Load/HB1/Sub-cycle average/Assertion/Assert/Assertion */
   double Assertion_1;              /* H-Bridge and Inductive Load/HB2/Sub-cycle average/Assertion/Assert/Assertion */
   bool Delay1;                     /* H-Bridge and Inductive Load/Delay1 */
} H_Bridge_and_Inductive_Load_ModelStates;
extern H_Bridge_and_Inductive_Load_ModelStates H_Bridge_and_Inductive_Load_X;


/* Block outputs */
typedef struct
{
   bool Switch;                     /* H-Bridge and Inductive Load/GD/Switch */
   double Switch_i1[4];             /* H-Bridge and Inductive Load/GD/Switch */
   double Offset;                   /* H-Bridge and Inductive Load/HB2/Sub-cycle average/Offset */
   double v_dc;                     /* H-Bridge and Inductive Load/HB2/Sub-cycle average/v_dc */
   double v_dc_1;                   /* H-Bridge and Inductive Load/HB1/Sub-cycle average/v_dc */
   double Offset_1;                 /* H-Bridge and Inductive Load/HB1/Sub-cycle average/Offset */
   bool Delay1;                     /* H-Bridge and Inductive Load/Delay1 */
   bool LogicalOperator1;           /* H-Bridge and Inductive Load/Logical Operator1 */
} H_Bridge_and_Inductive_Load_BlockOutputs;
extern H_Bridge_and_Inductive_Load_BlockOutputs H_Bridge_and_Inductive_Load_B;

#if defined(EXTERNAL_MODE) && EXTERNAL_MODE
/* External mode signals */
#define H_Bridge_and_Inductive_Load_NumExtModeSignals 2
extern const double * const H_Bridge_and_Inductive_Load_ExtModeSignals[];
/* Tunable parameters */
#define H_Bridge_and_Inductive_Load_NumTunableParameters 1
#endif /* defined(EXTERNAL_MODE) */


/* Block parameters */
typedef struct
{
   /* Parameter 'Value' of
    *  Constant : 'H-Bridge and Inductive Load/Constant'
    */
   double Constant_Value;
} H_Bridge_and_Inductive_Load_Parameters;
extern H_Bridge_and_Inductive_Load_Parameters H_Bridge_and_Inductive_Load_P;

/* Entry point functions */
void H_Bridge_and_Inductive_Load_initialize(double time);
void H_Bridge_and_Inductive_Load_step(void);
void H_Bridge_and_Inductive_Load_terminate(void);

#endif /* PLECS_HEADER_H_Bridge_and_Inductive_Load_h_ */
