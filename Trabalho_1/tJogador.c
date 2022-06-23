#include "tJogador.h"

struct tJogador
{
    char nome[21];
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

struct tLeitura
{
    int quantidade;
    tJogador **jogadores;
};

tJogador *CriaJogador()
{
    int i;

    tJogador *jogador;

    jogador = malloc(sizeof(tJogador));

    for (i = 0; i < 21; i++)
    {
        jogador->nome[i] = '\0';
    }

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

    // Garante acesso só desses numeros.
    while (num != 1 && num != 2 && num != 8 && num != 9 && num != 0)
    {
        printf("Modo de jogo invalido, tente outro dentro das opcoes: ");

        scanf("%d", &num);
    }

    return num;
}

void LiberaJogador(tJogador *player)
{
    free(player);
    player = NULL;
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

void EscreveLehEstatistica(tJogador *jogador, tJogador *jogadorLidoCopia)
{
    int cont = 0, i = 0;

    tLeitura *leitura;

    leitura = malloc(sizeof(tLeitura));

    leitura->jogadores = malloc(sizeof(tJogador *) * 20);

    for (i = 0; i < 20; i++)
    {
        leitura->jogadores[i] = CriaJogador();
    }

    CriaArquivo();

    FILE *arquivo = fopen("jogadores.bin", "rb");

    fread(leitura, sizeof(tLeitura), 1, arquivo);

    for (i = 0; i < 20; i++)
    {
        ImprimeEstatisticaJogador(leitura->jogadores[i]);
    }

    for (i = 0; i < 20; i++)
    {
        if (ConfereNomeJogadorEstatistica(jogador, leitura->jogadores[i]) == 0)
        {
            ModificaJogadorEstatistica(jogador, leitura->jogadores[i]);
            ImprimeEstatisticaJogador(leitura->jogadores[i]);
            break;
        }

        else
        {
            if (SlotJogadorVazio(leitura->jogadores[i]) == 1)
            {
                EscreveJogadorEstatistica(jogador, leitura->jogadores[i]);
                ImprimeEstatisticaJogador(leitura->jogadores[i]);
                break;
            }
        }
    }
    fclose(arquivo);

    arquivo = fopen("jogadores.bin", "wb");

    fwrite(leitura, sizeof(tLeitura), 1, arquivo);

    fclose(arquivo);
}

int SlotJogadorVazio(tJogador *jogador)
{
    if (jogador->nome[0] == '\0')
    {
        return 1;
    }

    return 0;
}

void CriaArquivo()
{
    FILE *arquivo;

    arquivo = fopen("jogadores.bin", "ab");

    if (!arquivo)
    {
        printf("Nao foi possivel cria o arquivo\n");
    }

    fclose(arquivo);
}

void ClonaJogador(tJogador *lido, tJogador *jogadorLidoCopia)
{
    char nome[21];
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

    strcpy(nome, lido->nome);
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

    strcpy(jogadorLidoCopia->nome, nome);
    jogadorLidoCopia->qtdJogos = qtdJogos;
    jogadorLidoCopia->porcentagemVitorias = porcentagemVitorias;
    jogadorLidoCopia->sequenciaVitorias = sequenciaVitorias;
    jogadorLidoCopia->maiorSequenciaVitorias = maiorSequenciaVitorias;
    jogadorLidoCopia->ganhouUmaTentativa = ganhouUmaTentativa;
    jogadorLidoCopia->ganhouDuasTentativas = ganhouDuasTentativas;
    jogadorLidoCopia->ganhouTresTentativas = ganhouTresTentativas;
    jogadorLidoCopia->ganhouQuatroTentativas = ganhouQuatroTentativas;
    jogadorLidoCopia->ganhouCincoTentativas = ganhouCincoTentativas;
    jogadorLidoCopia->ganhouSeisTentativas = ganhouSeisTentativas;
    jogadorLidoCopia->qtdDerrotas = qtdDerrotas;
}

int ConfereNomeJogadorEstatistica(tJogador *jogador, tJogador *jogadores)
{
    if (strcmp(jogador->nome, jogadores->nome) == 0)
    {
        return 0;
    }

    return 1;
}

void EscreveJogadorEstatistica(tJogador *jogador, tJogador *leitura)
{
    float porcentagemVitorias = 0;
    int sequenciaVitorias = 0;
    int maiorSequenciaVitorias = 0;

    if (jogador->qtdDerrotas == 0)
    {
        sequenciaVitorias++;

        // Caso sequencia for > maiorSequencia.
        maiorSequenciaVitorias = sequenciaVitorias;
        porcentagemVitorias = 100;

        jogador->sequenciaVitorias = sequenciaVitorias;
        jogador->maiorSequenciaVitorias = maiorSequenciaVitorias;
        jogador->porcentagemVitorias = porcentagemVitorias;
    }

    strcpy(leitura->nome, jogador->nome);
    leitura->qtdJogos = jogador->qtdJogos;
    leitura->porcentagemVitorias = jogador->porcentagemVitorias;
    leitura->sequenciaVitorias = jogador->sequenciaVitorias;
    leitura->maiorSequenciaVitorias = jogador->maiorSequenciaVitorias;
    leitura->ganhouUmaTentativa = jogador->ganhouUmaTentativa;
    leitura->ganhouDuasTentativas = jogador->ganhouDuasTentativas;
    leitura->ganhouTresTentativas = jogador->ganhouTresTentativas;
    leitura->ganhouQuatroTentativas = jogador->ganhouQuatroTentativas;
    leitura->ganhouCincoTentativas = jogador->ganhouCincoTentativas;
    leitura->ganhouSeisTentativas = jogador->ganhouSeisTentativas;
    leitura->qtdDerrotas = jogador->qtdDerrotas;
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
    printf("%s, ", jogador->nome);
    printf("%d, ", jogador->qtdJogos);
    printf("%.2f, ", jogador->porcentagemVitorias);
    printf("%d, ", jogador->sequenciaVitorias);
    printf("%d\n", jogador->maiorSequenciaVitorias);
    printf("%d\n", jogador->ganhouUmaTentativa);
    printf("%d\n", jogador->ganhouDuasTentativas);
    printf("%d\n", jogador->ganhouTresTentativas);
    printf("%d\n", jogador->ganhouQuatroTentativas);
    printf("%d\n", jogador->ganhouCincoTentativas);
    printf("%d\n", jogador->ganhouSeisTentativas);
    printf("%d\n\n", jogador->qtdDerrotas);
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

void ImprimeRanking()
{
    int num = 0;

    tJogador *ranking = CriaJogador();

    FILE *arquivo = NULL;

    arquivo = fopen("jogadores.bin", "rb");

    while (1)
    {
        if (!feof(arquivo))
        {
            break;
        }

        fread(ranking, sizeof(tJogador), 1, arquivo);

        num++;
    }

    fclose(arquivo);

    tJogador **matriz = malloc(sizeof(tJogador *) * num);

    int i = 0;

    for (i = 0; i < num; i++)
    {
        matriz[i] = CriaJogador();
    }
}