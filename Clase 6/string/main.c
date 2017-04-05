#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre[20];
    printf("ingrese nombre: ");
    //scanf(" %s", nombre);
    fgets(nombre,20,stdin); //para que no se corte en los espacios en blanco
    printf("%s", nombre);
    return 0;
}
