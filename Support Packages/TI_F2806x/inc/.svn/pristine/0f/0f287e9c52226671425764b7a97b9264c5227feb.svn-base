/*
   Copyright (c) 2017 by Plexim GmbH
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

#ifndef EE_H_
#define EE_H_

#include "ee_impl.h" // implementation specific

extern EE_Handle_t EE_init(void *aMemory, const size_t aNumBytes);
extern void EE_configure(EE_Handle_t aHandle, SPI_Handle_t aSpiHandle, DIO_Handle_t aSpiCsHandle);

extern bool_t EE_unlock(EE_Handle_t aHandle);

bool_t EE_beginWrite(EE_Handle_t aHandle, uint32_t aAddress);
bool_t EE_write(EE_Handle_t aHandle, uint16_t *aData, uint16_t aLen);
bool_t EE_endWrite(EE_Handle_t aHandle);

bool_t EE_beginRead(EE_Handle_t aHandle, uint32_t aAddress);
bool_t EE_read(EE_Handle_t aHandle, uint16_t *aData, uint16_t aLen);
bool_t EE_endRead(EE_Handle_t aHandle);

#endif /*EE_H_*/
