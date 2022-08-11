#include "ufenixuniq.h"

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

        if (string == NULL)
            break;

        if (k == TAM_INICIAL * multiplicador)
        {
            multiplicador += 1;
            texto = realloc(texto, sizeof(char *) * (TAM_INICIAL * multiplicador));
            quantidade = realloc(quantidade, sizeof(int) * (TAM_INICIAL * multiplicador));
        }

        texto[k] = string;
        k++;
    }
  
    // Para cada linha da matriz texto existe um loop que busca suas idênticas
    for (int i = 0; i < (TAM_INICIAL * multiplicador) - 1; i++)
    {
        if (texto[i] == NULL)
            break;

        if (texto[i][0] != '\0')
        {   
            // Busca linhas idêntidas
            for (int j = i + 1; j < (TAM_INICIAL * multiplicador); j++)
            {
                if (texto[j] == NULL)
                    break;
              
                if (texto[j][0] != '\0')
                {  
                    // Conta linha idêntica e incrementa posição da linha referência (texto[i]) no vetor quatidade
                    if (strcmp(texto[i], texto[j]) == 0)
                    {
                        texto[j][0] = '\0';

                        quantidade[i] += 1;
                        quantidade[j] = 0;
                    }
                }
            }
        }
    }
  
    // Imprime as linhas que ficaram como referencia
    for (int i = 0; i < TAM_INICIAL * multiplicador; i++)
    {
        if (texto[i] == NULL)
            break;

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

int mainUfenix_uniq(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1)
    {
        fp = stdin;
    }

    if(argv[1][0] == '-')
    {
      printf("uniq nao suporta flags de linha de comando\n");
      return 0;
    }
      
    else
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
          printf("%s: Arquivo não encontrado\n", argv[1]);
          return 0;
        }
    }
    ufenix_uniq(fp);
    fclose(fp);
    return 0;
}
