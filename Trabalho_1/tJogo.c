#include "tJogo.h"

#define QTD_PALAVRAS 18289

struct tJogo
{
    char *teclado;
    int tentativas;
    int quemJoga;
};

void JogaJogoSolo(tJogador *jogador, tPalavra *palavra, tArquivo *arquivo)
{
    tJogo *jogo;

    jogo = InicializaJogadas();

    InicializaPalavraAtual(palavra);

    InicializaTeclado(jogo);

    CopiaPalavra(palavra);

    InicializaPalavraClassificada(palavra);

    while (1)
    {
        AtualizaTentativas(palavra, jogo);

        CabecalhoJogo(jogador, palavra, jogo, arquivo);

        ClassificaPalavra(palavra);

        if (AcertouPalavra(palavra) == 1)
        {
            RegistraEstatisticaSolo(jogador, jogo);
            CabecalhoJogoVitoriaSolo(jogador, palavra, jogo);

            // Coloca porcentagem de vitorias, sequencia e maxima sequencia de vitorias.
            ClassificacaoParcial(jogador);

            ImprimeEstatisticaJogador(jogador);

            // EscreveLehEstatistica(jogador);

            break;
        }

        if (TentativasZeradas(jogo) == 1)
        {
            RegistraEstatisticaSolo(jogador, jogo);
            CabecalhoJogoDerrotaSolo(jogador, palavra, jogo);
            ImprimeEstatisticaJogador(jogador);
            // EscreveLehEstatistica(jogador);

            break;
        }
    }

    LiberaJogo(jogo);
}

void AtualizaTentativas(tPalavra *palavra, tJogo *jogo)
{
    int aux = 0;

    aux = jogo->tentativas;

    PassaTentativas(palavra, aux);
}

void JogaJogoDupla(tJogador *jogador_1, tPalavra *palavra, tArquivo *arquivo)
{
    tJogo *jogo;
    tJogador *jogador_2;

    jogador_2 = CriaJogador();
    LehJogador_2(jogador_1, jogador_2);

    jogo = InicializaJogadas();

    InicializaPalavraAtual(palavra);

    InicializaTeclado(jogo);

    CopiaPalavra(palavra);

    InicializaPalavraClassificada(palavra);

    RandomizaQuemComeca(jogo);

    while (1)
    {
        AtualizaTentativas(palavra, jogo);

        CabecalhoJogoDupla(jogador_1, jogador_2, palavra, jogo, arquivo);

        ClassificaPalavra(palavra);

        if (AcertouPalavra(palavra) == 1)
        {
            RegistraEstatisticaDupla(jogador_1, jogador_2, jogo);
            CabecalhoJogoVitoriaDupla(jogador_1, jogador_2, palavra, jogo);
            ImprimeEstatisticaJogador(jogador_1);
            ImprimeEstatisticaJogador(jogador_2);
            // EscreveLehEstatistica(jogador_1);
            // EscreveLehEstatistica(jogador_2);

            break;
        }

        if (TentativasZeradas(jogo) == 1)
        {
            RegistraEstatisticaDupla(jogador_1, jogador_2, jogo);
            CabecalhoJogoDerrotaDupla(jogador_1, jogador_2, palavra, jogo);
            ImprimeEstatisticaJogador(jogador_1);
            ImprimeEstatisticaJogador(jogador_2);
            // EscreveLehEstatistica(jogador_1);
            // EscreveLehEstatistica(jogador_2);

            break;
        }
    }

    LiberaJogador(jogador_2);
    LiberaJogo(jogo);
}

tJogo *InicializaJogadas()
{
    tJogo *jogo;
    int numero = 6;

    jogo = malloc(sizeof(tJogo));

    jogo->teclado = malloc(sizeof(char) * 27);

    jogo->tentativas = numero;

    return jogo;
}

void CabecalhoJogo(tJogador *jogador, tPalavra *palavra, tJogo *jogo, tArquivo *arquivo)
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

    while (1)
    {
        LehPalavraEscolhidaPeloJogador(palavra);

        if (PalavraExiste(palavra, arquivo) == 1)
        {
            break;
        }

        else
        {
            printf("\nNão existe essa palavra, tente outra: ");
        }
    }

    PadronizaPalavra(palavra);

    ReduzTentativasRestantes(jogo);

    AlteraTeclado(jogo, palavra);
}

void CabecalhoJogoDupla(tJogador *jogador_1, tJogador *jogador_2, tPalavra *palavra, tJogo *jogo, tArquivo *arquivo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ###################### TERMO DUPLA ###################### |\n");
    printf("|                                                           |\n");

    ImprimeAmbosJogadores(jogador_1, jogador_2);

    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    if (jogo->quemJoga == 1)
    {
        ImprimeNomeJogadorCabecalho(jogador_1);
    }

    else
    {
        ImprimeNomeJogadorCabecalho(jogador_2);
    }

    while (1)
    {
        LehPalavraEscolhidaPeloJogador(palavra);

        if (PalavraExiste(palavra, arquivo) == 1)
        {
            break;
        }

        else
        {
            printf("\nNão existe essa palavra, tente outra: ");
        }
    }

    PadronizaPalavra(palavra);

    ReduzTentativasRestantes(jogo);

    AlteraTeclado(jogo, palavra);

    ProximoJogador(jogo);
}

void ProximoJogador(tJogo *jogo)
{
    int um = 1, dois = 2;

    if (jogo->quemJoga == 1)
    {
        jogo->quemJoga = dois;
    }

    else
    {
        jogo->quemJoga = um;
    }
}

