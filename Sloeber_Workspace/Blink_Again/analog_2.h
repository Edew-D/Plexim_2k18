// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
#include "setup.h"
#include "portConfig.h"
//#include "wiring_private.h"
//#include "pins_arduino.h"
#define ON 1
#define OFF 0

#define NOT_ON_TIMER 0
#define TIMER2B 3
#define TIMER0B 5
#define TIMER0A 6
#define TIMER1A 9
#define TIMER1B 10
#define TIMER2A 11
const int TCCR0A = 15;
const int TCCR1A = 16;
const int TCCR2A = 17;
const int COM0A1 = 18;
const int COM0B1 = 19;
const int COM1A1 = 20;
const int COM1B1 = 21;
const int COM2A1 = 22;
const int COM2B1 = 23;


const byte dt_timer(byte pin){
	const byte registry[] = {
	        NOT_ON_TIMER, /* 0 - port D */
	        NOT_ON_TIMER,
	        NOT_ON_TIMER,
	        TIMER2B,
	        NOT_ON_TIMER,
	        TIMER0B,
	        TIMER0A,
	        NOT_ON_TIMER,
	        NOT_ON_TIMER, /* 8 - port B */
	        NOT_ON_TIMER, //NO TIMER 1 /TIMER1A
	        NOT_ON_TIMER, //NO TIMER 1 /TIMER1B
	        TIMER2A,
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

void set_bit(int bit){
	switch(bit){
	case COM0A1:
		TCCR0A |= (1 << COM0A1);
		break;
	case COM0B1:
		TCCR0A |= (1 << COM0B1);
		break;
	case COM1A1:
		TCCR1A |= (1 << COM1A1);
		break;
	case COM1B1:
		TCCR1A |= (1 << COM1B1);
		break;
	case COM2A1:
		TCCR2A |= (1 << COM2A1);
		break;
	case COM2B1:
		TCCR2A |= (1 << COM2B1);
		break;
	}
}

void set_analog(int pin, int val){


        // We need to make sure the PWM output is enabled for those pins
        // that support it, as we turn it off when digitally reading or
        // writing with them.  Also, make sure the pin is in output mode
        // for consistenty with Wiring, which doesn't require a pinMode
        // call for the analog output pins.

        //configDout(0, pin); //Do this in Plecs
        if (val == 0)
        {
                setDout(pin, OFF);
        }
        else if (val == 255)
        {
                setDout(pin, ON);
        }
        else
        {
                switch(dt_timer(pin))
                {
                        case TIMER0A:
                                // connect pwm to pin on timer 0, channel A
                                set_bit(TCCR0A, COM0A1);
                                OCR0A = val; // set pwm duty
                                break;

                        case TIMER0B:
                                // connect pwm to pin on timer 0, channel B
                                set_bit(TCCR0A, COM0B1);
                                OCR0B = val; // set pwm duty
                                break;

                        case TIMER1A:
                                // connect pwm to pin on timer 1, channel A
                                set_bit(TCCR1A, COM1A1);
                                OCR1A = val; // set pwm duty
                                break;

                        case TIMER1B:
                                // connect pwm to pin on timer 1, channel B
                                set_bit(TCCR1A, COM1B1);
                                OCR1B = val; // set pwm duty
                                break;

                        case TIMER2A:
                                // connect pwm to pin on timer 2, channel A
                                set_bit(TCCR2A, COM2A1);
                                OCR2A = val; // set pwm duty
                                break;

                        case TIMER2B:
                                // connect pwm to pin on timer 2, channel B
                                set_bit(TCCR2A, COM2B1);
                                OCR2B = val; // set pwm duty
                                break;


                        case NOT_ON_TIMER:
                        default:
                                if (val < 128) {
                                        setDout(pin, OFF);
                                } else {
                                        setDout(pin, ON);
                                }
                }
        }
}
