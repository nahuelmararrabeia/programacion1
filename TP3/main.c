#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,tam;
    EMovie movie;
    EMovie *lista;
    lista=(EMovie *)malloc(sizeof(EMovie));


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie);
                break;
            case 2:
                borrarPelicula(movie);
                break;
            case 3:
                generarPagina();
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
