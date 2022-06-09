#ifndef TDATA_H
#define TDATA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct tData tData;

void LehData(tData *data[], int n);

int SaoDiferentes(tData *data, tData *dataFinal);

tData *AvancaParaDiaSeguinte(tData *data);

void ImprimeData(tData *data[], int i);

int EhBissexto(tData *data[], int i);

int QtdDeDiasNoMes(tData *data[], int i);

void CorrigiData(tData *data[], int n);

#endif