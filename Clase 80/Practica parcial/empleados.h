#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "fecha.h"
#include "sector.h"
typedef struct
{
    int legajo;
    int isEmpty;
    float salario;
    char nombre[51];
    char apellido[51];
    char sexo;
    eFecha fechaIngreso;
    int idSector;

}eEmpleado;

void inicializarEmpleado(eEmpleado* list,int tam);

void opcionEmpleado(eEmpleado* list,int tamEmp,eSector* sec,int tamSec);

void altaEmpleado(eEmpleado* list,int tamEmp,eSector* sec,int tamSec);

int buscarLugarLibre(eEmpleado* lista,int tam);

int siguienteID(eEmpleado* list,int limite);

#endif // EMPLEADOS_H_INCLUDED
