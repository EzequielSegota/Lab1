
#include "Empleado.h"


void cargarEmpleado(eEmpleado lista[], int tam)
{
    int i;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);

        lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }



}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i]);
        }

    }
}
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d-%s-%c-%f-%f\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto);

}
int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={1,8,9,7,2,4};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char sexo[]={'F','M','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000,6000};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;

    }

}
int buscarLegajo(eEmpleado lista[],int T,int legajo)
{
    int i,empleadoI=-1;

    for(i=0;i<T;i++)
    {
        if(lista[i].legajo==legajo)
        {
            empleadoI=i;
        }
    }
    return empleadoI;
}

void bajaEmpleado(eEmpleado lista[],int tamanio)
{
    int legajo,i;
    mostrarListaEmpleados(lista,tamanio);

    printf("\nQue empleado desea dar de baja(legajo):");
    scanf("%d",&legajo);

    i=buscarLegajo(lista,tamanio,legajo);

    if(lista[i].estado==OCUPADO)
    {
        lista[i].estado=LIBRE;
    }
    else
    {
        printf("\nEse usuario esta vacio.\n");
    }
}

void modificarEmpleado(eEmpleado lista[],int tamanio)
{
    int legajo,i,opcion,sueldoAux;
    char sexoAux;
    mostrarListaEmpleados(lista,tamanio);

    printf("\nQue empleado desea modificar(legajo):");
    scanf("%d",&legajo);

    i=buscarLegajo(lista,tamanio,legajo);
    if(lista[i].estado==OCUPADO)
    {
        printf("\nQue desea modificar:\n1.Nombre\n2.Sexo\n3.Sueldo Bruto\n4.Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\nIngrese nombre:");
                fflush(stdin);
                gets(lista[i].nombre);
                break;
            case 2:
                system("cls");
                printf("\nIngrese sexo:");
                fflush(stdin);
                scanf("%c",&sexoAux);
                lista[i].sexo=sexoAux;
                break;
            case 3:
                printf("nIngrese sueldo bruto:");
                scanf("%d",&sueldoAux);
                lista[i].sueldoBruto=sueldoAux;
                lista[i].sueldoNeto=sueldoAux*0.85;
                break;
            default:
                break;
        }
    }
    else
    {
        printf("\nEse usuario esta vacio.\n");
    }
}

