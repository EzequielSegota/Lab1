#include "persona.h"


int main(void)
{
    ePersona* pPersona;

    pPersona = new_Persona_Parametros(100,40,1.87);

    if(mostrarPersona(pPersona)!=1)
    {
        printf("\nError al mostrar");
    }

    delete_Persona(pPersona);


    return 0;
}
