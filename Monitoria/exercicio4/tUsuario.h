#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tConta.h"

typedef struct tUsuario tUsuario;

tUsuario *CriaUsuario(FILE *arquivo);

void ImprimeNomeCPF(FILE *saida, tUsuario *usuario);

#endif