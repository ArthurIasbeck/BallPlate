#include "PidDigital.h"

PidDigital::PidDigital(float A, float B, float C, float D, float E, float T)
{
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    this->E = E;
    this->T = T;

    u2 = u1 = u = e2 = e1 = e = 0;
}

PidDigital::PidDigital()
{

}

float PidDigital::compute(float out)
{
    e = ref - out;

    u = A*u1 + B*u2 + C*e + D*e1 + E*e2;

    debug = 1; // DEBUG
    if(debug) // DEBUG
    { 
        Serial.print(String(out) + " ");
        Serial.print(String(e) + " ");
    }

    if(u < infLim) u = infLim;
    if(u > supLim) u = supLim;

    if(debug) // DEBUG
    {
        Serial.println(String(u));
    }
    
    u2 = u1;
    u1 = u;
    e2 = e1;
    e1 = e;

    return u;
}

void PidDigital::setLimits(float infLim, float supLim)
{
    this->infLim = infLim;
    this->supLim = supLim;
}

void PidDigital::setRef(float ref)
{
    this->ref = ref;
}

float PidDigital::getErr()
{
    return e;
}