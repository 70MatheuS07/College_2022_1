#include "tArquivo.h"

#define QTD_PALAVRAS 5

char **ArmazenaPalavrasArquivo()
{
    char **matriz;
    int i = 0, j = 0;
    char caracter;

    matriz = malloc(QTD_PALAVRAS * sizeof(char *));

    for (i = 0; i < QTD_PALAVRAS + 1; i++)
    {
        matriz[i] = malloc(6 * sizeof(char));
    }

    FILE *arquivo;

    arquivo = fopen("cincoPalavras.txt", "r");

    i = 0;

    do
    {
        fscanf(arquivo, "%c", &caracter);

        if (caracter == '\n')
        {
            matriz[i][j] = '\0';
            i++;
            j = 0;
        }

        else
        {
            matriz[i][j] = caracter;
            j++;
        }

    } while (!feof(arquivo));

    fclose(arquivo);

    for (i = 0; i < QTD_PALAVRAS + 1; i++)
    {
        printf("\n%s", matriz[i]);
    }

    return matriz;
}

void LiberaMatrizArquivo(char **matriz)
{
    int i = 0;

    for (i = 0; i < QTD_PALAVRAS + 1; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}