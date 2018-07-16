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

#ifndef SPI_IMPL_H_
#define SPI_IMPL_H_

/* TI convention:
 * pol/phase = 0/0: inactive level low, slave read at falling edge (transitions at rising edge)
 * pol/phase = 0/1: inactive level low, slave read at rising edge (transitions at falling edge)
 * pol/phase = 1/0: inactive level high, slave read at rising edge (transitions at falling edge)
 * pol/phase = 1/1: inactive level high, slave read at falling edge (transitions at rising edge)
 */

typedef void(*SPI_CsCallbackPtr_t)(bool);

typedef struct SPI_OBJ {
	uint16_t port;
	uint32_t portHandle;
	uint32_t clk;
} SPI_Obj_t;

typedef SPI_Obj_t *SPI_Handle_t;

#endif /* SPI_IMPL_H_ */
