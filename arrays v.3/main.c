#include <stdio.h>
int main()
{
    int v[3],pos,i;
    char seguir;
    for(i=0;i<3;i++)
    v[i]=0; // inicializamos vector
    do
    {
        printf("Ingrese posici¢n: ");
        scanf("%d",&pos);
        printf("Ingrese valor a cargar en el vector: ");
        scanf("%d",&v[pos]);
        printf("Desea ingresar otro dato S/N? ");
        scanf(" %c",&seguir);
    }while(seguir=='s');
    for(i=0;i<3;i++)
        printf("%d", v[i]);




    return 0;
}
