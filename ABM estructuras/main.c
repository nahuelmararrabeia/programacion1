#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define E 5




int main()
{
    struct Eempleado empleado;


    int legajos[E], estados[E]= {0}, i, j;
    int auxInt, flagEncontro=0;
    char nombres[E][20], auxString[20];
    float sueldos[E], auxFloat;
    int opcion;
    char seguir ='s', respuesta;


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
