#include "tPalavra.h"

#define QTD_PALAVRAS 5

struct tPalavra
{
    char *palavra;
};

tPalavra *CriaPalavra()
{
    tPalavra *palavra;

    palavra = malloc(6 * sizeof(palavra));

    return palavra;
}

void LehPalavra(tPalavra *palavra)
{
    int tempo = 0;
    int escolhida = 0;

    tempo = PegaTempo();

    srand(tempo);

    escolhida = rand() % QTD_PALAVRAS;

    PegaPalavraArquivo(palavra, escolhida);
}

int PegaTempo()
{
    int result = 0;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    return (tm.tm_mday + tm.tm_mon + 1 + tm.tm_year + 1900);
}

//Parei aqui, tá dando B.O
void PegaPalavraArquivo(tPalavra *palavra, int escolhida)
{
    int i = 0, j = 0, x, y;
    char string[6];
    char caracter;
    FILE *arquivo;
    char matriz[QTD_PALAVRAS][6];

    arquivo = fopen("cincoPalavras.txt", "r");

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

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < 5; j++)
    {
        palavra->palavra[j] = matriz[escolhida - 1][j];
    }
}

void ImprimePalavra(tPalavra *palavra)
{
    printf("%s\n", palavra->palavra);
}