#include "TouchTest.h"

void TouchTest::setup()
{
    Serial.begin(9600);
    while(!Serial);
}

void TouchTest::loop()
{
    getRawValues();
}

void TouchTest::getRawValues()
{
    Serial.print("getRawX" + String(touch.getRawX) + "\t");
    Serial.println("getRawY" + String(touch.getRawY));
    delay(100);
}