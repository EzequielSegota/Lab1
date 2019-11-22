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
    int numClienteAux;
    int id_ProblemaAux;



    id_LlamadaAux=atoi(id_Llamada);
    numClienteAux=atoi(num_Cliente);
    id_ProblemaAux=atoi(id_Problema);

    this = llamadas_new();

    //printf("llamada-%d-problema-%d-fecha-%d-numcliente-%d-solucion-%d\n",llamadas_setIdLlamada(this,id_LlamadaAux),llamadas_setIdProblema(this,id_ProblemaAux),llamadas_setFecha(this,fecha),llamadas_setNumCliente(this,numClienteAux),llamadas_setSolucion(this,solucion));

     if(!llamadas_setIdLlamada(this,id_LlamadaAux) &&
        !llamadas_setIdProblema(this,id_ProblemaAux) &&
        !llamadas_setFecha(this,fecha) &&
        !llamadas_setNumCliente(this,numClienteAux) &&
        !llamadas_setSolucion(this,solucion)
       )
    {
        //printf("entro al constructor\n");
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

int llamadas_setNumCliente(llamadas* this, int num_Cliente)
{
    int retorno=-1;

    if(this!=NULL && num_Cliente>0)
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

int llamadas_setFecha(llamadas* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        retorno = 0;
        strcpy(this->fecha,fecha);
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

int llamadas_getFecha(llamadas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->fecha;
    }

    return retorno;
}

void llamadas_print(llamadas* this)
{
    int id_Llamadas;
    int id_Problemas;
    char fecha[20];
    int num_Cliente;
    char solucion[3];

    if(this != NULL)
    {

        id_Llamadas=llamadas_getIdLlamadas(this);
        id_Problemas=llamadas_getIdProblema(this);
        strcpy(fecha,llamadas_getFecha(this));
        num_Cliente=llamadas_getNumCliente(this);
        strcpy(solucion,llamadas_getSolucion(this));

        printf("%d\t\t%s\t%d\t\t\t%d\t%s\n", id_Llamadas,fecha, num_Cliente, id_Problemas, solucion);
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

int funcionQueFiltraUno(void* item)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==1)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraDos(void* item)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==2)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraTres(void* item)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==3)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraCuatro(void* item)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==4)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraCinco(void* item)
{
    int retorno=0;

    llamadas* aux;
    aux = (llamadas*) item;

    if(llamadas_getIdProblema(aux)==5)
    {
        retorno=1;
    }

    return retorno;
}



void llamadas_printAllProblemas(LinkedList* this)
{
    int i;
    int length;
    llamadas* aux;

    length=ll_len(this);

    printf("\nID Call\tFecha\t\tNum Cliente\t\tProblema\t\tSolucion\n");

    for(i=0;i<length;i++)
    {
        aux=ll_get(this,i);

        if(aux!=NULL)
        {
            llamadas_printProblema(aux);
        }
    }
}

void llamadas_printProblema(llamadas* this)
{
    int id_Llamadas;
    int id_Problemas;
    char fecha[20];
    int num_Cliente;
    char solucion[3];

    char problemaUno[30]={"NO ENCIENDE LA PC"};
    char problemaDos[30]={"NO FUNCIONA EL MOUSE"};
    char problemaTres[30]={"NO FUNCIONA EL TECLADO"};
    char problemaCuatro[30]={"NO HAY INTERNET"};
    char problemaCinco[30]={"NO FUNCIONA EL TELEFONO"};
    if(this != NULL)
    {

        id_Llamadas=llamadas_getIdLlamadas(this);
        id_Problemas=llamadas_getIdProblema(this);
        strcpy(fecha,llamadas_getFecha(this));
        num_Cliente=llamadas_getNumCliente(this);
        strcpy(solucion,llamadas_getSolucion(this));

        switch(id_Problemas)
        {
        case 1:
            printf("%d\t%s\t%d\t\t%s\t\t%s\n", id_Llamadas,fecha, num_Cliente, problemaUno, solucion);
            break;
        case 2:
            printf("%d\t%s\t%d\t\t%s\t\t%s\n", id_Llamadas,fecha, num_Cliente, problemaDos, solucion);
            break;
        case 3:
            printf("%d\t%s\t%d\t\t%s\t\t%s\n", id_Llamadas,fecha, num_Cliente, problemaTres, solucion);
            break;
        case 4:
            printf("%d\t%s\t%d\t\t%s\t\t\t%s\n", id_Llamadas,fecha, num_Cliente, problemaCuatro, solucion);
            break;
        case 5:
            printf("%d\t%s\t%d\t\t%s\t\t%s\n", id_Llamadas,fecha, num_Cliente, problemaCinco, solucion);
            break;
        default:
            printf("\nError");
        }
    }
}

