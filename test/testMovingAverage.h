/**
 *@file testMovingAverage.h
 *@author Arthur Iasbeck (arthuriasbeck@gmail.com)
 *@brief Teste da classe MovingAverage. 
 *@details Uma sequência de números aleatórios é gerada e o filtro de 
 médias móveis é aplicado a eles a partir da implementação da classe 
 MovingAvarage. 
 *@version 0.1
 *@date 2020-06-23
 *
 *@copyright Copyright (c) 2020
 *
 */

#include <Arduino.h>

#include "MovingAverage.h"
#include "Pin.h"

MovingAverage filter(FILTER_SIZE);

float input, output;

/**
 * @brief Função setup() principal.
 * 
 */
void setupRoot()
{
    Serial.begin(BAUD_RATE);
    while(!Serial);
}

/**
 * @brief Função loop() principal.
 * 
 */
void loopRoot()
{
    input = random(0,10);
    output = filter.compute(input);
    Serial.println(String(input) + "\t" + String(output));
    delay(1000);
}