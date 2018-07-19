// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
#include "Arduino.h"
#include "portConfig.h"
//#include "wiring_private.h"
//#include "pins_arduino.h"
#define ON 1
#define OFF 0

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

#define no_prescaler 62500
#define prescaler_8 7812.5
#define prescaler_32 1953.125
#define prescaler_64 976.5625
#define prescaler_128 488.28125
#define prescaler_256 244.140625
#define prescaler_1024 61.03515625



/*
const int TCCR0A = 15;
const int TCCR1A = 16;
const int TCCR2A = 17
const int COM0A1_s = 18;
const int COM0B1_s = 19;
const int COM1A1_s = 20;
const int COM1B1_s = 21;
const int COM2A1_s = 22;
const int COM2B1_s = 23;*/

void analog_init(int channel, double frequency){
    dRecord *pinaddr;
    pinaddr = &digiPin[channel];
    int pin = pinaddr->pin_num;
    volatile uint8_t *Timerc;

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

    if (Timerc == TCCR2A){
		switch(frequency){

		case no_prescaler:
		break;
		case prescaler_8:
			break;
		case prescaler_32:
			break;
		case prescaler_64:
			break;
		case prescaler_128:
			break;
		case prescaler_256:
			break;
		case prescaler_1024:
			break;
		}
    }
	else if (Timerc == TCCR0A){

		switch(frequency){

		case no_prescaler:
			TCCR0B |= (1 << CS00);
		break;
		case prescaler_8:
			TCCR0B |= (1 << CS01);
			break;
		case prescaler_32:
			TCCR0B |= (1 << CS01) | (1 << CS00);
			break;
		case prescaler_64:
			break;
		case prescaler_128:
			break;
		case prescaler_256:
			break;
		case prescaler_1024:
			break;
		}
		}

	}



const int dt_timer(int pin){
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
	//Serial.println("Pin is: ");
	//Serial.println(registry[pin]);
	return registry[pin];


}

void set_Abit(int bit){
	switch(bit){
	case COM0A1_s:
		TCCR0A |= (1 << COM0A1);
		//Serial.println("Set Bit: Success!");
		break;
	case COM0B1_s:
		TCCR0A |= (1 << COM0B1);
		break;
	case COM1A1_s:
		TCCR1A |= (1 << COM1A1);
		break;
	case COM1B1_s:
		TCCR1A |= (1 << COM1B1);
		break;
	case COM2A1_s:
		TCCR2A |= (1 << COM2A1);
		break;
	case COM2B1_s:
		TCCR2A |= (1 << COM2B1);
		break;
	}
}

void set_analog(int channel, int val){
	    //Serial.println("in set analog");
	    dRecord *pinaddr;
	    pinaddr = &digiPin[channel];
	    int pin = pinaddr->pin_num;

        // We need to make sure the PWM output is enabled for those pins
        // that support it, as we turn it off when digitally reading or
        // writing with them.  Also, make sure the pin is in output mode
        // for consistenty with Wiring, which doesn't require a pinMode
        // call for the analog output pins.

        //configDout(channel, ); //Do this in Plecs
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
                        	    //Serial.println("Switch: Success!");
                                // connect pwm to pin on timer 0, channel A
                                set_Abit(COM0A1_s);
                                OCR0A = val; // set pwm duty
                                //Serial.println("Set_Val: Success!");
                                break;

                        case TIMER0B_s:
                                // connect pwm to pin on timer 0, channel B
                                set_Abit(COM0B1_s);
                                OCR0B = val; // set pwm duty
                                break;

                        case TIMER1A_s:
                                // connect pwm to pin on timer 1, channel A
                                set_Abit(COM1A1_s);
                                OCR1A = val; // set pwm duty
                                break;

                        case TIMER1B_s:
                                // connect pwm to pin on timer 1, channel B
                                set_Abit(COM1B1_s);
                                OCR1B = val; // set pwm duty
                                break;

                        case TIMER2A_s:
                                // connect pwm to pin on timer 2, channel A
                                set_Abit(COM2A1_s);
                                OCR2A = val; // set pwm duty
                                break;

                        case TIMER2B_s:
                                // connect pwm to pin on timer 2, channel B
                                set_Abit(COM2B1_s);
                                OCR2B = val; // set pwm duty
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
