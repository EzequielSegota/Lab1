#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int codigo;
    char nombre[25];
    int capacidad;
    float precio;
}ePendrive;

int cargarPendrive(ePendrive* pen);

void mostrarPendrive(ePendrive* pen);

int cargarPendriveParam(ePendrive* pen,int codigo,char nombre[],int capacidad,float precio);

int main()
{
    int opcion,flag;
    ePendrive pendrive;

    do{
        printf("1.Cargar Pendrive\n");
        printf("2.Mostrar Pendrive\n");
        printf("3.Salir\n");
        printf("\nIngrese opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                //flag=cargarPendrive(&pendrive);
                flag=cargarPendriveParam(&pendrive,1234,"pepito",16,200.55);
                system("cls");
                break;
            case 2:
                system("cls");
                if(flag==1)
                {
                    mostrarPendrive(&pendrive);
                    system("pause");
                }
                system("cls");
                break;
            case 3:
                system("cls");
                printf("\nAdios\n");
        }

    }while(opcion!=3);


    return 0;
}



int cargarPendrive(ePendrive* pen)
{
    int flag=0;
    if(pen!=NULL)
    {

        printf("\nIngrese codigo:");
        scanf("%d",&pen->codigo);

        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(pen->nombre);

        printf("\nIngrese capacidad:");
        scanf("%d",&pen->capacidad);

        printf("\nIngrese precio:");
        scanf("%f",&pen->precio);



        flag=1;

    }
    return flag;
}



void mostrarPendrive(ePendrive* pen)
{
    if(pen!=NULL)
    printf("\nCodigo:%d\tNombre:%s\tCapacidad:%d\tPrecio:%.2f\n",pen->codigo,pen->nombre,pen->capacidad,pen->precio);
}

int cargarPendriveParam(ePendrive* pen,int codigo,char nombre[],int capacidad,float precio)
{
    int flag=0;
    if(pen!=NULL)
    {
        pen->codigo=codigo;

        pen->capacidad=capacidad;

        pen->precio=precio;

        strcpy(pen->nombre,nombre);

        flag=1;
    }




    return flag;
}
