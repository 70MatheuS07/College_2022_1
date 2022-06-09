#include "tData.h"

struct tData
{
    int dia;
    int mes;
    int ano;
};

void LehData(tData *data[], int n)
{
    int dia, mes, ano, i = 0;

    for (i = 0; i < n; i++)
    {
        data[i] = malloc(sizeof(tData));

        scanf("\n%d %d %d", &dia, &mes, &ano);

        data[i]->dia = dia;
        data[i]->mes = mes;
        data[i]->ano = ano;
    }
}

int SaoDiferentes(tData *data, tData *dataFinal)
{
    if (data->dia == dataFinal->dia &&
        data->mes == dataFinal->mes &&
        data->ano == dataFinal->ano)
    {
        return 0;
    }

    return 1;
}

void ImprimeData(tData *data[], int i)
{
    int dia, mes, ano;

    dia = data[i]->dia;
    mes = data[i]->mes;
    ano = data[i]->ano;

    printf("'%02d/%02d/%04d'", dia, mes, ano);
}

int EhBissexto(tData *data[], int i)
{
    if (!(data[i]->ano % 400))
    {
        return 1;
    }

    if (!(data[i]->ano % 100))
    {
        return 0;
    }

    if (!(data[i]->ano % 4))
    {
        return 1;
    }

    return 0;
}

int QtdDeDiasNoMes(tData *data[], int i)
{
    if (data[i]->mes == 1 || data[i]->mes == 3 || data[i]->mes == 5 ||
        data[i]->mes == 7 || data[i]->mes == 8 || data[i]->mes == 10 ||
        data[i]->mes == 12)
    {
        return 31;
    }

    else if (data[i]->mes == 4 || data[i]->mes == 6 ||
             data[i]->mes == 9 || data[i]->mes == 11)
    {
        return 30;
    }

    if (data[i]->mes == 2)
    {
        if (EhBissexto(data, i) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

void CorrigiData(tData *data[], int n)
{
    int dias, i = 0;

    for (i = 0; i < n; i++)
    {

        if (data[i]->mes > 12)
        {
            data[i]->mes = 12;
        }

        else if (data[i]->mes < 1)
        {
            data[i]->mes = 1;
        }

        dias = QtdDeDiasNoMes(data, i);

        if (data[i]->dia > dias)
        {
            data[i]->dia = dias;
        }

        else if (data[i]->dia < 1)
        {
            data[i]->dia = 1;
        }
    }
}