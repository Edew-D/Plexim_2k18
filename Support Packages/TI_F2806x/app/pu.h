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

#ifndef PU_H_
#define PU_H_

#include "pil.h"

// fixed-point representation for voltages, currents, resistances
#define Q_IV 10
#define R_IV 1024

#define Q_WF 10
#define R_WF 1024

// fixed-point references
#define VDC_REF 36.0
#define I_REF 2.0
#define F_REF 50.0

#define VP_REF  (2.0 / 3.0 * VDC_REF)
#define R_REF   (VP_REF / I_REF)
#define P_REF   (1.5 * VP_REF * I_REF)

#define W_REF (F_REF * 6.2832)
#define L_REF   (R_REF / W_REF)
#define PSI_REF (VP_REF / W_REF)

/* pu globals */
struct PU_VARS {
	uint16_t dummy;
};

extern struct PU_VARS PuVars;

extern void InitPuVars();

#endif /* PU_H_ */
