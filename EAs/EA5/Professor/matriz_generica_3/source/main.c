/*-------------------------------------------*
 * programa principal para teste do uso de 
 * matriz como um tipo abstrato de dados   
 *-------------------------------------------*/
#include <stdio.h>

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 */
#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%f"
#define TIPADO_(THING) D_ ## THING
#include "matriz.h"


int main ()
{
    D_Matriz_pt Dmat3por4 = D_criaMatriz(3,4);
    D_Matriz_pt Dmat2por3 = D_criaMatriz(2,3);
    D_Matriz_pt DmatProduto;
    
    D_preencheSequencialMatriz (Dmat3por4);
   	D_exibeMatriz (Dmat3por4);

    D_preencheSequencialMatriz (Dmat2por3);
    D_exibeMatriz (Dmat2por3);

	DmatProduto = D_multiplicaMatrizes (Dmat2por3, Dmat3por4);
	
	D_exibeMatriz (DmatProduto);

	return 0;
}
