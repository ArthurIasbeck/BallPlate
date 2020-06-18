/**
 * @file main.cpp
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Definição das funções setup() e loop().
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../main/mainMotor.h"

/**
 * @brief Função setup() principal.
 * 
 * @details Função setup() que será de fato executado pelo Arduino. Note 
 * que esta função realiza a chamada da função setupRoot(), que se 
 * comportará de acordo com a classe incluida ao início deste arquivo. 
 */
void setup()
{
    setupRoot();
}

/**
 * @brief loop() que será de fato executado pelo Arduino. Note que esta
 * função realiza a chamada da função looppRoot(), que se comportará de 
 * acordo com a classe incluida ao início deste arquivo. 
 * 
 */
void loop()
{
    loopRoot();
}
