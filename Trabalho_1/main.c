#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"
#include "tArquivo.h"
#include "tTempo.h"

int main()
{
    int modoJogo = 0;
    char lixo;

    tJogador *jogador;
    tPalavra *palavra;
    char **palavras;

    jogador = CriaJogador();

    palavra = CriaPalavra();

    LehJogador(jogador);

    LimpaBuffer();

    ImprimeJogador(jogador);

    palavras = ColetaPalavrasArquivo();

    return 0;
}