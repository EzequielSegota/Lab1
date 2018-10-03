#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "empleados.h"
#include "sector.h"
#include "menu.h"
#include "almuerzo.h"
#define TAMEMP 10
#define TAMMENU 5

int main()
{
    int opcion;
    char seguir='s';
    eEmpleado lista[TAMEMP];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    inicializarEmpleado(lista,TAMEMP);


    do
    {
        printf("\n1.Menues");
        printf("\n2.Empleados");
        printf("\n3.Almuerzos");
        printf("\n4.Salir");
        printf("\nQue desea hacer?:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\n\n\t\tMENUES\n\n");
                opcionMenu();
                system("cls");
                break;
            case 2:
                system("cls");
                printf("\n\n\t\tEMPLEADOS\n\n");
                opcionEmpleado(lista,TAMEMP,sectores,5);
                system("cls");
                break;
            case 3:
                system("cls");
                printf("\n\n\t\tALMUERZOS\n\n");
                opcionAlmuerzo();
                system("cls");
                break;
            case 4:
                system("cls");
                seguir='n';
                break;


        }

    }while(seguir=='s');



    return 0;
}
