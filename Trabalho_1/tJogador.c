#include "tJogador.h"

struct tJogador
{
    char nome[21];
};

tJogador *CriaJogador()
{
    tJogador *jogador;

    jogador = malloc(sizeof(jogador));

    return jogador;
}

void LehJogador(tJogador *jogador)
{
    char nome[21];

    scanf("%[A-z]", nome);

    strcpy(jogador->nome, nome);

    LimpaBuffer();
}

void LimpaBuffer()
{
    int ch;

    do
    {
        ch = fgetc(stdin);

    } while (ch != EOF && ch != '\n');
}

void LiberaJogador(tJogador *jogador)
{
    free(jogador);
    jogador = NULL;
}

void ImprimeNomeJogadorCabecalho(tJogador *jogador)
{
    printf(" Jogador %s digite uma palavra a sua escolha: ", jogador->nome);
}