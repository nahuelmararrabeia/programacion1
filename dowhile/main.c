#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resultado;
    char respuesta;
    int operacion;



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
                resultado=numero1+numero2;
                break;
            case 2:
                resultado=numero1-numero2;
                break;
            case 3:
                resultado=numero1*numero2;
                break;
            case 4:
                resultado=numero1/numero2;
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
