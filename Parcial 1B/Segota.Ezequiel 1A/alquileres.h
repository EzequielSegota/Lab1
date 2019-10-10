#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idJugador;
    char apellido[31];
    char nombre[31];
    int idEquipo;
    char sexo;
    eFecha fechaNac;
    int isEmpty;
}eJugadores;

int getNextIdJugador(eJugadores jugadores[],int tamanioJugadores);
int iniciarEstadosJugadores(eJugadores jugadores [], int tamanioJugadores);
int buscarJugadoresLibre(eJugadores jugadores [], int tamanioJugadores);
int buscarJugador(eJugadores jugadores [], int tamanioJugadores,int idJugador);
int equiposActivos(eEquipo equipos[], int tamanioEquipos);


//int clientesActivos(eCliente clientes[], int tamanioClientes);

//void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[]);
//void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[]);

void abmJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores);

#endif // ALQUILERES_H_INCLUDED
