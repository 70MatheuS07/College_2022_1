#include "tPalavra.h"

#define QTD_PALAVRAS 18289

struct tPalavra
{
    char *palavra;
    char *palavraCopia;
    char *palavraAtual;
    char *palavraClassificada;
    int *escolhida;
};

tPalavra *CriaPalavra()
{
    int i;
    tPalavra *palavra;

    palavra = malloc(sizeof(tPalavra *));

    palavra->palavra = malloc(sizeof(char) * 6);
    palavra->palavraCopia = malloc(sizeof(char) * 6);
    palavra->palavraAtual = malloc(sizeof(char) * 6);
    palavra->palavraClassificada = malloc(sizeof(char) * 22);
    palavra->escolhida = malloc(sizeof(int));

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

    printf("\n%d\n", escolhida);
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
    if (palavra->palavra != NULL)
    {
        free(palavra->palavra);
        palavra->palavra = NULL;
    }

    if (palavra->palavraCopia != NULL)
    {
        free(palavra->palavraCopia);
        palavra->palavraCopia = NULL;
    }

    if (palavra->palavraAtual != NULL)
    {
        free(palavra->palavraAtual);
        palavra->palavraAtual = NULL;
    }

    if (palavra->palavraClassificada != NULL)
    {
        free(palavra->palavraClassificada);
        palavra->palavraClassificada = NULL;
    }

    if (palavra->escolhida != NULL)
    {
        free(palavra->escolhida);
        palavra->escolhida = NULL;
    }

    free(palavra);
    palavra = NULL;
}

void InicializaPalavraAtual(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        palavra->palavraAtual[i] = '\0';
    }
}

void LehPalavraEscolhidaPeloJogador(tPalavra *palavra)
{
    int i = 0;
    char caracter;

    for (i = 0; i < 5; i++)
    {
        scanf("%c", &caracter);
        palavra->palavraAtual[i] = caracter;
    }

    palavra->palavraAtual[5] = '\0';
}

void ClassificaPalavra(tPalavra *palavra)
{
    int i = 0, j = 0, cont = 0;
    char caracter;

    palavra->palavraClassificada[cont] = '|';

    for (i = 0; i < 5; i++)
    {
        if (palavra->palavraAtual[i] == palavra->palavra[i])
        {
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavraAtual[i];
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = '|';

            palavra->palavraCopia[i] = ' ';
        }

        else if (NaoTemEssaLetraNaPalavra(palavra, i) == 1)
        {
            cont++;
            palavra->palavraClassificada[cont] = '!';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavraAtual[i];
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = '|';
        }

        else
        {
            for (j = 0; j < 5; j++)
            {
                if (palavra->palavraAtual[i] == palavra->palavra[j])
                {
                    cont++;
                    palavra->palavraClassificada[cont] = '(';
                    cont++;
                    palavra->palavraClassificada[cont] = palavra->palavraAtual[i];
                    cont++;
                    palavra->palavraClassificada[cont] = ')';
                    cont++;
                    palavra->palavraClassificada[cont] = '|';
                }
            }
        }
    }

    palavra->palavraClassificada[21] = '\0';
}

void PadronizaPalavra(tPalavra *palavra)
{
    int i = 0;
    char caracter;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavra[i] >= 'a' && palavra->palavra[i] <= 'z')
        {
            caracter = palavra->palavra[i];
            caracter -= 32;
            palavra->palavra[i] = caracter;
        }
    }

    i = 0;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraAtual[i] >= 'a' && palavra->palavraAtual[i] <= 'z')
        {
            caracter = palavra->palavraAtual[i];
            caracter -= 32;
            palavra->palavraAtual[i] = caracter;
        }
    }
}

int NaoTemEssaLetraNaPalavra(tPalavra *palavra, int i)
{
    int j = 0, cont = 0;

    for (j = 0; j < 5; j++)
    {
        if (palavra->palavraCopia[i] == palavra->palavraAtual[j])
        {
            cont++;
        }
    }

    if (cont == 1)
    {
        return 0;
    }

    return 1;
}

void ImprimePalavraClassificada(tPalavra *palavra)
{
    printf("|                   ");

    printf("%s", palavra->palavraClassificada);

    printf("                   |\n");
}

void InicializaPalavraClassificada(tPalavra *palavra)
{
    palavra->palavraClassificada[0] = '|';
    palavra->palavraClassificada[1] = ' ';
    palavra->palavraClassificada[2] = ' ';
    palavra->palavraClassificada[3] = ' ';
    palavra->palavraClassificada[4] = '|';
    palavra->palavraClassificada[5] = ' ';
    palavra->palavraClassificada[6] = ' ';
    palavra->palavraClassificada[7] = ' ';
    palavra->palavraClassificada[8] = '|';
    palavra->palavraClassificada[9] = ' ';
    palavra->palavraClassificada[10] = ' ';
    palavra->palavraClassificada[11] = ' ';
    palavra->palavraClassificada[12] = '|';
    palavra->palavraClassificada[13] = ' ';
    palavra->palavraClassificada[14] = ' ';
    palavra->palavraClassificada[15] = ' ';
    palavra->palavraClassificada[16] = '|';
    palavra->palavraClassificada[17] = ' ';
    palavra->palavraClassificada[18] = ' ';
    palavra->palavraClassificada[19] = ' ';
    palavra->palavraClassificada[20] = '|';
    palavra->palavraClassificada[21] = '\0';

    printf("\n\n%s\n\n", palavra->palavraClassificada);
}

int AcertouPalavra(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraAtual[i] != palavra->palavra[i])
        {
            return 0;
        }
    }

    return 1;
}

char ColetaLetraPalavra(tPalavra *palavra, int i)
{
    char caracter;

    caracter = palavra->palavraAtual[i];

    if (caracter >= 'a' && caracter <= 'z')
    {
        caracter -= 32;
    }

    return caracter;
}

void CopiaPalavra(tPalavra *palavra)
{
    int i;
    char caracter;
    for (i = 0; i < 6; i++)
    {
        palavra->palavraCopia[i] = palavra->palavra[i];

        caracter = palavra->palavraCopia[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
            palavra->palavraCopia[i] = caracter;
        }
    }
}

int NaoSaoLetrasIguais(tPalavra *palavra, int i)
{
    if (palavra->palavraAtual[i] == palavra->palavra[i])
    {
        return 0;
    }

    return 1;
}