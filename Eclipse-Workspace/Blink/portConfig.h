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


bool configDout(dRecord *record, unsigned char pin) { //configure pin as output and stores info in the structure that the record variable points to

  if ((pin > 1) && (pin < 8)) { //configures pins less than 8 as PORTD and sets the accompanying pin index to portMask
    DDRB = (1 << pin); //sets pin as OUTPUT
    record->portAddr = &PORTD;
    record->portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (1 << (pin % 8));
    record->portAddr = &PORTB;
    record->portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}

bool configDin(dRecord *record, unsigned char pin) {

  if ((pin > 1) && (pin < 8)) {
    DDRD = (0 << pin); //sets pin as INPUT
    record->portAddr = &PORTD;
    record->portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (0 << (pin % 8));
    record->portAddr = &PORTB;
    record->portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}


void setPin(dRecord *record, int state) { //either sets the pin as HIGH or LOW based on the state passed into the function

  if (state == 1) {
    *(record->portAddr) |= record->portMask;
    return;
  }
  else {
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
