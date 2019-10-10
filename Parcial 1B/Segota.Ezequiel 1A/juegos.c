#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

int menu()
{
    int option;
    system("cls");
    printf(" *** MENU DE OPCIONES ***\n\n");
    printf("  1- Menu Equipos\n");
    printf("  2- Menu Jugadores\n");
    printf("  3- Menu Referis\n");
    printf("  4- Menu Partidos\n");
    printf("  5- Salir\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

int menuABM()
{
    int option;
    system("cls");
    printf(" *** ABM ***\n\n");
    printf("  1- Alta\n");
    printf("  2- Modificar\n");
    printf("  3- Baja\n");
    printf("  4- Listar\n");
    printf("  5- Salir\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

void hardcodeoEquipos(eEquipo equipos[])
{
    //char equipos[][51] = {"Cambios FC","Camboya","Dep Muy Caliente","Hacha y Birra","Bidon de Branco","Real Coholicos","Suc. Congreso","Sucursal Flores","Los Isotopos","Ornad + 4"};
    //char localidades[][33] = {"Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA","Lanus","Banfield","Avellaneda","CABA"};



    equipos[0].idEquipo = 1;
    strcpy(equipos[0].nombre, "A");
    strcpy(equipos[0].localidad, "AA");
    equipos[0].isEmpty = ACTIVO;

    equipos[1].idEquipo = 2;
    strcpy(equipos[1].nombre, "B");
    strcpy(equipos[1].localidad, "BB");
    equipos[1].isEmpty = ACTIVO;

    equipos[3].idEquipo = 3;
    strcpy(equipos[3].nombre, "D");
    strcpy(equipos[3].localidad, "DD");
    equipos[3].isEmpty = ACTIVO;

    equipos[4].idEquipo = 4;
    strcpy(equipos[4].nombre, "C");
    strcpy(equipos[4].localidad, "CC");
    equipos[4].isEmpty = ACTIVO;



}

int getNextId(eEquipo equipo[],int tamanioEquipos)
{
    int flag = 0;
    for(int i=0; i<tamanioEquipos; i++)
    {
        if(equipo[i].isEmpty == ACTIVO || equipo[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

int iniciarEstadosEquipos(eEquipo equipos [], int tamanioEquipos)
{
    int flag = -1;
    for(int i=0; i<tamanioEquipos; i++)
    {
        equipos[i].isEmpty = VACIO;
    }
    return flag;
}


int buscarEquiposLibre(eEquipo equipos[], int tamanioEquipos)
{
    int indice = -1;

    for(int i=0; i< tamanioEquipos; i++)
    {
        if( equipos[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEquipo(eEquipo equipos[], int tamanioEquipos, int idEquipos)
{
    int indice = -1;
    for(int i=0; i < tamanioEquipos; i++)
    {
        if(equipos[i].idEquipo == idEquipos && equipos[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEquipo(eEquipo equipos)
{

    printf("\t%d  | %s  |  %s  \n", equipos.idEquipo, equipos.nombre, equipos.localidad);

}

void mostrarEquipos(eEquipo equipos[], int tamanioEquipos)
{
    int i;
    printf("\n\tId  |     Nombre  |  Localidad\n\n");
    for(i=0; i<tamanioEquipos; i++){
        if(equipos[i].isEmpty == ACTIVO){
        mostrarEquipo(equipos[i]);
        }
    }
}

void altaEquipo(eEquipo equipos[], int tamanioEquipos)
{
    eEquipo nuevoEquipo;
    int indice;
    int idAux;
    char nombreAux[51];
    char localidadAux[31];

    system("cls");
    printf("  *** Alta Equipo ***\n\n");

    indice = buscarEquiposLibre(equipos, tamanioEquipos);
    if(indice == -1)
    {
        printf("No hay lugar para agregar mas equipos.\n\n");
    }
    else
    {
        idAux = getNextId(equipos, tamanioEquipos);

        getValidStringRango("Ingrese nombre: ", "Error, solo se admiten letras. Reintente.\n\n", nombreAux, 51);
        getValidStringRango("Ingrese localidad: ", "Error, solo se admiten letras. Reintente.\n\n", localidadAux, 33);


        nuevoEquipo.idEquipo = idAux;
        nuevoEquipo.isEmpty = ACTIVO;
        strcpy(nuevoEquipo.nombre, nombreAux);
        strcpy(nuevoEquipo.localidad, localidadAux);

        equipos[indice] = nuevoEquipo;
        printf("\nSe agrego nuevo equipo:\n\n");
        printf("\tId\tNombre\tLocalidad\n\n");
        mostrarEquipo(equipos[indice]);
        printf("\n");
    }
}

void modificarEquipo(eEquipo equipos[], int tamanioEquipos)
{
    int idEquipos;
    int indice;
    int opcion;
    char confirmacion;

    char nombreAux[51];
    char localidadAux[33];


    system("cls");
    printf("  *** Modificar Equipo ***\n\n");
    idEquipos = getValidInt("Ingrese el ID del equipo: ", "Error, solo se admiten numeros.\n\n");
    indice = buscarEquipo(equipos, tamanioEquipos, idEquipos);
    if( indice == -1)
    {
        printf("No hay ningun equipo con el ID %d\n\n", idEquipos);
    }
    else
    {
        printf("\n\tId\tNombre\tLocalidad\n\n");
        mostrarEquipo( equipos[indice]);
        printf("\n Menu de opciones\n\n1- Modificar nombre\n2- Modificar localidad\n3- Salir\n\n");
        opcion = getValidInt("Ingrese opcion: ", "Error, ingreso no valido. Reintente.\n\n");
        switch(opcion)
        {
        case 1:
            printf("\nModificar Nombre\n\n");
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", nombreAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", equipos[indice].nombre, nombreAux);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(equipos[indice].nombre, nombreAux);
                printf("Se modifico el nombre con exito.\n\n");
            }
            break;
        case 2:
            printf("\nModificar localidad\n\n");
            getValidStringRango("Ingrese nueva localidad: ", "Error, solo se admiten letras.\n", localidadAux, 33);
            printf("\nSe modificara \"%s\" por \"%s\"", equipos[indice].localidad, localidadAux);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion de la localidad.\n\n");
            }
            else
            {
                strcpy(equipos[indice].localidad, localidadAux);
                printf("Se modifico la localidad con exito.\n\n");
            }
            break;
        case 3:
            printf("\nAdios.");
            system("pause");
            break;
        default:
            printf("Error, opcion incorrecta.\n\n");

        }
    }

}

void bajaEquipo(eEquipo equipo[], int tamanioEquipo)
{
    int indice;
    int idEquipo;
    char confirmacion;

    system("cls");
    printf("  *** Baja Equipo ***\n\n");

    idEquipo = getValidInt("Ingrese el ID del juego: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarEquipo(equipo, tamanioEquipo, idEquipo);

    if( indice == -1)
    {
        printf("No hay ningun equipo con el ID: %d\n\n", idEquipo);
    }
    else
    {
        printf("\n\t Id\tNombre\tLocalidad\n\n");
        mostrarEquipo(equipo[indice]);
        printf("\nSe eliminara el equipo.\n");
        confirmacion = getValidChar("\nConfirma baja de juego (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            equipo[indice].isEmpty = BAJA;
            printf("Se ha eliminado el equipo con exito.\n\n");
        }
    }
}

void listarEquipos(eEquipo equipos[], int tamanioEquipos)
{
    system("cls");
    printf("  *** Lista de Equipos ***\n");
    printf("  Ordenados Alfabeticamente por Nombre.\n\n");
    eEquipo auxEquipo;
    for(int i=0; i<tamanioEquipos-1; i++)
    {
        for(int j=i+1; j<tamanioEquipos; j++)
        {
            if(strcmp(equipos[i].nombre, equipos[j].nombre) > 0)
            {
                auxEquipo = equipos[i];
                equipos[i] = equipos[j];
                equipos[j] = auxEquipo;
            }
        }
    }
    mostrarEquipos(equipos, tamanioEquipos);
    printf("\n");
}


void abmEquipos(eEquipo equipos[], int tamanioEquipos)
{
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        switch(menuABM())
        {
        case 1:
            altaEquipo(equipos, tamanioEquipos);
            system("pause");
            break;
        case 2:
            modificarEquipo(equipos, tamanioEquipos);
            system("pause");
            break;
        case 3:
            bajaEquipo(equipos, tamanioEquipos);
            system("pause");
            break;
        case 4:
            listarEquipos(equipos, tamanioEquipos);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");
        }
    }
    while(seguir == 's');
}
