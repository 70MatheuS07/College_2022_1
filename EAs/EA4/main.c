#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "num.h"

int main()
{
    char operacao;
    Num *numero1;
    Num *numero2;
    Num *resultado;
    FILE *arquivo;

    scanf("%c\n", &operacao);

    numero1 = numCreate();
    scanf(" ");
    numero2 = numCreate();

    numero1 = InvertePalavra(numero1);
    numero2 = InvertePalavra(numero2);

    if (operacao == 'a')
    {
        resultado = numAdd(numero1, numero2);
    }

    else if (operacao == 'm')
    {
        resultado = numMultiply(numero1, numero2);
    }

    else if (operacao == 'e')
    {
        resultado = numExp(numero1, numero2);
    }

    resultado = InvertePalavra(resultado);

    numPrint(resultado, arquivo);

    return 0;
}