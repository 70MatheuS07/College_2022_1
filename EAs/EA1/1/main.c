#include <stdlib.h>
#include <stdio.h>

typedef struct Amigos
{
    int friends[10000];
    int quantidade;

} tAmigos;

void LehAmigos(tAmigos amigos[], int num);

int QuantidadeAmigosIguais(tAmigos amigos[], int num);

void ImprimeQuantidadeAmigosEmComum(tAmigos amigos[], int num);

int main()
{
    int num = 0;

    scanf("%d\n", &num);

    tAmigos amigos[num];

    LehAmigos(amigos, num);

    ImprimeQuantidadeAmigosEmComum(amigos, num);

    return 0;
}

void LehAmigos(tAmigos amigos[], int num)
{
    int i = 0, j = 0;
    int amigo = 0;
    int quantidade = 0;
    char lixo;

    for (i = 0; i < num; i++)
    {
        scanf("%d%c", &quantidade, &lixo);

        amigos[i].quantidade = quantidade;

        for (j = 0; j < quantidade; j++)
        {
            if (j < quantidade - 1)
            {
                scanf("%d%c", &amigo, &lixo);
            }

            else
            {
                scanf("%d%c", &amigo, &lixo);
                scanf("%c", &lixo);
            }

            amigos[i].friends[j] = amigo;
        }
    }
}

int QuantidadeAmigosIguais(tAmigos amigos[], int num)
{
    int i = 0, j = 0;

    for (i = 0; i < num; i++)
    {
        for (j = 1; j < num; j++)
        {
            if (amigos[i].quantidade != amigos[j].quantidade)
            {
                return 0;
            }
        }
    }

    return 1;
}

void ImprimeQuantidadeAmigosEmComum(tAmigos amigos[], int num)
{
    int i = 0, j = 0;
    int m = 0, n = 0;
    int amigosIguais = 0;
    int amigo = 1;
    int igual = 1;

    for (j = 0; j < amigos[0].quantidade; j++)
    {

        for (m = 1; m < num; m++)
        {
            for (n = 0; n < amigos[m].quantidade; n++)
            {
                if (amigos[0].friends[j] == amigos[m].friends[n])
                {
                    igual++;
                }
            }

            if (igual == num)
            {
                amigosIguais++;
            }
        }

        igual = 1;
    }

    if (amigosIguais != 0)
    {
        printf("%d amigos em comum!\n", amigosIguais);
    }

    else
    {
        printf("IMPOSSIVEL!\n");
    }
}