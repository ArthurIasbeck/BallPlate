#include <Arduino.h>
#include <Vector.h>

Vector<int> vector;

void setupRoot()
{
    Serial.begin(2000000);
    while(!Serial);

    vector.push_back(1);
    vector.push_back(4);
    vector.push_back(8);
    vector.push_back(11);

    Serial.println("vector[0] = " + String(vector[0]));
    Serial.println("vector[1] = " + String(vector[1]));
    Serial.println("vector[2] = " + String(vector[2]));
    Serial.println("vector[3] = " + String(vector[3]));
}

void loopRoot()
{

}