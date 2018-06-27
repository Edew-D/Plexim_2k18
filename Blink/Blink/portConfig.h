
typedef struct {
  volatile uint8_t *portAddr;
  byte portIndex;
  byte portMask;
} dRecord;

dRecord *configDoutt(int channel, int pin) {
  if ((pin > 1) && (pin < 8)) {
    digitalPin[channel].portAddr = &PORTD;
    //digitalPin[channel].portMask = pin;
    return true;
  }
  digitalPin[channel]

  return *digitalPin[channel]
}

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


void setPin(dRecord *record, int state) {

  if (state == 1) {
    *(record->portAddr) |= record->portMask;
    return true;
  }
  else {
    *(record->portAddr) ^= record->portMask;
    return true;
  }

}












