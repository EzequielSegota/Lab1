#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED
#include "referi.h"
#include "jugadores.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int codigo;
    char nombre[52];
    char localidad[33];
}eEquipo;

void menuEquipo(eEquipo*,int);

void inicializarEquipo(eEquipo*,int);

int buscarSiguienteLibre(eEquipo*,int);

int siguienteCodigo(eEquipo*,int);

void altaEquipo(eEquipo*,int);

void ordenarEquiposAlf(eEquipo*,int);

void mostrarEquipo(eEquipo);

void mostrarEquipos(eEquipo*,int);

void hardcodearEquipos(eEquipo*,int);
#endif // EQUIPO_H_INCLUDED
