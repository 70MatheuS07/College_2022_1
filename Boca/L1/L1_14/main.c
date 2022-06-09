#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Forma.h"

int main()
{
    int n=0, i=0;
    int qtdQuadrados = 0, qtdCirculos = 0, qtdRetangulos = 0;

    float areaCirculo = 0, areaQuadrado = 0, areaRetangulo = 0;
    float totalAreaCirculo = 0, totalAreaQuadrado = 0, totalAreaRetangulo = 0;

    tForma *forma;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        forma = LehForma();

        if (EhCirculo(forma) == 1)
        {
            areaCirculo = AreaCirculo(forma);

            totalAreaCirculo += areaCirculo;

            qtdCirculos++;
        }

        else if (EhQuadrado(forma) == 1)
        {
            areaQuadrado = AreaQuadrado(forma);

            totalAreaQuadrado += areaQuadrado;

            qtdQuadrados++;
        }

        else if (EhRetangulo(forma) == 1)
        {
            areaRetangulo = AreaRetangulo(forma);

            totalAreaRetangulo += areaRetangulo;

            qtdRetangulos++;
        }

        free(forma);
    }

    printf("Circulos: %d Area: %.2f\n", qtdCirculos, totalAreaCirculo);
    printf("Quadrados: %d Area: %.2f\n", qtdQuadrados, totalAreaQuadrado);
    printf("Retangulos: %d Area: %.2f", qtdRetangulos, totalAreaRetangulo);

    return 0;
}