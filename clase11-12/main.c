#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define E 1000

int main()
{
    Eproducto producto[E];
    int opcion,i;
    char seguir='s';
    for(i=0;i<E;i++)
    producto[i].estado=0;

    do{
    printf("1.Altas\n2.Modificar\n3.Baja\n4.Listar\n5.Salir\n\nSeleccione una opcion: ");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        altasProductos(producto,E);
        break;
    case 2:
        modificarProductos(producto,E);
        break;
    case 3:
        bajaProductos(producto,E);

        break;
    case 4:
        listarProductos(producto, E);

        break;
    case 5:
        seguir='n';

        break;
    }
    }while(seguir=='s');


    return 0;
}
