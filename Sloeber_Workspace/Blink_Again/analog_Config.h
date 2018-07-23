#include "Arduino.h"
#include "portConfig.h"

#define ON 1
#define OFF 0

volatile uint8_t *Timerc;

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

void set_Abit(int bit){
	switch(bit){

	case COM0A1_s:
		TCCR0A |= (1 << COM0A1);
		Timerc = &TCCR1A;
		break;
	case COM0B1_s:
		TCCR0A |= (1 << COM0B1);
		Timerc = &TCCR1A;
		break;
	case COM1A1_s:
		TCCR1A |= (1 << COM1A1);
		Timerc = &TCCR1A;
		break;
	case COM1B1_s:
		TCCR1A |= (1 << COM1B1);
		Timerc = &TCCR1A;
		break;
	case COM2A1_s:
		TCCR2A |= (1 << COM2A1);
		Timerc = &TCCR2A;
		break;
	case COM2B1_s:
		TCCR2A |= (1 << COM2B1);
		Timerc = &TCCR2A;
		break;
	}
}


void analog_init(int channel, int analog_prescale){
    dRecord *pinaddr;
    pinaddr = &digiPin[channel];
    int pin = pinaddr->pin_num;

    //if (timer_0) analog_prescale+=2;

    switch(pin){
    case 3:
    	TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
    	Timerc = &TCCR2A;
    	break;
    case 5:
    	TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
    	Timerc = &TCCR0A;
    	break;
    case 6:
    	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    	Timerc = &TCCR0A;
    	break;
    case 11:
    	TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
    	Timerc = &TCCR2A;
    	break;
    }

    if (Timerc == &TCCR2A){

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



int dt_timer(int pin){
	const int registry[] = {
	        NOT_ON_TIMER, /* 0 - port D */
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        TIMER2B_s,
	        NOT_ON_TIMER,
	        TIMER0B_s,
	        TIMER0A_s,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER, /* 8 - port B */
	        NOT_ON_TIMER, //NO TIMER 1 /TIMER1A_s
	        NOT_ON_TIMER, //NO TIMER 1 /TIMER1B_s
	        TIMER2A_s,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER, /* 14 - port C */
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	};
	return registry[pin];


}


void set_analog(int channel, int val){
		val = map(val, 0.0, 1.0, 0, 255);

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
                switch(dt_timer(pin))
                {
                        case TIMER0A_s:
                                set_Abit(COM0A1_s);
                                OCR0A = val;
                                break;

                        case TIMER0B_s:
                                set_Abit(COM0B1_s);
                                OCR0B = val;
                                break;

                        case TIMER1A_s:
                                set_Abit(COM1A1_s);
                                OCR1A = val;
                                break;

                        case TIMER1B_s:
                                set_Abit(COM1B1_s);
                                OCR1B = val;
                                break;

                        case TIMER2A_s:
                                set_Abit(COM2A1_s);
                                OCR2A = val;
                                break;

                        case TIMER2B_s:
                                set_Abit(COM2B1_s);
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
