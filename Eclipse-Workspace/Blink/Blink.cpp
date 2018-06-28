#include <Arduino.h>

//#include <avr/io.h>
//#include <avr/interrupt.h>
#include "portConfig.h"
#define on 1
#define off 0
dRecord ledPin;
dRecord dOutPins[16];

int main(void) {

  TCCR1B = (1 << WGM12) | (1 << CS12);
  OCR1A = 12499;
  TIMSK1 = (1 << OCIE1A);
  sei();

  configDout(&ledPin, 13);
  //configDout(&ledPin2, 2);

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine

  if (PORTB == (0 << PB5)) { //if Pin13 is LOW
    setPin(&ledPin, on);
  //  setPin(&ledPin2, off);
  }

  else {
    setPin(&ledPin, off); //turn on pin
  //  setPin(&ledPin2, on);
  }

}

void loop () {

}
