#include <stdio.h>
#include <stdlib.h>
#define MAX_VOTOS 50
void inicializarArray(float* votos,int tam);

void ordenar(float* votos,int tam);

void swapPunteros(float*,float*);

void mostrarArray(float* votos,int tam);

int main()
{
    float votos[MAX_VOTOS];
    char seguir='s';
    int flag=0;

    inicializarArray(votos,MAX_VOTOS);

    do{
        printf("\nIngrese num de orden:");
        scanf("%f",&votos[flag]);
        flag++;

        printf("\nDesea continuar(s/n):");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");
    }while(seguir=='s');

    printf("\nAntes de Ordenar");
    mostrarArray(votos,MAX_VOTOS);
    ordenar(votos,MAX_VOTOS);
    printf("\nDespues de Ordenar");
    mostrarArray(votos,MAX_VOTOS);

    return 0;
}

void inicializarArray(float* votos,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        *(votos+i)=-1;
    }
}

void mostrarArray(float* votos,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(*(votos+i)!=-1)
        {
            printf("\nPosicion-Orden");
            printf("\n  %d-%.2f",i,*(votos+i));
        }
    }
}

void ordenar(float* votos,int tam)
{
    int i,j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(*(votos+i)>*(votos+j))
            {
                swapPunteros(votos+i,votos+j);
            }
        }
    }


}

void swapPunteros(float* primerPuntero,float* segundoPuntero)
{
    float temp;
    temp=*primerPuntero;
    *primerPuntero=*segundoPuntero;
    *segundoPuntero=temp;
}
