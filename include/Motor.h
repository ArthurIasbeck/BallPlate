#ifndef Motor_h
#define Motor_h

#include "Servo.h"
#include "Arduino.h"

//! Realiza leitura da touchscreen.
class Motor
{
    public:
        Motor(int controlPin, int zeroPos); 
        void setupMotor();
        void setPos(int pos);
        void goZero();
    private:
        int controlPin;
        int zeroPos;
        Servo servo;
};

#endif