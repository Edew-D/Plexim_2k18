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

#include "pwm.h"

#pragma diag_suppress 112 // ASSERT(0) in switch statements

PWM_SObj_t PWM_SObj;

void PWM_sinit()
{
	EALLOW;
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1; // ePWM1
	SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1; // ePWM1
	SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1; // ePWM1
	SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1; // ePWM4
	SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;	// ePWM5
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;	// ePWM6

	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
	EDIS;
}

void PWM_getRegisterBase(PWM_Unit_t aPwmChannel, volatile struct EPWM_REGS** aReg){
	switch(aPwmChannel)
	{
		default:
			ASSERT(0);
			break;
		case PWM_EPWM1:
			*aReg = &EPwm1Regs;
			break;
		case PWM_EPWM2:
			*aReg = &EPwm2Regs;
			break;
		case PWM_EPWM3:
			*aReg = &EPwm3Regs;
			break;
		case PWM_EPWM4:
			*aReg = &EPwm4Regs;
			break;
		case PWM_EPWM5:
			*aReg = &EPwm5Regs;
			break;
		case PWM_EPWM6:
			*aReg = &EPwm6Regs;
			break;
		case PWM_EPWM7:
			*aReg = &EPwm7Regs;
			break;
		case PWM_EPWM8:
			*aReg = &EPwm8Regs;
			break;
	}
}

void PWM_setDefaultParams(PWM_Params_t *aParams)
{
	aParams->TBPRD = 0;
	aParams->DBFED = 0;
	aParams->DBRED = 0;
	aParams->TBCTL.bit.SYNCOSEL = TB_SYNC_IN;

	aParams->TBPHS.half.TBPHS = 0; // set Phase register to zero
	aParams->TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // symmetrical mode
	aParams->TBCTL.bit.PHSEN = TB_DISABLE; // master module
	aParams->TBCTL.bit.PRDLD = TB_SHADOW;
	aParams->CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	aParams->CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	aParams->CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // load on CTR=Zero
	aParams->CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; // load on CTR=Zero
	aParams->AQCTLA.bit.CAU = AQ_SET; // set actions for EPWM1A
	aParams->AQCTLA.bit.CAD = AQ_CLEAR;
	aParams->DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // enable Dead-band module
	aParams->DBCTL.bit.POLSEL = DB_ACTV_HIC; // active Hi complementary
	aParams->TZCTL.bit.TZA = TZ_FORCE_LO;
	aParams->TZCTL.bit.TZB = TZ_FORCE_LO;

	aParams->ETSEL.bit.SOCASEL = ET_CTR_ZERO;
	aParams->ETSEL.bit.INTSEL = ET_CTR_ZERO;
}

PWM_Handle_t PWM_init(void *aMemory, const size_t aNumBytes)
{
	PWM_Handle_t handle;

	if(aNumBytes < sizeof(PWM_Obj_t))
		return((PWM_Handle_t)NULL);

	// set handle
	handle = (PWM_Handle_t)aMemory;

	return handle;
}

void PWM_configure(PWM_Handle_t aHandle, uint16_t aModulator, const PWM_Params_t *aParams)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;

	ASSERT(aModulator >= 1);
	ASSERT(aModulator <= 6);

	obj->cmprProbe = (uint16_t *)&PWM_SObj.cmp + sizeof(uint16_t)*(aModulator-1);

	// TODO: Use PWM_getRegisterBase
	switch(aModulator)
	{
		default:
		case 1:
			obj->pwm = &EPwm1Regs;
			break;
		case 2:
			obj->pwm = &EPwm2Regs;
			break;
		case 3:
			obj->pwm = &EPwm3Regs;
			break;
		case 4:
			obj->pwm = &EPwm4Regs;
			break;
		case 5:
			obj->pwm = &EPwm5Regs;
			break;
		case 6:
			obj->pwm = &EPwm6Regs;
			break;
	}

	EALLOW;

	obj->pwm->TBPRD = aParams->TBPRD;
	obj->pwm->DBFED = aParams->DBFED;
	obj->pwm->DBRED = aParams->DBRED;
	obj->pwm->TBCTL.bit.SYNCOSEL = aParams->TBCTL.bit.SYNCOSEL;

	obj->pwm->TBPHS.half.TBPHS = aParams->TBPHS.half.TBPHS;
	obj->pwm->TBCTL.bit.CTRMODE = aParams->TBCTL.bit.CTRMODE;
	obj->pwm->TBCTL.bit.PHSEN = aParams->TBCTL.bit.PHSEN;
	obj->pwm->TBCTL.bit.PRDLD = aParams->TBCTL.bit.PRDLD;
	obj->pwm->CMPCTL.bit.SHDWAMODE = aParams->CMPCTL.bit.SHDWAMODE;
	obj->pwm->CMPCTL.bit.SHDWBMODE = aParams->CMPCTL.bit.SHDWBMODE;
	obj->pwm->CMPCTL.bit.LOADAMODE = aParams->CMPCTL.bit.SHDWAMODE;
	obj->pwm->CMPCTL.bit.LOADBMODE = aParams->CMPCTL.bit.SHDWBMODE;
	obj->pwm->AQCTLA.bit.CAU = aParams->AQCTLA.bit.CAU;
	obj->pwm->AQCTLA.bit.CAD = aParams->AQCTLA.bit.CAD;
	obj->pwm->DBCTL.bit.OUT_MODE = aParams->DBCTL.bit.OUT_MODE;
	obj->pwm->DBCTL.bit.POLSEL = aParams->DBCTL.bit.POLSEL;
	obj->pwm->TZCTL.bit.TZA = aParams->TZCTL.bit.TZA;
	obj->pwm->TZCTL.bit.TZB = aParams->TZCTL.bit.TZB;

	obj->pwm->ETSEL.bit.SOCASEL = aParams->ETSEL.bit.SOCASEL;
	obj->pwm->ETSEL.bit.INTSEL = aParams->ETSEL.bit.INTSEL;

	// make sure all is off
	obj->pwm->TZFRC.bit.OST=1;

	switch(aModulator)
	{
		default:
		case 1:
			GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;
			break;
		case 2:
			GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;
			break;
		case 3:
			GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;
			break;
		case 4:
			GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;
			break;
		case 5:
			GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;
			break;
		case 6:
			GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;
			break;
	}

	EDIS;
}

void PWM_setCompare(PWM_Handle_t aHandle, uint16_t aCompare)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;

	*(obj->cmprProbe) = aCompare;
	obj->pwm->CMPA.half.CMPA = aCompare;
}
