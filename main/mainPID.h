#include "Arduino.h"
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
long Tm; 
long T;

void updatePosXY();
void controlStop();
void checkBall();
void applyControl();
void showData();
void waitSampleTime();

void setupRoot()
{
    Serial.begin(BAUD_RATE);
    while(!Serial);

    Tm = 10;
    T = Tm*1000;

    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    filterX = MovingAverage(FILTER_SIZE);
    filterY = MovingAverage(FILTER_SIZE);
    motorA = Motor(MOT_A, -70, 70);
    motorB = Motor(MOT_B, -75, 80);
    
    // Configuração dos motores
    motorA.setupMotor();
    motorB.setupMotor();

    motorB.invertMotor();

    // Configurações do controlador PID para o motor A (eixo x)
    pidX = Pid(1, 1, 1, Tm);
    pidX.setLimits(-75, 75);
    pidX.setRef(0);
    pidX.debug = 1; // DEBUG

    // Configurações do controlador PID para o motor B (eixo y)
    pidY = Pid(1, 1, 1, Tm);
    pidY.setLimits(-55, 75);
    pidY.setRef(0);
    pidY.debug = 0; // DEBUG

    countNoBall = 0;
    stopControl = false;

    motorA.goZero();
    motorB.goZero();

    Serial.println("Inicialização do código...");
    delay(1);

    dt = -1;
    t0 = micros();
}

void loopRoot()
{
    updatePosXY();
    checkBall();
    applyControl();
    // showData();
    waitSampleTime();
}

/**
 * @brief Realiza a leitura da touchscreen e atualização das variáveis 
 * x e y que ditam a posição da esfera.  
 */
void updatePosXY()
{
    // x = filterX.compute(touch.getCmX()); // DEBUG
    // y = filterY.compute(touch.getCmY()); // DEBUG

    x = touch.getCmX(); // DEBUG
    y = touch.getCmY(); // DEBUG

    if(!touch.isTouching()) stopControl = true;
}

/**
 * @brief Verifica a presença da esfera sobre a mesa e interrompe a atuação 
 * do controlador PID caso a esfera tenha sido removida. 
 */
void checkBall()
{
    if(stopControl)
    {
        Serial.println("Bola removida!");
        motorA.goZero();
        motorB.goZero();
        while(!touch.isTouching())
        {
            x = touch.getCmX();
        }
        stopControl = false;
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
    Serial.print("uX = " + String(controlX) + "|");
    Serial.print("uY = " + String(controlY) + "|");
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