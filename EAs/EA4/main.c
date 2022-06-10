#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "num.h"

#define INT_MAX 10

int main()
{
  Num *numero1;
  Num *numero2;
  Num *numeroFinal;
  char comando;

  char numero[INT_MAX];

  scanf("%c\n", &comando);

  numero1 = numCreate(numero);

  numero2 = numCreate(numero);

  LehNumeros(numero1, numero2);

  numeroFinal = numCreate(numero);

  numAdd(numero1, numero2);

  ImprimeNumeros(numero1, numero2, numeroFinal);

  return 0;
}