#include "tArquivo.h"

struct tArquivo
{
    char **palavras;
};

#define QTD_PALAVRAS 18289

tArquivo *CriaArmazenaPalavrasArquivo()
{
    tArquivo *arquivo;
    int i = 0, j = 0;
    char caracter;

    arquivo = malloc(sizeof(tArquivo));

    arquivo->palavras = malloc(sizeof(char *) * QTD_PALAVRAS);

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        arquivo->palavras[i] = malloc(sizeof(char) * 6);
    }

    FILE *file;

    file = fopen("palavras.txt", "r");

    i = 0;

    do
    {
        fscanf(file, "%c", &caracter);

        if (caracter == '\n')
        {
            arquivo->palavras[i][j] = '\0';
            i++;
            j = 0;
        }

        else
        {
            arquivo->palavras[i][j] = caracter;
            j++;
        }

    } while (!feof(file));

    fclose(file);

    // Corrigi a ultima palavra que está duplicando o ultimo char.
    arquivo->palavras[QTD_PALAVRAS - 1][5] = '\0';

    return arquivo;
}

void ColetaPalavraDoArquivo(tPalavra *palavra, tArquivo *arquivo)
{
    int i = 0, j = 0;
    char string[6];

    i = ColetaPalavraEscolhida(palavra);

    for (j = 0; j < 6; j++)
    {
        string[j] = arquivo->palavras[i][j];
    }

    for (i = 0; i < 6; i++)
    {
        CopiaStringParaPalavra(palavra, string);
    }
}

void LiberaPalavrasArquivo(tArquivo *arquivo)
{
    int i = 0;

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        free(arquivo->palavras[i]);
        arquivo->palavras[i] = NULL;
    }

    free(arquivo);
    arquivo = NULL;
}

char CharPalavraArquivo(tArquivo *arquivo, int i, int j)
{
    char caracter;

    caracter = arquivo->palavras[i][j];

    return caracter;
}