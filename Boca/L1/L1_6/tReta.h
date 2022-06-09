#ifndef TRETA_H
#define TRETA_H

#include <stdlib.h>
#include <stdio.h>
#include "tPonto.h"

typedef struct tReta tReta;

tReta *LehReta();

int ComparaDistancia(tPonto *ponto, tReta *reta);

void ImprimeResultado(int distancia);

#endif