#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void altasProductos(Eproducto producto[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(producto[i].estado==0)
        {
            producto[i].codigo=i+1;
            printf("Codigo del producto: %d", producto[i].codigo);
            printf("\nDescripcion del producto: ");
            fflush(stdin);
            gets(producto[i].descripcion);
            printf("\nIngrese el importe del producto: ");
            scanf("%f", &producto[i].importe);
            printf("\n Ingrese la cantidad del producto: ");
            scanf("%d", &producto[i].cantidad);
            producto[i].estado=1;

            break;
        }
    }
}

void modificarProductos(Eproducto producto[],int tam)
{
    int i, auxInt, opcion;

    printf("\nIngrese el codigo del producto a modificar: ");
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {
        if(auxInt==producto[i].codigo)
        {
            printf("\n1.Descripcion del producto: %s\n1.Importe del producto: %.1f\n1.Cantidad del producto: %d", producto[i].descripcion,producto[i].importe,producto[i].cantidad);
            printf("\nIngrese la opcion del dato que desea modificar: ");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                printf("\nNueva descripcion del producto: ");
                gets(producto[i].descripcion);
                break;
            case 2:
                printf("\nNuevo importe del producto: ");
                scanf("%f", &producto[i].importe);
                break;
            case 3:
                printf("\nNueva cantidad del producto: ");
                scanf("%d", &producto[i].cantidad);
                break;
            }
        }
    }
}

void listarProductos(Eproducto producto[], int tam)
{
    int i,j;
    Eproducto auxStruct;
    for(i=0; i<tam; i++)
    {
        if(producto[i].estado==1)
        {
            for(j=i+1; j==tam; j++)
            {
                if(strcmp(producto[i].descripcion, producto[j].descripcion)<0)
                {
                    auxStruct=producto[i];
                    producto[i]=producto[j];
                    producto[j]=auxStruct;
                }
            }
        }
        for(i=0; i<tam; i++)
        {
            if(producto[i].estado==1)
                printf("\nDescripcion: %s\nCodigo: %d\nCantidad: %d\nImporte: %.1f", producto[i].descripcion, producto[i].codigo, producto[i].cantidad, producto[i].importe);
        }
    }
}

void bajaProductos(Eproducto producto[], int tam)
{
    int i, auxCod;
    char opcion;
    printf("\nIngrese el codigo del producto a dar de baja: ");
    scanf("%d", &auxCod);
    for(i=0;i<tam;i++)
    {
        if(auxCod==producto[i].codigo)
        {
            printf("\nDescripcion: %s\nCodigo: %d\nCantidad: %d\nImporte: %.1f", producto[i].descripcion, producto[i].codigo, producto[i].cantidad, producto[i].importe);
            printf("Desea dar de baja este producto?");
            scanf(" %c", &opcion);
            if(opcion=='s')
            {
                producto[i].estado=0;
                printf("\nProducto dado de baja");
                break;
            }else{
                printf("\nAccion cancelada por el usuario");
                break;
            }
        }
    }
}


