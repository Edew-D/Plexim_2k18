#define SAMPLE_TIME 1e-06
#define prescaler 1
#define count 15
#define digitalPins 3
#define MINIMUM_SAMPLE 1.25e-07
#define MAXIMUM_SAMPLE 4.194368

#define start_time 0
#define Base_Step Blink_step()
#define Base_Init Blink_initialize(start_time)

extern void Blink_step();
extern void Blink_initialize(double time);
extern void Blink_terminate();