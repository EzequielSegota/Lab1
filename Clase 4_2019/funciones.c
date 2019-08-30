#include "funciones.h"

int pedirEntero(char* msj,char* msjError ,int min, int max)
{
    int n;
    printf("\n%s",msj);
    scanf("%d",&n);
    while(n<min || n>max)
    {
        printf("\n%s",msjError);
        scanf("%d",&n);
    }
    system("pause");
    system("cls");
    return n;
}




