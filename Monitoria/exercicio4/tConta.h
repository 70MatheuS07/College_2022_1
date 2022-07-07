#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tUsuario.h"

typedef struct tConta tConta;

tConta **CriaContas();

void CadastraContas(FILE *arquivo, tConta **conta, int num);

void PegaDadosConta(FILE *arquivo, tConta **conta, int num);

void RegistraSaque(FILE *arquivo, tConta **conta, int num);

void RegistraDeposito(FILE *arquivo, tConta **conta, int num);

void RegistraTransferencia(FILE *arquivo, tConta **conta, int num);

void ImprimeRelatorio(tConta **conta, int num);

void LiberaContas(tConta **conta, int num);

#endif