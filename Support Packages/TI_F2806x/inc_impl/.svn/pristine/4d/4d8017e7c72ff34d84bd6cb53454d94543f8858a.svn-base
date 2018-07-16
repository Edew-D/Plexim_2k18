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

#ifndef PWR_IMPL_H_
#define PWR_IMPL_H_

#define PWR_MAX_PWM_CHANNELS 6

typedef enum
{
	PWR_STATE_POWERUP,
	PWR_STATE_DISABLED,
	PWR_STATE_ENABLING,
	PWR_STATE_ENABLED,
	PWR_STATE_FAULT,
	PWR_STATE_FAULT_ACKN,
	PWR_STATE_CRITICAL_FAULT
} PWR_FsmState_t;

typedef enum
{
	PWR_ERR_NONE,
	PWR_GDRV_ERROR,
	PWR_ERR_UNKNOWN
} PWR_Error_t;

typedef struct PWR_OBJ
{
	GDRV_Handle_t gdrvHandle;
	uint16_t timer;
	uint16_t fsmExecRateHz;

	uint16_t numRegisteredPwmChannels;
	PWM_Handle_t pwmChannels[PWR_MAX_PWM_CHANNELS];

	PIL_READ_PROBE(int16_t, pilMode, 0, 1, "");
	PIL_READ_PROBE(int16_t, state, 0, 1, "");
	PIL_READ_PROBE(uint16_t, gdrvInitReq, 0, 1, "");
	PIL_READ_PROBE(int16_t, gdrvStatus, 0, 1, "");
	PIL_READ_PROBE(uint16_t, enableReq, 0, 1, "");
	PIL_READ_PROBE(uint16_t, errorCode, 0, 1, "");
	PIL_READ_PROBE(uint16_t, gatesActive, 0, 1, "");
	PIL_READ_PROBE(uint16_t, calibsAreDirty, 0, 1, "");
} PWR_Obj_t;

typedef PWR_Obj_t *PWR_Handle_t;

#endif /* PWR_IMPL_H_ */
