#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"

// Dando core dumped.

int main()
{
    int modoJogo = 0;
    char lixo;
    tJogador *jogador;
    tPalavra *palavra;

    jogador = CriaJogador();

    palavra = CriaPalavra();

    LehJogador(jogador);

    LehPalavra(palavra);

    ImprimeJogador(jogador);

    return 0;
}