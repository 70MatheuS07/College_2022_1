#include "tJogo.h"

void ComecaJogo(tJogador *jogador, tPalavra *palavra)
{
    CabecalhoJogo(jogador, palavra);
}

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra)
{
    system("clear");
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    if (InicioDoJogo(palavra) == 1)
    {
        printf("|                   |   |   |   |   |   |                   |\n");
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
}