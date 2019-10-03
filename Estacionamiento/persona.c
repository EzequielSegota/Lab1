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
        newPersona[i].estado=1;
    }
}

void mostrarPersona(ePersona newPersona)
{
    printf("\n|Fecha(dd/mm/aaaa)\t|Nombre  |\t|ID|\n|%d/%d/%d|\t\t|%s\t|%d|",newPersona.fechaNac.dia,newPersona.fechaNac.mes,newPersona.fechaNac.anio,newPersona.nombre,newPersona.id);
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
    char patente[4][50]={"AAA 111","BBB 222","AA 111 BB","AAA 111"};//OJ 222 BB
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
    printf("\n\nAutos:");
    printf("\n|Patente\t|Fecha de Ingreso(dd/mm/aaaa)\t|Hora de ingreso\t|Hora de salida|\n|%s|\t|%d/%d/%d|\t\t\t|%d|\t\t\t\t|%d|",vehiculos.patente,vehiculos.fechaIngreso.dia,vehiculos.fechaIngreso.mes,vehiculos.fechaIngreso.anio,vehiculos.horaIngreso,vehiculos.horaSalida);
    printf("\n\nDuenio:");
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

void ordenarPorPatente(eVehiculo vehiculos[],int cant,ePersona persona[],int cantPersonas)
{
    eVehiculo aux;
    int i,j;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(persona[(vehiculos[i].idDuenio)-1].nombre,persona[(vehiculos[j].idDuenio)-1].nombre)==1)
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
                if(personas[i].fechaNac.anio<personas[j].fechaNac.anio)
                {
                    aux=personas[i];
                    personas[i]=personas[j];
                    personas[j]=aux;
                }
            }
        }
    }
}

void inicializarPersonas(ePersona personas[],int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        personas[i].estado=0;
    }
}

int menuPrincipal(void)
{
    int opcion;
    printf("\n1.Mostrar Propietario");
    printf("\n2.Ordenar Propietario");
    printf("\n3.Mostrar Vehiculos");
    printf("\n4.Ordenar Vehiculos");
    printf("\n5.Mostrar Vehiculos de un dueño.");
    printf("\n6.Mostrar Coste de Estadia.");

    printf("\nIngrese una opcion(1-6):");
    scanf("%d",&opcion);

    return opcion;
}

int buscarLibre(ePersona personas[], int tam)
{
    int i;
    int libre=-1;
    for(i=0;i<tam;i++)
    {
        if(personas[i].estado==0)
        {
           libre=i;
           break;
        }
    }
    return libre;
}

void mostrarVehiculosPorID(eVehiculo vehiculos[],int tamVehiculos,int id)
{
    int i;
    for(i=0;i<tamVehiculos;i++)
    {
        if(vehiculos[i].idDuenio==id)
        {
            mostrarVehiculosSinDuenio(vehiculos[i]);
        }
    }
}

void mostrarVehiculosSinDuenio(eVehiculo vehiculos)
{

        printf("\n|Patente\t|Fecha de Ingreso(dd/mm/aaaa)\t|Hora de ingreso\t|Hora de salida\n|%s\t|%d/%d/%d\t\t\t|%d\t\t\t|%d|",vehiculos.patente,vehiculos.fechaIngreso.dia,vehiculos.fechaIngreso.mes,vehiculos.fechaIngreso.anio,vehiculos.horaIngreso,vehiculos.horaSalida);
}

void mostrarPersonasConVehiculos(ePersona newPersona[],int cant,eVehiculo vehiculos[],int tamVehiculos)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\n|Fecha(dd/mm/aaaa)\t|Nombre\t|ID|\n|%d/%d/%d\t\t|%s\t|%d|",newPersona[i].fechaNac.dia,newPersona[i].fechaNac.mes,newPersona[i].fechaNac.anio,newPersona[i].nombre,newPersona[i].id);
        printf("\nAutos:\n");
        mostrarVehiculosPorID(vehiculos,tamVehiculos,newPersona[i].id);
        printf("\n");
    }
}

void calcularEstadia(eVehiculo vehiculos[],int tamVehiculos)
{
    int i;
    int acumulador;
    for(i=0;i<tamVehiculos;i++)
    {
        acumulador=vehiculos[i].horaSalida-vehiculos[i].horaIngreso;
        mostrarVehiculosSinDuenio(vehiculos[i]);
        printf("\n\nHoras que Estuvo:%d\t|Debe pagar:%d\n\n",acumulador,acumulador*100);
    }
}




void altaPropietario(ePersona personas[], int tam)
{

}
