/*
 * Header file for: ArduinoTest
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 9 Jul 2018 14:24:49
 */
#ifndef PLECS_HEADER_ArduinoTest_h_
#define PLECS_HEADER_ArduinoTest_h_

#include <stdbool.h>
#include <stdint.h>

/* Model floating point type */
typedef double ArduinoTest_FloatType;

/* Model checksum */
extern const char * const ArduinoTest_checksum;

/* Model error status */
extern const char * ArduinoTest_errorStatus;


/* Model sample time */
extern const double ArduinoTest_sampleTime;


/* Entry point functions */
void ArduinoTest_initialize(double time);
void ArduinoTest_step(void);
void ArduinoTest_terminate(void);

#endif /* PLECS_HEADER_ArduinoTest_h_ */
