#include <string>
#include "include/Balde.hpp"
using namespace std;

Balde::Balde(int m, int dlocal) {
    this->tamanhoM = m;
    this->dlocal = dlocal;

    this->pseudochaves = new string[m];
    for (int i = 0; i < m; i++) 
        this->pseudochaves[i] = "-1";
}

int Balde::getTamanhoM() { return this->tamanhoM; }

string Balde::getPseudoChave(int i) { return this->pseudochaves[i]; }
void Balde::setPseudoChave(int i, string chave) { this->pseudochaves[i] = chave; }

int Balde::getDLocal() { return this->dlocal; }
void Balde::addDLocal() { this->dlocal++; }

void Balde::removeChave(string chave) {
    for (int i = 0; i < this->getTamanhoM(); i++) {
        if (this->getPseudoChave(i) == chave) {
            this->setPseudoChave(i, "-1");
            return;
        }
    }
}

bool Balde::temEspaco() {
    for (int i = 0; i < this->getTamanhoM(); i++) {
        if (this->getPseudoChave(i) == "-1")
            return true;
    }
    return false;
}

void Balde::insereChave(string chave) {
    for (int i = 0; i < this->getTamanhoM(); i++) {
        if (this->getPseudoChave(i) == "-1") {
            this->setPseudoChave(i, chave);
            return;
        }
    }
}
