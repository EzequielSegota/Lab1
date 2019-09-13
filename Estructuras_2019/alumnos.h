#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int legajo;
    char nombre[50];
    int nota;

}eAlumno;


void mostrarAlumno(eAlumno);
eAlumno pedirAlumno();
int compararAlumnoPorLegajo(eAlumno,eAlumno);
void cargarAlumnos(eAlumno[],int);
void mostrarAlumnos(eAlumno[],int);
void ordenarAlumnosPorNombre(eAlumno[],int);
void hardcodearAlumno(eAlumno[],int);

#endif // ALUMNOS_H_INCLUDED
