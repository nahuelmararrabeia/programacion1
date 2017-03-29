#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int rto;
     printf("ingrese un numero: ");
     scanf("%d", &numero);

   for(i=1,i<=numero,i++)
   {
       rto=rto*i;
   }
    return rto;
}

/*toupper mayuscula char
  tolower minuscula char

  char letra1='A';
  char letra2='b';

  letra1=tolower(letra1);
  letra2=toupper(letra2);
