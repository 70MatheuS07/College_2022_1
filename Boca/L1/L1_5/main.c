#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tPonto.h"

int main()
{
    int i = 0, n = 0;
    float hipotenusa = 0, x = 0, y = 0;
    tPonto *pontoBase;
    tPonto *ponto;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pontoBase = LehPonto();
            printf("-\n");
        }
        else
        {
            ponto = LehPonto();

            hipotenusa = CalculaDistanciaEntrePontos(ponto, pontoBase);

            free(pontoBase);
            
            ImprimeDistancia(hipotenusa);

            pontoBase = ponto;
        }
    }

    free(pontoBase);

    return 0;
}