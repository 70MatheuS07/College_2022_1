#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tUsuario.h"

typedef struct tConta tConta;

tConta *CriaConta();

tConta *PegaDadosConta();

void DepositaDinheiro(tConta *conta);

void SacaDinheiro(tConta *conta);

void ImprimeSaldo(tConta *conta);

void ImprimeDadosConta(tConta *conta);

#endif