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

#include "hal.h"
#include "power.h"

HAL_SObj_t HAL_SObj;

void HAL_sinit()
{
	int i,j;
	DIO_sinit(); // ok to call multiple times
	for(i=0; i<HAL_NUM_DIN_CHANNELS; i++)
	{
		HAL_SObj.inPortHandles[i] = DIO_init(&HAL_SObj.inPortObjs[i],sizeof(HAL_SObj.inPortObjs[i]));
	}
	for(i=0; i<HAL_NUM_DOUT_CHANNELS; i++)
	{
		HAL_SObj.outPortHandles[i] = DIO_init(&HAL_SObj.outPortObjs[i],sizeof(HAL_SObj.outPortObjs[i]));
	}

	PWM_sinit();
	for(i=0; i<HAL_NUM_PWM_CHANNELS; i++)
	{
		HAL_SObj.pwmHandles[i] = PWM_init(&HAL_SObj.pwmObjs[i],sizeof(HAL_SObj.pwmObjs[i]));
	}
	HAL_SObj.lowestPwmResourceConfigured = 0xFFFF;

	QEP_sinit();
	for(i=0; i<HAL_NUM_QEP_CHANNELS; i++)
	{
		HAL_SObj.qepHandles[i] = QEP_init(&HAL_SObj.qepObjs[i],sizeof(HAL_SObj.qepObjs[i]));
	}

	AIN_sinit();
	for(i=0; i<HAL_NUM_ADCS; i++)
	{
		HAL_SObj.aInHandle[i] = AIN_init(&HAL_SObj.aInObjs[i],sizeof(HAL_SObj.aInObjs[i]));
		HAL_SObj.highestSocConfigured[i] = -1;
		for(j=0; j<HAL_NUM_CHANNELS_PER_ADC; j++)
		{
			HAL_SObj.aInChannelIsConfigured[i][j] = false;
			HAL_SObj.aInScale[i][j] = 1.0;
			HAL_SObj.aInOffset[i][j] = 0.0;
		}
	}
}

void HAL_setupDigitalOut(uint16_t aChannel, uint16_t aResourceNumber, bool aInitialValue)
{
	ASSERT(aChannel < HAL_NUM_DOUT_CHANNELS);
	DIO_configureOut(HAL_SObj.outPortHandles[aChannel], aResourceNumber, aInitialValue);
}

void HAL_setupDigitalIn(uint16_t aChannel, uint16_t aResourceNumber)
{
	ASSERT(aChannel < HAL_NUM_DIN_CHANNELS);
	DIO_configureIn(HAL_SObj.inPortHandles[aChannel], aResourceNumber);
}

AIN_AdcParams_t* HAL_getDefaultAdcParams()
{
	AIN_setDefaultAdcParams(&HAL_SObj.aInParamsMemory);
	return &HAL_SObj.aInParamsMemory;
}

void HAL_setupAdc(uint16_t aHandle, uint16_t aAdc, const AIN_AdcParams_t *aInParams)
{
	AIN_configure(HAL_SObj.aInHandle[aHandle], (enum AIN_UNIT)aAdc, aInParams);
	AIN_resetChannelSetup(HAL_SObj.aInHandle[aHandle]);
}

AIN_ChannelParams_t* HAL_getDefaultAinChannelParams()
{
	AIN_setDefaultChannelParams(&HAL_SObj.aInChannelParamsMemory);
	return &HAL_SObj.aInChannelParamsMemory;
}

void HAL_setupAnalogIn(uint16_t aAdc, uint16_t aChannel, uint16_t aResourceNumber, const AIN_ChannelParams_t *aParams)
{
	ASSERT(aAdc < HAL_NUM_ADCS);
	ASSERT(aChannel < HAL_NUM_CHANNELS_PER_ADC);
	ASSERT(!HAL_SObj.aInChannelIsConfigured[aAdc][aChannel]);

	HAL_SObj.aInChannelIsConfigured[aAdc][aChannel] = true;
	if(HAL_SObj.highestSocConfigured[aAdc] < (int)aChannel)
	{
		HAL_SObj.highestSocConfigured[aAdc] = (int)aChannel;
	}

	AIN_setupChannel(HAL_SObj.aInHandle[aAdc], aChannel, aResourceNumber, aParams);
}

void HAL_setupAnalogInF(uint16_t aAdc, uint16_t aChannel, uint16_t aResourceNumber, const AIN_ChannelParams_t *aParams, float scale, float offset)
{
	HAL_setupAnalogIn(aAdc, aChannel, aResourceNumber, aParams);
	HAL_SObj.aInScale[aAdc][aChannel] = scale;
	HAL_SObj.aInOffset[aAdc][aChannel] = offset;
}

PWM_Params_t* HAL_getDefaultPwmParams(uint16_t aPeriodCounts, uint16_t aDeadtimeCounts)
{
	PWM_setDefaultParams(&HAL_SObj.pwmParamsMemory);
	HAL_SObj.pwmParamsMemory.TBPRD = aPeriodCounts;
	HAL_SObj.pwmParamsMemory.DBFED = aDeadtimeCounts;
	HAL_SObj.pwmParamsMemory.DBRED = aDeadtimeCounts;
	return &HAL_SObj.pwmParamsMemory;
}

void HAL_setupPwmOut(uint16_t aChannel, uint16_t aResourceNumber, const PWM_Params_t *aPwmParams)
{
	ASSERT(aChannel < HAL_NUM_PWM_CHANNELS);

	PWM_configure(HAL_SObj.pwmHandles[aChannel], aResourceNumber, aPwmParams);
	PWR_registerPwmChannel(HAL_SObj.pwmHandles[aChannel]);
	if(HAL_SObj.lowestPwmResourceConfigured > aResourceNumber)
	{
		HAL_SObj.lowestPwmResourceConfigured = aResourceNumber;
	}
}

void HAL_setupQep(uint16_t aChannel, uint16_t aResourceNumber, uint16_t aPinSet)
{
	ASSERT(aChannel < HAL_NUM_QEP_CHANNELS);
	QEP_configure(HAL_SObj.qepHandles[aChannel], aResourceNumber, aPinSet);
}

void HAL_configure()
{
	PWR_unregisterAllPwmChannels();
}

bool HAL_getLowestPwmResourceConfigured(uint16_t *aResourceNumber)
{
	if(HAL_SObj.lowestPwmResourceConfigured == 0xFFFF)
	{
		return false;
	}
	*aResourceNumber = HAL_SObj.lowestPwmResourceConfigured;
	return true;
}

bool HAL_getHighestSocConfigured(uint16_t adc, uint16_t *aSoc)
{
	ASSERT(adc < HAL_NUM_ADCS);
	if(HAL_SObj.highestSocConfigured[adc] < 0)
	{
		return false;
	}
	*aSoc = HAL_SObj.highestSocConfigured[adc];
	return true;
}
