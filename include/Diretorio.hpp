#include <vector>
#include "Balde.hpp"

class Diretorio {
    private: 
        Balde **balde;
        int dglobal;
        int tamanho;
    public:
        Diretorio(int tamanho, int dglobal, int balde_size);
};