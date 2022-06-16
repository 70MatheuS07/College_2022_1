#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tPalavra.h"

typedef struct tArquivo tArquivo;

tArquivo *CriaArmazenaPalavrasArquivo();

void ColetaPalavraDoArquivo(tPalavra *palavra, tArquivo *arquivo);

void LiberaPalavrasArquivo(tArquivo *arquivo);

char CharPalavraArquivo(tArquivo *arquivo, int i, int j);

#endif