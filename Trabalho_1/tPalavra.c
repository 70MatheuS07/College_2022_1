#include "tPalavra.h"

#define QTD_PALAVRAS 18289

struct tPalavra
{
    char *palavraColetada;
    char *palavraCopia;
    char *palavraAtual;
    char **palavraClassificada;
    char *palavraAtualCopia;
    int tentativa;
    int escolhida;
    int quantidadePalavras;
};

/**
 * @brief Aloca memoria para tPalavra *palavra.
 *
 * @return tPalavra*
 */
tPalavra *CriaPalavra()
{
    int i;
    tPalavra *palavra;

    palavra = malloc(sizeof(tPalavra));

    palavra->palavraColetada = malloc(sizeof(char) * 6);
    palavra->palavraCopia = malloc(sizeof(char) * 6);
    palavra->palavraAtual = malloc(sizeof(char) * 6);
    palavra->palavraClassificada = malloc(sizeof(char *) * 6);

    for (i = 0; i < 6; i++)
    {
        palavra->palavraClassificada[i] = malloc(sizeof(char) * 22);
    }

    palavra->palavraAtualCopia = malloc(sizeof(char) * 6);

    return palavra;
}

/**
 * @brief Realiza o sorteio do numero que vai selecionar a palavra.
 *
 * @param palavra
 * @param i
 */
void SorteiaPalavra(tPalavra *palavra, int i)
{
    unsigned int tempo = 0;
    int escolhida = 0;

    if (i == 0)
    {
        tempo = PegaTempo();
        srand(tempo);
    }

    escolhida = rand() % (QTD_PALAVRAS);

    palavra->escolhida = escolhida;
}

/**
 * @brief Imprime a palavra coletada do palavras.txt.
 *
 * @param palavra
 */
void ImprimePalavra(tPalavra *palavra)
{
    printf("\n\n%s\n\n", palavra->palavraColetada);
}

/**
 * @brief Libera memória de uma struct tPalavra* que é passada por parametro.
 *
 * @param palavra
 */
void LiberaPalavra(tPalavra *palavra)
{
    int i;

    free(palavra->palavraColetada);
    palavra->palavraColetada = NULL;

    free(palavra->palavraCopia);
    palavra->palavraCopia = NULL;

    free(palavra->palavraAtual);
    palavra->palavraAtual = NULL;

    free(palavra->palavraAtualCopia);
    palavra->palavraAtualCopia = NULL;

    for (i = 0; i < 6; i++)
    {
        free(palavra->palavraClassificada[i]);
        palavra->palavraClassificada[i] = NULL;
    }

    free(palavra->palavraClassificada);
    palavra->palavraClassificada = NULL;

    free(palavra);
    palavra = NULL;
}

/**
 * @brief Inicializa a palavraAtual com '\0'.
 *
 * @param palavra
 */
void InicializaPalavraAtual(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        palavra->palavraAtual[i] = '\0';
    }
}

/**
 * @brief Verifica se a palavra inserida pelo jogador existe nas palavras.txt e se tem tamanho 5 (nem maior e nem menor).
 *
 * @param palavra
 */
void LehPalavraEscolhidaPeloJogador(tPalavra *palavra)
{
    int i = 0;
    char string[6], stringVerifica[10000];

    while (1)
    {
        scanf("%s", stringVerifica);

        if (strlen(stringVerifica) > 6 || stringVerifica[5] != '\0')
        {
            printf("Palavra invalida, tente outra de tamanho cinco: ");
        }

        else
        {
            strcpy(string, stringVerifica);
            break;
        }
    }

    strcpy(palavra->palavraAtual, string);
}

/**
 * @brief Classifica a palavra de acordo com as respectivas regras do trabalho.
 *
 * @param palavra
 */
