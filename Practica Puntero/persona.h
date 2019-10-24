#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int orden;
    char apellido[32];
    int estado;
}ePersona;

void inicializarPersonas(ePersona* persona,int tam);

void hardcodearPersonas(ePersona* personas,int tam);

void pedirDatos(ePersona* miPersonas, int id);

void ordenarPersonas(ePersona*,int tam);

int buscarPersonasLibre(ePersona*,int);

int siguienteIDPersonas(ePersona*,int);

void altaPersonas(ePersona*,int);

void swapPunteros(ePersona*,ePersona*);

void mostrarPersonas(ePersona* persona,int tam);
#endif // PERSONA_H_INCLUDED
