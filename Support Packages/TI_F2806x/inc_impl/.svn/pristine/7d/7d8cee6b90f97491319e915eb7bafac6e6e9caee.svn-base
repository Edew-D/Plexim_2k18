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

#ifndef DIO_IMPL_H_
#define DIO_IMPL_H_

typedef struct DIO_OBJ
{
	uint32_t mask;
	volatile uint32_t *dat;
	volatile uint32_t *toggle;
} DIO_Obj_t;

typedef DIO_Obj_t *DIO_Handle_t;

inline bool DIO_get(DIO_Handle_t aHandle)
{
	DIO_Obj_t *obj = (DIO_Obj_t *)aHandle;

	return ((*obj->dat & obj->mask) != 0);
}

inline void DIO_set(DIO_Handle_t aHandle, bool aVal)
{
	DIO_Obj_t *obj = (DIO_Obj_t *)aHandle;

	if(aVal)
	{
		*obj->dat |= obj->mask;
	}
	else
	{
		*obj->dat &= ~obj->mask;
	}
}

inline void DIO_toggle(DIO_Handle_t aHandle)
{
	DIO_Obj_t *obj = (DIO_Obj_t *)aHandle;

	*obj->toggle = obj->mask;
}

#endif /* DIO_IMPL_H_ */
