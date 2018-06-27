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

#ifndef ANALOGIN_H_
#define ANALOGIN_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @brief Setup of the n-th analog input.
 * 
 *	
 * @param n ID of analog input.
 * @param scale Scaling factor.
 * @param offset Offset.
 */
void setupAnalogIn(int n, float scale, float offset);

/**
* @brief Returns the conversion result of the n-th analog input.
 * 
 *	
 * @param n ID of analog input.
 */   
#define getAnalogIn(n) (*(ADCInput + n))

#ifdef __cplusplus
}
#endif

#endif /* ANALOGIN_H_ */
