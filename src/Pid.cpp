/**
 * @file Pid.cpp
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Implementação da classe Pid.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Pid.h"

Pid::Pid(float kp, float ki, float kd, float T)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->T = T;

    ie = 0;
    errPrev = 0;
}

Pid::Pid()
{

}

float Pid::compute(float out)
{
    float control; 

    err = ref - out;
    de = (err - errPrev)/T;
    ie = ie + err*T;

    // Zero o integrador para amenizar o overshoot
    // if(err*errPrev < 0) ie = 0; // DEBUG

    control = kp*err + ki*ie + kd*de;

    // Serial.print(String(kp*err) + " ");
    // Serial.print(String(ki*ie) + " ");
    // Serial.print(String(kd*de) + " ");
    // Serial.print("\n");

    if(control < infLim) control = infLim;
    if(control > supLim) control = supLim;
    
    errPrev = err;

    return control;
}

void Pid::setLimits(float infLim, float supLim)
{
    this->infLim = infLim;
    this->supLim = supLim;
}

void Pid::setRef(float ref)
{
    this->ref = ref;
}

float Pid::getErr()
{
    return err;
}