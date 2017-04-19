#include <stdio.h>
#include <stdlib.h>

int main()
{
    float matriz[2][3];
    float aux;
    int i,j;

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("M[%d][%d]: ",i,j);
            scanf("%f",&aux);
            matriz[i][j]=aux;
        }
    }
     for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("\n%.0f", matriz[i][j]);
            }
        }


    return 0;
}
    //printf("%d", sizeof(float));
