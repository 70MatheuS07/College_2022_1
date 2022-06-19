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

// Problema com o arquivo binario!
void EscreveLehEstatistica(tJogador *jogador)
{
    int cont = 0, i = 0;
    tJogador *lido;
    lido = CriaJogador();

    FILE *estatistica = NULL;

    estatistica = fopen("jogadores.bin", "ab+");

    while (!feof(estatistica))
    {
        fread(lido, sizeof(tJogador), 1, estatistica);

        if (ConfereNomeJogadorEstatistica(jogador, lido) == 0)
        {
            ModificaJogadorEstatistica(jogador, lido);
            cont++;
            break;
        }

        i++;
    }

    if (cont == 0)
    {
        EscreveJogadorEstatistica(jogador, estatistica);
        fclose(estatistica);
    }

    else
    {
        fclose(estatistica);

        estatistica = fopen("jogadores.bin", "wb");

        if (fseek(estatistica, i * sizeof(tJogador), SEEK_SET) == 0)
        {
            fwrite(lido, sizeof(tJogador), 1, estatistica);
        }

        fclose(estatistica);
    }

    LiberaJogador(lido);
}

int ConfereNomeJogadorEstatistica(tJogador *jogador, tJogador *lido)
{
    if (strcmp(jogador->nome, lido->nome) == 0)
    {
        return 0;
    }

    return 1;
}

void EscreveJogadorEstatistica(tJogador *jogador, FILE *estatistica)
{
    float porcentagemVitorias = 0;
    int sequenciaVitorias = 0;
    int maiorSequenciaVitorias = 0;

    if (jogador->qtdDerrotas == 0)
    {
        sequenciaVitorias++;
        maiorSequenciaVitorias = sequenciaVitorias;
        porcentagemVitorias = 100;

        jogador->sequenciaVitorias = sequenciaVitorias;
        jogador->maiorSequenciaVitorias = maiorSequenciaVitorias;
        jogador->porcentagemVitorias = porcentagemVitorias;
    }

    fwrite(jogador, sizeof(tJogador), 1, estatistica);
}

void ModificaJogadorEstatistica(tJogador *jogador, tJogador *lido)
{
    int qtdJogos = 0;
    float porcentagemVitorias = 0;
    int sequenciaVitorias = 0;
    int maiorSequenciaVitorias = 0;
    int ganhouUmaTentativa = 0;
    int ganhouDuasTentativas = 0;
    int ganhouTresTentativas = 0;
    int ganhouQuatroTentativas = 0;
    int ganhouCincoTentativas = 0;
    int ganhouSeisTentativas = 0;
    int qtdDerrotas = 0;

    float vitorias = 0;
    float resultado = 0;

    qtdJogos = lido->qtdJogos;
    porcentagemVitorias = lido->porcentagemVitorias;
    sequenciaVitorias = lido->sequenciaVitorias;
    maiorSequenciaVitorias = lido->maiorSequenciaVitorias;
    ganhouUmaTentativa = lido->ganhouUmaTentativa;
    ganhouDuasTentativas = lido->ganhouDuasTentativas;
    ganhouTresTentativas = lido->ganhouTresTentativas;
    ganhouQuatroTentativas = lido->ganhouQuatroTentativas;
    ganhouCincoTentativas = lido->ganhouCincoTentativas;
    ganhouSeisTentativas = lido->ganhouSeisTentativas;
    qtdDerrotas = lido->qtdDerrotas;

    qtdJogos++;

    if (jogador->qtdDerrotas == 0)
    {
        sequenciaVitorias++;
    }

    else
    {
        sequenciaVitorias = 0;
    }

    if (sequenciaVitorias > maiorSequenciaVitorias)
    {
        maiorSequenciaVitorias = sequenciaVitorias;
    }

    ganhouUmaTentativa += jogador->ganhouUmaTentativa;
    ganhouDuasTentativas += jogador->ganhouDuasTentativas;
    ganhouTresTentativas += jogador->ganhouTresTentativas;
    ganhouQuatroTentativas += jogador->ganhouQuatroTentativas;
    ganhouCincoTentativas += jogador->ganhouCincoTentativas;
    ganhouSeisTentativas += jogador->ganhouSeisTentativas;
    qtdDerrotas += jogador->qtdDerrotas;

    vitorias = (ganhouUmaTentativa + ganhouDuasTentativas + ganhouTresTentativas + ganhouQuatroTentativas + ganhouCincoTentativas + ganhouSeisTentativas);

    porcentagemVitorias = (float)((vitorias / qtdJogos) * 100);

    lido->qtdJogos = qtdJogos;
    lido->porcentagemVitorias = porcentagemVitorias;
    lido->sequenciaVitorias = sequenciaVitorias;
    lido->maiorSequenciaVitorias = maiorSequenciaVitorias;
    lido->ganhouUmaTentativa = ganhouUmaTentativa;
    lido->ganhouDuasTentativas = ganhouDuasTentativas;
    lido->ganhouTresTentativas = ganhouTresTentativas;
    lido->ganhouQuatroTentativas = ganhouQuatroTentativas;
    lido->ganhouCincoTentativas = ganhouCincoTentativas;
    lido->ganhouSeisTentativas = ganhouSeisTentativas;
    lido->qtdDerrotas = qtdDerrotas;
}

