/**
 *@file mainTouchVar.h
 *@author Arthur Iasbeck (arthuriasbeck@gmail.com)
 *@brief Coleta de dados da tela touch para averiguação de ruídos.
 *@details Neste arquivo são implementadas funções para coleta de 
 valores da tela touch. Os valores são coletados e enviados ao PC
 juntamente com tempo de amostragem. O objetivo desta coleta é determinar
 a variância do ruído de medida para projeto do Filtro de Kalman. Vale
 ressaltar que o experimento realizado dura 20 segundos e seu fim 
 é ditado pelo Arduino.
 *@version 0.1
 *@date 2020-06-23
 *
 *@copyright Copyright (c) 2020
 *
 */

#include<Arduino.h>
#include<Pin.h>
#include<Touch.h>
#include<SerialComm.h>

Touch touch;
SerialComm serialComm; 
float x, y;
float data[3];
int k = 0;
unsigned long startTime; 
unsigned long Ts = 40000; // us

void setupRoot()
{
    touch.setupTouch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    serialComm.setupComm();
    serialComm.setPrecision(10);
}

void loopRoot()
{
    for(int k = 0; k < round(20000000/Ts) + 1; k++)
    {
        startTime = micros();
        x = touch.getX();
        y = touch.getY();
        data[0] = x;
        data[1] = y;
        data[2] = startTime;
        serialComm.sendData(data, 3);
        while (micros() - startTime < Ts);
    }
    data[0] = -999;
    data[1] = -999;
    data[2] = -999;
    serialComm.sendData(data, 3);
    while(1);
}