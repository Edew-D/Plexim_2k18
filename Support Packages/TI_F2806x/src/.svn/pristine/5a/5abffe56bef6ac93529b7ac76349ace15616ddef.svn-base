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

#include "qep.h"

QEP_Handle_t QEP_init(void *aMemory, const size_t aNumBytes)
{
	QEP_Handle_t handle;

	if(aNumBytes < sizeof(QEP_Obj_t))
		return((QEP_Handle_t)NULL);

	// set handle
	handle = (QEP_Handle_t)aMemory;

	return handle;
}

void QEP_configure(QEP_Handle_t aHandle, uint16_t aUnit, uint16_t aPinSet)
{
	QEP_Obj_t *obj = (QEP_Obj_t *)aHandle;

	if((aUnit < 1) || (aUnit > 2))
	{
		aUnit = 1;
	}

	EALLOW;
	switch(aUnit)
	{
		default:
		case 1:
			obj->qep = &EQep1Regs;
			SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 1;
			switch(aPinSet)
			{
				default:
				case 0:
					GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;	// 0=GPIO,  1=EQEPA-1,  2=Resv,  3=COMP1OUT
					GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;	// 0=GPIO,  1=EQEPB-1,  2=Resv,  3=COMP2OUT
					GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1;	// 0=GPIO,  1=EQEPI-1,  2=Resv,  3=LINRX-A
					break;
				case 1:
					// enable internal pull-up for the eQEP selected pins
					GpioCtrlRegs.GPBPUD.bit.GPIO50 = 0;
					GpioCtrlRegs.GPBPUD.bit.GPIO51 = 0;
					GpioCtrlRegs.GPBPUD.bit.GPIO53 = 0;

					// synchronize inputs to SYSCLKOUT
					GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0;
					GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0;
					GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0;

					// set muxes
					GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 1;
					GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 1;
					GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 1;
					break;
			}
			break;
	}

	obj->qep->QDECCTL.all = 0;

	obj->qep->QPOSINIT = 0;   // set counter initialization to 0
	obj->qep->QPOSMAX = 0xFFFFFFFF; //<<<< set maximum count value to 1999

	obj->qep->QEPCTL.all = 0;
	obj->qep->QEPCTL.bit.FREE_SOFT = 0; // all QEP timers stop on emulation suspend
	obj->qep->QEPCTL.bit.PCRM = 1; // operate QEP in Reset on Max counter mode
	obj->qep->QEPCTL.bit.SEI = 0; // disable strobe init
	obj->qep->QEPCTL.bit.IEI = 0; // disable index init
	obj->qep->QEPCTL.bit.SWI = 0; // don't allow software to initialize counter
	obj->qep->QEPCTL.bit.SEL = 0; // disable strobe event
	obj->qep->QEPCTL.bit.IEL = 3; //<<<< Latch on index event marker
	obj->qep->QEPCTL.bit.QPEN = 1; //<<<< QEP enable
	obj->qep->QEPCTL.bit.QCLM = 0; // disable EQEP capture latch
	obj->qep->QEPCTL.bit.UTE = 0; // disable unit timer
	obj->qep->QEPCTL.bit.WDE = 0; // disable QEP watchdog

	obj->qep->QPOSCTL.all = 0;   // set eQEP position-compare control unit to the default mode

	obj->qep->QEINT.bit.QDC = 0;   // disable quadrature direction change interrupt
	obj->qep->QEINT.bit.PCO = 0;   // disable position counter overflow interrupt
	obj->qep->QEINT.bit.PCU = 0;   // disable position counter underflow interrupt
	obj->qep->QEINT.bit.PCM = 0;   // disable position compare match interrupt
	obj->qep->QEINT.bit.UTO = 0;   // disable unit time out event interrupt

	EDIS;
}
