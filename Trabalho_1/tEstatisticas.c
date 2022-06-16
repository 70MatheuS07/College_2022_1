#include "tEstatisticas.h"

struct tEstatisticas
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

tEstatisticas *InicializaEstatisticas()
{
    int num = 0;
    tEstatisticas *estatisticas;

    estatisticas = malloc(sizeof(tEstatisticas));

    estatisticas->nome = malloc(sizeof(char) * 21);

    estatisticas->qtdJogos = num;
    estatisticas->porcentagemVitorias = num;
    estatisticas->sequenciaVitorias = num;
    estatisticas->maiorSequenciaVitorias = num;
    estatisticas->ganhouUmaTentativa = num;
    estatisticas->ganhouDuasTentativas = num;
    estatisticas->ganhouTresTentativas = num;
    estatisticas->ganhouQuatroTentativas = num;
    estatisticas->ganhouCincoTentativas = num;
    estatisticas->ganhouSeisTentativas = num;
    estatisticas->qtdDerrotas = num;

    return estatisticas;
}

void RegistraEstatisticas(tEstatisticas *estatisticas)
{
    printf("\n\nEntrou na estatistica\n\n");
}