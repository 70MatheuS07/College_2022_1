#include "tUsuario.h"

struct tUsuario
{
    char nome[21];
    int cpf;
};

tUsuario *CriaUsuario()
{
    int cpf;
    char nome[21];
    tUsuario *usuarioRtn;

    usuarioRtn = malloc(sizeof(tUsuario));

    scanf("%s %d", nome, &cpf);

    strcpy(usuarioRtn->nome, nome);

    usuarioRtn->cpf = cpf;

    return usuarioRtn;
}

void ImprimeNomeCPF(tUsuario *usuario)
{
    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %d\n\n", usuario->cpf);
}