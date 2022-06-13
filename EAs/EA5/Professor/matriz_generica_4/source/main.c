/*-------------------------------------------*
 * programa principal para teste do uso de 
 * matriz como um tipo abstrato de dados   
 *-------------------------------------------*/
#include <stdio.h>

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 */

#include "matriz_double.h"
#include "matriz_float.h"
#include "matriz_integer.h"

int main ()
{
	printf ("======== PROCESSAMENTO DE MATRIZES DE DOUBLE ======== \n");
    D_Matriz_pt Dmat3por4 = D_criaMatriz(3,4);
    D_Matriz_pt Dmat2por3 = D_criaMatriz(2,3);
    D_Matriz_pt DmatProduto;
    
    D_preencheSequencialMatriz (Dmat3por4);
   	D_exibeMatriz (Dmat3por4);

    D_preencheSequencialMatriz (Dmat2por3);
    D_exibeMatriz (Dmat2por3);

	DmatProduto = D_multiplicaMatrizes (Dmat2por3, Dmat3por4);
	
	D_exibeMatriz (DmatProduto);
	
	
	printf ("======== PROCESSAMENTO DE MATRIZES DE FLOAT ======== \n");
	F_Matriz_pt Fmat3por4 = F_criaMatriz(3,4);
    F_Matriz_pt Fmat2por3 = F_criaMatriz(2,3);
    F_Matriz_pt FmatProduto;
    
    F_preencheSequencialMatriz (Fmat3por4);
   	F_exibeMatriz (Fmat3por4);

    F_preencheSequencialMatriz (Fmat2por3);
    F_exibeMatriz (Fmat2por3);

	FmatProduto = F_multiplicaMatrizes (Fmat2por3, Fmat3por4);
	
	F_exibeMatriz (FmatProduto);
	
	
	printf ("======== PROCESSAMENTO DE MATRIZES DE INTEIRO ======== \n");
	I_Matriz_pt Imat3por4 = I_criaMatriz(3,4);
    I_Matriz_pt Imat2por3 = I_criaMatriz(2,3);
    I_Matriz_pt ImatProduto;
    
    I_preencheSequencialMatriz (Imat3por4);
   	I_exibeMatriz (Imat3por4);

    I_preencheSequencialMatriz (Imat2por3);
    I_exibeMatriz (Imat2por3);

	ImatProduto = I_multiplicaMatrizes (Imat2por3, Imat3por4);
	
	I_exibeMatriz (ImatProduto);

	return 0;
}
