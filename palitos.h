// Arquivo de cabeçalho para as funções e constantes

#ifndef PALITOS_H
#define PALITOS_H

// Declaração da quantidade de pauzinhos que podem ser retirados
const int MIN_RETIRADA = 1;
const int MAX_RETIRADA = 3;

// Funções
void limpar_tela();
void apresentar_palitos(int quantidade);
int jogada_robo(int quantidade);
int jogada_humano(int retirada);
void jogo_dos_palitos(int quantidade_total);

#endif 