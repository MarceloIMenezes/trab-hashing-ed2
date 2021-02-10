#include <string>
#include "include/Balde.hpp"
using namespace std;

Balde::Balde(int m, int dlocal) {
    this.tamanhoM = m;
    this.dlocal = dlocal;
    this.pseudochaves = new string[m];
}
