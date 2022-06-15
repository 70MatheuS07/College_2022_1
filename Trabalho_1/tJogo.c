#include "tJogo.h"

struct tJogo
{
    char teclado[27];
    int tentativas;
    // adicionar palavraClassificada aqui.
};

void JogaJogo(tJogador *jogador, tPalavra *palavra)
{
    tJogo *jogo;
    int i = 0;

    jogo = InicializaJogadas();

    InicializaPalavraClassificada(palavra);

    InicializaTeclado(jogo);

    CopiaPalavra(palavra);

    for (i = 0; i < 6; i++)
    {
        CabecalhoJogo(jogador, palavra, jogo);

        ClassificaPalavra(palavra);

        if (TentativasZeradas(jogo) == 1 || AcertouPalavra(palavra) == 1)
        {
            CabecalhoJogoFinal(palavra, jogo);

            break;
        }
    }
}

tJogo *InicializaJogadas()
{
    tJogo *jogadas;
    int numero = 6;

    jogadas = malloc(sizeof(tJogo *));

    jogadas->tentativas = numero;

    return jogadas;
}

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogadorCabecalho(jogador);

    LehPalavraEscolhidaPeloJogador(palavra);

    PadronizaPalavra(palavra);

    ReduzTentativasRestantes(jogo);

    AlteraTeclado(jogo, palavra);
}

void ImprimeTentativasRestantes(tJogo *jogo)
{
    printf("| Tentativas restantes: %d                                   |\n", jogo->tentativas);
}

void ReduzTentativasRestantes(tJogo *jogo)
{
    int result = 0;

    result = jogo->tentativas;
    result--;
    jogo->tentativas = result;
}

int TentativasZeradas(tJogo *jogo)
{
    if (jogo->tentativas == 0)
    {
        return 1;
    }

    return 0;
}

void CabecalhoJogoFinal(tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### TERMO ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");
    printf("|                    Q W E R T Y U I O P                    |\n");
    printf("|                     A S D F G H J K L                     |\n");
    printf("|                       Z X C V B N M                       |\n");
    printf("+-----------------------------------------------------------+\n\n");
}

void ImprimeTecladoJogo(tJogo *jogo)
{
    int i = 0;

    printf("|                    ");

    while (i < 10)
    {
        printf("%c ", jogo->teclado[i]);
        i++;
    }

    printf("                   |\n");

    printf("|                     ");

    while (i < 19)
    {
        printf("%c ", jogo->teclado[i]);
        i++;
    }

    printf("                    |\n");

    printf("|                       ");

    while (i < 26)
    {
        printf("%c ", jogo->teclado[i]);
        i++;
    }

    printf("                      |\n");
}

void InicializaTeclado(tJogo *jogo)
{
    jogo->teclado[0] = 'Q';
    jogo->teclado[1] = 'W';
    jogo->teclado[2] = 'E';
    jogo->teclado[3] = 'R';
    jogo->teclado[4] = 'T';
    jogo->teclado[5] = 'Y';
    jogo->teclado[6] = 'U';
    jogo->teclado[7] = 'I';
    jogo->teclado[8] = 'O';
    jogo->teclado[9] = 'P';
    jogo->teclado[10] = 'A';
    jogo->teclado[11] = 'S';
    jogo->teclado[12] = 'D';
    jogo->teclado[13] = 'F';
    jogo->teclado[14] = 'G';
    jogo->teclado[15] = 'H';
    jogo->teclado[16] = 'J';
    jogo->teclado[17] = 'K';
    jogo->teclado[18] = 'L';
    jogo->teclado[19] = 'Z';
    jogo->teclado[20] = 'X';
    jogo->teclado[21] = 'C';
    jogo->teclado[22] = 'V';
    jogo->teclado[23] = 'B';
    jogo->teclado[24] = 'N';
    jogo->teclado[25] = 'M';
    jogo->teclado[26] = '\0';
}

void AlteraTeclado(tJogo *jogo, tPalavra *palavra)
{
    int i = 0, j = 0;
    char letra;

    for (i = 0; i < 5; i++)
    {
        if (NaoTemEssaLetraNaPalavra(palavra, i) == 1)
        {
            if (NaoSaoLetrasIguais(palavra, i) == 1)
            {
                letra = ColetaLetraPalavra(palavra, i);

                for (j = 0; j < 26; j++)
                {
                    if (letra == jogo->teclado[j])
                    {
                        jogo->teclado[j] = '_';
                        break;
                    }
                }
            }
        }
    }
}