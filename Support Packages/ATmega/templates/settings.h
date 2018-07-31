#define SAMPLE_TIME 0.001
#define prescaler 1
#define count_V 249
#define digitalPins 6
#define MINIMUM_SAMPLE 4.06e-06
#define MAXIMUM_SAMPLE 1.04864
#define System Clock 16000000

#define start_time 0
#define Base_Step Blink_step()
#define Base_Init Blink_initialize(start_time)

#define Timer_RegisterA TCCR0A
#define Timer_RegisterB TCCR0B
#define Timer_Counter   TCNT0
#define Timer_RegisterOCR_A OCR0A
#define Timer_RegisterOCR_B OCR0B
#define Timer_RegisterMask TIMSK0
#define Timer_ISR TIMER0_COMPA_vect

extern void Blink_step();
extern void Blink_initialize(double time);
extern void Blink_terminate();