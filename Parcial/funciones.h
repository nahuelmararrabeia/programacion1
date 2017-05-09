#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int IdProyecto;
    char nombre[15];

}Eproyecto;

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
    int IdCategoria;
    Eproyecto IdProy;


}Eprogramador;





int stringNumerico(char [], char []);
void getString(char [], char []);
int esNumero(char []);
int contadorChar(char []);

void altaProgramador(Eprogramador [],int);
void bajaProgramador(Eprogramador [], int);
void listaProgramadores(Eprogramador[],int);
void inicEstado(Eprogramador[],int);
int stringLetras(char []);
int unicCod(Eprogramador[],int);
void graficoBarras(Eprogramador[],int);
int unicoDni(Eprogramador[], int, int);
void modificarProgramador(Eprogramador [], int );
void asignarProgramador(Eprogramador [], Eproyecto [], int , int );
void listaProyecto(Eproyecto [], int );
#endif // FUNCIONES_H_INCLUDED


