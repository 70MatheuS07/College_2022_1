#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tConta.h"
#include "tUsuario.h"

int main()
{
    tConta **conta;

    int comando = -1, num = 0;

    conta = CriaContas();

    FILE *arquivo = NULL;

    arquivo = fopen("entrada.txt", "r");

    while (1)
    {
        fscanf(arquivo, "%d\n", &comando);

        if (comando == 0) // Sair.
        {
            break;
        }

        else if (comando == 1) // Saque.
        {
            RegistraSaque(arquivo, conta, num);
        }

        else if (comando == 2) // Depósito.
        {
            RegistraDeposito(arquivo, conta, num);
        }

        else if (comando == 3) // Transferência.
        {
            RegistraTransferencia(arquivo, conta, num);
        }

        else if (comando == 4) // Registra conta.
        {
            num++;
            CadastraContas(arquivo, conta, num);
        }

        else if (comando == 5) // Imprime relatório.
        {
            ImprimeRelatorio(conta, num);
        }

        else if (comando == 6) // Imprime extrato.
        {
            //ImprimeExtrato(arquivo, conta, num);
        }
    }

    LiberaContas(conta, num);

    return 0;
}