#include "tArquivo.h"

#define QTD_PALAVRAS 18289

char **ArmazenaPalavrasArquivo()
{
    char **matriz;
    int i = 0, j = 0;
    char caracter;

    matriz = malloc(QTD_PALAVRAS * sizeof(char *));

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        matriz[i] = malloc(6 * sizeof(char));
    }

    FILE *arquivo;

    arquivo = fopen("palavras.txt", "r");

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

    // Corrigi a ultima palavra que está duplicando o ultimo char.
    matriz[QTD_PALAVRAS-1][5] = '\0';

    return matriz;
}

void LiberaMatrizArquivo(char **matriz)
{
    int i = 0;

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

void ImprimeMatriz(char **matriz)
{
    int i = 0, j = 0;

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%c", matriz[i][j]);
        }

        printf("\n");
    }
}