// class GxGDEH0154D67 : Display class for GDEH0154D67 e-Paper from Dalian Good Display Co., Ltd.: www.e-paper-display.com
//
// based on Demo Example from Good Display, available here: http://www.e-paper-display.com/download_detail/downloadsId=806.html
// Controller : SSD1681 : http://www.e-paper-display.com/download_detail/downloadsId=825.html
//
// Author : J-M Zingg
//
// Version : see library.properties
//
// License: GNU GENERAL PUBLIC LICENSE V3, see LICENSE
//
// Library: https://github.com/ZinggJM/GxEPD

#ifndef _GxGDEH0154D67_H_
#define _GxGDEH0154D67_H_

#include "OSAL.h"
#include "hal_board_cfg.h"

#define int8_t int8
#define uint8_t uint8
#define int16_t int16
#define uint16_t uint16
#define uint32_t uint32


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


#define GxEPD_BLACK     0x0000
#define GxEPD_DARKGREY  0x7BEF      /* 128, 128, 128 */
#define GxEPD_LIGHTGREY 0xC618      /* 192, 192, 192 */
#define GxEPD_WHITE     0xFFFF
#define GxEPD_RED       0xF800      /* 255,   0,   0 */

// the physical number of pixels (for controller parameter)
#define GxGDEH0154D67_X_PIXELS 200
#define GxGDEH0154D67_Y_PIXELS 200

#define GxGDEH0154D67_WIDTH GxGDEH0154D67_X_PIXELS
#define GxGDEH0154D67_HEIGHT GxGDEH0154D67_Y_PIXELS

#define GxGDEH0154D67_BUFFER_SIZE ((uint32_t)(GxGDEH0154D67_WIDTH) * (uint32_t)(GxGDEH0154D67_HEIGHT) / 8)

// divisor for AVR, should be factor of GxGDEH0154D67_HEIGHT
#define GxGDEH0154D67_PAGES 5

#define GxGDEH0154D67_PAGE_HEIGHT (GxGDEH0154D67_HEIGHT / GxGDEH0154D67_PAGES)
#define GxGDEH0154D67_PAGE_SIZE (GxGDEH0154D67_BUFFER_SIZE / GxGDEH0154D67_PAGES)

#define swap(a, b)      \
    {                   \
      uint16 t = a;     \
      a = b;            \
      b = t;            \
    }                   \

enum bm_mode //BM_ModeSet
{
  bm_normal = 0,
  bm_default = 1, // for use for BitmapExamples
  // these potentially can be combined
  bm_invert = (1 << 1),
  bm_flip_x = (1 << 2),
  bm_flip_y = (1 << 3),
  bm_r90 = (1 << 4),
  bm_r180 = (1 << 5),
  bm_r270 = bm_r90 | bm_r180,
  bm_partial_update = (1 << 6),
  bm_invert_red = (1 << 7),
  bm_transparent = (1 << 8)
};

static inline uint16_t gx_uint16_min(uint16_t a, uint16_t b) {return (a < b ? a : b);};
static inline uint16_t gx_uint16_max(uint16_t a, uint16_t b) {return (a > b ? a : b);};
    
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void init(void); // = 0 : disabled
    void fillScreen(uint16_t color); // 0x0 black, >0x0 white, to buffer
    void update(void);
    // to buffer, may be cropped, drawPixel() used, update needed
    //void  drawBitmap(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode);
    // to full screen, filled with white if size is less, no update needed
    void drawBitmap(const uint8_t *bitmap, uint32_t size, int16_t mode); // only bm_normal, bm_invert, bm_partial_update modes implemented
    void eraseDisplay(bool using_partial_update);
    // partial update of rectangle from buffer to screen, does not power off
    void updateWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool using_rotation);
    // partial update of rectangle at (xs,ys) from buffer to screen at (xd,yd), does not power off
    void updateToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation);
    // terminate cleanly updateWindow or updateToWindow before removing power or long delays
    void powerDown();
    // paged drawing, for limited RAM, drawCallback() is called GxGDEH0154D67_PAGES times
    // each call of drawCallback() should draw the same
    void drawPaged(void (*drawCallback)(void));
   // void drawPaged(void (*drawCallback)(uint32_t), uint32_t);
   // void drawPaged(void (*drawCallback)(const void*), const void*);
   // void drawPaged(void (*drawCallback)(const void*, const void*), const void*, const void*);
    // paged drawing to screen rectangle at (x,y) using partial update
    void drawPagedToWindow(void (*drawCallback)(void), uint16_t x, uint16_t y, uint16_t w, uint16_t h);
   // void drawPagedToWindow(void (*drawCallback)(uint32_t), uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t);
   // void drawPagedToWindow(void (*drawCallback)(const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*);
   // void drawPagedToWindow(void (*drawCallback)(const void*, const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*, const void*);
    void drawCornerTest(uint8_t em);
    void _writeToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h);
    void _writeData(uint8_t data);
    void _writeCommand(uint8_t command);
    void _writeCommandData(const uint8_t* pCommandData, uint8_t datalen);
    void _SetRamPointer(uint8_t addrX, uint8_t addrY, uint8_t addrY1);
    void _SetRamArea(uint8_t Xstart, uint8_t Xend, uint8_t Ystart, uint8_t Ystart1, uint8_t Yend, uint8_t Yend1);
    void _PowerOn(void);
    void _PowerOff(void);
    void _waitWhileBusy(uint16_t busy_time);
    void _setRamDataEntryMode(uint8_t em);
    void _InitDisplay(uint8_t em);
    void _Init_Full(uint8_t em);
    void _Init_Part(uint8_t em);
    void _Update_Full(void);
    void _Update_Part(void);
    void _rotate(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void delay(uint16 d);
    uint8_t getRotation(void);
    void powerDown(void);

#define GxEPD_WIDTH GxGDEH0154D67_WIDTH
#define GxEPD_HEIGHT GxGDEH0154D67_HEIGHT
//#define GxEPD_BitmapExamples <GxGDEH0154D67/BitmapExamples.h>
//#define GxEPD_BitmapExamplesQ "GxGDEH0154D67/BitmapExamples.h"

#endif