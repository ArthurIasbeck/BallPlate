#ifndef PidDigital_h
#define PidDigital_h

#include "Arduino.h"

class PidDigital
{
    public:
        /**
         * @brief Constrói um objeto PID.
         * 
         * @param kp Constante proporcional.
         * @param ki Constante integral.
         * @param kd Constante derivativa.
         * @param T Tempo de amostragem (em milissegundos).
         */
        PidDigital(float A, float B, float C, float D, float E, float T);
        /**
         * @brief Constrói um objeto PID padrão.
         */
        PidDigital();
        /**
         * @brief Computa a ação de controle.
         * 
         * @param out Saída do sistema (valor advindo do sensor).
         * @return Ação de controle.
         */
        float compute(float out); 
        /**
         * @brief Define os limites da ação de controle.
         * 
         * @param infLim Limite inferior da ação de controle.
         * @param supLim Limite superior da ação de controle.
         */
        void setLimits(float infLim, float supLim);
        /**
         * @brief Define a referência.
         * 
         * @param ref Referência (valor desejado para a saída).
         */
        void setRef(float ref);
        /**
         * @brief Retorna o valor do erro.
         * 
         * @return Erro computado na última iteração.
         */
        float getErr();

        int debug; // DEBUG
    private:
        float A, B, C, D, E;
        float ref;
        float u, u1, u2;
        float e, e1, e2;
        float T; 
        float ie, de;
        float infLim, supLim;
};

#endif