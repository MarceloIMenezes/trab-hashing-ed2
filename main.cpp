#include <iostream>
#include <bitset>
#include <random>
#include <time.h>

#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"
using namespace std;

#define N 500

void geraChavesAleatorias(int nBits, string* chave) {
    srand(time(NULL));
    for (int j=0; j<N; j++) {
        int aux = rand() % 1000;
        chave[j] = std::bitset<32>(aux).to_string();
        chave[j] = chave[j].substr(chave[j].length() - nBits, nBits);
    }
}

void geraChavesPadronizadas(int nBits, string* chave) {
    srand(time(NULL));
    int aux = rand() % 1000;
    string chaveI = std::bitset<32>(aux).to_string();
    chaveI = chaveI.substr(chaveI.length() - nBits/2, nBits/2);
    string *chaveF = new string[N];
    geraChavesAleatorias(nBits/2, chaveF);
    for(int i=0; i<N; i++) {
        chave[i] = chaveI + chaveF[i];
    }
}

int main () {
    int tamanhoBalde;
    int nBits;
    
    cout << "Insira o tamanho M dos baldes: ";
    cin >> tamanhoBalde;
    cout << "Insira o número de bits a ser usado nas pseudo-chaves: ";
    cin >> nBits;

    Diretorio* diretorio = new Diretorio(nBits, tamanhoBalde);
    
    string info;
    cout << "Gerar chaves aleatórias: digite 1" << endl;
    cout << "Gerar chaves padronizadas: digite 2" << endl;
    cin >> info;
    
    string *chaves = new string[N];
    
    if (info == "1")
        geraChavesAleatorias(nBits, chaves);
    else
        geraChavesPadronizadas(nBits, chaves);
    
    int nInseridos = N;
    for (int i = 0; i < N; i++) {
        if (!(diretorio->buscarChave(chaves[i])))
            diretorio->insereChave(chaves[i]);
        else
            nInseridos--;
    }
    //diretorio->imprimeDiretorio();
    cout << "Fator de carga da tabela: " << (float)nInseridos/(diretorio->getTamanho()*tamanhoBalde) << endl;
    cout << "Memoria ocupada: " << (diretorio->getTamanho()*tamanhoBalde) << endl;

    return 0;
}