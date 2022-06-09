#ifndef BOLETO_H
#define BOLETO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Boleto tBoleto;

tBoleto *LehBoleto();

// void LehBoletoVetor(tBoleto *boletoVetor[], int n);

tBoleto *LehMaisCaro();

tBoleto *LehMaisBarato();

void MaisCaro(tBoleto *boleto, tBoleto *boletoMaisCaro);

void MaisBarato(tBoleto *boleto, tBoleto *boletoMaisBarato);

float ValorBoleto(tBoleto *boleto);

void ImprimeBoleto(tBoleto *boletoMaisCaro, tBoleto *boletoMaisBarato);

#endif