#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init(EPersona lista[], int len){
    int i;
    for(i=0; i<len; i++){
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len){
    int i;
    int retorno = -1;

    for(i=0; i<len; i++){
        if(lista[i].isEmpty == 1){
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(EPersona lista[], int len){
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1){
        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(lista[index].nombre);

        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(lista[index].apellido);

        printf("\nIngrese DNI:");
        scanf("%ld",&lista[index].dni);

        printf("\nIngrese día de nacimiento:");
        scanf("%d",&lista[index].feNac.dia);

        printf("\nIngrese mes de nacimiento:");
        scanf("%d",&lista[index].feNac.mes);

        printf("\nIngrese año de nacimiento:");
        scanf("%d",&lista[index].feNac.anio);

        lista[index].isEmpty=0;

        system("cls");
    }
    else{
        system("cls");
        printf("\nError, no hay espacio libre.\n");
    }

    return;
}

void mostrar(EPersona lista[],int largo)
{
    int i;
    ordenar(lista,largo);
    for(i=0;i<largo;i++)
    {
        if(lista[i].isEmpty==0)
        printf("\nNombre:%s\tApellido:%s\tDNI:%ld\tFecha de Nacimiento:%d/%d/%d\n",lista[i].nombre,lista[i].apellido,lista[i].dni,lista[i].feNac.dia,lista[i].feNac.mes,lista[i].feNac.anio);
    }
}

int buscarPorDni(EPersona lista[],long int DNI,int len)
{
    int i,retorno=-1;

    for(i=0;i<len;i++)
    {
        if(lista[i].dni==DNI)
        {
          retorno=i;
        }
    }

    return retorno;
}


void baja(EPersona lista[],int tam)
{
    long int dni;
    int i;
    system("cls");
    mostrar(lista, tam);

    printf("\nIngrese DNI a borrar:");
    scanf("%ld",&dni);
    i=buscarPorDni(lista,dni,tam);
    if(i==-1)
    {
        system("cls");
        printf("\nError,DNI no encontrado.\n");
    }
    else
    {
        lista[i].isEmpty=1;
    }
}

void modificar(EPersona lista[],int largo)
{
    long int dni;
    int i;
    mostrar(lista, largo);

    printf("\nIngrese DNI a modificar:");
    scanf("%ld",&dni);
    i=buscarPorDni(lista,dni,largo);
    if(i==-1)
    {
        system("cls");
        printf("\nError,DNI no encontrado.\n");
    }
    else
    {
        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(lista[i].apellido);

        printf("\nIngrese DNI:");
        scanf("%ld",&lista[i].dni);

        printf("\nIngrese día de nacimiento:");
        scanf("%d",&lista[i].feNac.dia);

        printf("\nIngrese mes de nacimiento:");
        scanf("%d",&lista[i].feNac.mes);

        printf("\nIngrese año de nacimiento:");
        scanf("%d",&lista[i].feNac.anio);

        system("cls");
        mostrar(lista, largo);
    }
}

void ordenar(EPersona lista[],int largo)
{
    int i,j;
    EPersona aux;
    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido)>0)
            {
                aux=lista[i];

                lista[i]=lista[j];
                lista[j]=aux;
            }else if(strcmp(lista[i].apellido,lista[j].apellido)==0  && strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}
