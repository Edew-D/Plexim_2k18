// Clock configurations
#define SYSCLK_HZ 90000000.0L
#define PLL_DIV 18
#define CLK_SRC 0
#define PLX_CPU_RATE 11.111111111111L

// HAL object allocations
#define NUM_DOUT 0
#define NUM_DIN 0
#define NUM_PWM 0
#define NUM_ADC 0

// Dispatcher configurations
#define TIMEBASE_CLOCK_AUTO 0
#define TIMEBASE_CLOCK_CPUTIMER -1
#define TIMEBASE_CLOCK_PWM -2

#define TIMEBASE_TRIGGER_AUTO 0
#define TIMEBASE_TRIGGER_ADC -1

#define TIMEBASE_CLOCK TIMEBASE_CLOCK_AUTO
#define TIMEBASE_TRIGGER TIMEBASE_TRIGGER_AUTO
