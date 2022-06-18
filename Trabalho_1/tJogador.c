#include "tJogador.h"

struct tJogador
{
    char *nome;
    int qtdJogos;
    float porcentagemVitorias;
    int sequenciaVitorias;
    int maiorSequenciaVitorias;
    int ganhouUmaTentativa;
    int ganhouDuasTentativas;
    int ganhouTresTentativas;
    int ganhouQuatroTentativas;
    int ganhouCincoTentativas;
    int ganhouSeisTentativas;
    int qtdDerrotas;
};

tJogador *CriaJogador()
{
    tJogador *jogador;

    jogador = malloc(sizeof(tJogador));

    jogador->nome = malloc(sizeof(char) * 21);

    return jogador;
}

void LehJogador_1(tJogador *jogador_1)
{
    int i = 0, cont = 0;
    char caracter;
    char nome[21], nomeVerifica[10000];

    printf("Informe o nome do jogador\n\n");

    printf("Nome: ");

    while (1)
    {
        scanf("%s", nomeVerifica);

        if (strlen(nomeVerifica) > 21)
        {
            printf("Nome invalido, tente outro menor: ");
        }

        else
        {
            strcpy(nome, nomeVerifica);
            break;
        }
    }

    printf("%s", nome);

    strcpy(jogador_1->nome, nome);

    jogador_1->qtdJogos = 0;
    jogador_1->porcentagemVitorias = 0;
    jogador_1->sequenciaVitorias = 0;
    jogador_1->maiorSequenciaVitorias = 0;
    jogador_1->ganhouUmaTentativa = 0;
    jogador_1->ganhouDuasTentativas = 0;
    jogador_1->ganhouTresTentativas = 0;
    jogador_1->ganhouQuatroTentativas = 0;
    jogador_1->ganhouCincoTentativas = 0;
    jogador_1->ganhouSeisTentativas = 0;
    jogador_1->qtdDerrotas = 0;
}

void LehJogador_2(tJogador *jogador_1, tJogador *jogador_2)
{
    int i = 0, cont = 0;
    char caracter;
    char nome[21], nomeVerifica[10000];

    for (i = 0; i < 21; i++)
    {
        nome[i] = '\0';
    }

    for (i = 0; i < 10000; i++)
    {
        nomeVerifica[i] = '\0';
    }

    printf("Informe o nome do jogador 2\n\n");

    printf("Nome: ");

    while (1)
    {
        scanf("%s", nomeVerifica);

        if (strlen(nomeVerifica) > 21)
        {
            printf("Nome invalido, tente outro menor: ");
        }

        else if (NomesIguais(jogador_1, nomeVerifica) == 0)
        {
            printf("Nomes iguais, escolha outro nickname: ");
        }

        else
        {
            strcpy(nome, nomeVerifica);
            break;
        }
    }

    printf("%s", nome);

    strcpy(jogador_2->nome, nome);

    jogador_2->qtdJogos = 0;
    jogador_2->porcentagemVitorias = 0;
    jogador_2->sequenciaVitorias = 0;
    jogador_2->maiorSequenciaVitorias = 0;
    jogador_2->ganhouUmaTentativa = 0;
    jogador_2->ganhouDuasTentativas = 0;
    jogador_2->ganhouTresTentativas = 0;
    jogador_2->ganhouQuatroTentativas = 0;
    jogador_2->ganhouCincoTentativas = 0;
    jogador_2->ganhouSeisTentativas = 0;
    jogador_2->qtdDerrotas = 0;
}

int NomesIguais(tJogador *jogador_1, char nomeVerifica[10000])
{
    if (strcmp(jogador_1->nome, nomeVerifica) == 0)
    {
        return 0;
    }

    return 1;
}

int EscolhaDeModo(tJogador *jogador)
{
    int num = 0;

    printf("Jogador %s escolha o modo de jogo:\n\n", jogador->nome);

    printf("1- Termo\n");
    printf("2- 2 Players\n");
    printf("8- Ranking\n");
    printf("9- Estatisticas\n");
    printf("0- Sair do Jogo\n\n");

    scanf("%d", &num);

    printf("\n");

    if (num != 1 && num != 2 && num != 8 && num != 9 && num != 0)
    {
        printf("Modo de jogo invalido, tente outro dentro das opcoes: ");

        scanf("%d", &num);
    }

    return num;
}

void LiberaJogador(tJogador *jogador)
{
    free(jogador->nome);
    jogador->nome = NULL;

    free(jogador);
    jogador = NULL;
}

void ImprimeNomeJogadorCabecalho(tJogador *jogador)
{
    printf(" Jogador %s digite uma palavra a sua escolha: ", jogador->nome);
}

void ImprimeAmbosJogadores(tJogador *jogador_1, tJogador *jogador_2)
{
    printf("|");

    ImprimeEspacosJogador1(jogador_1);

    printf("%s x %s", jogador_1->nome, jogador_2->nome);

    ImprimeEspacosJogador2(jogador_2);

    printf("|\n");
}

void ImprimeEspacosJogador1(tJogador *jogador_1)
{
    int num = 0, i = 0;

    num = strlen(jogador_1->nome);

    for (i = 0; i < 28 - num; i++)
    {
        printf(" ");
    }
}

void ImprimeEspacosJogador2(tJogador *jogador_2)
{
    int num = 0, i = 0;

    num = strlen(jogador_2->nome);

    for (i = 0; i < 28 - num; i++)
    {
        printf(" ");
    }
}

void ImprimeNomeJogador(tJogador *jogador)
{
    printf("%s", jogador->nome);
}

void RegistraQtdJogos(tJogador *jogador)
{
    int num = 0;

    num = jogador->qtdJogos;

    num += 1;

    jogador->qtdJogos = num;
}

void RegistraGanhouUmaTentativa(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouUmaTentativa;

    num += 1;

    jogador->ganhouUmaTentativa = num;
}

void RegistraGanhouDuasTentativas(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouDuasTentativas;

    num += 1;

    jogador->ganhouDuasTentativas = num;
}

void RegistraGanhouTresTentativas(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouTresTentativas;

    num += 1;

    jogador->ganhouTresTentativas = num;
}

void RegistraGanhouQuatroTentativas(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouQuatroTentativas;

    num += 1;

    jogador->ganhouQuatroTentativas = num;
}

void RegistraGanhouCincoTentativas(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouCincoTentativas;

    num += 1;

    jogador->ganhouCincoTentativas = num;
}

void RegistraGanhouSeisTentativas(tJogador *jogador)
{
    int num = 0;

    num = jogador->ganhouSeisTentativas;

    num += 1;

    jogador->ganhouSeisTentativas = num;
}

void RegistraQtdDerrotas(tJogador *jogador)
{
    int num = 0;

    num = jogador->qtdDerrotas;

    num += 1;

    jogador->qtdDerrotas = num;
}