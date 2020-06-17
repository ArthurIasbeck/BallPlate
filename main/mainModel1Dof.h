/**
 * @file mainModel1Dof.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Coleta de dados para modelagem no eixo x.
 * @details Neste arquivo a coleta de dados no eixo x foi realizada 
 * enquanto a posição do motor A é determinada a partir da leitura 
 * do potenciômetro A. O objetivo aqui é realizar uma coleta de dados 
 * finita dos valores de x à medida em que a mesa é controlada pelo 
 * usuário. 
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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