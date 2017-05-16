#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int nro;
    char letras[15];
}estructura;

int main()
{
    int i,aux;
    estructura variable;
    estructura puntero;
    puntero=variable;

        printf("ingrese nro: ");
        scanf("%d", aux);
        puntero->nro=aux;

        printf("\ningrese letras: ");
        fflush(stdin);
        gets(puntero->letras);

    for(i=0; i<2; i++)
    {
        printf(" nro: %d", puntero->nro);
        printf(" \nletras: %s", puntero->letras);
    }


    return 0;
}
