#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief ejecuta instrucciones de la consola
 *
 * \param instruccion: la instrucción a ejecutar en consola
 *
 */
void ejecutarEnConsola(char[]);


/** \brief pide al usuario que ingrese un número
 *
 * \param mensajeIngreso: mensaje para pedir ingresó del número
 * \param mensajeReingresó: mensaje para pedir reingresó si corresponde
 * \return el número validado
 *
 */
float pedirFloat(const char[], const char[]);


/** \brief pide al usuario un número de opción de menú y valida con una lista
 *
 * \param lista: vector con la lista de números validos
 * \param tam: tamaño del vector (cantidad de opciones disponibles)
 * \return el número de opción elegido por el usuario
 *
 */
int pedirOpcionDeMenu(int[],int);


/** \brief muestra por printf el resultado de las operaciónes de la calculadora
 *
 * \param operacion: el signo de la operación que se va a mostrar el resultado (ej: +, -, etc)
 * \param numero1: el primer número que formo parte de la operación
 * \param numero2: el segundo número que formo parte de la operación
 * \param resultado: el resultado que dio la operación entre los números 1 y 2
 * \param cantidadDecimales: la cantidad de decimales a mostrar
 * \param limpiarPantalla: recibe S o N si debe borrar la pantalla antes de mostrar el resultado
 * \param hacerPausa: recibe S o N si debe hacer una pausa luego de mostrar el resultado
 *
 */
void mostrarResultado(char, float, float, float, const int, const char, const char);


/** \brief muestra el menú de opciones para que el usuario elija una
 *
 * \param primerNumeroYaSeIngreso: indica si el usuario ya ingresó su primer número
 * \param segundoNumeroYaSeIngreso: indica si el usuario ya ingresó su segundo número
 * \return el número de opcion de menú elegido
 *
 */
int mostrarMenuDeOpciones(char, char, float, float, int);


#endif // FUNCIONES_H_INCLUDED
