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

#ifndef GDRV_IMPL_H_
#define GDRV_IMPL_H_

typedef enum {
	GDRV_Pin_FaultIn,
	GDRV_Pin_OctwIn,
	GDRV_Pin_WakeOut,
	GDRV_Pin_EnableOut,
	GDRV_Pin_DcCalOut

} GDRV_PinId_t;

typedef struct GDRV_OBJ
{
	SPI_Handle_t spiHandle;
	DIO_Handle_t dOutSpiCsHandle;

	DIO_Handle_t dInFaultHandle;
	DIO_Handle_t dInOctwHandle;
	DIO_Handle_t dOutWakeHandle;
	DIO_Handle_t dOutEnableHandle;
	DIO_Handle_t dOutDcCalHandle;

	PIL_READ_PROBE(uint16_t, drvStat1, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvStat2, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvStat3, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvStat4, 0, 1.0, "");

	PIL_READ_PROBE(uint16_t, drvCtrl1, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrl2, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrl5, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrl6, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrl7, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrl9, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrlA, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrlB, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, drvCtrlC, 0, 1.0, "");
} GDRV_Obj_t;

typedef GDRV_Obj_t *GDRV_Handle_t;

#endif /* GDRV_IMPL_H_ */
