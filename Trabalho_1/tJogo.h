#ifndef JOGO_H
#define JOGO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"
#include "tArquivo.h"
#include "tTempo.h"

void ComecaJogo(tJogador *jogador, tPalavra *palavra);

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra);



#endif