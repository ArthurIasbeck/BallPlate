#ifndef PidBp_h
#define PidBp_h

#include "Arduino.h"

//! Implementa o controle do Ball and Plate utilizano PID. 
class PidBp
{
    public:
        //! Função setup() para implementação do controle PID.
        void setup();
        //! Função loop() para implementação do controle PID.
        void loop();
};

#endif