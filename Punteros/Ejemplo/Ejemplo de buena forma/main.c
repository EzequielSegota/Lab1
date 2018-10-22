#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    p=(int*)malloc(sizeof(int));

    if(p==NULL)
    {
        printf("\nNo hay espacio.");
        exit(1);
    }



    *p=24;



    printf("%d",*p);


    free(p);


    return 0;
}
