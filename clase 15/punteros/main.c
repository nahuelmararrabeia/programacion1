#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[3],i,aux;
    int *ptr;
    ptr=array;


    for(i=0;i<3;i++)
    {
        printf("ingresar nro: ");
        scanf("%d", ptr+i);

    }
    for(i=0;i<3;i++)
    {
        printf("%d", *(ptr+i));
    }

    return 0;
}
