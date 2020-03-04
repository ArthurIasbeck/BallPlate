#include <Arduino.h>
#include "PidBp.h"
#include "TouchTest.h"
#include "MotorTest.h"

PidBp pidBp;
TouchTest testTouch;
MotorTest motorTest;

void setup() {
    motorTest.setup();
}

void loop() {
    motorTest.loop();
}

/**
 * TODO: Implementar função para retornar posição da esfera em centímetros
 * TODO: Testar a classe Motor
 * TODO: Testar a classe Touch 
 * TODO: Implementar o controle PID
 */