void ImprimeEstatisticaJogador(tJogador *jogador)
{
    tJogador *leitura;
    leitura = CriaJogador();

    FILE *estatistica;

    estatistica = fopen("jogadores.bin", "rb");

    while (!feof(estatistica))
    {
        fread(leitura, sizeof(tJogador), 1, estatistica);

        if (ConfereNomeJogadorEstatistica(jogador, leitura) == 0)
        {
            printf("%s, ", leitura->nome);
            printf("%d, ", leitura->qtdJogos);
            printf("%.2f, ", leitura->porcentagemVitorias);
            printf("%d, ", leitura->sequenciaVitorias);
            printf("%d\n", leitura->maiorSequenciaVitorias);
            printf("%d\n", leitura->ganhouUmaTentativa);
            printf("%d\n", leitura->ganhouDuasTentativas);
            printf("%d\n", leitura->ganhouTresTentativas);
            printf("%d\n", leitura->ganhouQuatroTentativas);
            printf("%d\n", leitura->ganhouCincoTentativas);
            printf("%d\n", leitura->ganhouSeisTentativas);
            printf("%d\n\n", leitura->qtdDerrotas);

            break;
        }
    }

    fclose(estatistica);

    LiberaJogador(leitura);
}

void SalvaNome(tJogador *jogador, char nomeSalvo[21], int jogou)
{
    if (jogou == 0)
    {
        strcpy(nomeSalvo, jogador->nome);
    }

    else
    {
        strcpy(jogador->nome, nomeSalvo);
    }
}

void InicializaJogador(tJogador *jogador)
{
    int qtdJogos = 0;
    float porcentagemVitorias = 0;
    int sequenciaVitorias = 0;
    int maiorSequenciaVitorias = 0;
    int ganhouUmaTentativa = 0;
    int ganhouDuasTentativas = 0;
    int ganhouTresTentativas = 0;
    int ganhouQuatroTentativas = 0;
    int ganhouCincoTentativas = 0;
    int ganhouSeisTentativas = 0;
    int qtdDerrotas = 0;

    jogador->qtdJogos = qtdJogos;
    jogador->porcentagemVitorias = porcentagemVitorias;
    jogador->sequenciaVitorias = sequenciaVitorias;
    jogador->maiorSequenciaVitorias = maiorSequenciaVitorias;
    jogador->ganhouUmaTentativa = ganhouUmaTentativa;
    jogador->ganhouDuasTentativas = ganhouDuasTentativas;
    jogador->ganhouTresTentativas = ganhouTresTentativas;
    jogador->ganhouQuatroTentativas = ganhouQuatroTentativas;
    jogador->ganhouCincoTentativas = ganhouCincoTentativas;
    jogador->ganhouSeisTentativas = ganhouSeisTentativas;
    jogador->qtdDerrotas = qtdDerrotas;
}