#include "Touch.h"

Touch::Touch(int touchPin1, int touchPin2, int touchPin3, int touchPin4)
{
    this->touchPin1 = touchPin1;
    this->touchPin2 = touchPin2;
    this->touchPin3 = touchPin3;
    this->touchPin4 = touchPin4;

    xRaw = yRaw = xCm = yCm = 0;
    touching = false; 
}

Touch::Touch()
{
    
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
    return xRaw;
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
    return yRaw;
}

float Touch::getCmX()
{
    xRaw = getRawX();
    if(xRaw > 10)
    {
        touching = true;
        xCm = 0.0409*xRaw - 19.642;
    }
    else 
    {
        touching = false;
    }
    
    return xCm;
}

float Touch::getCmY()
{
    yRaw = getRawY();
    if(yRaw > 10)
    {
        touching = true;
        yCm = 0.0354*yRaw - 16.612;
    }
    else 
    {
        touching = false; 
    }

    return yCm;
}

boolean Touch::isTouching()
{
    return touching;
}