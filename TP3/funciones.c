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

void generarPagina()
{
    FILE* aRch;
    FILE* aRchHTML;
    int tam,i;
    tam=cantidadRegistros();
    EMovie *movies;
    EMovie movie[tam];
    movies=movie;

    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             if((aRch=fopen("movies.dat","wb+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }

    if((aRchHTML=fopen("movies.html","r+"))==NULL)
        {
             if((aRchHTML=fopen("movies.html","w+"))==NULL)
             {
                 printf("\nEl archivo no puede ser abierto");
                 return 0;
             }
        }

    for(i=0;i<tam;i++)
    {
        fread(movie[i],EMovie, 1, aRch);
        fflush(stdin);
        fprintf(aRchHTML,"%s", "<!DOCTYPE html>\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n    <!--[if lt IE 9]>\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n\n		" );
        fprintf(aRchHTML,"%s", "\n            <article class='col-md-4 article-intro'>\n                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n				<ul>\n					<li>Género:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duración:%d</li>					\n				</ul>\n               <p>%s</p>\n            </article>",*(movies+i)->linkImagen,*(movies+i)->titulo,*(movies+i)->genero,*(movies+i)->puntaje,*(movies+i)->duracion,*(movies+i)->descripcion);
        fprintf(aRchHTML,"%s","\n        </div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>");
    }



}









/*void generarPagina(EMovie* lista, char *nombre)
{
    int i,tam;
    long int ;
    tam=cantidadRegistros();
    FILE *aRch;
    EMovie* arrayMovies[tam];
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             printf("\nEl archivo no puede ser abierto");
             return 0;
        }
    rewind(aRch);
     while(!feof(aRch))
    {
        if(!feof(aRch))
            break;

        fread(&movie, sizeof(EMovie),1,aRch);
        tam++;
    }
    //fseek(aRch, 0L, SEEK_END);


    for(i=0;i<tam;i++)
    {
        fflush(stdin);
        printf("%s\t%s\t%s\t%d\t%d", lista->titulo, lista->genero,lista->descripcion,lista->duracion,lista->puntaje);
    }
    printf("%d", &tam);
}
*/
int cantidadRegistros()
{
    int tam=0;
    FILE* aRch;
    EMovie movie;
    if((aRch=fopen("movies.dat","rb+"))==NULL)
        {
             printf("\nEl archivo no puede ser abierto");
             return -1;
        }
    while(!feof(aRch))
    {

        fread(&movie, sizeof(EMovie),1,aRch);
        tam++;
         if(!feof(aRch))
            break;

    }
    fclose(aRch);
    return tam;
}
