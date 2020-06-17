/**
 * @file mainMotor.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Teste da classe Motor. 
 * @details Neste arquivo estão definidas as funções utilizadas no teste da classe 
 * Motor. Basicamente a posição dos motores é determinada a partir da leitura dos 
 * potênciômetros A e B, que são controlados pelo usuário. 
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Arduino.h>

#include "Pin.h"
#include "Motor.h"

int readPotA, readPotB;
int posA, posB;
Motor motorA, motorB;

void setupRoot()
{
    motorA.setupMotor(MOT_A, -90, 90);
    motorB.setupMotor(MOT_B, -90, 90);
    motorA.invertMotor();
    motorB.invertMotor();
    Serial.begin(BAUD_RATE);
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