#include <stdio.h>
#include <stdlib.h>
#include "matematica.h"


void ejecutarEnConsola(char instruccion[])
{
    fflush(stdin);
    printf("\n");
    system(instruccion);
}


int pedirOpcionDeMenu(int opcionesValidas[], int tam)
{
    int opcion;
    int i = -1;
    int opcionValida = 0;

    do
    {
        fflush(stdin);

        if(i == -1)
        {
            printf("\nElija una opci¢n de men£: ");
        }
        else
        {
            //armo lista de opciones en el renglón por si el usuario se equivoca muchas veces
            //y el menú queda fuera de vista
            for(i = 0 ; i < tam ; i++)
            {
                if(i == 0)
                {
                    printf("\nOpci¢n %d no v lida. Elija una opci¢n de men£ de la lista\n(%d", opcion, opcionesValidas[i]);
                }
                else
                {
                    if(i < tam-1)
                    {
                        printf("-%d", opcionesValidas[i]);
                    }
                    else
                    {
                        printf("-%d): ", opcionesValidas[i]);
                    }
                }
            }//for
        }

        scanf("%d", &opcion);

        //valido buscando opcion en la lista
        for(i = 0 ; i < tam ; i++)
        {
            if(opcion == opcionesValidas[i])
            {
                opcionValida = 1;
            }
        }

    }
    while(opcionValida == 0);

    return opcion;
}


float pedirFloat(const char mensajeIngreso[], const char mensajeReingreso[])
{
    float numero;
    int esNumero;

    ejecutarEnConsola("cls");
    fflush(stdin);
    printf("%s: ", mensajeIngreso);
    esNumero = scanf("%f", &numero);

    while(esNumero != 1)
    {
        fflush(stdin);
        printf("%s: ", mensajeReingreso);
        esNumero = scanf("%f", &numero);
    }

    return numero;
}


void mostrarResultado(char operacion, float numero1, float numero2, float resultado, const int cantidadDecimales, const char limpiarPantalla, const char hacerPausa)
{
    int numero1TienecantidadDecimales;
    int numero2TienecantidadDecimales;
    int resultadoTienecantidadDecimales;
    int esFactorial = 0;

    if(operacion == '!')
    {
        esFactorial = 1;
    }

    if(limpiarPantalla == 'S')
    {
        ejecutarEnConsola("cls");
    }

    if (esFactorial == 0)
    {
        numero1TienecantidadDecimales = chequearSiTieneDecimalesFloat(numero1);
        numero2TienecantidadDecimales = chequearSiTieneDecimalesFloat(numero2);
        resultadoTienecantidadDecimales = chequearSiTieneDecimalesFloat(resultado);

        //muestro los decimales en la máscara únicamente si existen
        //codifico todos los casos ordenados de 000 a 111 para que sea mas facil comprender el codigo
        if(numero1TienecantidadDecimales == 0
           && numero2TienecantidadDecimales == 0
           && resultadoTienecantidadDecimales == 0)
        {
            printf("\nResultado de %.0f %c %.0f = %.0f", numero1, operacion, numero2, resultado);
        }
        else if(numero1TienecantidadDecimales == 0
                && numero2TienecantidadDecimales == 0
                && resultadoTienecantidadDecimales == 1)
        {
            printf("\nResultado de %.0f %c %.0f = %.*f", numero1, operacion, numero2, cantidadDecimales, resultado);
        }
        else if(numero1TienecantidadDecimales == 0
                && numero2TienecantidadDecimales == 1
                && resultadoTienecantidadDecimales == 0)
        {
            printf("\nResultado de %.0f %c %.*f = %.0f", numero1, operacion, cantidadDecimales, numero2, resultado);
        }
        else if(numero1TienecantidadDecimales == 0
                && numero2TienecantidadDecimales == 1
                && resultadoTienecantidadDecimales == 1)
        {
            printf("\nResultado de %.0f %c %.*f = %.*f", numero1, operacion, cantidadDecimales, numero2, cantidadDecimales, resultado);
        }
        else if(numero1TienecantidadDecimales == 1
                && numero2TienecantidadDecimales == 0
                && resultadoTienecantidadDecimales == 0)
        {
            printf("\nResultado de %.*f %c %.0f = %.0f", cantidadDecimales, numero1, operacion, numero2, resultado);
        }
        else if(numero1TienecantidadDecimales == 1
                && numero2TienecantidadDecimales == 0
                && resultadoTienecantidadDecimales == 1)
        {
            printf("\nResultado de %.*f %c %.0f = %.*f", cantidadDecimales, numero1, operacion, numero2, cantidadDecimales, resultado);
        }
        else if(numero1TienecantidadDecimales == 1
                && numero2TienecantidadDecimales == 1
                && resultadoTienecantidadDecimales == 0)
        {
            printf("\nResultado de %.*f %c %.*f = %.0f", cantidadDecimales, numero1, operacion, cantidadDecimales, numero2, resultado);
        }
        else if(numero1TienecantidadDecimales == 1
                && numero2TienecantidadDecimales == 1
                && resultadoTienecantidadDecimales == 1)
        {
            printf("\nResultado de %.*f %c %.*f = %.*f", cantidadDecimales, numero1, operacion, cantidadDecimales, numero2, cantidadDecimales, resultado);
        }
    }
    else
    {
        printf("\nResultado de %.0f%c = %.0f", numero1, operacion, resultado);
    }

    if(hacerPausa == 'S')
    {
        ejecutarEnConsola("pause");
    }
}


int mostrarMenuDeOpciones(char primerNumeroYaSeIngreso, char segundoNumeroYaSeIngreso, float numero1, float numero2, int cantidadDecimales)
{
    int retorno;
    int listaOpcionesAmbosNumerosIngresados[9] = {1,2,3,4,5,6,7,8,9};
    int listaOpcionesPrimerNumeroIngresado[4] = {1,2,7,9};
    int listaOpcionesSegundoNumeroIngresado[3] = {1,2,9};

    ejecutarEnConsola("cls");
    if(primerNumeroYaSeIngreso == 'S')
    {
        if(segundoNumeroYaSeIngreso == 'S')
        {
            //A y B tienen valor
            printf("1- Ingresar 1er operando (A=%.*f)\n", cantidadDecimales, numero1);
            printf("2- Ingresar 2do operando (B=%.*f)\n", cantidadDecimales, numero2);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicaci¢n (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            retorno = pedirOpcionDeMenu(listaOpcionesAmbosNumerosIngresados, 9);
        }
        else
        {
            //A tiene valor
            printf("1- Ingresar 1er operando (A=%.*f)\n", cantidadDecimales, numero1);
            printf("2- Ingresar 2do operando (B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("9- Salir\n");
            retorno = pedirOpcionDeMenu(listaOpcionesPrimerNumeroIngresado, 4);
        }
    }
    else
    {
        if(segundoNumeroYaSeIngreso == 'S')
        {
            //B tiene valor
            printf("1- Ingresar 1er operando (A)\n");
            printf("2- Ingresar 2do operando (B=%.*f)\n", cantidadDecimales, numero2);
            printf("9- Salir\n");
            retorno = pedirOpcionDeMenu(listaOpcionesSegundoNumeroIngresado, 3);
        }
        else
        {
            //A y B no tienen valor ingresado
            printf("1- Ingresar 1er operando (A)\n");
            printf("2- Ingresar 2do operando (B)\n");
            printf("9- Salir\n");
            retorno = pedirOpcionDeMenu(listaOpcionesSegundoNumeroIngresado, 3);
        }
    }

    return retorno;
}
