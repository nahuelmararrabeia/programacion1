#include <stdio.h>
#include <stdlib.h>

int suma(int numero1, int numero2);
int resta(int numero1, int numero2);
int division(int numero1, int numero2);
int multiplicacion(int numero1, int numero2);

int main()
{
    int resultado;
    do{
            system("cls");
            printf("para sumar presione '1'");
            printf("\npara restar presione '2'");
            printf("\npara multiplicar presione '3'");
            printf("\npara dividir presione '4'");
            printf("\nindique la operacion: ");
            scanf("%d", &operacion);

            printf("ingrese un numero: ");
            scanf("%d",&numero1);
            printf("ingrese otro numero: ");
            scanf("%d",&numero2);
            switch(operacion)
            {
            case 1:
                resultado=suma(numero1, numero2);
                break;
            case 2:
                resultado=resta(numero1, numero2);
                break;
            case 3:
                resultado=division(numero1,numero2);
                break;
            case 4:
                resultado=multiplicacion(numero1, numero2);
                break;
            }

            printf("%d", resultado);
            printf("\ncontinuar? ");

            scanf(" %c",&respuesta);

        while(respuesta!='s' && respuesta!='n')
    {
        printf("respuesta invalida, ingrese s/n: ");
        scanf(" %c", &respuesta);
    }


    }while(respuesta=='s');
    return 0;
}

