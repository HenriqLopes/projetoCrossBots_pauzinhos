/*
    Comandos do terminal para rodar o código:
    mingw32-make
    ./programa
*/

#include <iostream>
#include <cstdlib>
#include "palitos.h"

using namespace std;

int main () {
    int quantidade_total = 0;
    
    cout << "Digite a quantidade inicial de palitos: ";
    cin >> quantidade_total;
    
    limpar_tela();

    // Inicia o jogo e declara o ganhador
    jogo_dos_palitos(quantidade_total);

    return 0;
}