#ifndef MotorTest_h
#define MotorTest_h

#include "Motor.h"
#include "Pin.h"

//! Verifica o funcionamento da classe Motor
class MotorTest{
    public:
        //! Função setup() para verificação do funcionamento da classe Motor.
        void setup();
        //! Função loop() para verificação do funcionamento da classe Motor.
        void loop();
    private:
        Motor motorA;
        Motor motorB;
        int readPotA, readPotB;
        int posA, posB;
};

#endif