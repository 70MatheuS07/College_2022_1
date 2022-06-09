#ifndef TPONTO_H
#define TPONTO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct tPonto tPonto;

tPonto *LehPonto();

float CalculaDistanciaEntrePontos(tPonto *ponto, tPonto *pontoBase);

void ImprimeDistancia(float hipotenusa);

tPonto *TransferePonto(tPonto *ponto);

#endif