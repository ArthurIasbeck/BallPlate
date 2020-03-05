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
    float xRaw;
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
    float yRaw;
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

float Touch::getCmX()
{
    float xRaw, xCm;
    xRaw = getRawX();
    if(xRaw <= 10)
    {
        xCm = NO_BALL;
    }
    else
    {
        xCm = -20.2769 + 0.043315402*xRaw;
    }
}

float Touch::getCmY()
{
    float yRaw, yCm;
    yRaw = getRawY();
    if(yRaw <= 10)
    {
        yCm = NO_BALL;
    }
    else
    {
        yCm = -20.2769 + 0.043315402*yRaw;
    }
}