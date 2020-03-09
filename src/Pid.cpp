#include "Pid.h"

Pid::Pid(float kp, float ki, float kd, float T)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->T = T;
}

Pid::Pid()
{

}

float Pid::compute(float out)
{
    float control; 
    float ie=0, de;

    err = ref - out;
    de = (errPrev - err)/T;
    ie = ie + err*T;

    // Zero o integrador para amenizar o overshoot
    if(err*errPrev < 0) ie = 0;

    control = kp*err + ki*ie + kd*de;

    if(control < infLim) control = infLim;
    if(control > supLim) control = supLim;

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