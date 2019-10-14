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


void hardcodeoPartidos(ePartido partidos[]);

int iniciarEstadosPartidos(ePartido partido[], int tamanioPartido);

int getNextIdPartido(ePartido partido[], int tamanioPartido);

int buscarPartidoLibre(ePartido partido[], int tamanioPartido);

int buscarPartido(ePartido partido[], int tamanioPartido, int idPartido);

void cargarReferi(eReferi referi[],int tamanioReferi,int idReferi,char cadena[]);

void mostrarPartido(ePartido partido,char localAux[],char visitanteAux[],char referiAux[]);

void mostrarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

void altaPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

void bajaPartidos(ePartido partido[], int tamanioPartido);

void listarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

void mostrarReferiConMasPartidos(ePartido partido[], int tamanioPartido,eReferi referis[],int tamanioReferi);

void listarEquiposYReferisPorFecha(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);

int menuListadosPartidos(void);

void abmPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi);
#endif // CLIENTES_H_INCLUDED
