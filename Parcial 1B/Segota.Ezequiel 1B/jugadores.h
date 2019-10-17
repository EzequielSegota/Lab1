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

/** \brief Saca un promedio.Lista los equipos menores al promedio
 *
 * \param eJugadores[]
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarEquiposJovenes(eJugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Lista jugadores por nombre
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipo int
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \return void
 *
 */
void listarJugadoresPorNombreConEquipo(eEquipo equipos[],int tamanioEquipo,eJugadores jugadores[],int tamanioJugadores);

/** \brief Consigue el id del siguiente jugador
 *
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \return int
 *
 */
int getNextIdJugador(eJugadores jugadores[],int tamanioJugadores);

/** \brief Inicializa estado de jugadores
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \return int
 *
 */
int iniciarEstadosJugadores(eJugadores jugadores [], int tamanioJugadores);

/** \brief Busca jugadores con estado libre
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \return int
 *
 */
int buscarJugadoresLibre(eJugadores jugadores [], int tamanioJugadores);

/** \brief Busca un jugador por ID
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \param idJugador int
 * \return int
 *
 */
int buscarJugador(eJugadores jugadores [], int tamanioJugadores,int idJugador);

/** \brief Cuenta si hay equipos activos y cuantos
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return int
 *
 */
int equiposActivos(eEquipo equipos[], int tamanioEquipos);

/** \brief Alta de jugadores
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \return void
 *
 */
void altaJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores);

/** \brief Lista los jugadores
 *
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarJugadores(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Muestra jugadores
 *
 * \param eJugadores[]
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void mostrarJugadores(eJugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Muestra un jugador
 *
 * \param eJugadores
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void mostrarJugador(eJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Hardcodea jugadores
 *
 * \param jugadores[] eJugadores
 * \return void
 *
 */
void hardcodeoJugadores(eJugadores jugadores[]);

/** \brief Baja de jugadores
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void bajaJugadores(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Carga la cadena con el nombre del equipo según su ID
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param idEquipo int
 * \param cadena[] char
 * \return void
 *
 */
void cargarEquipo(eEquipo equipos[], int tamanioEquipos,int idEquipo,char cadena[]);

/** \brief Modifica un jugador
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void modificarJugador(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
//void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[]);
//int clientesActivos(eCliente clientes[], int tamanioClientes);
/** \brief Lista jugadores por equipo
 *
 * \param [] eJugadores jugadores
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarJugadoresPorEquipo(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);

/** \brief Menu de listados
 *
 * \param void
 * \return int
 *
 */
int menuListadosJugadores(void);

/** \brief Menu ABM
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \return void
 *
 */
void abmJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores);


/** \brief Lista los jugadores por sexo
 *
 * \param jugadores[] eJugadores
 * \param tamanioJugadores int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarJugadoresPorSexo(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos);
#endif // ALQUILERES_H_INCLUDED
