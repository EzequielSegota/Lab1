#include <stdio.h>
#include <stdlib.h>

int ingresarInt(int myArrayInt[], int tam);

int sumarPares(int myArrayInt[],int tam);

void ordenarArray(int myArrayInt[],int tam);

int main()
{
    int aux[10];
    int prueba;

    prueba=ingresarInt(aux,10);
    printf("\nValor de retorno:%d\n",prueba);
    if(prueba!=-1)
    {
        prueba=sumarPares(aux,10);
        printf("Suma de pares:%d\n",prueba);

        ordenarArray(aux,10);
    }

    return 0;
}

int ingresarInt(int myArrayInt[],int tam)
{
    int i,j,flag=0;

    for(i=0;i<tam;i++)
    {
        printf("\nIngrese num:");
        scanf("%d",&myArrayInt[i]);



        for(j=0;j<i;j++)
        {
            if(myArrayInt[i]==myArrayInt[j])
            {
                flag++;
            }
        }

        if(flag>=3)
        {
            flag=-1;
            break;
        }
    }
/*
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(myArrayInt[i]==myArrayInt[j])
            {
                flag++;
            }

        }
        if(flag>=3)
        {
            flag=-1;
            break;
        }
    }
*/

    return flag;
}

int sumarPares(int myArrayInt[],int tam)
{
    int i,retorno=0;

    for(i=0;i<tam;i++)
    {
        if(myArrayInt[i]%2==0)
        {
            retorno=myArrayInt[i]+retorno;
        }
    }

    return retorno;
}

void ordenarArray(int myArrayInt[],int tam)
{
    int i,j,aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(myArrayInt[i]>myArrayInt[j])
            {
                aux=myArrayInt[i];
                myArrayInt[i]=myArrayInt[j];
                myArrayInt[j]=aux;
            }
        }
    }
    printf("Array ordenado\n");
    for(i=0;i<tam;i++)
    {
        printf("%d\n",myArrayInt[i]);
    }
}
