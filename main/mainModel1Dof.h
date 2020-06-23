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
#include "SerialComm.h"

Touch touch; 
Motor motorA;
SerialComm serialComm; 
int readPotA;
float posA;
long t0, tf, dt;
float x; 
long countLoops;
float data[4];

void setupRoot()
{
    countLoops = 0;
    motorA.setupMotor(MOT_A, -90, 90);
    touch.setupTouch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    serialComm.setupComm();
    serialComm.setPrecision(10);
    Serial.begin(BAUD_RATE);
    while(!Serial);
    t0 = micros();
}

void loopRoot()
{   
    readPotA = analogRead(POT_A);
    posA = readPotA*PI/1023 - PI/2;

    x = touch.getX();
    motorA.setPosRad(posA);

    data[0] = posA;
    data[1] = x;
    data[2] = dt;
    data[3] = countLoops;
    serialComm.sendData(data, 4);

    while(1)
    {
        tf = micros();
        dt = tf - t0;
        if(dt > 20000) break;
    }
    t0 = micros();
    countLoops++;
    
    if(countLoops == 1500)
    {
        data[0] = -999;
        data[1] = -999;
        data[2] = -999;
        data[3] = -999;
        serialComm.sendData(data, 4);
        while(1);
    }
}