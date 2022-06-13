#define DESTE_TIPO_ double
#define FORMATO "%.2f"

#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"

int main()
{
    tPonto *p = CriarPonto(7.89, 9.76);

    ImprimirPonto(p);



    return 0;
}