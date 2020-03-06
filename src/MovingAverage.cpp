#include "MovingAverage.h"

MovingAverage::MovingAverage(int stepsPast)
{
    // Inicializando o vetor que armazena os dados passados
    for(int i = 0; i < 20; i++)
    {
        lastInputs[i] = 0;
    }
    
    // Verificando a dimensão do filtro
    if (filterSize > 20) 
    {
        Serial.println("filterSize deve ser menor ou igual a 20!");
        filterSize = 20;
    }
    this->filterSize = filterSize;
}

MovingAverage::MovingAverage()
{
    
}

float MovingAverage::compute(float input)
{
    float output = 0;

    // Atualizando o vetor que armazena os dados passados
    for (int i = MAX_SIZE - 1; i > 0; i--)
    {
        lastInputs[i] = lastInputs[i-1];
    }
    lastInputs[0] = input;

    // Calculando o valor de saída do filtro
    for (int i = 0; i < filterSize; i++)
    {
        output += lastInputs[i];
    }
    output /= filterSize;

    return output;
}
