#ifndef MATEMATICA_H_INCLUDED
#define MATEMATICA_H_INCLUDED


/** \brief recibe un número y chequea si tiene decimales
 *
 * \param el número a verificar
 * \return 1 si tiene decimales, 0 si no
 *
 */
int chequearSiTieneDecimalesFloat(float);


/** \brief recibe el valor del divisor y verifica que no sea cero
 *
 * \param divisor: el número divisor
 * \return devuelve 1 o 0 si es posible dividir o no y en caso de no ser posible, lo informa en pantalla.
 *
 */
int validarDivisionEsPosible(float);


/** \brief recibe un número y verifica que se pueda realizar el factorial
 *
 * \param numero: el número a procesar
 * \return devuelve 1 o 0 si es posible realizar o no el factorial y en caso de no ser posible, lo informa en pantalla.
 *
 */
int validarFactorialEsPosible(float);


/** \brief suma dos números y devuelve el resultado
 *
 * \param numero1: el primer operando
 * \param numero2: el segundo operando
 * \return la suma de los operandos
 *
 */
float sumarFloat(float, float);


/** \brief resta dos números y devuelve el resultado
 *
 * \param numero1: el primer operando
 * \param numero2: el segundo operando
 * \return la resta de los operandos
 *
 */
float restarFloat(float, float);


/** \brief multiplica dos números y devuelve el resultado
 *
 * \param numero1: el primer operando
 * \param numero2: el segundo operando
 * \return el producto de los operandos
 *
 */
float multiplicarFloat(float, float);


/** \brief divide dos números y devuelve el resultado en flotante
 *
 * \param numero1: el primer operando
 * \param numero2: el segundo operando
 * \return la division de los operandos
 *
 */
float dividirFloat(float, float);


/** \brief calcula el factorial de un número entero
 *
 * \param numero: el número al que se calcula su factorial
 * \return el factorial del número ingresado
 *
 */
float calcularFactorialInt(int);


#endif // MATEMATICA_H_INCLUDED
