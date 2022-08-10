#ifndef UFENIXTAIL_H
#define UFENIXTAIL_H

#include "prototipos.h"
#include <error.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void LiberaJanela(char **janela_deslizante, int n);

void ufenix_tail(FILE *fp, int n);

int argumento_inteiro(const char *str);

int mainUfenix_tail(int argc, char *argv[]);

#endif
