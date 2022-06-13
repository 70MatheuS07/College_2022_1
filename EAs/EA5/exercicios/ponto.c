#define DESTE_TIPO_ double
#define FORMATO "%.2f"

#include "ponto.h"

struct tPonto
{
    DESTE_TIPO_ x;
    DESTE_TIPO_ y;
};

tPonto *CriarPonto(DESTE_TIPO_ x, DESTE_TIPO_ y)
{
    tPonto *p = malloc(sizeof(tPonto));

    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    p->x = x;
    p->y = y;
}

void LiberaPonto(tPonto *p, FILE *f)
{
    free(p);
    p = NULL;

    free(f);
    f = NULL;
}

void ImprimirPonto(tPonto *p)
{
    char formato[15] = "{";

    strcat(formato, FORMATO);
    strcat(formato, ", ");
    strcat(formato, FORMATO);
    strcat(formato, "}");

    printf(formato, p->x, p->y);
    printf("\n");
}

void SalvarPonto(tPonto *p, FILE *f)
{

}

tPonto *CarregarArquivo(FILE *f)
{
    
}