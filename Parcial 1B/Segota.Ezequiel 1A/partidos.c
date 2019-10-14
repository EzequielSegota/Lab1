#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partidos.h"
#include "referi.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

void hardcodeoPartidos(ePartido partidos[])
{
    int visitante[] ={1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};
    int local[]={10,9,8,7,6,4,3,2,1,5,8,7,6,10,9,2,1,5,4,3,6,10,9,8,7};
    int dia[]={21,21,21,21,21,28,28,28,28,28,5,5,5,5,5,12,12,12,12,12,19,19,19,19,19 };
    int mes[]={9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int anio[]= {2019,2019,2019,2018,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};
    int referi[]= {1,2,6,4,5,1,2,3,4,6,6,2,3,4,5,1,6,3,4,5,1,2,3,6,5};

    for(int i=0;i<25;i++)
    {
        partidos[i].idPartido=i+1;
        partidos[i].idLocal=local[i];
        partidos[i].idVisitante=visitante[i];
        partidos[i].idReferi=referi[i];
        partidos[i].fechaPartido.dia=dia[i];
        partidos[i].fechaPartido.mes=mes[i];
        partidos[i].fechaPartido.anio=anio[i];

        partidos[i].isEmpty=ACTIVO;
    }
}

int getNextIdPartido(ePartido partido[], int tamanioPartido)
{
    int i;
    for(i=0; i<tamanioPartido; i++)
    {
        if(partido[i].isEmpty == ACTIVO || partido[i].isEmpty == BAJA)
        {
            i++;
            break;
        }
    }

    return i;
}

int iniciarEstadosPartidos(ePartido partido[], int tamanioPartido)
{
    int flag = -1;
    for(int i=0; i<tamanioPartido; i++)
    {
        partido[i].isEmpty = VACIO;
    }
    return flag;
}

int buscarPartidoLibre(ePartido partido[], int tamanioPartido)
{
    int indice = -1;

    for(int i=0; i< tamanioPartido; i++)
    {

        if( partido[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarPartido(ePartido partido[], int tamanioPartido, int idPartido)
{
    int indice = -1;
    for(int i=0; i < tamanioPartido; i++)
    {


        if(partido[i].idPartido == idPartido && partido[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarReferi(eReferi referi[],int tamanioReferi,int idReferi,char cadena[])
{

    for(int i=0; i < tamanioReferi; i++)
    {

        if( referi[i].idReferi == idReferi)
        {
            strcpy(cadena, referi[i].apellido);
            strcat(cadena," ");
            strcat(cadena,referi[i].nombre);
            break;
        }
    }
}

void mostrarPartido(ePartido partido,char localAux[],char visitanteAux[],char referiAux[])
{
    printf("\t%3d  | %2d/%2d/%4d  | %16s  |   %16s  |  %20s  \n", partido.idPartido, partido.fechaPartido.dia, partido.fechaPartido.mes, partido.fechaPartido.anio, localAux, visitanteAux, referiAux);
}

void mostrarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi)
{
    char localAux[51];
    char visitanteAux[51];
    char referiAux[63];



    printf("\n\t ID Partido| Fecha de Partido |          Local|         Visitante |        Referi\n\n");
    for(int i=0; i<tamanioPartido; i++)
    {
        if(partido[i].isEmpty == ACTIVO)
        {
            cargarEquipo(equipos,tamanioEquipos,partido[i].idLocal,localAux);
            cargarEquipo(equipos,tamanioEquipos,partido[i].idVisitante,visitanteAux);
            cargarReferi(referis,tamanioReferi,partido[i].idReferi,referiAux);
            mostrarPartido(partido[i],localAux,visitanteAux,referiAux);
        }
    }
}

void listarEquiposYReferisPorFecha(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi)
{
    int diaAux;
    int mesAux;
    int anioAux;
    int i,j;

    diaAux = getValidIntRango("Ingrese dia de partido: ", "Error de ingreso, reintente.\n\n", 1, 31);
    mesAux = getValidIntRango("Ingrese mes de partido: ", "Error de ingreso, reintente.\n\n", 1, 12);
    anioAux = getValidIntRango("Ingrese anio de partido (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2019);

    printf("\n----- Equipos de esa fecha ----");
    printf("\n\tId  |      Nombre     |    Localidad\n\n");
    for(i=0;i<tamanioPartido;i++)
    {
        if(partido[i].isEmpty==ACTIVO && partido[i].fechaPartido.dia==diaAux && partido[i].fechaPartido.mes==mesAux && partido[i].fechaPartido.anio==anioAux)
        {
            for(j=0;j<tamanioEquipos;j++)
            {
                if((equipos[j].idEquipo == partido[i].idLocal || equipos[j].idEquipo == partido[i].idVisitante) && equipos[j].isEmpty==ACTIVO)
                {
                    mostrarEquipo(equipos[j]);
                }
            }
        }
    }

    printf("\n----- Referis de esa fecha ----");
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento | Email\n\n");
    for(i=0;i<tamanioPartido;i++)
    {
        if(partido[i].isEmpty==ACTIVO && partido[i].fechaPartido.dia==diaAux && partido[i].fechaPartido.mes==mesAux && partido[i].fechaPartido.anio==anioAux)
        {
            for(j=0;j<tamanioReferi;j++)
            {
                if(referis[j].idReferi == partido[i].idReferi && referis[j].isEmpty==ACTIVO)
                {
                    mostrarReferi(referis[j]);
                }
            }
        }
    }
}

int menuListadosPartidos(void)
{
    int option;
    system("cls");
    printf("  1- Listar Partidos\n");
    printf("  2- Listar Partidos ordenados por fecha\n");
    printf("  3- Mostrar referi con mas partidos\n");
    printf("  4- Listar Referis y Equipos por fecha de partido\n");
    printf("  5- Salir\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

void altaPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi)
{
    ePartido nuevoPartido;
    int indice,indiceAuxLocal,indiceAuxVisitante,indiceAuxReferi;
    int idPartido,idVisitanteAux,idLocalAux,idReferiAux;
    int diaAux;
    int mesAux;
    int anioAux;
    char localAux[51];
    char visitanteAux[51];
    char referiAux[63];

    system("cls");
    printf("  *** Alta Partido ***\n\n");

    indice = buscarPartidoLibre(partido, tamanioPartido);
    if(indice == -1)
    {
        printf("No hay lugar para agregar mas partidos.\n\n");
    }
    else
    {
        idPartido = getNextIdPartido(partido, tamanioPartido);
        mostrarEquipos(equipos,tamanioEquipos);
        do{
            idVisitanteAux = getValidIntRango("\nIngrese equipo visitante: ", "Error de ingreso. Reintente.\n\n", 1, tamanioEquipos);
            indiceAuxVisitante=buscarEquipo(equipos,tamanioEquipos,idVisitanteAux);
        }while(equipos[indiceAuxVisitante].isEmpty!=ACTIVO);

        system("cls");

        mostrarEquipos(equipos,tamanioEquipos);
        do{
            idLocalAux = getValidIntRango("\nIngrese equipo local: ", "Error de ingreso. Reintente.\n\n", 1, tamanioEquipos);
            indiceAuxLocal=buscarEquipo(equipos,tamanioEquipos,idLocalAux);
        }while(equipos[indiceAuxLocal].isEmpty!=ACTIVO || indiceAuxLocal==indiceAuxVisitante);

        mostrarReferis(referis,tamanioReferi);
        do{
            idReferiAux = getValidIntRango("\nIngrese referi: ", "Error de ingreso. Reintente.\n\n", 1, tamanioReferi);
            indiceAuxReferi=buscarReferi(referis,tamanioReferi,idReferiAux);
        }while(referis[indiceAuxReferi].isEmpty!=ACTIVO);

        diaAux = getValidIntRango("Ingrese dia de partido: ", "Error de ingreso, reintente.\n\n", 1, 31);
        mesAux = getValidIntRango("Ingrese mes de partido: ", "Error de ingreso, reintente.\n\n", 1, 12);
        anioAux = getValidIntRango("Ingrese anio de partido (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2019);

        nuevoPartido.idPartido = idPartido;
        nuevoPartido.idLocal = idLocalAux;
        nuevoPartido.idVisitante = idVisitanteAux;
        nuevoPartido.idReferi = idReferiAux;
        nuevoPartido.fechaPartido.anio=anioAux;
        nuevoPartido.fechaPartido.mes=mesAux;
        nuevoPartido.fechaPartido.dia=diaAux;

        nuevoPartido.isEmpty=ACTIVO;

        partido[indice] = nuevoPartido;
        printf("\nSe agrego nuevo partido:\n\n");
        printf("\n\t ID Partido| Fecha de Partido |          Local|         Visitante |        Referi\n\n");
        cargarEquipo(equipos,tamanioEquipos,partido[indice].idLocal,localAux);
        cargarEquipo(equipos,tamanioEquipos,partido[indice].idVisitante,visitanteAux);
        cargarReferi(referis,tamanioReferi,partido[indice].idReferi,referiAux);
        mostrarPartido(partido[indice],localAux,visitanteAux,referiAux);
        printf("\n");
    }
}
/*
void modificarCliente(eCliente clientes[], int tamanioClientes)
{
    int idCliente;
    int indice;
    int opcion;
    char confirmacion;

    char apellidoAux[51];
    char nombreAux[51];
    char sexoAux;
    char direccionAux[51];

    system("cls");
    printf("  *** Modificar Cliente ***\n\n");
    idCliente = getValidInt("Ingrese el ID del cliente: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarCliente(clientes, tamanioClientes, idCliente);
    if( indice == -1)
    {
        printf("No hay ningun cliente con el ID: %d\n\n", idCliente);
    }
    else
    {
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\n Menu de opciones\n\n1. Modificar apellido\n2. Modificar nombre\n3. Sexo\n4. Domicilio\n5- Salir\n\n");
        opcion = getValidInt("Ingrese opcion: ", "Error, ingreso no valido. Reintente.\n\n");
        switch(opcion)
        {
        case 1:
            printf("\nModificar apellido\n\n");
            getValidStringRango("Ingrese nuevo apellido: ", "Error, solo se admiten letras.\n", apellidoAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", apellidoAux , clientes[indice].apellido);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del apellido.\n\n");
            }
            else
            {
                strcpy(clientes[indice].apellido, apellidoAux);
                printf("Se modifico el apellido con exito.\n\n");
            }
            break;
        case 2:
            printf("\nModificar nombre -->\n\n");
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", nombreAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", nombreAux , clientes[indice].nombre);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(clientes[indice].nombre, nombreAux);
                printf("Se modifico el nombre con exito.\n\n");
            }
            break;
        case 3:
            printf("\nModificar sexo\n\n");
            sexoAux = getValidChar("Ingrese nuevo sexo: ", "Error, solo se admiten letras.\n", 'm', 'f');
            printf("\nSe modificara \"%c\" por \"%c\"", sexoAux , clientes[indice].sexo);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del sexo.\n\n");
            }
            else
            {
                clientes[indice].sexo = sexoAux;
                printf("Se modifico el sexo con exito.\n\n");
            }
            break;
        case 4:
            printf("\nModificar direccion\n\n");
            getValidStringDireccionRango("Ingrese nueva direccion: ", "Error, solo se admiten letras.\n", direccionAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", direccionAux, clientes[indice].domicilio);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(clientes[indice].domicilio, direccionAux);
                printf("Se modifico la direccion con exito.\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Error, opcion incorrecta.\n\n");
        }
    }
}

void bajaCliente(eCliente clientes[], int tamanioClientes)
{
    int indice;
    int idCliente;
    char confirmacion;

    system("cls");
    printf("  *** Baja Cliente ***\n\n");

    idCliente = getValidInt("Ingrese el ID del cliente: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarCliente(clientes, tamanioClientes, idCliente);

    if( indice == -1)
    {
        printf("No hay ningun cliente con el ID %d\n\n", idCliente);
    }
    else
    {
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\nSe eliminara el cliente.\n");
        confirmacion = getValidChar("\nConfirma baja del cliente (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            clientes[indice].isEmpty = BAJA;
            printf("Se ha eliminado el cliente con exito.\n\n");
        }
    }

}*/

void listarPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi)
{
    ePartido auxPartido;
    system("cls");
    printf("  *** Lista de Partidos ***\n");
    printf("  Ordenados por Fecha.\n\n");
    for(int i=0; i<tamanioPartido-1; i++)
    {
        for(int j=i+1; j<tamanioPartido; j++)
        {
            if(partido[i].fechaPartido.dia>partido[j].fechaPartido.dia)
            {
                auxPartido = partido[i];
                partido[i] = partido[j];
                partido[j] = auxPartido;
            }
            if(partido[i].fechaPartido.mes>partido[j].fechaPartido.mes)
            {
                auxPartido = partido[i];
                partido[i] = partido[j];
                partido[j] = auxPartido;
            }
            if(partido[i].fechaPartido.anio>partido[j].fechaPartido.anio)
            {
                auxPartido = partido[i];
                partido[i] = partido[j];
                partido[j] = auxPartido;
            }
        }
    }
    mostrarPartidos(partido, tamanioPartido,equipos,tamanioEquipos,referis,tamanioReferi);
    printf("\n");
}

void mostrarReferiConMasPartidos(ePartido partido[], int tamanioPartido,eReferi referis[],int tamanioReferi)
{
    int indiceReferiAux,contadorActual=0,contadorAnterior=0;
    for(int i=0;i<tamanioReferi;i++)
    {
        for(int j=0;j<tamanioPartido;j++)
        {
            if(referis[i].idReferi==partido[j].idReferi && partido[j].isEmpty==ACTIVO && referis[i].isEmpty==ACTIVO)
            {
                contadorActual++;
            }
            if(contadorActual>contadorAnterior)
            {
                indiceReferiAux=i;
                contadorAnterior=contadorActual;
            }
        }
    }
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento | Email\n\n");
    mostrarReferi(referis[indiceReferiAux]);
}

void abmPartidos(ePartido partido[], int tamanioPartido,eEquipo equipos[],int tamanioEquipos,eReferi referis[],int tamanioReferi)
{
    char seguir = 's'; //Bandera continuar do-while.
    char seguirDos = 's';
    do
    {
        switch(menuABM())
        {
        case 1:
            altaPartidos(partido, tamanioPartido,equipos,tamanioEquipos,referis,tamanioReferi);
            system("pause");
            break;
        case 2:
            //modificarCliente(clientes, tamanioClientes);
            system("pause");
            break;
        case 3:
            //bajaCliente(clientes, tamanioClientes);
            system("pause");
            break;
        case 4:
            do
            {
                switch(menuListadosPartidos())
                {
                    case 1:
                        mostrarPartidos(partido,tamanioPartido,equipos,tamanioEquipos,referis,tamanioReferi);
                        system("pause");
                        break;
                    case 2:
                        listarPartidos(partido, tamanioPartido,equipos,tamanioEquipos,referis,tamanioReferi);
                        system("pause");
                        break;
                    case 3:
                        mostrarReferiConMasPartidos(partido,tamanioPartido,referis,tamanioReferi);
                        system("pause");
                        break;
                    case 4:
                        listarEquiposYReferisPorFecha(partido,tamanioPartido,equipos,tamanioEquipos,referis,tamanioReferi);
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        seguirDos='n';
                        printf("\nAdios");
                        break;
                    default:
                        printf("\nError\n");
                }
            }while(seguirDos=='s');
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
