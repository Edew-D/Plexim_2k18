#include <Arduino.h>
#define __ASSERT_USE_STDERR
#include <assert.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "portConfig.h" //This is where most of the functions are stored
#define on 1
#define off 0


int main(void) {
  init();

  TCCR1B = (1 << WGM12) | (1 << CS12); //CS12 sets prescaler of 256
  OCR1A = 12499;
  TIMSK1 = (1 << OCIE1A);
  sei(); //setup compare on match interrupt using timer1

  bool success = configDout(0, 13); // configure pin 13 as output
  assert(success);
  success = configDin(1, 5); // configure pin 5 as input
  assert(success);
 // setDout(0, getDin(1)); // set pin 13 to value of pin 5

  Serial.begin(9600);

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine

  setDout(0, getDin(1));

/*
  if (PIND & (1 << digiPin[1].portMask)) { //if Pin13 is LOW
   // setDout(0, on); //toggles pin 13 to HIGH
  //  setPin(&ledPin2, off);

  }

  else {
    //setDout(0, off); //toggle pin 13 to LOW
  //  setPin(&ledPin2, on);
	//  Serial.println("HIGH");
	//  Serial.println(PIND);
  }*/

}

void loop () {

}
