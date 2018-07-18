#include "Arduino.h"
#include "portConfig.h"
#include "analog_Config.h"
//#include <avr/io.h>
//#include <avr/interrupt.h>
#define SAMPLE_TIME 0.2
#define prescaler 64
#define count 49999.0

void config_interrupt(){
	cli(); //stop interrupts
	TCCR1A = 0; //Clear register
	TCCR1B = 0; //Clear register
	TCNT1  = 0; // initialize counter value to 0

	OCR1A = count; //set interrupt compare match value

	TCCR1B |= (1 << WGM12); // turn on CTC mode

	TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
}

void set_prescale(){
	if (prescaler == 1){
		// Set CS12, CS11 and CS10 bits for 1 prescaler/no prescale
		TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
	}

	else if (prescaler == 8){
		// Set CS12, CS11 and CS10 bits for x8 prescaler
		TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);
	}

	else if (prescaler == 64){
		// Set CS12, CS11 and CS10 bits for x64 prescaler
		TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);
	}

	else if (prescaler == 256){
		// Set CS12, CS11 and CS10 bits for x256 prescaler
		TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
	}

	else if (prescaler == 1024){
		// Set CS12, CS11 and CS10 bits for x1024 prescaler
		TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10);
	}
}
int main(void) {
  //init();
  config_interrupt();
  set_prescale();
  sei();
  Serial.begin(9600);

  configDout(0, 9);
  configDin(1, 13);
  configDout(2, 6);



  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //ISR
    Serial.println("interrupt");

	set_analog(0, 254);
    setDout(0, getDin(1));

	/*if(PINB |= (1 << PINB2)){
		Serial.println("if statement");
		setDout(0, 1);
	}

	else{
		Serial.println("else statement");
		setDout(0, 0);
	}*/

}


//#include "setup.h"

/*


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



  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine
  Serial.println("interrupting");
  setDout(0, getDin(1)); //set pin 13 to value of pin 5



  if (PIND & (1 << digiPin[1].portMask)) { //if Pin13 is LOW

   // setDout(0, on); //toggles pin 13 to HIGH
  }

  else {
    //setDout(0, off); //toggle pin 13 to LOW
  }

}

int main(void) {
  init();
	double init = 0;
	Blink_initialize(init);

	//TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
	TCCR1B = B00001100;                                                     //CS12 sets prescaler of 1024
	OCR1A = 28000; //timer will clear and interrupt upon reaching this count
	TIMSK1 = (1 << OCIE1A); //will interrupt when timer1 matches the value of OCR1A
	sei(); //setup compare on match interrupt using timer1


	  for (;;) {

	  }

	  return 0;
	}*/



