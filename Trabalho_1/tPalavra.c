#include "tPalavra.h"

#define QTD_PALAVRAS 5

struct tPalavra
{
    char *palavra;
    int escolhida;
};

tPalavra *CriaPalavra()
{
    tPalavra *palavra;

    palavra = malloc(6 * sizeof(palavra));

    return palavra;
}

void SorteiaPalavra(tPalavra *palavra)
{
    int tempo = 0;
    int escolhida = 0;

    tempo = PegaTempo();

    srand(tempo);

    escolhida = rand() % QTD_PALAVRAS;

    palavra->escolhida = escolhida;
}

void ImprimePalavra(tPalavra *palavra)
{
    printf("%s\n", palavra->palavra);
}