#include "tConta.h"

struct tConta
{
    tUsuario *usuario;
    int conta;
    int agencia;
    float dinheiro;
};

tConta *CriaConta()
{
    tConta *conta;

    conta = malloc(sizeof(conta));

    return conta;
}

tConta *PegaDadosConta()
{
    tConta *conta;

    conta = CriaConta();

    conta->usuario = CriaUsuario();

    conta->conta = 12345;
    conta->agencia = 1234;
    conta->dinheiro = 0;

    return conta;
}

void DepositaDinheiro(tConta *conta)
{
    float deposito = 0;

    scanf("%f\n", &deposito);

    conta->dinheiro += deposito;

    printf("Deposito realizado no valor de %.2f\n\n", deposito);
}

void SacaDinheiro(tConta *conta)
{
    float saque = 0;

    scanf("%f\n", &saque);

    if (conta->dinheiro < saque)
    {
        printf("Saldo insuficiente!\n\n");
    }

    else
    {
        conta->dinheiro -= saque;

        printf("Saque realizado no valor de %.2f\n\n", saque);
    }
}

void ImprimeSaldo(tConta *conta)
{
    printf("Saldo: %.2f\n", conta->dinheiro);
}

void ImprimeDadosConta(tConta *conta)
{
    ImprimeUsuario(conta->usuario);

    printf("Conta: %d\n", conta->conta);

    printf("Agencia: %d\n\n", conta->agencia);
}

void LiberaConta(tConta *conta)
{
    LiberaUsuario(conta->usuario);

    free(conta);
    
    conta = NULL;
}