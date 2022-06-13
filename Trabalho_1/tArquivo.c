#include "tArquivo.h"

#define QTD_PALAVRAS 18289

char **ArmazenaPalavrasArquivo()
{
    char **palavras;
    int i = 0, j = 0;
    char caracter;

    palavras = malloc(QTD_PALAVRAS * sizeof(char *));

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        palavras[i] = malloc(6 * sizeof(char));
    }

    FILE *arquivo;

    arquivo = fopen("palavras.txt", "r");

    i = 0;

    do
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == '\n')
        {
            palavras[i][j] = '\0';
            i++;
            j = 0;
        }

        else
        {
            palavras[i][j] = caracter;
            j++;
        }

    } while (!feof(arquivo));

    fclose(arquivo);

    // Corrigi a ultima palavra que está duplicando o ultimo char.
    palavras[QTD_PALAVRAS - 1][5] = '\0';

    return palavras;
}

void LiberaPalavrasArquivo(char **palavras)
{
    int i = 0;

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        free(palavras[i]);
    }

    free(palavras);
    palavras = NULL;
}