#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"
#include "tArquivo.h"
#include "tTempo.h"
#include "tJogo.h"

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

    SorteiaPalavra(palavra);

    InicializaPalavraAtual(palavra);

    palavras = ArmazenaPalavrasArquivo();

    ColetaPalavraDoArquivo(palavra, palavras);

    // JogaJogo(jogador, palavra);

    LiberaJogador(jogador);
    LiberaPalavra(palavra);
    LiberaPalavrasArquivo(palavras);

    return 0;
}