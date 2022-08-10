#include "prototipos.h"
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TAM_INICIAL 100
#define QUANTIDADE_INICIAL 1

void LiberaTextoUniq(char **texto, int multiplicador)
{
    for (int i = 0; i < TAM_INICIAL * multiplicador; i++)
    {
        free(texto[i]);
        texto[i] = NULL;
    }

    free(texto);
    texto = NULL;
}

void ufenix_uniq(FILE *fp)
{

    char **texto = calloc(TAM_INICIAL, sizeof(char *));
    char *string = NULL;
    int k = 0, multiplicador = 1;
    int *quantidade = calloc(TAM_INICIAL, sizeof(int));

    while (1)
    {
        string = ler_linha(fp);

        if (string == NULL) break;

        if (k == TAM_INICIAL * multiplicador)
        {
            multiplicador += 1;
            texto = realloc(texto, sizeof(char *) * (TAM_INICIAL * multiplicador));
            quantidade = realloc(quantidade, sizeof(int)*(TAM_INICIAL * multiplicador));
        }

        texto[k] = string;
        k++;
      }

    

    for (int i = 0; i < (TAM_INICIAL * multiplicador) - 1; i++)
    {
      if(texto[i] == NULL) break;
      
        if (texto[i][0] != '\0')
        {
            for (int j = i + 1; j < (TAM_INICIAL * multiplicador); j++)
            {
              if(texto[j] == NULL) break;
              
                if (texto[j][0] != '\0')
                {
                    if (strcmp(texto[i], texto[j]) == 0)
                    {
                        texto[j][0] = '\0';
      
                        quantidade[i] += 1;
                        quantidade[j] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < TAM_INICIAL * multiplicador; i++)
    {
      if(texto[i] == NULL) break;
      
        if (texto[i][0] != '\0')
        {
            printf("%7d %s\n", (QUANTIDADE_INICIAL + quantidade[i]), texto[i]);
        }
    }

    LiberaTextoUniq(texto, multiplicador);
  
    free(string);
    string = NULL;

    free(quantidade);
    quantidade = NULL;
}

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1)
    {
        fp = stdin;
    }
    else
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
            error(1, 0, "%s: Arquivo nao encontrado", argv[1]);
    }
    ufenix_uniq(fp);
    fclose(fp);
    return 0;
}
