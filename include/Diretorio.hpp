#include <vector>
#include "./Balde.hpp"

class Diretorio {
    private: 
        Balde **balde;
        int dglobal;
        int tamanho;
    public:
        Diretorio();
        string buscarChave(string chave);
};