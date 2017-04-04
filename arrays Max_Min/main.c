#include <stdio.h>
#define MAX 5
int main()
{
int vec[MAX],i,mayor,menor,num,flag;
//Carga el vector
for(i=0;i<MAX;i++)
{
printf("Ingrese nro: ");
scanf("%d",&vec[i]);
}


// BUSQUEDA DEL MAYOR
mayor=vec[0];
for(i=0;i<MAX;i++)
{
if(vec[i]>mayor)
{
mayor=vec[i];
}
}
printf("el mayor es : %d", mayor);


//BUSQUEDA DEL MENOR
menor=vec[0];
for(i=0;i<MAX;i++)
{
if(vec[i]<menor)
{
menor=vec[i];
}
}
printf("\nel menor es: %d", menor);

//BUSCAR NUMERO
flag=0;
printf("\nIngrese numero a buscar: ");
scanf("%d",&num);
for(i=0;i<MAX;i++)
{
if(num==vec[i])
{
printf("Se encontro el numero");
flag=1;
}
}

if(flag==0)
printf("El numero no se encontro");


return 0;
}
