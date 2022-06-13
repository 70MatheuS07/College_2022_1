#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {
  struct matriz *m;
  
  m = inicializaMatriz(5, 3, sizeof(int));

  for (int i=0; i < 5; i++)
    for (int j =0; j < 3; j++)
      atribuiElemMatriz(m, i, j, &(i), TIPO_INT);

  imprimeMatriz(m,TIPO_INT);

  freeMatriz(m);

  return 0;
}