#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;
    if(list != NULL && len != NULL)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }

    return retorno;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n1. Ingresar empleado.");
    printf("\n2. Dar de baja empleado.");
    printf("\n3. Modificar empleado.");
    printf("\n4. Listar ordenando por apellido.");
    printf("\n5. Salir.\n");
    scanf("%d",&opcion);

    return opcion;
}

int buscarLugar(Employee* list, int len)
{
    int i,retorno=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int comprobarID(Employee* list,int len,int id)
{
    int i,retorno=0;
    for(i=0;i<len;i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
            retorno=-1;
    }
    return retorno;
}

int addEmployee(Employee* list, int len)
{
        int retorno=-1,espacioLibre;

        Employee aux;

        system("cls");
        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(aux.name);
        printf("\nIngrese apellido:");
        fflush(stdin);
        gets(aux.lastName);
        printf("\nIngrese id:");
        scanf("%d",&aux.id);
        printf("\nIngrese sector:");
        scanf("%d",&aux.sector);
        aux.isEmpty=0;
        system("cls");

        espacioLibre=buscarLugar(list,len);

        while(comprobarID(list,len,aux.id)==-1)
        {
            printf("\nError,ID ya en uso, ingrese nuevo ID:");
            scanf("%d",&aux.id);
        }

        if(espacioLibre!=-1)
        {
            list[espacioLibre]=aux;
            retorno=1;
        }


    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int i;
    for(i=0i<length;i++)
    {
        printf("\nNombre:%s\tApellido:%s\tID:%d\tSector:%d\t")
    }
}
