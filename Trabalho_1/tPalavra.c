#include "tPalavra.h"

#define QTD_PALAVRAS 18289

struct tPalavra
{
    char *palavraColetada;
    char *palavraCopia;
    char *palavraAtual;
    char *palavraClassificada;
    int escolhida;
    char *palavraAtualCopia;
};

tPalavra *CriaPalavra()
{
    int i;
    tPalavra *palavra;

    palavra = malloc(sizeof(tPalavra));

    palavra->palavraColetada = malloc(sizeof(char) * 6);
    palavra->palavraCopia = malloc(sizeof(char) * 6);
    palavra->palavraAtual = malloc(sizeof(char) * 6);
    palavra->palavraClassificada = malloc(sizeof(char) * 22);
    palavra->palavraAtualCopia = malloc(sizeof(char) * 6);

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
    printf("%s\n", palavra->palavraColetada);
}

void LiberaPalavra(tPalavra *palavra)
{
    free(palavra->palavraColetada);
    palavra->palavraColetada = NULL;

    free(palavra->palavraCopia);
    palavra->palavraCopia = NULL;

    free(palavra->palavraAtual);
    palavra->palavraAtual = NULL;

    free(palavra->palavraAtualCopia);
    palavra->palavraAtualCopia = NULL;

    free(palavra->palavraClassificada);
    palavra->palavraClassificada = NULL;

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
    char string[6], stringVerifica[10000];

    while (1)
    {
        scanf("%s", stringVerifica);

        if (strlen(stringVerifica) > 6)
        {
            printf("Palavra invalida, tente outra de tamanho cinco: ");
        }

        else
        {
            strcpy(string, stringVerifica);
            break;
        }
    }

    strcpy(palavra->palavraAtual, string);
}

void ClassificaPalavra(tPalavra *palavra)
{
    int i = 0, j = 0, cont = 0;

    char caracter;

    CopiaPalavra(palavra);

    palavra->palavraClassificada[cont] = '|';

    for (i = 0; i < 5; i++)
    {
        if (NaoTemEssaLetraNaPalavra(palavra, i) == 1)
        {
            cont++;
            palavra->palavraClassificada[cont] = '!';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavraAtualCopia[i];
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = '|';

            palavra->palavraAtualCopia[i] = '0';
        }

        else if (palavra->palavraAtualCopia[i] == palavra->palavraCopia[i])
        {
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = palavra->palavraAtualCopia[i];
            cont++;
            palavra->palavraClassificada[cont] = ' ';
            cont++;
            palavra->palavraClassificada[cont] = '|';

            palavra->palavraAtualCopia[i] = '0';
            palavra->palavraCopia[i] = '0';
        }

        else
        {
            for (j = 0; j < 5; j++)
            {
                if (palavra->palavraAtualCopia[i] == palavra->palavraCopia[j])
                {
                    cont++;
                    palavra->palavraClassificada[cont] = '(';
                    cont++;
                    palavra->palavraClassificada[cont] = palavra->palavraAtualCopia[i];
                    cont++;
                    palavra->palavraClassificada[cont] = ')';
                    cont++;
                    palavra->palavraClassificada[cont] = '|';

                    palavra->palavraCopia[j] = '0';

                    break;
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
        if (palavra->palavraColetada[i] >= 'a' && palavra->palavraColetada[i] <= 'z')
        {
            caracter = palavra->palavraColetada[i];
            caracter -= 32;
            palavra->palavraColetada[i] = caracter;
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
        if (palavra->palavraCopia[j] == palavra->palavraAtual[i])
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

    printf("\n%s\n", palavra->palavraClassificada);
}

int AcertouPalavra(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraAtual[i] != palavra->palavraColetada[i])
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
        palavra->palavraCopia[i] = palavra->palavraColetada[i];
        palavra->palavraAtualCopia[i] = palavra->palavraAtual[i];

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
    if (palavra->palavraAtual[i] == palavra->palavraColetada[i])
    {
        return 0;
    }

    return 1;
}

int ColetaPalavraEscolhida(tPalavra *palavra)
{
    int result;

    result = palavra->escolhida;

    return result;
}

void CopiaStringParaPalavra(tPalavra *palavra, char string[6])
{
    int i;

    for (i = 0; i < 6; i++)
    {
        palavra->palavraColetada[i] = string[i];
    }

    printf("\n%s\n", palavra->palavraColetada);
}

char CharPalavraAtual(tPalavra *palavra, int j)
{
    char caracter;

    caracter = palavra->palavraAtual[j];

    return caracter;
}