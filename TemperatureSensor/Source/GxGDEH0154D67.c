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

#include "GxGDEH0154D67.h"

//#define DISABLE_DIAGNOSTIC_OUTPUT

// Partial Update Delay, may have an influence on degradation
#define GxGDEH0154D67_PU_DELAY 300

static const uint16_t power_on_time = 80; // ms, e.g. 73508us
static const uint16_t power_off_time = 80; // ms, e.g. 68982us
static const uint16_t full_refresh_time = 1200; // ms, e.g. 1113273us
static const uint16_t partial_refresh_time = 300; // ms, e.g. 290867us

uint8_t rotation;     ///< Display rotation (0 thru 3)
uint8_t _buffer[GxGDEH0154D67_PAGE_SIZE];
int16_t _current_page;
bool _using_partial_mode;
bool _diag_enabled;
int8_t _rst;
int8_t _busy;
//int16_t _width;       ///< Display width as modified by current rotation
//int16_t _height;      ///< Display height as modified by current rotation

uint8_t getRotation(void)
{ 
  return rotation;
}

static int16_t width(void)
{
  return GxGDEH0154D67_X_PIXELS;
}

static int16_t height(void)
{
  return GxGDEH0154D67_Y_PIXELS;
}

void delay(uint16 d)
{
  while(d--)
  {
    /* 32 NOPs == 1 usecs */
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop"); asm("nop"); asm("nop"); asm("nop");
    asm("nop"); asm("nop");
  }
}

static void DEV_SPI_WriteByte(uint8_t value)
{
  U1CSR &= ~(BV(2) | BV(1));
  U1DBUF = value;
  while( !(U1CSR & BV(1)) );
}

static void startTransaction(void)
{
  DEV_Digital_Write(EPD_CS_PIN, 0);
}

static void  endTransaction(void)
{
  DEV_Digital_Write(EPD_CS_PIN, 1);
}

static void writeCommandTransaction(uint8_t Reg)
{
  DEV_Digital_Write(EPD_DC_PIN, 0);
  DEV_Digital_Write(EPD_CS_PIN, 0);
  DEV_SPI_WriteByte(Reg);
  DEV_Digital_Write(EPD_CS_PIN, 1);
  DEV_Digital_Write(EPD_DC_PIN, 1);
}

static void writeDataTransaction(uint8_t Data)
{
    DEV_Digital_Write(EPD_DC_PIN, 1);
    DEV_Digital_Write(EPD_CS_PIN, 0);
    DEV_SPI_WriteByte(Data);
    DEV_Digital_Write(EPD_CS_PIN, 1);
}

static void writeCommand(uint8_t c)
{
  DEV_Digital_Write(EPD_DC_PIN, 0);
  DEV_SPI_WriteByte(c);
  DEV_Digital_Write(EPD_DC_PIN, 1);
}

static void writeData(uint8_t d)
{
  DEV_SPI_WriteByte(d);
}

void drawPixel(int16_t x, int16_t y, uint16_t color)
{
  if ((x < 0) || (x >= width()) || (y < 0) || (y >= height())) return;

  // check rotation, move pixel around if necessary
  switch (getRotation())
  {
    case 1:
      swap(x, y);
      x = GxGDEH0154D67_WIDTH - x - 1;
      break;
    case 2:
      x = GxGDEH0154D67_WIDTH - x - 1;
      y = GxGDEH0154D67_HEIGHT - y - 1;
      break;
    case 3:
      swap(x, y);
      y = GxGDEH0154D67_HEIGHT - y - 1;
      break;
  }
  uint16_t i = x / 8 + y * GxGDEH0154D67_WIDTH / 8;
  if (_current_page < 1)
  {
    if (i >= sizeof(_buffer)) return;
  }
  else
  {
    y -= _current_page * GxGDEH0154D67_PAGE_HEIGHT;
    if ((y < 0) || (y >= GxGDEH0154D67_PAGE_HEIGHT)) return;
    i = x / 8 + y * GxGDEH0154D67_WIDTH / 8;
  }

  if (!color)
    _buffer[i] = (_buffer[i] | (1 << (7 - x % 8)));
  else
    _buffer[i] = (_buffer[i] & (0xFF ^ (1 << (7 - x % 8))));
}

