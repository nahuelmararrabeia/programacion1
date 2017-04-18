#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define E 5




int main()
{
    struct Eempleado empleado[E];

    int opcion, i;
    char seguir ='s', respuesta;

    for(i=0; i<E; i++)
    {
        empleado[i].estados=0;
    }

    do
    {
        printf("1.Alta\n2.Baja\n3.Modificacion\n4.ordenar\n5. mostrar\n6.salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarEmpleado(empleado, E);
            break;
        case 2:
            eliminarEmpleado(empleado, E);
            break;
        case 3:
            modificarEmpleado(empleado, E);
            break;
        case 4:
            ordenarEmpleados(empleado, E);
        break;
        case 5:
            mostrarEmpleados(empleado, E);
            break;

        case 6:
            seguir='n';
            break;
        }
    }
    while(seguir=='s');

    return 0;
}


/*void mostrarEmpleados(int legajos[], char nombres[][20], float sueldos[], int estados[], int tam)

*/
