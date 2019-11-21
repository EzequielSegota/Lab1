#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funciones.h"
#include "llamadas.h"
int main()
{
    FILE *fp;
    char seguir='s';
    int opcion=0,i;

    LinkedList* pList;
    LinkedList* listaFiltrada;

    pList=ll_newLinkedList();

    while(seguir=='s')
    {
        printf("\n1- Levantar archivo y crear lista\n");
        printf("2- Obtener lista con problemas\n");
        printf("3- Generar archivo con lista filtrada\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                    if(parser(fp,pList)==-1)
                    {
                        printf("Error.");
                    }

                }
                break;
            case 2:
                {

                }
                break;
             case 3:
                {
                    listaFiltrada=ll_filter(pList,funcionQueFiltra);

                    llamadas_printAll(listaFiltrada);

                    if(crearArchivo(fp, listaFiltrada)==-1)
                    {
                        printf("Error.");
                    }
                }
                break;
            default:
                seguir='n';
        }
    }

    return 0;
}
