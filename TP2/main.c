#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Persona.h"


int main()
{
    char salirDelPrograma = 'N';
    int opcion;
    const eMenu menuPrincipal = {/*cant opciones en el menu*/5
                                ,/*codigo opciones disponibles*/{1,2,3,4,9}
                                ,/*descripcion opciones*/{"1. Agregar una persona","2. Borrar una persona","3. Imprimir lista ordenada por nombre","4. Imprimir gr�fico de edades","9. Salir"}
                                ,/*titulo del menu*/"TP NRO 2 MARIANO PONTI"
                                };

    ePersona listaPersonas[CANT_MAX_PERSONAS];

    ePersona_init(listaPersonas, CANT_MAX_PERSONAS);

    ePersona_initHardcode(listaPersonas); //comentar esta linea para que no se inicialice con datos de prueba

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(menuPrincipal);
        switch(opcion)
        {
            case 1:
                ePersona_procesarAlta(listaPersonas, CANT_MAX_PERSONAS);
                break;
            case 2:
                ePersona_procesarBaja(listaPersonas, CANT_MAX_PERSONAS);
                break;
            case 3:
                ePersona_procesarMostrarLista(listaPersonas, CANT_MAX_PERSONAS);
                break;
            case 4:
                ePersona_procesarMostrarGrafico(listaPersonas, CANT_MAX_PERSONAS);
                break;
            case 9:
                salirDelPrograma = pedirConfirmacion("Desea salir del programa?");
                break;
        }
    }
    while(salirDelPrograma == 'N');

    return 0;
}
