#include "fecha.h"

eFecha ingresarFecha(void)
{
    eFecha aux;
    printf("\nIngrese dia:");
    scanf("%d",&aux.dia);

    printf("\nIngrese mes:");
    scanf("%d",&aux.mes);

    printf("\nIngrese a�o:");
    scanf("%d",&aux.anio);

    return aux;
}
