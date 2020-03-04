#include "MotorTest.h"

void MotorTest::setup()
{
    motorA = Motor(MOT_A, 90, -90, 90);
    motorB = Motor(MOT_B, 90, -90, 90);

    motorA.setupMotor();
    motorB.setupMotor();

    Serial.begin(9600);
    while(!Serial);
}

void MotorTest::loop()
{
    readPotA = analogRead(POT_A);
    readPotB = analogRead(POT_B);

    posA = map(readPotA, 0, 1023, 0, 180);
    posB = map(readPotB, 0, 1023, 0, 180);

    motorA.setPos(posA);
    motorB.setPos(posB);

    Serial.print("readPotA = " + String(readPotA) + "\t");
    Serial.print("angServoA = " + String(posA) + "   |   ");
    Serial.print("readPotB = " + String(readPotB) + "\t");
    Serial.println("angServoB = " + String(posB));

    delay(100);
}