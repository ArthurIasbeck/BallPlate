#include "../include/TouchTest.h"

void TouchTest::setup()
{
    Serial.begin(9600);
    while(!Serial);
}

void TouchTest::loop()
{
    showRawValues();
    delay(100);
}

void TouchTest::showRawValues()
{
    Serial.print("getRawX" + String(touch.getRawX) + "\t");
    Serial.println("getRawY" + String(touch.getRawY));
}