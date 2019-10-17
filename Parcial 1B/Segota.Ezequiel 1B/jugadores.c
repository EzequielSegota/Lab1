#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugadores.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2
#define ANIO_ACTUAL 2019

int getNextIdJugador(eJugadores jugadores[],int tamanioJugadores)
{
    int flag = 0;
    for(int i=0; i<tamanioJugadores; i++)
    {
        if(jugadores[i].isEmpty == VACIO || jugadores[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

void hardcodeoJugadores(eJugadores jugadores[])
{
    char Nombres[][50]={"JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL","JUAN","JOSE LUIS","JOSE","MARIA GUADALUPE","FRANCISCO","GUADALUPE","MARIA","JUANA","ANTONIO","JESUS","MIGUEL ANGEL","PEDRO","ALEJANDRO","MANUEL","MARGARITA","MARIA DEL CARMEN","JUAN CARLOS","ROBERTO","FERNANDO","DANIEL","CARLOS","JORGE","RICARDO","MIGUEL","EDUARDO","JAVIER","RAFAEL","MARTIN","RAUL","DAVID","JOSEFINA","JOSE ANTONIO","ARTURO","MARCO ANTONIO","JOSE MANUEL"};
    char Sexo[] = {'M','M','M','F','M','F','F','F','M','M','M','M','M','M','F','F','M','M','M','M','M','M','M','M','M','M','M','M','M','M','F','M','M','M','M'};
    char Apellido[][50]= {"Gonzales","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz","Gonzalez","Rodriguez","Gomez","Fernandez","Lopez","Diaz","Martinez","Perez","Romero","Sanchez","Garcia","Sosa","Torres","Ramirez","Alvarez","Benitez","Acosta","Flores","Medina","Ruiz"};
    int codigoEquipos[] = { 1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10};
    int anios[]={ 2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995,2000, 2001,2000,1998,1995};
    int mes[]={ 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1, 1,3,5,7,8,10,12,5,4,6,3,1};
    int dia[]= { 25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22,25,30,29,10,1,5,4,2,8,18,19,6,11,22};

    for(int i=0;i<50;i++)
    {
        jugadores[i].idJugador=i+1;
        jugadores[i].fechaNac.dia=dia[i];
        jugadores[i].fechaNac.mes=mes[i];
        jugadores[i].fechaNac.anio=anios[i];
        jugadores[i].sexo=Sexo[i];
        jugadores[i].idEquipo=codigoEquipos[i];
        strcpy(jugadores[i].nombre,Nombres[i]);
        strcpy(jugadores[i].apellido,Apellido[i]);

        jugadores[i].isEmpty=ACTIVO;
    }
}

int iniciarEstadosJugadores(eJugadores jugadores [], int tamanioJugadores)
{
    int flag = -1;
    for(int i=0; i<tamanioJugadores; i++)
    {
        jugadores[i].isEmpty = VACIO;
    }
    return flag;
}

void bajaJugadores(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    int indice;
    int idJugador;
    char confirmacion;

    system("cls");
    printf("  *** Baja Jugador ***\n\n");
    mostrarJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);
    idJugador = getValidInt("\nIngrese el ID del jugador: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarJugador(jugadores, tamanioJugadores, idJugador);

    if( indice == -1)
    {
        printf("No hay ningun jugador con el ID: %d\n\n", idJugador);
    }
    else
    {
        printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento  | Equipo\n\n");
        mostrarJugador(jugadores[indice],equipos,tamanioEquipos);
        printf("\nSe eliminara el jugador.\n");
        confirmacion = getValidChar("\nConfirma baja del jugador (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            jugadores[indice].isEmpty = BAJA;
            printf("Se ha eliminado el jugador con exito.\n\n");
        }
    }
}

int buscarJugadoresLibre(eJugadores jugadores[], int tamanioJugadores)
{
    int indice = -1;

    for(int i=0; i< tamanioJugadores; i++)
    {

        if( jugadores[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJugador(eJugadores jugadores[], int tamanioJugadores, int idJugador)
{
    int indice = -1;
    for(int i=0; i < tamanioJugadores; i++)
    {
        if(jugadores[i].idJugador == idJugador && jugadores[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void listarJugadoresPorSexo(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    system("cls");
    printf("  *** Lista de Jugadores ***\n");
    printf("  Ordenados por Sexo.\n\n");
    eJugadores auxJugador;
    for(int i=0; i<tamanioJugadores-1; i++)
    {
        for(int j=i+1; j<tamanioJugadores; j++)
        {
            if(jugadores[i].sexo>jugadores[j].sexo)
            {
                auxJugador = jugadores[i];
                jugadores[i] = jugadores[j];
                jugadores[j] = auxJugador;
            }
        }
    }
    mostrarJugadores(jugadores, tamanioJugadores,equipos,tamanioEquipos);
    printf("\n");
}

void abmJugadores(eEquipo equipos[], int tamanioEquipos, eJugadores jugadores[], int tamanioJugadores)
{
    char seguir = 's'; //Bandera continuar do-while.
    char seguirDos = 's';
    do
    {
        switch(menuABM())
        {
        case 1:
            altaJugadores(equipos, tamanioEquipos,jugadores,tamanioJugadores);
            system("pause");
            break;
        case 2:
            modificarJugador(jugadores,tamanioJugadores,equipos,tamanioEquipos);
            system("pause");
            break;
        case 3:
            bajaJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);
            system("pause");
            break;
        case 4:
            do
            {
                switch(menuListadosJugadores())
                {
                    case 1:
                        mostrarJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);
                        system("pause");
                        break;
                    case 2:
                        listarJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);
                        system("pause");
                        break;
                    case 3:
                        listarJugadoresPorEquipo(jugadores,tamanioJugadores,equipos,tamanioEquipos);
                        system("pause");
                        break;
                    case 4:
                        listarJugadoresPorNombreConEquipo(equipos,tamanioEquipos,jugadores,tamanioJugadores);
                        system("pause");
                        break;
                    case 5:
                        listarEquiposJovenes(jugadores,tamanioJugadores,equipos,tamanioEquipos);
                        system("pause");
                        break;
                    case 6:
                        listarJugadoresPorSexo(jugadores,tamanioJugadores,equipos,tamanioEquipos);
                        system("pause");
                        break;
                    case 7:
                        system("cls");
                        seguirDos='n';
                        printf("\nAdios\n");
                        break;
                    default:
                        printf("\nError\n");


                }
            }while(seguirDos=='s');

            //listarJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");
        }
    }
    while(seguir == 's');
}

void listarEquiposJovenes(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    int acumulador=0,contador=0,i,j,edadAux;
    float promedio;

    for(j=0;j<tamanioJugadores;j++)
    {
        if(jugadores[j].isEmpty==ACTIVO)
        {
            edadAux=ANIO_ACTUAL-jugadores[j].fechaNac.anio;
            acumulador=acumulador+edadAux;
            contador++;
        }
    }

    promedio=acumulador/contador;

    printf("\n---- Equipos mas jovenes (PROMEDIO:%.2f)----",promedio);
    printf("\n\tId  |      Nombre     |    Localidad\n\n");
    for(i=0;i<tamanioEquipos;i++)
    {
        acumulador=0;
        if(equipos[i].isEmpty==ACTIVO)
        {
            for(j=0;j<tamanioJugadores;j++)
            {
                if(jugadores[j].isEmpty==ACTIVO && jugadores[j].idEquipo==equipos[i].idEquipo)
                {
                    edadAux=ANIO_ACTUAL-jugadores[j].fechaNac.anio;
                    acumulador=acumulador+edadAux;
                }
            }
            if(acumulador<promedio)
                mostrarEquipo(equipos[i]);
        }
    }

}

int equiposActivos(eEquipo equipos[], int tamanioEquipos)
{
    int equiposActivos= 0;
    for(int i=0; i<tamanioEquipos; i++)
    {
        if(equipos[i].isEmpty == ACTIVO)
        {
            equiposActivos++;
        }
    }
    return equiposActivos;
}

void altaJugadores(eEquipo equipos[], int tamanioEquipos,eJugadores jugadores[], int tamanioJugadores)
{
    eJugadores jugadoresAux;
    int indice;

    int idAux;
    int idEquipoAux;
    char nombreJugadorAux[31];
    char apellidoJugadorAux[31];
    char sexoAux;
    int diaAux;
    int mesAux;
    int anioAux;

    int equiposActivosAux;
    int indiceAux;

    system("cls");
    printf(" *** ALTA JUGADOR ***\n\n");
    equiposActivosAux = equiposActivos(equipos, tamanioEquipos);

    indice = buscarJugadoresLibre(jugadores, tamanioJugadores);
    if(indice == -1)
    {
        printf("No hay lugar para la carga de jugadores.\n\n");
    }
    else
    {
        idAux = getNextIdJugador(jugadores, tamanioJugadores);
        if(equiposActivosAux != 0){
            mostrarEquipos(equipos, tamanioEquipos);
            do{
                idEquipoAux = getValidIntRango("\nIngrese equipo: ", "Error de ingreso. Reintente.\n\n", 1, tamanioEquipos);
                indiceAux=buscarEquipo(equipos,tamanioEquipos,idEquipoAux);
            }while(equipos[indiceAux].isEmpty!=ACTIVO);

            getValidStringRango("Ingrese nombre de jugador: ", "Error, solo se admiten letras. Reintente.\n\n", nombreJugadorAux, 31);
            getValidStringRango("Ingrese apellido de jugador: ", "Error, solo se admiten letras. Reintente.\n\n", apellidoJugadorAux, 31);

            sexoAux=getValidChar("\nIngrese sexo: ","Error, debe ser M o F",'M','F');

            diaAux = getValidIntRango("Ingrese dia de nac: ", "Error de ingreso, reintente.\n\n", 1, 31);
            mesAux = getValidIntRango("Ingrese mes de nac: ", "Error de ingreso, reintente.\n\n", 1, 12);
            anioAux = getValidIntRango("Ingrese anio de nac (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2018);

            jugadoresAux.idJugador = idAux;
            jugadoresAux.idEquipo = idEquipoAux;
            strcpy(jugadoresAux.nombre, nombreJugadorAux);
            strcpy(jugadoresAux.apellido, apellidoJugadorAux);
            jugadoresAux.sexo=sexoAux;
            jugadoresAux.fechaNac.dia = diaAux;
            jugadoresAux.fechaNac.mes = mesAux;
            jugadoresAux.fechaNac.anio = anioAux;
            jugadoresAux.isEmpty = ACTIVO;

            jugadores[indice] = jugadoresAux;

            system("cls");
            mostrarJugador(jugadores[indice] ,equipos,tamanioEquipos);
            printf("\nSe agrego nuevo jugador.\n\n");
        }
        else{
            printf("\nAun no se han cargado equipos.\n\n");
        }
    }
}

void listarJugadores(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    system("cls");
    printf("  *** Lista de Jugadores ***\n");
    printf("  Ordenados Alfabeticamente por Nombre.\n\n");
    eJugadores auxJugador;
    for(int i=0; i<tamanioJugadores-1; i++)
    {
        for(int j=i+1; j<tamanioJugadores; j++)
        {
            if(strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0)
            {
                auxJugador = jugadores[i];
                jugadores[i] = jugadores[j];
                jugadores[j] = auxJugador;
            }
        }
    }
    mostrarJugadores(jugadores, tamanioJugadores,equipos,tamanioEquipos);
    printf("\n");
}
void mostrarJugadores(eJugadores jugadores[],int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    int i;
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento  | Equipo\n\n");
    for(i=0;i<tamanioJugadores;i++)
    {
        if(jugadores[i].isEmpty==ACTIVO)
        {
            mostrarJugador(jugadores[i],equipos,tamanioEquipos);
        }
    }

}
void mostrarJugador(eJugadores jugador,eEquipo equipos[], int tamanioEquipos)
{
    char auxEquipo[51];
    cargarEquipo(equipos,tamanioEquipos,jugador.idEquipo,auxEquipo);
    printf("\n\t%3d  |  %16s  |  %16s  |  %c  |  %2d/%2d/%4d  | %16s",jugador.idJugador,jugador.nombre,jugador.apellido,jugador.sexo,jugador.fechaNac.dia,jugador.fechaNac.mes,jugador.fechaNac.anio,auxEquipo);
}


void listarJugadoresPorNombreConEquipo(eEquipo equipos[],int tamanioEquipo,eJugadores jugadores[],int tamanioJugadores)
{
    char nombreAux[31];

    getValidStringRango("\nIngrese nombre a buscar:","Error, solo se admiten letras. Reintente.\n",nombreAux,31);
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento  | Equipo\n");
    for(int i=0;i<tamanioJugadores;i++)
    {
        if(strcmp(nombreAux,jugadores[i].nombre)==0 && jugadores[i].isEmpty==ACTIVO)
        {
            mostrarJugador(jugadores[i],equipos,tamanioEquipo);
        }
    }
}


void cargarEquipo(eEquipo equipos[], int tamanioEquipos,int idEquipo,char cadena[])
{
    for(int i=0; i < tamanioEquipos; i++)
    {
        if( equipos[i].idEquipo == idEquipo)
        {
            strcpy(cadena, equipos[i].nombre);
            break;
        }
    }
}

void modificarJugador(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    int idJugador,idEquipoAux,diaAux,mesAux,anioAux;
    int indice,indiceAux;
    int opcion,opcionFecha;
    char confirmacion,sexAux;


    char nombreEquipoAux[51];
    char nombreEquipoActualAux[51];

    char nombreAux[31];
    char apellidoAux[31];


    system("cls");
    printf("  *** Modificar Jugador ***\n\n");
    mostrarJugadores(jugadores,tamanioJugadores,equipos,tamanioEquipos);

    idJugador = getValidInt("Ingrese el ID del jugador: ", "Error, solo se admiten numeros.\n\n");
    indice = buscarJugador(jugadores, tamanioJugadores, idJugador);
    if( indice == -1)
    {
        printf("No hay ningun jugador con el ID %d\n\n", idJugador);
    }
    else
    {
        system("cls");
        printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento  | Equipo\n\n");
        mostrarJugador(jugadores[indice],equipos,tamanioEquipos);


        printf("\n\nMenu de opciones\n\n1- Modificar nombre\n2- Modificar apellido\n3- Modificar Sexo\n4- Modificar Fecha\n5- Modificar Equipo\n6- Salir\n\n");
        opcion = getValidInt("\nIngrese opcion: ", "Error, ingreso no valido. Reintente.\n\n");
        switch(opcion)
        {
            case 1:
                printf("\nModificar Nombre\n\n");
                getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", nombreAux, 31);
                printf("\nSe modificara \"%s\" por \"%s\"", jugadores[indice].nombre, nombreAux);
                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del nombre.\n\n");
                }
                else
                {
                    strcpy(jugadores[indice].nombre, nombreAux);
                    printf("Se modifico el nombre con exito.\n\n");
                }
                break;
            case 2:
                printf("\nModificar apellido\n\n");
                getValidStringRango("Ingrese nuevo apellido: ", "Error, solo se admiten letras.\n", apellidoAux, 31);
                printf("\nSe modificara \"%s\" por \"%s\"", jugadores[indice].apellido, apellidoAux);
                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del apellido.\n\n");
                }
                else
                {
                    strcpy(jugadores[indice].apellido, apellidoAux);
                    printf("Se modifico el apellido con exito.\n\n");
                }
                break;
            case 3:
                printf("\nModificar sexo\n\n");
                sexAux=getValidChar("Ingrese sexo F/M: ", "Error, debe ser F o M.\n", 'F', 'M');
                printf("\nSe modificara \"%c\" por \"%c\"", jugadores[indice].sexo, sexAux);
                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del sexo.\n\n");
                }
                else
                {
                    jugadores[indice].sexo=sexAux;
                    printf("Se modifico el sexo con exito.\n\n");
                }
                break;
            case 4:
                printf("\n\nMenu de Fecha\n\n1- Modificar dia\n2- Modificar mes\n3- Modificar anio\n4- Salir\n\n");
                opcionFecha=getValidInt("\nIngrese opcion:","Error, ingreso no valido. Reintente.\n\n");
                switch(opcionFecha)
                {
                    case 1:
                        diaAux = getValidIntRango("Ingrese dia de nac: ", "Error de ingreso, reintente.\n\n", 1, 31);
                        printf("\nSe modificara \"%d\" por \"%d\"", jugadores[indice].fechaNac.dia, diaAux);
                        confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                        if(confirmacion == 'n')
                        {
                            printf("Se cancelo la modificacion del dia.\n\n");
                        }
                        else
                        {
                            jugadores[indice].fechaNac.dia=diaAux;
                            printf("Se modifico el dia con exito.\n\n");
                        }
                        break;
                    case 2:
                        mesAux = getValidIntRango("Ingrese mes de nac: ", "Error de ingreso, reintente.\n\n", 1, 12);
                        printf("\nSe modificara \"%d\" por \"%d\"", jugadores[indice].fechaNac.mes, mesAux);
                        confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                        if(confirmacion == 'n')
                        {
                            printf("Se cancelo la modificacion del mes.\n\n");
                        }
                        else
                        {
                            jugadores[indice].fechaNac.mes=mesAux;
                            printf("Se modifico el mes con exito.\n\n");
                        }

                        break;
                    case 3:
                        anioAux = getValidIntRango("Ingrese anio de nac (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2018);
                        printf("\nSe modificara \"%d\" por \"%d\"", jugadores[indice].fechaNac.anio, anioAux);
                        confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                        if(confirmacion == 'n')
                        {
                            printf("Se cancelo la modificacion del anio.\n\n");
                        }
                        else
                        {
                            jugadores[indice].fechaNac.anio=anioAux;
                            printf("Se modifico el anio con exito.\n\n");
                        }
                        break;
                    case 4:
                        printf("\nAdios.");
                        system("pause");
                        break;
                    default:
                        printf("Error, opcion incorrecta.\n\n");
                }
                break;
            case 5:
                mostrarEquipos(equipos, tamanioEquipos);
                do{
                    idEquipoAux = getValidIntRango("\nIngrese equipo: ", "Error de ingreso. Reintente.\n\n", 1, tamanioEquipos);
                    indiceAux=buscarEquipo(equipos,tamanioEquipos,idEquipoAux);
                }while(equipos[indiceAux].isEmpty!=ACTIVO);


                cargarEquipo(equipos,tamanioEquipos,jugadores[indice].idEquipo ,nombreEquipoActualAux);
                cargarEquipo(equipos,tamanioEquipos,idEquipoAux,nombreEquipoAux);

                printf("\nSe modificara \"%s\" por \"%s\"", nombreEquipoActualAux, nombreEquipoAux);
                confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
                if(confirmacion == 'n')
                {
                    printf("Se cancelo la modificacion del equipo.\n\n");
                }
                else
                {
                    jugadores[indice].idEquipo=idEquipoAux;
                    printf("Se modifico el equipo con exito.\n\n");
                }
                break;
            case 6:
                printf("\nAdios.");
                system("pause");
                break;
            default:
                printf("Error, opcion incorrecta.\n\n");

        }
    }

}

int menuListadosJugadores(void)
{
    int option;
    system("cls");
    printf("  1- Listar jugadores\n");
    printf("  2- Listar jugadores ordenados alfabeticamente\n");
    printf("  3- Listar jugadores por Equipo\n");
    printf("  4- Listar jugadores por nombre con Equipo\n");
    printf("  5- Listar equipos mas jovenes\n");
    printf("  6- Listar equipos ordenados por sexo\n");
    printf("  7- Salir\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

void listarJugadoresPorEquipo(eJugadores jugadores [], int tamanioJugadores,eEquipo equipos[], int tamanioEquipos)
{
    system("cls");
    int idEquipoAux,indiceAux;
    mostrarEquipos(equipos,tamanioEquipos);
    do
    {
            idEquipoAux = getValidIntRango("\nIngrese equipo: ", "Error de ingreso. Reintente.\n\n", 1, tamanioEquipos);
            indiceAux=buscarEquipo(equipos,tamanioEquipos,idEquipoAux);
    }while(equipos[indiceAux].isEmpty!=ACTIVO);

    printf("  *** Lista de Jugadores Por Equipo***\n");
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento  | Equipo\n\n");
    for(int i=0; i<tamanioJugadores; i++)
    {
        if(jugadores[i].idEquipo==idEquipoAux && jugadores[i].isEmpty==ACTIVO)
        {
            mostrarJugador(jugadores[i],equipos,tamanioEquipos);
        }
    }
}

/*
int clientesActivos(eCliente clientes[], int tamanioClientes)
{
    int clientesActivos=0;
    for(int i=0; i<tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO)
        {
            clientesActivos++;
        }
    }
    return clientesActivos;
}


void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[])
{
    for(int i=0; i < tamanioJuegos; i++)
    {
        if( juegos[i].idJuego == idJuego)
        {
            strcpy(cadena, juegos[i].descripcion);
            break;
        }
    }
}
*/
