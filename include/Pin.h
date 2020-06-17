/**
 * @file Pin.h
 * @author Arthur Iasbeck (arthuriasbeck@gmail.com)
 * @brief Arquivo de configurações.
 * @details Neste arquivo estão definidas diversas constantes essenciais ao
 * funcionamento do restante do código, como os pinos em que estão conectados
 * os principais componentes, por exemplo. 
 * @version 0.1
 * @date 2020-06-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef Pin_h
#define Pin_h

#include "Arduino.h"

#define TOUCH_1 A1 // Fio preto
#define TOUCH_2 A2 
#define TOUCH_3 A0
#define TOUCH_4 A3

#define MOT_A 3
#define MOT_B 5

#define POT_A A4
#define POT_B A5

#define FILTER_SIZE 5

#define BAUD_RATE 2000000

#define T_S 40 // ms

#endif