#include <Arduino.h>
#include "PidBp.h"
#include "../test/TouchTest.h"

PidBp pidBp;
TouchTest testTouch;

void setup() {
    testTouch.setup();
}

void loop() {
    testTouch.loop();
}