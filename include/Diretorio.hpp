#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <vector>
#include "./Balde.hpp"

class Diretorio {
    private: 
        Balde **balde;
        int dglobal;
        int tamanho;

        Balde* baldeProcurado(string chave);
        void divideBaldes(Balde* baldeProcurado, int indiceBalde);
        void redistribuiChaves(Balde* bNovo, Balde* bAntigo, int indiceBalde);
    public:
        Diretorio(int balde_size);

        int getDGlobal();

        void insereChave(string chave);
        bool buscarChave(string chave);
};

#endif //DIRETORIO_HPP