#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Suma dos numeros recibidos como parametro
 * \param  nro1 numero a ser sumado
 * \param  nro2 numero a sumar
 * \return resultado de la suma
 *
 */

float suma2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1+nro2;
    return resultado;
}





/** \brief Resta dos numeros recibidos como parametro
 * \param  nro1 numero a ser restado
 * \param  nro2 numero a restar
 * \return resultado de la resta
 *
 */

float resta2nros(float nro1,float nro2)
{
    int resultado;
    resultado=nro1-nro2;
    return resultado;
}






/** \brief Divide dos numeros recibidos como parametro
 * \param  nro1 dividendo de la division
 * \param  nro2 divisor de la division
 * \return resultado de la division
 *
 */

float div2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1/nro2;
    return resultado;
}





/** \brief Multiplica dos numeros recibidos como parametro
 * \param  nro1 numero a ser multiplicado
 * \param  nro2 numero a multiplicar
 * \return resultado de la multiplicacion
 *
 */
float mult2nros(float nro1,float nro2)
{
    float resultado;
    resultado=nro1*nro2;
    return resultado;
}




/** \brief Calcula el factorial de un numero recibido como parametro
 * \param numero a calcular el factorial
 * \return resultado del factorial
 *
 */

float getsFact(float numero)
{
    float i,r=1;

  for (i=numero;i>1;i--)
    {
    r=r*i;
    }
    return r;

}

void cargarEmpleado(struct Eempleado empleado, int tam)
{
    int flagEncontro = 0, i;
    for(i=0; i<tam; i++)
    {
        if(empleado.estados==0)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &empleado[i].legajos);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(empleado[i].nombres);
            printf("Ingrese sueldo: ");
            scanf("%f", &empleado[i].sueldos);

            empleado[i].estados = 1;
            flagEncontro = 1;

            break;
        }
    }
    if(!flagEncontro)
    {
        printf("No hay espacio suficiente!!!");
    }
}

 void eliminarEmpleado(struct Eempleado empleado, int tam)
    {
        int flagEncontro=0, i;
        int auxInt;
        char respuesta;
        printf("Ingrese legajo: ");
        scanf("%d", &auxInt);
        for(i=0; i<tam; i++)
        {
            if(estados[i]==1)
            {
                if(auxInt == empleado[i].legajos)
                {
                    printf("%d\t%s\t%.2f\n", empleado[i].legajos,empleado[i].nombres,empleado[i].sueldos);

                    printf("Esta seguro de eliminar el dato s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        empleado[i].estados = 0;
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario!!!");
                    }

                    flagEncontro=1;
                    break;

                }

            }
        }
        if(flagEncontro==0)
        {
            printf("Dato inexistente");
        }
    }

void modificarEmpleado(struct Eempleado empleado, int tam)
{
    int flagEncontro=0, i, auxInt;
    float auxFloat;
    char respuesta;
            printf("Ingrese legajo: ");
            scanf("%d", &auxInt);
            for(i=0; i<tam; i++)
            {
                if(empleado[i].estados==1)
                {
                    if(auxInt == empleado[i].legajos)
                    {
                        printf("%d\t%s\t%.2f\n", empleado[i].legajos,empleado[i].nombres,empleado[i].sueldos);
                        printf("Ingrese sueldo a modificar");
                        scanf("%f", &auxFloat);
                        printf("Esta seguro de realizar la modificacion s/n: ");
                        respuesta = getche();
                        if(respuesta=='s')
                        {
                            empleado[i].sueldos = auxFloat;
                        }
                        else
                        {
                            printf("Accion cancelada por el usuario!!!");
                        }

                        flagEncontro=1;
                        break;

                    }

                }
            }
            if(flagEncontro==0)
            {
                printf("Dato inexistente");
            }

}

void ordenarEmpleados(struct Eempleado empleado, int tam)
{
    int i,j,auxInt;
    float auxFloat;
    char auxString;
    for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(strcmp(empleado[i].nombres, empleado[j].nombres)>0)
                    {
                        strcpy(auxString, empleado[i].nombres);
                        strcpy(empleado[i].nombres, empleado[j].nombres);
                        strcpy(empleado[j].nombres, auxString);

                        auxInt=legajos[i];
                        empleado[i].legajos = empleado[j].legajos;
                        empleado[j].legajos = auxInt;

                        auxFloat = empleado[i].sueldos;
                        empleado[i].sueldos = empleado[j].sueldos;
                        empleado[j].sueldos = auxFloat;

                        auxInt=empleado[i].estados;
                        empleado[i].estados = empleado[j].estados;
                        empleado[j].estados = auxInt;


                    }
                    else
                    {
                        if(strcmp(empleado[i].nombres, empleado[j].nombres)==0)
                        {
                            if(empleado[i].legajos>empleado[j].legajos)
                            {
                                auxInt=empleado[i].legajos;
                                empleado[i].legajos = empleado[j].legajos;
                                empleado[j].legajos = auxInt;

                                auxFloat = empleado[i].sueldos;
                                empleado[i].sueldos = empleado[j].sueldos;
                                empleado[j].sueldos = auxFloat;

                                auxInt=empleado[i].estados;
                                empleado[i].estados = empleado[j].estados;
                                empleado[j].estados = auxInt;
                            }
                        }
                    }
                }
            }

}

void mostrarEmpleados(struct Eempleado empleado, int tam)
{
    int i;
printf("Legajo\tnombre\tsueldo\n");
            for(i=0; i<tam; i++)
            {
                if(empleado[i].estados!=0)
                    printf("%d\t%s\t%.2f\n", empleado[i].legajos,empleado[i].nombres,empleado[i].sueldos);
            }


}
