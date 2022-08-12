#include "ufenixls.h"

// Valor que struct dirent->d_type assume após identificar um diretório
#define DIRETORIO 4

typedef int (*FunctionPointerDot)(const struct dirent *);

// Ordena por nome
int Sort(const struct dirent **a, const struct dirent **b)
{

  const char *c = (*a)->d_name;
  const char *d = (*b)->d_name;

  return strcmp(c, d);
}

// Ordena primeiro por nome, em seguida por tipo, com diretórios à frente de não-diretórios
int SortByType(const struct dirent **a, const struct dirent **b)
{

  const char *c = (*a)->d_name;
  const char *d = (*b)->d_name;
  const int e = (*a)->d_type;
  const int f = (*b)->d_type;
  int result;

  result = strcmp(c, d);

  if (e == DIRETORIO && f != DIRETORIO)
    return -1;

  else if (f == DIRETORIO && e != DIRETORIO)
    return 1;

  return result;
}

int FilterDot(const struct dirent *line)
{

  if (line->d_name[0] == '.')
  {
    return 0;
  }

  return 1;
}

void ufenix_ls(const char *dir, bool show_all, bool sort_by_type)
{

  FunctionPointerDot FptrDot = NULL;
  struct dirent **namelist;
  int n, i = 0;

  if (show_all == false)
  {
    FptrDot = FilterDot;
  }

  if (sort_by_type == true)
  {
    n = scandir(dir, &namelist, FptrDot, SortByType);
  }

  else
  {
    n = scandir(dir, &namelist, FptrDot, Sort);
  }

  if (n < 0)
  {
    printf("Nao e possivel acessar %s", dir);
  }
    
  else
  {

    while (1)
    {

      if (i == n)
        break;

      printf("%s", namelist[i]->d_name);

      if (namelist[i]->d_type == DIRETORIO)
      {
        printf(" |");
      }
      printf("\n");

      free(namelist[i]);
      i++;
    }

    free(namelist);
  }
}

int mainUfenix_ls(int argc, char *argv[])
{
  optind = 0;
  bool mostrar_tudo = false;
  bool dirs_primeiro = false;

  int opt;
  // o getopt ajuda a pegar e tratar os argumentos
  while ((opt = getopt(argc, argv, "az")) != -1)
  {
    switch (opt)
    {
    case 'a':
      mostrar_tudo = true;
      break;
    case 'z':
      dirs_primeiro = true;
      break;
    default:
      exit(1);
    }
  }
  // optind é um variavel com escopo extern do getopt
  // ver documentação para entender
  if (optind < argc - 1)
  {
    for (int i = optind; i < argc; i++)
    {
      printf("%s:\n", argv[i]);
      ufenix_ls(argv[i], mostrar_tudo, dirs_primeiro);
      printf("\n");
    }
  }
  else
  {
    ufenix_ls(optind == argc - 1 ? argv[optind] : ".", mostrar_tudo,
              dirs_primeiro);
  }

  return 0;
}
