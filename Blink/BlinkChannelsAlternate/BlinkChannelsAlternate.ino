#include <avr/io.h>
#include <avr/interrupt.h>
#include "portConfig.h"
#define on 1
#define off 0
dRecord  *Pin;
dRecord  *Pin2;


int main(void) {

  TCCR1B = (1 << WGM12) | (1 << CS12);
  OCR1A = 12499;
  TIMSK1 = (1 << OCIE1A);
  sei();
  Pin = configDout(0, 13);
  Pin2 = configDin(1, 2);
  
//  assert(success);
//  success  = configDin(1, 5);
  

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine
  setDout(Pin, getDin(1));
  /*
  if (PORTB  == (0 << PB5)) { //if Pin13 is LOW
    setDout(Pin, on);
  //  setPin(&ledPin2, off);
  }

  else {
    setDout(Pin, off); //turn on pin
  //  setPin(&ledPin2, on);
  }*/

}

void loop () {

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
