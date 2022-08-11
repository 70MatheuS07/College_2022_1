#include "ufenixtail.h"

void LiberaJanela(char **janela_deslizante, int n)
{
  for (int i = 0; i < n; i++)
  {
    free(janela_deslizante[i]);
    janela_deslizante[i] = NULL;
  }

  free(janela_deslizante);
  janela_deslizante = NULL;
}

void ufenix_tail(FILE *fp, int n)
{
  int i = 0, j = 0, numLinhasArquivo = 0;
  char **janela_deslizante = calloc(n, sizeof(char *));
  char *string = NULL;

  while (1)
  {
    string = ler_linha(fp);

    if (string == NULL)
      break;
    
    // Move matriz janela_deslizante
    if (j == 1)
    {
      // Libera memória da posição da linha zero e desloca as demais posições da matriz janela_deslizante uma unidade para cima
      free(janela_deslizante[0]);
      janela_deslizante[0] = NULL;
  
      for (int k = 1; k < n; k++)
      {
        janela_deslizante[k - 1] = janela_deslizante[k];
        janela_deslizante[k] = NULL;
      }

      j = 0;
    }

    janela_deslizante[i] = string;
    i++;

    // Impede que a matriz janela_deslizante cresça mais que a quantidade de linhas n que ela deve armazenar
    if (i == n)
    {
      i = n - 1;
      j = 1;
    }

    numLinhasArquivo++;
  }

  if (numLinhasArquivo < n)
  {
    printf("O argumento -N excede o numero maximo de linhas do arquivo\n");
  }

  else
  {
    for (int k = 0; k < n; k++)
    {
      printf("%s\n", janela_deslizante[k]);
    }
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

int mainUfenix_tail(int argc, char *argv[])
{
  int num = 10;

  if (argc > 1 && argv[1][0] == '-')
  {
    num = argumento_inteiro(argv[1] + 1);
    argv++;
    argc--;
  }

  else
  {
    printf("E necessario ter o argumento -N com o numero de linhas\n");
    return 0;
  }

  if(argc > 2 || argv[2][0] == '-')
  {
    printf("Essa funcao so suporta 2 argumentos uma linha de comando -N e o arquivo\n");
    return 0;
  }

  FILE *fp;
  if (argc == 1)
  {
    fp = stdin;
  }
  else
  {
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
      printf("%s: Arquivo nao encontrado\n", argv[1]);
      return 0;
    }
  }

  ufenix_tail(fp, num);
  fclose(fp);
  return 0;
}