#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "llamadas.h"

llamadas* llamadas_new(void)
{
    llamadas* returnAux = (llamadas*) malloc(sizeof(llamadas));
    return returnAux;
}

llamadas* llamadas_newParametros(char* id_Llamada, char* fecha,char* num_Cliente, char* id_Problema, char* solucion)
{
    llamadas* this;

    int id_LlamadaAux;
    char diaAux[20];
    char mesAux[20];
    char anioAux[20];
    int numClienteAux;
    int id_ProblemaAux;

    int i=0;
    int flagBarraUno=0;
    int flagBarraDos=0;

    do
    {
        if(fecha[i]=='/' && flagBarraUno==0)
        {
            flagBarraUno=fecha[i];
            strncpy(diaAux,fecha,flagBarraUno);

        }else if(fecha[i]=='/' && flagBarraDos==0)
        {
            flagBarraDos=fecha[i];
            strncpy(mesAux,fecha+flagBarraUno,flagBarraDos);
        }
        else
        {
            strncpy(anioAux,fecha+flagBarraDos,strlen(fecha)-1);
        }
        i++;
    }while(fecha[i]!='\0');
    printf("%s",diaAux);
    id_LlamadaAux=atoi(id_Llamada);
    numClienteAux=atoi(num_Cliente);
    id_ProblemaAux=atoi(id_Problema);

    this = llamadas_new();

     if(!llamadas_setIdLlamada(this,id_LlamadaAux) &&
        !llamadas_setIdProblema(this,id_ProblemaAux) &&
        !llamadas_setDia(this,diaAux) &&
        !llamadas_setMes(this,mesAux) &&
        !llamadas_setAnio(this,anioAux) &&
        !llamadas_setNumCliente(this,numClienteAux) &&
        !llamadas_setSolucion(this,solucion)
       )
    {
        return this;
    }

    llamadas_delete(this);

    return NULL;
}

void llamadas_delete(llamadas* this)
{
    if(this != NULL)
    free(this);
}

int llamadas_setIdLlamada(llamadas* this, int id_Llamada)
{
    int retorno=-1;

    if(this!=NULL && id_Llamada>0)
    {
        retorno=0;

        this->id_Llamada=id_Llamada;
    }

    return retorno;
}

int llamadas_setIdProblema(llamadas* this, int id_Problema)
{
    int retorno=-1;

    if(this!=NULL && id_Problema>0)
    {
        retorno=0;

        this->id_Problema=id_Problema;
    }

    return retorno;
}

int llamadas_getIdLlamadas(llamadas* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id_Llamada;
    }

    return retorno;
}

int llamadas_getIdProblema(llamadas* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id_Problema;
    }

    return retorno;
}

int llamadas_setDia(llamadas* this, int dia)
{
    int retorno = -1;
    if(this != NULL)///Falta validar el dia
    {
        retorno = 0;
        this->dia=dia;
    }
    return retorno;
}

int llamadas_setMes(llamadas* this, int mes)
{
    int retorno = -1;
    if(this != NULL )///Falta validar mes
    {
        retorno = 0;
        this->mes=mes;
    }
    return retorno;
}

int llamadas_setAnio(llamadas* this, int anio)
{
    int retorno = -1;
    if(this != NULL)///Falta validar año
    {
        retorno = 0;
        this->anio=anio;
    }
    return retorno;
}

int llamadas_getDia(llamadas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->dia;
    }

    return retorno;
}

int llamadas_getMes(llamadas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->mes;
    }

    return retorno;
}

int llamadas_getAnio(llamadas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->anio;
    }

    return retorno;
}

int llamadas_setNumCliente(llamadas* this, int num_Cliente)
{
    int retorno=-1;

    if(this!=NULL && num_Cliente!=NULL)
    {
        retorno=0;
        this->num_Cliente=num_Cliente;
    }

    return retorno;
}

int llamadas_getNumCliente(llamadas* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->num_Cliente;
    }

    return retorno;
}

int llamadas_setSolucion(llamadas* this, char* solucion)
{
    int retorno = -1;
    if(this != NULL && solucion != NULL)
    {
        retorno = 0;
        strcpy(this->solucion,solucion);
    }
    return retorno;
}

int llamadas_getSolucion(llamadas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->solucion;
    }

    return retorno;
}

void llamadas_print(llamadas* this)
{
    int id_Llamadas;
    int id_Problemas;
    int dia;
    int mes;
    int anio;
    int num_Cliente;
    char solucion[2];

    if(this != NULL)
    {

        id_Llamadas=llamadas_getIdLlamadas(this);
        id_Problemas=llamadas_getIdProblema(this);
        dia=llamadas_getDia(this);
        mes=llamadas_getMes(this);
        anio=llamadas_getAnio(this);
        num_Cliente=llamadas_getNumCliente(this);
        strcpy(solucion,llamadas_getSolucion(this));

        printf("%d\t%2d/%2d/%4d\t\t%d\t\t%d\t%s\n", id_Llamadas,dia,mes,anio, num_Cliente, id_Problemas, solucion);
    }

}

void llamadas_printAll(LinkedList* this)
{
    int i;
    int length;
    llamadas* aux;

    length=ll_len(this);

    printf("\nID Call\tFecha\t\tNum Cliente\t\tID Prob\tSolucion\n");

    for(i=0;i<length;i++)
    {
        aux=ll_get(this,i);

        if(aux!=NULL)
        {
            llamadas_print(aux);
        }
    }
}

int funcionQueFiltra(void* item,int filter)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==filter)
    {
        retorno=1;
    }

    return retorno;
}
/*
void llamadas_printAllProblemas(LinkedList* this);
{

}

void llamadas_printProblema(llamadas* this)
{

}
*/
