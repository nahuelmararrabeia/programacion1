#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    char edad;
    int estado;
    int dni;

}Epersona;

int stringNumerico(char [], char []);
void getString(char [], char []);
int esNumero(char []);
void agregarPersona(Epersona [], int);
void borrarPersona(Epersona[], int);
void listaOrdenada(Epersona[], int);
void inicEstado(Epersona[], int);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(Epersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(Epersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED

