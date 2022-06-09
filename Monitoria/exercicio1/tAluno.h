#ifndef TALUNO_H
#define TALUNO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct tAluno tAluno;

void LehAlunos(tAluno *alunos[], int num);

void AnalisaAprovados(tAluno *alunos[], int num);

void ImprimeAprovados(tAluno *alunos[], int num);

void OrdenaMatriculas(tAluno *alunos[], int num);

void LiberaAlunos(tAluno *alunos[], int num);

#endif