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

#include "gatedriver.h"

GDRV_Handle_t GDRV_init(void *aMemory, const size_t aNumBytes)
{
	GDRV_Handle_t handle;

	if(aNumBytes < sizeof(GDRV_Obj_t))
		return((GDRV_Handle_t)NULL);

	// set handle
	handle = (GDRV_Handle_t)aMemory;

	GDRV_Obj_t *obj = (GDRV_Obj_t *)handle;
	obj->spiHandle = NULL;

	obj->dInFaultHandle = DIO_obtainDummyRead(true); // never fault
	obj->dOutEnableHandle = DIO_obtainDummyWrite();

	return handle;
}

void GDRV_assignSpiPort(GDRV_Handle_t aHandle, SPI_Handle_t aSpiHandle, DIO_Handle_t aDoutSpiCsHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;
	obj->spiHandle = aSpiHandle;
	obj->dOutSpiCsHandle = aDoutSpiCsHandle;
}

bool GDRV_assignPin(GDRV_Handle_t aHandle, GDRV_PinId_t aPinId, DIO_Handle_t aDioHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;
	switch(aPinId)
	{
		case GDRV_Pin_FaultIn:
			obj->dInFaultHandle = aDioHandle;
			break;
		case GDRV_Pin_EnableOut:
			obj->dOutEnableHandle = aDioHandle;
			break;
		default:
			return false;
	}
	return true;
}

void GDRV_powerup(GDRV_Handle_t aHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;

	DIO_set(obj->dOutEnableHandle, true); // active low
}

bool GDRV_setup(GDRV_Handle_t aHandle)
{
	return true;
}

void GDRV_enable(GDRV_Handle_t aHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;
	DIO_set(obj->dOutEnableHandle, false); // active low
}

void GDRV_disable(GDRV_Handle_t aHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;
	DIO_set(obj->dOutEnableHandle, true); // active low
}

bool GDRV_hasFaulted(GDRV_Handle_t aHandle)
{
	GDRV_Obj_t *obj = (GDRV_Obj_t *)aHandle;
	return (DIO_get(obj->dInFaultHandle) == 0);
}
