#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char nombre[32];
    eFecha fechaNac;
    int estado;
}ePersona;

typedef struct
{
    char patente[50];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;



void hardcodePersonas(ePersona*,int);

void mostrarPersona(ePersona);

void mostrarPersonas(ePersona*,int);

void hardcodeVehiculos(eVehiculo*,int);

void mostrarVehiculo(eVehiculo,ePersona*,int);

void mostrarVehiculos(eVehiculo*,int,ePersona*,int);

int buscarPersonaPorID(ePersona*,int,int);

int buscarPorPatente(eVehiculo*,int,char*);

void ordenarPorPatente(eVehiculo*,int,ePersona*,int);

void ordenarPorNombre(ePersona*,int);

void inicializarPersonas(ePersona*,int);

int menuPrincipal(void);

int buscarLibre(ePersona*, int);

void altaPropietario(ePersona*, int);

void mostrarVehiculosSinDuenio(eVehiculo);

void mostrarVehiculosPorID(eVehiculo*,int,int);

void mostrarPersonasConVehiculos(ePersona*,int,eVehiculo*,int);

void calcularEstadia(eVehiculo*,int);
#endif // PERSONA_H_INCLUDED
