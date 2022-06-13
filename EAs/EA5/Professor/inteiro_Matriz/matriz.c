#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "matriz.h"

struct matriz {
	int** mat;
	int ncolunas;
	int nlinhas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
	Matriz* mat = (Matriz*) malloc (sizeof(struct matriz));
	mat->ncolunas = ncolunas;
	mat->nlinhas = nlinhas;
	mat->mat = (int**) malloc (nlinhas*sizeof(int*));
	int i;
	for (i=0; i<nlinhas;i++)
		mat->mat[i] = (int*)malloc (ncolunas*sizeof(int));

	return mat;
}; 

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
	mat->mat[linha][coluna]= elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
	return mat->mat[linha][coluna];
}

Matriz* transposta (Matriz* mat)
{
   int i, j;
   Matriz* trp = inicializaMatriz(mat->ncolunas, mat->nlinhas);
   for (i=0; i<mat->nlinhas; i++)
	  for (j=0; j<mat->ncolunas; j++)
		   trp->mat[j][i] = mat->mat[i][j];
	   return trp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
	Matriz* mult= inicializaMatriz(mat1->nlinhas, mat2->ncolunas);
	int i, j, k, t;
	for (i=0;i<mult->nlinhas;i++)
		for (j=0;j<mult->ncolunas;j++)
		{
			t = 0;
			for (k=0;k<mat1->ncolunas;k++)
				t = t + mat1->mat[i][k]*mat2->mat[k][j];
			mult->mat[i][j] = t;
		}
	return mult;
}


void imprimeMatriz(Matriz* mat)
{
	int i, j;
	for (i=0; i<mat->nlinhas; i++)
	{
		for (j=0; j<mat->ncolunas;j++)
			printf ("%d ", mat->mat[i][j]);
		printf ("\n");
	}	
}

int retornaNColunas (Matriz* mat)
{
	return mat->ncolunas;
}

int retornaNLinhas (Matriz* mat)
{
	return mat->nlinhas;
}

void destroiMatriz(Matriz* mat)
{
	int i, j;
	for (i=0; i<mat->nlinhas; i++)
	{
		free(mat->mat[i]);
	}
	free(mat->mat);	
	free(mat);
	
}

void giraMatriz(Matriz* mat){
	if (mat->nlinhas != mat->ncolunas)
	{
		printf("A matriz não é NxN");
		return;
	}
	 int n = mat->nlinhas;
	for (int layer = 0; layer < n / 2; ++layer) {
		
		int first = layer;
		
		int last = n - 1 - layer;
		
		for(int i = first; i < last; ++i) {
			
			int offset = i - first;
			
			int top = mat->mat[first][i]; // save top
			
			// left -> top
			
			mat->mat[first][i] = mat->mat[last-offset][first]; 			
			
						 // bottom -> left
			mat->mat[last-offset][first] = mat->mat[last][last - offset];
			
						 // right -> bottom
			mat->mat[last][last - offset] = mat->mat[i][last];	
		
		}
	}	

}
