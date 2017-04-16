#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Eempleado{
    int legajos;
    char nombres[20];
    float sueldos;
    int estados;
    };



float suma2nros(float,float);
float resta2nros(float,float);
float div2nros(float,float);
float mult2nros(float,float);
float getsFact(float);
void cargarEmpleado(struct Eempleado, int);
void eliminarEmpleado(struct Eempleado, int);
void modificarEmpleado(struct Eempleado, int);
void ordenarEmpleados(struct Eempleado, int);
void mostrarEmpleados(struct Eempleado, int);




#endif // FUNCIONES_H_INCLUDED
