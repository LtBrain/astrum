#include "as5600.h"

// Reads a 12-bit angle (0-4095)
bool AS5600_ReadAngle(AS5600_HandleTypeDef *dev, uint16_t *angle) {
    uint8_t buf[2];
    if(HAL_I2C_Mem_Read(dev->hi2c, AS5600_ADDR, AS5600_REG_ANGLE, I2C_MEMADD_SIZE_8BIT, buf, 2, HAL_MAX_DELAY) != HAL_OK) {
        return false;
    }
    // Combine MSB and LSB
    *angle = ((uint16_t)buf[0] << 8 | buf[1]) & 0x0FFF;
    dev->angle = *angle;
    return true;
}

// Read single byte from a register
bool AS5600_ReadRegister(AS5600_HandleTypeDef *dev, uint8_t reg, uint8_t *data) {
    if(HAL_I2C_Mem_Read(dev->hi2c, AS5600_ADDR, reg, I2C_MEMADD_SIZE_8BIT, data, 1, HAL_MAX_DELAY) != HAL_OK) {
        return false;
    }
    return true;
}

// Write single byte to a register
bool AS5600_WriteRegister(AS5600_HandleTypeDef *dev, uint8_t reg, uint8_t data) {
    if(HAL_I2C_Mem_Write(dev->hi2c, AS5600_ADDR, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY) != HAL_OK) {
        return false;
    }
    return true;
}
