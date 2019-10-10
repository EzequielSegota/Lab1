#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include "equipo.h"
#include "referi.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    eFecha fechaNac;
    int codigo;
    char apellido[31];
    char nombre[31];
    int codigoEquipo;
    char sexo;
}



#endif // JUGADORES_H_INCLUDED
