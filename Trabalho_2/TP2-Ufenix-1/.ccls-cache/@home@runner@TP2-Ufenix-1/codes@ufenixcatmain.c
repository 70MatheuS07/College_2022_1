#include "ufenixcat.h"

int main(int argc, char **argv)
{
    FILE *fp;

    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) error(1, 0, "%s: Arquivo não encontrado", argv[1]);
    }

    ufenix_cat(fp);

    fclose(fp);
    return 0;
}