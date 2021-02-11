#include <iostream>
#include <bitset>
#include <random>
#include <time.h>

#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"
using namespace std;

#define N 10


int main () {
    int tamanhoBalde;
    int dglobalMax;
    
    /*
    cout << "Insira o tamanho M dos baldes: ";
    cin >> tamanhoBalde;
    cout << "Insira o número de bits a ser usado nas pseudo-chaves: ";
    cin >> dglobalMax;
    cout << "DIRETORIO EXISTE";
    */
   tamanhoBalde = 3;
   dglobalMax = 8;
    Diretorio* diretorio = new Diretorio(dglobalMax, tamanhoBalde);
    
    srand(time(NULL));
    for (int j=0; j<N; j++) {
        string chave;
        for(int i=0; i<dglobalMax; i++) {
            int aux = rand() % 1000;
            chave = std::bitset<8>(aux).to_string();
        }
        diretorio->insereChave(chave);
    }
    diretorio->imprimeDiretorio();
    
    return 0;
}