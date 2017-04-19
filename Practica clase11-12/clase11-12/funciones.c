#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void altasProductos(Eproducto producto[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(producto[i].estado==0){
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

    printf("Ingrese el codigo del producto a modificar: ");
    scanf("%d", auxInt);
    for(i=0;i<tam;i++)
    {
        if(auxInt==producto[i].codigo)
        {
        printf("\n1.Descripcion del producto: %s\n1.Importe del producto: %.1f\n1.Cantidad del producto: %d", producto[i].descripcion,producto[i].importe,producto[i].cantidad);
        printf("\nIngrese la opcion del dato que desea modificar: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("nueva descripcion del producto: ");
                gets(producto[i].descripcion);
                break;
            case 2:
                printf("nuevo importe del producto: ");
                scanf("%f", &producto[i].importe);
                break;
            case 3:
                printf("nueva cantidad del producto: ");
                scanf("%d", &producto[i].cantidad);
                break;
        }
        }
    }
}


