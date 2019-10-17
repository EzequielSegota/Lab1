#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "equipos.h"
#include "referi.h"


typedef struct
{
    int idPartido;
    int idVisitante;
    int idLocal;
    int idReferi;
    int isEmpty;
    eFecha fechaPartido;
} ePartido;


/** \brief Hardcodea partidos
 *
 * \param partidos[] ePartido
 * \return void
 *
 */
void hardcodeoPartidos(ePartido partidos[]);

/** \brief Inicializa estado de partidos
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \return int
 *
 */
int iniciarEstadosPartidos(ePartido partido[], int tamanioPartido);

/** \brief Consigue el siguente ID de partido libre
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \return int
 *
 */
int getNextIdPartido(ePartido partido[], int tamanioPartido);

/** \brief Busca la siguente posiciòn de partido libre
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \return int
 *
 */
int buscarPartidoLibre(ePartido partido[], int tamanioPartido);

/** \brief Busca partido por ID
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param idPartido int
 * \return int
 *
 */
int buscarPartido(ePartido partido[], int tamanioPartido, int idPartido);

/** \brief Carga cadena con nombre de referi por su ID
 *
 * \param referi[] eReferi
 * \param tamanioReferi int
 * \param idReferi int
 * \param cadena[] char
 * \return void
 *
 */
void cargarReferi(eReferi referi[],int tamanioReferi,int idReferi,char cadena[]);

/** \brief Muestra un partido
 *
 * \param partido ePartido
 * \param localAux[] char
 * \param visitanteAux[] char
 * \param referiAux[] char
 * \return void
 *
 */
void mostrarPartido(ePartido partido,char localAux[],char visitanteAux[],char referiAux[]);

/** \brief Muestra los partidos
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void mostrarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

/** \brief Alta partido
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void altaPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

/** \brief Baja partido
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \return void
 *
 */
void bajaPartidos(ePartido partido[], int tamanioPartido);

/** \brief Lista partidos
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void listarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

/** \brief Muestra el referi con más partidos
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void mostrarReferiConMasPartidos(ePartido partido[], int tamanioPartido,eReferi referis[],int tamanioReferi);

/** \brief Lista los partidos por una fecha con los referi
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void listarEquiposYReferisPorFecha(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

/** \brief Menu listado
 *
 * \param void
 * \return int
 *
 */
int menuListadosPartidos(void);

/** \brief ABM de partidos
 *
 * \param partido[] ePartido
 * \param tamanioPartido int
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param referis[] eReferi
 * \param tamanioReferi int
 * \return void
 *
 */
void abmPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

void listarPartidosOrdenadosPorArbitro(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

void listarReferisConMasDeCuatrosPartidos(ePartido partido[], int tamanioPartido,eReferi referis[],int tamanioReferi);
#endif // CLIENTES_H_INCLUDED
