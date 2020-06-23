/**
 * @file testTouch.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Teste da classe Touch. 
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Arduino.h>

#include "Touch.h"
#include "Pin.h"

Touch touch;
int xRaw, yRaw;
float x, y;
boolean isTouching;

/**
 * @brief Função setup() principal.
 * 
 */
void setupRoot() {
    touch.setupTouch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    Serial.begin(BAUD_RATE);
    while(!Serial);
}

/**
 * @brief Função setup() principal.
 * 
 */
void loopRoot() {
    xRaw = touch.getRawX();
    yRaw = touch.getRawY();
    x = touch.getCmX();
    y = touch.getCmY();
    isTouching = touch.isTouching();
    Serial.print(String(xRaw) + "\t" + String(yRaw) + "\t");
    Serial.print(String(x) + "\t" + String(y) + "\t");
    Serial.println(String(isTouching));
    delay(100);   
}