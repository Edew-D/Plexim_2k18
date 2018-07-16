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

#include "dio.h"

#pragma diag_suppress 112 // ASSERT(0) in switch statements

typedef struct DIO_SOBJ
{
	volatile uint32_t dummyWriteVar;
	volatile uint32_t dummyReadAllwaysHighVar;
	volatile uint32_t dummyReadAllwaysLowVar;

	DIO_Obj_t dummyWriteObj;
	DIO_Obj_t dummyReadAllwaysHighObj;
	DIO_Obj_t dummyReadAllwaysLowObj;
} DIO_SObj_t;

static DIO_SObj_t DIO_SObj;

void DIO_configure(DIO_Handle_t aHandle, uint16_t aChannel, bool aDirIsOut, bool aInitVal);

void DIO_sinit()
{
	DIO_SObj.dummyWriteObj.dat = &DIO_SObj.dummyWriteVar;
	DIO_SObj.dummyWriteObj.mask = 0;

	DIO_SObj.dummyReadAllwaysHighObj.dat = &DIO_SObj.dummyReadAllwaysHighVar;
	DIO_SObj.dummyReadAllwaysHighObj.mask = 1;

	DIO_SObj.dummyReadAllwaysLowObj.dat = &DIO_SObj.dummyReadAllwaysLowVar;
	DIO_SObj.dummyReadAllwaysLowObj.mask = 1;

	DIO_SObj.dummyReadAllwaysHighVar = 1;
	DIO_SObj.dummyReadAllwaysLowVar = 0;
}

DIO_Handle_t DIO_obtainDummyWrite()
{
	return (DIO_Handle_t)&DIO_SObj.dummyWriteObj;
}

DIO_Handle_t DIO_obtainDummyRead(bool aReadValue)
{
	if(aReadValue)
	{
		return (DIO_Handle_t)&DIO_SObj.dummyReadAllwaysHighObj;
	}
	else
	{
		return (DIO_Handle_t)&DIO_SObj.dummyReadAllwaysLowObj;
	}
}

DIO_Handle_t DIO_init(void *aMemory, const size_t aNumBytes)
{
	DIO_Handle_t handle;

	if(aNumBytes < sizeof(DIO_Obj_t))
		return((DIO_Handle_t)NULL);

	// set handle
	handle = (DIO_Handle_t)aMemory;

	return handle;
}

void DIO_configureIn(DIO_Handle_t aHandle, uint16_t aChannel)
{
	DIO_configure(aHandle, aChannel, false, false);
}

void DIO_configureOut(DIO_Handle_t aHandle, uint16_t aChannel, bool aInitVal)
{
	DIO_configure(aHandle, aChannel, true, aInitVal);
}

static void DIO_configure(DIO_Handle_t aHandle, uint16_t aChannel, bool aDirIsOut, bool aInitVal)
{
	DIO_Obj_t *obj = (DIO_Obj_t *)aHandle;

	// determine registers and masks
	uint16_t group = aChannel / 32;
	uint16_t groupIndex = aChannel % 32;
	uint16_t mux = groupIndex / 16;
	uint16_t muxIndex = groupIndex % 16;

	obj->mask = 1L << groupIndex;
	uint32_t muxMask = 3L << (muxIndex * 2);

	uint32_t *dirReg;
	uint32_t *muxReg;
	switch(group)
	{
		default:
			ASSERT(0);
			break;
		case 0:
			dirReg = (uint32_t *)&GpioCtrlRegs.GPADIR.all;
			obj->dat = &GpioDataRegs.GPADAT.all;
			obj->toggle = &GpioDataRegs.GPATOGGLE.all;
			switch(mux)
			{
				default:
					ASSERT(0);
					break;
				case 0:
					muxReg = (uint32_t *)&GpioCtrlRegs.GPAMUX1.all;
					break;
				case 1:
					muxReg = (uint32_t *)&GpioCtrlRegs.GPAMUX2.all;
					break;
			}
			break;

		case 1:
			dirReg = (uint32_t *)&GpioCtrlRegs.GPBDIR.all;
			obj->dat = &GpioDataRegs.GPBDAT.all;
			obj->toggle = &GpioDataRegs.GPBTOGGLE.all;
			switch(mux)
			{
				default:
					ASSERT(0);
					break;
				case 0:
					muxReg = (uint32_t *)&GpioCtrlRegs.GPBMUX1.all;
					break;
				case 1:
					muxReg = (uint32_t *)&GpioCtrlRegs.GPBMUX2.all;
					break;
			}
			break;
	}

	// set initial value (only relevant for outputs)
	if(aInitVal)
	{
		*obj->dat |= obj->mask;
	}
	else
	{
		*obj->dat &= ~obj->mask;
	}

	// configure hardware
	EALLOW;
	if(aDirIsOut)
	{
		*dirReg |= obj->mask;
	}
	else
	{
		*dirReg &= ~obj->mask;
	}
	*muxReg &= ~muxMask;
	EDIS;
}
