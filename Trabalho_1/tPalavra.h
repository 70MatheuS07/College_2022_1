#ifndef PALAVRAS_H
#define PALAVRAS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tTempo.h"

typedef struct tPalavra tPalavra;

tPalavra *CriaPalavra();

void SorteiaPalavra(tPalavra *palavra);

void ImprimePalavra(tPalavra *palavra);

void ColetaPalavraDoArquivo(tPalavra *palavra, char **matrizPalavras);

int InicioDoJogo(tPalavra *palavra);

void InicializaPalavraAtual(tPalavra *palavra);

#endif