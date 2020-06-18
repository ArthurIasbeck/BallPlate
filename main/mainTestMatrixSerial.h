#include<Arduino.h>

void setupRoot()
{
    Serial.begin(2000000);
    while(!Serial);

    float A[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            A[i][j] = -999;
        }
    }

    String str = "[1.5, 2; 4, 5]"; 

    int i = 0;
    int j = 0;
    int n;
    int m;
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

void loopRoot()
{
    
}