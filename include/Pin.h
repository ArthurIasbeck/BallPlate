/**
 * @brief Arquivo criado para definição das conexões físicas do arduino e de 
 * outras variáveis de vital importância ao funcionamento dos códigos contidos 
 * no projeto.
 */

#ifndef Pin_h
#define Pin_h

#include "Arduino.h"

static const int TOUCH_1 = A1; // Fio preto
static const int TOUCH_2 = A2; 
static const int TOUCH_3 = A0; 
static const int TOUCH_4 = A3; 

static const int MOT_A = 5;
static const int MOT_B = 3;

static const int POT_A = A4;
static const int POT_B = A5;

static const int FILTER_SIZE = 5;

#endif