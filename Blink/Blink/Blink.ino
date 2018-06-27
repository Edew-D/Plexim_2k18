#include <avr/io.h>
#include <avr/interrupt.h>

typedef struct {
  volatile uint8_t *portAddr;
  byte portIndex;
} dRecord;

//dRecord *record;

void setPin(dRecord *record) {
  *(record->portAddr) = (1 << record->portIndex);
}

void clearPin(dRecord *record) {
  *(record->portAddr) = (0 << record->portIndex);
}

int main(void) {
  DDRB = (1 << PB5);

  TCCR1B = (1 << WGM12) | (1 << CS12);
  OCR1A = 31249;
  TIMSK1 = (1 << OCIE1A);
  sei();

  Serial.begin(9600);
  for (;;) {

  }
  
  return 0;
}

ISR(TIMER1_COMPA_vect) {       //This is our interrupt service routine

  //PORTB ^= (1 << PB5);  //Toggle led state
  //PORTB = PORTB ^ (1 << PB5);
  dRecord dPin13;
  //int x = (int(dPin13.portAddr));
  //Serial.println(x);
  dPin13.portAddr = &PORTB;
  //int y = (int(dPin13.portAddr));
  //Serial.println(y);
  dPin13.portIndex = PB5;

  //record = &dPin13;
  
  if (PORTB == (0<<PB5)) {
    //Serial.println(dPin13.portAddr);
    setPin(&dPin13); //turn on pin 13
    //record->portAddr = (1 << record->portIndex);
    // = PORTB ^ (1 << PB5);
  }
   
  else {
    //clearPin(&dPin13); //turn off pin 13
    //record->portAddr = record->portAddr ^ (0 << record->portIndex);
    //PORTB = PORTB ^ (0 << PB5);
    clearPin(&dPin13);
  }

}

void loop () {

}
