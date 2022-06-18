#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tJogador tJogador;

tJogador *CriaJogador();

void LehJogador_1(tJogador *jogador_1);

int EscolhaDeModo(tJogador *jogador);

void LiberaJogador(tJogador *jogador);

void ImprimeNomeJogadorCabecalho(tJogador *jogador);

void ImprimeAmbosJogadores(tJogador *jogador_1, tJogador *jogador_2);

void ImprimeEspacosJogador1(tJogador *jogador_1);

void ImprimeEspacosJogador2(tJogador *jogador_2);

void LehJogador_2(tJogador *jogador_1, tJogador *jogador_2);

int NomesIguais(tJogador *jogador_1, char nomeVerifica[10000]);

#endif