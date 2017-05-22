
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int IdProyecto;
    char nombre[20];

}Eproyecto;

typedef struct {
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
    int IdCategoria;
}Eprogramador;

 typedef struct{
    int IdProgramador;
    int IdProyecto;
    int estado;
 }EProgramadorProyecto;

 typedef struct{
    int IdCategoria;
    char nombre[15];
    int precioXhora;

 }Ecategoria;





int stringNumerico(char [], char []);
void getString(char [], char []);
int esNumero(char []);
int contadorChar(char []);

void altaProgramador(Eprogramador [], Ecategoria [],int);
void bajaProgramador(Eprogramador [], int);
void listaProgramadores(Eproyecto [], Eproyecto [], EProgramadorProyecto [], int, int);
void inicEstado(Eprogramador[],int);
int stringLetras(char []);
int unicCod(Eprogramador[],int);
void graficoBarras(Eprogramador[],int);
int unicoDni(Eprogramador[], int, int);
void modificarProgramador(Eprogramador [], int );
void asignarProgramador(Eprogramador [], Eproyecto [], EProgramadorProyecto [], int , int);
void listaProyecto(Eprogramador [], Eproyecto [], EProgramadorProyecto [], int, int);
void inicProyectos(Eproyecto [] , int);
void inicCategoria(Ecategoria []);


#endif // FUNCIONES_H_INCLUDED

