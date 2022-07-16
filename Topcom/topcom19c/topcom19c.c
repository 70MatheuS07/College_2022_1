#include <stdlib.h>
#include <stdio.h>

int ConfereString(char *string, int num);

int main()
{
  int num, i = 1, j;
  char caracter;
  char string[1000];

  scanf("%d\n", &num);

  int parenteses = 0, chaves = 0, colchetes = 0;

  for (j = 0; j < num; j++)
  {

    for (;; i++)
    {
      scanf("%c", &caracter);

      if (caracter == '\n')
      {
        string[i - 1] = '\0';
        break;
      }

      else
      {
        string[i - 1] = caracter;
      }

      switch (caracter)
      {
      case '(':
        parenteses++;
        break;

      case ')':
        parenteses--;
        break;

      case '[':
        colchetes++;
        break;

      case ']':
        colchetes--;
        break;

      case '{':
        chaves++;
        break;

      case '}':
        chaves--;
        break;
      }
    }

    if (parenteses == 0)
    {
      if (colchetes == 0)
      {
        if (chaves == 0)
        {
          if (ConfereString(string, i) == 1)
          {
            printf("Balanceada\n");
          }
          else
          {
            printf("Erro de balanceamento\n");
          }
        }

        else
        {
          printf("Erro de balanceamento\n");
        }
      }

      else
      {
        printf("Erro de balanceamento\n");
      }
    }

    else
    {
      printf("Erro de balanceamento\n");
    }

    parenteses = 0;
    colchetes = 0;
    chaves = 0;
    i = 1;
  }

  return 0;
}

int ConfereString(char string, int num)
{
  char alvos[1000];
  int n = -1;
  for (int i = 0; i < num; i++)
  {
    if (string[i] == '{')
    {
      n++;
      alvos[n] = '}';
    }
    else if (string[i] == '(')
    {
      n++;
      alvos[n] = ')';
    }
    else if (string[i] == '[')
    {
      n++;
      alvos[n] = ']';
    }

    if (alvos[n] == '}' && (string[i] == ')' || string[i] == ']'))
    {
      return 0;
    }
    else if (alvos[n] == ')' && (string[i] == ']' || string[i] == '}'))
    {
      return 0;
    }
    else if (alvos[n] == ']' && (string[i] == ')' || string[i] == '}'))
    {
      return 0;
    }

    if (string[i] == alvos[n])
    {
      if (n > 0)
      {
        n--;
      }
    }
  }
  return 1;
}