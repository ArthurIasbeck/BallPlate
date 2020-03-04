#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

// Pinos da touch screen 
#define TOUCH_1 A1 // Fio preto
#define TOUCH_2 A2 
#define TOUCH_3 A0
#define TOUCH_4 A3

//! Realiza leitura da touchscreen.
class Touch
{
    public:
        //! Retorna o valor bruto (0-1023) lido no eixo X.
        int getRawX();
        //! Retorna o valor bruto (0-1023) lido no eixo Y.
        int getRawY();
    private:
        int xRaw;
        int yRaw;
};

#endif