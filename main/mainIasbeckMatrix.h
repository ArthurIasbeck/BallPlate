#include<Arduino.h>
#include<IasbeckMatrix.h>

void setupRoot()
{
    Serial.begin(2000000);
    while(!Serial);
    IasbeckMatrix A, B, C, D;
    A.set("[1, 2; 3, 4]");
    B.set("[2.44, 3.14; 1, 2]");
    D.set("[0, 0; 0, 0]");

    Serial.println("A");
    A.print();
    Serial.println("B");
    B.print();

    sum(C, A, B);
    Serial.println("C");
    C.print();

    // F = *(sum(C, D));

    

}

void loopRoot()
{

}