#include "tArquivo.h"

#define QTD_PALAVRAS 5

char **ColetaPalavrasArquivo()
{
    char **matriz;
    int i = 0;

    matriz = malloc(QTD_PALAVRAS * sizeof(char *));

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        matriz[i] = malloc(6 * sizeof(char));
    }

    FILE *arquivo;

    arquivo = fopen("cincoPalavras.txt", "r");

    for (i = 0; i < QTD_PALAVRAS || !feof(arquivo); i++)
    {
        fscanf(arquivo, "%[^\n]", matriz[i]);
    }

    fclose(arquivo);
}