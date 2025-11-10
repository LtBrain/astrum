#include <stdio.h>
#include <stdlib.h>

#define TIME_STEP 0.01 

typedef struct {
    float kp; // Proportional gain
    float ki; // Integral gain
    float kd; // Derivative gain

    float integral;
    float previous_error;
    
    float output;
} PID_Constants;

PID_Constants PIDController(float kp, float ki, float kd) {
    PID_Constants pid = {kp, ki, kd, 0, 0, 0};
    return pid;
}

double PIDCalculate(PID_Constants *pid, double position, double setpoint) {
    double error = setpoint - position;
    
    // P term
    double P = pid->kp * error;

    // I term
    pid->integral += error * TIME_STEP;
    double I = pid->ki * pid->integral;

    // D term
    double D = pid->kd * (error - pid->previous_error) / TIME_STEP;

    // store error for next step
    pid->previous_error = error;

    // total output
    pid->output = P + I + D;
    return pid->output;
}
