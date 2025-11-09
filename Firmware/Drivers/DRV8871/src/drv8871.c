#include "drv8871.h"

// Motor creation
Motor Motor_Create(TIM_HandleTypeDef* htim, uint32_t channel, GPIO_TypeDef* in1Port, uint16_t in1Pin, GPIO_TypeDef* in2Port, uint16_t in2Pin) {
    Motor m;
    m.htim = htim;
    m.channel = channel;
    m.in1Port = in1Port;
    m.in1Pin = in1Pin;
    m.in2Port = in2Port;
    m.in2Pin = in2Pin;

    HAL_TIM_PWM_Start(htim, channel); // start PWM
    HAL_GPIO_WritePin(in1Port, in1Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(in2Port, in2Pin, GPIO_PIN_RESET);
    return m;
}

// Set motor speed
void Motor_SetSpeed(Motor* motor, float speed) {
    if (speed > 1.0f) speed = 1.0f;
    if (speed < -1.0f) speed = -1.0f;

    uint32_t pwm = (uint32_t)(motor->htim->Init.Period * fabs(speed));

    if (speed > 0) {
        __HAL_TIM_SET_COMPARE(motor->htim, motor->channel, pwm);
        HAL_GPIO_WritePin(motor->in1Port, motor->in1Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(motor->in2Port, motor->in2Pin, GPIO_PIN_RESET);
    } else if (speed < 0) {
        __HAL_TIM_SET_COMPARE(motor->htim, motor->channel, pwm);
        HAL_GPIO_WritePin(motor->in1Port, motor->in1Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(motor->in2Port, motor->in2Pin, GPIO_PIN_SET);
    } else {
        Motor_Coast(motor);
    }
}

void Motor_Brake(Motor* motor) {
    HAL_GPIO_WritePin(motor->in1Port, motor->in1Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(motor->in2Port, motor->in2Pin, GPIO_PIN_SET);
    __HAL_TIM_SET_COMPARE(motor->htim, motor->channel, 0);
}

void Motor_Coast(Motor* motor) {
    HAL_GPIO_WritePin(motor->in1Port, motor->in1Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(motor->in2Port, motor->in2Pin, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(motor->htim, motor->channel, 0);
}