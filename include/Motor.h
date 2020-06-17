/**
 * @file Motor.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Cabeçalho da classe Motor.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef Motor_h
#define Motor_h

#include "Servo.h"
#include "Arduino.h"

//! Implementa funções para controle dos servomotores.
class Motor
{
    public:
        /**
         * @brief Inicializa o objeto Motor.
         * 
         * @param controlPin Pino de controle (PWM) do motor.
         * @param infLim Limite inferior para a posição do motor (-90 - 0).
         * @param supLim Limite superior para a posição do motor (0 - 90).
         */
        void setupMotor(int controlPin, int infLimit, int supLimit); 
        /**
         * @brief Realiza configurações iniciais do motor.
         */
        void setupMotor();
        /**
         * @brief Envia o motor para uma dada posição.
         * 
         * @param pos Posição para a qual é enviada o motor.
         */
        void setPos(int pos);
        /**
         * @brief Define o zero do motor (igual a 90 por padrão).
         * 
         * @param zeroPos Posição considerada como zero do motor (0 - 180). 
         */
        void setZero(int zeroPos);
        /**
         * @brief Envia o motor para a posição 0.
         */
        void goZero();
        /**
         * @brief Inverte a direção do giro dos motores quando chamada.
         */
        void invertMotor();
    private:
        int controlPin;
        int zeroPos;
        int infLimit, supLimit;
        int direction;
        Servo servo;
};

#endif