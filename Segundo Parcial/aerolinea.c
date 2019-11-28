#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "aerolinea.h"

aerolinea* aerolinea_new(void)
{
    aerolinea* returnAux = (aerolinea*) malloc(sizeof(aerolinea));
    return returnAux;
}

aerolinea* aerolinea_newParametros(char* id_Avion,char* id_Piloto,char* id_Vuelo, char* fecha,char* destino,char* cantPasajeros, char* horaDespegue,char* horaLlegada)
{
    aerolinea* this;

    int id_VueloAux;
    int id_PilotoAux;
    int id_AvionAux;
    int horaDespegueAux;
    int horaLlegadaAux;
    int cantPasajerosAux;


    id_VueloAux=atoi(id_Vuelo);
    id_PilotoAux=atoi(id_Piloto);
    id_AvionAux=atoi(id_Avion);
    horaDespegueAux=atoi(horaDespegue);
    horaLlegadaAux=atoi(horaLlegada);
    cantPasajerosAux=atoi(cantPasajeros);

    this = aerolinea_new();

    //printf("llamada-%d-problema-%d-fecha-%d-numcliente-%d-solucion-%d\n",aerolinea_setIdLlamada(this,id_LlamadaAux),aerolinea_setIdProblema(this,id_ProblemaAux),aerolinea_setFecha(this,fecha),aerolinea_setNumCliente(this,numClienteAux),aerolinea_setSolucion(this,solucion));

     if(!aerolinea_setIdVuelo(this,id_VueloAux) &&
        !aerolinea_setIdAvion(this,id_AvionAux) &&
        !aerolinea_setIdPiloto(this,id_PilotoAux) &&
        !aerolinea_setFecha(this,fecha) &&
        !aerolinea_setHoraDespegue(this,horaDespegueAux) &&
        !aerolinea_setHoraLlegada(this,horaLlegadaAux) &&
        !aerolinea_setCantPasajeros(this,cantPasajerosAux) &&
        !aerolinea_setDestino(this,destino)
       )
    {
        //printf("entro al constructor\n");
        return this;
    }

    aerolinea_delete(this);

    return NULL;
}

void aerolinea_delete(aerolinea* this)
{
    if(this != NULL)
    free(this);
}

int aerolinea_setIdAvion(aerolinea* this, int id_Avion)
{
    int retorno=-1;

    if(this!=NULL && id_Avion>0)
    {
        retorno=0;

        this->id_Avion=id_Avion;
    }

    return retorno;
}

int aerolinea_setIdVuelo(aerolinea* this, int id_Vuelo)
{
    int retorno=-1;

    if(this!=NULL && id_Vuelo>0)
    {
        retorno=0;

        this->id_Vuelo=id_Vuelo;
    }

    return retorno;
}

int aerolinea_setIdPiloto(aerolinea* this, int id_Piloto)
{
    int retorno=-1;

    if(this!=NULL && id_Piloto>0)
    {
        retorno=0;

        this->id_Piloto=id_Piloto;
    }

    return retorno;
}

int aerolinea_setHoraDespegue(aerolinea* this, int horaDespegue)
{
    int retorno=-1;

    if(this!=NULL && horaDespegue>0)
    {
        retorno=0;

        this->horaDespegue=horaDespegue;
    }

    return retorno;
}

int aerolinea_setHoraLlegada(aerolinea* this, int horaLlegada)
{
    int retorno=-1;

    if(this!=NULL && horaLlegada>0)
    {
        retorno=0;

        this->horaLlegada=horaLlegada;
    }

    return retorno;
}

int aerolinea_getIdAvion(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id_Avion;
    }

    return retorno;
}

int aerolinea_getIdVuelo(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id_Vuelo;
    }

    return retorno;
}

int aerolinea_getIdPiloto(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->id_Piloto;
    }

    return retorno;
}

int aerolinea_getHoraDespegue(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->horaDespegue;
    }

    return retorno;
}

int aerolinea_getHoraLlegada(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->horaLlegada;
    }

    return retorno;
}

int aerolinea_setCantPasajeros(aerolinea* this, int cantPasajeros)
{
    int retorno=-1;

    if(this!=NULL && cantPasajeros>0)
    {
        retorno=0;
        this->cantPasajeros=cantPasajeros;
    }

    return retorno;
}

int aerolinea_getCantPasajeros(aerolinea* this)
{
    int retorno=-1;

    if(this!=NULL)
    {
        retorno=this->cantPasajeros;
    }

    return retorno;
}

