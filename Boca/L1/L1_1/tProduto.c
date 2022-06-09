#include "tProduto.h"

struct Produto
{
    int codigo;
    float preco;
    int quantidade;
};

void LehProdutos(tProduto *produtos[], int num)
{
    int codigo = 0;
    float preco = 0;
    int quantidade = 0;
    char lixo;
    int i = 0;

    for (i = 0; i < num; i++)
    {
        produtos[i] = malloc(sizeof(tProduto));

        if (i == num - 1)
        {
            scanf("%d;%f;%d", &codigo, &preco, &quantidade);
        }

        else
        {
            scanf("%d;%f;%d%c", &codigo, &preco, &quantidade, &lixo);
        }

        produtos[i]->codigo = codigo;
        produtos[i]->preco = preco;
        produtos[i]->quantidade = quantidade;
    }
}

void ImprimeProdutoSemQuantidade(tProduto *produtos[], int num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        if (produtos[i]->quantidade == 0)
        {
            printf("FALTA:COD %d, PRE %.2f, QTD %d\n", produtos[i]->codigo, produtos[i]->preco, produtos[i]->quantidade);
        }
    }
}

void ImprimeProdutoMaiorPreco(tProduto *produtos[], int num)
{
    float preco = 0;
    int i = 0;
    tProduto produtoMaior;

    for (i = 0; i < num; i++)
    {
        if (produtos[i]->preco > preco)
        {
            preco = produtos[i]->preco;
            produtoMaior.codigo = produtos[i]->codigo;
            produtoMaior.preco = produtos[i]->preco;
            produtoMaior.quantidade = produtos[i]->quantidade;
        }
    }

    printf("MAIOR:COD %d, PRE %.2f, QTD %d\n", produtoMaior.codigo, produtoMaior.preco, produtoMaior.quantidade);
}

void ImprimeProdutoMenorPreco(tProduto *produtos[], int num)
{
    float preco = 2000000;
    int i = 0;
    tProduto produtoMenor;

    for (i = 0; i < num; i++)
    {
        if (produtos[i]->preco < preco)
        {
            preco = produtos[i]->preco;
            produtoMenor.codigo = produtos[i]->codigo;
            produtoMenor.preco = produtos[i]->preco;
            produtoMenor.quantidade = produtos[i]->quantidade;
        }
    }

    printf("MENOR:COD %d, PRE %.2f, QTD %d\n", produtoMenor.codigo, produtoMenor.preco, produtoMenor.quantidade);
}