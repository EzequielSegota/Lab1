#include "alumnos.h"
#define T 5
int main()
{
    eAlumno listaAlumnos[T];
    int opcion;

    do
    {
        printf("\n1.Cargar alumnos");
        printf("\n2.Mostrar alumnos");
        printf("\n3.Ordenar alumnos(Por nombre)");
        printf("\nIngrese una opcion:");
        scanf("%d",&opcion);
        system("pause");
        system("cls");

        switch(opcion)
        {
            case 0:
                hardcodearAlumno(listaAlumnos,T);
                break;
            case 1:
                cargarAlumnos(listaAlumnos,T);
                break;
            case 2:
                mostrarAlumnos(listaAlumnos,T);
                break;
            case 3:
                ordenarAlumnosPorNombre(listaAlumnos,T);
                break;
        }


    }while(opcion!=5);






    return 0;
}
