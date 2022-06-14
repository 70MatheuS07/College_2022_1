#include "tJogo.h"

struct tJogo
{
    int tentativas;
};

void JogaJogo(tJogador *jogador, tPalavra *palavra)
{
    tJogo *jogadas;
    int i = 0;

    jogadas = InicializaJogadas();

    InicializaPalavraClassificada(palavra);

    // DEBUG THIS!

    for (i = 0; i < 6; i++)
    {
        CabecalhoJogo(jogador, palavra, jogadas);

        ClassificaPalavra(palavra);
    }
}

tJogo *InicializaJogadas()
{
    tJogo *jogadas;

    jogadas = malloc(sizeof(jogadas));

    jogadas->tentativas = 6;

    return jogadas;
}

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogadas)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    printf("|                     ");
    ImprimePalavraClassificada(palavra);
    printf("                  |\n");

    printf("|                                                           |\n");
    printf("|                                                           |\n");
    printf("| Tentativas restantes: 6                                   |\n");
    printf("|                                                           |\n");
    printf("|                    Q W E R T Y U I O P                    |\n");
    printf("|                     A S D F G H J K L                     |\n");
    printf("|                       Z X C V B N M                       |\n");
    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogadorCabecalho(jogador);

    LehPalavraEscolhidaPeloJogador(palavra);
}