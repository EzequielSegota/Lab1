#include <stdio.h>
#include <stdlib.h>
#define MAXPRODUCTOS 4
typedef struct
{
    int id;
    char nombre[50];
    float precio;
}eProducto;

void ordenarProductos(eProducto*,int);
void mostrarProductos(eProducto*,int);
int main()
{
    eProducto productos[MAXPRODUCTOS];
    hardcodePersonas(productos,MAXPRODUCTOS);
    printf("\nANTES DE ORDENAR:\n");
    mostrarProductos(productos,MAXPRODUCTOS);
    ordenarProductos(productos,MAXPRODUCTOS);
    printf("\nANTES DE DESPUES DE ORDENAR:\n");
    mostrarProductos(productos,MAXPRODUCTOS);


    return 0;
}

void ordenarProductos(eProducto productos[],int tam)
{
    int i,j;
    eProducto auxProducto;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(productos[i].precio>productos[j].precio)
            {
                auxProducto=productos[j];
                productos[j]=productos[i];
                productos[i]=auxProducto;
            }
            else if(productos[i].precio==productos[j].precio)
            {
                if(strcmp(productos[i].nombre,productos[j].nombre)==1)
                {
                    auxProducto=productos[j];
                    productos[j]=productos[i];
                    productos[i]=auxProducto;
                }
            }
        }
    }
}

void hardcodePersonas(eProducto newPersona[],int cant)
{
    int i;
    char nombre[4][32]={"Arroz","Arbeja","Lenteja","Agua"};
    int id[4]={1,2,3,4};
    float precio[4]={75.25,18.50,5,5};
    for(i=0;i<cant;i++)
    {
        strcpy(newPersona[i].nombre,nombre[i]);
        newPersona[i].id=id[i];
        newPersona[i].precio=precio[i];
    }
}

void mostrarProductos(eProducto productos[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n|Nombre\t|Precio\t|ID|\n%s\t|%f\t|%d|",productos[i].nombre,productos[i].precio,productos[i].id);
    }
}
