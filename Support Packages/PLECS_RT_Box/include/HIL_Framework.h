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
#ifndef HIL_FRAMEWORK_H_
#define HIL_FRAMEWORK_H_

#include "ScopeBuffer.h"

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(push, 4)

struct PlxArmResponse
{
   int msg;
   int mMsgLength;
   int mTransactionId;
   int mLength;
   float mSampleTime;
   int mBufferIndex;
   int mOffset;
   int mNumActiveSignals;
   unsigned short mActiveSignals[1];
};

struct PlxTriggerInfo
{
   int mTransactionId;
   int mLength;
   int mEdge; 
   float mTriggerValue;
   int mTriggerChannel;
   int mDecimation;
   int mTriggerDelay;
   int mNumActiveSignals;
   unsigned short mActiveSignals[1];
};

void plxStartSimulationModel(double aModelSampleTime, int aFloatSize,
                             int aUseExternalMode, int aNumExtModeSignals,
                             int aNumTunableParameters, void* aTunableParameters, 
                             struct PlxTriggerInfo* aTriggerInfo,
                             struct PlxArmResponse* aArmResponse,
                             const char* aModelChecksum,
                             const char* aModelName);
                                
void plxSetMaxNumConsecutiveOverruns(int aNumOverruns); 

int plxSendRawResponse(void* aMsg, int aSize);

typedef void (*PlxRawCallback)(void* aData, int aSize);
void plxRegisterRawCallback(PlxRawCallback aCallback);

typedef void (*PlxBackgroundTaskCallback)(void);
void plxRegisterBackgroundTask(PlxBackgroundTaskCallback aCallback);
void plxStandaloneBackgroundTask();

extern volatile int scopeArmed;
extern volatile int scopeTriggered;
extern volatile int plxCurrentWriteBuffer;
extern struct ScopeBuffer plxScopeBuffer[];
extern volatile int plxErrorFlag;

#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif
