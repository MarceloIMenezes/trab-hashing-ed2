#include <math.h>
#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"

Diretorio::Diretorio(int balde_size) {
    this->dglobal = 1;
    this->tamanho = pow(2, this->dglobal);

    this->balde = new Balde*[this->tamanho];

    Balde* first = new Balde(balde_size, 1);
    for (int i = 0; i < this->tamanho; i++)
        balde[i] = first;
}

int Diretorio::getDGlobal() {
    return this->dglobal;
}

Balde* Diretorio::baldeProcurado(string chave) {
    int indiceBalde = std::stoi(chave.substr(0, this->dglobal), nullptr, 2);
    return this->balde[indiceBalde];
}

void Diretorio::insereChave(string chave) {
    Balde* baldeProcurado = this->baldeProcurado(chave);
    if (baldeProcurado->temEspaco()) {
        baldeProcurado->insereChave(chave);
    } else {
        if (baldeProcurado->getDLocal() == this->getDGlobal()) {
            //duplica tam diretorio
        }
        //divide balde e incremenda dlocal
    }
}

bool Diretorio::buscarChave(string chave) {
    Balde* baldeProcurado = this->baldeProcurado(chave);
    for (int i = 0; i < baldeProcurado->getTamanhoM(); i++) {
        if (baldeProcurado->getPseudoChave(i) == chave)
            return true;
    }
    return false;
}

