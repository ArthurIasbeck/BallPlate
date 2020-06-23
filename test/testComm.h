/**
 * @file testComm.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Teste da classe SerialComm. 
 * @details Neste arquivo estão definidas as funções utilizadas para
 * verificação do funcionamento da classe SerialComm. Há funções para 
 * envio e recebimento de mensagens simples, e envio e recebimento de 
 * mensagens compostas. Além disso, há uma função que simula o 
 * funcionamento do algorítmo de controle e realiza, simultanemente o 
 * envio e recebimento de mensagens. 
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <Arduino.h>
#include "SerialComm.h"
#include "Pin.h"

SerialComm serialComm; 

char flag; 
long startTime; 
float rcvFloat; 
String rcvString;
float sendFloatMulti[2];
float rcvFloatMulti[2];

void loopSendRcv();
void loopRcv();
void loopSend();
void loopSendMult();
void loopRcvMult();
void loopSendRcvMult();

/**
 * @brief Função setup() principal.
 * 
 */
void setupRoot()
{
    serialComm.setupComm();
    flag = 's';
}

/**
 * @brief Função loop() principal. 
 * 
 */
void loopRoot()
{   
    loopRcv();
}

/**
 * @brief Função loop() para envio de mensagens.
 * 
 */
void loopSend()
{
    startTime = micros();
    serialComm.sendData(random(0, 10));
    while(micros() - startTime < T_S*1000);
}

/**
 * @brief Função loop() para recebimento de mensagens. 
 * 
 */
void loopRcv()
{
    startTime = micros();
    rcvString = serialComm.rcvData(true);
    if(serialComm.dataReceived())
    {
        serialComm.sendData(startTime);
        // while(micros() - startTime < 6000);
    }
}

/**
 * @brief Função loop() para recebimento e envio simultâneo de 
 * mensagens simples (que contém somente um dado).
 * 
 */
void loopSendRcv()
{
    // Envio das medições
    if (flag == 's')
    {
        startTime = micros();
        delay(6);
        serialComm.sendData(startTime);
        flag = 'r';
    }

    // Leitura da ação de controle
    if (flag == 'r')
    {
        rcvFloat = serialComm.rcvData();
        if(serialComm.dataReceived())
        {
            serialComm.sendData(rcvFloat);
            flag = 'a';
        }
    }

    // Atuação nos motores
    if (flag == 'a')
    {
        delay(1);
        flag = 'w';
    }

    // Espera do tempo de amostragem
    if (flag == 'w')
    {
        flag = 's';
        while (micros() - startTime < 15000);
    }
}

/**
 * @brief Função loop() para envio de mensagens compostas 
 * (que contém múltiplos dados).
 * 
 */
void loopSendMult()
{
    sendFloatMulti[0] = random(300)/100.0;
    sendFloatMulti[1] = random(300)/100.0;
    serialComm.sendData(sendFloatMulti, 2);
    while (micros() - startTime < 10000);
}

/**
 * @brief Função loop() para recebimento de mensagens compostas 
 * (que contém múltiplos dados).
 * 
 */
void loopRcvMult()
{
    serialComm.rcvData(&rcvFloatMulti[0], 2);
    if(serialComm.dataReceived())
    {
        serialComm.sendData(rcvFloatMulti, 2);
    }
}

/**
 * @brief Função loop() para recebimento e envio simultâneo
 * de mensagens compostas (que contém múltiplos dados).
 * 
 */
void loopSendRcvMult()
{
    // Envio das medições
    if (flag == 's')
    {
        startTime = micros();
        sendFloatMulti[0] = startTime;
        sendFloatMulti[1] = 1;
        delay(6);
        serialComm.sendData(sendFloatMulti, 2);
        flag = 'r';
    }

    // Leitura da ação de controle
    if (flag == 'r')
    {
        serialComm.rcvData(&rcvFloatMulti[0], 2);
        if(serialComm.dataReceived())
        {
            // serialComm.sendData(rcvFloatMulti, 2);
            flag = 'a';
        }
    }

    // Atuação nos motores
    if (flag == 'a')
    {
        delay(1);
        flag = 'w';
    }

    // Espera do tempo de amostragem
    if (flag == 'w')
    {
        flag = 's';
        while (micros() - startTime < 15000);
    }
}