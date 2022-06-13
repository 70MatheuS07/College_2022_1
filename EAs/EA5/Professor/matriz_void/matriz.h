#ifndef _MATRIZ_H
#define _MATRIZ_H

#include <stdio.h>

enum tipo { 
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_DOUBLE
};

//Tipo Matriz Opaco
typedef struct matriz Matriz;

/**
Inicializa a matriz com nlinhas e ncolunas

@params nlinhas = numero de linhas
        ncolunas=  numero de colunas

@return  Um ponteiro do tipo matriz alocada com o numero de linhas;
*/
Matriz* inicializaMatriz(int nlinhas, int ncolunas, size_t size);


/**
Libera matriz com nlinhas e ncolunas da memoria e após libera a struct matriz

@params matriz * 

*/
void freeMatriz(Matriz *mat);

void atribuiElemMatriz (Matriz *mat, 
						unsigned int i, 
                        unsigned int j, 
                        void *valor, enum tipo t);

void imprimeMatriz(Matriz* mat, enum tipo t);






#endif