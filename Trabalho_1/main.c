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
    tArquivo *arquivo;

    jogador = CriaJogador();
    palavra = CriaPalavra();

    LehJogador(jogador);

    SorteiaPalavra(palavra);

    arquivo = CriaArmazenaPalavrasArquivo();

    ColetaPalavraDoArquivo(palavra, arquivo);

    JogaJogo(jogador, palavra, arquivo);

    LiberaJogador(jogador);
    LiberaPalavra(palavra);
    LiberaPalavrasArquivo(arquivo);

    return 0;
}