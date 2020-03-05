#ifndef PidBp_h
#define PidBp_h

#include "Arduino.h"
#include "Touch.h"
#include "Motor.h"
#include "Pin.h"

//! Implementa o controle do Ball and Plate utilizano PID. 
class PidBp
{
    public:
        //! Função setup() para implementação do controle PID.
        void setup();
        //! Função loop() para implementação do controle PID.
        void loop();
    private:
        Touch touch;
        Motor motorA;
        Motor motorB;
};

#endif