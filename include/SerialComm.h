/**
 * @file SerialComm.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Cabeçalho da classe SerialComm.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SerialComm_h
#define SerialComm_h

#include "Arduino.h"
#include "Pin.h"

#define MSG_BREAK 'X'

//! Implementa funções para comunicação serial.
class SerialComm
{
    public:
        /**
         * @brief Constrói um novo objeto SerialComm.
         * 
         */
        SerialComm();
        /**
         * @brief Inicializa a comunicação serial.
         * 
         */
        void setupComm();
        /**
         * @brief Determina o número de casas após a vírgula que será 
         * adotado no envio das mensagens.
         * 
         * @param precision Número de casas após a vírgula.
         */
        void setPrecision(int precision);
        /**
         * @brief Realiza o envio de mensagens do tipo string.
         * 
         * @param data Mensagem (string) a ser enviada.
         */
        void sendData(String data);
        /**
         * @brief Realiza o envio de mensagens do tipo float.
         * 
         * @param data Mensagem (float) a ser enviada.
         */
        void sendData(float data);
        /**
         * @brief Realiza o envio de mensagens compostas por vários 
         * elementos do tipo float. 
         * 
         * @param data Vetor contendo os dados (float) a serem enviados.
         * @param sizeData Número de dados a serem enviados.
         */
        void sendData(float data[], int sizeData);
        /**
         * @brief Realiza o recebimento de dados do tipo float. 
         * 
         * @return Dado (float) recebido. 
         */
        float rcvData();
        /**
         * @brief Realiza o recebimento de dados compostos por vários
         * elementos do tipo float. 
         * 
         * @param rcvFloat Endereço da primeira posição do vetor que 
         * armazenará, após a chamada da função, os dados (floats) 
         * recebidos. 
         * @param sizeData Número de dados a serem recebidos.
         */
        void rcvData(float* rcvFloat, int sizeData);
        /**
         * @brief Retorna uma flag que indica se a chamada da função
         * rcvData() resultou na leitura de algum dado, ou seja, se 
         * algum dado foi de fato recebido.
         * 
         * @return true - Houve recebimento de dados. 
         * @return false - Não havia dados a serem lidos. 
         */
        bool dataReceived();
    private:
        void serialClear();
        bool received; 
        int precision; 
};

#endif