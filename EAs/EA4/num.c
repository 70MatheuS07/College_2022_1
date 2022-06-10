#include "num.h"

#define TAMANHO_INICIAL 10

#define BASE 10

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

        numSetDigit(n,i,d-'0');
    }

    return n;
}

void numSetDigit(const Num *n, int i, int d)
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

        n->num[i] = d;
    }
}

void numDestroy(Num *n)
{
    free(n);
    n = NULL;
}

Num *numAdd(const Num *x, const Num *y)
{
}

void numPrint(const Num *n, FILE *f)
{
    f = fopen("resultado.txt", "w");

    fprintf(f, "%s", n->num);

    fclose(f);
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

void ImprimeNumeros(Num *numero1, Num *numero2)
{
    ImprimeString(numero1->num);
    ImprimeString(numero2->num);
}

void ImprimeString(char *s)
{
    printf("%s\n", s);
}