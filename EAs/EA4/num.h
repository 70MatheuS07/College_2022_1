#ifndef NUM_H
#define NUM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * Aritmética de alta precisão em número não negativo na base 10.
 Implemte o struct num com os campos que julgue necessário.
 */
typedef struct Num Num;

/* cria um Num de uma  string */
/* string contém representação do número
 * na base 10, por ex. numCreate ("314159");
 * Retorna um ponteiro nulo (0) se a string contiver quaisquer não dígitos.
 * Os zeros à esquerda estão OK: numCreate ("012") cria um NUM como 12.
 * String vazia é analisada como 0*/
Num *numCreate();

/* Libera todos os recursos usados por um número */
void numDestroy(Num *numeros);

/*Retorna o valor do i-ésimo dígito menos significativo de um Num.
 * Retorna 0 se i estiver fora do intervalo.
 * Exemplo:
 *   n = numCreate("12345");
 *   numGetDigit(n, 0) == 5
 *   numGetDigit(n, 3) == 2
 *   numGetDigit(n, 17) == 0
 *   numGetDigit(n, -12) == 0
 */
int numGetDigit(const Num *n, int i);

/* Somar dois Nums, retornando um novo Num */
/* não destrói suas entradas, o caller que deve destruir a saída */
Num *numAdd(Num *numero1, Num *numero2);

/* Multiplicar dois Nums, retornando um novo Num */
/* não destrói suas entradas, o caller que deve destruir a saída */
Num *numMultiply(Num *numero1, Num *numero2);

/* Exponenciar  x elevado a y, retornando um novo Num */
/* não destrói suas entradas, o caller que deve destruir a saída */
Num *numExp(Num *numero1, Num *numero2);

/* Imprime os dígitos de um número para arquivo.
  * Não imprima nenhum zeros à esquerda, a menos que n seja zero.

  Ex de uso dessa função:
  numPrint(n, STDOUT);

    A função será feita para imprimir em um arquivo mas os testes serão feitos imprimindo em na saída padrão STDOUT como no exemplo acima (ver exemplos com  fputc )
  */
void numPrint(Num *numero, FILE *arquivo);

Num *InvertePalavra(Num *numero);

Num *InicializaNumero();

#endif /* NUM_H */