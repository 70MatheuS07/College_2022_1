#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

/* O TIPO DE DADOS DE CADA ELEMENTO DA MATRIZ 
 * É O "DESTE_TIPO_" DEFINIDO NA IMPLEMENTAÇÃO
 */
  
/* TAD: matriz m por n */
/* Tipo exportado */
typedef struct TIPADO_(Matriz_st) * TIPADO_(Matriz_pt);

/* Métodos exportadas */

/* Método cria
** Aloca e retorna uma matriz de dimensão m por n
*/
TIPADO_(Matriz_pt) TIPADO_(criaMatriz) (unsigned int m, unsigned int n);


/* Método libera
** Libera a memória de uma matriz previamente criada.
*/
void TIPADO_(liberaMatriz) (TIPADO_(Matriz_pt) mat);


/* Método acessa
** Retorna o valor do elemento da linha i e coluna j da matriz
*/
DESTE_TIPO_    TIPADO_(acessaMatriz) (TIPADO_(Matriz_pt) mat, 
                                       unsigned int i, unsigned int j);


/* Método atribui
** Atribui o valor dado ao elemento da linha i e coluna j da matriz
*/
void TIPADO_(atribuiElemMatriz) (TIPADO_(Matriz_pt) mat, 
						unsigned int i, unsigned int j, 
						DESTE_TIPO_ v);


/* Método linhas
** Retorna o número de linhas da matriz
*/
unsigned int TIPADO_(linhasMatriz) (TIPADO_(Matriz_pt) mat);


/* Método colunas
** Retorna o número de colunas da matriz
*/
unsigned int TIPADO_(colunasMatriz) (TIPADO_(Matriz_pt) mat);


/* Método exibe
** exibe os elementos da matriz
*/
void  TIPADO_(exibeMatriz) (TIPADO_(Matriz_pt) mat);


/* Método preencheSequencial
** vai preenchendo os valores de 1 ate (m x n)
*  linha por linha 
*/
void  TIPADO_(preencheSequencialMatriz) (TIPADO_(Matriz_pt) mat);


/* Método multiplicaMatrizes 
*/
TIPADO_(Matriz_pt)  TIPADO_(multiplicaMatrizes) (TIPADO_(Matriz_pt) mat1, 
                                         TIPADO_(Matriz_pt) mat2);

#endif /* MATRIZ_H_INCLUDED */
