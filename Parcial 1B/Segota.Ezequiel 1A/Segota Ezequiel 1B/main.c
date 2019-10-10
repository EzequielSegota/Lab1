#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "referi.h"
#include "equipo.h"
#include "jugadores.h"
#include "partido.h"
#define MAXEQUIPOS 4
#define MAXREFERI 3
#define MAXJUGADORES 3
int main()
{

    eEquipo equipos[MAXEQUIPOS];

    inicializarEquipo(equipos,MAXEQUIPOS);

    hardcodearEquipos(equipos,MAXEQUIPOS);

    menuEquipo(equipos,MAXEQUIPOS);

    return 0;
}
