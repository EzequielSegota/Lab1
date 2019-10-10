#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

int getNextIdJugador(eJugadores jugadores[],int tamanioJugadores)
{
    int flag = 0;
    for(int i=0; i<tamanioJugadores; i++)
    {
        if(jugadores[i].isEmpty == ACTIVO || jugadores[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

int iniciarEstadosJugadores(eJugadores jugadores [], int tamanioJugadores)
{
    int flag = -1;
    for(int i=0; i<tamanioJugadores; i++)
    {
        jugadores[i].isEmpty = VACIO;
    }
    return flag;
}


int buscarJugadoresLibre(eJugadores jugadores[], int tamanioJugadores)
{
    int indice = -1;

    for(int i=0; i< tamanioJugadores; i++)
    {

        if( jugadores[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJugador(eJugadores jugadores[], int tamanioJugadores, int idJugador)
{
    int indice = -1;
    for(int i=0; i < tamanioJugadores; i++)
    {
        if(jugadores[i].idJugador == idJugador && jugadores[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void abmJugadores(eEquipo equipos[], int tamanioEquipos, eJugadores jugadores[], int tamanioJugadores)
{
    eJugadores jugadoresAux;
    int indice;

    int idAux;
    int idEquipoAux;
    int diaAux;
    int mesAux;
    int anioAux;

    int equiposActivosAux;

    char nombreEquipo[51];

    system("cls");
    printf(" *** ALTA JUGADOR ***\n\n");
    equiposActivosAux = equiposActivos(equipos, tamanioEquipos);

    indice = buscarJugadoresLibre(jugadores, tamanioJugadores);
    if(indice == -1)
    {
        printf("No hay lugar para la carga de jugadores.\n\n");
    }
    else
    {
        idAux = getNextIdJugador(jugadores, tamanioJugadores);
        if(equiposActivosAux != 0){
            mostrarEquipos(equipos, tamanioEquipos);
            idEquipoAux = getValidIntRango("\nIngrese equipo: ", "Error de ingreso. Reintente.\n\n", 1, equiposActivosAux);
        }
        else{
            printf("\nAun no se han cargado equipos.\n\n");
        }

        diaAux = getValidIntRango("Ingrese dia de nac: ", "Error de ingreso, reintente.\n\n", 1, 31);
        mesAux = getValidIntRango("Ingrese mes de nac: ", "Error de ingreso, reintente.\n\n", 1, 12);
        anioAux = getValidIntRango("Ingrese anio de nac (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2018);

        jugadoresAux.idJugador = idAux;
        jugadoresAux.idEquipo = idEquipoAux;
        jugadoresAux.fechaNac.dia = diaAux;
        jugadoresAux.fechaNac.mes = mesAux;
        jugadoresAux.fechaNac.anio = anioAux;
        jugadoresAux.isEmpty = ACTIVO;

        jugadores[indice] = jugadoresAux;

        system("cls");
        printf("\nSe agrego nuevo jugador.\n\n");
    }
}

int equiposActivos(eEquipo equipos[], int tamanioEquipos)
{
    int equiposActivos= 0;
    for(int i=0; i<tamanioEquipos; i++)
    {
        if(equipos[i].isEmpty == ACTIVO)
        {
            equiposActivos++;
        }
    }
    return equiposActivos;
}
/*
int clientesActivos(eCliente clientes[], int tamanioClientes)
{
    int clientesActivos=0;
    for(int i=0; i<tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO)
        {
            clientesActivos++;
        }
    }
    return clientesActivos;
}


void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[])
{
    for(int i=0; i < tamanioClientes; i++)
    {
        if( clientes[i].idCliente == idCliente)
        {
            strcpy(cadena, clientes[i].nombre);
            break;
        }
    }
}

void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[])
{
    for(int i=0; i < tamanioJuegos; i++)
    {
        if( juegos[i].idJuego == idJuego)
        {
            strcpy(cadena, juegos[i].descripcion);
            break;
        }
    }
}
*/
