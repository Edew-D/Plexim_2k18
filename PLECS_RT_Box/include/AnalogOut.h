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

#ifndef ANALOGOUT_H_
#define ANALOGOUT_H_

#include "hw_wrapper.h"
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define DAC_INDEX0 0
#define DAC_INDEX1 4
#define DAC_INDEX2 8
#define DAC_INDEX3 12
#define DAC_INDEX4 2
#define DAC_INDEX5 6
#define DAC_INDEX6 10
#define DAC_INDEX7 14
#define DAC_INDEX8 1
#define DAC_INDEX9 5
#define DAC_INDEX10 9
#define DAC_INDEX11 13
#define DAC_INDEX12 3
#define DAC_INDEX13 7
#define DAC_INDEX14 11
#define DAC_INDEX15 15

/// Defining the hardware limits of all analog outputs.
typedef enum
{
   M00P50,///< 0V up to 5V.
   M00P100,///< 0V up to 10V.
   M50P50,///< -5V up to 5V.
   M100P100,///< -10V up to 10V.
   M25P25,///< -2.5V up to 2.5V.
   M25P75///< -2.5V up to 7.5V.
} DACSpan;

#define inf MAXFLOAT

/**
* @brief Setup of the n-th analog output.
 * 
 *	
 * @param n ID of analog input.
 * @param scale Scaling factor.
 * @param offset Offset.
 * @param min Minimum value to the DAC.
 * @param max Maximum value to the DAC.
 */

#define setupAnalogOut(aChannel, aScale, aOffset, aMin, aMax) \
   _setupAnalogOut(DAC_INDEX##aChannel, aScale, aOffset, aMin, aMax);

void _setupAnalogOut(int aChannel, float aScale, float aOffset, float aMin, float aMax);

/**
* @brief Defines the voltage at the n-th analog output.
 * 
 *	
 * @param n ID of analog output.
 * @param x Voltage at analog output.
 */   

#define setAnalogOut(n, x) *(DACOutput + DAC_INDEX##n) = x;
 
/**
* @brief Global setup for DAC modules.
 * 
 *	
 * @param aSpan DAC output span.
 */ 
int setupDACs(DACSpan aSpan);

/**
 * @brief Enable/Disable DAC outputs.
 * DAC outputs are disabled by default.  
 *
 * @param aValue Outputs are disabled when set to FALSE, enabled when set to TRUE.
 */ 
void enableAnalogOutputs(PLX_BOOL aValue);


#ifdef __cplusplus
}
#endif

#endif /* ANALOGOUT_H_ */
