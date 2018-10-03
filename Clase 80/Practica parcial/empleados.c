#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
void opcionEmpleado(eEmpleado* list,int tamEmp,eSector* sec,int tamSec)
{
    int opcion;

    printf("1.Alta\n");
    printf("2.Baja\n");
    printf("3.Modificacion\n");
    printf("4.Salir");
    printf("\nQue desea hacer?:");
    scanf("%d",&opcion);

    switch(opcion)
    {
        case 1:
            altaEmpleado(list,tamEmp,sec,tamSec);
            break;
        case 2:
            mostrarEmpleados(list,tamEmp,sec,tamSec);
            break;
        case 3:
            break;
        case 4:
            break;
    }
}

void inicializarEmpleado(eEmpleado* list,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        list[i].isEmpty=0;
        list[i].legajo=0;
    }
}

int buscarLugarLibre(eEmpleado* lista,int tam)
{
    int i,espacioVacio=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty==0)
        {
            espacioVacio=i;
            break;
        }
    }
    return espacioVacio;
}

int siguienteID(eEmpleado* list,int limite)
{
    int retorno = 0;
    int i;

        for(i=0; i<limite; i++)
        {
            if(list[i].isEmpty == 1)
            {
                    if(list[i].legajo>retorno)
                    {
                         retorno=list[i].legajo;
                    }

            }
        }

    return retorno+1;
}

void altaEmpleado(eEmpleado* list,int tamEmp,eSector* sec,int tamSec)
{
    eEmpleado aux;
    int espacioLibre=buscarLugarLibre(list,tamEmp);
    int legajo=siguienteID(list,tamEmp);


    if(espacioLibre!=-1 && legajo!=-1)
    {
        aux.legajo=legajo;

        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(aux.nombre);

        printf("\nIngrese apellido:");
        fflush(stdin);
        gets(aux.apellido);

        printf("\nIngrese sexo(f o m):");
        scanf("%c",&aux.sexo);

        printf("\nIngrese salario:");
        scanf("%f",&aux.salario);

        aux.idSector=elegirSector(sec,tamSec);

        aux.isEmpty=1;

        aux.fechaIngreso=ingresarFecha();

        list[espacioLibre]=aux;
    }
}


