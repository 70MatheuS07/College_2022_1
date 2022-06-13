#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 */
  
/* TAD: matriz m por n */
/* Tipo exportado */
typedef struct Matriz_st * Matriz_pt;


/* Métodos exportadas */

/* Método cria
** Aloca e retorna uma matriz de dimensão m por n
*/
Matriz_pt criaMatriz (unsigned int m, unsigned int n);


/* Método libera
** Libera a memória de uma matriz previamente criada.
*/
void liberaMatriz (Matriz_pt mat);


/* Método acessa
** Retorna o valor do elemento da linha i e coluna j da matriz
*/
DESTE_TIPO_ acessaMatriz (Matriz_pt mat, unsigned int i, unsigned int j);


/* Método atribui
** Atribui o valor dado ao elemento da linha i e coluna j da matriz
*/
void atribuiElemMatriz (Matriz_pt mat, 
						unsigned int i, unsigned int j, 
						DESTE_TIPO_ v);


/* Método linhas
** Retorna o número de linhas da matriz
*/
unsigned int linhasMatriz (Matriz_pt mat);


/* Método colunas
** Retorna o número de colunas da matriz
*/
unsigned int colunasMatriz (Matriz_pt mat);


/* Método exibe
** exibe os elementos da matriz
*/
void  exibeMatriz (Matriz_pt mat);


/* Método preencheSequencial
** vai preenchendo os valores de 1 ate (m x n)
*  linha por linha 
*/
void  preencheSequencialMatriz (Matriz_pt mat);


/* Método multiplicaMatrizes 
*/
Matriz_pt  multiplicaMatrizes (Matriz_pt mat1, Matriz_pt mat2);

#endif /* MATRIZ_H_INCLUDED */
