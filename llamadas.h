#ifndef LLAMADAS_H_INCLUDED
#define LLAMADAS_H_INCLUDED

struct
{
    int dia;
    int mes;
    int anio;
    int id_Llamada;
    int id_Problema;
    int num_Cliente;
    char solucion[2];

}typedef llamadas;

/** \brief Constructor. Asigna espacio en memoria a una variable
 *
 * \param void
 * \return llamadas* La variable de tipo empleador* a añadir.
 *
 */
llamadas* llamadas_new(void);

/** \brief Libera espacio en memoria ocupado por una variable de tipo llamadas*.
 *
 * \param this llamadas* La variable de tipo empleador* a eliminar.
 * \return void
 *
 */
void llamadas_delete(llamadas* this);

/** \brief Se le asigna la ID a una variable de tipo llamadas*.
 *
 *
 * \param this llamadas* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo llamadas* o la ID es menor a 0, sino devuelve 0.
 *
 */
int llamadas_setIdLlamada(llamadas* this, int id_Llamada);
int llamadas_setIdProblema(llamadas* this, int id_Problema);
/** \brief Obtiene la ID de una variable de tipo llamadas*.
 *
 * \param this llamadas* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo llamadas* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int llamadas_getIdLlamadas(llamadas* this);
int llamadas_getIdProblema(llamadas* this);
/** \brief Se le asigna el nombre a una variable de tipo llamadas*.
 *
 * \param this llamadas* La variable donde se va a asignar el nombre.
 * \param nombre char* El nombre a asignar.
 * \return int Devuelve -1 si la variable de tipo llamadas* o el nombre es igual a NULL, sino 0.
 *
 */
int llamadas_setDia(llamadas* this, int dia);
int llamadas_setMes(llamadas* this, int mes);
int llamadas_setAnio(llamadas* this, int anio);

/** \brief
 *
 * \param this llamadas* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo llamadas* es igual a NULL, sino la direccion de memoria donde esta guardado el nombre.
 *
 */
int llamadas_getDia(llamadas* this);
int llamadas_getMes(llamadas* this);
int llamadas_getAnio(llamadas* this);
/** \brief Se le asigna el sueldo a una variable de tipo llamadas*.
 *
 * \param this llamadas* La variable donde se va a asignar el sueldo.
 * \param sueldo char* El sueldo a asignar.
 * \return int Devuelve -1 si la variable de tipo llamadas* o el sueldo es igual a NULL, sino 0.
 *
 */
int llamadas_setNumCliente(llamadas* this,int num_Cliente);

/** \brief Obtiene el sueldo de una variable de tipo llamadas*.
 *
 * \param this llamadas* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo llamadas* es igual a NULL, sino la direccion de memoria donde esta guardado el sueldo.
 *
 */
int llamadas_getNumCliente(llamadas* this);

int llamadas_setSolucion(llamadas* this, char* solucion);

/** \brief Obtiene la profesion de una variable de tipo llamadas*.
 *
 * \param this llamadas* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo llamadas* es igual a NULL, sino la direccion de memoria donde esta guardada la profesion.
 *
 */
int llamadas_getSolucion(llamadas* this);

/** \brief
 *
 * \param this llamadas*
 * \return void
 *
 */
void llamadas_print(llamadas* this);

/** \brief Muestra en pantalla todos los elementos del arraylist.
 *
 * \param this ArrayList* El arraylist a imprimir.
 * \return void
 *
 */
void llamadas_printAll(LinkedList* this);

/** \brief Esta funcion llama a los setters para asi poder agregar elementos a una lista.
 *
 * \param id int El id del empleado.
 * \param nombre char* El nombre del empleado.
 * \param sueldo char* El sueldo del empleado.
 * \param edad int La edad del empleado.
 * \param profesion char* La profesion del empleado.
 * \return llamadas* Una variable que contiene los datos de un empleado.
 *
 */
llamadas* llamadas_newParametros(char* id_Llamada, int dia,int mes,int anio, char* num_Cliente, char* id_Problema, char* solucion);

/** \brief Filtra llamadas segun su edad (mayores a 30) y profesion (Programador).
 *
 * \param item void* Empleado a filtrar.
 * \return int Devuelve 1 para mantener el elemento en la lista de salida y 0 para filtrarlo.
 *
 */
int funcionQueFiltra(void* item, int filter);

void llamadas_printAllProblemas(LinkedList* this);

void llamadas_printProblema(llamadas* this);

#endif // llamadas_H_INCLUDED
