#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployee.h"
#define ELEMENTS 1000



int main()
{
    Employee list[ELEMENTS];
    int flag=0;
    char seguir='s';
    initEmployees(list,ELEMENTS);

    eSector sectores[] =
    {
    {1,"RRHH"},
    {2,"Ventas"},
    {3,"Compras"},
    {4, "Contable"},
    {5,"Sistemas"}
    };

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                if(addEmployee(list, ELEMENTS,)==-1)
                {
                    printf("\nError, no se puede agregar usuario.");
                }
                else
                {
                    flag=1;
                }
                break;
            case 2:
                system("cls");
                if(flag==1)
                {

                }
                else
                {
                    printf("No se han ingresado empleados");
                }
                break;
            case 5:
                printf("Adios.");
                seguir='n';
                break;

            default:
                printf("Adios.");
                seguir='n';
                break;
        }
    }while(seguir=='s');


    /*for(int i=0;i<ELEMENTS;i++)
    {
        printf("%d\n",list[i].isEmpty);
    }*/
    return 0;
}
