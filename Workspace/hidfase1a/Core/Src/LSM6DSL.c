#include "stm32l4xx_hal.h"
#include "LSM6DSL.h"

extern I2C_HandleTypeDef hi2c2;

void LSM6DSL_Init(void)
{
	uint8_t buffer[1];
	buffer[0] = 0x40;

	HAL_I2C_Mem_Write(&hi2c2, 0xD4, 0x10,
			I2C_MEMADD_SIZE_8BIT, buffer, 1, 1000);
}

int16_t LSM6DSL_ReadAccel(uint8_t axis)
{
	uint8_t buffer[2];
	HAL_I2C_Mem_Read(&hi2c2, 0xD4, 0x28+2*axis,
			I2C_MEMADD_SIZE_8BIT, buffer, 2, 1000);
	return ((int16_t)(buffer[1]<<8) | buffer[0]) * 0.061f;
}
