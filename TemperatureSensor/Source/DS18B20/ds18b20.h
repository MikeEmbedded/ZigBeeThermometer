#ifndef DS18b20_H
#define DS18b20_H

#include "hal_board.h"

#define DS18B20_PORT 0
#define DS18B20_PIN 7

#define TSENS_POWER_BIT P1_0
#define TSENS_POWER_BV BV(0)
#define TSENS_POWER_DIR P1DIR

#define TSENS_SBIT P0_7
#define TSENS_BV BV(7)
#define TSENS_DIR P0DIR

int16 readTemperature(void);

#endif
