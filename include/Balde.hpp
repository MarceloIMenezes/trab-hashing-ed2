#ifndef BALDE_HPP
#define BALDE_HPP

#include <string>
using namespace std;

class Balde {
    private: 
        string* pseudochaves;
        int tamanhoM;
        int dlocal;

        void setPseudoChave(int i, string chave);
    public: 
        Balde(int m, int dlocal);

        int getTamanhoM();
        string getPseudoChave(int i);
        int getDLocal();
        void addDLocal();

        bool temEspaco();
        void insereChave(string chave);
};

#endif //BALDE_HPP