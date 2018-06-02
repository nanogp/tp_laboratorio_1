//ORIGEN CON TODA SU HITORIA EN http://github.com/nanogp/TP3.git
//COPIA EN https://github.com/nanogp/Programacion1y-laboratorio1.git
//OTRA COPIA EN https://github.com/nanogp/tp_laboratorio_1.git
/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "Pelicula.h"
#include "Archivo.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************** MENUS **************************************************************/
#define MAIN_MENU_TITULO "TP3 MARIANO PONTI"
//cambiar MAIN_MENU_CANT a 6 y descomentar las opciones del menu para listar por pantalla
#define MAIN_MENU_CANT 5
#define MAIN_MENU_DETALLE1  "1. Agregar pelicula"
#define MAIN_MENU_DETALLE2  "2. Borrar pelicula"
#define MAIN_MENU_DETALLE3  "3. Modificar pelicula"
#define MAIN_MENU_DETALLE4  "4. Generar pagina web"
#define MAIN_MENU_DETALLE5  "5. Salir"
#define MAIN_MENU_DETALLE0  "0. Listado en pantalla"

int main()
{
   eMenu menuPrincipal = {/*titulo del menu*/{MAIN_MENU_TITULO},
                          /*cantidad de opciones*/MAIN_MENU_CANT,
                          /*codigos*/{1,2,3,4,5,
                                      //0
                                      },
                          /*descripciones*/{MAIN_MENU_DETALLE1,
                                            MAIN_MENU_DETALLE2,
                                            MAIN_MENU_DETALLE3,
                                            MAIN_MENU_DETALLE4,
                                            MAIN_MENU_DETALLE5,
                                            //MAIN_MENU_DETALLE0
                                            }};
   int opcion;
   char salirDelPrograma = 'N';


   /************************ ARRAYS DE ESTRUCTURAS ***********************************************/
   eMovie listadoPeliculas[PELICULA_CANT_MAX] = {};

   /************************ INICIALIZACION ******************************************************/
   eMovie_init(listadoPeliculas, PELICULA_CANT_MAX);
   eArchivoBinario_leer(ARCHIVO_BINARIO_NOMBRE, listadoPeliculas, PELICULA_CANT_MAX);

   /************************ GENERA DATOS POR HARDCODE PARA DEBUG ********************************/
   /************************ (SOLO SI EL ARCHIVO BINARIO NO EXISTE) ******************************/
   eArchivoBinario_initHardcode(listadoPeliculas);

   do
   {
      /******************** MENU PRINCIPAL *******************************************************/
      ejecutarEnConsola(LIMPIAR_PANTALLA);
      opcion = pedirOpcion(&menuPrincipal);
      switch(opcion)
      {
         case 1:
            /************ ALTA *******************************************************************/
            eMovie_alta(listadoPeliculas, PELICULA_CANT_MAX);
            eArchivoBinario_escribir(ARCHIVO_BINARIO_NOMBRE, listadoPeliculas, PELICULA_CANT_MAX);
            break;
         case 2:
            /************ BAJA *******************************************************************/
            eMovie_baja(listadoPeliculas, PELICULA_CANT_MAX);
            eArchivoBinario_escribir(ARCHIVO_BINARIO_NOMBRE, listadoPeliculas, PELICULA_CANT_MAX);
            break;
         case 3:
            /************ MODIFICACION ***********************************************************/
            eMovie_modificacion(listadoPeliculas, PELICULA_CANT_MAX);
            eArchivoBinario_escribir(ARCHIVO_BINARIO_NOMBRE, listadoPeliculas, PELICULA_CANT_MAX);
            break;
         case 4:
            /************ LISTADO WEB ************************************************************/
            eArchivoHtml_generarWeb(listadoPeliculas, PELICULA_CANT_MAX);
            break;
         case 5:
            /************ SALIR DEL PROGRAMA *****************************************************/
            salirDelPrograma = pedirConfirmacion(MSJ_SALIR_DEL_PROGRAMA);
            break;
         case 0:
            /************ LISTADO EN PANTALLA ****************************************************/
            eMovie_mostrarListado(listadoPeliculas, PELICULA_CANT_MAX);pausa();
            break;
      }

   }
   while(salirDelPrograma == 'N');
   return 0;
}
