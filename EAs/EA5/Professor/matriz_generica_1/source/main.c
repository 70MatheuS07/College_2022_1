/*-------------------------------------------*
 * programa principal para teste do uso de 
 * matriz como um tipo abstrato de dados   
 *-------------------------------------------*/
#include <stdio.h>

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 */
#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "f"
#include "matriz.h"


int main ()
{
    Matriz_pt mat3por4 = criaMatriz(3,4);
    Matriz_pt mat2por3 = criaMatriz(2,3);
    Matriz_pt matProduto;
    
    preencheSequencialMatriz (mat3por4);
   	exibeMatriz (mat3por4);

    preencheSequencialMatriz (mat2por3);
    exibeMatriz (mat2por3);

	matProduto = multiplicaMatrizes (mat2por3, mat3por4);
	
	exibeMatriz (matProduto);

	return 0;
}
