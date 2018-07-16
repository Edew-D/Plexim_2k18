#include "Blink.c"
/*
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

  //TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
  TCCR1B = B00001100;                                                     //CS12 sets prescaler of 1024
  OCR1A = 28000; //timer will clear and interrupt upon reaching this count
  TIMSK1 = (1 << OCIE1A); //will interrupt when timer1 matches the value of OCR1A
  sei(); //setup compare on match interrupt using timer1

  bool success = configDout(0, 13); // configure pin 13 as output
  assert(success);
  success = configDin(1, 5); // configure pin 5 as input
  assert(success);

  Serial.begin(9600);

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine
  Serial.println("interrupting");
  setDout(0, getDin(1)); //set pin 13 to value of pin 5

/*

  if (PIND & (1 << digiPin[1].portMask)) { //if Pin13 is LOW

   // setDout(0, on); //toggles pin 13 to HIGH
  }

  else {
    //setDout(0, off); //toggle pin 13 to LOW
  }

}
*/
void setup(){
	Blink_initialize(Blink_sampleTime);
}


void loop () {
	Blink_step();
}

