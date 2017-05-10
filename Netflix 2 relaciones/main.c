#include <stdio.h>
#include <stdlib.h>
#define C 10
#define S 5

/*
1- mostrar series
2- mostrar clientes
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
    int idSerie;
}eCliente;

typedef struct
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConSerie(eCliente[], eSerie[], int, int);
void mostrarSeriesConClientes(eCliente[], eSerie[], int, int);
void mostrarSerieLoser(eCliente[], eSerie[], int, int);
void mostrarClientesTBBT(eCliente[], eSerie[], int, int);
int main()
{

    eSerie series[S];
    eCliente clientes[C];

    cargarSeries(series);
    cargarClientes(clientes);

    mostrarSeries(series, S);
    mostrarClientes(clientes, C);

    mostrarClientesConSerie(clientes, series, C,S);

    mostrarSeriesConClientes(clientes,series,C,S);

    mostrarSerieLoser(clientes, series,C,S);
    mostrarClientesTBBT(clientes, series,C,S);

    return 0;
}

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
     char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]={100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarSeries(eSerie series[], int tam)
{
    int i;
    printf("SERIES:\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t%10s\t%d\t%15s\n", series[i].idSerie, series[i].titulo, series[i].temporadas, series[i].genero);
    }

}
void mostrarClientes(eCliente clientes[], int tam)
{
    int i;
    printf("\n********************************************************\nCLIENTES:\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t%15s\t\t%d\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].idSerie);
    }

}

void mostrarClientesConSerie(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    int i, j;
    char titulo[25];

     printf("\n********************************************************\nCLIENTES c/ TITULO:\n");
    for(i=0; i<tamC; i++)//recorre los clientes
    {
        printf("%d\t%15s\t", clientes[i].idCliente, clientes[i].nombre);
        for(j=0; j<tamS; j++)//las series
        {
            if(clientes[i].idSerie==series[j].idSerie)//coinciden
            {
                printf("%s\n", series[j].titulo);
                //strcpy(titulo, series[j].titulo);
                break;
            }
        }

       // printf("%d\t%15s\t%s\n", clientes[i].idCliente, clientes[i].nombre, titulo);

    }
}

void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    int i, j;
    printf("\n********************************************************\nSERIE c/ CLIENTES:\n");
    for(i=0; i<tamS; i++)
    {
        printf("-%s\n", series[i].titulo);
        for(j=0; j<tamC; j++)
        {
            if(series[i].idSerie == clientes[j].idSerie)
            {
                printf("\t* %s\n", clientes[j].nombre);
            }
        }
    }
}

void mostrarClientesTBBT(eCliente clientes[], eSerie series[], int tamC, int tamS)
{

    int i, j, idSearch;

    //Busco codigo de TBBT

    for(i=0; i<tamS; i++)
    {
        if(strcmp(series[i].titulo,"TBBT")==0)
        {
            idSearch = series[i].idSerie;
            break;
        }
    }


  printf("\n********************************************************\nVen TBBT\n");

        for(j=0; j<tamC; j++)
        {
            if(idSearch == clientes[j].idSerie)
            {
                printf("\t*%s\n", clientes[j].nombre);
            }
        }


}

void mostrarSerieLoser(eCliente clientes[], eSerie series[], int tamC, int tamS)
{
    eLoser loser[5];
    int i, j;
    int minimo, flag=0;

    for(i=0; i<tamS; i++)
    {
        loser[i].idSerie=series[i].idSerie;
        loser[i].cont = 0;

        for(j=0; j<tamC; j++)
        {
            if(loser[i].idSerie == clientes[j].idSerie)
            {
                loser[i].cont++;
            }
        }
    }

    for(i=0; i<tamS; i++)
    {
        if(flag==0 || loser[i].cont<minimo)
        {
            minimo = loser[i].cont ;
            flag = 1;
        }
    }

    //printf("MINIMO: %d", minimo);
    printf("\n********************************************************\nLa serie Loser es:\n");
    for(i=0; i<5; i++)
    {
       if(loser[i].cont == minimo)
       {
          //printf("%d\t%d\n", loser[i].idSerie, loser[i].cont);
          for(j=0; j=tamS; j++)
          {
              if(loser[i].idSerie == series[i].idSerie)
              {
                  printf("%s\n", series[i].titulo);
                  break;
              }
          }
       }

    }


}


