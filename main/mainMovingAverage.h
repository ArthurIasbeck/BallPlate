#include <Arduino.h>

#include "MovingAverage.h"
#include "Pin.h"

MovingAverage filter(FILTER_SIZE);

float input, output;

void setupRoot()
{
    Serial.begin(9600);
    while(!Serial);
}

void loopRoot()
{
    input = random(0,10);
    output = filter.compute(input);
    Serial.println(String(input) + "\t" + String(output));
    delay(1000);
}