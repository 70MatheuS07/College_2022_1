#include "tUsuario.h"

struct tUsuario
{
    char nome[21];
    int cpf;
};

tUsuario *CriaUsuario(FILE *arquivo)
{
    int cpf;
    char nome[21];
    tUsuario *usuarioRtn;

    usuarioRtn = malloc(sizeof(tUsuario));

    fscanf(arquivo, "%s %d", nome, &cpf);

    strcpy(usuarioRtn->nome, nome);

    usuarioRtn->cpf = cpf;

    return usuarioRtn;
}

void ImprimeNomeCPF(FILE *saida, tUsuario *usuario)
{
    fprintf(saida, "Nome: %s\n", usuario->nome);
    fprintf(saida, "CPF: %d\n\n", usuario->cpf);
}