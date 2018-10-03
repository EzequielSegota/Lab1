#include "sector.h"
int elegirSector(eSector sectores[],int tam)
{
    int idSector;
    int i;
    printf("\nSectores\n\n");
    for(i=0;i<tam;i++)
    {
        printf("%d. %s\n",sectores[i].id,sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d",&idSector);

    return idSector;
}
