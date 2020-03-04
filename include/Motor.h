#ifndef Motor_h
#define Motor_h

#include "Servo.h"
#include "Arduino.h"

class Motor
{
    public:
        Motor(int controlPin, int zeroPos, int infLim, int supLim); 
        void setupMotor();
        void setPos(int pos);
        void goZero();
    private:
        int controlPin;
        int zeroPos;
        int infLimit, supLimit;
        Servo servo;
};

#endif