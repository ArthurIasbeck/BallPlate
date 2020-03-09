#include <Arduino.h>

#include "Touch.h"
#include "Pin.h"

Touch touch;
int xRaw, yRaw;
float x, y;

void setupRoot() {
    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    Serial.begin(BAUD_RATE);
    while(!Serial);
}

void loopRoot() {
    xRaw = touch.getRawX();
    yRaw = touch.getRawY();
    x = touch.getCmX();
    y = touch.getCmY();
    Serial.print(String(xRaw) + "\t" + String(yRaw) + "\t");
    Serial.println(String(x) + "\t" + String(y));
    delay(2000);   
}