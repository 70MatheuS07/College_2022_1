#ifndef UFENIXUNIQ_H
#define UFENIXUNIQ_H

#include "prototipos.h"
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TAM_INICIAL 100
#define QUANTIDADE_INICIAL 1

void LiberaTextoUniq(char **texto, int multiplicador);

void ufenix_uniq(FILE *fp);

int mainUfenix_uniq(int argc, char *argv[]);

#endif
