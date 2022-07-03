#include "tConta.h"

struct tConta
{
    tUsuario *usuario;
    int conta;
    float dinheiro;
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

void CadastraContas(tConta **conta, int num)
{
    if (num > 10)
    {
        conta = realloc(conta, sizeof(tConta *) * num);
    }

    PegaDadosConta(conta, num);
}

void PegaDadosConta(tConta **conta, int num)
{
    int numConta = 0;

    conta[num - 1]->usuario = CriaUsuario();

    scanf(" %d\n", &numConta);

    conta[num - 1]->conta = numConta;

    conta[num - 1]->dinheiro = 0;
}

void RegistraSaque(tConta **conta, int num)
{
    int usuario = 0;
    float saque = 0;

    scanf("%d ", &usuario);
    scanf("%f \n", &saque);

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

void RegistraDeposito(tConta **conta, int num)
{
    int usuario = 0;
    float deposito = 0;

    scanf("%d ", &usuario);

    scanf("%f \n", &deposito);

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

void RegistraTransferencia(tConta **conta, int num)
{
    int origem = 0, destino = 0;
    float transferencia = 0;

    scanf("%d ", &origem);
    scanf("%d ", &destino);
    scanf("%f \n", &transferencia);

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
    printf("===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < num; i++)
    {
        printf("Conta: %d\n", conta[i]->conta);
        printf("Saldo: R$ %.2f\n", conta[i]->dinheiro);

        ImprimeNomeCPF(conta[i]->usuario);
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