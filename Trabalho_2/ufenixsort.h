#ifndef UFENIXSORT_H
#define UFENIXSORT_H

#include "prototipos.h"
#include <error.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_fn_t)(const void *p, const void *q);

void LiberaTextoSort(char **texto, int multiplicador);

int cmp_pstr(const void *p, const void *q);

int cmp_pstr_tamanho(const void *p, const void *q);

int cmp_pstr_numeros(const void *p, const void *q);

void Uniq_function(char **matriz, int qtd_linhas);

void ufenix_sort(FILE *fp, cmp_fn_t cmp, bool uniq, bool reverse);

int mainUfenix_sort(int argc, char *argv[]);

#endif
