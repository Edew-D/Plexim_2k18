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

#include "dispatcher.h"

/*
 * Assumptions/simplifications:
 * 1) ADC configured to trigger ADCINT1
 * 2) ePWM configured to issue SOCA
 * 3) ePWM int on PIE group 3 (ok for epwm1-8)
 * 4) ePWM clock = SYSCLK/2
 * 5) ePWM in up/down count mode
 * 6) Use of CpuTimer0 is hardcoded
 */

// singleton ('cause PIL framework still singleton)
DISPR_Obj_t DisprObj;
DISPR_Handle_t DisprHandle;

void DISPR_dispatch();

void DISPR_sinit()
{
	DisprHandle = (DISPR_Handle_t)&DisprObj;

	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;
	obj->powerupDelayMs = 0;
}

void DISPR_configure(uint32_t aSysClkHz)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	obj->sysClkHz = aSysClkHz;
}

static void DISPR_configurePwm(PWM_Unit_t aPwmChannel)
{
	ASSERT((int)aPwmChannel >= (int)PWM_EPWM1);
	ASSERT((int)aPwmChannel <= (int)PWM_EPWM8);

	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;
	PWM_getRegisterBase(aPwmChannel, &obj->ePwm);
	obj->ePwmIntVector = (PINT *)((uint32_t)(&PieVectTable.EPWM1_INT) + ((uint32_t)aPwmChannel-1)*sizeof(PINT *));
	obj->ePwmIerBitMask = (1 << (aPwmChannel-1));
}

void DISPR_setPowerupDelayMs(uint16_t aDelayMs)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;
	obj->powerupDelayMs = aDelayMs;
}

bool DISPR_powerupDelayIsActive()
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	return (obj->powerupCountdown > 0);
}

void DISPR_setTriggerByAdcViaTimer(AIN_Unit_t aAdcUnit, uint16_t aEocChannel)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	DISPR_stop();

	AIN_getRegisterBase(aAdcUnit, &obj->adc);
	obj->timeBase = DISPR_TimebaseIsAdc;
	obj->baseClock = DISPR_BaseClockIsTimer;

	// CPU timer does not need any config

	EALLOW;
	obj->adc->INTSEL1N2.bit.INT1CONT = 0; // disable ADCINT1 Continuous mode
	obj->adc->INTSEL1N2.bit.INT1SEL = aEocChannel; // setup EOC to trigger ADCINT1
	obj->adc->INTSEL1N2.bit.INT1E = 1; // enable ADCINT1
	obj->adc->ADCCTL1.bit.INTPULSEPOS = 1; // ADCINT1 trips after AdcResults latch
	PieVectTable.ADCINT1 = &DISPR_dispatch;
	EDIS;
}

void DISPR_setTriggerByAdcViaPwm(AIN_Unit_t aAdcUnit, uint16_t aEocChannel, PWM_Unit_t aPwmChannel)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	DISPR_stop();

	DISPR_configurePwm(aPwmChannel);

	AIN_getRegisterBase(aAdcUnit, &obj->adc);
	obj->timeBase = DISPR_TimebaseIsAdc;
	obj->baseClock = DISPR_BaseClockIsPwm;

	// work here: should also work without PWM, should make sure only one SOCAEN is set
	obj->ePwm->ETSEL.bit.SOCAEN	= 1; // enable SOC on A group

	EALLOW;
	obj->adc->INTSEL1N2.bit.INT1CONT = 0; // disable ADCINT1 Continuous mode
	obj->adc->INTSEL1N2.bit.INT1SEL = aEocChannel; // setup EOC to trigger ADCINT1
	obj->adc->INTSEL1N2.bit.INT1E = 1; // enable ADCINT1
	obj->adc->ADCCTL1.bit.INTPULSEPOS = 1; // ADCINT1 trips after AdcResults latch
	PieVectTable.ADCINT1 = &DISPR_dispatch;
	EDIS;
}

