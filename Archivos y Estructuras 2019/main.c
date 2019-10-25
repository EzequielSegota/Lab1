#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[32];
    char apellido[32];
    char email[32];
    float sueldo;
}eEmpleado;

int main()
{

    ///Esto pincha
    FILE* miArchivo;
    char id[50];
    char nombre[50];
    char apellido[50];
    char email[50];
    char sueldo[50];
    int i=0;
    miArchivo=fopen("Data.csv","r");

    eEmpleado lista[50];
    eEmpleado miEmpleado;

    fscanf("%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,email,sueldo);

    while(!feof(miArchivo))
    {
        fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,email,sueldo);

        miEmpleado.id=atoi(id);
        strcpy(miEmpleado.nombre,nombre);
        strcpy(miEmpleado.apellido,apellido);
        strcpy(miEmpleado.email,email);
        miEmpleado.sueldo=atof(sueldo);

        lista[i]=miEmpleado;
        i++;
    }

    for(i=0;i<50;i++)
    {
        printf("%d--%s--%s--%s--%f",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].email,lista[i].sueldo);
    }

    fclose(miArchivo);
    return 0;
}
