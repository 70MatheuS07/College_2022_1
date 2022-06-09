#ifndef TDATA_H
#define TDATA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct tData tData;

tData *LehData();

int SaoDiferentes(tData *data, tData *dataFinal);

tData *AvancaParaDiaSeguinte(tData *data);

void ImprimeData(tData *data);

int EhBissexto(tData *data);

int QtdDeDiasNoMes(tData *data);

tData *CorrigiData(tData *data);

#endif