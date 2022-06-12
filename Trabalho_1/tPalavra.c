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
}

void ImprimePalavra(tPalavra *palavra)
{
    printf("%s\n", palavra->palavra);
}