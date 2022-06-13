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
    tUsuario *usuario;

    usuario = malloc(sizeof(usuario));

    scanf("%s %d", nome, &cpf);

    strcpy(usuario->nome, nome);

    usuario->cpf = cpf;

    return usuario;
}

void ImprimeUsuario(tUsuario *usuario)
{
    printf("Usuario: %s\n", usuario->nome);
}