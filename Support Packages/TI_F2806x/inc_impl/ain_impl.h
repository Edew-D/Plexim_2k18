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

#ifndef AIN_IMPL_H_
#define AIN_IMPL_H_

#define AIN_NUM_CHANNELS 16

typedef enum AIN_UNIT {
	AIN_ADC=0
} AIN_Unit_t;

typedef struct AIN_ADC_RESULT_OVERRIDE {
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT0, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT1, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT2, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT3, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT4, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT5, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT6, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT7, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT8, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT9, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT10, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT11, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT12, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT13, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT14, 0, 1.0, "");
	PIL_OVERRIDE_PROBE(uint16_t, ADCRESULT15, 0, 1.0, "");
} AIN_Adc_Result_Override_t;

typedef struct AIN_ADC_PARAMS {
	union INTSEL1N2_REG INTSEL1N2;
	union ADCCTL1_REG ADCCTL1;
	union ADCCTL2_REG ADCCTL2;
	union SOCPRICTL_REG	SOCPRICTL;
} AIN_AdcParams_t;

typedef struct AIN_CHANNEL_PARAMS {
	union ADCSOCxCTL_REG ADCSOCxCTL;
} AIN_ChannelParams_t;

typedef struct AIN_OBJ
{
	volatile struct ADC_REGS *adc;
	union ADCSOCxCTL_REG *socCtrl;
	volatile uint16_t *results;
	AIN_Adc_Result_Override_t ovrd;

} AIN_Obj_t;

typedef AIN_Obj_t *AIN_Handle_t;

extern void AIN_getRegisterBase(AIN_Unit_t aAdcUnit, volatile struct ADC_REGS** aReg);

#endif /* AIN_IMPL_H_ */