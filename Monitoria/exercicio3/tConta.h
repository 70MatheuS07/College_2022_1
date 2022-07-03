#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tUsuario.h"

typedef struct tConta tConta;

tConta **CriaContas();

void CadastraContas(tConta **conta, int num);

void PegaDadosConta(tConta **conta, int num);

void RegistraSaque(tConta **conta, int num);

void RegistraDeposito(tConta **conta, int num);

void RegistraTransferencia(tConta **conta, int num);

void ImprimeRelatorio(tConta **conta, int num);

void LiberaContas(tConta **conta, int num);

#endif