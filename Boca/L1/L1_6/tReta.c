#include "tReta.h"

struct tReta
{
    tPonto *pi;
    tPonto *pf;
};

tReta *LehReta()
{
    int x = 0, y = 0;
    tReta *reta;

    reta->pi = malloc(sizeof(reta->pi));
    reta->pf = malloc(sizeof(reta->pi));

    reta = malloc(sizeof(tReta));

    reta->pi = LehPontoReta();
    reta->pf = LehPontoReta();

    return reta;
}

void ImprimeResultado(int distancia)
{
    if (distancia == 0)
    {
        printf("INICIO\n");
    }

    else if (distancia == 1)
    {
        printf("EQUIDISTANTE\n");
    }

    else if (distancia == 2)
    {
        printf("FIM\n");
    }
}

int ComparaDistancia(tPonto *ponto, tReta *reta)
{
    float distanciaPi = 0, distanciaPf = 0;
    float deltaXi = 0, deltaXf = 0; 
    float deltaYi = 0, deltaYf = 0;

    distanciaPi = DistanciaEntrePontosPi(ponto, reta);

    ponto2.x = reta->pf.x;
    ponto2.y = reta->pf.y;

    distanciaPf = DistanciaEntrePontosPf(ponto, reta);

    if (distanciaPi > distanciaPf)
    {
        return 2;
    }

    else if (distanciaPi == distanciaPf)
    {
        return 1;
    }

    else if (distanciaPi < distanciaPf)
    {
        return 0;
    }
}