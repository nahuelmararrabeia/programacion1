/* #include <stdio.h>
int var;
void carga(void);
void main(void)
{
int x,y,z;
var=5;
carga();
printf("%d",var);
}
void carga(void)
{
int var;
var=3;
} */  // en la funcion declara una nueva variable

#include <stdio.h>
int var;
void carga(void);
void main(void)
{
int x,y,z;
var=5;
carga();
printf("%d",var);
}
void carga(void)
{
var=3;  //usa la variable global
}
