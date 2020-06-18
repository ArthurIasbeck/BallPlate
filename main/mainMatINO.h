#include<Arduino.h>
#include<MatlINO.h>

float A[N][N];
float At[N][N];
float B[N][N];
float C[N][N];

int n, m;

void setupRoot()
{
    Serial.begin(9600);
    while(!Serial);
}

void loopRoot()
{
    set(A, "[1, 2, 3; 4, 5, 6]", n, m);
    set(B, "[2, 5, 0; 2, 1, 1]");
    sum(C, A, B, n, m);
    trans(At, A, n, m);

    Serial.println("n = " + String(n));
    Serial.println("m = " + String(m));
    Serial.println("A[][] = " + String(A[0][0]));

    while(1);
}