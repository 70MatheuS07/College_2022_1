#ifndef JOGO_H
#define JOGO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"
#include "tArquivo.h"
#include "tTempo.h"

typedef struct tJogo tJogo;

void JogaJogo(tJogador *jogador, tPalavra *palavra);

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogadas);

tJogo *InicializaJogadas();

void ImprimeTentativasRestantes(tJogo *jogadas);

void ReduzTentativasRestantes(tJogo *jogadas);

int TentativasZeradas(tJogo *jogadas);

void CabecalhoJogoFinal(tPalavra *palavra, tJogo *jogadas);

void InicializaTeclado(tJogo *jogo);

void AlteraTeclado(tJogo *jogo, tPalavra *palavra);

void ImprimeTecladoJogo(tJogo *jogo);

#endif