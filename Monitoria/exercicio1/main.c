#include <stdlib.h>
#include <stdio.h>
#include "tAluno.h"

int main()
{
    int num=0;

    scanf("%d\n", &num);

    tAluno *alunos[num];

    LehAlunos(alunos, num);

    AnalisaAprovados(alunos, num);

    OrdenaMatriculas(alunos, num);

    ImprimeAprovados(alunos, num);

    LiberaAlunos(alunos,num);
}