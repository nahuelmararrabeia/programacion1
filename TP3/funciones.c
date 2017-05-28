#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(EMovie movie)
{
    FILE *aRch;
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    if(fseek(aRch, 0L, SEEK_END)==0)
    {
        printf("\nIngrese el titulo: ");
        fflush(stdin);
        gets(movie.titulo);
        printf("\nIngrese el genero: ");
        fflush(stdin);
        gets(movie.genero);
        printf("\nIngrese la descripcion: ");
        fflush(stdin);
        gets(movie.descripcion);
        printf("\nIngrese la duracion: ");
        scanf("%d", &movie.duracion);
        printf("Ingrese el puntaje: ");
        scanf("%d", &movie.puntaje);
        printf("\nIngrese el link de la imagen: ");
        fflush(stdin);
        gets(movie.linkImagen);
        movie.estado=1;
        fflush(stdin);
        fwrite (&movie, sizeof(movie) , 1, aRch);
        fclose(aRch);
    }else{
        printf("Error al cargar nuevo registro");
        fclose(aRch);
        system("pause");
        return 0;
    }
}

int borrarPelicula(EMovie movie)
{
    FILE* aRch;
    char auxString;
    int flag;
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }
    rewind(aRch);
    printf("\nIngrese el titulo de la pelicula");
    fflush(stdin);
    gets(auxString);
    while(!feof(aRch))
    {
        fread(&movie,sizeof(movie), 1, aRch);
        if(strcmp(auxString,movie.titulo)==0)
        {
            flag=1;
            movie.estado=0;
            printf("Registro de pelicula borrado con exito");

        }

    }
    if(flag==0)
    {
        printf("No fue encontrado el registro buscado");
    }
    fseek(aRch,sizeof(movie)*-1,SEEK_CUR);
    fflush(stdin);
    fwrite(&movie,sizeof(movie),1, aRch);
    fclose(aRch);





}
