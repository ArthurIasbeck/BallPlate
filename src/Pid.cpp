#include "Pid.h"

Pid::Pid(float kp, float ki, float kd, float T)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->T = T;
}

void Pid::setRef(float ref)
{
    this->ref = ref;
}

float Pid::getErr()
{
    return err;
}

float Pid::compute(float out)
{
    float control; 
    float ie, de;

    err = ref - out;
    de = (errPrev - err)/T;
    ie = ie + err*T;

    // Zero o integrador para evitar overshoots muito altos
    if(err*errPrev < 0) ie = 0;

    control = kp*err + ki*ie + kd*de;
}