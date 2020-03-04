#include "Touch.h"

int Touch::getRawX()
{
    pinMode(TOUCH_3, INPUT);
    pinMode(TOUCH_1, INPUT);
    digitalWrite(TOUCH_1, LOW);
    pinMode(TOUCH_2, OUTPUT);
    digitalWrite(TOUCH_2, LOW);
    pinMode(TOUCH_4, OUTPUT);
    digitalWrite(TOUCH_4, HIGH);
    delay(3);
    xRaw = analogRead(TOUCH_3);
}

int Touch::getRawY()
{
    pinMode(TOUCH_3, OUTPUT);
    digitalWrite(TOUCH_3, HIGH);
    pinMode(TOUCH_1, OUTPUT);
    digitalWrite(TOUCH_1, LOW);
    pinMode(TOUCH_2, INPUT);
    pinMode(TOUCH_4, INPUT);
    digitalWrite(TOUCH_4, LOW);
    delay(3);
    yRaw = analogRead(TOUCH_2);
}