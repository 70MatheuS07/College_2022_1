#include <stdlib.h>
#include <stdio.h>
#include "tData.h"

int main()
{
    tData *data;
    tData *dataInicial;
    tData *dataFinal;

    dataInicial = LehData();
    dataFinal = LehData();

    data = dataInicial;
    dataInicial = CorrigiData(data);

    data = dataFinal;
    dataFinal = CorrigiData(data);

    for (data = dataInicial; 0 < SaoDiferentes(data, dataFinal); data = AvancaParaDiaSeguinte(data))
    {
        ImprimeData(data);
        printf("\n");
    }

    return 0;
}