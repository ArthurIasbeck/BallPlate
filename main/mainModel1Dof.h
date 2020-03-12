#include <Arduino.h>

#include "Pin.h"
#include "Motor.h"
#include "Touch.h"

Touch touch; 
Motor motorA;
int readPotA;
int posA;
long t0, tf, dt;
float x; 
long countLoops;

void setupRoot()
{
    countLoops = 0;
    motorA = Motor(MOT_A, -90, 90);
    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    motorA.setupMotor();
    Serial.begin(BAUD_RATE);
    while(!Serial);
    t0 = micros();
}

void loopRoot()
{   
    readPotA = analogRead(POT_A);
    posA = map(readPotA, 0, 1023, -90, 90);

    x = touch.getCmX();
    motorA.setPos(posA);

    Serial.print(String(posA) + " ");
    Serial.print(String(x) + " ");
    Serial.print(String(dt));
    Serial.print("\n");

    while(1)
    {
        tf = micros();
        dt = tf - t0;
        if(dt > 10000) break;
    }
    t0 = micros();
    countLoops++;
    
    if(countLoops == 6000)
    {
        Serial.println("Fim do teste");
        while(1);
    }
}