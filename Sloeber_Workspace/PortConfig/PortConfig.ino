#include "Arduino.h"
#include "portConfig.h"
#include <avr/io.h>
#include <avr/interrupt.h>
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
  init();
  config_interrupt();
  set_prescale();
  sei();

  configDout(0, 11);
  configDin(1, 10);
  Serial.begin(9600);

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) {       //ISR
    Serial.println("interrupt");

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



