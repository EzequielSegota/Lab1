#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* pArchive;
    char miNombre[50];//="Ezequiel";//Hardcodeado
    /*pArchive=fopen("miNombre.txt","w");

    fprintf(pArchive,"Me llamo:Ezequiel\n");
    fprintf(pArchive,"Me llamo:Alexis");

*/
    pArchive=fopen("miNombre.txt","r");

    while(!feof(pArchive))
    {
        fgets(miNombre,50,pArchive);
        printf("%s",miNombre);
    }


    fclose(pArchive);
    return 0;
}
