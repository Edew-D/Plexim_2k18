/*
 * Header file for: test2
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 26 Jul 2018 10:25:38
 */
#ifndef PLECS_HEADER_test2_h_
#define PLECS_HEADER_test2_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double test2_FloatType;

/* Model checksum */
extern const char * const test2_checksum;

/* Model error status */
extern const char * test2_errorStatus;


/* Model sample time */
extern const double test2_sampleTime;


/* Entry point functions */
void test2_initialize(double time);
void test2_step(void);
void test2_terminate(void);

#endif /* PLECS_HEADER_test2_h_ */
