#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;
typedef struct
{
    int idEquipo;
    char nombre[51];
    char localidad[33];
    int isEmpty;
} eEquipo;

/** \brief Menu principal
 *
 * \return int
 *
 */
int menu();

/** \brief Menu ABM
 *
 * \return int
 *
 */
int menuABM();

/** \brief Menu de listados
 *
 * \return int
 *
 */
int menuListadoEquipos();

/** \brief Listar el/los equipos con nombre más largo
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarEquiposConNombreMasLargo(eEquipo equipos[],int tamanioEquipos);

/** \brief Hardcodea equipos
 *
 * \param equipos[] eEquipo
 * \return void
 *
 */
void hardcodeoEquipos(eEquipo equipos[]);

/** \brief Consigue el siguente ID de equipo
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return int
 *
 */
int getNextId(eEquipo equipos[],int tamanioEquipos);

/** \brief Inicializa estados de equipos
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return int
 *
 */
int iniciarEstadosEquipos(eEquipo equipos[], int tamanioEquipos);

/** \brief Muestra un equipo
 *
 * \param equipos eEquipo
 * \return void
 *
 */
void mostrarEquipo(eEquipo equipos);

/** \brief Muestra los equipos
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void mostrarEquipos(eEquipo equipos[], int tamanioEquipos);

/** \brief Busca un posicion de equipo libre
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return int
 *
 */
int buscarEquiposLibre(eEquipo equipos[], int tamanioEquipos);

/** \brief Busca un equipo por ID
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \param idEquipo int
 * \return int
 *
 */
int buscarEquipo(eEquipo equipos[], int tamanioEquipos, int idEquipo);

/** \brief Alta de equipo
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void altaEquipo(eEquipo equipos[], int tamanioEquipos);

/** \brief Modificar equipo
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void modificarEquipo(eEquipo equipos[], int tamanioEquipos);

/** \brief Baja de equipo
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void bajaEquipo(eEquipo equipos[], int tamanioEquipos);

/** \brief Lista equipos
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void listarEquipos(eEquipo equipos[], int tamanioEquipos);

/** \brief ABM de equipos
 *
 * \param equipos[] eEquipo
 * \param tamanioEquipos int
 * \return void
 *
 */
void abmEquipos(eEquipo equipos[], int tamanioEquipos);
#endif // JUEGOS_H_INCLUDED
