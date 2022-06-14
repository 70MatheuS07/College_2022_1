#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tJogador tJogador;

tJogador *CriaJogador();

void LehJogador(tJogador *jogador);

void LimpaBuffer();

void LiberaJogador(tJogador *jogador);

void ImprimeNomeJogadorCabecalho(tJogador *jogador);

#endif