#include "setup.h"
//#include "portConfig.h"
//#include "analog_Config.h"

#ifndef Timer1_Select
volatile uint8_t *TimerRA = &Timer_RegisterA;
volatile uint8_t *TimerRB = &Timer_RegisterB;
volatile uint8_t *TimerRM = &Timer_RegisterMask;
volatile uint8_t *TimerCount = &Timer_Counter;
volatile uint8_t *TimerOCR_A = &Timer_RegisterOCR_A;
volatile uint8_t *TimerOCR_B = &Timer_RegisterOCR_B;
#endif

#ifdef Timer1_Select
volatile uint8_t *TimerRA = &Timer_RegisterA;
volatile uint8_t *TimerRB = &Timer_RegisterB;
volatile uint8_t *TimerRM = &Timer_RegisterMask;
volatile uint16_t *TimerCount = &Timer_Counter;
volatile uint16_t *TimerOCR_A = &Timer_RegisterOCR_A;
volatile uint16_t *TimerOCR_B = &Timer_RegisterOCR_B;
#endif
const long count = count_V;



void config_interrupt(){

	cli(); //stop interrupts
	*TimerRA = 0; //Clear register
	*TimerRB = 0; //Clear register
	*TimerCount  = 0; // initialize counter value to 0

	*TimerOCR_A = 249; //set interrupt compare match value

	if (TimerRB == &TCCR1B) *TimerRB |= (1 << WGM12); // turn on CTC mode
	else *TimerRB |= (1 << 1);

	*TimerRM |= (1 << 1); // enable timer compare interrupt
}

void set_prescale(){

	*TimerRB |= (1 << CS20);
	/*if (TimerRA == &TCCR2A){ //Sets prescalers for Timer2
		switch(prescaler){
		case 1:
			*TimerRB |= (1 << CS20);
			break;
		case 8:
			*TimerRB |= (1 << CS21);
			break;
		case 32:
			*TimerRB |= (1 << CS21) | (1 << CS20);
			break;
		case 64:
			*TimerRB |= (1 << CS22);
			break;
		case 128:
			*TimerRB |= (1 << CS22) | (1 << CS20);
			break;
		case 256:
			*TimerRB |= (1 << CS22) | (1 << CS21);
			break;
		case 1024:
			*TimerRB |= (1 << CS22) | (1 << CS21) | (1 << CS20);
			break;
		}

	}


	else{

		switch(prescaler){  //Sets correct prescalers for Timer0 and Timer1
		case 1:
			*TimerRB |= (1 << 0);
			break;
		case 8:
			*TimerRB |= (1 << 1);
			break;
		case 64:
			*TimerRB |= (1 << 1) | (1 << 0);
			break;
		case 256:
			*TimerRB |= (1 << 2);
			break;
		case 1024:
			*TimerRB |= (1 << 2) | (1 << 0);
			break;
		}
	}*/

}

int main(void) {
  //init();

  config_interrupt(); //config arduino to interrupt on compare match with OCRxA
  set_prescale();
  sei(); //enable global interrupts

  //TCCR1A |= (1 << COM1B1) | (1 << WGM10);
  //TCCR1B |= (1 << WGM12);
  //TCCR1B |= (1 << CS10);

  Base_Init;
  //OCR1A= 125;
  //OCR1B = 125;
  //TCCR1A |= (1 << COM1A1) | (1 << WGM10);
  //TCCR1B |= (1 << WGM12);
  //TCCR1B |= (1 << CS11) | (1 << CS10);// | (1 << CS12);
  for (;;) {

  }

  return 0;
}

ISR(Timer_ISR) { //ISR that runs when timer reaches value of OCR2A->Discretization step size.
	Base_Step;
}
