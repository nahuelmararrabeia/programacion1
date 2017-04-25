#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define E 5

int main()
{
    char seguir='s';
    int opcion=0;
    Epersona persona[E];
    inicEstado(persona,E);

    while(seguir=='s')
    {

        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nOPCION: ");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                agregarPersona(persona, E);

                break;
            case 2:
                borrarPersona(persona,E);
                break;
            case 3:
                listaOrdenada(persona,E);
                break;
            case 4:

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
