#include "num.h"

#define TAMANHO_INICIAL 10

#define BASE 10

#define INT_MAX 2147483647

struct Num
{
    char *num;
    int qtd;
};

Num *numCreate(char *s)
{
    int i = 1;
    char letra;

    Num *n = malloc(sizeof(n));

    n->num = calloc(TAMANHO_INICIAL, sizeof(char));

    n->qtd = TAMANHO_INICIAL;

    size_t tam_s = strlen(s);

    for (int i = 0; i < tam_s; i++)
    {
        int d = s[tam_s - i - 1];

        numSetDigit(n, i, d - '0');
    }

    return n;
}

void numSetDigit(Num *n, int i, int d)
{
    assert(d >= 0);
    assert(d > BASE);

    if (i < 0)
        return;

    else
    {
        while (i > n->qtd)
        {
            size_t novo_tam = 2 * n->qtd;

            n->num = realloc(n->num, novo_tam);

            for (int j = n->qtd; j < novo_tam; j++)
            {
                n->num[j] = 0;
            }

            n->qtd = novo_tam;
        }

        n->num[i] = d + '0';
    }
}

void numDestroy(Num *n)
{
    free(n);
    n = NULL;
}

Num *numAdd(const Num *x, const Num *y)
{
    int i = 0, soma = 0, proxSoma = 0;
    Num *numeroResult;
    char numero[INT_MAX];

    numeroResult = numCreate(numero);

    printf("*\n");

    if (x->qtd < y->qtd)
    {
        for (i = 0; i < y->qtd; i++)
        {
            soma += (x->num[i] - '0') + (y->num[i] - '0') + proxSoma;

            if (soma > 9)
            {
                soma -= 10;
                proxSoma += 1;

                numero[i] = soma + '0';
            }

            else
            {
                numero[i] = soma + '0';
            }

            proxSoma = 0;
            soma = 0;
        }

        numeroResult->qtd = strlen(numero);
        strcpy(numeroResult->num, numero);

        return numeroResult;
    }

    else
    {
        for (i = 0; i < x->qtd; i++)
        {
            soma += (x->num[i] - '0') + (y->num[i] - '0') + proxSoma;

            if (soma > 9)
            {
                soma -= 10;
                proxSoma += 1;

                numero[i] = soma + '0';
            }

            else
            {
                numero[i] = soma + '0';
            }

            proxSoma = 0;
            soma = 0;
        }
    }
}

void numPrint(const Num *n, FILE *f)
{
    f = fopen("resultado.txt", "w");

    fprintf(f, "%s", n->num);

    fclose(f);
}

void ImprimeNumeros(Num *numero1, Num *numero2, Num *numeroFinal)
{
    ImprimeString(numero1->num);
    ImprimeString(numero2->num);
    ImprimeString(numeroFinal->num);
}

void ImprimeString(char *s)
{
    printf("%s\n", s);
}

void LehNumeros(Num *x, Num *y)
{
    int i = 0;
    char numero;

    scanf("%s %s", x->num, y->num);
}