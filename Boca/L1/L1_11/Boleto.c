#include "Boleto.h"

struct Boleto
{
    int codigo;
    float valor;
};

tBoleto *LehBoleto()
{
    tBoleto *boleto;

    int codigo = 0;
    float valor = 0;

    boleto = malloc(sizeof(tBoleto));

    scanf("\n%d %f", &codigo, &valor);

    boleto->codigo = codigo;
    boleto->valor = valor;

    return boleto;
}

/*void LehBoletoVetor(tBoleto *boletoVetor[], int n)
{
    int codigo = 0;
    float valor = 0;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        boletoVetor[i] = malloc(sizeof(tBoleto));

        scanf("\n%d %f", &codigo, &valor);

        boletoVetor[i]->codigo = codigo;
        boletoVetor[i]->valor = valor;
    }


    for (i = 0; i < n; i++)
    {
        printf("%d %f\n", boletoVetor[i]->codigo, boletoVetor[i]->valor);
    }
}*/

tBoleto *LehMaisCaro()
{
    tBoleto *boletoMaisCaro;

    boletoMaisCaro = malloc(sizeof(tBoleto));

    boletoMaisCaro->codigo = 0;
    boletoMaisCaro->valor = -1000000;

    return boletoMaisCaro;
}

tBoleto *LehMaisBarato()
{
    tBoleto *boletoMaisBarato;

    boletoMaisBarato = malloc(sizeof(tBoleto));

    boletoMaisBarato->codigo = 0;
    boletoMaisBarato->valor = 1000000;

    return boletoMaisBarato;
}

void MaisCaro(tBoleto *boleto, tBoleto *boletoMaisCaro)
{
    if (boleto->valor > boletoMaisCaro->valor)
    {
        boletoMaisCaro->codigo = boleto->codigo;
        boletoMaisCaro->valor = boleto->valor;
    }
}

void MaisBarato(tBoleto *boleto, tBoleto *boletoMaisBarato)
{
    if (boleto->valor < boletoMaisBarato->valor)
    {
        boletoMaisBarato->codigo = boleto->codigo;
        boletoMaisBarato->valor = boleto->valor;
    }
}

float ValorBoleto(tBoleto *boleto)
{
    float result;

    result = boleto->valor;

    return result;
}

void ImprimeBoleto(tBoleto *boletoMaisCaro, tBoleto *boletoMaisBarato)
{
    printf("Mais caro: Cod: %d valor: %.2f\n", boletoMaisCaro->codigo, boletoMaisCaro->valor);

    printf("Mais barato: Cod: %d valor: %.2f\n", boletoMaisBarato->codigo, boletoMaisBarato->valor);
}