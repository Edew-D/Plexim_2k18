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
 * TODO: implement dummy ports (for safer module initialization)
 */

#include "includes.h"

#ifndef DIO_H_
#define DIO_H_

#include "dio_impl.h" // implementation specific

extern void DIO_sinit();

extern DIO_Handle_t DIO_obtainDummyWrite();
extern DIO_Handle_t DIO_obtainDummyRead(bool aReadValue);

extern DIO_Handle_t DIO_init(void *aMemory, const size_t aNumBytes);
extern void DIO_configureIn(DIO_Handle_t aHandle, uint16_t aChannel);
extern void DIO_configureOut(DIO_Handle_t aHandle, uint16_t aChannel, bool aInitVal);

extern bool DIO_get(DIO_Handle_t aHandle);
extern void DIO_set(DIO_Handle_t aHandle, bool aVal);
extern void DIO_toggle(DIO_Handle_t aHandle);

#endif /* DIO_H_ */
