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

/*
 * TODO:
 */

#include "includes.h"
#include "pil.h"

#include "gatedriver.h"
#include "pwm.h"

#ifndef PWR_H_
#define PWR_H_

#include "power_impl.h"

extern void PWR_sinit();

extern void PWR_configure(GDRV_Handle_t aGateDrvHandle, uint16_t aFsmExecRateHz);
extern void PWR_unregisterAllPwmChannels();
extern void PWR_registerPwmChannel(PWM_Handle_t aChannel);

extern void PWR_reset();
extern void PWR_fsm();
extern void PWR_background();
extern void PWR_enable(bool aEnable);
extern bool PWR_isSafe();
extern bool PWR_isReadyForEnable();
extern bool PWR_isEnabled();
extern bool PWR_calibsAreDirty();
extern void PWR_disableSwitching();
extern void PWR_enableSwitching();
extern void PWR_setPilMode(bool pilMode);

#endif /* PWR_H_ */
