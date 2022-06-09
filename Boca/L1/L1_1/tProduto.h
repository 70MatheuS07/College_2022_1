#ifndef TPRODUTO_H
#define TPRODUTO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Produto tProduto;

void LehProdutos(tProduto *produtos[], int num);

void ImprimeProdutoSemQuantidade(tProduto *produtos[], int num);

void ImprimeProdutoMaiorPreco(tProduto *produtos[], int num);

void ImprimeProdutoMenorPreco(tProduto *produtos[], int num);

#endif