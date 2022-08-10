#include "prototipos.h"
#include <error.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void LiberaJanela(char **janela_deslizante, int n)
{
  for(int i=0; i<n;i++)
    {
      free(janela_deslizante[i]);
      janela_deslizante[i] = NULL;
    }

  free(janela_deslizante);
  janela_deslizante = NULL;
}

void ufenix_tail(FILE *fp, int n)
{
  int i=0, j=0;
  char **janela_deslizante = calloc(n, sizeof(char *));
  char *string = NULL;

    while(1)
      {
        string = ler_linha(fp);

        if(string == NULL) break;

        if(j == 1)
        {
          free(janela_deslizante[0]);
          janela_deslizante[0] = NULL;

          for(int k=1;k<n;k++)
            {
              janela_deslizante[k-1] = janela_deslizante[k];
              janela_deslizante[k] = NULL;
            }
          
          j = 0;
        }

        janela_deslizante[i] = string;
        i++;

        if(i == n)
        {
          i = n-1;
          j = 1;
        }

      }

  for(int k=0;k<n;k++)
    {
      printf("%s\n", janela_deslizante[k]);
    }

  LiberaJanela(janela_deslizante, n);
  free(string);
}

int argumento_inteiro(const char *str)
{
    char *end;
    long n = strtol(str, &end, 10);
    if (*end != '\0') 
        error(1, 0, "Numero invalido '%s'", str);
    if (n < 1 || n > INT_MAX) 
        error(1, 0, "%s Fora do intervalo [%d, %d]", str, 1, INT_MAX);
    return n;
}

int main(int argc, char *argv[])
{
    int num = 10;

    if (argc > 1 && argv[1][0] == '-') {
        num = argumento_inteiro(argv[1] + 1);
        argv++;
        argc--;
    }

    FILE *fp;
    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) error(1, 0, "%s: Arquivo nao encontrado", argv[1]);
    }
    ufenix_tail(fp, num);
    fclose(fp);
    return 0;
}