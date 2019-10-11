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

int getNextIdReferi(eReferi referis[],int tamanioReferis);
int iniciarEstadosReferis(eReferi referis[],int tamanioReferis);
int buscarReferisLibre(eReferi referis[],int tamanioReferis);
void hardcodeoReferis(eReferi referis[]);

void abmReferis(eReferi referis[],int tamanioReferis);

int buscarReferi(eReferi referis[],int tamanioReferis,int idReferi);


void altaReferis(eReferi referis[],int tamanioReferis);
void listarReferis(eReferi referis[],int tamanioReferis);
void mostrarReferis(eReferi referis[],int tamanioReferis);
void mostrarReferi(eReferi referis);

#endif // REFERI_H_INCLUDED
