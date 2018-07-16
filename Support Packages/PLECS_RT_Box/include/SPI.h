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
 
#ifndef SPI_H_
#define SPI_H_

#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern u32 DigitalOutReg;

extern int plxNumQWordsSPI0;
extern double plxtTransSPI0;
extern double plxDelaySPI0;
extern int plxTrigModeSPI0;

extern int plxNumQWordsSPI1;
extern double plxtTransSPI1;
extern double plxDelaySPI1;
extern int plxTrigModeSPI1;

/// Defining the configuration structure for SPI module
typedef struct 
{
  u8 S_MODE;///<Single/Multi Slave Mode (0,1)
  u8 CLK_SPC1;///<SPI CLK spaces between CS edge and first WR event (1 to 15).
  u8 CLK_SPC2;///<SPI CLK spaces between last RD event and CS edge (1 to 15).
  u8 SPIMODE;///<SPI MODE (00 to 11 (CKPHA, CKPOL)).
  u8 DataBits;///< Bits per character (1-16)
  u8 bitOrder;///< MSB/LSB first (0, 1)
  u8 HS_MODE;///< 0 - SPI_CLK_OUT used for ReaderCLK, 1 - SPI_CLK_IN used for ReaderCLK
  u8 STREAM;///< 0 - Module used as Sequencer, 1 - Module used as Stream(parrallel)
  u8 STRMBR;///< Number of parallel stream signals
  u8 CSACTIVE;///< ACTIVE polarity of CS
  u16 TRGDELAY;
} SPI_CONF;

/**
* @brief Setup the SPI Master.
* 
* 
*/
void setupSPI(int aModule, const SPI_CONF* aConfig, double aClockFrequency, 
              int aNumWordsInput0, int aNumWordsInput1, int aNumWordsInput2);

/**
* @brief Setup a SPI Input Channel.
* 
* ID Map: [D0,D1,D2,D3, CLK,CS0 ,CS1,CS2]
* ID Map: [0, 1, 2 , 3 , 4 , 5 , 6 , 7 ]
*/
void setupSPIInput(int aModule, int aID, int aChannel);

/**
* @brief Setup a SPI Output Channel.
* 
* ID Map: [CLK,DATA0,CS0,CS1/D1,CS2/D2,  D3 ]
* ID Map: [ 0 , 1  , 2 ,   3   ,  4   ,  5  ]
*/
void setupSPIOutput(int aModule,int aID, int aChannel);

/** @brief Send value to SPI buffer 0
 * 
 * @param 
 */ 
#define setSPIOut0(n, x) \
{ \
   *(SPIOutput0 + n) = x; \
}

/**
 * @brief read value from SPI buffer 0
 * 
 *
 * @param n ID of SPI input.
 */   
#define getSPIIn0(n) ((float)*(SPIInput0 + n))

#define getSPIInputState0() (!!(*SPIInputState & 0x01))
#define getSPIInputState1() (!!(*SPIInputState & 0x02))

/** @brief Send value to SPI buffer 1
 * 
 * @param 
 */ 
#define setSPIOut1(n, x) \
{ \
   *(SPIOutput1 + n) = x; \
}

/**
 * @brief read value from SPI buffer 1
 * 
 *
 * @param n ID of SPI input.
 */   
#define getSPIIn1(n) ((float)*(SPIInput1 + n))

#ifdef __cplusplus
}
#endif

#endif /*SPI_H_*/