void ClassificaPalavra(tPalavra *palavra)
{
    int i = 0, j = 0, cont = 0, aux = 6;

    char caracter;

    CopiaPalavra(palavra);

    aux = aux - palavra->tentativa;

    palavra->palavraClassificada[aux][cont] = '|';

    for (i = 0; i < 5; i++)
    {
        if (NaoTemEssaLetraNaPalavra(palavra, i) == 1)
        {
            cont++;
            palavra->palavraClassificada[aux][cont] = '!';
            cont++;
            palavra->palavraClassificada[aux][cont] = palavra->palavraAtualCopia[i];
            cont++;
            palavra->palavraClassificada[aux][cont] = ' ';
            cont++;
            palavra->palavraClassificada[aux][cont] = '|';

            palavra->palavraAtualCopia[i] = '0';
        }

        else if (palavra->palavraAtualCopia[i] == palavra->palavraCopia[i])
        {
            cont++;
            palavra->palavraClassificada[aux][cont] = ' ';
            cont++;
            palavra->palavraClassificada[aux][cont] = palavra->palavraAtualCopia[i];
            cont++;
            palavra->palavraClassificada[aux][cont] = ' ';
            cont++;
            palavra->palavraClassificada[aux][cont] = '|';

            palavra->palavraAtualCopia[i] = '0';
            palavra->palavraCopia[i] = '0';
        }

        else
        {
            for (j = 0; j < 5; j++)
            {
                if (palavra->palavraAtualCopia[i] == palavra->palavraCopia[j])
                {
                    cont++;
                    palavra->palavraClassificada[aux][cont] = '(';
                    cont++;
                    palavra->palavraClassificada[aux][cont] = palavra->palavraAtualCopia[i];
                    cont++;
                    palavra->palavraClassificada[aux][cont] = ')';
                    cont++;
                    palavra->palavraClassificada[aux][cont] = '|';

                    palavra->palavraCopia[j] = '0';

                    break;
                }
            }
        }
    }

    palavra->palavraClassificada[aux][21] = '\0';
}

/**
 * @brief Pega as tentativas e armazena em um inteiro dentro da struct tPalavra *palavra.
 *
 * @param palavra
 * @param tentativas
 */
void PassaTentativas(tPalavra *palavra, int tentativas)
{
    palavra->tentativa = tentativas;
}

/**
 * @brief Atualiza as palavras para caixa alta, para padronizar elas.
 *
 * @param palavra
 */
void PadronizaPalavra(tPalavra *palavra)
{
    int i = 0;
    char caracter;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraColetada[i] >= 'a' && palavra->palavraColetada[i] <= 'z')
        {
            caracter = palavra->palavraColetada[i];
            caracter -= 32;
            palavra->palavraColetada[i] = caracter;
        }
    }

    i = 0;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraAtual[i] >= 'a' && palavra->palavraAtual[i] <= 'z')
        {
            caracter = palavra->palavraAtual[i];
            caracter -= 32;
            palavra->palavraAtual[i] = caracter;
        }
    }
}

/**
 * @brief Confere se a letra existe na palavra.
 * 
 * @param palavra 
 * @param i 
 * @return int 
 */
int NaoTemEssaLetraNaPalavra(tPalavra *palavra, int i)
{
    int j = 0, cont = 0;

    for (j = 0; j < 5; j++)
    {
        if (palavra->palavraCopia[j] == palavra->palavraAtual[i])
        {
            cont++;
        }
    }

    if (cont >= 1)
    {
        return 0;
    }

    return 1;
}

/**
 * @brief Imprime a palavra classificada.
 * 
 * @param palavra 
 */
void ImprimePalavraClassificada(tPalavra *palavra)
{
    int i;

    for (i = 0; i < 6; i++)
    {
        printf("|                   ");

        printf("%s", palavra->palavraClassificada[i]);

        printf("                   |\n");
    }
}

/**
 * @brief Inicializa palavra classificada.
 * 
 * @param palavra 
 */
void InicializaPalavraClassificada(tPalavra *palavra)
{
    int i;

    for (i = 0; i < 6; i++)
    {
        palavra->palavraClassificada[i][0] = '|';
        palavra->palavraClassificada[i][1] = ' ';
        palavra->palavraClassificada[i][2] = ' ';
        palavra->palavraClassificada[i][3] = ' ';
        palavra->palavraClassificada[i][4] = '|';
        palavra->palavraClassificada[i][5] = ' ';
        palavra->palavraClassificada[i][6] = ' ';
        palavra->palavraClassificada[i][7] = ' ';
        palavra->palavraClassificada[i][8] = '|';
        palavra->palavraClassificada[i][9] = ' ';
        palavra->palavraClassificada[i][10] = ' ';
        palavra->palavraClassificada[i][11] = ' ';
        palavra->palavraClassificada[i][12] = '|';
        palavra->palavraClassificada[i][13] = ' ';
        palavra->palavraClassificada[i][14] = ' ';
        palavra->palavraClassificada[i][15] = ' ';
        palavra->palavraClassificada[i][16] = '|';
        palavra->palavraClassificada[i][17] = ' ';
        palavra->palavraClassificada[i][18] = ' ';
        palavra->palavraClassificada[i][19] = ' ';
        palavra->palavraClassificada[i][20] = '|';
        palavra->palavraClassificada[i][21] = '\0';
    }
}

