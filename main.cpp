#include <iostream>
#include <random>
#include <time.h>

#include "./include/Diretorio.hpp"
#include "./include/Balde.hpp"
using namespace std;

#define N 5


int main (int argc, char *argv[]) {
    int tamanhoBalde;
    int dglobalMax;
    
    cout << "Insira o tamanho M dos baldes: ";
    cin >> tamanhoBalde;
    cout << "Insira o número de bits a ser usado nas pseudo-chaves: ";
    cin >> dglobalMax;

    Diretorio* diretorio = new Diretorio(dglobalMax, tamanhoBalde);

    for (int j=0; j<N; j++) {
        string chave = "";
        for(int i=0; i<dglobalMax; i++) {
            srand(time(NULL));
            int aux = rand() % 2;
            chave += to_string(aux);
        }
        diretorio->insereChave(chave);
    }

    return 0;
}