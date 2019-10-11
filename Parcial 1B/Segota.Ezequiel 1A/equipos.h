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

int menu();
int menuABM();
void hardcodeoEquipos(eEquipo equipos[]);
int getNextId(eEquipo equipos[],int tamanioEquipos);
int iniciarEstadosEquipos(eEquipo equipos[], int tamanioEquipos);
void mostrarEquipo(eEquipo equipos);
void mostrarEquipos(eEquipo equipos[], int tamanioEquipos);
int buscarEquiposLibre(eEquipo equipos[], int tamanioEquipos);
int buscarEquipo(eEquipo equipos[], int tamanioEquipos, int idEquipo);
void altaEquipo(eEquipo equipos[], int tamanioEquipos);
void modificarEquipo(eEquipo equipos[], int tamanioEquipos);
void bajaEquipo(eEquipo equipos[], int tamanioEquipos);
void listarEquipos(eEquipo equipos[], int tamanioEquipos);
void abmEquipos(eEquipo equipos[], int tamanioEquipos);

#endif // JUEGOS_H_INCLUDED
