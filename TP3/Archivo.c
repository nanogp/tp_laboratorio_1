/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Archivo.h"
#include "Pelicula.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**************************** INICIALIZACIONES ***************************************************/
void eArchivoBinario_initHardcode(eMovie* listadoPeliculas)
{
   FILE* pArchivo;

   pArchivo = fopen(ARCHIVO_BINARIO_NOMBRE, ARCHIVO_BINARIO_LECTURA);

   //SOLO SI EL ARCHIVO NO EXISTE, GENERO UNO CON DATOS DE PRUEBA HARDCODEADOS
   //ASI SE MANTIENEN LOS DATOS QUE YA ESTAN GUARDADOS EN EL ARCHIVO
   if(pArchivo == NULL)
   {
      eMovie_initHardcode(listadoPeliculas);

      pArchivo = fopen(ARCHIVO_BINARIO_NOMBRE, ARCHIVO_BINARIO_ESCRITURA);

      if(pArchivo == NULL)
      {
         imprimirEnPantalla("\nNo se pudo generar un archivo con datos de prueba");
         pausa();
      }
      else
      {
         eArchivoBinario_escribir(ARCHIVO_BINARIO_NOMBRE, listadoPeliculas, PELICULA_CANT_MAX);
      }
   }
}
//-----------------------------------------------------------------------------------------------//
int eArchivoHtml_init(char** codigoHtml)
{
   int retorno = -1;

   //pido memoria para guardar el codigo fuente de la pagina en el heap y no llenar el stack
   *codigoHtml = (char*) malloc(sizeof(char)*1000*PELICULA_CANT_MAX);

   if(codigoHtml !=NULL)
   {
      retorno = 0;

      //blanqueo variables
      strcpy(*codigoHtml, "");
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO HTML ***********************************************/
int eArchivoHtml_generarCodigoHtmlPelicula(char* htmlPelicula, eMovie* pelicula)
{
   int retorno = -1;

   if(pelicula != NULL)
   {
      retorno = 0;

      //concateno lineas
      strcat(htmlPelicula, "\n            <article class='col-md-4 article-intro'>");
      strcat(htmlPelicula, "\n                <a href='#'>");
      strcat(htmlPelicula, "\n                    <img class='img-responsive img-rounded' src='");
      strcat(htmlPelicula, (char*)&(pelicula->linkImagen));
      strcat(htmlPelicula, "' alt=''>");
      strcat(htmlPelicula, "\n                </a>");
      strcat(htmlPelicula, "\n                <h3>");
      strcat(htmlPelicula, "\n                    <a href='#'>");
      strcat(htmlPelicula, (char*)&(pelicula->titulo));
      strcat(htmlPelicula, "</a>");
      strcat(htmlPelicula, "\n                </h3>");
      strcat(htmlPelicula, "\n            <ul>");
      strcat(htmlPelicula, "\n               <li>Genero:");
      strcat(htmlPelicula, (char*)&(pelicula->genero));
      strcat(htmlPelicula, "</li>");
      strcat(htmlPelicula, "\n               <li>Puntaje:");
      strcat(htmlPelicula, intToChar(pelicula->puntaje));
      strcat(htmlPelicula, "</li>");
      strcat(htmlPelicula, "\n               <li>Duracion:");
      strcat(htmlPelicula, intToChar(pelicula->duracion));
      strcat(htmlPelicula, "</li>");
      strcat(htmlPelicula, "\n            </ul>");
      strcat(htmlPelicula, "\n                <p>");
      strcat(htmlPelicula, (char*)&(pelicula->descripcion));
      strcat(htmlPelicula, "</p>");
      strcat(htmlPelicula, "\n            </article>");

   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
char* eArchivoHtml_pedirNombreArchivo()
{
   char* retorno;

   retorno = constructorStringParametrizado(ARCHIVO_HTML_MSJ_INGRESE_NOMBRE, ARCHIVO_HTML_MSJ_REINGRESE_NOMBRE, ARCHIVO_HTML_LARGO_NOMBRE);
   strcat(retorno, ARCHIVO_HTML_EXTENSION);

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eArchivoHtml_escribirArchivoHtml(char* nombreArchivo, char* codigoHtml)
{
   int retorno = -1;
   FILE* pArchivo;

   pArchivo = fopen(nombreArchivo, ARCHIVO_HTML_ESCRITURA);

   if(pArchivo != NULL)
   {
      retorno = 0;

      fprintf(pArchivo,"%s",codigoHtml);
      fclose(pArchivo);
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eArchivoHtml_generarWeb(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;
   char* codigoHtml = NULL;
   char* nombreArchivo = NULL;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      limpiarPantallaYMostrarTitulo(ARCHIVO_GENERAR_WEB_TITULO);

      if(eMovie_informarListadoVacio(listadoPeliculas, limitePeliculas) == 0)
      {
         //inicializo el codigo fuente de la pagina
         eArchivoHtml_init(&codigoHtml);

         //copio el inicio de la pagina
         strcat(codigoHtml, "<!DOCTYPE html>\n"
                            "<html lang='en'>\n"
                            "<head>\n"
                            "    <meta charset='utf-8'>\n"
                            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
                            "    <meta name='viewport' content='width=device-width initial-scale=1'>\n"
                            "    <title>Lista peliculas</title>\n"
                            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
                            "    <link href='css/custom.css' rel='stylesheet'>\n"
                            "</head>\n"
                            "<body>\n"
                            "    <div class='container'>\n"
                            "        <div class='row'>\n");

         //copio el codigo de las peliculas
         for(i=0 ; i<limitePeliculas ; i++)
         {
            if((listadoPeliculas+i)->estado == OCUPADO)
            {
               eArchivoHtml_generarCodigoHtmlPelicula(codigoHtml, (listadoPeliculas+i));
            }
         }

         //copio el final de la pagina
         strcat(codigoHtml, "        </div>\n"
                            "    </div>\n"
                            "    <script src='js/jquery-1.11.3.min.js'></script>\n"
                            "    <script src='js/bootstrap.min.js'></script>\n"
                            "    <script src='js/ie10-viewport-bug-workaround.js'></script>\n"
                            "    <script src='js/holder.min.js'></script>\n"
                            "</body>\n"
                            "</html>\n");

         nombreArchivo = eArchivoHtml_pedirNombreArchivo();

         //llamo a escribir el archivo en disco con el codigo generado
         if(eArchivoHtml_escribirArchivoHtml(nombreArchivo, codigoHtml) == 0)
         {
             imprimirEnPantalla(ARCHIVO_MSJ_HTML_OK);
             imprimirEnPantalla(nombreArchivo);
         }
         else
         {
             imprimirEnPantalla(ARCHIVO_MSJ_HTML_ERROR);
         }
      }
   }

   pausa();
   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO BINARIO ********************************************/
int eArchivoBinario_leer(char* nombreArchivo, eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1; //error en listadoPeliculas
   int cantidadDeRegistros;
   FILE* pArchivo;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = -2; //error en archivo

      pArchivo = fopen(nombreArchivo, ARCHIVO_BINARIO_LECTURA);

      if(pArchivo != NULL)
      {
         retorno = -3; //error en carga de array

         fread(&cantidadDeRegistros, sizeof(int), 1, pArchivo);

         if(cantidadDeRegistros > 0)
         {
            fread(listadoPeliculas, sizeof(eMovie), cantidadDeRegistros, pArchivo);
            retorno = 0;
         }
      }

      fclose(pArchivo);
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eArchivoBinario_escribir(char* nombreArchivo, eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1; //error en listadoPeliculas
   int cantidadDeRegistros;
   int i;
   FILE* pArchivo;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = -2; //error en archivo

      pArchivo = fopen(nombreArchivo, ARCHIVO_BINARIO_ESCRITURA);

      if(pArchivo != NULL)
      {
         retorno = -3; //error en carga de array

         cantidadDeRegistros = eMovie_obtenerCantidadElementos(listadoPeliculas, limitePeliculas);
         fwrite(&cantidadDeRegistros, sizeof(int), 1, pArchivo); //guardo cantidad de registros

         for(i=0 ; i<limitePeliculas ; i++)
         {
            if((listadoPeliculas+i)->estado == OCUPADO)
            {
               fwrite((listadoPeliculas+i), sizeof(eMovie), 1, pArchivo);
            }
         }
      }

      fclose(pArchivo);
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
