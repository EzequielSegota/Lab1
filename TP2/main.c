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

    do
    {
        switch(menu())
        {
            case 1:
                system("cls");
                if(addEmployee(list, ELEMENTS)==-1)
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
