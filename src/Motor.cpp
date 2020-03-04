#include "Motor.h"

Motor::Motor(int controlPin, int zeroPos)
{
    this->controlPin = controlPin;
    this->zeroPos = zeroPos;
}

void Motor::setupMotor()
{
    servo.attach(controlPin);
}

void Motor::setPos(int pos)
{
    servo.write(pos + zeroPos);
}

void Motor::goZero()
{
    servo.write(zeroPos);
}