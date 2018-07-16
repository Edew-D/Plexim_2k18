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

#ifndef PWM_IMPL_H_
#define PWM_IMPL_H_

typedef enum PWM_UNIT {
	PWM_EPWM_NONE=0,
	PWM_EPWM1,
	PWM_EPWM2,
	PWM_EPWM3,
	PWM_EPWM4,
	PWM_EPWM5,
	PWM_EPWM6,
	PWM_EPWM7,
	PWM_EPWM8
} PWM_Unit_t;

typedef struct PWM_CMP_READ_PROBES {
	PIL_READ_PROBE(uint16_t, CMP1, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP2, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP3, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP4, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP5, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP6, 0, 1.0, "");
} PWM_CmpReadProbes_t;

typedef struct PWM_PARAMS {
	Uint16 TBPRD;
	union TBPHS_HRPWM_GROUP TBPHS;
	union TBCTL_REG TBCTL;
	union CMPCTL_REG CMPCTL;
	union AQCTL_REG AQCTLA;
	union DBCTL_REG DBCTL;
	Uint16 DBFED;
	Uint16 DBRED;
	union TZCTL_REG TZCTL;
	union ETSEL_REG ETSEL;
} PWM_Params_t;

typedef struct PWM_SOBJ
{
	PWM_CmpReadProbes_t cmp;
} PWM_SObj_t;

typedef struct PWM_OBJ
{
	uint16_t *cmprProbe;
	volatile struct EPWM_REGS *pwm;
} PWM_Obj_t;

typedef PWM_Obj_t *PWM_Handle_t;

extern void PWM_getRegisterBase(PWM_Unit_t aPwmChannel, volatile struct EPWM_REGS** aReg);

inline uint32_t PWM_getPeriod(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBPRD;
}

inline uint32_t PWM_getCounter(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBCTR;
}

inline bool PWM_getCountDirection(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBSTS.bit.CTRDIR;
}

inline void PWM_enableOut(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	EALLOW;
	obj->pwm->TZCLR.bit.OST=1;
	EDIS;
}

inline void PWM_disableOut(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	EALLOW;
	obj->pwm->TZFRC.bit.OST=1;
	EDIS;
}

#endif /* PWM_IMPL_H_ */
