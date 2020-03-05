#ifndef MovingAverage_h
#define MovingAverage_h

#include "Arduino.h"

#define MAX_SIZE 20

class MovingAverage
{
    public:
        MovingAverage(int filterSize);
        float compute(float input);
    private:
        int filterSize;
        int lastInputs[MAX_SIZE];
};

#endif