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
    if(err*errPrev < 0) ie = 0;

    control = kp*err + ki*ie + kd*de;

    debug = 1; // DEBUG
    if(debug) // DEBUG
    { 
        Serial.print(String(out) + " ");
        Serial.print(String(err) + " ");
        Serial.print(String(de) + " ");
        Serial.print(String(ie) + " ");
        Serial.print(String(kp*err) + " ");
        Serial.print(String(ki*ie) + " ");
        Serial.print(String(kd*de) + " ");
        Serial.print(String(control) + " ");  
    }

    if(control < infLim) control = infLim;
    if(control > supLim) control = supLim;

    if(debug) // DEBUG
    {
        Serial.println(String(control));
    }
    
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