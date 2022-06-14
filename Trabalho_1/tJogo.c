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

        PadronizaPalavra(palavra);

        ClassificaPalavra(palavra);

        if (TentativasZeradas(jogadas) == 1 || AcertouPalavra(palavra) == 1)
        {
            CabecalhoJogoFinal(palavra, jogadas);

            break;
        }
    }
}

tJogo *InicializaJogadas()
{
    tJogo *jogadas;

    jogadas = malloc(sizeof(tJogo *));

    jogadas->tentativas = 6;

    return jogadas;
}

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogadas)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogadas);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(palavra);

    printf("|                    Q W E R T Y U I O P                    |\n");
    printf("|                     A S D F G H J K L                     |\n");
    printf("|                       Z X C V B N M                       |\n");
    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogadorCabecalho(jogador);

    LehPalavraEscolhidaPeloJogador(palavra);

    ReduzTentativasRestantes(jogadas);
}

void ImprimeTentativasRestantes(tJogo *jogadas)
{
    printf("| Tentativas restantes: %d                                   |\n", jogadas->tentativas);
}

void ReduzTentativasRestantes(tJogo *jogadas)
{
    int result = 0;

    result = jogadas->tentativas;
    result--;
    jogadas->tentativas = result;
}

int TentativasZeradas(tJogo *jogadas)
{
    if (jogadas->tentativas == 0)
    {
        return 1;
    }

    return 0;
}

void CabecalhoJogoFinal(tPalavra *palavra, tJogo *jogadas)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogadas);

    printf("|                                                           |\n");
    printf("|                    Q W E R T Y U I O P                    |\n");
    printf("|                     A S D F G H J K L                     |\n");
    printf("|                       Z X C V B N M                       |\n");
    printf("+-----------------------------------------------------------+\n\n");
}