void DISPR_setTriggerByTimer()
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	DISPR_stop();

	obj->timeBase = DISPR_TimebaseIsTimer;
	obj->baseClock = DISPR_BaseClockIsTimer;

	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
	CpuTimer0Regs.TCR.bit.TIE = 1;

	EALLOW;
	PieVectTable.TINT0 = &DISPR_dispatch;
	EDIS;
}

void DISPR_setTriggerByPwm(PWM_Unit_t aPwmChannel)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	DISPR_stop();

	DISPR_configurePwm(aPwmChannel);

	obj->timeBase = DISPR_TimebaseIsPwm;
	obj->baseClock = DISPR_BaseClockIsPwm;

	// work here: should make sure only one INTEN is set
	obj->ePwm->ETSEL.bit.INTEN = 1;  // enable INT
	PieCtrlRegs.PIEIER3.all |= obj->ePwmIerBitMask;

	EALLOW;
	*obj->ePwmIntVector = &DISPR_dispatch;
	EDIS;
}

void DISPR_reset()
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;
	obj->task2DispatchTimer = 0;
}

void DISPR_start(DISPR_CallbackPtr_t aTsk1, uint32_t aTsk1Freq,
		DISPR_CallbackPtr_t aTsk2, uint32_t aTsk2Freq)
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	obj->tsk1 = aTsk1;
	obj->tsk2 = aTsk2;

	CpuTimer0Regs.TCR.bit.TSS = 1; // stop timer
	CpuTimer0Regs.TPRH.all = 0;
	CpuTimer0Regs.TPR.all = 1; // set cpu timer to same clock as ePWM (SYSCLK/2)

	if(obj->baseClock == DISPR_BaseClockIsTimer)
	{
		obj->ctrlPeriod =  obj->sysClkHz/2L/aTsk1Freq-1;
		ASSERT((obj->ctrlPeriod+1)*2L*aTsk1Freq == obj->sysClkHz);

		CpuTimer0Regs.PRD.all = obj->ctrlPeriod;
		CpuTimer0Regs.TCR.bit.TRB = 1; // reload timer
	}
	else if(obj->baseClock == DISPR_BaseClockIsPwm)
	{
		ASSERT(obj->ePwm->TBCTL.bit.CTRMODE == TB_COUNT_UPDOWN); // TODO: implement TB_COUNT_UP, TB_COUNT_DOWN

		uint32_t pwmClkHz = obj->sysClkHz/4L/(uint32_t)obj->ePwm->TBPRD;

		uint16_t prd = (uint16_t)(pwmClkHz/aTsk1Freq);

		if(((uint32_t)prd*aTsk1Freq) != pwmClkHz)
		{
			ASSERT(0); // only exact multiples allowed
		}
		if(prd > 3)
		{
			ASSERT(0); // ratio not supported
		}

		if(obj->timeBase == DISPR_TimebaseIsAdc)
		{
			obj->ePwm->ETPS.bit.SOCAPRD = prd;
		}
		else
		{
			obj->ePwm->ETPS.bit.INTPRD = prd;
		}

		// configure timer for timing diagnostics
		obj->ctrlPeriod =  (uint32_t)prd * (uint32_t)obj->ePwm->TBPRD * 2L -1;
		if(obj->ePwm->ETSEL.bit.SOCASEL == ET_CTR_PRD)
		{
			CpuTimer0Regs.PRD.all = obj->ctrlPeriod - (uint32_t)obj->ePwm->TBPRD; // initial offset
			CpuTimer0Regs.TCR.bit.TRB = 1; // reload timer (initial offset)
			CpuTimer0Regs.PRD.all = obj->ctrlPeriod;
		}
		else
		{
			CpuTimer0Regs.PRD.all = obj->ctrlPeriod;
			CpuTimer0Regs.TCR.bit.TRB = 1; // reload timer
		}
	}

	obj->task2DispatchPeriod = (uint16_t)(aTsk1Freq/aTsk2Freq);
	if(((uint32_t)obj->task2DispatchPeriod*aTsk2Freq) != aTsk1Freq)
	{
		ASSERT(0); // only exact multiples allowed
	}

	obj->task2Active = false;
	obj->interruptNesting = 0;
	obj->cntdownTimestamp1 = 0xFFFFFFFF;
	obj->cntdownTimestamp2 = 0xFFFFFFFF;
	DISPR_reset();

	obj->powerupCountdown = (uint16_t)(aTsk1Freq/1000*obj->powerupDelayMs);

	if(obj->timeBase == DISPR_TimebaseIsAdc)
	{
		PieCtrlRegs.PIEIER1.bit.INTx1 = 1;
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // Acknowledge interrupt to PIE
		IER |= M_INT1;
	}
	else if (obj->timeBase == DISPR_TimebaseIsPwm)
	{
		PieCtrlRegs.PIEIER3.all |= obj->ePwmIerBitMask;
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP3; // Acknowledge interrupt to PIE
		IER |= M_INT3;
	}
	else // timer
	{
		PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // Acknowledge interrupt to PIE
		IER |= M_INT1;
	}
}

