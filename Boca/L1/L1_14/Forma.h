#ifndef FORMA_H
#define FORMA_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Forma tForma;

tForma *LehForma();

int EhCirculo(tForma *forma);

int EhQuadrado(tForma *forma);

int EhRetangulo(tForma *forma);

void ImprimeFormas(int qtdCirculos, int qtdQuadrados, int qtdRetangulos);

float AreaCirculo(tForma *forma);

float AreaQuadrado(tForma *forma);

float AreaRetangulo(tForma *forma);

#endif