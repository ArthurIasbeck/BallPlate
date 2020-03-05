#include "PidBp.h"

void PidBp::setup()
{
    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    filterX = MovingAverage(FILTER_SIZE);
    filterY = MovingAverage(FILTER_SIZE);
    motorA = Motor(MOT_A, 90, -90, 90);
    motorB = Motor(MOT_B, 90, -90, 90);
    pidX = Pid(1, 0, 0, 10);

    countNoBall = 0;
    stopControl = false;

    Serial.begin(9600);
    while(!Serial);
}

void PidBp::loop()
{
    updatePosXY();
    checkBall();
    computeControl();
}

void PidBp::updatePosXY()
{
    x = filterX.compute(touch.getCmX());
    y = filterX.compute(touch.getCmY());

    if(x == Touch::NO_BALL) countNoBall += 1;
    else countNoBall = 0;

    if(countNoBall == 10) stopControl = true; 
}

void PidBp::checkBall()
{
    if(stopControl)
    {
        motorA.goZero();
        motorB.goZero();
        while(x == Touch::NO_BALL)
        {
            x = touch.getCmX();
        }
    }
}

void PidBp::computeControl()
{
    
}