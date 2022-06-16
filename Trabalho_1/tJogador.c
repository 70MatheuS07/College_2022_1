#include "tJogador.h"

struct tJogador
{
    char *nome;
    int tentativas;
};

tJogador *CriaJogador()
{
    tJogador *jogador;

    jogador = malloc(sizeof(tJogador));

    jogador->nome = malloc(sizeof(char) * 21);

    return jogador;
}

void LehJogador(tJogador *jogador)
{
    int i = 0;
    char caracter;
    char nome[21];

    scanf("%s", nome);

    strcpy(jogador->nome, nome);
}

void LiberaJogador(tJogador *jogador)
{
    free(jogador->nome);
    jogador->nome = NULL;

    free(jogador);
    jogador = NULL;
}

void ImprimeNomeJogadorCabecalho(tJogador *jogador)
{
    printf(" Jogador %s digite uma palavra a sua escolha: ", jogador->nome);
}