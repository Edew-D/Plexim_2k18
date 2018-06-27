
typedef struct {
  volatile uint8_t *portAddr;
  byte portIndex;
  byte portMask;
} dRecord;

//const byte portIndexes[] = {PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, PB0, PB1, PB2, PB3, PB4,
 //                           PB5, PB6, PB7
   //                        };

bool configDout(dRecord *record, unsigned char pin) {
  
  if ((pin > 1) && (pin < 8)) {
    DDRB = (1 << pin);
    record->portAddr = &PORTD;
    record->portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (1 << (pin % 8));
    record->portAddr = &PORTB;
    record->portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}

bool configDin(dRecord *record, unsigned char pin) {
  
  if ((pin > 1) && (pin < 8)) {
    DDRD = (0 << pin);
    record->portAddr = &PORTD;
    record->portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (0 << (pin % 8));
    record->portAddr = &PORTB;
    record->portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}


void setPin(dRecord *record, int state){
  
  if (state == 1) {
    *(record->portAddr) |= record->portMask;
    return true;
  }
  else {
    *(record->portAddr) ^= record->portMask;
    return true;
  }

}












