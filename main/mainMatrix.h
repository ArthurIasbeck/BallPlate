#include "Arduino.h"
#include "Matrix.h"
#include "Pin.h"

float Ai[2][2] = {{1, 3}, {2, 8}};
float Bi[2][2] = {{2, 2}, {1, 5}};

Matrix A((float*) Ai, 2, 2, "A");
Matrix B((float*) Bi, 2, 2, "B");
Matrix C(2, 2, "C");

void setupRoot()
{
    Serial.begin(2000000);
    while(!Serial);

    A.print();
    B.print(); 
    
    C.sum(A, B);
    C.print();
}

void loopRoot()
{

}

