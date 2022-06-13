#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "matriz.h"

struct matriz{
  void** mat;
  unsigned int ncolunas;
  unsigned int nlinhas;
};

//Or use the Enum Type
Matriz* inicializaMatriz(int nlinhas, int ncolunas, size_t size)
{
  Matriz *mat;
  mat = (Matriz *)malloc(sizeof(struct matriz));
  if (mat == NULL)
  {
    printf("Error");
    exit(1);
  }
    
  mat->nlinhas= nlinhas;
  mat->ncolunas = ncolunas;
  
  mat->mat =  malloc(nlinhas*sizeof(size ));

  for (int i=0; i < nlinhas; i++)
    mat->mat[i] = malloc(ncolunas*sizeof(size));


  return mat;

}
void atribuiElemMatriz (Matriz *mat, 
						unsigned int i, 
                        unsigned int j, 
                        void *valor, enum tipo t) 
{
	if ( i>= mat->nlinhas ||  j>=mat->ncolunas) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
  switch (t) {
        case TIPO_DOUBLE:
       ((double **)mat->mat)[i][j] = (*(double *)valor);
        break;

        case TIPO_INT:
        ((int **)mat->mat)[i][j] = (*(int *)valor);
        break;

        case TIPO_FLOAT:
       ((float **)mat->mat)[i][j] = (*(float *)valor);
        break;
    }
  
	
}


void imprimeMatriz(Matriz* mat, enum tipo t)
{
	int i, j;
	for (i=0; i<mat->nlinhas; i++)
	{
		for (j=0; j<mat->ncolunas;j++)
      {
        switch (t) {
        case TIPO_DOUBLE:
       printf ("%lf ",((double **)mat->mat)[i][j]);
        break;

        case TIPO_INT:
        printf ("%d ",((int **)mat->mat)[i][j]);
        break;

        case TIPO_FLOAT:
       printf ("%f ",((float **)mat->mat)[i][j]);
        break;
    }
      }
			
		printf ("\n");
	}	
}

void freeMatriz(Matriz *mat)
{
  for(int i=0; i < mat->nlinhas; i++)
  {
    free(mat->mat[i]);
  }
  free(mat->mat);
  free(mat);
  mat=NULL;
}
