#include "persona.h"
#include "utn.h"
#define MAXPERSONA 5
#define MAXVEHICULOS 15
/*
Estructuras a utilizar:
ePropietario
PK	IdPropietario
	nombre
	fechaNacimiento

eFecha
	dia
	mes
	anio

eVehiculo
PK	patente
	fechaIngreso
	horaEntrada
	horaSalida
FK	idPropietario

El programa deberá contar con un menú de opciones que permita:
1.	Cargar un propietario. Cargar los datos para un propietario. El Id deberá ser autoincremental.
2.	Eliminar un propietario.
3.	Modificar datos de un propietario. Desplegar un menú de opciones con los datos que se podrán modificar.
4.	Ingresar un vehículo. Se ingresa la patente, la fecha y la hora de entrada junto al propietario del vehículo.
5.	Egresar un vehículo. Se ingresa la hora de salida del vehículo.
6.	Informar:
a.	Todas las personas ordenadas por nombre y año de nacimiento.
b.	Todos los vehículos ordenados por dueño y patente.
c.	Cada auto con el nombre de su dueño.
d.	Por cada dueño los autos que tiene estacionados.
e.	Ingresar un dueño y mostrar todos sus autos.
f.	Mostrar el total de la estadía de cada auto, sabiendo que el valor hora es $100.
g.	Mostrar cuanto deberá pagar cada dueño por todos sus autos estacionados.
h.	Mostrar el/los dueños con más autos estacionados.
*/


int main()
{
    //char patente[23]={"AA 111 BB"};
    ePersona newPersona[MAXPERSONA];
    eVehiculo newVehiculo[MAXVEHICULOS];
    inicializarPersonas(newPersona,MAXPERSONA);
    inicializarVehiculos(newVehiculo,MAXVEHICULOS);
    hardcodePersonas(newPersona,4);

    //mostrarPersonas(newPersona,MAXPERSONA);

    hardcodeVehiculos(newVehiculo,4);

    //mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);

    int idAux;
    char respuesta='s';
    do{
        switch(menuPrincipal())
        {
            case 1:
                system("cls");
                altaPropietario(newPersona,MAXPERSONA);
                //
                break;
            case 2:
                system("cls");
                mostrarPersonasConVehiculos(newPersona,MAXPERSONA,newVehiculo,MAXVEHICULOS);
                bajaPersona(newPersona,MAXPERSONA);
                /*
                ordenarPorNombre(newPersona,MAXPERSONA);
                mostrarPersonasConVehiculos(newPersona,MAXPERSONA,newVehiculo,MAXVEHICULOS);
                */

                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                mostrarPersonasConVehiculos(newPersona,MAXPERSONA,newVehiculo,MAXVEHICULOS);
                //mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                modificarPersona(newPersona,MAXPERSONA);
                break;
            case 4:
                //ordenarPorPatente(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                //mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                system("cls");
                altaVehiculo(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                mostrarVehiculos(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                bajaVehiculo(newVehiculo,MAXVEHICULOS,newPersona,MAXPERSONA);
                /*mostrarPersonas(newPersona,MAXPERSONA);
                printf("\nIngrese un duenio(ID):");
                scanf("%d",&idAux);
                mostrarVehiculosPorID(newVehiculo,MAXVEHICULOS,idAux);*/
                break;
            case 6:
                system("cls");
                menuInformes(newPersona,MAXPERSONA,newVehiculo,MAXVEHICULOS);
                //calcularEstadia(newVehiculo,MAXVEHICULOS);
                break;
            default:
                system("cls");
                printf("\nError, ingrese 1-6\n");
                system("pause");

        }

    }while(respuesta=='s');










    //PRUEBA DE PATENTE
//    mostrarVehiculo(newVehiculo[buscarPorPatente(newVehiculo,MAXVEHICULOS,patente)],newPersona,MAXPERSONA);

    //Ordenar por año
    return 0;
}
