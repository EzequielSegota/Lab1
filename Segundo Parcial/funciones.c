#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "funciones.h"
#include "aerolinea.h"

int parser(FILE* pFile, LinkedList* this)
{
    int retorno = -1;

    char fecha[20];
    char id_Vuelo[20];
    char id_Piloto[20];
    char id_Avion[20];
    char cantPasajeros[20];
    char horaDespegue[20];
    char horaLlegada[20];
    char num_Cliente[20];
    char destino[30];

    char nomArchivo[50];

    aerolinea* auxLlamadas;

    printf("Ingrese nombre del archivo a abrir: ");
    fflush(stdin);
    gets(nomArchivo);

    pFile = fopen(nomArchivo, "r");

    if(pFile != NULL)
    {
        retorno = 0;

        printf("\nID Vuelo\tID Avion\tID Piloto\tFecha\t\tDestino\t\tCantPasajeros\tHora Despegue\tHora Llegada\n");
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_Vuelo,id_Avion,id_Piloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

        do
        {
          //  auxLlamadas = (llamadas*) malloc(sizeof(llamadas));


            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id_Vuelo,id_Avion,id_Piloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada)==8)
            {
                //printf("test");
                auxLlamadas = aerolinea_newParametros(id_Avion,id_Piloto,id_Vuelo,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                //printf("%s", fecha);
                ll_add(this,auxLlamadas);
                aerolinea_print(auxLlamadas);
            }
        }while(!feof(pFile));

    }

    fclose(pFile);

    return retorno;
}


int crearArchivo(FILE* pFile, LinkedList* this)
{
    aerolinea* llamadasAux;

    int i, length;
    int retorno=-1;

    pFile = fopen("out.csv", "w");

    if(pFile!=NULL)
    {
        length=ll_len(this);
        retorno=0;

        char fecha[20];
        int id_Avion;
        int id_Piloto;
        int id_Vuelo;
        int cantPasajeros;
        int horaDespegue;
        int horaLlegada;
        char destino[30];

        for(i=0;i<length;i++)
        {
            llamadasAux= (aerolinea*) ll_get(this, i);

            id_Avion=aerolinea_getIdAvion(llamadasAux);
            id_Piloto=aerolinea_getIdPiloto(llamadasAux);
            id_Vuelo=aerolinea_getIdVuelo(llamadasAux);
            horaDespegue=aerolinea_getHoraDespegue(llamadasAux);
            horaLlegada=aerolinea_getHoraLlegada(llamadasAux);
            strcpy(fecha, aerolinea_getFecha(llamadasAux));
            cantPasajeros=aerolinea_getCantPasajeros(llamadasAux);
            strcpy(destino, aerolinea_getDestino(llamadasAux));

            fprintf(pFile, "%d,%d,%d,%s,%s,%d,%d,%d\n", id_Vuelo,id_Avion,id_Piloto, fecha,destino ,cantPasajeros,horaDespegue,horaLlegada);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(pFile);

    return retorno;
}
