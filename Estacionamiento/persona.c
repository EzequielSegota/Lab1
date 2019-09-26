#include "persona.h"

void hardcodePersonas(ePersona newPersona[],int cant)
{
    int i;
    char nombre[4][32]={"Maria","Ezequiel","German","Yanina"};
    int id[4]={1,2,3,4};
    int anio[4]={1990,1980,2000,1995};
    int mes[4]={3,4,12,11};
    int dia[4]={33,22,25,11};
    for(i=0;i<cant;i++)
    {
        strcpy(newPersona[i].nombre,nombre[i]);
        newPersona[i].id=id[i];
        newPersona[i].fechaNac.anio=anio[i];
        newPersona[i].fechaNac.mes=mes[i];
        newPersona[i].fechaNac.dia=dia[i];
    }
}

void mostrarPersona(ePersona newPersona)
{
    printf("\nFecha(dd/mm/aaaa):%d/%d/%d",newPersona.fechaNac.dia,newPersona.fechaNac.mes,newPersona.fechaNac.anio);
    printf("\nNombre:%s",newPersona.nombre);
    printf("\nID:%d\n\n",newPersona.id);
}

void mostrarPersonas(ePersona newPersona[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
       mostrarPersona(newPersona[i]);
    }
}


void hardcodeVehiculos(eVehiculo newVehiculo[],int cant)
{
    char patente[4][50]={"AAA 111","BBB 222","AA 111 BB","OJ 222 BB"};
    int dia[4]={26,26,26,26};
    int mes[4]={9,9,9,9};
    int anio[4]={2019,2019,2019,2019};
    int horaEntrada[4]={10,9,8,11};
    int horaSalida[4]={11,11,11,12};
    int idDuenio[4]={1,2,2,4};
    int i;

    for(i=0;i<cant;i++)
    {
        strcpy(newVehiculo[i].patente,patente[i]);
        newVehiculo[i].horaIngreso=horaEntrada[i];
        newVehiculo[i].horaSalida=horaSalida[i];
        newVehiculo[i].fechaIngreso.dia=dia[i];
        newVehiculo[i].fechaIngreso.mes=mes[i];
        newVehiculo[i].fechaIngreso.anio=anio[i];
        newVehiculo[i].idDuenio=idDuenio[i];
    }
}

void mostrarVehiculo(eVehiculo vehiculos,ePersona duenio[],int cant)
{
    printf("\nPatente:%s",vehiculos.patente);
    printf("\nFecha de Ingreso(dd/mm/aaaa):%d/%d/%d",vehiculos.fechaIngreso.dia,vehiculos.fechaIngreso.mes,vehiculos.fechaIngreso.anio);
    printf("\nHora de ingreso:%d",vehiculos.horaIngreso);
    printf("\nHora de salida:%d",vehiculos.horaSalida);
    printf("\nDuenio:");
    mostrarPersona(duenio[buscarPersonaPorID(duenio,cant,vehiculos.idDuenio)]);
}

void mostrarVehiculos(eVehiculo vehiculos[],int cant,ePersona duenios[],int cantDuenios)
{
    int i;

    for(i=0;i<cant;i++)
    {
        mostrarVehiculo(vehiculos[i],duenios,cantDuenios);
    }
}

int buscarPersonaPorID(ePersona persona[],int cant,int auxID)
{
    int i,retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(persona[i].id==auxID)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int buscarPorPatente(eVehiculo vehiculos[],int cant,char patenteAux[])
{
    int i,retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(strcmpi(vehiculos[i].patente,patenteAux)==0)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

void ordenarPorPatente(eVehiculo vehiculos[],int cant)
{
    eVehiculo aux;
    int i,j;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(vehiculos[i].patente,vehiculos[j].patente)==1)
            {
                aux=vehiculos[i];
                vehiculos[i]=vehiculos[j];
                vehiculos[j]=aux;
            }
        }
    }
}
//ORDENAR POR NOMBRE
void ordenarPorNombre(ePersona personas[],int cant)
{
    ePersona aux;
    int i,j;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(personas[i].nombre,personas[j].nombre)==1)
            {
                aux=personas[i];
                personas[i]=personas[j];
                personas[j]=aux;
            }
        }
    }
}
