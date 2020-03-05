#ifndef PidBp_h
#define PidBp_h

#include "Arduino.h"
#include "Touch.h"
#include "Motor.h"
#include "Pin.h"
#include "MovingAverage.h"

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
        MovingAverage filterX;
        MovingAverage filterY;
        Motor motorA;
        Motor motorB;
};

#endif