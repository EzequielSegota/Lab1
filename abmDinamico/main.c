#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcion[20];
}eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
}eAlmuerzo;


void inicializarEmpleados( eEmpleado x[], int tam);

int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp,eSector sec[],int tam);
void mostrarEmpleados(eEmpleado nomina[], int tam,eSector sec[],int tamSec);
void agregarEmpleado(eEmpleado empleados[], int tam,eSector sec[],int tamSec);
void eliminarEmpleado(eEmpleado empleados[], int tam,eSector sec[],int tamSec);
void modificarEmpleado(eEmpleado empleados[], int tam,eSector sec[],int tamSec);
int elegirSector(eSector sectores[],int tam);
void cargarDescripcion(eSector sec[],int tamSec,int idSector,char cadena[]);
void listarEmpleadosPorSector(eEmpleado empleados[],int tam,eSector sec[],int tamSec);
void ordenarXSectorYNombre(eEmpleado empleados[],int tam,eSector sectores[],int tamSec);
int menu();
void mostrarAlmuerzosConEmpleados(eEmpleado empleados[],int tamEmp,eComida comida[],int tamCom,eAlmuerzo almuerzo[],int tamAlm);
void almuerzosXEmpleados(eEmpleado empleados[],int tamEmp,eComida comida[],int tamCom,eAlmuerzo almuerzo[],int tamAlm);



int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] =
    {
    {1,"RRHH"},
    {2,"Ventas"},
    {3,"Compras"},
    {4,"Contable"},
    {5,"Sistemas"}
    };

    eComida comidas[] =
    {
    {1,"Milanesa"},
    {2,"Fideos"},
    {3,"Pizza"},
    {4, "Sopa"},
    {5,"Pescado"}
    };

     eAlmuerzo almuerzos[] =
    {
        {100, 1111, 2},
        {101, 6544, 1},
        {102, 4646, 5},
        {103, 1111, 3},
        {104, 5261, 1},
        {105, 5555, 4},
        {106, 1111, 2},
        {107, 5555, 3},
        {108, 1313, 4},
        {109, 5555, 1},
        {110, 5252, 1},
        {111, 4646, 4},
        {112, 1111, 2},
        {113, 5555, 5},
        {114, 6467, 1},
        {115, 5555, 2},
        {116, 3214, 4},
        {117, 5252, 3},
        {118, 3211, 5},
        {119, 1234, 3},
        {120, 1111, 3}
    };

    inicializarEmpleados(lista, 10);


    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, 10,sectores,5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10,sectores,5);
            break;
        case 3:
            modificarEmpleado(lista, 10,sectores,5);
            break;
        case 4:
            mostrarEmpleados(lista, 10,sectores,5);
            system("pause");
            break;
        case 5:
            listarEmpleadosPorSector(lista,10,sectores,5);
            system("pause");
            break;
        case 6:
            ordenarXSectorYNombre(lista,10,sectores,5);
            system("pause");
            break;
        case 7:
            break;
        case 8:
            mostrarAlmuerzosConEmpleados(lista,10,comidas,5,almuerzos,20);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[],int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1,i;

    for( i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1,i;
    for(i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Listar empleados por sector y ordenados por nombre\n");
    printf("7- Mostrar el/los empleado/s que mas ganan por sector\n");
    printf("8- Mostrar almuerzos con empleados\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[],int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta],sectores,tamSector);
        }
        else{
            nuevoEmpleado.legajo = legajo;

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("\nIngrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("\nIngrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector=elegirSector(sectores,5);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

void mostrarEmpleado(eEmpleado emp,eSector sec[],int tamSec)
{
    char descripcion[20];
    cargarDescripcion(sec,tamSec,emp.idSector,descripcion);
    printf("%d\t%s\t%c\t%.2f\t%s\n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam,eSector sec[],int tamSec)
{
    int i;
    for(i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i],sec,tamSec);
        }
    }
}



void mostrarAlmuerzosConEmpleados(eEmpleado empleados[],int tamEmp,eComida comida[],int tamCom,eAlmuerzo almuerzo[],int tamAlm)
{
    char nombreEmp[20];
    char desComida[20];


    system("cls");
    for(int i=0;i<tamAlm;i++)
    {
        for(int j=0;j<tamEmp;j++)
        {
            if(almuerzo[i].idEmpleado==empleados[j].legajo)
            {
                strcpy(nombreEmp,empleados[j].nombre);
                break;
            }
        }

        for(int k=0;k<tamCom;k++)
        {
            if(almuerzo[i].idComida==comida[k].id)
            {
                strcpy(desComida,comida[k].descripcion);
                break;
            }
        }

        printf("\nID Almuerzo:%d\tLegajo:%d\tNombre:%s\tComida:%s\n",almuerzo[i].id,almuerzo[i].idEmpleado,nombreEmp,desComida);
    }

}


void eliminarEmpleado(eEmpleado empleados[], int tam,eSector sec[],int tamSec){

int legajo;
int indice;
char borrar;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice],sec,tamSec);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
    }
    system("pause");
}

}

void modificarEmpleado(eEmpleado empleados[], int tam,eSector sec[],int tamSec){

int legajo;
int indice;
char modificar;
float nuevoSueldo;

printf("Ingrese legajo: ");
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice],sec,tamSec);

    printf("\nModifica sueldo?: ");
    fflush(stdin);
    scanf("%c", &modificar);
    if(modificar != 's'){
        printf("Modificacion cancelada\n\n");
    }
    else{
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

        empleados[indice].sueldo = nuevoSueldo;
        printf("Se ha modificado el sueldo con exito\n\n");
    }

    system("pause");
}



}

int elegirSector(eSector sectores[],int tam)
{
    int idSector;
    int i;
    printf("\nSectores\n\n");
    for(i=0;i<tam;i++)
    {
        printf("%d. %s\n",sectores[i].id,sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d",&idSector);

    return idSector;
}

void cargarDescripcion(eSector sec[],int tamSec,int idSector,char cadena[])
{
    int i;
    for(i=0;i<tamSec;i++)
    {
        if(sec[i].id == idSector)
        {
            strcpy(cadena,sec[i].descripcion);
            break;
        }
    }
}


void listarEmpleadosPorSector(eEmpleado empleados[],int tam,eSector sec[],int tamSec)
{
    int opcion=elegirSector(sec,tamSec),flag=-1;
    char descripcion[20];

    cargarDescripcion(sec,tamSec,opcion,descripcion);

    for(int i=0;i<tam;i++)
    {
        if(empleados[i].idSector==opcion && empleados[i].isEmpty==1)
        {
            mostrarEmpleado(empleados[i],sec,tamSec);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("No hay empleados en ese sector.");
    }
}

void ordenarXSectorYNombre(eEmpleado empleados[],int tam,eSector sectores[],int tamSec)
{
    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado aux;

    for(int i=0;i<tam-1;i++)
    {

        for(int j=i+1;j<tam;j++)
        {
            cargarDescripcion(sectores,tamSec,empleados[i].idSector,descripcionI);
            cargarDescripcion(sectores,tamSec,empleados[j].idSector,descripcionJ);
            if(strcmp(descripcionI,descripcionJ)>0)
            {
                aux=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=aux;
            }
            else if(strcmp(descripcionI, descripcionJ)==0 && strcmp(empleados[i].nombre, empleados[j].nombre)>0)
            {
                aux=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=aux;
            }

        }
    }
}



