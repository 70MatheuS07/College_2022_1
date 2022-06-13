#define DESTE_TIPO_ double
#define FORMATO "%.2f"

#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"

int main()
{
    tPonto *p = CriarPonto(7.89, 9.76);

    ImprimirPonto(p);

    FILE *fp;
    SalvarPonto(p, fp);
    LiberaPonto(p);

    tPonto *p2 = CarregarArquivo(fp);

    ImprimirPonto(p2);
    LiberaPonto(p2);

    return 0;
}