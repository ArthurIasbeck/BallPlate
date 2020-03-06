#ifndef Motor_h
#define Motor_h

#include "Servo.h"
#include "Arduino.h"

//! Implementa funções para controle dos servomotores.
class Motor
{
    public:
        /**
         * @brief Constrói um objeto Motor.
         * 
         * @param controlPin Controle PWM do motor.
         * @param zeroPos Posição (0 - 180) em que será definido o zero.
         * @param infLim Limite inferior para a posição do motor (-90 - 90).
         * @param supLim Limite superior para a posição do motor (-90 - 90).
         */
        Motor(int controlPin, int zeroPos, int infLim, int supLim); 
        /**
         * @brief Constrói um objeto Motor padrão.
         */
        Motor();
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
         * @brief Envia o motor para a posição 0.
         */
        void goZero();
    private:
        int controlPin;
        int zeroPos;
        int infLimit, supLimit;
        Servo servo;
};

#endif