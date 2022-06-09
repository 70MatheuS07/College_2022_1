#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tPonto.h"

int main()
{
    int i = 0, num = 0;
    int quadrante = -1;

    tPonto *ponto;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        ponto = LehPonto();

        ImprimePonto(ponto);

        quadrante = QuadranteDoPonto(ponto);

        printf(" ");

        ImprimeQuadrante(quadrante);

        printf(" ");

        ponto = AlteraAbscissaX(ponto);

        ponto = AlteraOrdeenadaY(ponto);

        ImprimePonto(ponto);

        quadrante = QuadranteDoPonto(ponto);

        printf(" ");

        ImprimeQuadrante(quadrante);

        printf("\n");

        free(ponto);
    }

    return 0;
}