#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
int codigo;
char descripcion[51];
float importe;
int cantidad, estado;
}Eproducto;

void altasProductos(Eproducto[], int);
void modificarProductos(Eproducto[], int);
void bajaProductos(Eproducto[], int);
void listarProductos(Eproducto[], int);








#endif // FUNCIONES_H_INCLUDED
