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

#include "power.h"

#pragma diag_suppress 179 // enter_PS_FSM_STATE_CRITICAL_FAULT declared but not referenced

#define PS_ENABLE_DELAY_MS 100

typedef bool (*WriteInterlockPtr_t)(uint16_t flag);
extern PIL_setWriteInterlockHandler(WriteInterlockPtr_t writeIntLockPtr);

// singleton (cause PIL framework still singleton)
PWR_Obj_t PWR_SObj;
static PWR_Handle_t PWR_SHandle;

bool PWR_CalibWriteInterlock(uint16_t flag);

void PWR_sinit()
{
	PWR_SHandle = (PWR_Handle_t)&PWR_SObj;
}

void PWR_configure(GDRV_Handle_t aGateDrvHandle, uint16_t aFsmExecRateHz)
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;
	obj->gdrvHandle = aGateDrvHandle;

	obj->fsmExecRateHz = aFsmExecRateHz;

	PWR_unregisterAllPwmChannels();
	PIL_setWriteInterlockHandler(PWR_CalibWriteInterlock);

	obj->pilMode = false;
	obj->gdrvInitReq = true;
	obj->gdrvStatus = 0;
	obj->calibsAreDirty = false;

	GDRV_powerup(obj->gdrvHandle);
	PWR_reset();
}

void PWR_unregisterAllPwmChannels()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	obj->numRegisteredPwmChannels = 0;
}

void PWR_registerPwmChannel(PWM_Handle_t aChannel)
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	ASSERT(obj->numRegisteredPwmChannels < PWR_MAX_PWM_CHANNELS);
	obj->pwmChannels[obj->numRegisteredPwmChannels] = aChannel;
	obj->numRegisteredPwmChannels++;
}

void PWR_reset()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	obj->gatesActive = false;
	obj->state = PWR_STATE_POWERUP;
	obj->enableReq = false;
	obj->errorCode = PWR_ERR_NONE;
}

void PWR_fsm()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	if(obj->gdrvStatus <= 0)
	{
		// DRV830x not ready
		return;
	}

	switch(obj->state)
	{
		// powerup
		case PWR_STATE_POWERUP:
			if(!obj->enableReq)
			{
				goto enter_PS_FSM_STATE_DISABLED;
			}
			break;

		// disabled
		enter_PS_FSM_STATE_DISABLED:
			GDRV_disable(obj->gdrvHandle);
			obj->state = PWR_STATE_DISABLED;
		break;
		case PWR_STATE_DISABLED:
			if(obj->enableReq)
			{
				goto enter_PS_FSM_STATE_ENABLING;
			}
			break;

		// enabling
		enter_PS_FSM_STATE_ENABLING:
			obj->calibsAreDirty = false; // we assume higher level FSM has dealt with dirty calibs
			obj->state = PWR_STATE_ENABLING;
			if(obj->pilMode != true)
			{
				GDRV_enable(obj->gdrvHandle);
				obj->timer = obj->fsmExecRateHz/1000 * PS_ENABLE_DELAY_MS; // for charge-pump to reach steady-state
				if(obj->timer < 1)
				{
					obj->timer = 1; // enforce minimal delay
				}
			}
			else
			{
				obj->timer = 0;
			}
			break;
		case PWR_STATE_ENABLING:
			if(obj->timer == 0)
			{
				goto enter_PS_FSM_STATE_ENABLED;
			}
			else
			{
				obj->timer--;
			}
			break;

		// enabled
		enter_PS_FSM_STATE_ENABLED:
			// enable powerstage
			obj->state = PWR_STATE_ENABLED;
		break;
		case PWR_STATE_ENABLED:
			// check for fault
			if(GDRV_hasFaulted(obj->gdrvHandle))
			{
				goto enter_PS_FSM_STATE_FAULT;
			}
			if(!obj->enableReq)
			{
				goto enter_PS_FSM_STATE_DISABLED;
			}
			break;

		// fault
		enter_PS_FSM_STATE_FAULT:
			PWR_disableSwitching();
			GDRV_disable(obj->gdrvHandle);
			obj->state = PWR_STATE_FAULT;
		break;
		case PWR_STATE_FAULT:
			if(!obj->enableReq)
			{
				goto enter_PS_FSM_STATE_FAULT_ACKN;
			}
			break;

		// critical fault
		enter_PS_FSM_STATE_CRITICAL_FAULT:
			PWR_disableSwitching();
			GDRV_disable(obj->gdrvHandle);
			obj->state = PWR_STATE_CRITICAL_FAULT;
		break;
		case PWR_STATE_CRITICAL_FAULT:
			// no way out
			break;

		// fault acknowledge
		enter_PS_FSM_STATE_FAULT_ACKN:
			obj->state = PWR_STATE_FAULT_ACKN;
			break;
		case PWR_STATE_FAULT_ACKN:
			// reset gate driver here...
			goto enter_PS_FSM_STATE_DISABLED;
	}
}

void PWR_background()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	if(obj->gdrvInitReq)
	{
		if(GDRV_setup(obj->gdrvHandle))
		{
			obj->gdrvStatus = 1;
		}
		else
		{
			obj->gdrvStatus = -1;
		}
		obj->gdrvInitReq = false;
	}
}

void PWR_enable(bool aEnable)
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	obj->enableReq = aEnable;
}

bool PWR_isSafe()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	return ((obj->state != PWR_STATE_ENABLED) && (obj->state != PWR_STATE_ENABLING));
}

bool PWR_isReadyForEnable()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	return (obj->state == PWR_STATE_DISABLED);
}

bool PWR_isEnabled()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	return (obj->state == PWR_STATE_ENABLED);
}

bool PWR_calibsAreDirty()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	return obj->calibsAreDirty;
}

void PWR_disableSwitching()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	// disable actuators
	int i;
	for(i=0; i<	obj->numRegisteredPwmChannels; i++)
	{
		PWM_disableOut(obj->pwmChannels[i]);
	}
 	obj->gatesActive = false;
}

void PWR_enableSwitching()
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	if(obj->state != PWR_STATE_ENABLED)
	{
		return;
	}

	if(obj->pilMode == false)
	{
		// enable actuators
		int i;
		for(i=0; i<	obj->numRegisteredPwmChannels; i++)
		{
			PWM_enableOut(obj->pwmChannels[i]);
		}
	}
	obj->gatesActive = true;
}

void PWR_setPilMode(bool pilMode)
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	obj->pilMode = pilMode;
	if(pilMode)
	{
		PWR_disableSwitching();
	}
}

static bool PWR_CalibWriteInterlock(uint16_t flag)
{
	PWR_Obj_t *obj = (PWR_Obj_t *)PWR_SHandle;

	// we always allow calibration changes in PIL mode
	if(obj->pilMode == true)
	{
		return true;
	}

	// we never allow calibrations when powerstage is active
	if(!PWR_isSafe()){
		return false;
	}

	obj->calibsAreDirty = true;
	return true;
}
