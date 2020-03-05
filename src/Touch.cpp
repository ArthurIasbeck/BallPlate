#include "Touch.h"

Touch::Touch(int touchPin1, int touchPin2, int touchPin3, int touchPin4)
{
    this->touchPin1 = touchPin1;
    this->touchPin2 = touchPin2;
    this->touchPin3 = touchPin3;
    this->touchPin4 = touchPin4;
}

int Touch::getRawX()
{
    pinMode(touchPin3, INPUT);
    pinMode(touchPin1, INPUT);
    digitalWrite(touchPin1, LOW);
    pinMode(touchPin2, OUTPUT);
    digitalWrite(touchPin2, LOW);
    pinMode(touchPin4, OUTPUT);
    digitalWrite(touchPin4, HIGH);
    delay(3);
    xRaw = analogRead(touchPin3);
}

int Touch::getRawY()
{
    pinMode(touchPin3, OUTPUT);
    digitalWrite(touchPin3, HIGH);
    pinMode(touchPin1, OUTPUT);
    digitalWrite(touchPin1, LOW);
    pinMode(touchPin2, INPUT);
    pinMode(touchPin4, INPUT);
    digitalWrite(touchPin4, LOW);
    delay(3);
    yRaw = analogRead(touchPin2);
}