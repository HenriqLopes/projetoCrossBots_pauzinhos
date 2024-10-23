// Arquivo que contem as funções implementadas

#include <iostream>
#include <cstdlib> // Queremos a função clear dessa biblioteca
#include "palitos.h"

using namespace std;

void limpar_tela () {
    //Verifica qual é o S.O. para limpar o terminal com o comando compatível
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux && mac
    #endif
}

// Apresenta na tela a quantidade de palitos restantes
void apresentar_palitos(int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        cout << "| ";
    }
    cout << endl;
    cout << "Numero de palitos restantes: " << quantidade << endl;
}

//Estratégia: O robô tenta retirar um valor que faça o jogador humano ficar com uma quantidade de palitos múltiplo de quatro.
int jogada_robo (int quantidade) {
    int jogada = (quantidade % 4);

    //Caso não tenha a possibilidade, retira 1 palito.
    if (jogada == 0) {
        return 1;
    }

    return jogada;
}

// Input do valor retirado pelo jogador
int jogada_humano (int retirada) {
    cout << "Digite quantos palitos pegar (1, 2 ou 3): ";
    cin >> retirada;
    cout << endl;

    // Verifica se o valor digitado pelo usuário está entre os valores permitidos
    while(retirada < MIN_RETIRADA || retirada > MAX_RETIRADA) {
        cout << "Valor invalido! Valem somente as retiradas de valores entre " << MIN_RETIRADA << " e " << MAX_RETIRADA << " palitos" << endl;
        cout << "> ";
        cin >> retirada;
    }

    return retirada;
}

// Função onde ocorre a disputa entre o humano e o robô
void jogo_dos_palitos (int quantidade_total) {
    int retirada = 0;

    // Looping enquanto ainda houver palitos
    do {
        apresentar_palitos(quantidade_total);
        
        retirada = jogada_humano(quantidade_total);
        quantidade_total -= retirada; // Subtrai os palitos retirados pelo jogador humano
        
        // Caso o humano vença, o looping é interrompido e retorna para a função main
        if(quantidade_total == 0) {
            cout << "Fim do jogo -> Voce venceu!" << endl;
            return;
        }

        apresentar_palitos(quantidade_total);

        // Jogada do bot e retirada dos palitos por ele feita
        retirada = jogada_robo(quantidade_total);
        quantidade_total -= retirada;

        // Apresenta jogada do robô
        cout << "O computador pegou " << retirada << " palitos" << endl;
        cout << endl;
    } while(quantidade_total > 0); 

    cout << "Fim do jogo -> O computador venceu" << endl;
}