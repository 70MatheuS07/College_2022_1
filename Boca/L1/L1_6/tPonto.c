#include "tPonto.h"

struct tPonto
{
    int x;
    int y;
};

tPonto *LehPonto()
{
    int x = 0, y = 0;

    tPonto *ponto;

    ponto = malloc(sizeof(tPonto));

    scanf("%d %d", &x, &y);

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

tPonto *LehPontoReta()
{
    int x = 0, y = 0;

    tPonto *pontoRtn;

    pontoRtn = malloc(sizeof(pontoRtn));

    scanf(" %d %d", &x, &y);

    pontoRtn->x = x;
    pontoRtn->y = y;

    return pontoRtn;
}

tPonto *AchaSimetrico(tPonto *ponto)
{
    int x = 0, y = 0;

    x = ponto->x;
    y = ponto->y;

    x *= -1;
    y *= -1;

    ponto->x = x;
    ponto->y = y;

    return ponto;
}

int IdentificaQuadrante(tPonto *ponto)
{
    if (ponto->x == 0 || ponto->y == 0)
    {
        return 0;
    }

    else if (ponto->x > 0)
    {
        if (ponto->y > 0)
        {
            return 1;
        }

        else if (ponto->y < 0)
        {
            return 4;
        }
    }
    else
    {
        if (ponto->y > 0)
        {
            return 2;
        }

        else if (ponto->y < 0)
        {
            return 3;
        }
    }
}

tPonto *InicializaPonto(int x, int y)
{
    tPonto *pontoRtn;

    pontoRtn->x = x;
    pontoRtn->y = y;

    return pontoRtn;
}

int PegaAbscissa(tPonto *ponto)
{
    int x = 0;

    x = ponto->x;

    return x;
}

int PegaOrdenada(tPonto *ponto)
{
    int y = 0;

    y = ponto->y;

    return y;
}

float DistanciaEntrePontos(tPonto ponto1, tPonto ponto2)
{
    float distancia = 0, deltaX = 0, deltaY = 0;

    deltaX = ponto2.x - ponto1.x;
    deltaY = ponto2.y - ponto1.y;
    distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
    distancia = sqrt(distancia);

    return distancia;
}

float DistanciaEntrePontosPi(tPonto *ponto, tReta *reta)
{
    float distancia = 0, deltaX = 0, deltaY = 0;

    deltaX = ponto->x - reta->pi->x;
    deltaY = ponto->y - reta->pi->y;
    distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
    distancia = sqrt(distancia);

    return distancia;
}

float DistanciaEntrePontosPf(tPonto *ponto, tReta *reta)
{
    float distancia = 0, deltaX = 0, deltaY = 0;

    deltaX = ponto->x - reta->pf->x;
    deltaY = ponto->y - reta->pf->y;
    distancia = (pow(deltaX, 2)) + (pow(deltaY, 2));
    distancia = sqrt(distancia);

    return distancia;
}