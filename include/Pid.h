#ifndef Pid_h
#define Pid_h

#include "Arduino.h"

class Pid
{
    public:
        Pid(float kp, float ki, float kd, float T);
        float compute(float out); 
        void setLimits(float infLim, float supLim);
        void setRef(float ref);
        float getErr();
    private:
        float kp, ki, kd;
        float ref;
        float err, errPrev;
        float T; 
};

#endif