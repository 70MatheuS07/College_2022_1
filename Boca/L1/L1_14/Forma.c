#include "Forma.h"

struct Forma
{
    float base;
    float altura;
    float raio;
};

tForma *LehForma()
{
    tForma *forma = NULL;

    forma = malloc(sizeof(tForma));

    float num1 = 0, num2 = 0, num3 = 0;

    scanf("%f %f %f\n", &num1, &num2, &num3);

    forma->base = num1;
    forma->altura = num2;
    forma->raio = num3;

    return forma;
}

int EhCirculo(tForma *forma)
{
    if (forma->altura < 0 && forma->base < 0 && forma->raio > 0)
    {
        return 1;
    }

    return 0;
}

int EhQuadrado(tForma *forma)
{
    if (forma->altura > 0 && forma->base > 0 && forma->raio < 0 && forma->base == forma->altura)
    {
        return 1;
    }

    return 0;
}

int EhRetangulo(tForma *forma)
{
    if (forma->altura > 0 && forma->base > 0 && forma->raio < 0 && forma->base != forma->altura)
    {
        return 1;
    }

    return 0;
}

void ImprimeFormas(int qtdCirculos, int qtdQuadrados, int qtdRetangulos)
{
    printf("Circulos: %d\n", qtdCirculos);
    printf("Quadrados: %d\n", qtdQuadrados);
    printf("Retangulos: %d", qtdRetangulos);
}

float AreaCirculo(tForma *forma)
{
    float result;

    result = 3.141592 * forma->raio * forma->raio;

    return result;
}

float AreaQuadrado(tForma *forma)
{
    float result;

    result = forma->base * forma->altura;

    return result;
}

float AreaRetangulo(tForma *forma)
{
    float result;

    result = forma->base * forma->altura;

    return result;
}