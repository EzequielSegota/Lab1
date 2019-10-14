#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "equipos.h"
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

void listarEquiposJovenes(eJugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
void listarJugadoresPorNombreConEquipo(eEquipo equipos[],int tamanioEquipo,eJugadores jugadores[],int tamanioJugadores);
int getNextIdJugador(eJugadores jugadores[],int tamanioJugadores);
int iniciarEstadosJugadores(eJugadores jugadores [], int tamanioJugadores);
int buscarJugadoresLibre(eJugadores jugadores [], int tamanioJugadores);
int buscarJugador(eJugadores jugadores [], int tamanioJugadores,int idJugador);
int equiposActivos(eEquipo equipos[], int tamanioEquipos);
void altaJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores);
void listarJugadores(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
void mostrarJugadores(eJugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
void mostrarJugador(eJugadores,eEquipo equipos[], int tamanioEquipos);
void hardcodeoJugadores(eJugadores jugadores[]);
void bajaJugadores(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
void cargarEquipo(eEquipo equipos[], int tamanioEquipos,int idEquipo,char cadena[]);
void modificarJugador(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
//void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[]);
//int clientesActivos(eCliente clientes[], int tamanioClientes);
void listarJugadoresPorEquipo(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
int menuListadosJugadores(void);
void abmJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores);

#endif // ALQUILERES_H_INCLUDED
