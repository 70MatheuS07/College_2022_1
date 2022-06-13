#ifndef TJOGADOR_H
#define TJOGADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tJogador tJogador;

tJogador *CriaJogador();

void LehJogador(tJogador *jogador);

void LimpaBuffer();


void ImprimeNomeJogadorCabecalho(tJogador *jogador);

#endif