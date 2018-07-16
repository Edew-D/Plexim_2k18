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
#include "dio.h"
#include "spi.h"

#ifndef GDRV_H_
#define GDRV_H_

#include "gatedriver_impl.h"

extern GDRV_Handle_t GDRV_init(void *aMemory, const size_t aNumBytes);
extern void GDRV_assignSpiPort(GDRV_Handle_t aHandle, SPI_Handle_t aSpiHandle, DIO_Handle_t aDoutSpiCsHandle);
extern bool GDRV_assignPin(GDRV_Handle_t aHandle, GDRV_PinId_t aPinId, DIO_Handle_t aDioHandle);
extern void GDRV_powerup(GDRV_Handle_t aHandle);
extern bool GDRV_setup(GDRV_Handle_t aHandle);

extern void GDRV_enable(GDRV_Handle_t aHandle);
extern void GDRV_disable(GDRV_Handle_t aHandle);
extern bool GDRV_hasFaulted(GDRV_Handle_t aHandle);

#endif /* GDRV_H_ */