void init(void)
{
  fillScreen(GxEPD_WHITE);
  _current_page = -1;
  _using_partial_mode = false;
}

void fillScreen(uint16_t color)
{
  uint8_t data = (color == GxEPD_BLACK) ? 0xFF : 0x00;
  for (uint16_t x = 0; x < sizeof(_buffer); x++)
  {
    _buffer[x] = data;
  }
}

void update(void)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (uint16_t y = 0; y < GxGDEH0154D67_HEIGHT; y++)
  {
    for (uint16_t x = 0; x < GxGDEH0154D67_WIDTH / 8; x++)
    {
      uint16_t idx = y * (GxGDEH0154D67_WIDTH / 8) + x;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  _Update_Full();
  _PowerOff();
}

//void  drawBitmap(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode)
//{
//  if (mode & bm_default) mode |= bm_flip_x | bm_invert;
//  drawBitmapBM(bitmap, x, y, w, h, color, mode);
//}

void drawBitmap(const uint8_t *bitmap, uint32_t size, int16_t mode)
{
  if (_current_page != -1) return;
  // example bitmaps are made for y-decrement, x-increment, for origin on opposite corner
  // bm_flip_x for normal display (bm_flip_y would be rotated)
  if (mode & bm_default) mode |= bm_flip_x;
  uint8_t ram_entry_mode = 0x03; // y-increment, x-increment for normal mode
  if ((mode & bm_flip_y) && (mode & bm_flip_x)) ram_entry_mode = 0x00; // y-decrement, x-decrement
  else if (mode & bm_flip_y) ram_entry_mode = 0x01; // y-decrement, x-increment
  else if (mode & bm_flip_x) ram_entry_mode = 0x02; // y-increment, x-decrement
  if (mode & bm_partial_update)
  {
    _using_partial_mode = true; // remember
    _Init_Part(ram_entry_mode);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
        data = pgm_read_byte(&bitmap[i]);
#else
        data = bitmap[i];
#endif
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    _Update_Part();
    delay(GxGDEH0154D67_PU_DELAY);
    // update erase buffer
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
        data = pgm_read_byte(&bitmap[i]);
#else
        data = bitmap[i];
#endif
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    delay(GxGDEH0154D67_PU_DELAY);
    _PowerOff();
  }
  else
  {
    _using_partial_mode = false; // remember
    _Init_Full(ram_entry_mode);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
#if defined(__AVR) || defined(ESP8266) || defined(ESP32)
        data = pgm_read_byte(&bitmap[i]);
#else
        data = bitmap[i];
#endif
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    _Update_Full();
    _PowerOff();
  }
}

void eraseDisplay(bool using_partial_update)
{
  if (_current_page != -1) return;
  if (using_partial_update)
  {
    _using_partial_mode = true; // remember
    _Init_Part(0x01);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      _writeData(0xFF);
    }
    _Update_Part();
    delay(GxGDEH0154D67_PU_DELAY);
    // update erase buffer
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      _writeData(0xFF);
    }
    delay(GxGDEH0154D67_PU_DELAY);
  }
  else
  {
    _using_partial_mode = false; // remember
    _Init_Full(0x01);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEH0154D67_BUFFER_SIZE; i++)
    {
      _writeData(0x00);
    }
    _Update_Full();
    _PowerOff();
  }
}

void updateWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h, bool using_rotation)
{
  if (_current_page != -1) return;
  if (using_rotation) _rotate(x, y, w, h);
  if (x >= GxGDEH0154D67_WIDTH) return;
  if (y >= GxGDEH0154D67_HEIGHT) return;
  uint16_t xe = gx_uint16_min(GxGDEH0154D67_WIDTH, x + w) - 1;
  uint16_t ye = gx_uint16_min(GxGDEH0154D67_HEIGHT, y + h) - 1;
  uint16_t xs_d8 = x / 8;
  uint16_t xe_d8 = xe / 8;
  _Init_Part(0x03);
  _SetRamArea(xs_d8, xe_d8, y % 256, y / 256, ye % 256, ye / 256); // X-source area,Y-gate area
  _SetRamPointer(xs_d8, y % 256, y / 256); // set ram
  _waitWhileBusy(100); // needed ?
  _writeCommand(0x24);
  for (int16_t y1 = y; y1 <= ye; y1++)
  {
    for (int16_t x1 = xs_d8; x1 <= xe_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  _Update_Part();
  delay(GxGDEH0154D67_PU_DELAY);
  // update erase buffer
  _SetRamArea(xs_d8, xe_d8, y % 256, y / 256, ye % 256, ye / 256); // X-source area,Y-gate area
  _SetRamPointer(xs_d8, y % 256, y / 256); // set ram
  _waitWhileBusy(100); // needed ?
  _writeCommand(0x24);
  for (int16_t y1 = y; y1 <= ye; y1++)
  {
    for (int16_t x1 = xs_d8; x1 <= xe_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  delay(GxGDEH0154D67_PU_DELAY);
}

void _writeToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h)
{
  //Serial.printf("_writeToWindow(%d, %d, %d, %d, %d, %d)\n", xs, ys, xd, yd, w, h);
  // the screen limits are the hard limits
  if (xs >= GxGDEH0154D67_WIDTH) return;
  if (ys >= GxGDEH0154D67_HEIGHT) return;
  if (xd >= GxGDEH0154D67_WIDTH) return;
  if (yd >= GxGDEH0154D67_HEIGHT) return;
  w = gx_uint16_min(w, GxGDEH0154D67_WIDTH - xs);
  w = gx_uint16_min(w, GxGDEH0154D67_WIDTH - xd);
  h = gx_uint16_min(h, GxGDEH0154D67_HEIGHT - ys);
  h = gx_uint16_min(h, GxGDEH0154D67_HEIGHT - yd);
  uint16_t xds_d8 = xd / 8;
  uint16_t xde_d8 = (xd + w - 1) / 8;
  uint16_t yde = yd + h - 1;
  // soft limits, must send as many bytes as set by _SetRamArea
  uint16_t xse_d8 = xs / 8 + xde_d8 - xds_d8;
  uint16_t yse = ys + h - 1;
  _SetRamArea(xds_d8, xde_d8, yd % 256, yd / 256, yde % 256, yde / 256); // X-source area,Y-gate area
  _SetRamPointer(xds_d8, yd % 256, yd / 256); // set ram
  _waitWhileBusy(100); // needed ?
  _writeCommand(0x24);
  for (int16_t y1 = ys; y1 <= yse; y1++)
  {
    for (int16_t x1 = xs / 8; x1 <= xse_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
}

void updateToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation)
{
  if (using_rotation)
  {
    switch (getRotation())
    {
      case 1:
        swap(xs, ys);
        swap(xd, yd);
        swap(w, h);
        xs = GxGDEH0154D67_WIDTH - xs - w - 1;
        xd = GxGDEH0154D67_WIDTH - xd - w - 1;
        break;
      case 2:
        xs = GxGDEH0154D67_WIDTH - xs - w - 1;
        ys = GxGDEH0154D67_HEIGHT - ys - h - 1;
        xd = GxGDEH0154D67_WIDTH - xd - w - 1;
        yd = GxGDEH0154D67_HEIGHT - yd - h - 1;
        break;
      case 3:
        swap(xs, ys);
        swap(xd, yd);
        swap(w, h);
        ys = GxGDEH0154D67_HEIGHT - ys  - h - 1;
        yd = GxGDEH0154D67_HEIGHT - yd  - h - 1;
        break;
    }
  }
  _Init_Part(0x03);
  _writeToWindow(xs, ys, xd, yd, w, h);
  _Update_Part();
  delay(GxGDEH0154D67_PU_DELAY);
  // update erase buffer
  _writeToWindow(xs, ys, xd, yd, w, h);
  delay(GxGDEH0154D67_PU_DELAY);
}

void powerDown(void)
{
  _using_partial_mode = false;
  _PowerOff();
}

void _writeCommand(uint8_t command)
{
//  if ((_busy >= 0) && digitalRead(_busy))
//  {
//    String str = String("command 0x") + String(command, HEX);
    _waitWhileBusy(100); // needed?
//  }
  writeCommandTransaction(command);
}

void _writeData(uint8_t data)
{
  writeDataTransaction(data);
}

void _writeCommandData(const uint8_t* pCommandData, uint8_t datalen)
{
  if (P1_2 == 1)
  {
    //String str = String("command 0x") + String(pCommandData[0], HEX);
    _waitWhileBusy(100); // needed?
  }
  startTransaction();
  writeCommand(*pCommandData++);
  for (uint8_t i = 0; i < datalen - 1; i++)  // sub the command
  {
    writeData(*pCommandData++);
  }
  endTransaction();
}

void _waitWhileBusy(uint16_t busy_time)
{
  if (_busy >= 0)
  {
    while(P1_2 == 1) {      //LOW: idle, HIGH: busy
        delay(10000);
    }
  }
  else delay(busy_time);
}

void _setRamDataEntryMode(uint8_t em)
{
  const uint16_t xPixelsPar = GxGDEH0154D67_X_PIXELS - 1;
  const uint16_t yPixelsPar = GxGDEH0154D67_Y_PIXELS - 1;
  em = gx_uint16_min(em, 0x03);
  _writeCommand(0x11);
  _writeData(em);
  switch (em)
  {
    case 0x00: // x decrease, y decrease
      _SetRamArea(xPixelsPar / 8, 0x00, yPixelsPar % 256, yPixelsPar / 256, 0x00, 0x00);  // X-source area,Y-gate area
      _SetRamPointer(xPixelsPar / 8, yPixelsPar % 256, yPixelsPar / 256); // set ram
      break;
    case 0x01: // x increase, y decrease : as in demo code
      _SetRamArea(0x00, xPixelsPar / 8, yPixelsPar % 256, yPixelsPar / 256, 0x00, 0x00);  // X-source area,Y-gate area
      _SetRamPointer(0x00, yPixelsPar % 256, yPixelsPar / 256); // set ram
      break;
    case 0x02: // x decrease, y increase
      _SetRamArea(xPixelsPar / 8, 0x00, 0x00, 0x00, yPixelsPar % 256, yPixelsPar / 256);  // X-source area,Y-gate area
      _SetRamPointer(xPixelsPar / 8, 0x00, 0x00); // set ram
      break;
    case 0x03: // x increase, y increase : normal mode
      _SetRamArea(0x00, xPixelsPar / 8, 0x00, 0x00, yPixelsPar % 256, yPixelsPar / 256);  // X-source area,Y-gate area
      _SetRamPointer(0x00, 0x00, 0x00); // set ram
      break;
  }
}

void _SetRamArea(uint8_t Xstart, uint8_t Xend, uint8_t Ystart, uint8_t Ystart1, uint8_t Yend, uint8_t Yend1)
{
  _writeCommand(0x44);
  _writeData(Xstart);
  _writeData(Xend);
  _writeCommand(0x45);
  _writeData(Ystart);
  _writeData(Ystart1);
  _writeData(Yend);
  _writeData(Yend1);
}

void _SetRamPointer(uint8_t addrX, uint8_t addrY, uint8_t addrY1)
{
  _writeCommand(0x4e);
  _writeData(addrX);
  _writeCommand(0x4f);
  _writeData(addrY);
  _writeData(addrY1);
}

void _PowerOn(void)
{
  _writeCommand(0x22);
  _writeData(0xc0);
  _writeCommand(0x20);
  _waitWhileBusy(power_on_time);
}

void _PowerOff(void)
{
  _writeCommand(0x22);
  _writeData(0xc3);
  _writeCommand(0x20);
  _waitWhileBusy(power_off_time);
}

void _InitDisplay(uint8_t em)
{
  _writeCommand(0x12);
  _waitWhileBusy(power_on_time);
  _writeCommand(0x01); // Driver output control
  _writeData(0xC7);
  _writeData(0x00);
  _writeData(0x00);
  _writeCommand(0x3C); // BorderWavefrom
  _writeData(0x05);
  _writeCommand(0x18); // Read built-in temperature sensor
  _writeData(0x80);
  _setRamDataEntryMode(em);
}

void _Init_Full(uint8_t em)
{
  _InitDisplay(em);
  _PowerOn();
}

void _Init_Part(uint8_t em)
{
  _InitDisplay(em);
  _PowerOn();
}

void _Update_Full(void)
{
  _writeCommand(0x22);
  _writeData(0xf7);
  _writeCommand(0x20);
  _waitWhileBusy(full_refresh_time);
}

void _Update_Part(void)
{
  _writeCommand(0x22);
  _writeData(0xff);
  _writeCommand(0x20);
  _waitWhileBusy(partial_refresh_time);
}

void drawPaged(void (*drawCallback)(void))
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
  {
    fillScreen(GxEPD_WHITE);
    drawCallback();
    for (int16_t y1 = 0; y1 < GxGDEH0154D67_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEH0154D67_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _writeData(~data);
      }
    }
  }
  _current_page = -1;
  _Update_Full();
  _PowerOff();
}

//void drawPaged(void (*drawCallback)(uint32_t), uint32_t p)
//{
//  if (_current_page != -1) return;
//  _using_partial_mode = false;
//  _Init_Full(0x03);
//  _writeCommand(0x24);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    fillScreen(GxEPD_WHITE);
//    drawCallback(p);
//    for (int16_t y1 = 0; y1 < GxGDEH0154D67_PAGE_HEIGHT; y1++)
//    {
//      for (int16_t x1 = 0; x1 < GxGDEH0154D67_WIDTH / 8; x1++)
//      {
//        uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
//        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
//        _writeData(~data);
//      }
//    }
//  }
//  _current_page = -1;
//  _Update_Full();
//  _PowerOff();
//}

//void drawPaged(void (*drawCallback)(const void*), const void* p)
//{
//  if (_current_page != -1) return;
//  _using_partial_mode = false;
//  _Init_Full(0x03);
//  _writeCommand(0x24);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    fillScreen(GxEPD_WHITE);
//    drawCallback(p);
//    for (int16_t y1 = 0; y1 < GxGDEH0154D67_PAGE_HEIGHT; y1++)
//    {
//      for (int16_t x1 = 0; x1 < GxGDEH0154D67_WIDTH / 8; x1++)
//      {
//        uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
//        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
//        _writeData(~data);
//      }
//    }
//  }
//  _current_page = -1;
//  _Update_Full();
//  _PowerOff();
//}

//void drawPaged(void (*drawCallback)(const void*, const void*), const void* p1, const void* p2)
//{
//  if (_current_page != -1) return;
//  _using_partial_mode = false;
//  _Init_Full(0x03);
//  _writeCommand(0x24);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    fillScreen(GxEPD_WHITE);
//    drawCallback(p1, p2);
//    for (int16_t y1 = 0; y1 < GxGDEH0154D67_PAGE_HEIGHT; y1++)
//    {
//      for (int16_t x1 = 0; x1 < GxGDEH0154D67_WIDTH / 8; x1++)
//      {
//        uint16_t idx = y1 * (GxGDEH0154D67_WIDTH / 8) + x1;
//        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
//        _writeData(~data);
//      }
//    }
//  }
//  _current_page = -1;
//  _Update_Full();
//  _PowerOff();
//}

void _rotate(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  switch (getRotation())
  {
    case 1:
      swap(x, y);
      swap(w, h);
      x = GxGDEH0154D67_WIDTH - x - w - 1;
      break;
    case 2:
      x = GxGDEH0154D67_WIDTH - x - w - 1;
      y = GxGDEH0154D67_HEIGHT - y - h - 1;
      break;
    case 3:
      swap(x, y);
      swap(w, h);
      y = GxGDEH0154D67_HEIGHT - y - h - 1;
      break;
  }
}

void drawPagedToWindow(void (*drawCallback)(void), uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  if (_current_page != -1) return;
  _rotate(x, y, w, h);
  if (!_using_partial_mode)
  {
    eraseDisplay(false);
    eraseDisplay(true);
  }
  _using_partial_mode = true;
  _Init_Part(0x03);
  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
    if (yde > yds)
    {
      fillScreen(GxEPD_WHITE);
      drawCallback();
      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  _Update_Part();
  delay(GxGDEH0154D67_PU_DELAY);
  // update erase buffer
  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
    if (yde > yds)
    {
      fillScreen(GxEPD_WHITE);
      drawCallback();
      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  delay(GxGDEH0154D67_PU_DELAY);
  _current_page = -1;
  _PowerOff();
}

//void drawPagedToWindow(void (*drawCallback)(uint32_t), uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t p)
//{
//  if (_current_page != -1) return;
//  _rotate(x, y, w, h);
//  if (!_using_partial_mode)
//  {
//    eraseDisplay(false);
//    eraseDisplay(true);
//  }
//  _using_partial_mode = true;
//  _Init_Part(0x03);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  _Update_Part();
//  delay(GxGDEH0154D67_PU_DELAY);
//  // update erase buffer
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  delay(GxGDEH0154D67_PU_DELAY);
//  _current_page = -1;
//  _PowerOff();
//}
//
//void drawPagedToWindow(void (*drawCallback)(const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void* p)
//{
//  if (_current_page != -1) return;
//  _rotate(x, y, w, h);
//  if (!_using_partial_mode)
//  {
//    eraseDisplay(false);
//    eraseDisplay(true);
//  }
//  _using_partial_mode = true;
//  _Init_Part(0x03);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  _Update_Part();
//  delay(GxGDEH0154D67_PU_DELAY);
//  // update erase buffer
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  delay(GxGDEH0154D67_PU_DELAY);
//  _current_page = -1;
//  _PowerOff();
//}
//
//void drawPagedToWindow(void (*drawCallback)(const void*, const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void* p1, const void* p2)
//{
//  if (_current_page != -1) return;
//  _rotate(x, y, w, h);
//  if (!_using_partial_mode)
//  {
//    eraseDisplay(false);
//    eraseDisplay(true);
//  }
//  _using_partial_mode = true;
//  _Init_Part(0x03);
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p1, p2);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  _Update_Part();
//  delay(GxGDEH0154D67_PU_DELAY);
//  // update erase buffer
//  for (_current_page = 0; _current_page < GxGDEH0154D67_PAGES; _current_page++)
//  {
//    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEH0154D67_PAGE_HEIGHT);
//    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEH0154D67_PAGE_HEIGHT);
//    if (yde > yds)
//    {
//      fillScreen(GxEPD_WHITE);
//      drawCallback(p1, p2);
//      uint16_t ys = yds % GxGDEH0154D67_PAGE_HEIGHT;
//      _writeToWindow(x, ys, x, yds, w, yde - yds);
//    }
//  }
//  delay(GxGDEH0154D67_PU_DELAY);
//  _current_page = -1;
//  _PowerOff();
//}

void drawCornerTest(uint8_t em)
{
  if (_current_page != -1) return;
  _Init_Full(em);
  _writeCommand(0x24);
  for (uint32_t y = 0; y < GxGDEH0154D67_HEIGHT; y++)
  {
    for (uint32_t x = 0; x < GxGDEH0154D67_WIDTH / 8; x++)
    {
      uint8_t data = 0xFF;
      if ((x < 1) && (y < 8)) data = 0x00;
      if ((x > GxGDEH0154D67_WIDTH / 8 - 3) && (y < 16)) data = 0x00;
      if ((x > GxGDEH0154D67_WIDTH / 8 - 4) && (y > GxGDEH0154D67_HEIGHT - 25)) data = 0x00;
      if ((x < 4) && (y > GxGDEH0154D67_HEIGHT - 33)) data = 0x00;
      _writeData(data);
    }
  }
  _Update_Full();
  _PowerOff();
}