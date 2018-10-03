#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
} eSector;

int elegirSector(eSector sectores[],int tam);

#endif // SECTOR_H_INCLUDED
