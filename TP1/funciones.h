#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief ejecuta instrucciones de la consola
 *
 * \param instruccion: la instrucci�n a ejecutar en consola
 *
 */
void ejecutarEnConsola(char[]);


/** \brief pide al usuario que ingrese un n�mero
 *
 * \param mensajeIngreso: mensaje para pedir ingres� del n�mero
 * \param mensajeReingres�: mensaje para pedir reingres� si corresponde
 * \return el n�mero validado
 *
 */
float pedirFloat(const char[], const char[]);


/** \brief pide al usuario un n�mero de opci�n de men� y valida con una lista
 *
 * \param lista: vector con la lista de n�meros validos
 * \param tam: tama�o del vector (cantidad de opciones disponibles)
 * \return el n�mero de opci�n elegido por el usuario
 *
 */
int pedirOpcionDeMenu(int[],int);


/** \brief muestra por printf el resultado de las operaci�nes de la calculadora
 *
 * \param operacion: el signo de la operaci�n que se va a mostrar el resultado (ej: +, -, etc)
 * \param numero1: el primer n�mero que formo parte de la operaci�n
 * \param numero2: el segundo n�mero que formo parte de la operaci�n
 * \param resultado: el resultado que dio la operaci�n entre los n�meros 1 y 2
 * \param cantidadDecimales: la cantidad de decimales a mostrar
 * \param limpiarPantalla: recibe S o N si debe borrar la pantalla antes de mostrar el resultado
 * \param hacerPausa: recibe S o N si debe hacer una pausa luego de mostrar el resultado
 *
 */
void mostrarResultado(char, float, float, float, const int, const char, const char);


/** \brief muestra el men� de opciones para que el usuario elija una
 *
 * \param primerNumeroYaSeIngreso: indica si el usuario ya ingres� su primer n�mero
 * \param segundoNumeroYaSeIngreso: indica si el usuario ya ingres� su segundo n�mero
 * \return el n�mero de opcion de men� elegido
 *
 */
int mostrarMenuDeOpciones(char, char, float, float, int);


#endif // FUNCIONES_H_INCLUDED
