/*
 * Header file for: ArduinoTest/Blink
 * Generated with : PLECS 4.2.0-DEV
 * Generated on   : 31 Jul 2018 08:49:46
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


/* Entry point functions */
void Blink_initialize(double time);
void Blink_step(void);
void Blink_terminate(void);

#endif /* PLECS_HEADER_Blink_h_ */