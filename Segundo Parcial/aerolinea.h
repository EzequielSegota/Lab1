#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

struct
{
    char fecha[20];
    int id_Avion;
    int id_Piloto;
    int id_Vuelo;
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}typedef aerolinea;

/** \brief Constructor. Asigna espacio en memoria a una variable
 *
 * \param void
 * \return aerolinea* La variable de tipo empleador* a añadir.
 *
 */
aerolinea* aerolinea_new(void);

int aerolinea_CantidadPasajeros(void* this);
int aerolinea_CantidadPasajerosIrlanda(void* this);

/** \brief Libera espacio en memoria ocupado por una variable de tipo aerolinea*.
 *
 * \param this aerolinea* La variable de tipo empleador* a eliminar.
 * \return void
 *
 */
void aerolinea_delete(aerolinea* this);

/** \brief Se le asigna la ID a una variable de tipo aerolinea*.
 *
 *
 * \param this aerolinea* La variable donde se va a asignar la ID.
 * \param id int La ID a asignar.
 * \return int Devuelve -1 si la variable de tipo aerolinea* o la ID es menor a 0, sino devuelve 0.
 *
 */
int aerolinea_setIdAvion(aerolinea* this, int id_Llamada);
int aerolinea_setIdPiloto(aerolinea* this, int id_Piloto);
int aerolinea_setIdVuelo(aerolinea* this, int id_Vuelo);
int aerolinea_setHoraDespegue(aerolinea* this, int horaDespegue);
int aerolinea_setHoraLlegada(aerolinea* this, int horaLlegada);

/** \brief Obtiene la ID de una variable de tipo aerolinea*.
 *
 * \param this aerolinea* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo aerolinea* es igual a NULL, sino la direccion de memoria donde esta guardada la ID.
 *
 */
int aerolinea_getIdAvion(aerolinea* this);
int aerolinea_getIdPiloto(aerolinea* this);
int aerolinea_getIdVuelo(aerolinea* this);
int aerolinea_getHoraDespegue(aerolinea* this);
int aerolinea_getHoraLlegada(aerolinea* this);

/** \brief Se le asigna el nombre a una variable de tipo aerolinea*.
 *
 * \param this aerolinea* La variable donde se va a asignar el nombre.
 * \param nombre char* El nombre a asignar.
 * \return int Devuelve -1 si la variable de tipo aerolinea* o el nombre es igual a NULL, sino 0.
 *
 */
int aerolinea_setFecha(aerolinea* this, char* fecha);

/** \brief
 *
 * \param this aerolinea* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo aerolinea* es igual a NULL, sino la direccion de memoria donde esta guardado el nombre.
 *
 */
int aerolinea_getFecha(aerolinea* this);
/** \brief Se le asigna el sueldo a una variable de tipo aerolinea*.
 *
 * \param this aerolinea* La variable donde se va a asignar el sueldo.
 * \param sueldo char* El sueldo a asignar.
 * \return int Devuelve -1 si la variable de tipo aerolinea* o el sueldo es igual a NULL, sino 0.
 *
 */

/** \brief Obtiene el sueldo de una variable de tipo aerolinea*.
 *
 * \param this aerolinea* Variable en la que se obtiene el elemento.
 * \return int Devuelve -1 si la variable de tipo aerolinea* es igual a NULL, sino la direccion de memoria donde esta guardado el sueldo.
 *
 */

int aerolinea_setDestino(aerolinea* this, char* solucion);

/** \brief Obtiene la profesion de una variable de tipo aerolinea*.
 *
 * \param this aerolinea* Variable en la que se obtiene el elemento
 * \return int Devuelve -1 si la variable de tipo aerolinea* es igual a NULL, sino la direccion de memoria donde esta guardada la profesion.
 *
 */
int aerolinea_getDestino(aerolinea* this);

/** \brief
 *
 * \param this aerolinea*
 * \return void
 *
 */
void aerolinea_print(aerolinea* this);

void aerolinea_printVuelosAPortugal(aerolinea* this);

void aerolinea_printVuelosAPortugalAll(LinkedList* this);

/** \brief Muestra en pantalla todos los elementos del arraylist.
 *
 * \param this ArrayList* El arraylist a imprimir.
 * \return void
 *
 */
void aerolinea_printAll(LinkedList* this);

/** \brief Esta funcion llama a los setters para asi poder agregar elementos a una lista.
 *
 * \param id int El id del empleado.
 * \param nombre char* El nombre del empleado.
 * \param sueldo char* El sueldo del empleado.
 * \param edad int La edad del empleado.
 * \param profesion char* La profesion del empleado.
 * \return aerolinea* Una variable que contiene los datos de un empleado.
 *
 */
aerolinea* aerolinea_newParametros(char* id_Avion,char* id_Piloto,char* id_Vuelo, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue,char* horaLlegada);

/** \brief Filtra aerolinea segun su edad (mayores a 30) y profesion (Programador).
 *
 * \param item void* Empleado a filtrar.
 * \return int Devuelve 1 para mantener el elemento en la lista de salida y 0 para filtrarlo.
 *
 */
int funcionQueFiltraUno(void* item);

int funcionQueFiltraCuatro(void* item);

int funcionQueFiltraDos(void* item);

int funcionQueFiltraTres(void* item);

int funcionQueFiltraCinco(void* item);

void aerolinea_printAllProblemas(LinkedList* this);

void aerolinea_printProblema(aerolinea* this);

int funcionQueFiltraAlex(void* item);

int funcionQueFiltraVuelos(void* item);
#endif // aerolinea_H_INCLUDED
