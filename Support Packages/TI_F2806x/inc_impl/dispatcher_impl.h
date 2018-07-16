/*
   Copyright (c) 2014-2016 by Plexim GmbH
   All rights reserved.

   A free license is granted to anyone to use this software for any legal
   non safety-critical purpose, including commercial applications, provided
   that:
   1) IT IS NOT USED TO DIRECTLY OR INDIRECTLY COMPETE WITH PLEXIM, and
   2) THIS COPYRIGHT NOTICE IS PRESERVED in its entirety.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */

#ifndef DISPATCHER_IMPL_H_
#define DISPATCHER_IMPL_H_

typedef enum {
	DISPR_TimebaseIsTimer = 0,
	DISPR_TimebaseIsPwm = 1,
	DISPR_TimebaseIsAdc = 2
} DISPR_Timebase_t;

typedef enum {
	DISPR_BaseClockIsTimer = 0,
	DISPR_BaseClockIsPwm = 1,
} DISPR_BaseClock_t;

typedef struct DISPR_OBJ
{
	volatile struct EPWM_REGS *ePwm;
    PINT *ePwmIntVector;
    uint16_t ePwmIerBitMask;
	volatile struct ADC_REGS *adc;

	uint32_t sysClkHz;
	uint32_t disprClkHz;
	uint16_t powerupDelayMs;

	DISPR_Timebase_t timeBase;
	DISPR_BaseClock_t baseClock;

	PIL_READ_PROBE(uint32_t, ctrlPeriod, 0, 1, "");

	DISPR_CallbackPtr_t tsk1;
	DISPR_CallbackPtr_t tsk2;

	uint16_t powerupCountdown;

	uint16_t task2DispatchPeriod;
	uint16_t task2DispatchTimer;

	// diagnostics
	uint16_t task2Active; // make 16-bit so that PLECS can access variable
	int16_t interruptNesting;
	PIL_READ_PROBE(uint32_t, thisCntdownTimestamp0, 0, 1, "");
	PIL_READ_PROBE(uint32_t, thisCntdownTimestamp1, 0, 1, "");
	PIL_READ_PROBE(uint32_t, thisCntdownTimestamp2, 0, 1, "");
	PIL_READ_PROBE(uint32_t, cntdownTimestamp1, 0, 1, "");
	PIL_READ_PROBE(uint32_t, cntdownTimestamp2, 0, 1, "");
} DISPR_Obj_t;

typedef DISPR_Obj_t *DISPR_Handle_t;

extern DISPR_Handle_t DisprHandle;

inline uint32_t DISPR_getTimeStamp()
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;
	return (obj->ctrlPeriod - CpuTimer0Regs.TIM.all);
}

#endif /* DISPATCHER_IMPL_H_ */
