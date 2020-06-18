#include "IasbeckMatrix.h"

// void IasbeckMatrix::print()
// {
//     for(int i = 0; i < N)
// }

void IasbeckMatrix::set(String str)
{
    int i = 0;
    int j = 0;

    String element = ""; 
    char chr;
    for(int k = 1; k < (int)str.length(); k++)
    {
        Serial.println("----------------------------------------");
        Serial.println("k = " + String(k));
        chr = str[k];
        Serial.println("chr = " + String(chr));

        if(chr == ',' || chr == ';' || chr == ']')
        {
            Serial.println("Virgula ou ponto e virgula!");
            A[i][j] = element.toFloat();
            Serial.println("A[" + String(i) + "][" + String(j) + "] = " + String(A[i][j]));
            element = "";
            if(chr == ','){
                Serial.println("Nova coluna!");
                j++;
                // m++;
            }
            else if(chr == ';'){
                Serial.println("Nova linha!");
                i++;
                // n++;
                j = 0;
            }
        }
        else
        {
            if(chr != ' ')
            {
                Serial.println("Construindo elemento!");
                element += chr;
                Serial.println("element = " + element);
            }
            else
            {
                Serial.println("Eh so um espaco!");
            }
        }
    }

    n = i + 1;
    m = j + 1;

    Serial.println("============================================");
    Serial.println("Apresentando a matriz!");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Serial.print(String(A[i][j]) + "\t");
        }
        Serial.println();
    }
}

void IasbeckMatrix::print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Serial.print(String(A[i][j]) + "\t");
        }
        Serial.println();
    }
}

// void IasbeckMatrix::sum(IasbeckMatrix X, IasbeckMatrix Y)
// {
//     m = X.m;
//     n = X.n;

//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             A[i][j] = X.A[i][j] + Y.A[i][j];
//         }
//     }
// }

void sum(IasbeckMatrix& Z, const IasbeckMatrix& X, const IasbeckMatrix& Y)
{
    Serial.println("COMEÇANDO SOMA!!!!");
    for(int i = 0; i < X.n; i++)
    {
        for(int j = 0; j < X.m; j++)
        {
            Z.A[i][j] = X.A[i][j] + Y.A[i][j];
            Serial.println(Z.A[i][j]);
        }
    }
    Z.n = X.n;
    Z.m = X.m;
    Z.print();
}
