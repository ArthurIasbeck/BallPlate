#ifndef PidBp_h
#define PidBp_h

#include "Arduino.h"
#include "Touch.h"
#include "Motor.h"
#include "Pid.h"
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
        Pid pidX;
        Pid pidY;
        float x; 
        float y;
        void updatePosXY();
        void controlStop();
        void checkBall();
        void applyControl();
        void waitSampleTime();
        int countNoBall;
        bool stopControl;
        float controlX;
        float controlY;
        long dt;
        long t0;
        long tf; 
        int Tm; 
        int T;
};

#endif