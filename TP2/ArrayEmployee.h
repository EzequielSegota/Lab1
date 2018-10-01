#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

typedef struct
{
    int id;
    char description[20];

}eSector;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Menu de opciones.
 *
 * \param void
 * \return int Opcion elegida
 *
 */
int menu(void);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len);


/** \brief Busca en el array un lugar libre
 *
 * \param list Employee*
 * \param len int
 * \return int Devuelve el indice del lugar vacio o -1 si no hay lugar
 *
 */
int buscarLugar(Employee* list, int len);

/** \brief Comprueba que el id no este en uso
 *
 * \param list Employee*
 * \param len int
 * \return void
 *
 */
int comprobarID(Employee* list,int len,int id);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length,eSector* sectores);

#endif // FUNCIONES_H_INCLUDED
