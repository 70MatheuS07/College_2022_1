#include "tPonto.h"

struct tPonto
{
    int x;
    int y;
};

tPonto *LehPonto()
{
    tPonto *ponto;

    ponto = malloc(sizeof(ponto));

    scanf("\n%d %d", &ponto->x, &ponto->y);

    return ponto;
}

float CalculaDistanciaEntrePontos(tPonto *ponto, tPonto *pontoBase)
{
    float x = 0, y = 0;

    x = ponto->x;
    y = ponto->y;

    if (x == pontoBase->x)
    {
        y -= pontoBase->y;

        if (y < 0)
        {
            y *= -1;
        }
      
        return y;
    }

    else if (y == pontoBase->y)
    {
        x -= pontoBase->x;

        if (x < 0)
        {
            x *= -1;
        }
      
        return x;
    }

    else
    {
        x -= pontoBase->x;

        if (x < 0)
        {
            x *= -1;
        }

        y -= pontoBase->y;

        if (y < 0)
        {
            y *= -1;
        }

        x = sqrt(pow(x, 2) + pow(y, 2));

        return x;
    }
}

void ImprimeDistancia(float hipotenusa)
{
    printf("%.2f\n", hipotenusa);
}

tPonto *TransferePonto(tPonto *ponto)
{
    return ponto;
}