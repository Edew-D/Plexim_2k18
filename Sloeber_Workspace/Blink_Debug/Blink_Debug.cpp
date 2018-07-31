#include "setup.h"
#include "analog_Config.h"

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

	*TimerOCR_A = count; //set interrupt compare match value

	if (TimerRB == &TCCR1B) *TimerRB |= (1 << 3); // turn on CTC mode
	else *TimerRB |= (1 << 1);

	*TimerRM |= (1 << 1); // enable timer compare interrupt
}

void set_prescale(){
	if (prescaler == 1){
		// Set CS12, CS11 and CS10 bits for 1 prescaler/no prescale
		*TimerRB |= (1 << 1) | (1 << 1) | (1 << 0);
	}

	else if (prescaler == 8){
		// Set CS12, CS11 and CS10 bits for x8 prescaler
		*TimerRB |= (1 << 2) | (1 << 1) | (0 << 0);
	}

	else if (prescaler == 32){
		// Set CS12, CS11 and CS10 bits for x8 prescaler
		*TimerRB |= (1 << 1) | (1 << 0);
	}

	else if (prescaler == 64){
		// Set CS12, CS11 and CS10 bits for x64 prescaler
		*TimerRB |= (1 << 2) | (1 << 1) | (1 << 0);
	}

	else if (prescaler == 128){
		// Set CS12, CS11 and CS10 bits for x8 prescaler
		*TimerRB |= (1 << 2) | (1 << 1);
	}

	else if (prescaler == 256){
		// Set CS12, CS11 and CS10 bits for x256 prescaler
		*TimerRB |= (1 << 2) | (1 << 1) | (1 << 0);
	}

	else if (prescaler == 1024){
		// Set CS12, CS11 and CS10 bits for x1024 prescaler
		*TimerRB |= (1 << 2) | (1 << 1) | (1 << 0);
	}
}

int main(void) {
  Serial.begin(9600);
  Serial.println("started serial");
  //init();
  config_interrupt(); //config arduino to interrupt on compare match with OCR1A
  set_prescale();
  //Base_Init;
  /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)' */
  configDout(3, 10);
  analogOut_init(3, 2, 0);

  /* Initialization for PWM Out : 'Blink/PWM Out (ePWM0)1' */
  configDout(4, 3);
  analogOut_init(4, 4, 0);

  for (;;) {

  }

  return 0;
}

ISR(Timer_ISR) { //ISR that runs when timer reaches value of OCR2A->Discretization step size.
	//Base_Step;
	   /* Digital Out : 'Blink/Digital Out2' */
	   setDout(0, 1.);
	   /* Digital Out : 'Blink/Digital Out3' */
	   setDout(2, getDin(1));
	   /* PWM Out : 'Blink/PWM Out (ePWM0)' */
	   set_analogOut(3, 0.8, 0);
	   /* PWM Out : 'Blink/PWM Out (ePWM0)1' */
	   set_analogOut(4, 0.8, 0);
}
