#define SAMPLE_TIME 0.001
#define prescaler 1
#define count 15999
#define digitalPins 5
#define MINIMUM_SAMPLE 1.25e-07
#define MAXIMUM_SAMPLE 4.194368
#define System Clock 16000000

#define start_time 0
#define Base_Step Blink_step()
#define Base_Init Blink_initialize(start_time)

#define Timer_RegisterA TCCR1A
#define Timer_RegisterB TCCR1B
#define Timer_Counter   TCNT1
#define Timer_RegisterOCR_A OCR1A
#define Timer_RegisterOCR_B OCR1B
#define Timer_RegisterMask TIMSK1
#define Timer1_Select true

extern void Blink_step();
extern void Blink_initialize(double time);
extern void Blink_terminate();