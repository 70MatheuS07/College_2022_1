#include "prototipos.h"
#include "ufenixcat.h"
#include "ufenixls.h"
#include "ufenixsort.h"
#include "ufenixtail.h"
#include "ufenixuniq.h"

char LehCaracterCaracter(char *string);

int ColetaArgumentos(int argc, char **argv, char caracterPosComando);

int LiberaArgumentos(int argc, char **argv);

int main(int argc, char *argv[])
{
  int i = 0;
  char *opcao = calloc(TAM_INICIAL, sizeof(char));
  char caracterPosComando;

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

    caracterPosComando = LehCaracterCaracter(opcao);

    if (strcmp(opcao, "sair") == 0)
    {
      break;
    }

    else if (strcmp(opcao, "cat") == 0)
    {
      argc = ColetaArgumentos(argc, argv, caracterPosComando);
      mainUfenix_cat(argc, argv);
    }

    else if (strcmp(opcao, "ls") == 0)
    {
      argc = ColetaArgumentos(argc, argv, caracterPosComando);
      mainUfenix_ls(argc, argv);
    }

    else if (strcmp(opcao, "tail") == 0)
    {
      argc = ColetaArgumentos(argc, argv, caracterPosComando);
      mainUfenix_tail(argc, argv);
    }

    else if (strcmp(opcao, "uniq") == 0)
    {
      argc = ColetaArgumentos(argc, argv, caracterPosComando);
      mainUfenix_uniq(argc, argv);
    }

    else if (strcmp(opcao, "sort") == 0)
    {
      argc = ColetaArgumentos(argc, argv, caracterPosComando);
      mainUfenix_sort(argc, argv);
    }

    else
    {
      printf("Operacao invalida, tente novamente\n\n");
    }

    argc = LiberaArgumentos(argc, argv);
  }

  free(opcao);
  opcao = NULL;

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

int ColetaArgumentos(int argc, char **argv, char caracterPosComando)
{
  char *argumento = NULL;
  char caracter;

  if (caracterPosComando == '\n')
  {
    return argc;
  }

  while (1)
  {
    argumento = calloc(TAM_INICIAL, sizeof(char));

    caracter = LehCaracterCaracter(argumento);

    argc++;
    argv[argc - 1] = argumento;

    if (caracter == '\n')
    {
      return argc;
    }
  }
}

int LiberaArgumentos(int argc, char **argv)
{
  for (int k = 1; k < argc; argc--)
  {
    free(argv[argc - 1]);
    argv[argc - 1] = NULL;
  }

  return argc;
}