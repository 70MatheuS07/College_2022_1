#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tJogador.h"
#include "tPalavra.h"
#include "tArquivo.h"
#include "tTempo.h"
#include "tJogo.h"

#define QTD_PALAVRAS 18289

int main()
{
    int modoJogo = 0, jogou = 0, num = 0, i = 0;
    char lixo;
    char nomeSalvo[21];

    tJogador *jogador_1;
    tPalavra *palavra;
    tArquivo *arquivo;

    jogador_1 = CriaJogador();
    palavra = CriaPalavra();
    LehJogador_1(jogador_1);

    arquivo = CriaArmazenaPalavrasArquivo();

    while (1)
    {
        while (1)
        {
            SorteiaPalavra(palavra, i);
            ColetaPalavraDoArquivo(palavra, arquivo);

            if (NaoFoiSorteadoEssaPalavra(palavra) == 1)
            {
                RegistraPalavraNoArquivo(palavra);
                break;
            }

            else
            {
                i++;
            }

            if (i == QTD_PALAVRAS - 1)
            {
                remove("palavrasUsadas.txt");
                i = 0;
            }
        }

        SalvaNome(jogador_1, nomeSalvo, jogou);

        InicializaJogador(jogador_1);

        modoJogo = EscolhaDeModo(jogador_1);

        if (modoJogo == 1)
        {
            JogaJogoSolo(jogador_1, palavra, arquivo);
            jogou++;
        }

        else if (modoJogo == 2)
        {
            JogaJogoDupla(jogador_1, palavra, arquivo);
            jogou++;
        }

        else if (modoJogo == 8)
        {
            // Ranking.
        }

        else if (modoJogo == 9)
        {
            ImprimeTodasEstatisticas();
        }

        else if (modoJogo == 0)
        {
            if (jogou == 0)
            {
                printf("Voce ainda nao jogou nenhum modo, se sair agora tera seu current_steak zerado,\n");
                printf("deseja continuar?\n\n");

                printf("1- Continuar\n");
                printf("2- Sair do Jogo\n\n");

                scanf("%d", &num);

                printf("\n");

                if (num != 1 && num != 2)
                {
                    printf("Opcao invalida, tente outra dentro das opcoes: ");

                    scanf("%d", &num);
                }
            }

            if (num == 2 || jogou > 0)
            {
                break;
            }
        }
    }

    LiberaJogador(jogador_1);
    LiberaPalavra(palavra);
    LiberaPalavrasArquivo(arquivo);

    return 0;
}