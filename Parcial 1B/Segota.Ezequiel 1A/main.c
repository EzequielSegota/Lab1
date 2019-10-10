#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "utn.h"
#define TAM_EQUIPOS 5
#define TAM_CLIENTES 20
#define TAM_JUGADORES 10

int main()
{

    eEquipo equipos[TAM_EQUIPOS];
    eCliente clientes[TAM_CLIENTES];
    eJugadores jugadores[TAM_JUGADORES];
    char seguir = 's';

    iniciarEstadosEquipos(equipos, TAM_EQUIPOS);
    iniciarEstadosClientes(clientes, TAM_CLIENTES);
    iniciarEstadosJugadores(jugadores, TAM_JUGADORES);

    hardcodeoEquipos(equipos);
    hardcodeoClientes(clientes);

    do
    {
        switch(menu())
        {
        case 1:
            abmEquipos(equipos, TAM_EQUIPOS);
            system("pause");
            break;
        case 2:
            //abmClientes(clientes, TAM_CLIENTES);
            system("pause");
            break;
        case 3:
            abmJugadores(equipos, TAM_EQUIPOS, jugadores, TAM_JUGADORES);
            system("pause");
            break;
        case 4:
            //Partidos
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
