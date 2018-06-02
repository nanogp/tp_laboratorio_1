#include <stdio.h>
#include <stdlib.h>
#include "matematica.h"
#include "funciones.h"

/*defino los ASCII de los simbolos para cada operación matemática
para poder mostrar correctamente el caracter en la consola*/
#define DECIMALES_FLOAT 4
#define SUMA 43
#define RESTA 45
#define MULTIPLICACION 42
#define DIVISION 47
#define FACTORIAL 33

int main()
{
    const char limpiarPantalla          = 'S';
    const char noLimpiarPantalla        = 'N';
    const char hacerPausa               = 'S';
    const char noHacerPausa             = 'N';
    const char simboloSuma              = (char)SUMA;
    const char simboloResta             = (char)RESTA;
    const char simboloMultiplicacion    = (char)MULTIPLICACION;
    const char simboloDivision          = (char)DIVISION;
    const char simboloFactorial         = (char)FACTORIAL;
    const char mensajeIngreso[20]       = "Ingrese un n£mero";
    const char mensajeReingreso[80]     = "Reingrese un n£mero que sea v lido. (No pueden ser s¡mbolos ni letras)";
    char primerNumeroYaSeIngreso        = 'N';
    char segundoNumeroYaSeIngreso       = 'N';
    char seguir                         = 'S';
    float numero1;
    float numero2;
    float resultado;
    int opcion;

    while(seguir=='S')
    {

        opcion = mostrarMenuDeOpciones(primerNumeroYaSeIngreso, segundoNumeroYaSeIngreso, numero1, numero2, DECIMALES_FLOAT);

        switch(opcion)
        {
            case 1:
                numero1 = pedirFloat(mensajeIngreso, mensajeReingreso);
                primerNumeroYaSeIngreso = 'S';
                break;
            case 2:
                numero2 = pedirFloat(mensajeIngreso, mensajeReingreso);
                segundoNumeroYaSeIngreso = 'S';
                break;
            case 3:
                resultado = sumarFloat(numero1, numero2);
                mostrarResultado(simboloSuma, numero1, numero2, resultado, DECIMALES_FLOAT, limpiarPantalla, hacerPausa);
                break;
            case 4:
                resultado = restarFloat(numero1, numero2);
                mostrarResultado(simboloResta, numero1, numero2, resultado, DECIMALES_FLOAT, limpiarPantalla, hacerPausa);
                break;
            case 5:
                if(validarDivisionEsPosible(numero2) == 1)
                {
                    resultado = dividirFloat(numero1, numero2);
                    mostrarResultado(simboloDivision, numero1, numero2, resultado, DECIMALES_FLOAT, limpiarPantalla, hacerPausa);
                }
                else
                {
                    ejecutarEnConsola("pause");
                }
                break;
            case 6:
                resultado = multiplicarFloat(numero1, numero2);
                mostrarResultado(simboloMultiplicacion, numero1, numero2, resultado, DECIMALES_FLOAT, limpiarPantalla, hacerPausa);
                break;
            case 7:
                if(validarFactorialEsPosible(numero1) == 1)
                {
                    resultado = calcularFactorialInt(numero1);
                    mostrarResultado(simboloFactorial, numero1, 0, resultado, DECIMALES_FLOAT, limpiarPantalla, hacerPausa);
                }
                else
                {
                    ejecutarEnConsola("pause");
                }
                break;
            case 8:
                resultado = sumarFloat(numero1, numero2);
                mostrarResultado(simboloSuma, numero1, numero2, resultado, DECIMALES_FLOAT, limpiarPantalla, noHacerPausa);

                resultado = restarFloat(numero1, numero2);
                mostrarResultado(simboloResta, numero1, numero2, resultado, DECIMALES_FLOAT, noLimpiarPantalla, noHacerPausa);

                if(validarDivisionEsPosible(numero2) == 1)
                {
                    resultado = dividirFloat(numero1, numero2);
                    mostrarResultado(simboloDivision, numero1, numero2, resultado, DECIMALES_FLOAT, noLimpiarPantalla, noHacerPausa);
                }

                resultado = multiplicarFloat(numero1, numero2);
                mostrarResultado(simboloMultiplicacion, numero1, numero2, resultado, DECIMALES_FLOAT, noLimpiarPantalla, noHacerPausa);

                if(validarFactorialEsPosible(numero1) == 1)
                {
                    resultado = calcularFactorialInt(numero1);
                    mostrarResultado(simboloFactorial, numero1, 0, resultado, DECIMALES_FLOAT, noLimpiarPantalla, noHacerPausa);
                }
                ejecutarEnConsola("pause");
                break;
            case 9:
                seguir = 'N';
                break;
        }//switch
    }//while
    return 0;
}
