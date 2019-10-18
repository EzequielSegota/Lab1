#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* pEntero=(int*)calloc(sizeof(int),5);
    int i;
    *(pEntero+3)=5;
    for(i=0;i<5;i++)
    {
        printf("P[%d]:%d\n",i,*(pEntero+i));
    }

    free(pEntero);

    return 0;
}
