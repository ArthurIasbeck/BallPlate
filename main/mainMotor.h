#include <Arduino.h>

#include "Pin.h"
#include "Motor.h"

Motor motorA(MOT_A, -50, 50);
Motor motorB(MOT_B, -50, 50);

int readPotA, readPotB;
int posA, posB;

void setupRoot()
{
    motorA.setupMotor();
    motorB.setupMotor();
    Serial.begin(9600);
    while(!Serial);
}

void loopRoot()
{
    readPotA = analogRead(POT_A);
    readPotB = analogRead(POT_B);

    posA = map(readPotA, 0, 1023, -90, 90);
    posB = map(readPotB, 0, 1023, -90, 90);

    motorA.setPos(posA);
    motorB.setPos(posB);

    Serial.print("readPotA = " + String(readPotA) + "\t");
    Serial.print("angServoA = " + String(posA) + "   |   ");
    Serial.print("readPotB = " + String(readPotB) + "\t");
    Serial.println("angServoB = " + String(posB));

    delay(100);
}