#ifndef DIRETORIO_HPP
#define DIRETORIO_HPP

#include <vector>
#include "./Balde.hpp"

class Diretorio {
    private: 
        Balde **balde;
        int dglobal;
        int tamanho;
    public:
        Diretorio(int balde_size);
        string buscarChave(string chave);
};

#endif //DIRETORIO_HPP