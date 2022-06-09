#ifndef TPONTO_H
#define TPONTO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct tPonto tPonto;

tPonto *LehPonto();

void ImprimePonto(tPonto *ponto);

int QuadranteDoPonto(tPonto *ponto);

void ImprimeQuadrante(int quadrante);

tPonto *AlteraAbscissaX(tPonto *ponto);

tPonto *AlteraOrdeenadaY(tPonto *ponto);

#endif