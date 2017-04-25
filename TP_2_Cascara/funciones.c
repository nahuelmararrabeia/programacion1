#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void starEst(Epersona persona[],  int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        persona[i].estado=0;
    }

}


void agregarPersona(Epersona persona[], int tam)
{
    int i,flagEncontro=0;
    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==0)
        {
            printf("\nNombre: ");
            fflush(stdin);
            gets(persona[i].nombre);
            printf("\nEdad: ");
            scanf("%d",persona[i].edad);
            printf("\nDNI: ");
            scanf("d", persona[i].dni);

            persona[i].estado=1;
            flagEncontro=1;
        }
    }
    if(flagEncontro==0)
    printf("No hay espacio disponible");
}

void borrarPersona(Epersona persona[], int tam)
{
    int i,auxDNI,flagEncontro=0;
    char opcion;
    printf("Ingrese el DNI de la persona a borrar: ");
    scanf("%d", &auxDNI);
    for(i=0;i<tam;i++)
    {
        if(auxDNI==persona[i].dni)
        {
            flagEncontro=1;
            printf("%s\t%d\t%d", persona[i].nombre, persona[i].edad,persona[i].dni);
            printf("\nDesea eliminar este registro?(s/n)");
            scanf(" %c", &opcion);
            while(opcion!='n' && opcion!='s')
            {
                printf("Respuesta invalida. Desea eliminar este registro?(s/n)\n");
                scanf("%d", &opcion);
            }
            if(opcion=='n')
            {
                persona[i].estado=0;
                printf("Registro borrado");
            }else
            {
                printf("Operacion anulada por el usuario");
            }
        }
    }
    if(flagEncontro==0)
        printf("No se encontró el DNI ingresado");
}

void listaOrdenada(Epersona persona[], int tam)
{
    int i,j;
    Epersona auxStruct;
    for(i=0;i<tam;i++)
    {
        if(persona[i].estado=1)
        {
            for(j=i+1;j==tam;j++)
            {
                if(strcmp(persona[i].nombre, persona[j].nombre)<0)
                    auxStruct=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxStruct;
            }
        }
    }
    for(i=0;i<tam;i++)
        printf(printf("%s\t%d\t%d", persona[i].nombre, persona[i].edad,persona[i].dni);
}
