#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funciones.h"
#include "llamadas.h"
int main()
{
    FILE *fp;
    char seguir='s';
    int opcion=0,flag=0;

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
                    else
                    {
                        flag=1;
                    }
                }
                break;
            case 2:
                {
                    system("cls");
                    if(flag==1)
                    {
                        llamadas_printAllProblemas(pList);
                    }
                    else{
                        printf("\nNo hay archivo cargado");
                    }
                }
                break;
             case 3:
                {
                    system("cls");

                    if(flag==1)
                    {
                        int auxProblema;

                        do
                        {
                            printf("\nIngrese ID problema para filtrar:");
                            scanf("%d",&auxProblema);
                        }while(auxProblema>5 || auxProblema<1);
                        ///FALTA VALIDAR

                        switch(auxProblema)
                        {
                            case 1:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraUno);
                                llamadas_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }
                                break;
                            case 2:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraDos);
                                llamadas_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }
                                break;
                            case 3:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraTres);
                                llamadas_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }

                                break;
                            case 4:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraCuatro);
                                llamadas_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }

                                break;
                            case 5:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraCinco);
                                llamadas_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }

                                break;
                            default:
                                printf("\nError");
                        }
                    }
                    else
                    {
                        printf("\nNo hay archivo cargado");
                    }
                }
                break;
            default:
                seguir='n';
        }
    }

    return 0;
}
