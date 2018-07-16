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

#ifndef PWM_H_
#define PWM_H_

#include "pwm_impl.h" // implementation specific

extern void PWM_sinit();

extern PWM_Handle_t PWM_init(void *aMemory, const size_t aNumBytes);

extern void PWM_setDefaultParams(PWM_Params_t *aParams);

extern void PWM_configure(PWM_Handle_t aHandle, uint16_t aModulator, const PWM_Params_t *aParams);

extern void PWM_setCompare(PWM_Handle_t aHandle, uint16_t aCompare);

extern uint32_t PWM_getPeriod(PWM_Handle_t aHandle);

extern uint32_t PWM_getCounter(PWM_Handle_t aHandle);

extern bool PWM_getCountDirection(PWM_Handle_t aHandle);

extern void PWM_enableOut(PWM_Handle_t aHandle);

extern void PWM_disableOut(PWM_Handle_t aHandle);

#endif /* PWM_H_ */