int aerolinea_setDestino(aerolinea* this, char* destino)
{
    int retorno = -1;
    if(this != NULL && destino != NULL)
    {
        retorno = 0;
        strcpy(this->destino,destino);
    }
    return retorno;
}

int aerolinea_setFecha(aerolinea* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL)
    {
        retorno = 0;
        strcpy(this->fecha,fecha);
    }
    return retorno;
}

int aerolinea_getDestino(aerolinea* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->destino;
    }

    return retorno;
}

int aerolinea_getFecha(aerolinea* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->fecha;
    }

    return retorno;
}

void aerolinea_print(aerolinea* this)
{
    int id_Avion;
    int id_Vuelo;
    int id_Piloto;
    char fecha[20];
    int cantPasajeros;
    char destino[30];
    int horaLlegada;
    int horaDespegue;

    if(this != NULL)
    {

        id_Avion=aerolinea_getIdAvion(this);
        id_Piloto=aerolinea_getIdPiloto(this);
        id_Vuelo=aerolinea_getIdVuelo(this);
        horaDespegue=aerolinea_getHoraDespegue(this);
        horaLlegada=aerolinea_getHoraLlegada(this);
        strcpy(fecha,aerolinea_getFecha(this));
        cantPasajeros=aerolinea_getCantPasajeros(this);
        strcpy(destino,aerolinea_getDestino(this));

        if(strlen(destino)==5)
        {
            printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
        }
        else if(strlen(destino)==6 || strlen(destino)==7)
        {
            printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
        }
        else
        {
            printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
        }
    }

}

void aerolinea_printAll(LinkedList* this)
{
    int i;
    int length;
    aerolinea* aux;

    length=ll_len(this);

    printf("\nID Vuelo\tID Avion\tID Piloto\tFecha\t\tDestino\t\tCantPasajeros\t\tHora Despegue\tHora Llegada\n");

    for(i=0;i<length;i++)
    {
        aux=ll_get(this,i);

        if(aux!=NULL)
        {
            aerolinea_print(aux);
        }
    }
}

