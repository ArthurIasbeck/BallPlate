#ifndef MatlINO_h
#define MatlINO_h

// O Arduino não é capaz de lidar com vetores bidimensionais (matrizes)
// porque sua memória é muito limitada

// https://arduino.stackexchange.com/questions/14369/arduino-uno-not-able-to-handle-2-dimensional-array

// https://br-arduino.org/2015/06/arduino-progmem-sram.html

#define N 10

void set(float A[N][N], String str, int &n, int &m);
void print(float A[N][N], int n, int m, String label);
void zeros(float A[N][N], int n, int m);
void sum(float A[N][N], float B[N][N], float C[N][N], int n, int m);

void set(float A[N][N], String str, int &n = &0, int &m = &0)
{
    int i = 0;
    int j = 0;

    String element = ""; 
    char chr;
    for(int k = 1; k < (int)str.length(); k++)
    {
        chr = str[k];

        if(chr == ',' || chr == ';' || chr == ']')
        {
            A[i][j] = element.toFloat();
            element = "";
            if(chr == ','){
                j++;
            }
            else if(chr == ';'){
                i++;
                j = 0;
            }
        }
        else
        {
            if(chr != ' ')
            {
                element += chr;
            }
        }
        n = i + 1;
        m = j + 1;
    }
}

void print(float A[N][N], int n, int m, String label = "")
{
    Serial.println(label);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            Serial.print(String(A[i][j]) + "\t");
        }
        Serial.println();
    }
}

void zeros(float A[N][N], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = 0;
        }
    }
}

void sum(float A[N][N], float B[N][N], float C[N][N], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = B[i][j] + C[i][j];
        }
    }
}

void trans(float At[N][N], float A[N][N], int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            At[i][j] = A[j][i];
        }
    } 
}

#endif