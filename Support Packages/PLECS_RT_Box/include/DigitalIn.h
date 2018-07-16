/*
   Copyright (c) 2016 by Plexim GmbH
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

#ifndef DIGITALIN_H_
#define DIGITALIN_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @brief Returns the actual state of digital input n.
 * 
 *	
 * @param n ID of digital input.
 */
#define getDigitalIn(n) ((*DigitalInput >> n) & 1)

/**
* @brief Returns the percentage the digital input n persisted in logically true state during the previous interval.
 * 
 *	
 * @param n ID of digital input. 
 */
#define getDigitalInAveraged(n) ((*(ActiveCountPWM+n))*(*PWMCycleRate))

/**
* @brief Returns the state transitions occured at digital input n during the previous interval.
 * 
 *	This can be used to calculate switching losses. 
 *
 * @param n ID of digital input.
 */
#define getDigitalEdgeCounter(n) (*(EventCountPWM+n))

/**
* @brief Initializes the pwm capture module. 
 * 
 */
void initPWMCapture(void);

/**
* @brief Initializes a channel of the input capture module. 
 * 
 * @param aChannel Defines the channel.
 * @param aPolarity Defines the polarity of a logically true signal.
 */
void setupPWMCaptureChannel(u16 aChannel,PWMPolarity aPolarity);

#ifdef __cplusplus
}
#endif

#endif /* DIGITALIN_H_ */
