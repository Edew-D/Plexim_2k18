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

#ifndef QEP_IMPL_H_
#define QEP_IMPL_H_

typedef struct QEP_OBJ
{
	volatile struct EQEP_REGS *qep;
} QEP_Obj_t;

typedef QEP_Obj_t *QEP_Handle_t;

inline void QEP_sinit(){}

inline uint32_t QEP_getPosCnt(QEP_Handle_t aHandle)
{
	QEP_Obj_t *obj = (QEP_Obj_t *)aHandle;
	return obj->qep->QPOSCNT;
}

inline uint32_t QEP_getPosILatchCnt(QEP_Handle_t aHandle)
{
	QEP_Obj_t *obj = (QEP_Obj_t *)aHandle;
	return obj->qep->QPOSILAT;
}

inline bool QEP_getAndClearIndexFlag(QEP_Handle_t aHandle)
{
	QEP_Obj_t *obj = (QEP_Obj_t *)aHandle;

	bool flag = obj->qep->QFLG.bit.IEL;
	obj->qep->QCLR.bit.IEL = flag;

	return flag;
}

#endif /* QEP_IMPL_H_ */