/**
 * @brief Confere se aspalavras são iguais ou tem alguma diferença.
 * 
 * @param palavra 
 * @return int 
 */
int AcertouPalavra(tPalavra *palavra)
{
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraAtual[i] != palavra->palavraColetada[i])
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief Pega uma letra especifica.
 * 
 * @param palavra 
 * @param i 
 * @return char 
 */
char ColetaLetraPalavra(tPalavra *palavra, int i)
{
    char caracter;

    caracter = palavra->palavraAtual[i];

    if (caracter >= 'a' && caracter <= 'z')
    {
        caracter -= 32;
    }

    return caracter;
}

/**
 * @brief Copia a palavra e padroniza ela em maiusculo.
 * 
 * @param palavra 
 */
void CopiaPalavra(tPalavra *palavra)
{
    int i;
    char caracter;
    for (i = 0; i < 6; i++)
    {
        palavra->palavraCopia[i] = palavra->palavraColetada[i];
        palavra->palavraAtualCopia[i] = palavra->palavraAtual[i];

        caracter = palavra->palavraCopia[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
            palavra->palavraCopia[i] = caracter;
        }
    }
}

/**
 * @brief Confere se as letras não são iguais.
 * 
 * @param palavra 
 * @param i 
 * @return int 
 */
int NaoSaoLetrasIguais(tPalavra *palavra, int i)
{
    if (palavra->palavraAtual[i] == palavra->palavraColetada[i])
    {
        return 0;
    }

    return 1;
}

/**
 * @brief Coleta valor da palavra escolhida.
 * 
 * @param palavra 
 * @return int 
 */
int ColetaPalavraEscolhida(tPalavra *palavra)
{
    int result;

    result = palavra->escolhida;

    return result;
}

/**
 * @brief Copia uma string.
 * 
 * @param palavra 
 * @param string 
 */
void CopiaStringParaPalavra(tPalavra *palavra, char string[6])
{
    int i;

    for (i = 0; i < 6; i++)
    {
        palavra->palavraColetada[i] = string[i];
    }
}

/**
 * @brief Coleta um char uma palavra.
 * 
 * @param palavra 
 * @param j 
 * @return char 
 */
char CharPalavraAtual(tPalavra *palavra, int j)
{
    char caracter;

    caracter = palavra->palavraAtual[j];

    return caracter;
}

/**
 * @brief Confere se a palavra já foi sorteada.
 * 
 * @param palavra 
 * @return int 
 */
int NaoFoiSorteadoEssaPalavra(tPalavra *palavra)
{
    int i, cont = 0;
    char caracter;
    char palavraLida[6];

    FILE *registrador;

    registrador = fopen("palavrasUsadas.txt", "a+");

    while (1)
    {
        if (feof(registrador))
        {
            break;
        }

        for (i = 0; i < 5; i++)
        {
            fscanf(registrador, "%c", &caracter);
            palavraLida[i] = caracter;
        }

        palavraLida[5] = '\0';
        // Leitura do espaço que separa as palavras
        fscanf(registrador, "%c", &caracter);
        // fread(palavraLida->palavraColetada, sizeof(char) * 6, 1, registrador);

        if (strcmp(palavraLida, palavra->palavraColetada) == 0)
        {
            fclose(registrador);
            return 0;
        }

        cont++;
    }

    fclose(registrador);

    return 1;
}

/**
 * @brief Registra a palavra do jogo, paar ela não se repetir.
 * 
 * @param palavra 
 */
void RegistraPalavraNoArquivo(tPalavra *palavra)
{
    int i;
    char caracter;
    FILE *registrador;

    registrador = fopen("palavrasUsadas.txt", "a+");

    // Concerta a letra pra gravar igual a do arquivo "palavras.txt".
    for (i = 0; i < 6; i++)
    {
        if (palavra->palavraColetada[i] >= 'A' && palavra->palavraColetada[i] <= 'Z')
        {
            caracter = palavra->palavraColetada[i];
            caracter += 32;
            palavra->palavraColetada[i] = caracter;
        }
    }

    fprintf(registrador, "%s ", palavra->palavraColetada);
    // fwrite(palavra->palavraColetada, sizeof(char) * 6, 1, registrador);

    fclose(registrador);
}