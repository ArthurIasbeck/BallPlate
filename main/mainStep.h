#include <Arduino.h>

#include "Pin.h"
#include "Motor.h"
#include "Touch.h"
#include "MovingAverage.h"

MovingAverage filter;
Touch touch; 
Motor motorA;
int readPotA;
int posA;
long t0, tf, dt;
float x; 
long countLoops;
int stepAmp, stepDir, stepTime;
long simTime, nStep, countStep;

void setupRoot()
{
    Serial.begin(BAUD_RATE);
    while(!Serial);

    filter = MovingAverage(3);
    motorA = Motor(MOT_A, -90, 90);
    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    motorA.setupMotor();

    simTime = 10;
    stepTime = 0.5;
    stepAmp = 10;
    countStep = countLoops = 0;
    stepDir = -1;
    nStep = round(1/0.01);

    Serial.println("Iniciando coleta...");
    motorA.goZero();

    delay(5000);

    t0 = micros();
}

void loopRoot()
{   
    motorA.setPos(stepAmp*stepDir);
    x = filter.compute(touch.getCmX());

    countStep++;

    if(countStep == nStep)
    {
        stepDir *= -1;
        countStep = 0;
    }
    
    Serial.print(String(stepAmp*stepDir) + " ");
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
    
    if(countLoops == round(simTime/0.01))
    {
        motorA.goZero();
        Serial.println("Fim do teste");
        while(1);
    }
}