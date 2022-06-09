#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tPonto.h"
#include "tReta.h"

int main()
{
    int num = 0, i = 1;
    int distancia = -1;

    tPonto *ponto = NULL;
    tReta *reta = NULL;

    scanf("%d\n", &num);

    for (i = 0; i < num; i++)
    {
        ponto = LehPonto();

        reta = LehReta();

        distancia = ComparaDistancia(ponto, reta);

        ImprimeResultado(distancia);
    }

    return 0;
}