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
#ifndef DATA_CAPTURE_H_
#define DATA_CAPTURE_H_

#ifdef __cplusplus
extern "C"
{
#endif

struct PlxDataCaptureRegistry
{
   double* dataBuffer;
   const char* blockName;
   int numSamples;
   int width;
   int triggerCondition;
   double triggerValue;
   int currentReadBuffer;
   int currentWriteBuffer;
   int currentPosition;
   int triggered;
   double lastTriggerValue;
   volatile int bufferFull[2];
   volatile int bufferFullCount;
   volatile int bufferLocked;
};

void plxSetupDataCapture(int aInstance, const char* aComponentPath, int aWidth, int aNumSamples, 
                      double* aDataBuffer, int aTriggerCondition, double aTriggerValue);
void plxUpdateDataCapture(int aInstance, double aTriggerSignal, double* aDataValues);
int plxGetDataCaptureBuffer(int aInstance, void* aDestination);
int plxGetDataCaptureBufferFullCount(int aInstance);
void plxSendDataCaptureInfoResponse(int aMsg, int aInstance, void* aBuffer);
int plxGetNumDataCaptures();

#ifdef __cplusplus
}
#endif

#endif
