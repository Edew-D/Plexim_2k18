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
#include "dispatcher.h"

void PilCallback(PIL_CtrlCallbackReq_t aCallbackReq)
{
	switch(aCallbackReq)
	{
		case  PIL_CLBK_ENTER_NORMAL_OPERATION_REQ:
			// enabling the hardware actuation (if desired by user)
			PIL_inhibitPilSimulation();
			return;

		case PIL_CLBK_LEAVE_NORMAL_OPERATION_REQ:
			// stopping the hardware actuation or invoking a transfer to a safe system state
			PIL_allowPilSimulation();
			return;

		case PIL_CLBK_INITIALIZE_SIMULATION:
			DISPR_reset();
			return;

		case PIL_CLBK_TERMINATE_SIMULATION:
		     //Termination Request
			 PilInitCalibrations();
		     break;

		case PIL_CLBK_STOP_TIMERS:
			// stopping relevant timers
			EALLOW;
			SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 0;
			SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 0;
			SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 0;
			SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 0;
			SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 0;
			SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 0;
			EDIS;
			return;

		case PIL_CLBK_START_TIMERS:
			// starting relevant timers
			EALLOW;
			SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;
			SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1;
			SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1;
			SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1;
			SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;
			SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;
			EDIS;
			return;
   }
}

