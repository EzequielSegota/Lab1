#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "funciones.h"
#include "llamadas.h"

int parser(FILE* pFile, LinkedList* this)
{
    int retorno = -1;

    char fecha[20];
    char id_Llamada[20];
    char id_Problema[20];
    char num_Cliente[20];
    char solucion[3];

    char nomArchivo[50];

    llamadas* auxLlamadas;

    printf("Ingrese nombre del archivo a abrir: ");
    fflush(stdin);
    gets(nomArchivo);

    pFile = fopen(nomArchivo, "r");

    if(pFile != NULL)
    {
        retorno = 0;

        printf("\nID Llamada\tFecha\t\tNum Cliente\t\tID Prob\tSolucionado\n");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_Llamada,fecha,num_Cliente,id_Problema,solucion);

        do
        {
          //  auxLlamadas = (llamadas*) malloc(sizeof(llamadas));


            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_Llamada,fecha,num_Cliente,id_Problema,solucion)==5)
            {
                //printf("test");
                auxLlamadas = llamadas_newParametros(id_Llamada,fecha, num_Cliente, id_Problema, solucion);
                //printf("%s", fecha);
                ll_add(this,auxLlamadas);
                llamadas_print(auxLlamadas);
            }
        }while(!feof(pFile));

    }

    fclose(pFile);

    return retorno;
}


int crearArchivo(FILE* pFile, LinkedList* this)
{
    llamadas* llamadasAux;

    int i, length;
    int retorno=-1;

    pFile = fopen("out.csv", "w");

    if(pFile!=NULL)
    {
        length=ll_len(this);
        retorno=0;

        char fecha[20];
        int id_Llamada;
        int id_Problema;
        int num_Cliente;
        char solucion[2];

        for(i=0;i<length;i++)
        {
            llamadasAux= (llamadas*) ll_get(this, i);

            id_Llamada=llamadas_getIdLlamadas(llamadasAux);
            id_Problema=llamadas_getIdProblema(llamadasAux);
            strcpy(fecha, llamadas_getFecha(llamadasAux));
            num_Cliente=llamadas_getNumCliente(llamadasAux);
            strcpy(solucion, llamadas_getSolucion(llamadasAux));

            fprintf(pFile, "%d,%s,%d,%d,%s\n", id_Llamada, fecha, num_Cliente,id_Problema,solucion);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(pFile);

    return retorno;
}
