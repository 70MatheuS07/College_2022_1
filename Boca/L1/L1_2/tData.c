#include "tData.h"

struct tData
{
    int dia;
    int mes;
    int ano;
};

tData *LehData()
{
    int dia, mes, ano;
    tData *data;
    data = malloc(sizeof(data));

    scanf("%d %d %d\n", &dia, &mes, &ano);

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    return data;
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

tData *AvancaParaDiaSeguinte(tData *data)
{
    data->dia += 1;

    if (data->mes > 12)
    {
        data->mes = 1;
        data->ano += 1;
    }

    else if (data->mes < 1)
    {
        data->mes = 1;
    }

    if (data->dia < 1)
    {
        data->dia = 1;
    }

    else if (data->dia > QtdDeDiasNoMes(data))
    {
        data->dia = 1;
        data->mes += 1;

        if (data->mes > 12)
        {
            data->mes = 1;
            data->ano += 1;
        }
    }

    return data;
}

void ImprimeData(tData *data)
{
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int EhBissexto(tData *data)
{
    if (!(data->ano % 400))
    {
        return 1;
    }

    if (!(data->ano % 100))
    {
        return 0;
    }

    if (!(data->ano % 4))
    {
        return 1;
    }

    return 0;
}

int QtdDeDiasNoMes(tData *data)
{
    if (data->mes == 1 || data->mes == 3 || data->mes == 5 ||
        data->mes == 7 || data->mes == 8 || data->mes == 10 ||
        data->mes == 12)
    {
        return 31;
    }

    else if (data->mes == 4 || data->mes == 6 ||
             data->mes == 9 || data->mes == 11)
    {
        return 30;
    }

    if (data->mes == 2)
    {
        if (EhBissexto(data) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

tData *CorrigiData(tData *data)
{
    int dias;

    if (data->mes > 12)
    {
        data->mes = 12;
    }

    else if (data->mes < 1)
    {
        data->mes = 1;
    }

    dias = QtdDeDiasNoMes(data);

    if (data->dia > dias)
    {
        data->dia = dias;
    }

    else if (data->dia < 1)
    {
        data->dia = 1;
    }

    return data;
}