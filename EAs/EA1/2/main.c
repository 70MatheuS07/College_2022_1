#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Estudante
{
    int matricula;
    char nome[21];
    int dia;
    int mes;
    int ano;
    float coeficiente;
    int quantidade;

} tEstudante;

void InicializaEstudante(tEstudante estudante[10000]);

int RegistraEstudante(tEstudante estudante[10000], int quantidade);

int VerificaData(char data[11]);

void ImprimeEstudantes(tEstudante estudante[10000], int quantidade);

int main()
{
    int quantidade = 0;
    int comando = 0;
    char lixo = 0;

    tEstudante estudante[10000];

    InicializaEstudante(estudante);

    while (1)
    {

        printf("Opções:\n");
        printf("1 - Registra aluno.\n");
        printf("2 - Imprime alunos.\n");
        printf("0 - Sair do programa.\n\n");

        scanf("%d%c", &comando, &lixo);

        system("clear");

        if (comando == 0)
        {
            printf("Você saiu do programa.\n");
            break;
        }

        else if (comando == 1)
        {
            printf("Passe todas as informações do aluno\n");
            printf("cada informação por linha:\n");
            printf("matrícula, nome, data de nascimento e coeficiente\n");

            quantidade += RegistraEstudante(estudante, quantidade);
        }

        else if (comando == 2)
        {
            ImprimeEstudantes(estudante, quantidade);
        }
    }
    return 0;
}

void InicializaEstudante(tEstudante estudante[10000])
{
    int i = 0, j = 0;

    for (i = 0; i < 10000; i++)
    {
        estudante[i].matricula = 0;

        for (j = 0; j < 21; j++)
        {
            estudante[i].nome[j] = '\0';
        }

        estudante[i].dia = 0;
        estudante[i].mes = 0;
        estudante[i].ano = 0;

        estudante[i].coeficiente = 0;
    }
}

int RegistraEstudante(tEstudante estudante[10000], int quantidade)
{
    int matricula;
    int i = 0, j = 0;
    char caracter;
    char data[11];
    char nome[21];
    char *ponteiro;
    char lixo;

    char dia[3];
    char mes[3];
    char ano[5];

    scanf("%d%c", &matricula, &lixo);

    scanf("%s%c", nome, &lixo);

    scanf("%s%c", data, &lixo);

    if (VerificaData(data) == 1)
    {
        estudante[quantidade].matricula = matricula;

        ponteiro = strtok(data, "/");

        strcpy(dia, ponteiro);

        ponteiro = strtok(NULL, "/");

        strcpy(mes, ponteiro);

        ponteiro = strtok(NULL, "/");

        strcpy(ano, ponteiro);

        estudante[quantidade].dia = (dia[0] - 48) * 10 + (dia[1] - 48);
        estudante[quantidade].mes = (mes[0] - 48) * 10 + (mes[1] - 48);
        estudante[quantidade].ano = (ano[0] - 48) * 1000 + (ano[1] - 48) * 100 + (ano[2] - 48) * 10 + (ano[3] - 48);

        scanf("%f%c", &estudante[quantidade].coeficiente, &lixo);

        strcpy(estudante[quantidade].nome, nome);

        return 1;
    }

    return 0;
}

int VerificaData(char data[11])
{
    if (data[2] == '/' && data[5] == '/')
    {
        return 1;
    }

    return 0;
}

void ImprimeEstudantes(tEstudante estudante[10000], int quantidade)
{
    int i = 0, j = 0;

    for (i = 0; i < quantidade; i++)
    {

        printf("%d\n", estudante[i].matricula);

        printf("%s\n", estudante[i].nome);

        printf("%d/", estudante[i].dia);
        printf("%d/", estudante[i].mes);
        printf("%d\n", estudante[i].ano);

        printf("%.2f\n", estudante[i].coeficiente);

        i++;
    }
}
