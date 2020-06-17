#include "Matrix.h"

Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
}

Matrix::Matrix(int n, int m, String name)
{
    this->n = n;
    this->m = m;
    this->name = name;
}

Matrix::Matrix(float* A0, int n, int m)
{
    this->n = n;
    this->m = m;
    set(A0);
}

Matrix::Matrix(float* A0, int n, int m, String name)
{
    this->n = n;
    this->m = m;
    this->name = name;
    set(A0);
}

float Matrix::get(int i, int j) const
{
    return A[i][j];
}

void Matrix::set(float value, int i, int j)
{
    if(i > this->n || j > this->m || i < 0 || j < 0)
    {
        Serial.println("i ou j definidos de forma errada!");  
        return; 
    }

    A[i][j] = value; 
}

void Matrix::set(float* A0)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = *(A0 + j + i*m);
        }
    }
}

void Matrix::print()
{
    Serial.println(name);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Serial.print(String(A[i][j]) + "\t");
        }
        Serial.println();
    }
}

void Matrix::sum(const Matrix& B, const Matrix& C)
{ 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = B.get(i,j) + C.get(i,j);
        }
    }
}

void Matrix::equal(const Matrix& B)
{ 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = B.get(i,j);
        }
    }
}

void Matrix::sub(const Matrix& B, const Matrix& C)
{ 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = B.get(i,j) - C.get(i,j);
        }
    }
}

void Matrix::trans(const Matrix &B)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = B.get(j,i);
        }
    }
}