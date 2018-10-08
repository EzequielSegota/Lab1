#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Negocio.h"
void inicializarEstado(eJuegos juegos[],eCliente clientes[],eAlquiler alquileres[],int tamJuego,int tamCliente,int tamAlquiler)
{
    int i;
    for(i=0;i<tamJuego;i++)
    {
        juegos[i].isEmpty=0;
    }

    for(i=0;i<tamCliente;i++)
    {
        clientes[i].isEmpty=0;
    }

    for(i=0;i<tamAlquiler;i++)
    {
        alquileres[i].isEmpty=0;
    }
}

int menu()
{
    int opcion=-1;
    system("cls");
    do{
        printf("***Menu de Opciones***\n\n");
        printf("1- Juegos\n");
        printf("2- Clientes\n");
        printf("3- Alquileres\n");
        printf("4- Salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }while(opcion<1 || opcion>4);


    return opcion;
}

int menuJuegos(eJuegos juegos[],int tamJuego)
{
        int opcionDos;
        do{
            system("cls");
            printf("\nMenu Juegos:\n");
            printf("1.Alta\n");
            printf("2.Baja\n");
            printf("3.Modificacion\n");
            printf("4.Listar\n");
            printf("5.Salir\n");
            scanf("%d",&opcionDos);
        }while(opcionDos<1 || opcionDos>5);

        return opcionDos;
}
int menuClientes(eCliente cliente[],int tamJuego)
{
        int opcionDos;
        do{
            system("cls");
            printf("\nMenu Clientes:\n");
            printf("1.Alta\n");
            printf("2.Baja\n");
            printf("3.Modificacion\n");
            printf("4.Listar\n");
            printf("5.Salir\n");
            scanf("%d",&opcionDos);
        }while(opcionDos>5 || opcionDos<1);

        switch(opcionDos)
        {
            case 1:
                break;
        }



        return opcionDos;
}
int menuAlquiler(eAlquiler alquiler[],int tamAlquiler)
{
        int opcionDos;
        do{
            system("cls");
            printf("\nMenu Alquileres:\n");
            printf("1.Alta\n");
            printf("2.Baja\n");
            printf("3.Modificacion\n");
            printf("4.Listar\n");
            printf("5.Salir\n");
            scanf("%d",&opcionDos);
        }while(opcionDos>5 || opcionDos<1);

        return opcionDos;
}


int buscarLugarJuego(eJuegos x[],int tamJuegos)
{
    int indice = -1,i;
    for( i=0; i< tamJuegos; i++)
    {
        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLugarCliente(eCliente x[],int tamClientes)
{
    int indice = -1,i;

    for( i=0; i< tamClientes; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaJuego(eJuegos juego[],int tamJuego)
{

    eJuegos auxJuego;
    int indice,flag=-1;
    char descripcion[51];
    float importe;

    indice=buscarLugarJuego(juego,tamJuego);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        flag=1;
        printf("\nIngrese descripcion:");
        fflush(stdin);
        gets(descripcion);
        while(getStringLengh(descripcion,51)==-1)
        {
            printf("\nIngrese descripcion:");
            gets(descripcion);
        }
        auxJuego.id=siguienteIDJuego(juego,tamJuego);
        importe=getFloat("Ingrese importe:");
        strcpy(auxJuego.descripcion,descripcion);
        auxJuego.importe=importe;
        auxJuego.isEmpty=1;

        juego[indice]=auxJuego;
    }
    return flag;
}

int bajaJuego(eJuegos juego[],int tamJuego)
{
    int codigo,i,flag=0;

    printf("\nIngrese codigo a borrar:");
    scanf("%d",&codigo);
    for(i=0;i<tamJuego;i++)
    {
        if(juego[i].id==codigo)
        {
            flag=1;
            juego[i].isEmpty=0;
        }
    }
    if(flag!=1)
    {
        printf("\nError, codigo inexistente.");
    }

    return flag;
}

int siguienteIDJuego(eJuegos juego[],int tamJuego)
{
    int retorno = 0;
    int i;

        for(i=0; i<tamJuego; i++)
        {
            if(juego[i].isEmpty == 1)
            {
                    if(juego[i].id>retorno)
                    {
                         retorno=juego[i].id;
                    }

            }
        }

    return retorno+1;
}

int buscarJuego(eJuegos x[],int tamJuego,int codigo)
{
    int indice = -1,i;
    for(i=0; i < tamJuego; i++)
    {


        if( x[i].id == codigo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarJuego(eJuegos juego[],int tamJuego)
{
    int i,id,opcion;
    char descripcion[51];
    float importe;
    printf("\nIngrese codigo de juego:");
    scanf("%d",&id);
    i=buscarJuego(juego,tamJuego,id);
    if(i==-1)
    {
        printf("\nError, juego inexistente.");
    }
    else
    {

        printf("\n1.Descripcion.");
        printf("\n2.Importe.");
        printf("\n3.Salir.");
        printf("\n\tQue desea modificar?:");
        scanf("%d",&opcion);

        do{
            switch(opcion)
            {
                case 1:
                    printf("\nIngrese descripcion:");
                    fflush(stdin);
                    gets(descripcion);
                    while(getStringLengh(descripcion,51)==-1)
                    {
                        printf("\nIngrese descripcion:");
                        gets(descripcion);
                    }
                    strcpy(juego[i].descripcion,descripcion);
                    break;
                case 2:
                    importe=getFloat("Ingrese importe:");
                    juego[i].importe=importe;
                    break;
                case 3:
                    printf("\nAdios.");
                    break;
            }
        }while(opcion!=3);
    }
}

void mostrarJuegos(eJuegos juegos[], int tamJuego)
{
    int i;
    for(i=0; i< tamJuego; i++)
    {
        if( juegos[i].isEmpty == 1)
        {
            mostrarJuego(juegos[i]);
        }
    }
}

void mostrarJuego(eJuegos juego)
{
    printf("Codigo:%d\tDescripcion:%s\tImporte:%.2f\t\n\n", juego.id, juego.descripcion,juego.importe);

}
