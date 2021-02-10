#include <math.h>
#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"

Diretorio::Diretorio() {
    this->dglobal = 1;
    this->tamanho = pow(2, this->dglobal);
    this->balde = new Balde*[this->tamanho];
    for (int i = 0; i < tamanho; i++)
        balde[i] = NULL;
}

string Diretorio::buscarChave(string chave) {
    int indiceBalde = std::stoi(chave.substr(0, this->dglobal), nullptr, 2);
    Balde *baldeProcurado = this->balde[indiceBalde];
    for (int i = 0; i < baldeProcurado->getTamanhoM(); i++) {
        if (baldeProcurado->getPseudoChave(i) == chave)
            return baldeProcurado->getPseudoChave(i);
    }
    return "Chave não encontrada";
}