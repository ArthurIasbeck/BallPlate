#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

/**
 * @brief Realiza a leitura da touchscreen.
 */
class Touch
{
    public:
        /**
         * @brief Constrói um objeto Touch.
         * 
         * @param touchPin1 Pino 1 da touchscreen.
         * @param touchPin2 Pino 2 da touchscreen.
         * @param touchPin3 Pino 3 da touchscreen.
         * @param touchPin4 Pino 4 da touchscreen.
         */
        Touch(int touchPin1, int touchPin2, int touchPin3, int touchPin4);
        /**
         * @brief Constrói um objeto Touch padrão.
         */
        Touch();
        /**
         * @brief Retorna o valor bruto (0-1023) lido no eixo X.
         * 
         * @return Valor bruto lido no eixo X (0-1023) 
         */
        int getRawX();
        /**
         * @brief Retorna o valor bruto (0-1023) lido no eixo Y.
         * 
         * @return Valor bruto lido no eixo YS (0-1023) 
         */
        int getRawY();
        /**
         * @brief Retorna a posição do toque em cm no eixo X.
         * 
         * @return Posição no eixo X. 
         */
        float getCmX();
        /**
         * @brief Retorna a posição do toque em cm no eixo Y.
         * 
         * @return Posição no eixo Y. 
         */
        float getCmY();
        bool isTouching();
    private:
        int touchPin1, touchPin2, touchPin3, touchPin4;
        float xRaw, yRaw;
        float xCm, yCm;
        bool touching;
};

#endif