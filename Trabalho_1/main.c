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
    int modoJogo = 0, jogou = 0, num = 0;
    char lixo;

    tJogador *jogador_1;
    tPalavra *palavra;
    tArquivo *arquivo;

    jogador_1 = CriaJogador();
    palavra = CriaPalavra();
    LehJogador(jogador_1);
    SorteiaPalavra(palavra);
    arquivo = CriaArmazenaPalavrasArquivo();
    ColetaPalavraDoArquivo(palavra, arquivo);

    while (1)
    {
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
            // Estatisticas.
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

            if (num == 2)
            {
                break;
            }

            else
            {
                system("clear");
            }
        }
    }
    LiberaJogador(jogador);
    LiberaPalavra(palavra);
    LiberaPalavrasArquivo(arquivo);

    return 0;
}