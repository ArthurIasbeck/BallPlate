/**
 * @file MovingAverage.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Cabeçalho da classe MovingAverage.
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MovingAverage_h
#define MovingAverage_h

#include "Arduino.h"

#define MAX_SIZE 20

//! Implementa um filtro de médias móveis.
class MovingAverage
{
    public:
        /**
         * @brief Constrói um objeto MovingAverage.
         * 
         * @param filterSize Número de dados considerado na computação da média.
         */
        MovingAverage(int filterSize);

        /**
         *@brief Constrói um objeto MovingAverage.
         *
         */
        MovingAverage();
        
        /**
         * @brief Retorna o dado filtrado (saída do filtro)
         * 
         * @param input último valor bruto lido.
         * @return Dado filtrado
         */
        float compute(float input);
    private:
        int filterSize;
        int lastInputs[MAX_SIZE];
};

#endif