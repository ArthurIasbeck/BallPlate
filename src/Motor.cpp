#include "Motor.h"

Motor::Motor(int controlPin, int infLimit, int supLimit)
{
    if(infLimit < -90) infLimit = -90;
    if(infLimit > 0) infLimit = 0;
    if(supLimit < 0) supLimit = 0;
    if(supLimit > 90) supLimit = 90;

    this->controlPin = controlPin;
    this->infLimit = infLimit;
    this->supLimit = supLimit;
    zeroPos = 90;
    direction = 1;
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
    pos *= direction;
    if(pos < infLimit) pos = infLimit;
    if(pos > supLimit) pos = supLimit;
    servo.write(pos + zeroPos);
}

void Motor::setZero(int zeroPos)
{
    this->zeroPos = zeroPos;
}

void Motor::goZero()
{
    setPos(0);
}

void Motor::invertMotor()
{
    direction = -1;
}