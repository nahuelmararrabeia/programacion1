#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* int main()
{
   struct Eempleado
   {
       int legajos;
       int estados;
       char nombres[20];
       float sueldos;
   };

   struct Eempleado empleado; //Variable estado, del tipo de dato Eempleado
   empleado.legajo=3; // utilizo el campo legajo de la variable empleado
   strcpy(empleado.nombres, "juan"); //asigno el nombre juan en el campo nombre de la variable empleado


    return 0;
} */

#include <stdio.h>
#include <string.h>
#define MAX 3
struct alumno
{
    char nombre[20];
    int nota;

};
void main(void)
{
    int i=0,j;
    struct alumno pers[MAX],aux;
    for(i=0; i<MAX; i++)
    {
        printf("ingrese el nombre del alumno: ");
        fflush(stdin);
        gets(pers[i].nombre);


    }
    for(i=0; i<MAX-1; i++)
        for(j=i+1; j<MAX; j++)
            if((strcmp(pers[i].nombre,pers[j].nombre))<0)
            {
                aux=pers[i];
                pers[i]=pers[j];
                pers[j]=aux;
                  for(i=0; i<MAX; i++)
            printf("%s", pers[i].nombre);
            }

// ...
}
