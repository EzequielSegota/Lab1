#include "equipo.h"
#include "referi.h"
#include "jugadores.h"
#include "utn.h"

void menuEquipo(eEquipo equipo[],int tamEquipo)
{
    char respuesta= 's';
    int opcion;
    do
    {
        printf("\n---Que desea hacer?---");
        printf("\n1.Alta");
        printf("\n2.Listar");
        printf("\n9.Salir");

        opcion=getValidInt("\nIngrese una opcion:","Error debe ser entre 1 y 2",1,2);

        switch(opcion)
        {
        case 1:
            altaEquipo(equipo,tamEquipo);
            break;
        case 2:
            system("cls");
            mostrarEquipos(equipo,tamEquipo);
            system("pause");
            break;
        case 9:
            system("cls");
            printf("\nAdios");
            respuesta='n';
            break;
        default:
            printf("\nIngrese una opcion valida");
        }


    }
    while(respuesta=='s');

}

void inicializarEquipo(eEquipo equipos[],int tamEquipo)
{
    int i;
    for(i=0; i<tamEquipo; i++)
    {
        equipos[i].codigo=0;
        strcpy(equipos[i].nombre,"");
        strcpy(equipos[i].localidad,"");
    }
}

int buscarSiguienteLibre(eEquipo equipos[],int tamEquipos)
{
    int i,auxIndice=-2;
    for(i=0; i<tamEquipos; i++)
    {
        if(equipos[i].codigo==0)
        {
            auxIndice=i;
            break;
        }
    }
    return auxIndice;
}

int siguienteCodigo(eEquipo equipos[],int tamEquipo)
{
    int i,auxIndice=-2;
    for(i=0; i<tamEquipo; i++)
    {
        if(equipos[i].codigo==0)
        {
            auxIndice=i;
            break;
        }
    }
    return auxIndice+1;
}

void altaEquipo(eEquipo equipos[],int tamEquipos)
{
    char nombreAux[52];
    char localidadAux[33];
    int codigoAux,libre;

    libre=buscarSiguienteLibre(equipos,tamEquipos);
    codigoAux=siguienteCodigo(equipos,tamEquipos);

    if(codigoAux!=-1 || libre!=-1)
    {
        do
        {
            printf("\nIngrese un nombre:");
            gets(nombreAux);
            fflush(stdin);
        }
        while(strlen(nombreAux)>52);

        do
        {
            printf("\nIngrese un localidad:");
            gets(localidadAux);
            fflush(stdin);
        }
        while(strlen(localidadAux)>33);

        strcpy(equipos[libre].nombre,nombreAux);
        strcpy(equipos[libre].localidad,localidadAux);
        equipos[libre].codigo=codigoAux;
    }
    else
    {
        printf("\nNo hay lugar..");
    }

}

void ordenarEquiposAlf(eEquipo equipos[],int tamEquipos)
{
    eEquipo auxEquipo;
    int i,j;
    for(i=0; i<tamEquipos-1; i++)
    {
        for(j=i+1; j<tamEquipos; j++)
        {
            if(strcmp(equipos[i].nombre,equipos[j].nombre)!=-1)
            {
                auxEquipo=equipos[i];
                equipos[i]=equipos[j];
                equipos[j]=auxEquipo;
            }
        }
    }
}

void mostrarEquipo(eEquipo equipos)
{
    if(strlen(equipos.nombre)>7 && strlen(equipos.localidad)>7)
    {
        printf("\n%s\t%s\t%d",equipos.nombre,equipos.localidad,equipos.codigo);
    }
    else
    {
        printf("\n%s\t\t%s\t\t%d",equipos.nombre,equipos.localidad,equipos.codigo);
    }
}

void mostrarEquipos(eEquipo equipos[],int tamEquipos)
{
    int i;
    printf("\nNombre   |   Localidad   |   Codigo");
    ordenarEquiposAlf(equipos,tamEquipos);
    for(i=0; i<tamEquipos; i++)
    {
        if(equipos[i].codigo!=0)
        {
            mostrarEquipo(equipos[i]);
        }
    }
}

void hardcodearEquipos(eEquipo equipos[],int cant)
{
    int i;
    char nombre[4][32]={"ArgJ","ZZ","EE","BB"};
    char localidad[4][32]={"Ezeiza","Avellaneda","Banfield","Temperley"};
    int id[4]={1,2,3,4};
    for(i=0;i<cant;i++)
    {
        strcpy(equipos[i].nombre,nombre[i]);
        strcpy(equipos[i].localidad,localidad[i]);
        equipos[i].codigo=id[i];
    }
}
