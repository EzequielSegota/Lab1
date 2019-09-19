#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dni;
    char nombre[32];
    char apellido[32];
    int estado;
} ePersona;

void inicializarPersona(ePersona*,int);

void ingresarPersonas(ePersona*,int);

void mostrarPersona(ePersona);

void mostrarPersonas(ePersona*,int);

void menuPersonas(ePersona*,int);

int buscarSiguienteLibre(ePersona*,int);

void ordenarPorDNI(ePersona*,int);

int validarDNI(ePersona*,int,int);

void ordenarPorApellidoYNombre(ePersona*,int);
#endif // PERSONAS_H_INCLUDED
