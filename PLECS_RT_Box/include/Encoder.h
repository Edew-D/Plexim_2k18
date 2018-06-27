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

#ifndef Encoder_H_
#define Encoder_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
   ENC1,
   ENC2
} Encoder_ID;

/**
* @brief Encoder setup.
 * 
 * Called during initialization.
 *	
 * @param aID ID of Encoder.
 * @param aSampleTime Model time step.
 * @param aLinePairs Amount of encoder line pairs.
 * @param aCOD Encoder coding style.
 */
void setupEncoder(Encoder_ID aID, double aSampleTime, u32 aLinePairs, int aCOD);
/**
* @brief Encoder update.
 * 
 * Called with model step.
 *
 * @param aID ID of Encoder.
 * @param aSpeed Motor speed.
 * @param aAngle Motor angle.
 * @param aSpeedDerivative Motor speed derivative.
 */
void updateEncoder(Encoder_ID aID, float aSpeed, float aAngle, float aSpeedDerivative, int aExtrapolation);

#ifdef __cplusplus
}
#endif

#endif /*Encoder_H_*/
