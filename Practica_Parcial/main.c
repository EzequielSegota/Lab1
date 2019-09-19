#include "Personas.h"
#define MAX_PERSONA 5
int main()
{
    ePersona persona[MAX_PERSONA];

    inicializarPersona(persona,MAX_PERSONA);

    menuPersonas(persona,MAX_PERSONA);

    return 0;
}
