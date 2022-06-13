#ifndef PONTO_H
#define PONTO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARQUIVO "pontos.bin"

typedef struct tPonto tPonto;

tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y);

void ImprimirPonto(tPonto *p);

void LiberaPonto(tPonto *p);

void SalvarPonto(tPonto *p, FILE *f);

tPonto *CarregarArquivo();

#endif