#include "tPonto.h"

struct tPonto
{
    int x;
    int y;
};

tPonto *LehPonto()
{
    tPonto *pontoInterno;
    int x, y;

    pontoInterno = malloc(sizeof(pontoInterno));

    scanf("\n%d %d", &x, &y);

    pontoInterno->x = x;
    pontoInterno->y = y;

    return pontoInterno;
}

void ImprimePonto(tPonto *ponto)
{
    int x, y;

    x = ponto->x;
    y = ponto->y;

    printf("(%d,%d)", x, y);
}

int QuadranteDoPonto(tPonto *ponto)
{
    if (ponto->x > 0 && ponto->y > 0)
    {
        return 1;
    }

    else if (ponto->x < 0 && ponto->y > 0)
    {
        return 2;
    }

    else if (ponto->x < 0 && ponto->y < 0)
    {
        return 3;
    }

    else if (ponto->x > 0 && ponto->y < 0)
    {
        return 4;
    }

    return 0;
}

void ImprimeQuadrante(int quadrante)
{
    printf("%d", quadrante);
}

tPonto *AlteraAbscissaX(tPonto *ponto)
{
    int x;

    if (ponto->x > 0 || ponto->x < 0)
    {
        x = ponto->x;

        x *= -1;

        ponto->x = x;
    }

    return ponto;
}

tPonto *AlteraOrdeenadaY(tPonto *ponto)
{
    int y;

    if (ponto->y > 0 || ponto->y < 0)
    {
        y = ponto->y;

        y *= -1;

        ponto->y = y;
    }

    return ponto;
}