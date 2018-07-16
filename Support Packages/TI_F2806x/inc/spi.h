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

#ifndef SPI_H_
#define SPI_H_

#include "spi_impl.h" // implementation specific

extern SPI_Handle_t SPI_init(void *aMemory, const size_t aNumBytes);
extern void SPI_configure(SPI_Handle_t aHandle, uint16_t port, uint32_t clk);
extern void SPI_setupPort(SPI_Handle_t aHandle, uint32_t baudrate, uint16_t charlen, bool pol, bool phase);
extern bool SPI_putGetChar(SPI_Handle_t aHandle, unsigned char out, unsigned char *in);
extern bool SPI_putGetWord(SPI_Handle_t aHandle, uint16_t out, uint16_t *in);

#endif /* SPI_H_ */
