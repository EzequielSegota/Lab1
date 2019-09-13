#include "alumnos.h"


void mostrarAlumno(eAlumno unAlumno)
{
    printf("\n%d\t%s\t%d",unAlumno.legajo,unAlumno.nombre,unAlumno.nota);
}

eAlumno pedirAlumno()
{
    eAlumno miAlumno;//={1000,"Pepe",7};

    printf("\nIngrese legajo:");
    scanf("%d",&miAlumno.legajo);

    printf("\nIngrese nombre:");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("\nIngrese nota:");
    scanf("%d",&miAlumno.nota);

    return miAlumno;
}

int compararAlumnoPorLegajo(eAlumno unAlumno,eAlumno otroAlumno)
{
    int comp = 0;
    if(unAlumno.legajo==otroAlumno.legajo)
    {
        comp=1;
    }
    return comp;
}

void cargarAlumnos(eAlumno lista[],int TAM)
{
    int i;
     for(i=0;i<TAM;i++)
    {
        lista[i]=pedirAlumno();
    }
}

void mostrarAlumnos(eAlumno lista[],int TAM)
{
    int i;
     for(i=0;i<TAM;i++)
    {
        mostrarAlumno(lista[i]);
    }
}

void ordenarAlumnosPorNombre(eAlumno lista[],int TAM)
{
    int i,j;
    eAlumno auxAlumno;

    for(i=0;i<TAM;i++)
    {
        for(j=i+1;j<TAM;j++)
        {
            if(stricmp(lista[j].nombre,lista[i].nombre)<0)
            {
                auxAlumno=lista[i];
                lista[i]=lista[j];
                lista[j]=auxAlumno;
            }
        }
    }

}

void hardcodearAlumno(eAlumno lista[],int TAM)
{
    int legajo[]={101,102,105,444,555};
    int nota[]={10,5,9,3,8};
    char nombre[][20]={"Juan","Maria","Jose","Rocio","Daniel"};
    int i;
    for(i=0;i<TAM;i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre,nombre[i]);
    }
}
