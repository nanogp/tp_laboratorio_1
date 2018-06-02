#pragma once
#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

/**************************** MACROS *************************************************************/
#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro
#define LIMPIAR_PANTALLA "cls"
#define HACER_PAUSA "pause"

/**************************** LIMITES ************************************************************/
#define TITULO_LARGO_MAX 1000
#define STRING_LARGO_MAX 1000

/**************************** CONSTANTES *********************************************************/
#define OCUPADO 1
#define LIBRE 0

/**************************** MENSAJES INFO ******************************************************/
#define MSJ_CONFIRMA_CORRECTOS "Confirma que los datos ingresados son correctos?"
#define MSJ_CANCELO_GESTION "\nSe cancelo la gestion"
#define MSJ_MODIFICANDO_REGISTRO "MODIFICANDO REGISTRO"
#define MSJ_DATOS_A_MODIFICAR "\nDatos a modificar:\n"
#define MSJ_SALIR_DEL_PROGRAMA "Confirma que desea salir del programa?"

/**************************** MENSAJES ERROR *****************************************************/
#define MSJ_MALLOC_STRING_ERROR "\nNo se pudo asignar memoria para el texto solicitado"

/**************************** BUSQUEDA ***********************************************************/
/** \brief busca coincidencia de un valor entero dentro de un array
 *
 * \param array int*: el array donde buscar
 * \param limite int: la cantidad maxima de elementos del array
 * \param buscar int: el numero entero a buscar
 * \return int la posicion del elemento buscado. -1 en caso de no encontrarlo
 *
 */
int buscarEnArrayInt(int*, int, int);
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
/** \brief pide confirmacion por S o N al usuario y devuelve la letra validada
 *
 * \param  mensajeAlUsuario  char*: mensaje al usuario
 * \return char: S o N validado
 *
 */
char pedirConfirmacion(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief hace una pausa y pide al usuario que presione cualquier tecla para continuar
 *
 * \return void
 *
 */
void pausa();
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero entero
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return int: el numero entero
 *
 */
int pedirInt(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero int y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  int: valor inferior v�lido
 * \param limiteSuperior  int: valor superior v�lido
 * \return int: el n�mero validado
 *
 */
int pedirIntValido(char*, char*, int, int);
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero float
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return float: el numero float
 *
 */
float pedirFloat(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese un numero float y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  float: valor inferior v�lido
 * \param limiteSuperior  float: valor superior v�lido
 * \return float: el n�mero validado
 *
 */
float pedirFloatValido(char*, char*, float, float);
//-----------------------------------------------------------------------------------------------//
/** \brief pide memoria para un string del tama�o especificado en el limite y retorna su puntero
 *
 * \param limite int el tama�o
 * \return char* puntero a char donde se retorna el string creado
 *
 */
char* constructorString(int limite);
//-----------------------------------------------------------------------------------------------//
/** \brief pide memoria para una cadena de texto y realiza su ingreso validado
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limite int: el l�mite para la cantidad de caracteres
 * \return char* puntero a char donde se retorna el string creado y validado
 *
 */
char* constructorStringParametrizado(char* mensajeIngreso, char* mensajeReingreso, int limite);
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese una cadena de texto y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return void
 *
 */
void pedirString(char*, char*);
//-----------------------------------------------------------------------------------------------//
/** \brief pide que se ingrese una cadena de texto, valida su tama�o y la asigna a una variable
 *
 * \param stringValido char*: puntero a char donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limite int: el l�mite para la cantidad de caracteres
 * \return int devuelve cero si no hubo error
 *
 */
int pedirStringValido(char* stringValido, char* mensajeIngreso, char* mensajeReingreso, int limite);
//-----------------------------------------------------------------------------------------------//


/**************************** LISTADO DE DATOS ***************************************************/
/** \brief Recibe un texto y lo decora como t�tulo
 *
 * \param  char*: el texto a decorar
 * \return void
 *
 */
void generarTitulo(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief escribe el texto recibido con un printf
 *
 * \param texto  char*: la cadena de texto a mostrar
 * \return void
 *
 */
void imprimirEnPantalla(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief Recibe un texto y lo muestra decorado como t�tulo
 *
 * \param   char*: el texto a mostrar
 * \return void
 *
 */
void imprimirTitulo(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief limpia el contenido de la pantalla
 *
 * \return void
 *
 */
void limpiarPantalla();
//-----------------------------------------------------------------------------------------------//
/** \brief limpia la pantalla y muestra un mensaje con formato de titulo
 *
 * \param char*: el texto a utilizar en el titulo
 * \return void
 *
 */
void limpiarPantallaYMostrarTitulo(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief hace un salto de linea en pantalla
 *
 * \return void
 *
 */
void saltoDeLinea();
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
/** \brief corre comandos en la consola del sistema operativo
 *
 * \param  lineaDeComando  char*: el string del comando
 * \return void
 *
 */
void ejecutarEnConsola(char*);
//-----------------------------------------------------------------------------------------------//
/** \brief convierte un entero en texto
 *
 * \param numero int el numero entero
 * \return char* texto
 *
 */
char* intToChar(int numero);
//-----------------------------------------------------------------------------------------------//
/** \brief convierte un flotante en texto
 *
 * \param numero float el numero flotante
 * \return char* texto
 *
 */
char* floatToChar(float numero);
//-----------------------------------------------------------------------------------------------//
/** \brief calcula el promedio entre dos numeros float
 *
 * \param numero1 float: el primer numero
 * \param numero2 float: el segundo numero
 * \return float: el promedio entre ambos numeros
 *
 */
float calcularPromedio(float, float);
//-----------------------------------------------------------------------------------------------//
#endif // GENERAL_H_INCLUDED
