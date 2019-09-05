#include "funciones.h"
void mostrarArray(int myArray[], int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("\nEdad Ingresada:%d",myArray[i]);
    }
}

int encontrarMax(int myArray[],int cantidad)
{
    int i,max=myArray[0];
    for(i=0;i<cantidad;i++)
    {
        if(myArray[i]>max)
            max=myArray[i];
    }
    return max;
}

int encontrarMin(int myArray[],int cantidad)
{
    int i,min=myArray[0];
    for(i=0;i<cantidad;i++)
    {
        if(myArray[i]<min)
            min=myArray[i];
    }
    return min;
}

void inicializarArray(int myArray[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        myArray[i]=0;
    }
}

void cargaSecuencialDeArray(int myArray[],int cantidad,char* mensaje)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf(mensaje);
        scanf("%d",&myArray[i]);
    }
}

float dameElPromedio(int myArray[],int cantidad)
{
    int i;
    float acumulador=0;
    for(i=0;i<cantidad;i++)
    {
        acumulador=acumulador+myArray[i];
    }
    acumulador=acumulador/cantidad;
    return acumulador;
}

void ordenarArray(int myArray[],int cantidad)
{
    int i,j,aux;

    for(i=0;i<cantidad-1;i++)//Empieza en 0 y va hasta el limite menos 1
    {
        for(j=i+1;j<cantidad;j++)//Empieza adelante de i y va hasta el final
        {
            if(myArray[i]>myArray[j])//si el primero es mayor al segundo
            {
                aux=myArray[j];//Guardo el segundo en aux
                myArray[j]=myArray[i];//Remplazo el segundo con el primero
                myArray[i]=aux;//Remplazo el primero con el aux(antiguo segundo)
            }
        }
    }
}
