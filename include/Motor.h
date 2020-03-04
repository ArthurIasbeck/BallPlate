#ifndef Motor_h
#define Motor_h

#include "Servo.h"
#include "Arduino.h"

//! Realiza leitura da touchscreen.
class Motor
{
    public:
        // TODO: Neste construtor preciso dar o atacch. Uma função na classe Motors vai mandar os dois motores pra posição 0.
        Motor(int controlPin, int zeroPos); 
        void setPos(int pos);
        void goZero();
    private:
        int controlPin;
        int zeroPos;
};

#endif