#ifndef _setup_H_
#define _setup_H_

//add your includes for the project Blinkpt2 here
#include "Arduino.h"
#include "settings.h"

//other definitions


//add your function definitions for the project Blinkpt2 here
bool configDout(int channel, byte pin);
bool configDin(int channel, byte pin);
int getDin(int channel);
void setDout(int channel, int state);
void config_interrupt(void);
void set_prescale(void);




//Do not add code below this line
#endif /* _Blinkpt2_H_ */
