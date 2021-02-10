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
    int indiceBalde = std::stoi(chave.substr(0, this->getDGlobal()), nullptr, 2);
    return this->balde[indiceBalde];
}

void Diretorio::divideBaldes(Balde* baldeProcurado, int indiceBalde) {
    Balde* novo = new Balde(baldeProcurado->getTamanhoM(), baldeProcurado->getDLocal());
    novo->addDLocal();
    baldeProcurado->addDLocal();
    this->balde[indiceBalde] = novo;
    this->redistribuiChaves(novo, baldeProcurado, indiceBalde);
}

void Diretorio::redistribuiChaves(Balde* bNovo, Balde* bAntigo, int indiceNovo) {
    int j = 0;
    for (int i=0; i < bAntigo->getTamanhoM(); i++) {
        int indiceVelho = std::stoi(bAntigo->getPseudoChave(i).substr(0, this->getDGlobal()), nullptr, 2);
        if (indiceNovo == indiceVelho) {
            bNovo->setPseudoChave(j, bAntigo->getPseudoChave(i));
            bAntigo->removeChave(bAntigo->getPseudoChave(i));
            j++;
        }
    }
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
        int indiceBalde = std::stoi(chave.substr(0, this->getDGlobal()), nullptr, 2);
        this->divideBaldes(baldeProcurado, indiceBalde);
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

