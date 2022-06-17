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

void JogaJogoSolo(tJogador *jogador, tPalavra *palavra, tArquivo *arquivo);

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogo, tArquivo *arquivo);

int PalavraExiste(tPalavra *palavra, tArquivo *arquivo);

tJogo *InicializaJogadas();

void ImprimeTentativasRestantes(tJogo *jogadas);

void ReduzTentativasRestantes(tJogo *jogadas);

int TentativasZeradas(tJogo *jogadas);

void CabecalhoJogoVitoria(tPalavra *palavra, tJogo *jogo);

void CabecalhoJogoDerrota(tPalavra *palavra, tJogo *jogo);

void InicializaTeclado(tJogo *jogo);

void AlteraTeclado(tJogo *jogo, tPalavra *palavra);

void ImprimeTecladoJogo(tJogo *jogo);

#endif