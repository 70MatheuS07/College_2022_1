#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TAM_LINHA 32

char *ler_linha(FILE *fp);

void LiberaResult(char *result);

#endif
