#include "tPalavra.h"

#define QTD_PALAVRAS 18289

struct tPalavra
{
    char palavra[6];
    char palavraAtual[6];
    char palavraDigitada[6];
    int escolhida;
};

tPalavra *CriaPalavra()
{
    tPalavra *palavra;

    palavra = malloc(sizeof(palavra));

    return palavra;
}

void SorteiaPalavra(tPalavra *palavra)
{
    int tempo = 0;
    int escolhida = 0;

    tempo = PegaTempo();

    srand(tempo);

    escolhida = rand() % QTD_PALAVRAS - 1;

    palavra->escolhida = escolhida;

    printf("\n%d\n", palavra->escolhida);
}

void ImprimePalavra(tPalavra *palavra)
{
    printf("%s\n", palavra->palavra);
}

void ColetaPalavraDoArquivo(tPalavra *palavra, char **matrizPalavras)
{
    int i = 0, j = 0;
    char string[6];

    i = palavra->escolhida;

    for (j = 0; j < 6; j++)
    {
        string[j] = matrizPalavras[i][j];
    }

    for (i = 0; i < 6; i++)
    {
        palavra->palavra[i] = string[i];
    }

    printf("\n%s\n", palavra->palavra);
}

void LiberaPalavra(tPalavra *palavra)
{
    free(palavra);
    palavra = NULL;
}

void InicializaPalavraAtual(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        palavra->palavraAtual[i] = '*';
    }

    palavra->palavraAtual[5] = '\0';
}

int InicioDoJogo(tPalavra *palavra)
{
    int i = 0;
    int cont = 0;

    for (i = 0; i < 5; i++)
    {
        if (palavra->palavraAtual[i] != '*')
        {
            printf("\nEntrou\n");
            return 0;
        }
    }

    return 1;
}

void LehPalavraEscolhidaPeloJogador(tPalavra *palavra)
{
    char string[6];
    char lixo, caracter;
    int i = 0;

    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            scanf("%c", &caracter);

            string[i] = caracter;
        }

        if (i == 5)
        {
            string[i] = '\0';
            i = 0;
        }

        break;
    }

    for (i = 0; i < 6; i++)
    {
        palavra->palavraDigitada[i] = string[i];
    }
}