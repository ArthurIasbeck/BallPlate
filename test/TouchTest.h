#ifndef TouchTest_h
#define TouchTest_h

#include "Touch.h"

//! Verifica o funcionamento da classe Touch
class TouchTest{
    public:
        //! Função setup() para verificação do funcionamento da classe Touch.
        void setup();
        //! Função loop() para verificação do funcionamento da classe Touch.
        void loop();
        //! Apresenta no Monitor Serial os valores brutos da touchscreen nas direções X e Y.
        void getRawValues();
    private:
        Touch touch;
};

#endif