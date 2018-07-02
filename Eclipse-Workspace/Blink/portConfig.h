/*
 * portConfig.h
 *
 *  Created on: Jun 28, 2018
 *      Author: wede
 */

#ifndef PORTCONFIG_H_
#define PORTCONFIG_H_


typedef struct {
  volatile uint8_t *portAddr; //portAddr must be a pointer because PORTD cannot be assigned to a normal variable, so we use its address
  volatile uint8_t portMask;
} dRecord; //Create structure called dRecord that stores the pin's port(portAddr) and which indexes are on or off(portMask)

dRecord digiPin[16];

bool configDout(int channel, int pin) {

  if ((pin > 1) && (pin < 8)) {
    DDRB = (1 << pin);
    digiPin[channel].portAddr = &PORTD;
    digiPin[channel].portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (1 << (pin % 8));
    digiPin[channel].portAddr = &PORTB;
    digiPin[channel].portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}

bool configDin(int channel, unsigned char pin) {

  if ((pin > 1) && (pin < 8)) {
    DDRD = (0 << pin);
    digiPin[channel].portAddr = &PIND;
    digiPin[channel].portMask = pin;
    return &digiPin[channel];
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (0 << (pin % 8));
    digiPin[channel].portAddr = &PIND;
    digiPin[channel].portMask = (1 << (pin % 8));
    return &digiPin[channel];
  }
  else {
    return false;
  }
}

int getDin(int channel){
	dRecord *rec = &digiPin[channel];
	//Serial.println("getdin");
	if (*rec->portAddr & (1 << digiPin[channel].portMask)){
		//Serial.println("func success");
		return 1;
	}
	else{
		//Serial.println("func Fail");
		return 0;
	}

	/*else{
		Serial.println("elsing");
		assert(false);
		return 0;
	}*/
}


void setDout(int channel, int state) {
  dRecord *record;
  record = &digiPin[channel];

  if (state == 1) {
    //digiPin[channel].portAddr |= digiPin[channel].portMask;
    *(record->portAddr) |= record->portMask;
    return;
  }
  else {
    //digiPin[channel].portAddr ^= digiPin[channel].portMask;
	 *(record->portAddr) ^= record->portMask;
    return;
  }

}

void __assert(const char *__func, const char *__file, int __lineno, const char *__sexp) {
    // transmit diagnostic informations through serial link.
    Serial.println(__func);
    Serial.println(__file);
    Serial.println(__lineno, DEC);
    Serial.println(__sexp);
    Serial.flush();
    // abort program execution.
    abort();
}











#endif /* PORTCONFIG_H_ */
