#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Negocio.h"
#define ELEMENTS 30

int main()
{
    eJuegos juegos[ELEMENTS];
    eCliente clientes[ELEMENTS];
    eAlquiler alquiler[ELEMENTS];
    int flagMenus;
    char seguir='s',seguirDos='s';

    inicializarEstado(juegos,clientes,alquiler,ELEMENTS,ELEMENTS,ELEMENTS);

    do{
        switch(menu())
        {
            case 1:
                do
                {
                    switch(menuJuegos(juegos,ELEMENTS))
                    {
                        case 1:
                            altaJuego(juegos,ELEMENTS);
                            system("pause");
                            break;
                        case 2:
                            bajaJuego(juegos,ELEMENTS);
                            system("pause");
                            break;
                        case 3:
                            modificarJuego(juegos,ELEMENTS);
                            system("pause");
                            break;
                        case 4:
                            mostrarJuegos(juegos,ELEMENTS);
                            system("pause");
                            break;
                        case 5:
                            printf("\nAdios.");
                            seguir='n';
                            system("pause");
                            break;
                                }
                }while(seguir=='s');

                break;
            case 2:
                do{

                    flagMenus=menuClientes(clientes,ELEMENTS);
                    system("pause");
                }while(flagMenus!=5);

                break;
            case 3:
                menuAlquiler(alquiler,ELEMENTS);

                break;
            case 4:
                printf("\nAdios.");
                seguirDos='n';
                break;
        }
    }while(seguirDos=='s');




    return 0;
}
