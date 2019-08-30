#include "funciones.h"
int main()
{
    int edad=pedirEntero("Ingrese edad:","\nERROR, debe ser entre 0 y 100:",0,100);
    int legajo=pedirEntero("Ingrese legajo:","\nERROR, debe ser entre 0 y 2000:",0,2000);
    int nota = pedirEntero("Ingrese nota:", "\nERROR, debe ser entre 0 y 10:",0,10);
    int documento = pedirEntero("Ingrese documento:","\nERROR debe ser entre 1 y 50000:",1,50000);
    printf("\nEdad:%d\n\n",edad);
    printf("\nLegajo%d\n\n",legajo);
    printf("\nNota:%d\n\n",nota);
    printf("\nDocumento:%d\n\n",documento);
    return 0;
}
