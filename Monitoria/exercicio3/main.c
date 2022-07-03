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

    while (1)
    {
        scanf("%d\n", &comando);

        if (comando == 0) // Sair.
        {
            break;
        }

        else if (comando == 1) // Saque.
        {
            RegistraSaque(conta, num);
        }

        else if (comando == 2) // Depósito.
        {
            RegistraDeposito(conta, num);
        }

        else if (comando == 3)
        {
            RegistraTransferencia(conta, num);
        }

        else if (comando == 4)
        {
            num++;
            CadastraContas(conta, num);
        }

        else if (comando == 5)
        {
            ImprimeRelatorio(conta, num);
        }
    }

    LiberaContas(conta, num);

    return 0;
}