#include "tJogador.h"

struct tJogador
{
    char *nome;
    int *tentativas;
};

tJogador *CriaJogador()
{
    tJogador *jogador;

    jogador = malloc(sizeof(tJogador));

    jogador->nome = malloc(sizeof(char) * 21);

    jogador->tentativas = malloc(sizeof(int));

    return jogador;
}

void LehJogador(tJogador *jogador)
{
    char nome[21];

    scanf("%[A-z]", nome);

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

void LiberaJogador(tJogador *jogador)
{
    if (jogador->nome != NULL)
    {
        free(jogador->nome);
        jogador->nome = NULL;
    }

    if (jogador->tentativas != NULL)
    {
        free(jogador->tentativas);
        jogador->tentativas = NULL;
    }

    if (jogador != NULL)
    {
        free(jogador);
        jogador = NULL;
    }
}

void ImprimeNomeJogadorCabecalho(tJogador *jogador)
{
    printf(" Jogador %s digite uma palavra a sua escolha: ", jogador->nome);
}