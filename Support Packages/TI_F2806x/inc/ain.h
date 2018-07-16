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

#include "includes.h"
#include "pil.h"

#ifndef AIN_H_
#define AIN_H_

#include "ain_impl.h" // implementation specific

extern void AIN_sinit();

extern AIN_Handle_t AIN_init(void *aMemory, const size_t aNumBytes);

extern void AIN_setDefaultAdcParams(AIN_AdcParams_t *aParams);

extern void AIN_configure(AIN_Handle_t aHandle, AIN_Unit_t aUnit, const AIN_AdcParams_t *aParams);

extern void AIN_resetChannelSetup(AIN_Handle_t aHandle);

extern void AIN_setDefaultChannelParams(AIN_ChannelParams_t *aParams);

extern void AIN_setupChannel(AIN_Handle_t aHandle, uint16_t aChannel, uint16_t aSource, const AIN_ChannelParams_t *aParams);

extern uint16_t AIN_getIn(AIN_Handle_t aHandle, uint16_t aChannel);

#endif /* AIN_H_ */
