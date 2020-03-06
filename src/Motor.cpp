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
    if(pos < infLimit) pos = infLimit;
    if(pos > supLimit) pos = supLimit;
    servo.write(pos + zeroPos);
}

void Motor::goZero()
{
    setPos(0);
}