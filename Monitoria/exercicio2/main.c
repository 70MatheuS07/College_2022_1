#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tConta.h"
#include "tUsuario.h"

int main()
{
    tConta *conta;

    int comando = -1;

    conta = PegaDadosConta();

    ImprimeDadosConta(conta);

    while (1)
    {
        scanf("%d\n", &comando);

        if (comando == 0) // Sair.
        {
            ImprimeSaldo(conta);

            break;
        }

        else if (comando == 1) // Saque.
        {
            SacaDinheiro(conta);
        }

        else if (comando == 2) // Depósito.
        {
            DepositaDinheiro(conta);
        }
    }

    return 0;
}