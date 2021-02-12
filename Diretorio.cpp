#include <math.h>
#include <stdio.h>
#include <iostream>
#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"

Diretorio::Diretorio(int dglobalMax, int balde_size) {
    if (dglobalMax > 0)
        this->dglobalMax = dglobalMax;
    else
        this->dglobalMax = 1;
    this->dglobal = 1;
    this->tamanho = pow(2, this->dglobal);

    this->balde = new Balde*[this->tamanho];

    Balde* first = new Balde(balde_size, 0);
    Balde* second = new Balde(balde_size, 0);
    this->balde[0] = first;
    this->balde[1] = second;
}

int Diretorio::getDGlobal() {
    return this->dglobal;
}
void Diretorio::addDGlobal() {
    this->dglobal++;
    if (this->dglobal > this->dglobalMax) {
        exit(-1);
    }
}
int Diretorio::getTamanho() {
    return this->tamanho;
}
void Diretorio::setTamanho() {
    this->tamanho = pow(2, this->getDGlobal());
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

void Diretorio::duplicaTamanho() {
    int tamanho = this->getTamanho();
    this->addDGlobal();
    this->setTamanho();

    Balde** temp = new Balde*[this->getTamanho()];

    for (int i=0; i < tamanho; i++) {
        temp[i*2] = this->balde[i];
        temp[i*2 + 1] = this->balde[i];
    }

    delete[] this->balde;

    this->balde = temp;
}

void Diretorio::insereChave(string chave) {
    Balde* baldeProcurado = this->baldeProcurado(chave);
    if (baldeProcurado->temEspaco()) {
        baldeProcurado->insereChave(chave);
    } else {
        if (baldeProcurado->getDLocal() == this->getDGlobal()) {
            //duplica tam diretorio
            this->duplicaTamanho();
        }
        //divide balde e incremenda dlocal
        int indiceBalde = std::stoi(chave.substr(0, this->getDGlobal()), nullptr, 2);
        this->divideBaldes(baldeProcurado, indiceBalde);
        this->insereChave(chave);
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

void Diretorio::imprimeDiretorio() {
    int tamanhoBalde = this->balde[0]->getTamanhoM();
    for(int i=0; i < this->getTamanho(); i++) {
        std::cout << "Balde " << i + 1 << endl;
        for(int j=0; j < tamanhoBalde; j++) {
            std::cout << this->balde[i]->getPseudoChave(j) << endl;
        }
    }
}

