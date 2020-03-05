#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

// Pinos da touchscreen 
// touchPin1 A1 // Fio preto
// touchPin2 A2 
// touchPin3 A0
// touchPin4 A3

//! Realiza leitura da touchscreen.
class Touch
{
    public:
        Touch(int touchPin1, int touchPin2, int touchPin3, int touchPin4);
        //! Retorna o valor bruto (0-1023) lido no eixo X.
        int getRawX();
        //! Retorna o valor bruto (0-1023) lido no eixo Y.
        int getRawY();
    private:
        int touchPin1, touchPin2, touchPin3, touchPin4;
        int xRaw;
        int yRaw;
};

#endif