#include "PidBp.h"

void PidBp::setup()
{
    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    filterX = MovingAverage(FILTER_SIZE);
    filterY = MovingAverage(FILTER_SIZE);
    motorA = Motor(MOT_A, 90, -90, 90);
    motorB = Motor(MOT_B, 90, -90, 90);

    Serial.begin(9600);
    while(!Serial);
}

void PidBp::loop()
{

}