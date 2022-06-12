#ifndef PALAVRAS_H
#define PALAVRAS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct tPalavra tPalavra;

tPalavra *CriaPalavra();

char *CriaPalavraChar();

void LehPalavra(tPalavra *palavra);

int PegaTempo();

void SorteioPalavra(tPalavra *palavra);

void ImprimePalavra(tPalavra *palavra);

tPalavra **CriaTodasPalavras();

#endif