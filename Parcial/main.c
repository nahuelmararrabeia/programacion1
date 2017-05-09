#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define EPROG 3
#define EPROY 5

int main()
{
    char rta='s';
    char opcion;
    int i;
    Eprogramador programador[EPROG];
    Eproyecto proyecto[EPROY];
    inicEstado(programador, EPROG);
    for(i=0;i<EPROY;i++)
    {
        proyecto[i].IdProyecto=i+1;
        strcpy(proyecto[i].nombre, "proyecto");
    }

    while(rta=='s')
    {
    printf("\n1.Alta de programador\n2.Modificar datos de programador\n3.Baja de programador\n4.Asignar programador a proyecto");
    printf("\n5.Listado de programadores\n6.Listado de proyectos\n7.Listar proyecto de programador");
    printf("\n8.Proyecto demandante\n9.Salir");
    printf("\n\nOPCION: ");
   fflush(stdin);
        scanf("%c",&opcion);
        while(opcion<'1' || opcion>'9')
        {
            printf("Opcion invalida.\nSeleccione una opcion: ");
            fflush(stdin);
            scanf("%c",&opcion);
        }
        system("cls");
    switch(opcion)
    {
    case '1':
        altaProgramador(programador, EPROG);
        break;
    case '2':
        modificarProgramador(programador,EPROG);
        break;
    case '3':
        bajaProgramador(programador,EPROG);
        break;
    case '4':
        asignarProgramador(programador,proyecto,EPROY,EPROG);
        break;
    case '5':
        listaProgramador(programador,EPROG);
        break;
    case '6':
        listaProyecto(proyecto,EPROG);
        break;
    case '7':

        break;
    case '8':

        break;
    case '9':
        rta='n';
        break;

    }




    }

    return 0;
}
