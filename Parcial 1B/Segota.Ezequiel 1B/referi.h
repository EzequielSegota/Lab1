#ifndef REFERI_H_INCLUDED
#define REFERI_H_INCLUDED
#include "equipos.h"
typedef struct
{
    int idReferi;
    char apellido[31];
    char nombre[31];
    int idEquipo;
    char sexo;
    char email[31];
    eFecha fechaNac;
    int isEmpty;
}eReferi;

/** \brief Consigue el ID del siguiente referi
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return int
 *
 */
int getNextIdReferi(eReferi referis[],int tamanioReferis);

/** \brief inicializa estados de referi
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return int
 *
 */
int iniciarEstadosReferis(eReferi referis[],int tamanioReferis);

/** \brief Busca referi con estado libre
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return int
 *
 */
int buscarReferisLibre(eReferi referis[],int tamanioReferis);

/** \brief Hardcodea referis
 *
 * \param referis[] eReferi
 * \return void
 *
 */
void hardcodeoReferis(eReferi referis[]);

/** \brief Menu ABM
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return void
 *
 */
void abmReferis(eReferi referis[],int tamanioReferis);

/** \brief Busca referi por ID
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \param idReferi int
 * \return int
 *
 */
int buscarReferi(eReferi referis[],int tamanioReferis,int idReferi);

/** \brief Alta de referi
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return void
 *
 */
void altaReferis(eReferi referis[],int tamanioReferis);

/** \brief Lista los referis
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return void
 *
 */
void listarReferis(eReferi referis[],int tamanioReferis);

/** \brief Muestra referis
 *
 * \param referis[] eReferi
 * \param tamanioReferis int
 * \return void
 *
 */
void mostrarReferis(eReferi referis[],int tamanioReferis);

/** \brief Muestra un referi
 *
 * \param referis eReferi
 * \return void
 *
 */
void mostrarReferi(eReferi referis);


#endif // REFERI_H_INCLUDED
