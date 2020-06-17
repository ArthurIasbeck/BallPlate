/**
 * @file Touch.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Cabeçalho da classe Touch.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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
         * @brief inicializa objeto Touch.
         * 
         * @param touchPin1 Pino 1 da touchscreen.
         * @param touchPin2 Pino 2 da touchscreen.
         * @param touchPin3 Pino 3 da touchscreen.
         * @param touchPin4 Pino 4 da touchscreen.
         */
        void setupTouch(int touchPin1, int touchPin2, int touchPin3, int touchPin4);
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
        /**
         * @brief Retorna a posição do toque em m no eixo X.
         * 
         * @return Posição no eixo X.
         */
        float getX();
        /**
         * @brief Retorna a posição do toque em m no eixo Y.
         * 
         * @return Posição no eixo Y.
         */
        float getY();
        /**
         * @brief Boleano que indica se a tela está sendo pressionada. Esta função deve ser chamada 
         * após a utilização de alguma função get().
         * 
         * @return true se a tela estiver sendo tocada.  
         */
        boolean isTouching();
    private:
        int touchPin1, touchPin2, touchPin3, touchPin4;
        float xRaw, yRaw;
        float xCm, yCm;
        boolean touching;
};

#endif