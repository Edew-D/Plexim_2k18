#include "setup.h"

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
  config_interrupt(); //config arduino to interrupt on compare match with OCR1A
  set_prescale();
  sei(); //enable global interrupts

  Base_Init;

  for (;;) {

  }

  return 0;
}

ISR(TIMER1_COMPA_vect) { //ISR that runs when timer reaches value of OCR2A->Discretization step size.
	Base_Step;
}
