#define DESTE_TIPO_ double
#define FORMATO "%.2f"

#include "ponto.h"

struct tPonto
{
    DESTE_TIPO_ x;
    DESTE_TIPO_ y;
};

struct tPonto_array
{
    tPonto *pontos;
    size_t qtd;
    size_t tamArray;
};

tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y)
{
    tPonto *p = malloc(sizeof(tPonto));

    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    p->x = x;
    p->y = y;
}

void LiberaPonto(tPonto *p)
{
    free(p);
    p = NULL;
}

void ImprimirPonto(tPonto *p)
{
    char formato[15] = "{";

    strcat(formato, FORMATO);
    strcat(formato, ", ");
    strcat(formato, FORMATO);
    strcat(formato, "}");

    printf(formato, p->x, p->y);
    printf("\n");
}

void SalvarPonto(tPonto *p, FILE *f)
{
    f = fopen(ARQUIVO, "ab");

    if (f == NULL)
    {
        printf("Erro abertura do arquivo!\n");
        exit(EXIT_FAILURE);
    }

    fwrite(p, sizeof(tPonto *), 1, f);

    fclose(f);
}

tPonto *CarregarArquivo(FILE *fp)
{
    fp = fopen(ARQUIVO, "rb");

    if (fp == NULL)
    {
        printf("Erro abertura do arquivo!\n");
        exit(EXIT_FAILURE);
    }

    tPonto *p = malloc(sizeof(tPonto *));

    fread(p, sizeof(tPonto *), 1, fp);

    fclose(fp);

    return p;
}