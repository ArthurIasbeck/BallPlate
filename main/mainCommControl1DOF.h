/**
 * @file mainCommControl1DOF.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Implementação do controle 1DOF baseado na comunicação com o Matlab.
 * @details Neste arquivo estão definidas as funções utilizadas na implementação de um controlador
 * genérico considerando apenas a direção x do Ball and Plate. Observe que aqui a leitura da tela
 * é realizada, o valor é enviado ao Matlab, a ação de controle é recebida e aplicada aos motores. 
 * A lei de controle implementada no Matlab não interefere no funcionamento deste código. O que 
 * importa é que o Matlab computará o valor da ação de controle e enviará ao Arduino. 
 * de estados. 
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Arduino.h"
#include "Touch.h"
#include "Motor.h"
#include "SerialComm.h"
#include "Pin.h"

Touch touch;
Motor motor;
SerialComm serialComm;
float x;
float u;
char flag; 
long startLoopTime; 

/*
 * flag values:
 * s - send
 * r - receive
 * t - touch wait
 * a - actuate
 * w - wait Ts
 */

void setupRoot()
{
    touch.setupTouch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    motor.setupMotor(MOT_A, -90, 90);
    serialComm.setupComm();

    motor.invertMotor();

    flag = 's';
}

void loopRoot()
{
    // Leitura da tela
    if(flag == 's')
    {
        startLoopTime = micros();
        x = touch.getX();
        if(touch.isTouching())
        {
            serialComm.sendData(x);
            flag = 'r';
        }
        else 
        {
            flag = 't';
        }
    }

    // Estado de espera pro caso da bola ter sido removida  
    if(flag == 't')
    {
        while(!touch.isTouching())
        {
            touch.getX();
        }
        flag = 's';
    }

    // Recebimento da ação de controle
    if(flag == 'r')
    {
        u = serialComm.rcvData();
        if(serialComm.dataReceived()) flag = 'a';
    }

    // Atuação nos motores
    if(flag == 'a')
    {
        motor.setPos(u*180/PI);
        flag = 'w';
    }

    // Espera do tempo de amostragem
    if(flag == 'w')
    {
        flag = 's';
        while (micros() - startLoopTime < T_S*1000);
    }
}