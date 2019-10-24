#include "persona.h"
#define MAX_VOTOS 10


int main()
{
    ePersona miPersona[MAX_VOTOS];

    inicializarPersonas(miPersona,MAX_VOTOS);

    hardcodearPersonas(miPersona,MAX_VOTOS);

    altaPersonas(miPersona,MAX_VOTOS);

    printf("\nAntes de Ordenar");
    mostrarPersonas(miPersona,MAX_VOTOS);
    ordenarPersonas(miPersona,MAX_VOTOS);
    printf("\nDespues de Ordenar");
    mostrarPersonas(miPersona,MAX_VOTOS);

    return 0;
}
