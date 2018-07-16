/*
   Copyright (c) 2016 by Plexim GmbH
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
#ifndef DIGITAL_OUT_H_
#define DIGITAL_OUT_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern u32 DigitalOutReg;

/// Defining the signal forwarded to digital output n.
typedef enum
{
   DO_GPIO,  ///<GPIOn.
   DO_PWM,   ///<PWMn.
   DO_ENC1A, ///<ENC1A.
   DO_ENC1B, ///<ENC1B.
   DO_ENC1I, ///<ENC1I.
   DO_ENC2A, ///<ENC2A.
   DO_ENC2B, ///<ENC2B.
   DO_ENC2I ///<ENC2I.
} DOMAP_MUX;

/// Defining an inversion of the signal at digital output n.
typedef enum
{
   DO_NINV, ///<Not inverted.
   DO_INV ///<Inverted.
} DOMAP_INV;

/// Defining the configuration structure for PWM output
typedef struct 
{
  u16 Prd[32]; ///<Period.
  u16 Delay[32]; ///<Turn-on Delay.
  u16 Shft[32]; ///<Phase shift.
  u16 Aux[32]; ///<Other configurations.
} PWMCONFIG_TYPE;

/// Defining the polarity of the PWM output
typedef enum
{
   NORM, ///<Normal.
   INVS  ///<Inversed.
} POLAR_TYPE;

/// Defining the type of carrier wave of PWM output
typedef enum
{
   SAWTOOTH, ///<Saw tooth.
   SYMMETRIC ///<Symmetrical.
} CARRIER_TYPE;

/// Defining the type of compare value update of PWM output
typedef enum
{
   PLX_CARRIER_MIN, 
   PLX_IMMEDIATE,
   PLX_CARRIER_MAX,
   PLX_CARRIER_MIN_MAX
} UPDATE_TYPE;

/// Defining enable/disable of synchronised PWM generation
typedef enum
{
   DISABLE, ///<Asynchronised
   ENABLE   ///<Synchronised
} SYNC_TYPE;

/// Defining master or slave mode
typedef enum
{
   MST, ///<Asynchronised
   SLV   ///<Synchronised
} SLV_TYPE;

/**
* @brief Defines the signal forwarded to digital output n and if it is inverted.
 * 
 *	
 * @param aID ID of digital output n.
 * @param aConfig  Specifies signal forwarded.
 * @param aInv Specifies signal inversion.
 */
void setupDigitalOut(int aID, DOMAP_MUX aConfig, DOMAP_INV aInv);

/**
* @brief Reinitialization of the DOMAP module.
* 
* Should be called previous to the setupDigitalOut section.
* 
*/
int initDigitalOut(void);

/**
* @brief Sets the n-th digital output to logically high.
 * 
 * Note that those changes wont take any effect without a syncDigitalOuts call.
 *	
 * @param n ID of digital output.
 */
#define setDigitalOut(n) (DigitalOutReg |= (1 << n))

/**
* @brief Sets the n-th digital output to logically low.
 * 
 * Note that those changes wont take any effect without a syncDigitalOuts call.
 *	
 * @param n ID of digital output.
 */
#define clearDigitalOut(n) (DigitalOutReg &= ~((1 << n)))

/**
* @brief Sets the n-th digital output to x.
 * 
 * Note that those changes wont take any effect without a syncDigitalOuts call.
 *	
 * @param n ID of digital output.
 * @param x Defines logical level the output is set to.
 */
#define writeDigitalOut(n, x) \
{ \
    if (x) \
       DigitalOutReg |= (1 << n); \
    else \
       DigitalOutReg &= ~((1 << n)); \
}

/**
* @brief Changes made to the digital outputs are synched.
* 
* 
*/
void syncDigitalOuts();

/**
* @brief Initialization of the PWM generator module.
* 
 * Note that those changes wont take any effect without a updatePWMGen call.
 *	
 * @param aStepSize model step size (in seconds)
 * @param aID ID of PWM output.
 * @param aPrd Period of PWM in prescaled clock cycles.
 * @param aDelay Turn on delay of PWM in prescaled clock cycles
 * @param aShft Phase shift of PWM in prescaled clock cycles
 * @param aPrscl Prescale factor for PWM clock F_PWM = F_CPU/(2^aPrscl) 
 * @param aSlv Slave/master mode
 * @param aMstID ID of the master channel if configured as slave
 * @param aSync Synchronisation with CPU enable
 * @param aPolar polarity of PWM
 * @param aCarrier Type of carrier of PWM
 * @param aUpdate Update type of PWM
 * 
 * @return SUCCESS or FAILURE
 */
int setupPWMGen(u16 aID, u16 aPrd, u16 aDelay, u16 aShft, u16 aPrscl, 
                u16 aUndef, SLV_TYPE aSlv, u16 aMstID, SYNC_TYPE aSync, 
                POLAR_TYPE aPolar, CARRIER_TYPE aCarrier, UPDATE_TYPE aUpdate);

/**
* @brief Update the PWM configurations made by setupPWMGen.
* 
* 
*/
void updatePWMGen();

void enablePWMGen();

/**
* @brief Set compare value for the PWM at the n-th digital output.
 * 
 *	
 * @param n ID of digital output.
 * @param x Compare value for PWM output.
 */   
#define setPWMOutCmp(n, x) \
{ \
		*(PWMOutput + 32 + n*2) = x; \
}

/**
* @brief Set period for the PWM at the n-th digital output.
 * 
 *	
 * @param n ID of analog output.
 * @param x Period for PWM output.
 */   
#define setPWMOutPrd(n, x) \
{ \
		*(PWMOutput + n) = x; \
}

/**
* @brief Set phase shift for the PWM at the n-th digital output.
 * 
 *	
 * @param n ID of analog output.
 * @param x Phase shift for PWM output.
 */   
#define setPWMOutShft(n, x) \
{ \
		*(PWMOutput + 32 + n*2 + 1) = x; \
}

#ifdef __cplusplus
}
#endif

#endif /*DIGITAL_OUT_H_*/

