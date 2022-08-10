#include "prototipos.h"
#include <error.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INICIAL 32

void LiberaTextoSort(char **texto, int multiplicador)
{
  for (int i = 0; i < TAM_INICIAL * multiplicador; i++)
  {
    free(texto[i]);
    texto[i] = NULL;
  }

  free(texto);
  texto = NULL;
}

int cmp_pstr(const void *p, const void *q)
{

  const char *r1 = *(const char **)p;
  const char *r2 = *(const char **)q;

  return (strcmp(r1, r2));
}

int cmp_pstr_tamanho(const void *p, const void *q)
{

  int qtd_r1 = 0, qtd_r2 = 0;

  const char *r1 = *(const char **)p;
  const char *r2 = *(const char **)q;

  qtd_r1 = strlen(r1);
  qtd_r2 = strlen(r2);

  return (qtd_r1 > qtd_r2) - (qtd_r1 < qtd_r2);
}

int cmp_pstr_numeros(const void *p, const void *q)
{

  int qtd_r1 = 0, qtd_r2 = 0;

  const char *r1 = *(const char **)p;
  const char *r2 = *(const char **)q;

  qtd_r1 = atoi(r1);
  qtd_r2 = atoi(r2);

  return (qtd_r1 > qtd_r2) - (qtd_r1 < qtd_r2);
}

void Uniq_function(char **matriz, int qtd_linhas)
{
  for (int i = 0; i < qtd_linhas; i++)
  {
    if (matriz[i] == NULL)
      break;

    if (strcmp(matriz[i], "\n") != 0)
    {

      if (matriz[i][0] != '\0')
      {

        for (int j = i + 1; j < qtd_linhas; j++)
        {

          if (matriz[j] == NULL)
            break;

          if (matriz[j][0] != '\0')
          {

            if (strcmp(matriz[i], matriz[j]) == 0)
            {
              matriz[j][0] = '\0';
            }
          }
        }
      }
    }
  }
}

void ufenix_sort(FILE *fp, cmp_fn_t cmp, bool uniq, bool reverse)
{
  char **matriz = calloc(TAM_INICIAL, sizeof(char *));
  char *string = NULL;
  int i = 0, multiplicador = 1, qtd_linhas = 0;

  while (1)
  {
    string = ler_linha(fp);

    if (string == NULL)
    {
      qtd_linhas = i;
      break;
    }

    if (i == (TAM_INICIAL * multiplicador))
    {
      multiplicador += 1;
      matriz = realloc(matriz, sizeof(char *) * (TAM_INICIAL * multiplicador));
    }

    matriz[i] = string;
    i++;
  }

  if (uniq == true)
  {
    Uniq_function(matriz, qtd_linhas);
  }

  qsort(matriz, qtd_linhas, sizeof(char *), cmp);

  if (reverse == true)
  {
    for (int j = qtd_linhas - 1; j >= 0; j--)
    {
      if (strcmp(matriz[j], "\n") != 0)
      {
        if (strcmp(matriz[j], "\0") != 0)
        {
          printf("%s\n", matriz[j]);
        }
      }
    }
  }

  else
  {
    for (int j = 0; j < qtd_linhas; j++)
    {
      if (strcmp(matriz[j], "\n") != 0)
      {
        if (strcmp(matriz[j], "\0") != 0)
        {
          printf("%s\n", matriz[j]);
        }
      }
    }
  }

  LiberaTextoSort(matriz, multiplicador);
}

int mainUfenix_sort(int argc, char *argv[])
{
  cmp_fn_t cmp = cmp_pstr;
  bool uniq = false, reverse = false;

  int opt;
  while ((opt = getopt(argc, argv, "lnru")) != -1)
  {
    // Baseado no opt seta a função de comparação
    switch (opt)
    {

    case 'l':
      cmp = cmp_pstr_tamanho;
      break;
    case 'n':
      cmp = cmp_pstr_numeros;
      break;
    case 'r':
      reverse = true;
      break;
    case 'u':
      uniq = true;
      break;
    default:
      exit(1);
    }
  }

  FILE *fp = stdin;
  if (optind < argc)
  {
    fp = fopen(argv[optind], "r");
    if (fp == NULL)
      error(1, 0, "%s: Arquivo nao encontrado", argv[optind]);
  }
  ufenix_sort(fp, cmp, uniq, reverse);
  fclose(fp);
  return 0;
}
