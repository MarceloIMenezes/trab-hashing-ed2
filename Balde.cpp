#include <string>
#include "include/Balde.hpp"
using namespace std;

Balde::Balde(int m, int dlocal) {
    this->tamanhoM = m;
    this->dlocal = dlocal;
    this->pseudochaves = new string[m];
}

int Balde::getTamanhoM() {
    return this->tamanhoM;
}
string Balde::getPseudoChave(int i) {
    return this->pseudochaves[i];
}
