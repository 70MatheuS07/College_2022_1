#include "tAluno.h"
#include <string.h>

struct tAluno
{
    char aluno[31];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
    char aprovado;
};

void LehAlunos(tAluno *alunos[], int num)
{
    int i = 0, j = 0;
    int l=0,k=0;
    char aluno[31];
    char letra;
    int matricula = 0;
    float nota1 = 0;
    float nota2 = 0;
    float nota3 = 0;

    for (i = 0; i < num; i++)
    {
        alunos[i] = malloc(sizeof(tAluno));

        scanf("%[^\n]", aluno);

        scanf("%d\n", &matricula);

        scanf("%f %f %f\n", &nota1, &nota2, &nota3);

        strcpy(alunos[i]->aluno, aluno);
        alunos[i]->matricula = matricula;
        alunos[i]->nota1 = nota1;
        alunos[i]->nota2 = nota2;
        alunos[i]->nota3 = nota3;
    }
}

void AnalisaAprovados(tAluno *alunos[], int num)
{
    int i = 0;
    float media = 0;

    for (i = 0; i < num; i++)
    {
        media = ((alunos[i]->nota1 + alunos[i]->nota2 + alunos[i]->nota3) / 3);

        if (media >= 7.00)
        {
            alunos[i]->aprovado = 's';
        }

        else
        {
          alunos[i]->aprovado = 'n';
        }
    }
}

void OrdenaMatriculas(tAluno *alunos[], int num)
{
  int i,j;
  tAluno *ponteiro = NULL;

  for(i=0;i<num;i++)
    {
      for(j=0;j<num;j++)
        {
            if(alunos[i]->matricula < alunos[j]->matricula)
            {
                ponteiro = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = ponteiro;
            }
        }
    }
}

void ImprimeAprovados(tAluno *alunos[], int num)
{
  int i=0;

  printf("Alunos Aprovados:\n");

  for(i=0;i<num;i++)
    {
      if(alunos[i]->aprovado == 's')
      {
          printf("%s\n", alunos[i]->aluno);
      }
    }
}

void LiberaAlunos(tAluno *alunos[], int num)
{
    int i=0;

    for(i=0;i<num;i++)
      {
        free(alunos[i]);

        alunos[i] = NULL;
      }
  
}