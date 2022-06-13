#ifndef USUARIO_H
#define USUARIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tConta.h"

typedef struct tUsuario tUsuario;

tUsuario *CriaUsuario();

void ImprimeUsuario(tUsuario *usuario);

void LiberaUsuario(tUsuario *usuario);

#endif