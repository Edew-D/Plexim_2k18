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

typedef struct {
  volatile uint8_t *portAddr; //portAddr must be a pointer because PORTD cannot be assigned to a normal variable, so we use its address
  volatile uint8_t portMask;
} dRecord; //Create structure called dRecord that stores the pin's port(portAddr) and which indexes are on or off(portMask)

dRecord digiPin[16];

bool configDout(int channel, int pin) { //configures a digital pin as output

  if ((pin > 0) && (pin < 8)) {
    DDRB |= (1 << pin);
    digiPin[channel].portAddr = &PORTD;
    digiPin[channel].portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB |= (1 << (pin % 8));
    digiPin[channel].portAddr = &PORTB;
    digiPin[channel].portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}

bool configDin(int channel, int pin) { //Configures digital pin as Input

  if ((pin > 1) && (pin < 8)) {
    DDRD = (0 << pin);
    digiPin[channel].portAddr = &PIND;
    digiPin[channel].portMask = pin;
    //return &digiPin[channel];
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (0 << (pin % 8));
    digiPin[channel].portAddr = &PIND;
    digiPin[channel].portMask = (1 << (pin % 8));
    //return &digiPin[channel];
    return true;
  }
  else {
    return false;
  }
}

int getDin(int channel){ //Reads a digital pin and returns its state
	dRecord *rec = &digiPin[channel];

	if (*rec->portAddr & (1 << digiPin[channel].portMask)){
		return 1;
	}
	else{
		return 0;
	}

}


void setDout(int channel, int state) { //sets a digital pin as high or low based on passed state
  dRecord *pin;
  pin = &digiPin[channel];

  if (state == 1) {
    *(pin->portAddr) |= pin->portMask;
    return;
  }
  else {
	 *(pin->portAddr) ^= pin->portMask;
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
