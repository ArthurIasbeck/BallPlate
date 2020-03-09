#include "Pid.h"

Pid::Pid(float kp, float ki, float kd, float T)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    this->T = T;

    ie = 0;
}

Pid::Pid()
{

}

float Pid::compute(float out)
{
    float control; 

    err = ref - out;
    de = (err - errPrev);
    ie = ie + err;

    // Zero o integrador para amenizar o overshoot
    if(err*errPrev < 0) ie = 0;

    control = kp*err + ki*ie + kd*de;

    Serial.println("output = " + String(out));
    Serial.println("err = " + String(err));
    Serial.println("de = " + String(de));
    Serial.println("ie = " + String(ie));
    Serial.println("kp*err = " + String(kp*err));
    Serial.println("ki*ie = " + String(ki*ie));
    Serial.println("kd*de = " + String(kd*de));
    Serial.println("control = " + String(control));

    if(control < infLim) control = infLim;
    if(control > supLim) control = supLim;

    Serial.println("control = " + String(control));
    Serial.println("---------------------------------------------");

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