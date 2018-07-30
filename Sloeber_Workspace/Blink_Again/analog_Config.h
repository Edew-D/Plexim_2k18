#include "Arduino.h"
#include "portConfig.h"
//#include <avr/io.h>

#define ON 1
#define OFF 0

volatile uint8_t *Timerc; //points to selected timer's TCCRxA
volatile uint16_t  *Invert16; //holds address to inverted pin's OCRxn
volatile uint8_t *Invert;     //^^
int pwmPins[6] = {3, 5, 6, 9, 10, 11};

int val;
long val16;

#define NOT_ON_TIMER_s 0
#define TIMER0B_s 5
#define TIMER0A_s 6
#define TIMER1A_s 9
#define TIMER1B_s 10
#define TIMER2B_s 3
#define TIMER2A_s 11

#define COM0A1_s  18
#define COM0B1_s  19
#define COM1A1_s  20
#define COM1B1_s  21
#define COM2A1_s  22
#define COM2B1_s  23

#define no_prescaler 1
#define prescaler_8 2
#define prescaler_32 3
#define prescaler_64 4
#define prescaler_128 5
#define prescaler_256 6
#define prescaler_1024 7



long map(float x, float in_min, float in_max, long out_min, long out_max) //arduino function maps range of numbers to another range, modified by me to use data types specific to the timers
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

bool missing_value(int val, int arr[], int size){ //checks for certain if value is in array
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val)
            return false;
    }
    return true;
}

void invert_signal(int pin_to_invert){ //sets bits required to start timer in inverted mode

	switch(pin_to_invert){
	case 3:
		TCCR2A |= (1 << COM2B0);
		break;
	case 11:
		TCCR2A |= (1 << COM2A0);
		break;
	case 5:
		TCCR0A |= (1 << COM0B0);
		break;
	case 6:
		TCCR0A |= (1 << COM0A0);
		break;
	case 9:
		TCCR1A |= (1 << COM1B0);
		break;
	case 10:
		TCCR1A |= (1 << COM1A0);
		break;
}
}


void analogOut_init(int channel, int analog_prescale, bool inv){ //sets bits for fast pwm Mode and prescaler, also
    dRecord *pinaddr;											 //calls function to start timer in inverted mode if inv = true
    pinaddr = &digiPin[channel];
    int pin = pinaddr->pin_num;

    if (inv) invert_signal(pin);

    switch(pin){ //Setting to fast pwm Mode
    case 3:
    	TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
    	Invert = &OCR2B;
    	Timerc = &TCCR2A;
    	break;
    case 11:
    	TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
    	Invert = &OCR2A;
    	Timerc = &TCCR2A;
    	break;
    case 5:
    	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
    	Invert = &OCR0B;
    	Timerc = &TCCR0A;
    	break;
    case 6:
    	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    	Invert = &OCR0A;
    	Timerc = &TCCR0A;
    	break;
    case 9:
    	ICR1 = 0xFFFF; //set TOP to 16 bit
    	TCCR1A |= (1 << COM1B1)| (1 << WGM10);
    	TCCR1B |= (1 << WGM12);
    	Invert16 = &OCR1B;
    	Timerc = &TCCR1A;
    	break;
    case 10:
    	ICR1 = 0xFFFF; //set TOP to 16 bit
    	TCCR1A |= (1 << COM1A1) | (1 << WGM10);
    	TCCR1B |= (1 << WGM12);
    	Invert16 = &OCR1A;
    	Timerc = &TCCR1A;
    	break;
    }

    if (Timerc == &TCCR2A){ //Set prescale

		switch(analog_prescale){

		case no_prescaler:
			TCCR2B |= (1 << CS20);
		break;
		case prescaler_8:
			TCCR2B |= (1 << CS21);
			break;
		case prescaler_32:
			TCCR2B |= (1 << CS20) | (1 << CS21);
			break;
		case prescaler_64:
			TCCR2B |= (1 << CS22);
			break;
		case prescaler_128:
			TCCR2B |= (1 << CS20) | (1 << CS22);
			break;
		case prescaler_256:
			TCCR2B |= (1 << CS20) | (1 << CS22);
			break;
		case prescaler_1024:
			TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
			break;
		}
    }

	else if (Timerc == &TCCR0A){

		switch(analog_prescale){

		case no_prescaler:
			TCCR0B |= (1 << CS00);
		break;
		case prescaler_8:
			TCCR0B |= (1 << CS01);
			break;
		case 3:
			TCCR0B |= (1 << CS01) | (1 << CS00);
			break;
		case 4:
			TCCR0B |= (1 << CS02);
			break;
		case 5:
			TCCR0B |= (1 << CS02) | (1 << CS00);
			break;
		}
	}
	else if (Timerc == &TCCR1A){
		switch(analog_prescale){

		case no_prescaler:
			TCCR1B |= (1 << CS10);
		break;
		case 2:
			TCCR1B |= (1 << CS11);
			break;
		case 3:
			TCCR1B |= (1 << CS11) | (1 << CS10);
			break;
		case 4:
			TCCR1B |= (1 << CS12);
			break;
		case 5:
			TCCR1B |= (1 << CS12) | (1 << CS10);
			break;
		}

	}

}




void set_analogOut(int channel, float pwm, bool inv){ //maps val to OCRxn acceptable range,

		val = map(pwm, 0.0, 1.0, 0, 255);
		val16 = map(pwm, 0.0, 1.0, 0, 65535);

		if (inv) *Invert = val;
		if (inv) *Invert16 = val;

	    dRecord *pinaddr;
	    pinaddr = &digiPin[channel];
	    int pin = pinaddr->pin_num;

	    if (missing_value(pin, pwmPins, 5)) pin = NOT_ON_TIMER;

        if (val == 0)
        {
                setDout(channel, OFF);
        }
        else if (val == 255)
        {
                setDout(channel, ON);
        }
        else
        {

                switch(pin)
                {
                        case TIMER0A_s:
                                OCR0A = val;
                                break;

                        case TIMER0B_s:
                                OCR0B = val;
                                break;

                        case TIMER1A_s:
                                OCR1A = 125;
                                break;

                        case TIMER1B_s:
                                OCR1B = 125;
                                break;

                        case TIMER2A_s:
                                OCR2A = val;
                                break;

                        case TIMER2B_s:
                                OCR2B = val;
                                break;


                        case NOT_ON_TIMER:
                        default:
                                if (val < 128) {
                                        setDout(channel, OFF);
                                } else {
                                        setDout(channel, ON);
                                }
                }
        }
}

void analogIn_init(){



}
