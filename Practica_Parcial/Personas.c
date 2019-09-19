#include "Personas.h"
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
void inicializarPersona(ePersona persona[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        persona[i].estado=VACIO;
    }
}

void ingresarPersonas(ePersona persona[],int cant)
{
        int i;
        i=buscarSiguienteLibre(persona,cant);
        if(i!=-1)
        {
            printf("\nIngrese nombre:");
            fflush(stdin);
            gets(persona[i].nombre);

            printf("\nIngrese apellido:");
            fflush(stdin);
            gets(persona[i].apellido);

            printf("\nIngrese DNI:");
            scanf("%d",&persona[i].dni);
            while(validarDNI(persona,cant,persona[i].dni)==1)
            {
                printf("\nError el DNI ingresado esta repetido, ingrese un DNI distinto:");
                scanf("%d",&persona[i].dni);
            }
            persona[i].estado=OCUPADO;
        }
        else
            printf("\nNo hay más lugar\n");
}

void mostrarPersona(ePersona persona)
{
    printf("\nEl nombre de la persona es:%s\nSu apellido es:%s\nSu DNI es:%d\n",persona.nombre,persona.apellido,persona.dni);
}

void mostrarPersonas(ePersona persona[],int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(persona[i].estado==OCUPADO)
            mostrarPersona(persona[i]);
    }
}

void menuPersonas(ePersona persona[],int cant)
{
    int opcion;

    do
    {
        printf("\n1.Agregar Persona");
        printf("\n2.Mostrar Personas");
        printf("\n3.Ordenar Personas por DNI");
        printf("\n4.Ordenar Personas por Apellido");
        printf("\n5.Salir");
        printf("\nIngrese una opcion:");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                ingresarPersonas(persona,cant);
                system("pause");
                break;
            case 2:
                system("cls");
                mostrarPersonas(persona,cant);
                system("pause");
                break;
            case 3:
                system("cls");
                ordenarPorDNI(persona,cant);
                system("pause");
                break;
            case 4:
                system("cls");
                ordenarPorApellidoYNombre(persona,cant);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("\nAdios\n");
                system("pause");
                break;
        }
    }
    while(opcion!=5);

}


int buscarSiguienteLibre(ePersona persona[],int cantidad)
{
    int i,retorno=-1;
    for(i=0;i<cantidad;i++)
    {
        if(persona[i].estado==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void ordenarPorDNI(ePersona persona[],int cant)
{
    int i,j;
    ePersona auxPersona;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(persona[i].dni>persona[j].dni)
            {
                auxPersona=persona[j];
                persona[j]=persona[i];
                persona[i]=auxPersona;
            }
        }
    }
}

int validarDNI(ePersona persona[],int cant,int auxDni)
{
    int i,retorno=0;
    for(i=0;i<cant;i++)
    {
        if(persona[i].estado==OCUPADO && persona[i].dni==auxDni)
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}

void ordenarPorApellidoYNombre(ePersona persona[],int cant)
{
    int i,j;
    ePersona auxPersona;

    for(i=0;i<cant-1;i++)
    {
        if(persona[i].estado==VACIO)
        {
                continue;
        }
        for(j=i+1;j<cant;j++)
        {
            if(persona[j].estado==VACIO)
            {
                continue;
            }
            if(strcmpi(persona[j].apellido,persona[i].apellido)==-1)
            {
                auxPersona=persona[j];
                persona[j]=persona[i];
                persona[i]=auxPersona;
            }
        }
    }
}
