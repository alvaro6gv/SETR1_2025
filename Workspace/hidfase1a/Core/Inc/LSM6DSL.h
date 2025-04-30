#ifndef INC_LSM6DSL_H_
#define INC_LSM6DSL_H_

#include "stm32l4xx_hal_conf.h"
#include <stdint.h>

void LSM6DSL_Init(void);
int16_t LSM6DSL_ReadAccel(uint8_t axis);

#endif
