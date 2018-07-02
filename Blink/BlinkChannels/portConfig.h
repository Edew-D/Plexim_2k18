
typedef struct {
  volatile uint8_t *portAddr;
  volatile uint8_t portMask;
} dRecord;

dRecord digiPin[16];


bool configDout(int channel, int pin) {

  if ((pin > 1) && (pin < 8)) {
    DDRB = (1 << pin);
    digiPin[channel].portAddr = &PORTD;
    digiPin[channel].portMask = pin;
    return true;
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (1 << (pin % 8));
    digiPin[channel].portAddr = &PORTB;
    digiPin[channel].portMask = (1 << (pin % 8));
    return true;
  }
  else {
    return false;
  }
}

bool configDin(int channel, unsigned char pin) {

  if ((pin > 1) && (pin < 8)) {
    DDRD = (0 << pin);
    digiPin[channel].portAddr = &PORTD;
    digiPin[channel].portMask = pin;
    return &digiPin[channel];
  }
  else if ((pin > 7) && (pin < 14 )) {
    DDRB = (0 << (pin % 8));
    digiPin[channel].portAddr = &PORTB;
    digiPin[channel].portMask = (1 << (pin % 8));
    return &digiPin[channel];
  }
  else {
    return false;
  }
}

int getDin(int channel){
  return digiPin[channel].portAddr;
}


void setDout(int channel, int state) {

  if (state == 1) {
    digiPin[channel].portAddr |= digiPin[channel].portMask;
    return;
  }
  else {
    digiPin[channel].portAddr ^= digiPin[channel].portMask;
    return;
  }

}












