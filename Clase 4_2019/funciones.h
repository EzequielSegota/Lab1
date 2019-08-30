#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
/** \brief Esta funcion pide un entero entre ciertos limites(no valida NUMEROS)
 *
 * \param msj char* El mensaje que muestra
 * \param msjError char* El mensaje de error en caso de no estar dentro de los limites el numero ingresado
 * \param int minimo El minimo numero
 * \param int maximo El maximo numero
 * \return int Retorna el numero que ingreso el usuario(-1 en caso de ser incorrecto)
 *
 */
int pedirEntero(char *msj,char* msjError,int minimo,int maximo);






#endif // FUNCIONES_H_INCLUDED
