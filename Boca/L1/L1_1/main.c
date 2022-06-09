#include <stdlib.h>
#include <stdio.h>
#include "tProduto.h"

int main()
{
    int num;
    char lixo;

    scanf("%d%c", &num, &lixo);

    tProduto *produtos[num];

    LehProdutos(produtos, num);

    ImprimeProdutoSemQuantidade(produtos, num);

    ImprimeProdutoMaiorPreco(produtos, num);

    ImprimeProdutoMenorPreco(produtos, num);

    return 0;
}