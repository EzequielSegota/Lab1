#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "utn.h"
#define TAM_JUEGOS 20
#define TAM_CLIENTES 20
#define TAM_ALQUILERES 20

int main()
{

    eJuego juegos[TAM_JUEGOS];
    eCliente clientes[TAM_CLIENTES];
    eAlquiler alquileres[TAM_ALQUILERES];
    char seguir = 's';

    iniciarEstadosJuegos(juegos, TAM_JUEGOS);
    iniciarEstadosClientes(clientes, TAM_CLIENTES);
    iniciarEstadosAlquileres(alquileres, TAM_ALQUILERES);

    hardcodeoJuegos(juegos);
    hardcodeoClientes(clientes);

    do
    {
        switch(menu())
        {
        case 1:
            abmJuegos(juegos, TAM_JUEGOS);
            system("pause");
            break;
        case 2:
            abmClientes(clientes, TAM_CLIENTES);
            system("pause");
            break;
        case 3:
            abmAlquiler(juegos, TAM_JUEGOS, clientes, TAM_CLIENTES, alquileres, TAM_ALQUILERES);
            system("pause");
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");
        }
    }while(seguir == 's');
    return 0;
}
