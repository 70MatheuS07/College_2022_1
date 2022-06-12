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

    scanf("%[^\n]", nome);

    strcpy(jogador->nome, nome);
}

void LimpaBuffer()
{
    int ch;
    do
    {
        ch = fgetc(stdin);

    } while (ch != EOF && ch != '\n');
}

void ImprimeJogador(tJogador *jogador)
{
    printf("%s\n", jogador->nome);
}