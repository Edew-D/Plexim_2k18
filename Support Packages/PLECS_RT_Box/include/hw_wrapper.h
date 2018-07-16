/*
 * hw_wrapper.h
 *
 *  Created on: Dec 23, 2014
 *      Author: Oliver
 */

#ifndef HW_WRAPPER_H_
#define HW_WRAPPER_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef int PLX_BOOL;
enum
{
   FALSE,
   TRUE
};

typedef enum
{
   SUCCESS,
   FAILURE
} Status;

typedef enum
{
   VOUT_3V3,
   VOUT_5V0
} DigitalOutVoltage;

typedef enum
{
   V_AIN_10V,
   V_AIN_5V
} AnalogInputVoltage;

typedef enum
{
   PWM_NEGATIVE_POLARITY,
   PWM_POSITIVE_POLARITY
} PWMPolarity;

typedef enum
{
   WAIT_TIMEOUT,
   WAIT_CONDITION
} WaitResult;

struct VersionType {
   int mVersionMajor;
   int mVersionMinor;
   int mVersionPatch;
};
extern const struct VersionType hilLibraryVersion;

struct OcmSharedData {
    uint32_t mDacSpan;
    uint32_t mHardwareVersion;
    uint32_t mFlags;
};
extern struct OcmSharedData* const ocmSharedData;


typedef uint32_t u32;
typedef int32_t s32;
typedef int16_t s16;
typedef uint16_t u16;
typedef uint8_t u8;


int initSystem();
int postInitCode(void);
int checkFPGAVersion();
void freeCache(void);
int setupDma(void);
int setupTimer(double aStepSize);
void plxSetBufferAdresses();
void plxSetupDataOffsets();
void setLed(int value);
void enableDigitalOutputs(PLX_BOOL aValue);
void enableOutputVoltages(PLX_BOOL aValue);
void setDigitalOutVoltage(DigitalOutVoltage aValue);
void setAnalogInputVoltage(AnalogInputVoltage aValue);
void initPerformanceCounter(void);
unsigned int readPerformanceCounter(void);
u32 getCpuFreq();
int usleep(unsigned int useconds);
void xil_printf(const char *ctrl1, ...);
void print(const char *text);
void clearIRQ();
PLX_BOOL startAfterFirstTrigger();
void waitForIrqAck();
void plxResetPeripherals();
u32 time2ticks(double aTime);
void plxSyncIOBuffers();

void stopTimer(void);
void startTimer(void);

void enterCriticalSection(void);
void exitCriticalSection(void);

typedef int (*WaitCriteria)(void);
WaitResult plxWait(int aMSecs, WaitCriteria aCriteria);

extern float * DACOutput;
extern u16 * PWMOutput;
extern u32 * ENCOutput;
extern float * SFPOutput;
extern u16 * SPIOutput0;
extern u16 * SPIOutput1;
extern volatile u32 * DiffEncInput;
extern volatile u32 * DigitalInput;
extern volatile u16 * TotalCountPWM;
extern volatile u16 * ActiveCountPWM;
extern volatile u8 * EventCountPWM;
extern volatile float * ADCInput;
extern volatile float * PWMCycleRate;
extern volatile float * SFPInput;
extern volatile u16 * SPIInputState;
extern volatile u16 * SPIInput0;
extern volatile u16 * SPIInput1;
extern const u16 PLX_INITIAL_DMA_TX_BUF_LEN;
extern const u16 PLX_INITIAL_DMA_RX_BUF_LEN;

void plxSetupAnalogSampling(u32 aMode, u32 aTicks, double aStepSize);

#ifdef __cplusplus
}
#endif

#endif /* HW_WRAPPER_H_ */
