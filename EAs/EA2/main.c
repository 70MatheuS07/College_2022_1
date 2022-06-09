#include <stdlib.h>
#include <stdio.h>

#define PI 3.1415
#define CIRCULO 5500
#define RETANGULO 3200
#define TRIANGULO 3300

typedef struct Data
{
    int dia;
    int mes;
    int ano;

} tData;

typedef struct Terreno
{
    char tipo;
    int raio;
    int comprimento;
    int largura;
    tData data;

} tTerreno;

tData LehData();

void InicializaTerrenos(tTerreno terrenos[], int num);

void LehTerrenos(tTerreno terrenos[], int num);

void CalculaImprimeAreaTerrenos(tTerreno terrenos[], int num);

int main()
{
    int num = 0;
    char lixo;

    scanf("%d%c", &num, &lixo);

    tTerreno terrenos[num];

    InicializaTerrenos(terrenos, num);

    LehTerrenos(terrenos, num);

    CalculaImprimeAreaTerrenos(terrenos, num);

    return 0;
}

tData LehData()
{
    int dia = 0, mes = 0, ano = 0;
    tData data;
  
    scanf("%d\\%d\\%d ", &dia, &mes, &ano);

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

void InicializaTerrenos(tTerreno terrenos[], int num)
{
    int i = 0;

    for (i = 0; i < num; i++)
    {
        terrenos[i].tipo = '\0';
        terrenos[i].raio = 0;
        terrenos[i].comprimento = 0;
        terrenos[i].largura = 0;
    }
}

void LehTerrenos(tTerreno terrenos[], int num)
{
    int i = 0;
    char tipoDoTerreno;
    int raioColetado = 0;
    int comprimentoColetado = 0;
    int larguraColetada = 0;
    int circulo = 0, retangulo = 0, triangulo = 0;
    tData dataLida;
    char lixo;

    for (i = 0; i < num; i++)
    {
        dataLida = LehData();
        terrenos[i].data.dia = dataLida.dia;
        terrenos[i].data.mes = dataLida.mes;
        terrenos[i].data.ano = dataLida.ano;

        scanf("%c ", &tipoDoTerreno);
        terrenos[i].tipo = tipoDoTerreno;

        if (terrenos[i].tipo == 'C')
        {
            scanf("%d%c", &raioColetado, &lixo);
            terrenos[i].raio = raioColetado;
        }

        else
        {
            scanf("%d %d%c", &comprimentoColetado, &larguraColetada, &lixo);
            terrenos[i].comprimento = comprimentoColetado;
            terrenos[i].largura = larguraColetada;
        }
    }
}

void CalculaImprimeAreaTerrenos(tTerreno terrenos[], int num)
{
    int i = 0;
    float area = 0;
    float valor = 0;

    for (i = 0; i < num; i++)
    {
        if (terrenos[i].tipo == 'C')
        {
            area = PI * terrenos[i].raio * terrenos[i].raio;

            valor = area * CIRCULO;

            printf("%.2f ; Tipo: Circular ; Data: ", area);

            printf("%02d/%02d/%04d\n", terrenos[i].data.dia, terrenos[i].data.mes, terrenos[i].data.ano);
        }

        else if (terrenos[i].tipo == 'R')
        {
            area = terrenos[i].comprimento * terrenos[i].largura;

            valor = area * RETANGULO;

            printf("%.2f ; Tipo: Circular ; Data: ", area);
            printf("%02d/%02d/%04d\n", terrenos[i].data.dia, terrenos[i].data.mes, terrenos[i].data.ano);
            
        }

        else if (terrenos[i].tipo == 'T')
        {
            area = (terrenos[i].comprimento * terrenos[i].largura) / 2;

            valor = area * TRIANGULO;

            printf("%.2f ; Tipo: Circular ; Data: ", area);
            printf("%02d/%02d/%04d\n", terrenos[i].data.dia, terrenos[i].data.mes, terrenos[i].data.ano);
        }
    }
}