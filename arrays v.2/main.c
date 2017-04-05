#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 2

int main()
{
    int legajo[CANTIDAD],i,edad[CANTIDAD];
    float salario[CANTIDAD];
    char nombre[CANTIDAD][45];

    for (i=0;i<CANTIDAD;i++)
    {
        printf("Ingrese el nombre del empleado %d: ", i+1);
        fflush(stdin);
        fgets(nombre[i],45,stdin);
        //scanf(" %s", nombre[i]);
        printf("Ingrese el nro de legajo del empleado %d: ", i+1);
        scanf("%d", &legajo[i]);
        printf("Ingrese el salario del empleado %d: ", i+1);
        scanf("%f", &salario[i]);
        printf("Ingrese la edad del empleado %d: ", i+1);
        scanf("%d", &edad[i]);


    }

    for (i=0;i<CANTIDAD;i++)
    {
        printf("\nNombre del empleado %d: %s",i+1,nombre[i]);
        printf("Nro de legajo del empleado %d: %d",i+1,legajo[i]);
        printf("\nEdad  del empleado %d: %d",i+1,edad[i]);
        printf("\nSalario del empleado %d: %.0f",i+1,salario[i]);

    }
    return 0;
}
