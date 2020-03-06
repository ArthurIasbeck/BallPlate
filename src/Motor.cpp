#include "Motor.h"

Motor::Motor(int controlPin, int zeroPos, int infLim, int supLim)
{
    this->controlPin = controlPin;
    this->zeroPos = zeroPos;
    this->infLimit = infLimit;
    this->supLimit = supLimit;
}

Motor::Motor()
{
    
}

void Motor::setupMotor()
{
    servo.attach(controlPin);
}

void Motor::setPos(int pos)
{
    float realPos;
    realPos = pos + zeroPos;
    if(realPos < infLimit) realPos = infLimit;
    if(realPos > supLimit) realPos = supLimit;
    servo.write(realPos);
}

void Motor::goZero()
{
    setPos(0);
}