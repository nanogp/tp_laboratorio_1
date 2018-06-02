#include <stdio.h>

int chequearSiTieneDecimalesFloat(float numero)
{
    int retorno = 0;
    int parteEntera;

    parteEntera = (int)numero;

    if((float)parteEntera != numero)
    {
        retorno = 1;
    }

    return retorno;
}


int validarDivisionEsPosible(float divisor)
{
    int retorno = 0;

    if(divisor != 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nEl divisor no puede ser cero");
    }

    return retorno;
}


int validarFactorialEsPosible(float numero)
{
    int retorno = 0;

    if(numero >= 0 && chequearSiTieneDecimalesFloat(numero) == 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nSolo se calcular  el factorial de n£meros enteros positivos sin decimales");
    }

    return retorno;
}


float sumarFloat(float numero1, float numero2)
{
    float resultado;

    resultado = numero1 + numero2;

    return resultado;
}


float restarFloat(float numero1, float numero2)
{
    float resultado;

    resultado = numero1 - numero2;

    return resultado;
}


float multiplicarFloat(float numero1, float numero2)
{
    float resultado;

    resultado = numero1 * numero2;

    return resultado;
}


float dividirFloat(float numero1, float numero2)
{
    float resultado;

    resultado = numero1 / numero2;

    return resultado;
}


float calcularFactorialInt(int numero)
{
    float resultado;
    int multiplicando;

    if(numero == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero;
        for(multiplicando = numero - 1 ; multiplicando > 0 ; multiplicando--)
        {
            resultado *= multiplicando;
        }
    }

    return resultado;
}
