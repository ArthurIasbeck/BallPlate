#include <Arduino.h>
#include "Motor.h"
#include "Pid.h"
#include "Pin.h"
#include "MovingAverage.h"
#include "Touch.h"

Touch touch;
MovingAverage filterX;
MovingAverage filterY;
Motor motorA;
Motor motorB;
Pid pidX;
Pid pidY;
float x; 
float y;
int countNoBall;
bool stopControl;
float controlX;
float controlY;
long dt;
long t0;
long tf; 
int Tm; 
int T;

void updatePosXY();
void controlStop();
void checkBall();
void applyControl();
void showData();
void waitSampleTime();

void setupRoot()
{
    Tm = 100;
    T = Tm*1000;

    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    filterX = MovingAverage(FILTER_SIZE);
    filterY = MovingAverage(FILTER_SIZE);
    motorA = Motor(MOT_A, -75, 75);
    motorB = Motor(MOT_B, -55, 75);

    // Configuração dos motores
    motorA.setupMotor();
    motorB.setupMotor();

    // Configurações do controlador PID (eixo x)
    pidX = Pid(1, 0, 0, 10);
    pidX.setLimits(-20, 20);
    pidX.setRef(0);

    // Configurações do controlador PID (eixo y)
    pidY = Pid(1, 0, 0, 10);
    pidY.setLimits(-20, 20);
    pidY.setRef(0);

    countNoBall = 0;
    stopControl = false;

    Serial.begin(9600);
    while(!Serial);

    motorA.goZero();
    motorB.goZero();

    Serial.println("Inicialização do código...");
    Serial.println("3"); delay(1000);
    Serial.println("2"); delay(1000);
    Serial.println("1"); delay(1000);

    dt = -1;
    t0 = micros();
}

void loopRoot()
{
    updatePosXY();
    checkBall();
    applyControl();
    showData();
    waitSampleTime();
}

/**
 * @brief Realiza a leitura da touchscreen e atualização das variáveis 
 * x e y que ditam a posição da esfera.  
 */
void updatePosXY()
{
    x = filterX.compute(touch.getCmX());
    y = filterY.compute(touch.getCmY());

    if(x == Touch::NO_BALL) countNoBall += 1;
    else countNoBall = 0;

    if(countNoBall == 5) stopControl = true; 
}

/**
 * @brief Verifica a presença da esfera sobre a mesa e interrompe a atuação 
 * do controlador PID caso a esfera tenha sido removida. 
 */
void checkBall()
{
    if(stopControl)
    {
        motorA.goZero();
        motorB.goZero();
        while(x == Touch::NO_BALL)
        {
            x = touch.getCmX();
        }
    }
}

/**
 * @brief Realiza a computação da ação de controle. 
 */
void applyControl()
{
    controlX = pidX.compute(x);
    controlY = pidY.compute(y);

    motorA.setPos(controlX);
    motorB.setPos(controlY);
}

void showData()
{
    Serial.print("x = " + String(x) + "|");
    Serial.print("y = " + String(y) + "|");
    Serial.print("controlX = " + String(controlX) + "|");
    Serial.print("controlY = " + String(controlY) + "|");
    Serial.print("dt = " + String(dt) + "|");
    Serial.print("\n");
}

void waitSampleTime()
{
    while(1)
    {
        tf = micros();
        dt = tf - t0;
        if(dt > T) break;
    }
    t0 = micros();
}