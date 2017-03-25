#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int numeroMaximo;
    int numeroMinimo;
    int contador=0;
    int acumulador=0;
    int flag=0;
    char respuesta;


    do
    {
        printf("ingrese un numero: ");
        scanf("%d", &numeroIngresado);
        if(flag==0)
        {
            numeroMaximo=numeroIngresado;
            numeroMinimo=numeroIngresado;
            flag=1;
        }

        if(numeroIngresado<numeroMinimo)
        {
            numeroMinimo=numeroIngresado;
        }

        if(numeroIngresado>numeroMaximo)
        {
            numeroMaximo=numeroIngresado;
        }

        contador++;
        acumulador=acumulador+numeroIngresado;
        printf("desea continuar? ");
        scanf(" %c", &respuesta);
        while(respuesta!='s' && respuesta!='n')
        {
            printf("respuesta invalida, desea continuar? s/n: ");
            scanf(" %c", &respuesta);
        }



    }while(respuesta=='s');

    printf("\nen numero maximo es: %d", numeroMaximo);
    printf("\nen numero minimo es: %d", numeroMinimo);
    printf("\ncantidad de numeros ingresados: %d", contador);
    printf("\nsuma de numeros ingresados: %d", acumulador);




    return 0;
}
