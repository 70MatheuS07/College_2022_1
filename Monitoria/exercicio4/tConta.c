#include "tConta.h"

struct tConta
{
    tUsuario *usuario;
    int conta;
    float dinheiro;
    float *extrato;
    int movimentacoes;
};

tConta **CriaContas()
{
    tConta **conta = NULL;

    conta = malloc(sizeof(tConta *) * 10);

    for (int i = 0; i < 10; i++)
    {
        conta[i] = malloc(sizeof(tConta));
    }

    return conta;
}

void CadastraContas(FILE *arquivo, tConta **conta, int num)
{
    if (num > 10)
    {
        conta = realloc(conta, sizeof(tConta *) * num);
    }

    PegaDadosConta(arquivo, conta, num);
}

void PegaDadosConta(FILE *arquivo, tConta **conta, int num)
{
    int numConta = 0;

    conta[num - 1]->usuario = CriaUsuario(arquivo);

    fscanf(arquivo, " %d\n", &numConta);

    conta[num - 1]->conta = numConta;

    conta[num - 1]->dinheiro = 0;
}

void RegistraSaque(FILE *arquivo, tConta **conta, int num)
{
    int usuario = 0;
    float saque = 0;

    fscanf(arquivo, "%d ", &usuario);
    fscanf(arquivo, "%f\n", &saque);

    for (int i = 0; i < num; i++)
    {
        if (conta[i]->conta == usuario)
        {
            if (conta[i]->dinheiro < saque)
            {
                printf("Saldo insuficiente!\n\n");
            }

            else
            {
                conta[i]->dinheiro -= saque;

                // printf("Saque realizado no valor de %.2f\n\n", saque);
            }

            break;
        }
    }
}

void RegistraDeposito(FILE *arquivo, tConta **conta, int num)
{
    int usuario = 0;
    float deposito = 0;

    fscanf(arquivo, "%d ", &usuario);

    fscanf(arquivo, "%f\n", &deposito);

    for (int i = 0; i < num; i++)
    {
        if (conta[i]->conta == usuario)
        {
            conta[i]->dinheiro += deposito;

            // printf("Deposito realizado no valor de %.2f\n\n", deposito);

            break;
        }
    }
}

void RegistraTransferencia(FILE *arquivo, tConta **conta, int num)
{
    int origem = 0, destino = 0;
    float transferencia = 0;

    fscanf(arquivo, "%d ", &origem);
    fscanf(arquivo, "%d ", &destino);
    fscanf(arquivo, "%f\n", &transferencia);

    for (int i = 0; i < num; i++)
    {
        if (conta[i]->conta == origem)
        {
            for (int j = 0; j < num; j++)
            {
                if (conta[j]->conta == destino)
                {
                    if (conta[i]->dinheiro < transferencia)
                    {
                        printf("Saldo insuficiente!\n\n");
                    }

                    else
                    {
                        conta[i]->dinheiro -= transferencia;

                        conta[j]->dinheiro += transferencia;

                        // printf("Transferencia realizado no valor de %.2f\n\n", transferencia);
                    }

                    break;
                }
            }
        }
    }
}

void ImprimeRelatorio(tConta **conta, int num)
{
    FILE *saida = NULL;

    saida = fopen("relatorio.txt", "a+");

    fprintf(saida, "===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < num; i++)
    {
        fprintf(saida, "Conta: %d\n", conta[i]->conta);
        fprintf(saida, "Saldo: R$ %.2f\n", conta[i]->dinheiro);

        ImprimeNomeCPF(saida, conta[i]->usuario);
    }
}

void LiberaContas(tConta **conta, int num)
{
    if (num > 10)
    {
        for (int i = 0; i < num; i++)
        {
            free(conta[i]->usuario);
            free(conta[i]);
        }
    }

    else
    {

        for (int i = 0; i < 10; i++)
        {
            free(conta[i]->usuario);
            free(conta[i]);
        }
    }

    free(conta);
    conta = NULL;
}

void RegistraMovimentacoes(tConta **conta, float valor, int num, int comando)
{
    conta[num - 1]->movimentacoes += 1;

    if (conta[num - 1]->movimentacoes > 10)
    {
        conta[num - 1]->extrato = realloc(conta[num - 1]->extrato, sizeof(float) * num);
    }

    if (comando == 1)
    {
        valor *= -1;
        conta[num - 1]->extrato
    }
}