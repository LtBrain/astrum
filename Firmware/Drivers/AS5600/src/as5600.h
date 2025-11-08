#ifndef AS5600_H
#define AS5600_H

#include "stm32h5xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

// AS5600 I2C address
#define AS5600_ADDR         0x36 << 1  // STM32 HAL uses 8-bit addresses

// Registers
#define AS5600_REG_ANGLE    0x0E
#define AS5600_REG_ZMCO     0x00
#define AS5600_REG_STATUS   0x0B
#define AS5600_REG_AGC      0x1A
#define AS5600_REG_MAGNITUDE 0x1B
#define AS5600_REG_BURN     0xFF

// Struct to hold driver state
typedef struct {
    I2C_HandleTypeDef *hi2c;
    uint16_t angle; // last read angle
} AS5600_HandleTypeDef;

// Function prototypes
bool AS5600_ReadAngle(AS5600_HandleTypeDef *dev, uint16_t *angle);
bool AS5600_ReadRegister(AS5600_HandleTypeDef *dev, uint8_t reg, uint8_t *data);
bool AS5600_WriteRegister(AS5600_HandleTypeDef *dev, uint8_t reg, uint8_t data);

#endif
