#include <stdio.h>
#include <stdlib.h>
int main()
{

    int* miVector,auxVector;
    int x;
    miVector=(int*) malloc(sizeof(int)*5);
    //supongamos que me dio direccion 0x100
    if(miVector!=NULL)
    {
        for(x=0;x<5;x++)
        {
            //miVector = 0x100+x va sumando a la siguente direccion del array
            *(miVector+x)=x+1;//A mi vector en posicion de mivector + x = x+1 (0+1 en primer iteracion)
        }
        for(x=0;x<5;x++)
        {
            printf("%d\n",*(miVector+x));//Muestro
        }

        //AGRANDO

        printf("Pido Espacio\n");
        auxVector=(int*)realloc(miVector,sizeof(int)*10);//Pido espacio para 10 los guardo en auxVector por si es NULL asi no se pierden los datos

        if(auxVector!=NULL)
        {
            miVector=auxVector;
            for(x=5;x<10;x++)
            {
                *(miVector+x)=x+1;
            }
            for(x=0;x<10;x++)
            {
                printf("%d\n",*(miVector+x));//Muestro
            }
        }
        else
        {
            printf("\nNo hay lugar");
        }

        //ACHICO
        printf("Lo reducimos\n");

        miVector=(int*)realloc(miVector,sizeof(int)*3);//Lo achico y lo asigno directamente a miVector directamente porque siempre va a ver menos
        for(x=0;x<3;x++)
        {
            printf("%d\n",*(miVector+x));//Muestro
        }

    }
    else
    {
        printf("\nNo hay lugar");
    }

    return 0;
}
