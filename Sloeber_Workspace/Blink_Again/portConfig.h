/*
 * portConfig.h
 *
 *  Created on: Jun 28, 2018
 *      Author: wede
 */

//#define __ASSERT_USE_STDERR
//#include <assert.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>
#ifndef PORTCONFIG_H_
#define PORTCONFIG_H_
#include "setup.h"

typedef struct {
  volatile uint8_t *portAddr; //portAddr must be a pointer because PORT* is a pointer and cannot be assigned to a normal variable, so we use its address
  volatile uint8_t portMask;
  int pin_num;
} dRecord; //Create structure called dRecord that stores the pin's port(portAddr) and which indexes are on or off(portMask)

dRecord digiPin[16];

bool configDout(int channel, byte pin) { //configures a digital pin as output

  if ((pin > 0) && (pin < 8)) {
    DDRD |= (1 << (pin));
    digiPin[channel].portAddr = &PORTD;
    digiPin[channel].portMask = (1 << (pin));
    digiPin[channel].pin_num = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB |= (1 << (pin % 8));
    digiPin[channel].portAddr = &PORTB;
    digiPin[channel].portMask = (1 << (pin % 8));
    digiPin[channel].pin_num = pin;
    return true;
  }

  else {
    return false;
  }
}

bool configDin(int channel, byte pin) { //Configures digital pin as Input
  byte off = 1;

  if ((pin > 1) && (pin < 8)) {
	off = (off << pin);
    DDRD = DDRD & ~off;
    digiPin[channel].portAddr = &PIND;
    digiPin[channel].portMask = (1 << (pin));
    digiPin[channel].pin_num = pin;
    //return &digiPin[channel];
    return true;
  }

  else if ((pin > 7) && (pin < 14 )) {
	off = (off << (pin % 8));
    DDRB = DDRB & ~off;
    digiPin[channel].portAddr = &PINB;
    digiPin[channel].portMask = (1 << (pin % 8));
    digiPin[channel].pin_num = pin;
    //return &digiPin[channel];
    return true;
  }

  else {
    return false;
  }
}

int getDin(int channel){ //Reads a digital pin and returns its state
	  dRecord *pin = &digiPin[channel];
	  byte test_pin = *(pin->portAddr);

	  //byte test_pin = *(pin->portAddr);

	if (test_pin & digiPin[channel].portMask){
		//Serial.println("returning HIGH");
		return 1;
	}
	else{
		//Serial.println("Returning LOW");
		return 0;
	}

}


void setDout(int channel, int state) { //sets a digital pin as high or low based on passed state
  dRecord *pin;
  pin = &digiPin[channel];

  if (state == 1) {
    *(pin->portAddr) |= pin->portMask;
   // Serial.println("SetHIGH");
    return;
  }
  else {
	 *(pin->portAddr) &=  ~pin->portMask;
	// Serial.println("SetLOW");
    return;
  }


}

/*
void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp) {
    // transmit diagnostic informations through serial link.
    Serial.println(__func);
    Serial.println(__file);
    Serial.println(__lineno, DEC);
    Serial.println(__sexp);
    Serial.flush();
    // abort program execution.
    abort();
}*/





#endif /* PORTCONFIG_H_ */
