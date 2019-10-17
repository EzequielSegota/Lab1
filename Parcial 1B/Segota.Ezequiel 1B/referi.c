#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "referi.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2



int getNextIdReferi(eReferi referis[],int tamanioReferis)
{
    int flag = 0;
    for(int i=0; i<tamanioReferis; i++)
    {
        if(referis[i].isEmpty == VACIO || referis[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

void hardcodeoReferis(eReferi referis[])
{
    char Nombres[][50]= {"Nicolas","Nazareno","Dario","Fernando","Gisella","Yael"};
    char Apellido[][50]= {"Lamolina","Arasa","Herrera","Espinoza","Trucco","Falcon Perez"};
    char eMail[][50]= {"nicolaslamolina@hotmail.com","arasanazareno@outlook.com","darioherrera@mail.com","espinozaFer33@hotmail.com","TruccoFernand012@hotmail.com","pfalc0n@outlook.com"};
    char Sexo[]= {'M','M','M','M','F','F'};
    int anios[]= {1980,1981,1975,1970,1986,1989};
    int mes[]= {8,10,5,6,6,2};
    int dia[]= {15,5,20,22,12,1};

    for(int i=0; i<6; i++)
    {
        referis[i].idReferi=i+1;
        referis[i].fechaNac.dia=dia[i];
        referis[i].fechaNac.mes=mes[i];
        referis[i].fechaNac.anio=anios[i];
        referis[i].sexo=Sexo[i];

        strcpy(referis[i].nombre,Nombres[i]);
        strcpy(referis[i].apellido,Apellido[i]);
        strcpy(referis[i].email,eMail[i]);

        referis[i].isEmpty=ACTIVO;
    }
}

int iniciarEstadosReferis(eReferi referis[],int tamanioReferis)
{
    int flag = -1;
    for(int i=0; i<tamanioReferis; i++)
    {
        referis[i].isEmpty = VACIO;
    }
    return flag;
}

void abmReferis(eReferi referis[],int tamanioReferis)
{
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        switch(menuABM())
        {
        case 1:
            altaReferis(referis, tamanioReferis);
            system("pause");
            break;
        case 2:
            //modificarReferis(referis, tamanioReferis);
            system("pause");
            break;
        case 3:
            //bajaReferis(referis, tamanioReferis);
            system("pause");
            break;
        case 4:
            listarReferis(referis, tamanioReferis);
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


void altaReferis(eReferi referis[],int tamanioReferis)
{
    eReferi referiAux;
    int indice;

    int idAux;
    char nombreReferiAux[31];
    char apellidoReferiAux[31];
    char emailReferiAux[31];
    char sexoAux;
    int diaAux;
    int mesAux;
    int anioAux;


    system("cls");
    printf(" *** ALTA REFERI ***\n\n");

    indice = buscarReferisLibre(referis, tamanioReferis);
    if(indice == -1)
    {
        printf("No hay lugar para la carga de referi.\n\n");
    }
    else
    {
        idAux = getNextIdReferi(referis, tamanioReferis);


        getValidStringRango("Ingrese nombre de referi: ", "Error, solo se admiten letras. Reintente.\n\n", nombreReferiAux, 31);
        getValidStringRango("Ingrese apellido de referi: ", "Error, solo se admiten letras. Reintente.\n\n", apellidoReferiAux, 31);

        getValidEmail("\nIngrese Email: ","\nError debe contener @ y al menos un . no debe superar 31.\nReintente: ",emailReferiAux,31);


        sexoAux=getValidChar("\nIngrese sexo: ","Error, debe ser M o F",'M','F');

        diaAux = getValidIntRango("Ingrese dia de nac: ", "Error de ingreso, reintente.\n\n", 1, 31);
        mesAux = getValidIntRango("Ingrese mes de nac: ", "Error de ingreso, reintente.\n\n", 1, 12);
        anioAux = getValidIntRango("Ingrese anio de nac (1950-2018): ", "Error de ingreso, reintente.\n\n", 1950, 2018);

        referiAux.idReferi = idAux;
        strcpy(referiAux.nombre, nombreReferiAux);
        strcpy(referiAux.apellido, apellidoReferiAux);
        strcpy(referiAux.email, emailReferiAux);
        referiAux.sexo=sexoAux;
        referiAux.fechaNac.dia = diaAux;
        referiAux.fechaNac.mes = mesAux;
        referiAux.fechaNac.anio = anioAux;
        referiAux.isEmpty = ACTIVO;

        referis[indice] = referiAux;

        system("cls");
        printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento | Email\n\n");
        mostrarReferi(referis[indice]);
        printf("\nSe agrego nuevo referi.\n\n");
    }
}
void listarReferis(eReferi referis[],int tamanioReferis)
{
    system("cls");
    printf("  *** Lista de Referis ***\n");
    printf("  Ordenados Alfabeticamente por Nombre.\n\n");
    eReferi auxReferi;
    for(int i=0; i<tamanioReferis-1; i++)
    {
        for(int j=i+1; j<tamanioReferis; j++)
        {
            if(strcmp(referis[i].nombre, referis[j].nombre) > 0)
            {
                auxReferi = referis[i];
                referis[i] = referis[j];
                referis[j] = auxReferi;
            }
        }
    }

    mostrarReferis(referis, tamanioReferis);
    printf("\n");
}

int buscarReferisLibre(eReferi referis[],int tamanioReferis)
{
    int indice = -1;

    for(int i=0; i< tamanioReferis; i++)
    {
        if( referis[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarReferis(eReferi referis[],int tamanioReferis)
{
    int i;
    printf("\n\tId  |           Nombre   |          Apellido  |  Sexo  | Fecha de Nacimiento | Email\n\n");
    for(i=0;i<tamanioReferis;i++)
    {
        if(referis[i].isEmpty==ACTIVO)
        {
            mostrarReferi(referis[i]);
        }
    }
}

void mostrarReferi(eReferi referis)
{
    printf("\n\t%3d  |  %16s  |  %16s  |  %c  |  %2d/%2d/%4d | %20s",referis.idReferi,referis.nombre,referis.apellido,referis.sexo,referis.fechaNac.dia,referis.fechaNac.mes,referis.fechaNac.anio,referis.email);
}

int buscarReferi(eReferi referis[],int tamanioReferis,int idReferi)
{
    int indice=-1;
    for(int i=0;i<tamanioReferis;i++)
    {
        if(referis[i].idReferi==idReferi && referis[i].isEmpty==ACTIVO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
