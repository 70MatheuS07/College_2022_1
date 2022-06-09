#include <stdlib.h>
#include <stdio.h>
#include "tData.h"

// Consegui @AbraaoAbe XD
// Era um erro no ImprimeData eu estava mandando 'n' aou invés de 'i'

int main()
{
    int i = 0, n = 0;

    scanf("%d", &n);

    tData *data[n];

    LehData(data, n);

    for (i = 0; i < n; i++)
    {
        if(data[i] == NULL)
            exit(1);
        
        CorrigiData(data, n);

        ImprimeData(data, i);

        if (EhBissexto(data, i) == 1)
        {
            printf(":Bisexto\n");
        }
        else
        {
            printf(":Normal\n");
        }

      free(data[i]);
    }

    return 0;
}