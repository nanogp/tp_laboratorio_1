/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Pelicula.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <string.h>


/**************************** INICIALIZACIONES ***************************************************/
void eMovie_initHardcode(eMovie* listadoPeliculas)
{
   //genero datos de prueba
   char titulos[3][50] = {{"Back to the future"},{"The Godfather"},{"Forrest Gump"}};
   char generos[3][50] = {{"Aventura"},{"Crime, Drama"},{"Drama, Romance"}};
   int puntajes[3] = {86,92,88};
   int duraciones[3] = {116,115,142};
   char descripciones[3][500] = {{"A young man is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents unite in order to save his own existence"},
                                 {"The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son."},
                                 {"The presidencies of Kennedy and Johnson, Vietnam, Watergate, and other history unfold through the perspective of an Alabama man with an IQ of 75"}
                                 };
   char linksImagenes[3][500] = {{"http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg"},
                                 {"https://ia.media-imdb.com/images/M/MV5BM2MyNjYxNmUtYTAwNi00MTYxLWJmNWYtYzZlODY3ZTk3OTFlXkEyXkFqcGdeQXVyNzkwMjQ5NzM@._V1_UY268_CR3,0,182,268_AL_.jpg"},
                                 {"https://ia.media-imdb.com/images/M/MV5BNWIwODRlZTUtY2U3ZS00Yzg1LWJhNzYtMmZiYmEyNmU1NjMzXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_UY268_CR1,0,182,268_AL_.jpg"}
                                 };

   //asigno datos al listado
   for(int i = 0; i<3 ; i++)
   {
      strcpy((char*)&((listadoPeliculas+i)->titulo), (char*)(titulos+i));
      strcpy((char*)&((listadoPeliculas+i)->genero), (char*)(generos+i));
      strcpy((char*)&((listadoPeliculas+i)->descripcion), (char*)(descripciones+i));
      strcpy((char*)&((listadoPeliculas+i)->linkImagen), (char*)(linksImagenes+i));
      (listadoPeliculas+i)->puntaje = *(puntajes+i);
      (listadoPeliculas+i)->duracion = *(duraciones+i);
      (listadoPeliculas+i)->idPelicula = i+1;
      (listadoPeliculas+i)->estado = OCUPADO;
   }

   //ordeno por titulo
   eMovie_ordenar(listadoPeliculas, PELICULA_CANT_MAX, PELICULA_ORDEN_TITULO);
}
//-----------------------------------------------------------------------------------------------//
int eMovie_init(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      for(i=0 ; i<limitePeliculas ; i++)
      {
         (listadoPeliculas+i)->estado= LIBRE;
         (listadoPeliculas+i)->idPelicula= 0;
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BUSQUEDA ***********************************************************/
int eMovie_buscarLugarLibre(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -2;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = -1;
      for(i=0 ; i<limitePeliculas ; i++)
      {
         if((listadoPeliculas+i)->estado == LIBRE)
         {
            retorno = i;
            break;
         }
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_siguienteId(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      for(i=0; i<limitePeliculas; i++)
      {
         if((listadoPeliculas+i)->estado == OCUPADO)
         {
            if(((listadoPeliculas+i)->idPelicula) > retorno)
            {
                retorno = (listadoPeliculas+i)->idPelicula;
            }
         }
      }
   }

   return (retorno+1);
}
//-----------------------------------------------------------------------------------------------//
int eMovie_estaVacio(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 1;
      for(i=0 ; i<limitePeliculas ; i++)
      {
         if((listadoPeliculas+i)->estado == OCUPADO)
         {
            retorno = 0;
            break;//con el primer ocupado ya se que no esta vacio
         }
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_informarListadoVacio(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = eMovie_estaVacio(listadoPeliculas, limitePeliculas);
      if(retorno == 1)
      {
         imprimirEnPantalla(PELICULA_MSJ_LISTA_VACIA);
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_buscarPorId(eMovie* listadoPeliculas, int limitePeliculas, int idPelicula)
{
   int retorno = -2;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = -1;
      for(i=0 ; i<limitePeliculas ; i++)
      {
         if((listadoPeliculas+i)->estado == OCUPADO && (listadoPeliculas+i)->idPelicula == idPelicula)
         {
            retorno = i;
            break;
         }
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_pedirIdYBuscar(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -2;
   int idPelicula;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = -1;
      do
      {
         eMovie_mostrarListado(listadoPeliculas, limitePeliculas);
         idPelicula = eMovie_pedirId();
         retorno = eMovie_buscarPorId(listadoPeliculas, limitePeliculas, idPelicula);
         if(retorno < 0)
         {
            imprimirEnPantalla(PELICULA_MSJ_ID_NO_EXISTE);
            pausa();
         }
      }
      while(retorno < 0);
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_obtenerCantidadElementos(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;

      for(i=0 ; i<limitePeliculas ; i++)
      {
         if((listadoPeliculas+i)->estado == OCUPADO)
         {
            retorno++;
         }
      }
   }

   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
int eMovie_pedirId()
{
   return pedirIntValido(PELICULA_MSJ_INGRESE_ID, PELICULA_MSJ_REINGRESE_ID, PELICULA_ID_MIN, PELICULA_ID_MAX);
}
//-----------------------------------------------------------------------------------------------//
int eMovie_pedirDuracion()
{
   return pedirIntValido(PELICULA_MSJ_INGRESE_DURACION, PELICULA_MSJ_REINGRESE_DURACION, PELICULA_DURACION_MIN, PELICULA_DURACION_MAX);
}
//-----------------------------------------------------------------------------------------------//
int eMovie_pedirPuntaje()
{
   return pedirIntValido(PELICULA_MSJ_INGRESE_PUNTAJE, PELICULA_MSJ_REINGRESE_PUNTAJE, PELICULA_PUNTAJE_MIN, PELICULA_PUNTAJE_MAX);
}
//-----------------------------------------------------------------------------------------------//
void eMovie_pedirTitulo(char* retorno)
{
   pedirStringValido(retorno, PELICULA_MSJ_INGRESE_TITULO, PELICULA_MSJ_REINGRESE_TITULO, PELICULA_LARGO_TITULO);
}
//-----------------------------------------------------------------------------------------------//
void eMovie_pedirGenero(char* retorno)
{
   pedirStringValido(retorno, PELICULA_MSJ_INGRESE_GENERO, PELICULA_MSJ_REINGRESE_GENERO, PELICULA_LARGO_GENERO);
}
//-----------------------------------------------------------------------------------------------//
void eMovie_pedirDescripcion(char* retorno)
{
   pedirStringValido(retorno, PELICULA_MSJ_INGRESE_DESCRIPCION, PELICULA_MSJ_REINGRESE_DESCRIPCION, PELICULA_LARGO_DESCRIPCION);
}
//-----------------------------------------------------------------------------------------------//
void eMovie_pedirLinkImagen(char* retorno)
{
   pedirStringValido(retorno, PELICULA_MSJ_INGRESE_LINK, PELICULA_MSJ_REINGRESE_LINK, PELICULA_LARGO_LINK);
}
//-----------------------------------------------------------------------------------------------//
eMovie eMovie_pedirIngreso(eMovie* listadoPeliculas, int limitePeliculas)
{
   eMovie retorno;

   retorno.idPelicula = eMovie_siguienteId(listadoPeliculas, limitePeliculas);

   eMovie_pedirTitulo((char*)&(retorno.titulo));

   eMovie_pedirGenero((char*)&(retorno.genero));

   retorno.duracion = eMovie_pedirDuracion();

   eMovie_pedirDescripcion((char*)&(retorno.descripcion));

   retorno.puntaje = eMovie_pedirPuntaje();

   eMovie_pedirLinkImagen((char*)&(retorno.linkImagen));

   retorno.estado = OCUPADO;

   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** LISTADO DE DATOS ***************************************************/
int eMovie_mostrarUno(eMovie* pelicula)
{
    int retorno = -1;

    if(pelicula != NULL)
    {
      retorno = 0;
      printf(PELICULA_MOSTRAR_UNO_MASCARA, pelicula->idPelicula, pelicula->titulo, pelicula->genero, pelicula->puntaje, pelicula->duracion);
    }
    return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_mostrarUnoCompleto(eMovie* pelicula)
{
    int retorno = -1;

    if(pelicula != NULL)
    {
      retorno = 0;
      printf(PELICULA_MOSTRAR_UNO_COMPLETO_MASCARA, pelicula->idPelicula, pelicula->titulo, pelicula->genero, pelicula->puntaje, pelicula->duracion, pelicula->descripcion, pelicula->linkImagen);
    }
    return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_mostrarListado(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   int i;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      limpiarPantallaYMostrarTitulo(PELICULA_LISTADO_TITULO);

      if(eMovie_informarListadoVacio(listadoPeliculas, limitePeliculas) == 0)
      {
         imprimirEnPantalla(PELICULA_MOSTRAR_UNO_CABECERA);

         for(i=0 ; i<limitePeliculas ; i++)
         {
            if((listadoPeliculas+i)->estado == OCUPADO)
            {
               eMovie_mostrarUno(listadoPeliculas+i);
            }

            if((i+1)%10 == 0)//cada 10 registros hago pausa y vuelvo a mostrar titulo
            {
               pausa();
               limpiarPantallaYMostrarTitulo(PELICULA_LISTADO_TITULO);
            }
         }
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ALTA DE REGISTRO ***************************************************/
int eMovie_alta(eMovie* listadoPeliculas, int limitePeliculas)
{
   int retorno = -1;
   eMovie registro;
   char confirmacion;
   int posicion;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      limpiarPantallaYMostrarTitulo(PELICULA_ALTA_TITULO);

      posicion = eMovie_buscarLugarLibre(listadoPeliculas, limitePeliculas);
      if(posicion < 0)
      {
         imprimirEnPantalla(PELICULA_MSJ_NO_MAS_LUGAR);
      }
      else if(posicion < 0)
      {
         retorno = posicion;
      }
      else
      {
         registro = eMovie_pedirIngreso(listadoPeliculas, limitePeliculas);

         limpiarPantallaYMostrarTitulo(PELICULA_ALTA_TITULO);
         eMovie_mostrarUnoCompleto(&registro);

         confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

         if(confirmacion == 'S')
         {
            *(listadoPeliculas+posicion) = registro;
            eMovie_ordenar(listadoPeliculas, limitePeliculas, PELICULA_ORDEN_TITULO);
            imprimirEnPantalla(PELICULA_MSJ_ALTA_OK);
         }
         else
         {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
         }
      }
      pausa();
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//


/**************************** MODIFICACION DE REGISTRO *******************************************/
int eMovie_modificarUno(eMovie* registro)
{
   int retorno = -1;
   int huboCambios = 0;
   eMenu menuModificar = {/*titulo del menu*/{PELICULA_MENU_MODIFICAR_UNO_TITULO},
                          /*cantidad de opciones*/PELICULA_MENU_MODIFICAR_UNO_CANT,
                          /*codigos*/{1,2,3,4,5,6,9,0},
                          /*descripciones*/{PELICULA_MENU_MODIFICAR_UNO_DETALLE1,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE2,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE3,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE4,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE5,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE6,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE9,
                                            PELICULA_MENU_MODIFICAR_UNO_DETALLE0}};
   int opcion;
   char finalizar = 'N';

   if(registro != NULL)
   {
      do
      {
         limpiarPantallaYMostrarTitulo(MSJ_MODIFICANDO_REGISTRO);
         imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);

         eMovie_mostrarUnoCompleto(registro);
         saltoDeLinea();

         opcion = pedirOpcion(&menuModificar);
         switch(opcion)
         {
            case 1:
               eMovie_pedirTitulo((char*)&(registro->titulo));
               huboCambios = 1;
               break;
            case 2:
               eMovie_pedirGenero((char*)&(registro->genero));
               huboCambios = 1;
               break;
            case 3:
               registro->duracion = eMovie_pedirDuracion();
               huboCambios = 1;
               break;
            case 4:
               eMovie_pedirDescripcion((char*)&(registro->descripcion));
               huboCambios = 1;
               break;
            case 5:
               registro->puntaje = eMovie_pedirPuntaje();
               huboCambios = 1;
               break;
            case 6:
               eMovie_pedirLinkImagen((char*)&(registro->linkImagen));
               huboCambios = 1;
               break;
            case 9:
               if(huboCambios == 0)//si finalizo pero no cambio nada
               {
                  imprimirEnPantalla(PELICULA_MSJ_MODIFICACION_SIN_CAMBIOS);
               }
               finalizar = 'S';
               retorno = huboCambios;
               break;
            case 0:
               finalizar = 'S';
               huboCambios = 0;
               retorno = huboCambios;
               break;
         }
      }
      while(finalizar == 'N');
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
int eMovie_modificacion(eMovie* listadoPeliculas, int limitePeliculas)
{
   eMovie registro;
   char confirmacion;
   int posicion;
   int huboCambios;

   limpiarPantallaYMostrarTitulo(PELICULA_MODIFICACION_TITULO);

   if(eMovie_informarListadoVacio(listadoPeliculas, limitePeliculas) == 0)
   {
      posicion = eMovie_pedirIdYBuscar(listadoPeliculas, limitePeliculas);
      //traigo el registro del id elegido para no pisar directo sobre el listadoPeliculas
      registro = *(listadoPeliculas+posicion);

      huboCambios = eMovie_modificarUno(&registro);
      if(huboCambios == 1)
      {
         /*if(aca se pregunta si hubo cambios que requieran reprocesar)
         {
            se recalcularian promedios por ejemplo
         }
         */

         limpiarPantallaYMostrarTitulo(PELICULA_MODIFICACION_TITULO);

         imprimirEnPantalla(PELICULA_MSJ_REGISTRO_ACTUAL);
         eMovie_mostrarUnoCompleto(listadoPeliculas+posicion);

         imprimirEnPantalla(PELICULA_MSJ_REGISTRO_MODIFICADO);
         eMovie_mostrarUnoCompleto(&registro);

         saltoDeLinea();
         confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
      }
      else
      {
         confirmacion = 'N';
      }

      if(confirmacion == 'S')
      {
         listadoPeliculas[posicion] = registro;
         eMovie_ordenar(listadoPeliculas, limitePeliculas, PELICULA_ORDEN_TITULO);


         imprimirEnPantalla(PELICULA_MSJ_MODIFICACION_OK);
      }
      else
      {
         imprimirEnPantalla(MSJ_CANCELO_GESTION);
      }
   }

   ejecutarEnConsola(HACER_PAUSA);
   return huboCambios;
}
//-----------------------------------------------------------------------------------------------//


/**************************** BAJA DE REGISTRO ****************************************************/
int eMovie_baja(eMovie* listadoPeliculas, int limitePeliculas)
{
   char confirmacion;
   int posicion;
   int idPelicula;

   limpiarPantallaYMostrarTitulo(PELICULA_BAJA_TITULO);

   if(eMovie_informarListadoVacio(listadoPeliculas, limitePeliculas) == 0)
   {
      limpiarPantallaYMostrarTitulo(PELICULA_BAJA_TITULO);

      posicion = eMovie_pedirIdYBuscar(listadoPeliculas, limitePeliculas);

      limpiarPantallaYMostrarTitulo(PELICULA_BAJA_TITULO);
      imprimirEnPantalla(PELICULA_MOSTRAR_UNO_CABECERA);
      eMovie_mostrarUno(listadoPeliculas+posicion);

      confirmacion = pedirConfirmacion(PELICULA_MSJ_CONFIRMAR_BAJA);

      if(confirmacion == 'S')
      {
         idPelicula = (listadoPeliculas+posicion)->idPelicula;
         (listadoPeliculas+posicion)->estado = LIBRE;
         imprimirEnPantalla(PELICULA_MSJ_BAJA_OK);
      }
      else
      {
         imprimirEnPantalla(MSJ_CANCELO_GESTION);
      }
   }

   ejecutarEnConsola(HACER_PAUSA);
   return idPelicula;
}
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
int eMovie_ordenar(eMovie* listadoPeliculas, int limitePeliculas, char* orden)
{
   int retorno = -1;
   int i;
   int j;
   eMovie aux;

   if(listadoPeliculas != NULL && limitePeliculas > 0)
   {
      retorno = 0;
      if(strcmp(orden, PELICULA_ORDEN_ID) == 0)
      {
         for(i=0 ; i<limitePeliculas-1 ; i++)
         {
            for(j=i+1 ; j<limitePeliculas ; j++)
            {
               if((listadoPeliculas+i)->idPelicula > (listadoPeliculas+j)->idPelicula)
               {
                  aux = *(listadoPeliculas+i);
                  *(listadoPeliculas+i) = *(listadoPeliculas+j);
                  *(listadoPeliculas+j) = aux;
               }
            }
         }
      }
      else if(strcmp(orden, PELICULA_ORDEN_ID_DESC) == 0)
      {
         for(i=0 ; i<limitePeliculas-1 ; i++)
         {
            for(j=i+1 ; j<limitePeliculas ; j++)
            {
               if((listadoPeliculas+i)->idPelicula < (listadoPeliculas+j)->idPelicula)
               {
                  aux = *(listadoPeliculas+i);
                  *(listadoPeliculas+i) = *(listadoPeliculas+j);
                  *(listadoPeliculas+j) = aux;
               }
            }
         }
      }
      else if(strcmp(orden, PELICULA_ORDEN_TITULO) == 0)
      {
         for(i=0 ; i<limitePeliculas-1 ; i++)
         {
            for(j=i+1 ; j<limitePeliculas ; j++)
            {
               if(strcmpi((listadoPeliculas+i)->titulo, (listadoPeliculas+j)->titulo) > 0)
               {
                  aux = *(listadoPeliculas+i);
                  *(listadoPeliculas+i) = *(listadoPeliculas+j);
                  *(listadoPeliculas+j) = aux;
               }
            }
         }
      }
      else if(strcmp(orden, PELICULA_ORDEN_TITULO_DESC) == 0)
      {
         for(i=0 ; i<limitePeliculas-1 ; i++)
         {
            for(j=i+1 ; j<limitePeliculas ; j++)
            {
               if(strcmpi((listadoPeliculas+i)->titulo, (listadoPeliculas+j)->titulo) < 0)
               {
                  aux = *(listadoPeliculas+i);
                  *(listadoPeliculas+i) = *(listadoPeliculas+j);
                  *(listadoPeliculas+j) = aux;
               }
            }
         }
      }
   }
   return retorno;
}
//-----------------------------------------------------------------------------------------------//
