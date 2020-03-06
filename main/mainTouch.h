#include <Arduino.h>

#include "Touch.h"
#include "Pin.h"

Touch touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
int xRaw, yRaw;
float x, y;

void setupRoot() {
    Serial.begin(9600);
    while(!Serial);
}

void loopRoot() {
    xRaw = touch.getRawX();
    yRaw = touch.getRawY();
    x = touch.getCmX();
    y = touch.getCmY();
    Serial.print(String(xRaw) + "\t" + String(yRaw) + "\t");
    Serial.println(String(x) + "\t" + String(y));
    delay(100);   
}