#include "tJogo.h"

#define QTD_PALAVRAS 18289

struct tJogo
{
    char *teclado;
    int tentativas;
};

void JogaJogoSolo(tJogador *jogador, tPalavra *palavra, tArquivo *arquivo)
{
    tJogo *jogo;
    int i = 0;

    jogo = InicializaJogadas();

    InicializaPalavraAtual(palavra);

    InicializaTeclado(jogo);

    CopiaPalavra(palavra);

    InicializaPalavraClassificada(palavra);

    while (1)
    {
        CabecalhoJogo(jogador, palavra, jogo, arquivo);

        ClassificaPalavra(palavra);

        if (AcertouPalavra(palavra) == 1)
        {
            system("clear");

            CabecalhoJogoVitoria(palavra, jogo);

            break;
        }

        if (TentativasZeradas(jogo) == 1)
        {
            system("clear");

            CabecalhoJogoDerrota(palavra, jogo);

            break;
        }
    }
}

/*void JogaJogoDupla(tJogador *jogador_1, tPalavra *palavra, tArquivo *arquivo)
{
    tJogo *jogo;
    int i = 0;

    jogo = InicializaJogadas();

    InicializaPalavraAtual(palavra);

    InicializaTeclado(jogo);

    CopiaPalavra(palavra);

    InicializaPalavraClassificada(palavra);

    for (i = 0; i < 6; i++)
    {
        CabecalhoJogo(jogador, palavra, jogo, arquivo);

        ClassificaPalavra(palavra);

        if (AcertouPalavra(palavra) == 1)
        {
            system("clear");

            CabecalhoJogoVitoria(palavra, jogo);

            break;
        }

        if (TentativasZeradas(jogo) == 1)
        {
            system("clear");

            CabecalhoJogoDerrota(palavra, jogo);

            break;
        }
    }
} */

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

void CabecalhoJogoVitoria(tPalavra *palavra, tJogo *jogo)
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
}

void CabecalhoJogoDerrota(tPalavra *palavra, tJogo *jogo)
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