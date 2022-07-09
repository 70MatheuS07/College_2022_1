#include "tConta.h"

#define TAM_INICIAL 10

struct tConta
{
    tUsuario *usuario;
    int conta;
    float dinheiro;
    float *extrato;
    int movimentacoes;
};

void LiberaContas(tConta **conta, int num)
{
    if (num > 10)
    {
        for (int i = 0; i < num; i++)
        {
            free(conta[i]->usuario);
            free(conta[i]->extrato);
            free(conta[i]);
        }
    }

    else
    {

        for (int i = 0; i < 10; i++)
        {
            free(conta[i]->usuario);
            free(conta[i]->extrato);
            free(conta[i]);
        }
    }

    free(conta);
    conta = NULL;
}

tConta **CriaContas()
{
    tConta **conta = NULL;

    conta = malloc(sizeof(tConta *) * TAM_INICIAL);

    for (int i = 0; i < 10; i++)
    {
        conta[i] = malloc(sizeof(tConta));
        conta[i]->extrato = malloc(sizeof(float) * TAM_INICIAL);
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

            RegistraMovimentacoesSaque(conta, num, i, saque);

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

            RegistraMovimentacoesDeposito(conta, num, i, deposito);

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

                        RegistraMovimentacoesTransferencia(conta, num, i, j, transferencia);
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

    saida = fopen("saida/relatorio.txt", "w");

    fprintf(saida, "===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < num; i++)
    {
        fprintf(saida, "Conta: %d\n", conta[i]->conta);
        fprintf(saida, "Saldo: R$ %.2f\n", conta[i]->dinheiro);

        ImprimeNomeCPF(saida, conta[i]->usuario);
    }

    fclose(saida);
}

void RegistraMovimentacoesSaque(tConta **conta, int num, int i, float valor)
{
    conta[i]->movimentacoes += 1;

    if (conta[i]->movimentacoes > 10)
    {
        conta[i]->extrato = realloc(conta[i]->extrato, sizeof(float) * num);
    }

    valor *= -1;
    conta[i]->extrato[conta[i]->movimentacoes - 1] = valor;
}

void RegistraMovimentacoesDeposito(tConta **conta, int num, int i, float valor)
{
    conta[i]->movimentacoes += 1;

    if (conta[i]->movimentacoes > 10)
    {
        conta[i]->extrato = realloc(conta[i]->extrato, sizeof(float) * num);
    }

    conta[i]->extrato[conta[i]->movimentacoes - 1] = valor;
}

void RegistraMovimentacoesTransferencia(tConta **conta, int num, int i, int j, float valor)
{
    conta[i]->movimentacoes += 1;
    conta[j]->movimentacoes += 1;

    if (conta[i]->movimentacoes > 10)
    {
        conta[i]->extrato = realloc(conta[i]->extrato, sizeof(float) * num);
    }

    if (conta[j]->movimentacoes > 10)
    {
        conta[j]->extrato = realloc(conta[j]->extrato, sizeof(float) * num);
    }

    conta[j]->extrato[conta[j]->movimentacoes - 1] = valor;

    valor *= -1;

    conta[i]->extrato[conta[i]->movimentacoes - 1] = valor;
}

void ImprimeExtrato(FILE *arquivo, tConta **conta, int num)
{
    int numConta, qtdImpressoes, numContaCopia = 0;
    char numeroConta[TAM_INICIAL * TAM_INICIAL], numeroContaCopia[TAM_INICIAL * TAM_INICIAL];
    int k = 0, resto = 0, j = 0, l = 0;
    int numeroMovimentacoes;
    char arquivoString[TAM_INICIAL * TAM_INICIAL] = "saida/";

    FILE *saida = NULL;

    fscanf(arquivo, "%d %d\n", &numConta, &qtdImpressoes);

    numContaCopia = numConta;

    while (1)
    {
        if (numConta > 9)
        {
            resto = numContaCopia % 10;
            numContaCopia /= 10;
            numeroContaCopia[k] = resto + '0';
            k++;
        }

        else
        {
            numeroContaCopia[k] = numContaCopia + '0';
            k++;
            numeroContaCopia[k] = '\0';
            break;
        }
    }

    while (1)
    {
        if (numeroContaCopia[k] != '\0')
        {
            numeroConta[j] = numeroContaCopia[k];
            j++;
        }

        if (k == 0)
        {
            numeroConta[j] = '\0';
            break;
        }

        k--;
    }

    strcat(numeroConta, ".txt");

    strcat(arquivoString, numeroConta);

    saida = fopen(arquivoString, "w");

    for (int i = 0; i < num; i++)
    {
        if (conta[i]->conta == numConta)
        {
            fprintf(saida, "===| Imprimindo Extrato |===\n");

            fprintf(saida, "Conta: %d\n", conta[i]->conta);
            fprintf(saida, "Saldo: R$ %.2f\n", conta[i]->dinheiro);

            ImprimeNomeCPF(saida, conta[i]->usuario);

            fprintf(saida, "Ultimas %d transacoes\n", qtdImpressoes);

            numeroMovimentacoes = conta[i]->movimentacoes;

            while (1)
            {
                if (qtdImpressoes == 0)
                {
                    break;
                }

                fprintf(saida, "%.2f\n", conta[i]->extrato[numeroMovimentacoes - 1]);

                qtdImpressoes--;
                numeroMovimentacoes--;
            }
        }
    }

    fclose(saida);
}