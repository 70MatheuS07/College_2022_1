#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 1, j = 1;
    char caracter;
    char *string1 = calloc(i, sizeof(char));
    char *string2 = calloc(j, sizeof(char));

    for (;; i++)
    {
        scanf("%c", &caracter);

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        string1 = realloc(string1, sizeof(char) * i);

        if (caracter == '\n')
        {
            string1[i - 1] = '\0';
            break;
        }

        else
        {
            string1[i - 1] = caracter;
        }
    }

    for (;; j++)
    {
        scanf("%c", &caracter);

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        string2 = realloc(string2, sizeof(char) * j);

        if (caracter == '\n')
        {
            string2[j - 1] = '\0';
            break;
        }

        else
        {
            string2[j - 1] = caracter;
        }
    }

    if (strcmp(string1, string2) == 0)
    {
        printf("True");
    }

    else
    {
        printf("False");
    }

    return 0;
}