int funcionQueFiltraUno(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(aerolinea_getIdPiloto(aux)==1)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraDos(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(aerolinea_getIdPiloto(aux)==2)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraTres(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(aerolinea_getIdPiloto(aux)==3)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraCuatro(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(aerolinea_getIdPiloto(aux)==4)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraCinco(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(aerolinea_getIdPiloto(aux)==5)
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraAlex(void* item)
{
    int retorno=0;

    aerolinea* aux;
    aux = (aerolinea*) item;

    if(!(aerolinea_getIdPiloto(aux)==1))
    {
        retorno=1;
    }

    return retorno;
}

int funcionQueFiltraVuelos(void* item)
{
    int retorno=0,auxLlegada,auxSalida;

    aerolinea* aux;
    aux = (aerolinea*) item;


    if(aux!=NULL)
    {
        auxSalida=aerolinea_getHoraDespegue(aux);
        auxLlegada=aerolinea_getHoraLlegada(aux);
        if(auxLlegada-auxSalida<3)
        {
            retorno=1;
        }
    }

    return retorno;
}

void aerolinea_printAllProblemas(LinkedList* this)
{
    int i;
    int length;
    aerolinea* aux;

    length=ll_len(this);

    printf("\nID Vuelo\tID Avion\tPiloto\t\tFecha\t\tDestino\t\tCantPasajeros\t\tHora Despegue\tHora Llegada\n");
    for(i=0;i<length;i++)
    {
        aux=ll_get(this,i);

        if(aux!=NULL)
        {
            aerolinea_printProblema(aux);
        }
    }
}

void aerolinea_printVuelosAPortugal(aerolinea* this)
{
    int id_Avion;
    int id_Vuelo;
    int id_Piloto;
    char fecha[20];
    int cantPasajeros;
    char destino[30];
    int horaLlegada;
    int horaDespegue;

    if(this != NULL)
    {

        id_Avion=aerolinea_getIdAvion(this);
        id_Piloto=aerolinea_getIdPiloto(this);
        id_Vuelo=aerolinea_getIdVuelo(this);
        horaDespegue=aerolinea_getHoraDespegue(this);
        horaLlegada=aerolinea_getHoraLlegada(this);
        strcpy(fecha,aerolinea_getFecha(this));
        cantPasajeros=aerolinea_getCantPasajeros(this);
        strcpy(destino,aerolinea_getDestino(this));

        if(strcmp("Portugal",aerolinea_getDestino(this))==0)
        {
            if(strlen(destino)==5)
            {
                printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
            }
            else if(strlen(destino)==6 || strlen(destino)==7)
            {
                printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
            }
            else
            {
                printf("%d\t\t%d\t\t%d\t\t%s\t%s\t\t%d\t\t%d\t\t%d\n", id_Vuelo,id_Avion,id_Piloto,fecha,destino ,cantPasajeros, horaDespegue, horaLlegada);
            }
        }
    }
}

void aerolinea_printVuelosAPortugalAll(LinkedList* this)
{
    int i;
    int length;
    aerolinea* aux;

    length=ll_len(this);

    printf("\nID Vuelo\tID Avion\tID Piloto\tFecha\t\tDestino\t\tCantPasajeros\t\tHora Despegue\tHora Llegada\n");

    for(i=0;i<length;i++)
    {
        aux=ll_get(this,i);

        if(aux!=NULL)
        {
            aerolinea_printVuelosAPortugal(aux);
        }
    }
}

void aerolinea_printProblema(aerolinea* this)
{
    int id_Avion;
    int id_Vuelo;
    int id_Piloto;
    char fecha[20];
    int cantPasajeros;
    char destino[30];
    int horaLlegada;
    int horaDespegue;

    char problemaUno[30]={"Alex Lifeson"};
    char problemaDos[30]={"Richard Bach"};
    char problemaTres[30]={"John Kerry"};
    char problemaCuatro[30]={"Erwin Rommel"};
    char problemaCinco[30]={"Stephen Coonts"};
    if(this != NULL)
    {

        id_Avion=aerolinea_getIdAvion(this);
        id_Vuelo=aerolinea_getIdVuelo(this);
        id_Piloto=aerolinea_getIdPiloto(this);
        horaDespegue=aerolinea_getHoraDespegue(this);
        horaLlegada=aerolinea_getHoraLlegada(this);
        strcpy(fecha,aerolinea_getFecha(this));
        cantPasajeros=aerolinea_getCantPasajeros(this);
        strcpy(destino,aerolinea_getDestino(this));

        switch(id_Piloto)
        {
        case 1:
            printf("%d\t\t%d\t\t%s\t%s\t%s\t\t%d\t%d\t%d\n", id_Vuelo,id_Avion,problemaUno,fecha,destino ,cantPasajeros,horaDespegue , horaLlegada);
            break;
        case 2:
            printf("%d\t\t%d\t\t%s\t%s\t%s\t\t%d\t%d\t%d\n", id_Vuelo,id_Avion,problemaDos,fecha,destino ,cantPasajeros,horaDespegue , horaLlegada);
            break;
        case 3:
            printf("%d\t\t%d\t\t%s\t%s\t%s\t\t%d\t%d\t%d\n", id_Vuelo,id_Avion,problemaTres,fecha,destino ,cantPasajeros,horaDespegue , horaLlegada);
            break;
        case 4:
            printf("%d\t\t%d\t\t%s\t%s\t%s\t\t%d\t%d\t%d\n", id_Vuelo,id_Avion,problemaCuatro,fecha,destino ,cantPasajeros,horaDespegue , horaLlegada);
            break;
        case 5:
            printf("%d\t\t%d\t\t%s\t%s\t%s\t\t%d\t%d\t%d\n", id_Vuelo,id_Avion,problemaCinco,fecha,destino ,cantPasajeros,horaDespegue , horaLlegada);
            break;
        default:
            printf("\nError");
        }
    }
}

int aerolinea_CantidadPasajeros(void* this)
{
    int auxCantPasajeros=0,i;
    aerolinea* aux;
    aux=(aerolinea*) this;
    if(aux!=NULL)
    {
        auxCantPasajeros=aerolinea_getCantPasajeros(aux);
    }
    return auxCantPasajeros;
}

int aerolinea_CantidadPasajerosIrlanda(void* this)
{
    int auxCantPasajeros=0,i;
    aerolinea* aux;
    aux=(aerolinea*) this;

    if(aux!=NULL && strcmp("Irlanda",aerolinea_getDestino(aux))==0)
    {
        auxCantPasajeros=aerolinea_getCantPasajeros(aux);
    }
    return auxCantPasajeros;
}
