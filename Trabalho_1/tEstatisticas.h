#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tEstatisticas tEstatisticas;

tEstatisticas *InicializaEstatisticas();

void RegistraEstatisticas(tEstatisticas *estatisticas);

#endif