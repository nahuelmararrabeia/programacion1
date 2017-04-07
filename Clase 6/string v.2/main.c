#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char saludo1[6];
    char saludo2[6];

    fflush(stdin);
    fgets(saludo1,6,stdin);
    fflush(stdin);
    fgets(saludo2,6,stdin);
    int cas=strcmp(*saludo1,*saludo2);

    printf("%d", &cas);

// PROBAR
//strupr(cad); pasa la cadena a matusculas
//strlwr(cad); pasa la cadena a minusculas
/* char nom[31];
char ape[31];
char nomApe[71];
nomApe[0]='\0';
strcat(nomApe,nom);
strcat(nomApe," ");
strcat(nomApe,ape);
    return 0;
}
