#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Boleto.h"

int main()
{
    int n = 0, i = 0;

    float somaDosBoletos = 0;

    tBoleto *boleto;
    tBoleto *boletoMaisCaro;
    tBoleto *boletoMaisBarato;

    scanf("%d", &n);

    tBoleto *boletoVetor[n];

    boletoMaisBarato = LehMaisBarato();

    boletoMaisCaro = LehMaisCaro();

    for (i = 0; i < n; i++)
    {
        // LehBoletoVetor(boletoVetor, n);
        
        boleto = LehBoleto();

        MaisCaro(boleto, boletoMaisCaro);

        MaisBarato(boleto, boletoMaisBarato);

        somaDosBoletos += ValorBoleto(boleto);

        free(boleto);
    }

    ImprimeBoleto(boletoMaisCaro, boletoMaisBarato);

    printf("Soma: %.2f", somaDosBoletos);

    free(boletoMaisCaro);
    free(boletoMaisBarato);

    return 0;
}