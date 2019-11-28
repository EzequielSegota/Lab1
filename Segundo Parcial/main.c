#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "funciones.h"
#include "aerolinea.h"
#include "validaciones.h"
int main()
{
    FILE *fp;
    char seguir='s';
    int opcion=0,flag=0,cantPasajeros;

    LinkedList* pList;
    LinkedList* listaFiltrada;

    pList=ll_newLinkedList();

    while(seguir=='s')
    {
        printf("\n1- Levantar archivo y crear lista\n");
        printf("2- Obtener Vuelos con Pilotos\n");
        printf("3- Generar archivo con lista filtrada\n");
        printf("4- Cantidad de Pasajeros Total\n");
        printf("5- Cantidad de Pasajeros de Irlanda\n");
        printf("6- Generar archivo con Vuelos cortos\n");
        printf("7- Obtener Vuelos a Portugal\n");
        printf("8- Obtener Vuelos que no sean de Alex Lifeson\n");
        printf("9- Salir\n");
        getValidInt("\nIngrese su opcion:","Error, debe ser de 1 a 4 y numerico",&opcion,1,9,3);
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
                        aerolinea_printAllProblemas(pList);
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
                        printf("\n1.Alex Lifeson\n2.Richard Bach\n3.John Kerry\n4.Erwin Rommel\n5.Stephen Coonts");
                        getValidInt("\nIngrese ID de Piloto para filtrar:","\nError debe ser de 1 a 5 y numerico",&auxProblema,1,5,3);

                        switch(auxProblema)
                        {
                            case 1:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraUno);
                                aerolinea_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }
                                break;
                            case 2:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraDos);
                                aerolinea_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }
                                break;
                            case 3:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraTres);
                                aerolinea_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }

                                break;
                            case 4:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraCuatro);
                                aerolinea_printAll(listaFiltrada);

                                if(crearArchivo(fp, listaFiltrada)==-1)
                                {
                                    printf("Error.");
                                }

                                break;
                            case 5:
                                listaFiltrada=ll_filter(pList,funcionQueFiltraCinco);
                                aerolinea_printAll(listaFiltrada);

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
            case 4:
                system("cls");
                if(flag==1)
                {
                    cantPasajeros=ll_count(pList,aerolinea_CantidadPasajeros);
                    printf("\nLa cantidad de pasajeros es:%d\n",cantPasajeros);
                }
                else
                {
                    printf("\nNo hay archivo cargado");
                }
                break;
            case 5:
                system("cls");
                if(flag==1)
                {
                    cantPasajeros=ll_count(pList,aerolinea_CantidadPasajerosIrlanda);
                    printf("\nLa cantidad de pasajeros de Irlanda es:%d\n",cantPasajeros);
                }
                else
                {
                    printf("\nNo hay archivo cargado");
                }
                break;
            case 6:
                system("cls");
                if(flag==1)
                {
                    listaFiltrada=ll_filter(pList,funcionQueFiltraVuelos);
                    aerolinea_printAll(listaFiltrada);

                    if(crearArchivo(fp, listaFiltrada)==-1)
                    {
                        printf("Error.");
                    }

                    break;
                }
                else
                {
                    printf("\nNo hay archivo cargado");
                }
                break;
            case 7:
                system("cls");
                if(flag==1)
                {
                    aerolinea_printVuelosAPortugalAll(pList);
                }
                else
                {
                    printf("\nNo hay archivo cargado");
                }
                break;
            case 8:
                system("cls");
                if(flag==1)
                {
                    listaFiltrada=ll_filter(pList,funcionQueFiltraAlex);
                    aerolinea_printAll(listaFiltrada);

                    if(crearArchivo(fp, listaFiltrada)==-1)
                    {
                        printf("Error.");
                    }

                    break;
                }
                else
                {
                    printf("\nNo hay archivo cargado");
                }
                break;
            default:
                seguir='n';
        }
    }

    return 0;
}
