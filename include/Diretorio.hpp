#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <vector>
#include "./Balde.hpp"

class Diretorio {
    private: 
        Balde **balde;
        int dglobal;
        int dglobalMax;
        int tamanho;

        Balde* baldeProcurado(string chave);
        void divideBaldes(Balde* baldeProcurado, int indiceBalde);
        void redistribuiChaves(Balde* bNovo, Balde* bAntigo, int indiceBalde);
        void duplicaTamanho();

        void addDGlobal();
        void setTamanho();
    public:
        Diretorio(int dglobalMax, int balde_size);

        int getDGlobal();
        int getTamanho();

        void insereChave(string chave);
        bool buscarChave(string chave);
};

#endif //DIRETORIO_HPP