#pragma once
#include "stm32h5xx_hal.h"
#include <math.h>
#include <stdbool.h>

typedef struct {
    TIM_HandleTypeDef* htim;
    uint32_t channel;
    GPIO_TypeDef* in1Port;
    uint16_t in1Pin;
    GPIO_TypeDef* in2Port;
    uint16_t in2Pin;
} Motor;

// Create a motor object
Motor Motor_Create(TIM_HandleTypeDef* htim, uint32_t channel, GPIO_TypeDef* in1Port, uint16_t in1Pin, GPIO_TypeDef* in2Port, uint16_t in2Pin);

// Control motor
void Motor_SetSpeed(Motor* motor, float speed); // speed -1.0 to 1.0
void Motor_Brake(Motor* motor);
void Motor_Coast(Motor* motor);