#include <stdio.h>
#include <stdlib.h>
#include "equipos.h"
#include "partidos.h"
#include "jugadores.h"
#include "referi.h"
#include "utn.h"
#define TAM_EQUIPOS 52
#define TAM_PARTIDOS 52
#define TAM_JUGADORES 52
#define TAM_REFERIS 52
int main()
{

    eEquipo equipos[TAM_EQUIPOS];
    eReferi referis[TAM_REFERIS];
    ePartido partidos[TAM_PARTIDOS];
    eJugadores jugadores[TAM_JUGADORES];
    char seguir = 's';

    iniciarEstadosEquipos(equipos, TAM_EQUIPOS);
    iniciarEstadosPartidos(partidos, TAM_PARTIDOS);
    iniciarEstadosJugadores(jugadores, TAM_JUGADORES);
    iniciarEstadosReferis(referis,TAM_REFERIS);

    hardcodeoEquipos(equipos);
    hardcodeoJugadores(jugadores);
    hardcodeoPartidos(partidos);
    hardcodeoReferis(referis);

    do
    {
        switch(menu())
        {
        case 1:
            abmEquipos(equipos, TAM_EQUIPOS);
            system("pause");
            break;
        case 2:
            abmJugadores(equipos, TAM_EQUIPOS, jugadores, TAM_JUGADORES);
            system("pause");
            break;
        case 3:
            abmReferis(referis,TAM_REFERIS);
            system("pause");
            break;
        case 4:
            //Partidos
            abmPartidos(partidos, TAM_PARTIDOS,equipos,TAM_EQUIPOS,referis,TAM_REFERIS);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");
        }
    }while(seguir == 's');
    return 0;
}
