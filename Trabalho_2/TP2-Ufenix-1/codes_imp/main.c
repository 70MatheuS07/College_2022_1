#include "prototipos.h"
#include "ufenixcat.h"
#include "ufenixls.h"
#include "ufenixsort.h"
#include "ufenixtail.h"
#include "ufenixuniq.h"

char LehCaracterCaracter(char *string);

int main(int argc, char *argv[])
{

  int i = 0;
  char opcao[TAM_INICIAL];
  char *argumentoComando = calloc(TAM_INICIAL, sizeof(char));
  char *argumento = calloc(TAM_INICIAL, sizeof(char));
  char *argumento_ls;
  char *argumento_sort;
  char caracter;

  while (1)
  {

    printf("Digite o nome da opcao desejada:\n");
    printf("- cat\n");
    printf("- ls\n");
    printf("- tail\n");
    printf("- uniq\n");
    printf("- sort\n");
    printf("- sair\n\n");

    printf("Ufenix$ ");

    caracter = LehCaracterCaracter(opcao);

    if (strcmp(opcao, "sair") == 0)
    {
      break;
    }

    else if (strcmp(opcao, "cat") == 0)
    {
      if (caracter == '\n')
      {
        mainUfenix_cat(argc, argv);
      }

      else
      {
        caracter = LehCaracterCaracter(argumento);
        argc++;
        argv[1] = argumento;
        mainUfenix_cat(argc, argv);
        argc--;
      }
    }

    else if (strcmp(opcao, "ls") == 0)
    {
      if (caracter == '\n')
      {
        mainUfenix_ls(argc, argv);
      }

      else
      {
        while (1)
        {
          argumento_ls = calloc(TAM_INICIAL, sizeof(char));

          caracter = LehCaracterCaracter(argumento_ls);

          argc++;
          argv[argc - 1] = argumento_ls;

          if (caracter == '\n')
          {
            break;
          }
        }

        mainUfenix_ls(argc, argv);

        for (int k = 1; k < argc; argc--)
        {
          free(argv[argc - 1]);
        }
      }
    }

    else if (strcmp(opcao, "tail") == 0)
    {
      if (caracter != '\n')
      {
        caracter = LehCaracterCaracter(argumentoComando);

        if (argumentoComando[0] == '-')
        {
          argc++;
          argv[1] = argumentoComando;

          if (caracter == '\n')
          {
            mainUfenix_tail(argc, argv);
          }

          else
          {
            caracter = LehCaracterCaracter(argumento);
            argc++;
            argv[2] = argumento;
            mainUfenix_tail(argc, argv);
            argc -= 2;
          }
        }

        else
        {
          printf("Tail precisa de um argumento -N (N sendo um valor inteiro) antes do arquivo\n");
        }
      }

      else
      {
        printf("Tail precisa de um argumento -N (N sendo um valor inteiro)\n");
      }
    }

    else if (strcmp(opcao, "uniq") == 0)
    {
      if (caracter == '\n')
      {
        mainUfenix_uniq(argc, argv);
      }

      else
      {
        LehCaracterCaracter(argumento);
        argc++;
        argv[1] = argumento;
        mainUfenix_uniq(argc, argv);
        argc--;
      }
    }

    else if (strcmp(opcao, "sort") == 0)
    {
      if (caracter == '\n')
      {
        mainUfenix_sort(argc, argv);
      }

      else
      {
        while (1)
        {
          argumento_sort = calloc(TAM_INICIAL, sizeof(char));

          caracter = LehCaracterCaracter(argumento_sort);

          argc++;
          argv[argc - 1] = argumento_sort;

          if (caracter == '\n')
          {
            break;
          }
        }

        mainUfenix_sort(argc, argv);

        for (int k = 1; k < argc; argc--)
        {
          free(argv[argc - 1]);
          argv[argc - 1] = NULL;
        }
      }
    }

    else
    {
      printf("Operacao invalida, tente novamente\n\n");
    }
  }

  free(argumentoComando);
  free(argumento);

  return 0;
}

char LehCaracterCaracter(char *string)
{
  int i = 0;
  char caracter;

  while (1)
  {
    scanf("%c", &caracter);

    if (caracter == '\n' || caracter == ' ')
    {
      string[i] = '\0';
      break;
    }

    else
    {
      string[i] = caracter;
      i++;
    }
  }

  return caracter;
}