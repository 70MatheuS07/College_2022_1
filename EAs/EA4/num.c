#include "num.h"

struct Num
{
    char num[101];
};

Num *numCreate()
{
    Num *numeroRtn;
    char letra;
    char numeros[101];
    int i = 0;

    numeroRtn = malloc(sizeof(numeroRtn));

    scanf("%s", numeros);

    strcpy(numeroRtn->num, numeros);

    return numeroRtn;
}

void numDestroy(Num *numeros)
{
    free(numeros);
    numeros = NULL;
}

Num *numAdd(Num *numero1, Num *numero2)
{
    Num *numeroFinal;
    int qtd_numero1 = 0, qtd_numero2 = 0, i = 0;
    int num;

    numeroFinal = malloc(sizeof(numeroFinal));

    qtd_numero1 = strlen(numero1->num);
    qtd_numero2 = strlen(numero2->num);

    if (qtd_numero1 >= qtd_numero2)
    {
        for (i = 0; i < qtd_numero1; i++)
        {
            num = (numero1->num[i] - '0');

            if (i == 0)
            {
                numeroFinal->num[i] = '0';
            }

            if (num > 9)
            {
                num -= 10;
                numeroFinal->num[i] = (num + '0');
            }

            else
            {
                numeroFinal->num[i] = (num + '0');
            }
        }
    }

    return numeroFinal;
}

Num *numMultiply(Num *numero1, Num *numero2)
{
    Num *numeroFinal;
    int i = 0, qtd_numero2 = 0;

    numeroFinal = malloc(sizeof(numeroFinal));
    qtd_numero2 = strlen(numero2->num);

    qtd_numero1 = strlen(numero1->num);
    qtd_numero2 = strlen(numero2->num);

    for (i = 0; i < qtd_numero1; i++)
    {
        num = (numero1->num[i] - '0') + (numero1->num[i] - '0');

        if (num > 9)
        {
            num -= 10;
            numeroFinal->num[i] = (num + '0');
        }

        else
        {
            numeroFinal->num[i] = (num + '0');
        }
    }
}

return numeroFinal;
}

Num *numExp(Num *numero1, Num *numero2)
{
    Num *numeroFinal;
    long double num1 = 0, num2 = 0;
    long double numReturn = 0;
    int i = 0;

    num1 = atoi(numero1->num);
    num2 = atoi(numero2->num);

    numReturn = num1;

    for (i = 0; i < num2; i++)
    {
        numReturn *= num1;
    }

    numeroFinal = malloc(sizeof(numeroFinal));

    sprintf(numeroFinal->num, "%Lf", numReturn);

    return numeroFinal;
}

void numPrint(Num *resultado, FILE *arquivo)
{
    arquivo = fopen("resultado.txt", "w");

    fprintf(arquivo, "%s", resultado->num);

    fclose(arquivo);
}

Num *InvertePalavra(Num *numero)
{
    int num = strlen(numero->num);
    int aux, i, j;

    for (i = 0, j = num - 1; i < j; i++, j--)
    {
        aux = numero->num[i];
        numero->num[i] = numero->num[j];
        numero->num[j] = aux;
    }

    return numero;
}

Num *InicializaNumero()
{
    Num *numero;
    int i;

    for (i = 0; i < 2147483647; i++)
    {
        numero->num[i] = '0';
    }

    return numero;
}