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

#include "spi.h"

#pragma diag_suppress 112 // ASSERT(0) in switch statements

#define SPI_REGS_PTR ((struct SPI_REGS *)obj->portHandle)

SPI_Handle_t SPI_init(void *aMemory, const size_t aNumBytes){
	if(aNumBytes < sizeof(SPI_Obj_t))
	{
		return((SPI_Handle_t)NULL);
	}
	SPI_Handle_t handle = (SPI_Handle_t)aMemory;
	return handle;
}

void SPI_configure(SPI_Handle_t aHandle, uint16_t port, uint32_t clk){
	SPI_Obj_t *obj = (SPI_Obj_t *)aHandle;
	obj->port = port;
	obj->clk = clk;
}

void SPI_setupPort(SPI_Handle_t aHandle, uint32_t baudrate, uint16_t charlen, bool pol, bool phase){
	SPI_Obj_t *obj = (SPI_Obj_t *)aHandle;

	EALLOW;
	switch(obj->port){
		default:
			ASSERT(0);
			break;
		case 0:
			obj->portHandle = (uint32_t)&SpiaRegs;
			// enable clock to SCIA
			SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 1;
			// configure pins
			GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;	// 0=GPIO,  1=SPISIMO-A,  2=Resv,  3=TZ2
			GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;	// 0=GPIO,  1=SPISOMI-A,  2=Resv,  3=TZ3
			GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;	// 0=GPIO,  1=SPICLK-A,  2=LINTX-A,  3=XCLKOUT

			GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;   // Enable pull-up on GPIO16 (SPISIMO-A)
			GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;   // Enable pull-up on GPIO17 (SPISOMI-A)
			GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pull-up on GPIO18 (SPICLK-A)

			GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3; // Asynch input GPIO16 (SPISIMO-A)
			GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3; // Asynch input GPIO17 (SPISOMI-A)
			GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3; // Asynch input GPIO18 (SPICLK-A)
			break;

		case 1:
			obj->portHandle = (uint32_t)&SpibRegs;
			// enable clock to SCIA
			SysCtrlRegs.PCLKCR0.bit.SPIBENCLK = 1;
			// configure pins
			GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 3;	// 0=GPIO,  1=TZ3,  2=LINTX-A,  3=SPICLK-B
			GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 3;	// 0=GPIO,  1=ECAP1,  2=Resv,  3=SPISIMO-B
			GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 3;	// 0=GPIO,  1=Resv,  2=Resv,  3=SPISOMI-B
			// enable pull-ups
			GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;
			GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;
			GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;
			// async inputs
			GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;
			GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 3;
			GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 3;
			break;
	}

	uint16_t SPICTLConf;
	uint16_t SPICCRConf;

	// configure register values
	if(phase == 0){
		SPICTLConf = 0x0004;
	} else {
		SPICTLConf = 0x000C;
	}

	if(pol == 0){
		SPICCRConf = 0x0000 + (charlen - 1); /* clock polarity: 0 = inactive */
	} else {
		SPICCRConf = 0x0040 + (charlen - 1); /* clock polarity: 1 = inactive */
	}

	SPI_REGS_PTR->SPICCR.bit.SPISWRESET = 0;
	SPI_REGS_PTR->SPIFFTX.all = 0x8000;
	SPI_REGS_PTR->SPICTL.all = SPICTLConf;
	SPI_REGS_PTR->SPIPRI.all = 0x0020; /* SPI priority high, emulator immediate on */
	SPI_REGS_PTR->SPISTS.all = 0x00e0; /* Clear all status bits */
	SPI_REGS_PTR->SPIBRR =  (Uint16)(obj->clk / baudrate - 1);
	SPI_REGS_PTR->SPICTL.all = SPICTLConf + 2;
	SPI_REGS_PTR->SPICCR.all = SPICCRConf;
	SPI_REGS_PTR->SPICCR.bit.SPISWRESET = 1;

	EDIS;
}

bool SPI_putGetChar(SPI_Handle_t aHandle, unsigned char out, unsigned char *in){
	SPI_Obj_t *obj = (SPI_Obj_t *)aHandle;

	while((SPI_REGS_PTR->SPISTS.all & 0x0020) != 0){  /* is buffer ready? */
		continue;
	}
	SPI_REGS_PTR->SPITXBUF = (out << 8);
	while((SPI_REGS_PTR->SPISTS.all & 0x0040) == 0){  /* is tx/rx over ? */
		continue;
	}
	*in = (SPI_REGS_PTR->SPIRXBUF & 0xFF);
	return true;
}

bool SPI_putGetWord(SPI_Handle_t aHandle, uint16_t out, uint16_t *in){
	SPI_Obj_t *obj = (SPI_Obj_t *)aHandle;

	while((SPI_REGS_PTR->SPISTS.all & 0x0020) != 0){  /* is buffer ready? */
		continue;
	}
	SPI_REGS_PTR->SPITXBUF = out;
	while((SPI_REGS_PTR->SPISTS.all & 0x0040) == 0){  /* is tx/rx over ? */
		continue;
	}
	*in = SPI_REGS_PTR->SPIRXBUF;
	return true;
}
