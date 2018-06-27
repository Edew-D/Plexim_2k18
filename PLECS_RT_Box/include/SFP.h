/*
   Copyright (c) 2017 by Plexim GmbH
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

#ifndef SFP_H_
#define SFP_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @brief Send value to SFP0 buffer
 * 
 * @param 
 */ 
#define setSFP0Out(n, x) \
{ \
   *(SFPOutput + n) = x; \
}

extern int plxNumOutputSFP0;

/**
 * @brief Send value to SFP1 buffer
 * 
 * @param 
 */ 
#define setSFP1Out(n, x) \
{ \
   *(SFPOutput + plxNumOutputSFP0 + n) = x; \
}

extern int plxNumOutputSFP1;

/**
 * @brief Send value to SFP2 buffer
 * 
 * @param 
 */ 
#define setSFP2Out(n, x) \
{ \
   *(SFPOutput + plxNumOutputSFP0 + plxNumOutputSFP1 + n) = x; \
}

extern int plxNumOutputSFP2;

/**
 * @brief Send value to SFP3 buffer
 * 
 * @param 
 */ 
#define setSFP3Out(n, x) \
{ \
   *(SFPOutput + plxNumOutputSFP0 + plxNumOutputSFP1 + plxNumOutputSFP2 + n) = x; \
}

/**
 * @brief Returns the conversion result of the n-th SFP0 input.
 * 
 *
 * @param n ID of SFP0 input.
 */   
float getSFP0In(int n);

/**
 * @brief Returns the conversion result of the n-th SFP1 input.
 * 
 *
 * @param n ID of SFP1 input.
 */   
float getSFP1In(int n);

/**
 * @brief Returns the conversion result of the n-th SFP2 input.
 * 
 * @param n ID of SFP2 input.
 */   
float getSFP2In(int n);

/**
 * @brief Returns the conversion result of the n-th SFP3 input.
 * 
 *
 * @param n ID of SFP3 input.
 */   
float getSFP3In(int n);

extern int plxNumInputSFP3;

void setupSFP0In(u32 aNumInputs, const float* aInitData);
void setupSFP1In(u32 aNumInputs, const float* aInitData);
void setupSFP2In(u32 aNumInputs, const float* aInitData);
void setupSFP3In(u32 aNumInputs, const float* aInitData);

void setupSFP0Out(u32 aNumOutputs);
void setupSFP1Out(u32 aNumOutputs);
void setupSFP2Out(u32 aNumOutputs);
void setupSFP3Out(u32 aNumOutputs);

void setupSFPSyncMaster(u32 aUseSFPA, u32 aUseSFPB, u32 aUseSFPC, u32 aUseSFPD);
void setupSFPSyncSlave(u32 aMasterChannel, u32 aSyncTime, u32 aSyncStartup);
Status plxWaitForSFPSync();

#ifdef __cplusplus
}
#endif

#endif