void DISPR_stop()
{
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	if(obj->timeBase == DISPR_TimebaseIsAdc)
	{
		PieCtrlRegs.PIEIER1.bit.INTx1 = 0;
	}
	else
	{
		PieCtrlRegs.PIEIER3.all &= ~obj->ePwmIerBitMask;
	}
}

static interrupt void DISPR_dispatch(){
	DISPR_Obj_t *obj = (DISPR_Obj_t *)DisprHandle;

	obj->thisCntdownTimestamp0 = CpuTimer0Regs.TIM.all;

	if(obj->timeBase == DISPR_TimebaseIsAdc)
	{
		obj->adc->ADCINTFLGCLR.bit.ADCINT1 = 1;	// clear ADCINT1 flag reinitialize for next SOC
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // acknowledge interrupt to PIE
		IER |= M_INT1;
	}
	else if (obj->timeBase == DISPR_TimebaseIsPwm)
	{
		obj->ePwm->ETCLR.bit.INT = 1;  // clear INT flag for this timer
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP3; // acknowledge interrupt to PIE
		IER |= M_INT3;
	}
	else
	{
		// timer
		CpuTimer0Regs.TCR.bit.TIF = 1;  // clear interrupt flag (seems to be optional)
		PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // acknowledge interrupt to PIE
		IER |= M_INT1;
	}

	if(obj->powerupCountdown > 0)
	{
		obj->powerupCountdown--;
		return;
	}

	obj->interruptNesting++;
	ASSERT(obj->interruptNesting <= 2);

	PIL_beginInterruptCall();
	obj->thisCntdownTimestamp1 = CpuTimer0Regs.TIM.all;

	// re-enable interrupt to allow sub-task to be interrupted
	EINT;

	obj->tsk1(); // this task is always dispatched

	obj->thisCntdownTimestamp2 = CpuTimer0Regs.TIM.all;

	// update values of worst-case latency and margin
	if(obj->cntdownTimestamp1 > obj->thisCntdownTimestamp1)
	{
		// keep in mind that cpu timer is counting down
		obj->cntdownTimestamp1 = obj->thisCntdownTimestamp1;
	}
	if(obj->cntdownTimestamp2 > obj->thisCntdownTimestamp2)
	{
		// keep in mind that cpu timer is counting down
		obj->cntdownTimestamp2 = obj->thisCntdownTimestamp2;
	}

	bool dispatchTask2 = (obj->task2DispatchTimer == 0);
	obj->task2DispatchTimer++;
	if(obj->task2DispatchTimer >= obj->task2DispatchPeriod)
	{
		obj->task2DispatchTimer = 0;
	}

	if(dispatchTask2)
	{
		ASSERT(!obj->task2Active);
		obj->task2Active = true;
		obj->tsk2();
		obj->task2Active = false;
	}

	DINT; // // TI expects interrupts are disabled before entering I$$REST
	obj->interruptNesting--;
}

void DISPR_background()
{
	; // perform latency and margin calculations here
}
