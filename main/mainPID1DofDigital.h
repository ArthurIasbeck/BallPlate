#include "Arduino.h"
#include "Motor.h"
#include "PidDigital.h"
#include "Pin.h"
#include "MovingAverage.h"
#include "Touch.h"

Touch touch;
MovingAverage filterX;
Motor motorA;
PidDigital pidX;
float x; 
int countNoBall;
bool stopControl;
float controlX;
long dt;
long t0;
long tf; 
long Tm; 
long T;
int countStop;

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

    dt = -1;
    Tm = 10;
    T = Tm*1000;
    countStop = 0;
    countNoBall = 0;
    stopControl = false;

    touch = Touch(TOUCH_1, TOUCH_2, TOUCH_3, TOUCH_4);
    filterX = MovingAverage(FILTER_SIZE);
    motorA = Motor(MOT_A, -70, 70);
    
    // Configuração dos motores
    motorA.setupMotor();
    motorA.invertMotor();

    // Configurações do controlador PID para o motor A (eixo x)
    pidX = PidDigital(0.6357, 0.3643, 191, -380.22, 189.1, 10);
    pidX.setLimits(-75, 75);
    pidX.setRef(0);

    motorA.goZero();

    Serial.println("Inicialização do código...");
    delay(1);

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
    x = touch.getCmX(); 

    if(!touch.isTouching())
    {
        countStop++;
    } 
    else 
    {
        countStop = 0;
    }
    if(countStop == 3)  stopControl = true;
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
        while(!touch.isTouching())
        {
            x = touch.getCmX();
        }
        stopControl = false;
        countStop = 0;
    }
}

/**
 * @brief Realiza a computação da ação de controle. 
 */
void applyControl()
{
    controlX = pidX.compute(x);

    motorA.setPos(controlX);
}

void showData()
{
    Serial.print("x = " + String(x) + "|");
    Serial.print("uX = " + String(controlX) + "|");
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