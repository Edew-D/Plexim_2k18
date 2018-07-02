#include <avr/io.h>
#include <avr/interrupt.h>
#include "portConfig.h"
#define on 1
#define off 0



int main(void) {

  TCCR1B = (1 << WGM12) | (1 << CS12);
  OCR1A = 12499;
  TIMSK1 = (1 << OCIE1A);
  sei();
  bool success  = configDout(0, 13)
//  assert(success);
//  success  = configDin(1, 5);
  

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine
  
  if (PORTB  == (0 << PB5)) { //if Pin13 is LOW
    setDout(0, on);
  //  setPin(&ledPin2, off);
  }

  else {
    setDout(0, off); //turn on pin
  //  setPin(&ledPin2, on);
  }

}

void loop () {

}

