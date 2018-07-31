#ifndef _setup_H_
#define _setup_H_

//add your includes for the project Blinkpt2 here
#include "Arduino.h"
#include "settings.h"
#include <stdbool.h>

//other definitions
#define SAMPLE_TIME 0.001
#define prescaler 1
#define count_V 249
#define digitalPins 5
#define MINIMUM_SAMPLE 4.06e-06
#define MAXIMUM_SAMPLE 1.04864
#define System Clock 16000000

#define start_time 0
#define Base_Step Blink_step()
#define Base_Init Blink_initialize(start_time)

#define Timer_RegisterA TCCR0A
#define Timer_RegisterB TCCR0B
#define Timer_Counter   TCNT0
#define Timer_RegisterOCR_A OCR0A
#define Timer_RegisterOCR_B OCR0B
#define Timer_RegisterMask TIMSK0
#define Timer_ISR TIMER0_COMPA_vect

extern void Blink_step();
extern void Blink_initialize(double time);
extern void Blink_terminate();



//add your function definitions for the project Blinkpt2 here
bool configDout(int channel, byte pin);
bool configDin(int channel, byte pin);
int getDin(int channel);
void setDout(int channel, int state);
void config_interrupt(void);
void set_prescale(void);




//Do not add code below this line
#endif /* _Blinkpt2_H_ */
