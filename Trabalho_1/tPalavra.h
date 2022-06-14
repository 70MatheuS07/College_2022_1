#ifndef PALAVRAS_H
#define PALAVRAS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tTempo.h"
#include "tJogador.h"

typedef struct tPalavra tPalavra;

tPalavra *CriaPalavra();

void SorteiaPalavra(tPalavra *palavra);

void ImprimePalavra(tPalavra *palavra);

void ColetaPalavraDoArquivo(tPalavra *palavra, char **matrizPalavras);

int InicioDoJogo(tPalavra *palavra);

void InicializaPalavraAtual(tPalavra *palavra);

void LehPalavraEscolhidaPeloJogador(tPalavra *palavra);

void LiberaPalavra(tPalavra *palavra);

void ClassificaPalavra(tPalavra *palavra);

int NaoTemEssaLetraNaPalavra(tPalavra *palavra, int i);

void ImprimePalavraClassificada(tPalavra *palavra);

void InicializaPalavraClassificada(tPalavra *palavra);

void PadronizaPalavra(tPalavra *palavra);

int AcertouPalavra(tPalavra *palavra);

char ColetaLetraPalavra(tPalavra *palavra, int i);

#endif