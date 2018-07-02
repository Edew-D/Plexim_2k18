#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "portConfig.h" //This is where most of the functions are stored
#define on 1
#define off 0
dRecord ledPin; //creates ledPin variable of type dRecord
//dRecord dOutPins[16];

int main(void) {

  TCCR1B = (1 << WGM12) | (1 << CS12); //CS12 sets prescaler of 256
  OCR1A = 12499;
  TIMSK1 = (1 << OCIE1A);
  sei(); //setup compare on match interrupt using timer1

  configDout(&ledPin, 13); //passed the address of ledPin and the pin to configure as output
  //configDout(&ledPin2, 2);

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine

  if (PORTB == (0 << PB5)) { //if Pin13 is LOW
    setPin(&ledPin, on); //toggles pin 13 to HIGH
  //  setPin(&ledPin2, off);
  }

  else {
    setPin(&ledPin, off); //toggle pin 13 to LOW
  //  setPin(&ledPin2, on);
  }

}

void loop () {

}