int PalavraExiste(tPalavra *palavra, tArquivo *arquivo)
{
    int i, j, cont = 0;

    for (i = 0; i < QTD_PALAVRAS; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (CharPalavraAtual(palavra, j) == CharPalavraArquivo(arquivo, i, j))
            {
                cont++;
            }
        }

        if (cont == 5)
        {
            return 1;
        }
        else
        {
            cont = 0;
        }
    }

    return 0;
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

void CabecalhoJogoVitoriaSolo(tJogador *jogador, tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### W I N ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogador(jogador);
    printf(" venceu!\n\n");
}

void CabecalhoJogoVitoriaDupla(tJogador *jogador_1, tJogador *jogador_2, tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################### W I N ######################### |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    if (jogo->quemJoga == 1)
    {
        ImprimeNomeJogador(jogador_2);
        printf(" venceu!\n\n");
    }

    else
    {
        ImprimeNomeJogador(jogador_1);
        printf(" venceu!\n\n");
    }
}

void CabecalhoJogoDerrotaSolo(tJogador *jogador, tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################## L O S E ######################## |\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogador(jogador);
    printf(" perdeu!\n\n");
}

void CabecalhoJogoDerrotaDupla(tJogador *jogador_1, tJogador *jogador_2, tPalavra *palavra, tJogo *jogo)
{
    printf("+-----------------------------------------------------------+\n");
    printf("| ######################## L O S E ######################## |\n");
    printf("|                                                           |\n");

    ImprimeAmbosJogadores(jogador_1, jogador_2);

    printf("|                                                           |\n");

    ImprimePalavraClassificada(palavra);

    printf("|                                                           |\n");
    printf("|                                                           |\n");

    ImprimeTentativasRestantes(jogo);

    printf("|                                                           |\n");

    ImprimeTecladoJogo(jogo);

    printf("+-----------------------------------------------------------+\n\n");

    ImprimeNomeJogador(jogador_1);
    printf(" e ");
    ImprimeNomeJogador(jogador_2);
    printf(" perderam!\n\n");
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

void LiberaJogo(tJogo *jogo)
{
    free(jogo->teclado);
    jogo->teclado = NULL;

    free(jogo);
    jogo = NULL;
}

void RandomizaQuemComeca(tJogo *jogo)
{
    int num = 0;

    srand((unsigned)time(NULL));

    num = 1 + (rand() % 2);

    jogo->quemJoga = num;

    printf("\n\nQuem comeca: %d\n\n", jogo->quemJoga);
}

void RegistraEstatisticaSolo(tJogador *jogador, tJogo *jogo)
{
    RegistraQtdJogos(jogador);

    if (6 - jogo->tentativas == 1)
    {
        RegistraGanhouUmaTentativa(jogador);
    }

    else if (6 - jogo->tentativas == 2)
    {
        RegistraGanhouDuasTentativas(jogador);
    }

    else if (6 - jogo->tentativas == 3)
    {
        RegistraGanhouTresTentativas(jogador);
    }

    else if (6 - jogo->tentativas == 3)
    {
        RegistraGanhouQuatroTentativas(jogador);
    }

    else if (6 - jogo->tentativas == 4)
    {
        RegistraGanhouCincoTentativas(jogador);
    }

    else if (6 - jogo->tentativas == 5)
    {
        RegistraGanhouSeisTentativas(jogador);
    }

    else
    {
        RegistraQtdDerrotas(jogador);
    }
}

void RegistraEstatisticaDupla(tJogador *jogador_1, tJogador *jogador_2, tJogo *jogo)
{
    RegistraQtdJogos(jogador_1);
    RegistraQtdJogos(jogador_2);

    if (jogo->quemJoga == 1)
    {
        if (6 - jogo->tentativas == 1)
        {
            RegistraGanhouUmaTentativa(jogador_2);
        }

        else if (6 - jogo->tentativas == 2)
        {
            RegistraGanhouDuasTentativas(jogador_2);
        }

        else if (6 - jogo->tentativas == 3)
        {
            RegistraGanhouTresTentativas(jogador_2);
        }

        else if (6 - jogo->tentativas == 3)
        {
            RegistraGanhouQuatroTentativas(jogador_2);
        }

        else if (6 - jogo->tentativas == 4)
        {
            RegistraGanhouCincoTentativas(jogador_2);
        }

        else if (6 - jogo->tentativas == 5)
        {
            RegistraGanhouSeisTentativas(jogador_2);
        }

        else
        {
            RegistraQtdDerrotas(jogador_1);
            RegistraQtdDerrotas(jogador_2);
        }
    }

    else
    {
        if (6 - jogo->tentativas == 1)
        {
            RegistraGanhouUmaTentativa(jogador_1);
        }

        else if (6 - jogo->tentativas == 2)
        {
            RegistraGanhouDuasTentativas(jogador_1);
        }

        else if (6 - jogo->tentativas == 3)
        {
            RegistraGanhouTresTentativas(jogador_1);
        }

        else if (6 - jogo->tentativas == 3)
        {
            RegistraGanhouQuatroTentativas(jogador_1);
        }

        else if (6 - jogo->tentativas == 4)
        {
            RegistraGanhouCincoTentativas(jogador_1);
        }

        else if (6 - jogo->tentativas == 5)
        {
            RegistraGanhouSeisTentativas(jogador_1);
        }

        else
        {
            RegistraQtdDerrotas(jogador_1);
            RegistraQtdDerrotas(jogador_2);
        }
    }
}