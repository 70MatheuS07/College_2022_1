#ifndef PALAVRAS_H
#define PALAVRAS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct tPalavra tPalavra;

tPalavra *CriaPalavra();

void SorteiaPalavra(tPalavra *palavra);

void ImprimePalavra(tPalavra *palavra);

#endif