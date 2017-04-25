#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void inicEstado(Epersona persona[],  int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }

}


void agregarPersona(Epersona persona[], int tam)
{
    printf("-----------AGREGAR PERSONA-----------\n");
    int i,flagEncontro=0;
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            printf("\nNombre: ");
            fflush(stdin);
            gets(persona[i].nombre);
            stringNumerico("\nEdad: ", persona[i].edad);


            /*while(persona[i].edad<1 || persona[i].edad>150)
            {
                printf("\nEdad invalida, vuelva a ingresar la edad: ");
                scanf("%d", &persona[i].edad);
            }*/
            printf("\nDNI: ");
            scanf("%d", &persona[i].dni);

            persona[i].estado=1;
            flagEncontro=1;
            system("cls");
            printf("\n----------PERSONA AGREGADA EXITOSAMENTE!--------");
            printf("\nDNI\tNOMBRE\tEDAD\n");
            printf("%d\t%s\t%d\n", persona[i].dni,persona[i].nombre,persona[i].edad);
            break;

        }
    }
    if(flagEncontro==0)
        printf("No hay espacio disponible");
}

void borrarPersona(Epersona persona[], int tam)
{

    printf("-----------BORRAR PERSONA-----------\n");
    int i,auxDNI,flagEncontro=0;
    char opcion;
    printf("Ingrese el DNI de la persona a borrar: ");
    scanf("%d", &auxDNI);
    for(i=0; i<tam; i++)
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
                system("cls");
                printf("Registro borrado");
            }
            else
            {
                system("cls");
                printf("Operacion anulada por el usuario");
            }
        }
    }
    if(flagEncontro==0)
        printf("No se encontro el DNI ingresado");
}

void listaOrdenada(Epersona persona[], int tam)
{
    int i,j;
    Epersona auxStruct;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(persona[i].nombre, persona[j].nombre)<0)
            {
                auxStruct = persona[i];
                persona[i] = persona[j];
                persona[j] = auxStruct;

            }
        }
            printf("DNI\tNOMBRE\tEDAD\n");
            for(i=0; i<tam; i++)
            {
                if(persona[i].estado!=0)
                    printf("%d\t%s\t%d\n", persona[i].dni,persona[i].nombre,persona[i].edad);
            }
        }
}

int stringNumerico(char mensaje[], char input[])
{
    char aux[25];
    getString(mensaje, aux);
    if(esNumero(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;


}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

int esNumero(char str[])
{
    int i =0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
            i++;
    }
    return 1;
}


