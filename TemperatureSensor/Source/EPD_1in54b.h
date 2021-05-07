/*****************************************************************************
* | File      	:	EPD_1in54b.h
* | Author      :   MH-ET LIVE
* | Function    :   Electronic paper driver
* | Info        :
*----------------
* |	This version:   V2.0
* | Date        :   2018-10-30
* | Info        :   
* 1.Remove:ImageBuff[EPD_HEIGHT * EPD_WIDTH / 8]
* 2.Change:EPD_Display(UBYTE *Image)
*   Need to pass parameters: pointer to cached data
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#ifndef _EPD1IN54B_H_
#define _EPD1IN54B_H_

#include "OSAL.h"
#include "hal_lcd.h"
/**
 * data
**/
#define UBYTE   uint8
#define UWORD   uint16
#define UDOUBLE uint32

// Display resolution
#define EPD_WIDTH       200
#define EPD_HEIGHT      200

// EPD1IN54B commands
// EPD1IN54 commands
#define DRIVER_OUTPUT_CONTROL                       0x01
#define BOOSTER_SOFT_START_CONTROL                  0x0C
#define GATE_SCAN_START_POSITION                    0x0F
#define DEEP_SLEEP_MODE                             0x10
#define DATA_ENTRY_MODE_SETTING                     0x11
#define SW_RESET                                    0x12
#define TEMPERATURE_SENSOR_CONTROL                  0x1A
#define MASTER_ACTIVATION                           0x20
#define DISPLAY_UPDATE_CONTROL_1                    0x21
#define DISPLAY_UPDATE_CONTROL_2                    0x22
#define WRITE_RAM                                   0x24
#define WRITE_VCOM_REGISTER                         0x2C
#define WRITE_LUT_REGISTER                          0x32
#define SET_DUMMY_LINE_PERIOD                       0x3A
#define SET_GATE_TIME                               0x3B
#define BORDER_WAVEFORM_CONTROL                     0x3C
#define SET_RAM_X_ADDRESS_START_END_POSITION        0x44
#define SET_RAM_Y_ADDRESS_START_END_POSITION        0x45
#define SET_RAM_X_ADDRESS_COUNTER                   0x4E
#define SET_RAM_Y_ADDRESS_COUNTER                   0x4F
#define TERMINATE_FRAME_READ_WRITE                  0xFF

/**
 * e-Paper GPIO
**/
#define HAL_LCD_DC_PORT 1
#define HAL_LCD_DC_PIN  7

#define HAL_LCD_RESET_PORT 1
#define HAL_LCD_RESET_PIN  3

#define HAL_LCD_CS_PORT 1
#define HAL_LCD_CS_PIN  4

/* LCD SPI lines */
#define HAL_LCD_CLK_PORT 1
#define HAL_LCD_CLK_PIN  5

#define HAL_LCD_MOSI_PORT 1
#define HAL_LCD_MOSI_PIN  6

#define HAL_LCD_BUSY_PORT 1
#define HAL_LCD_BUSY_PIN  2

#define EPD_RST_PIN     HAL_LCD_RESET_PORT, HAL_LCD_RESET_PIN
#define EPD_DC_PIN      HAL_LCD_DC_PORT,  HAL_LCD_DC_PIN
#define EPD_CS_PIN      HAL_LCD_CS_PORT,    HAL_LCD_CS_PIN
#define EPD_BUSY_PIN    HAL_LCD_BUSY_PORT,  HAL_LCD_BUSY_PIN
#define GPIO_PIN_RESET  0
#define GPIO_PIN_SET    1
/**
 * GPIO read and write
**/
#define HAL_IO_SET(port, pin, val)        HAL_IO_SET_PREP(port, pin, val)
#define HAL_IO_SET_PREP(port, pin, val)   st( P##port##_##pin = val; )

#define DEV_Digital_Write(_pin, _value) HAL_IO_SET(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)

/**
 * delay x ms
**/

extern const unsigned char lut_full_update[];
extern const unsigned char lut_partial_update[];

UBYTE EPD_Init(const unsigned char* lut);
void EPD_Clear(void);
void EPD_Display(UBYTE *Image);
void EPD_Sleep(void);
void DEV_SPI_WriteByte(UBYTE value);
void EPD_WaitUntilIdle(void);
void DEV_Delay_ms(uint16 mSecs);

#endif
