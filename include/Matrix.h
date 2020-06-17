#ifndef Matrix_h
#define Matrix_h

#include <Arduino.h>

#define N_MAX 10

class Matrix
{
    public:
        Matrix(int n, int m);
        Matrix(int n, int m, String name);
        Matrix(float* A0, int n, int m);
        Matrix(float* A0, int n, int m, String name);
        float get(int i, int j);
        void set(float value, int i, int j);
        void set(float* A0);
        void print();
        void sum(const Matrix& B, const Matrix& C);

    private:
        float A[N_MAX][N_MAX];
        int n;
        int m; 
        String name; 
};

#endif