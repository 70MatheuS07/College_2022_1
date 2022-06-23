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
        /* Confere se a palavra sorteada já foi usada
           E caso já tenham sido usadas todas as palavras
           do arquivo, recomeça a usar as palavras. */

        while (1)
        {
            /* Se o jogador entrar com o nome, mas não for jogar
               aqui garante que nao sera sorteada outra palavra. */
            if (num > 0)
            {
                num = 0;
                break;
            }

            SorteiaPalavra(palavra, i);
            ColetaPalavraDoArquivo(palavra, arquivo);

            if (NaoFoiSorteadoEssaPalavra(palavra) == 1)
            {
                break;
            }

            else
            {
                i++;
            }

            /* Garante que quando todas as palavras forem lidas
               exclui o arquivo palavrasUsadas e pode reutilizar
               as palavras novamente. */

            if (i == QTD_PALAVRAS - 1)
            {
                remove("palavrasUsadas.txt");
                i = 0;
            }
        }

        /* Por algum motivo quando eu guardo a pessoa dentro do arquivo "jogadores.bin"
           seu nome sai da struct tJogador jogador_1, então eu faço um ponto que salva
           o nome do participante para não perder. */
        SalvaNome(jogador_1, nomeSalvo, jogou);

        InicializaJogador(jogador_1);

        modoJogo = EscolhaDeModo(jogador_1);

        if (modoJogo == 1)
        {
            JogaJogoSolo(jogador_1, palavra, arquivo);
            RegistraPalavraNoArquivo(palavra);
            jogou++;
        }

        else if (modoJogo == 2)
        {
            JogaJogoDupla(jogador_1, palavra, arquivo);
            RegistraPalavraNoArquivo(palavra);
            jogou++;
        }

        else if (modoJogo == 8)
        {
            // Ranking.
        }

        else if (modoJogo == 9)
        {
            // Está dando segmentation fault. Quando faz na mão.
            // ImprimeEstatisticaJogador(jogador_1);
        }

        else if (modoJogo == 0)
        {
            if (jogou == 0)
            {
                printf("Voce ainda nao jogou nenhum modo, se sair agora tera seu current_steak zerado,\n");
                printf("deseja continuar?\n\n");

                printf("1- Continuar\n");
                printf("2- Sair do Jogo\n\n");

                /* Aqui eu iria zerar a sequencia de vitorias,
                   porém nao consegui fazer o arquivo binario. */

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

    LiberaPalavrasArquivo(arquivo);
    LiberaJogador(jogador_1);
    LiberaPalavra(palavra);

    return 0;
}