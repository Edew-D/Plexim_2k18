/*
   Copyright (c) 2018 by Plexim GmbH
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

#ifndef EncoderCounter_H_
#define EncoderCounter_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

u32 plxLastEncoderCounterValues[2];

void plxSetupEncoderCounter(int aInstance, unsigned int aMaxCounterValue, int aCounterMode, 
   int aDirection, int aCounterResetType, int aInputType, int aIndexEnable, int aInputA, 
   int aInputB, int aInputI, int aInputNA, int aInputNB, int aInputNI, double aStepTime);
   
void plxEnableEncoderCounter(int aInstance);

#define plxGetEncoderCounter(aInstance) *(DiffEncInput + aInstance * 2)
#define plxGetEncoderDirection(aInstance) (*(DiffEncInput + aInstance * 2 + 1) & 0x01)
#define plxGetEncoderIndex(aInstance) ((*(DiffEncInput + aInstance * 2 + 1) & 0x02) > 0)

float plxGetEncoderSpeed(int aInstance);
   
#ifdef __cplusplus
}
#endif

#endif
