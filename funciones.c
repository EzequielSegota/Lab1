#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "funciones.h"
#include "llamadas.h"

int parser(FILE* pFile, LinkedList* this)
{
    int retorno = -1;

    char fecha[11];
    int dia;
    int mes;
    int anio;
    char id_Llamada[20];
    char id_Problema[20];
    char num_Cliente[20];
    char solucion[2];

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

        do
        {
            auxLlamadas = (llamadas*) malloc(sizeof(llamadas));

            fscanf(pFile,"%[^,],%d/%d%/%d,%[^,],%[^,],%[^\n]\n",id_Llamada,dia,mes,anio,num_Cliente,id_Problema,solucion);

            if(fscanf(pFile,"%[^,],%d/%d%/%d,%[^,],%[^,],%[^\n]\n",id_Llamada,&dia,&mes,&anio,num_Cliente,id_Problema,solucion)==7)
            {
                auxLlamadas = llamadas_newParametros(id_Llamada,dia,mes,anio, num_Cliente, id_Problema, solucion);
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

        int dia;
        int mes;
        int anio;
        int id_Llamada;
        int id_Problema;
        int num_Cliente;
        char solucion[2];

        for(i=0;i<length;i++)
        {
            llamadasAux= (llamadas*) ll_get(this, i);

            id_Llamada=llamadas_getIdLlamadas(llamadasAux);
            id_Problema=llamadas_getIdProblema(llamadasAux);
            dia=llamadas_getDia(llamadasAux);
            mes=llamadas_getMes(llamadasAux);
            anio=llamadas_getAnio(llamadasAux);
            num_Cliente=llamadas_getNumCliente(llamadasAux);
            strcpy(solucion, llamadas_getSolucion(llamadasAux));

            fprintf(pFile, "%d,%d,%d,%d,%d,%d,%s\n", id_Llamada, dia,mes,anio, num_Cliente,id_Problema,solucion);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(pFile);

    return retorno;
}
