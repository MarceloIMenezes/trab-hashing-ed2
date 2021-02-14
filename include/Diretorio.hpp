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
        int nBaldes;

        Balde* baldeProcurado(string chave);
        void divideBaldes(Balde* baldeProcurado, int indiceBalde);
        void redistribuiChaves(Balde* bNovo, Balde* bAntigo, int indiceBalde);
        void duplicaTamanho();

        void addDGlobal();
        void addnBaldes();
        void setTamanho();
    public:
        Diretorio(int dglobalMax, int balde_size);

        int getDGlobal();
        int getTamanho();
        int getnBaldes();

        void insereChave(string chave);
        bool buscarChave(string chave);
        void imprimeDiretorio();
};

#endif //DIRETORIO_HPP