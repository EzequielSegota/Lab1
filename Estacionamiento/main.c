#include "persona.h"
#define MAXPERSONA 4
#define MAXVEHICULOS 4
int main()
{
    //char patente[23]={"AA 111 BB"};
    ePersona newPersona[MAXPERSONA];
    eVehiculo newVehiculo[MAXVEHICULOS];

    hardcodePersonas(newPersona,MAXPERSONA);

    mostrarPersonas(newPersona,MAXPERSONA);

    hardcodeVehiculos(newVehiculo,MAXVEHICULOS);

    mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);

    ordenarPorPatente(newVehiculo,MAXVEHICULOS);

    ordenarPorNombre(newPersona,MAXPERSONA);

    mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);

    mostrarPersonas(newPersona,MAXPERSONA);
    //PRUEBA DE PATENTE
    //mostrarVehiculo(newVehiculo[buscarPorPatente(newVehiculo,MAXVEHICULOS,patente)],newPersona,MAXPERSONA);

    //Ordenar por año
    return 0;
}
