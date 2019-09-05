#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD 6
int main()
{

    int listadoDeEdades[CANTIDAD],max,min;
    float promedio;
    inicializarArray(listadoDeEdades,CANTIDAD);

    cargaSecuencialDeArray(listadoDeEdades,CANTIDAD,"Ingrese edad:");

    mostrarArray(listadoDeEdades,CANTIDAD);

    max=encontrarMax(listadoDeEdades,CANTIDAD);
    min=encontrarMin(listadoDeEdades,CANTIDAD);
    promedio=dameElPromedio(listadoDeEdades,CANTIDAD);
    printf("\n\nLa mayor edad ingresada fue:%d",max);
    printf("\n\nLa menor edad ingresada fue:%d",min);
    printf("\n\nEl promedio es:%.2f",promedio);

    ordenarArray(listadoDeEdades,CANTIDAD);
    mostrarArray(listadoDeEdades,CANTIDAD);


    return 0;
}



