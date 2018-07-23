#include "Arduino.h"
#include "portConfig.h"

#define ON 1
#define OFF 0

volatile uint8_t *Timerc;
volatile uint8_t *Invert;
int val;



#define NOT_ON_TIMER_s 0
#define TIMER2B_s 3
#define TIMER0B_s 5
#define TIMER0A_s 6
#define TIMER1A_s 9
#define TIMER1B_s 10
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

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void invert_signal(int pin_to_invert){

	switch(pin_to_invert){
	case 3:
		TCCR2A |= (1 << COM2B0);
		break;
	case 5:
		TCCR0A |= (1 << COM0B0);
		break;
	case 6:
		TCCR0A |= (1 << COM0A0);
		break;
	case 11:
		TCCR2A |= (1 << COM2A0);
		break;

}
}



void analog_init(int channel, int analog_prescale, bool inv){
    dRecord *pinaddr;
    pinaddr = &digiPin[channel];
    int pin = pinaddr->pin_num;

    if (inv) invert_signal(pin);

    switch(pin){ //Setting to fast pwm Mode
    case 3:
    	TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
    	Invert = &OCR2B;
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
    case 11:
    	TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
    	Invert = &OCR2A;
    	Timerc = &TCCR2A;
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
		case prescaler_64:
			TCCR0B |= (1 << CS01) | (1 << CS00);
			break;
		case prescaler_256:
			TCCR0B |= (1 << CS02);
			break;
		case prescaler_1024:
			TCCR0B |= (1 << CS02) | (1 << CS00);
			break;
		}
	}

}




void set_analog(int channel, float pwm, bool inv){

		val = map(pwm, 0.0, 1.0, 0, 255);

		if (inv) *Invert = val;

	    dRecord *pinaddr;
	    pinaddr = &digiPin[channel];
	    int pin = pinaddr->pin_num;

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
                                OCR1A = val;
                                break;

                        case TIMER1B_s:
                                OCR1B = val;
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

