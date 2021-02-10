#ifndef BALDE_HPP
#define BALDE_HPP

#include <string>
using namespace std;

class Balde {
    private: 
        string* pseudochaves;
        int tamanhoM;
        int dlocal;
    public: 
        Balde(int m, int dlocal);
        int getTamanhoM();
        string getPseudoChave(int i);
};

#endif //BALDE_HPP