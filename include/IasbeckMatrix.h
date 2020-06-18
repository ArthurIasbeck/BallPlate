#ifndef IasbeckMatrix_h
#define IasbeckMatrix_h

#include<Arduino.h>

#define N 10

class IasbeckMatrix{
    public:
        void set(String str);
        void print();
        float A[N][N];
        int n; 
        int m;
};

void sum(IasbeckMatrix& Z, const IasbeckMatrix& X, const IasbeckMatrix& Y);

#endif