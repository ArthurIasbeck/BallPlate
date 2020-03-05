#ifndef Pid_h
#define Pid_h

#include "Arduino.h"

//! Classe que representa o controlador PID. 
class Pid
{
    public:
        /**
         * @brief Constrói um objeto PID.
         * 
         * @param kp Constante proporcional.
         * @param ki Constante integral.
         * @param kd Constante derivativa.
         * @param T Tempo de amostragem em milissegundos.
         */
        Pid(float kp, float ki, float kd, float T);
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
        //! Retorna o valor do erro. 
        float getErr();
    private:
        float kp, ki, kd;
        float ref;
        float err, errPrev;
        float T; 
};

#endif