#include "persona.h"
#include "utn.h"
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
    printf("\n|Fecha(dd/mm/aaaa)\t|Nombre\t|ID|\n|%d/%d/%d|\t\t|%s\t|%d|",newPersona.fechaNac.dia,newPersona.fechaNac.mes,newPersona.fechaNac.anio,newPersona.nombre,newPersona.id);
}

void mostrarPersonas(ePersona newPersona[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(newPersona[i].estado==1)
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
    int indiceAux;
    indiceAux=buscarPersonaPorID(duenio,cant,vehiculos.idDuenio);
    if(duenio[indiceAux].estado==1)
    {
        printf("\n\nAutos:");
        printf("\n|Patente\t|Fecha de Ingreso(dd/mm/aaaa)\t|Hora de ingreso\t|Hora de salida|\n|%s|\t|%d/%d/%d|\t\t\t|%d|\t\t\t\t|%d|",vehiculos.patente,vehiculos.fechaIngreso.dia,vehiculos.fechaIngreso.mes,vehiculos.fechaIngreso.anio,vehiculos.horaIngreso,vehiculos.horaSalida);
        printf("\n\nDuenio:");
        mostrarPersona(duenio[indiceAux]);
    }
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
    printf("\n1.Alta propietario");
    printf("\n2.Baja propietario");
    printf("\n3.Modificar propietario");
    printf("\n4.Ingreso Vehiculo");
    printf("\n5.Egreso Vehiculo");
    printf("\n6.Informes");

    printf("\nIngrese una opcion(1-6):");
    scanf("%d",&opcion);

    return opcion;
}

int siguienteID(ePersona personas[], int tam)
{
    int i;
    int vacio=-1;
    for(i=0;i<tam;i++)
    {
        if(personas[i].estado==0)
        {
           vacio=i;
           break;
        }
    }
    return vacio+1;
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
        if(newPersona[i].estado==1)
        {
            printf("\n|Fecha(dd/mm/aaaa)\t|Nombre\t|ID|\n|%d/%d/%d\t\t|%s\t|%d|",newPersona[i].fechaNac.dia,newPersona[i].fechaNac.mes,newPersona[i].fechaNac.anio,newPersona[i].nombre,newPersona[i].id);
            printf("\nAutos:\n");
            mostrarVehiculosPorID(vehiculos,tamVehiculos,newPersona[i].id);
            printf("\n");
        }

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
    int indiceAux;
    indiceAux=buscarLibre(personas,tam);
    if(indiceAux!=-1)
    {
        personas[indiceAux].id=siguienteID(personas,tam);
        getValidString("\nIngrese nombre:","\nError reintente",personas[indiceAux].nombre);
        personas[indiceAux].fechaNac.dia=getValidInt("\nIngrese dia de nacimiento:","Error entre 1-30",1,30);
        personas[indiceAux].fechaNac.mes=getValidInt("\nIngrese mes de nacimiento:","Error entre 1-12",1,12);
        personas[indiceAux].fechaNac.anio=getValidInt("\nIngrese anio de nacimiento:","Error entre 1850-2001",1850,2001);
        personas[indiceAux].estado=1;
    }
    else
    {
        printf("\nNo hay lugar!");
    }
}

void bajaPersona(ePersona personas[], int tam)
{
    char confirmacion;
    int idAux,indiceAux;
    idAux=getValidInt("Ingrese un ID:","Error ID incorrecto",0,tam);
    indiceAux=buscarPersonaPorID(personas,tam,idAux);
    if(indiceAux!=-1 && personas[indiceAux].estado==1)
    {
        system("cls");
        mostrarPersona(personas[indiceAux]);
        confirmacion=toupper(confirmacion=getChar("\n\nEsta seguro que desea borrar este usuario?(S/N):"));
        if(confirmacion=='S')
            personas[indiceAux].estado=0;
    }
    else
    {
        printf("\nPersona no encontrada...\n");
    }

}

void modificarPersona(ePersona personas[], int tam)
{
    char confirmacion;
    int idAux,indiceAux;
    idAux=getValidInt("\nIngrese un ID:","Error ID incorrecto",0,tam);
    indiceAux=buscarPersonaPorID(personas,tam,idAux);
    if(indiceAux!=-1 && personas[indiceAux].estado==1)
    {
        system("cls");
        mostrarPersona(personas[indiceAux]);
        confirmacion=toupper(confirmacion=getChar("\n\nEsta seguro que desea modificar este usuario?(S/N):"));
        if(confirmacion=='S')
        {
            do
            {
              switch(menuModificarPersona())
              {
                case 1:
                system("cls");
                getValidString("\nIngrese nombre:","\nError, solo letras",personas[indiceAux].nombre);
                break;
                case 2:
                    personas[indiceAux].fechaNac.dia=getValidInt("\nIngrese dia(1-30):","\nError debe ser entre 1-30",1,30);
                    break;
                case 3:
                    personas[indiceAux].fechaNac.mes=getValidInt("\nIngrese mes(1-12):","\nError debe ser entre 1-12",1,12);
                    break;
                case 4:
                    personas[indiceAux].fechaNac.anio=getValidInt("\nIngrese anio(1850-2001):","\nError debe ser entre 1850-2001",1850,2001);
                    break;
                case 5:
                    printf("\nAdios!");
                    confirmacion='n';
                    break;
                default:
                    printf("\nError\n");
                    system("pause");

              }
            }while(confirmacion=='S' || confirmacion=='s');

        }
    }
    else
    {
        printf("\nPersona no encontrada...\n");
    }
}

int menuModificarPersona()
{
    int opcion;

    system("cls");
    printf("\n1.Modificar Nombre.");
    printf("\n2.Modificar Dia de Nac.");
    printf("\n3.Modificar Mes de Nac.");
    printf("\n4.Modificar Anio de Nac.");
    printf("\n5.Salir.");
    printf("\nIngrese una opcion(1-5):");
    scanf("%d",&opcion);

    return opcion;
}

int menuInformes(ePersona personas[] ,int tamPersonas,eVehiculo vehiculos[] ,int tamVehiculos)
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

void inicializarVehiculos(eVehiculo vehiculo[],int tamVehiculos)
{
    int i;
    for(i=0;i<tamVehiculos;i++)
    {
        vehiculo[i].idDuenio=0;
    }
}

int buscarLibreVehiculo(eVehiculo vehiculo[] ,int tamVehiculos)
{
    int i,libre=-1;
    for(i=0;i<tamVehiculos;i++)
    {
        if(vehiculo[i].idDuenio==0)
        {
            libre=i;
            break;
        }
    }
    return libre;
}

void altaVehiculo(eVehiculo vehiculos[] ,int tamVehiculos,ePersona personas[],int tamPersonas)
{
    char patenteAux[52];
    int indiceAux,idAux;
    getString("\nIngrese Patente:",patenteAux);
    indiceAux=buscarLibreVehiculo(vehiculos,tamVehiculos);
    if(indiceAux!=-1)
    {
        while(esAlfaNumerico(patenteAux)!=1)
        {
            system("cls");
            fflush(stdin);
            getString("\nError! debe ser Alfanumerica\nIngrese Patente:",patenteAux);
        }
        fflush(stdin);
        strcpy(vehiculos[indiceAux].patente,patenteAux);

        vehiculos[indiceAux].fechaIngreso.dia=getValidInt("\nIngrese dia de ingreso:","\nError debe ser entre 1-30",1,30);
        vehiculos[indiceAux].fechaIngreso.mes=getValidInt("\nIngrese mes de ingreso:","\nError debe ser entre 1-12",1,12);
        vehiculos[indiceAux].fechaIngreso.anio=getValidInt("\nIngrese anio de ingreso:","\nError debe ser entre 1850-2001",1850,2001);

        vehiculos[indiceAux].horaIngreso=getValidInt("\nIngrese Hora de Ingreso:","\nError deber 1-24",1,24);

        mostrarPersonas(personas,tamPersonas);
        idAux=getInt("\nIngrese ID:");
/*
        while(personas[buscarPersonaPorID(personas,tamPersonas,idAux)].estado==0 || esNumerico(idAux)!=1)
        {
            system("cls");
            mostrarPersonas(personas,tamPersonas);
            idAux=getInt("\nError!\nIngrese ID:");
        }
        vehiculos[indiceAux].idDuenio=idAux;
    }
*/
}
