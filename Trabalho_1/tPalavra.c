#include "tPalavra.h"

#define QTD_PALAVRAS 18289

struct tPalavra
{
    char palavra[6];
    char palavraAtual[6];
    char palavraClassificada[21];
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
        palavra->palavraAtual[i] = string[i];
    }
}

void ClassificaPalavra(tPalavra *palavra)
{
    int i = 0, j = 0, cont = 0;

    palavra->palavraClassificada[0] = '|';

    for (i = 0; i < 5; i++)
    {
        if (palavra->palavraAtual[i] == palavra->palavra[i])
        {
            cont++;
            palavra->palavraClassificada[cont] = '*';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavra[i];
            cont++;
            palavra->palavraClassificada[cont] = '*';
            cont++;
            palavra->palavraClassificada[cont] = '|';
        }

        else if (NaoTemEssaLetraNaPalavra(palavra, i) == 0)
        {
            cont++;
            palavra->palavraClassificada[cont] = '!';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavra[i];
            cont++;
            palavra->palavraClassificada[cont] = '*';
            cont++;
            palavra->palavraClassificada[cont] = '|';
        }

        else
        {
            for (j = i; j < 5; j++)
            {
                if (palavra->palavraAtual[i] == palavra->palavra[j])
                {
                    cont++;
                    palavra->palavraClassificada[cont] = '(';
                    cont++;
                    palavra->palavraClassificada[cont] = palavra->palavra[i];
                    cont++;
                    palavra->palavraClassificada[cont] = ')';
                    cont++;
                    palavra->palavraClassificada[cont] = '|';
                }
            }
        }
    }

    palavra->palavraClassificada[0] = '\0';
}

int NaoTemEssaLetraNaPalavra(tPalavra *palavra, int i)
{
    int j = 0;

    for (j = 0; j < 5; j++)
    {
        if (palavra->palavraAtual[i] == palavra->palavra[j])
        {
            return 0;
        }
    }
}

void ImprimePalavraClassificada(tPalavra *palavra)
{
    int i;

    for (i = 0; i < 20; i++)
    {
        if (palavra->palavraClassificada[i] == '*')
        {
            printf(" ");
        }

        else
        {
            printf("%c", palavra->palavraClassificada[i]);
        }
    }
}

void InicializaPalavraClassificada(tPalavra *palavra)
{
    int cont = 0;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = ' ';
    cont++;
    palavra->palavraClassificada[cont] = '|';
    cont++;
    palavra->palavraClassificada[cont] = '\0';

    printf("\n\n%d\n\n", cont);
}