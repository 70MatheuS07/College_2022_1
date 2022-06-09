#ifndef TPONTO_H
#define TPONTO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tReta.h"

typedef struct tPonto tPonto;

tPonto *LehPonto();

tPonto *LehPontoReta();

tPonto *AchaSimetrico(tPonto *ponto);

int IdentificaQuadrante(tPonto *ponto);

tPonto *InicializaPonto(int x, int y);

int PegaAbscissa(tPonto *ponto);

int PegaOrdenada(tPonto *ponto);

float DistanciaEntrePontos(tPonto ponto1, tPonto ponto2);

float DistanciaEntrePontosPi(tPonto *ponto, tReta *reta);

float DistanciaEntrePontosPf(tPonto *ponto, tReta *reta);

#endif