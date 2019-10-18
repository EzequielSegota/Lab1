#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    //char nombre[50];
    int edad;
    float altura;
}ePersona;

ePersona* new_Persona();//Constructor por Defecto(inicializa una persona con valores en cero)
int mostrarPersona(ePersona*);
int delete_Persona(ePersona*);
ePersona* new_Persona_Parametros(int,int,float);
#endif // PERSONA_H_INCLUDED
