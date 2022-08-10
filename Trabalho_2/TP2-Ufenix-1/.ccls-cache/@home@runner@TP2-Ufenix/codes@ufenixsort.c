#include <error.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_fn_t)(const void *p, const void *q);

int cmp_pstr(const void *p, const void *q)
{
  
}

int cmp_pstr_tamanho(const void *p, const void *q)
{
  
}

int cmp_pstr_numeros(const void *p, const void *q)
{
  
}

void ufenix_sort(FILE *fp, cmp_fn_t cmp, bool uniq, bool reverse)
{
  
}

int main(int argc, char *argv[])
{
    cmp_fn_t cmp = cmp_pstr;
    bool uniq = false, reverse = false;

    int opt;
    while ((opt = getopt(argc, argv, "lnru")) != -1) {
        //Baseado no opt seta a função de comparação
        switch (opt) {
           
            case 'l': cmp = cmp_pstr_tamanho; break;
            case 'n': cmp = cmp_pstr_numeros; break;
            case 'r': reverse = true; break;
            case 'u': uniq = true; break;
            default: exit(1);
        }
    }

    FILE *fp = stdin;
    if (optind < argc) {
        fp = fopen(argv[optind], "r");
        if (fp == NULL) error(1, 0, "%s: Arquivo nao encontrado", argv[optind]);
    }
    ufenix_sort(fp, cmp, uniq, reverse);
    fclose(fp);
    return 0;
}
