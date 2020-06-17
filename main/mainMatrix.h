#include "Arduino.h"
#include "Matrix.h"
#include "Pin.h"

float Ai[2][2] = {{1, 3}, {2, 8}};
float Bi[2][2] = {{2, 2}, {1, 5}};

Matrix A((float*) Ai, 2, 2, "A");
Matrix B((float*) Bi, 2, 2, "B");
Matrix C(2, 2, "C");
Matrix At(2, 2, "At");
float AA[2][2];

void setupRoot()
{
    Serial.begin(2000000);
    while(!Serial);

    Serial.println("Apresentação das matrizes:");
    A.print();
    B.print(); 
    
    Serial.println("Soma das matrizes A e B:");
    C.sum(A, B);
    C.print();

    Serial.println("Igualando matrizes A e C:");
    A.equal(C);
    A.print();

    Serial.println("Subtraindo matrizes A e B");
    A.sub(B, C);
    B.print();
    C.print();
    A.print();

    // Serial.println("Transpondo a matriz A");
    // At.trans(A);
    // At.print();
}

void loopRoot()
{

}

