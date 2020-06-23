/**
 * @file Motor.cpp
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Implementação da classe Motor.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Motor.h"

void Motor::setupMotor(int controlPin, int infLimit, int supLimit)
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

    servo.attach(controlPin);
}

void Motor::setPos(float realPos)
{
    int pos = round(realPos);
    pos *= direction;
    if(pos < infLimit) pos = infLimit;
    if(pos > supLimit) pos = supLimit;
    servo.write(pos + zeroPos);
}

void Motor::setPosRad(float radPos)
{
    float realPos = radPos*180/PI;
    setPos(realPos);
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
    direction *= -1;
}