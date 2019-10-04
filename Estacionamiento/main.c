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

El programa deber� contar con un men� de opciones que permita:
1.	Cargar un propietario. Cargar los datos para un propietario. El Id deber� ser autoincremental.
2.	Eliminar un propietario.
3.	Modificar datos de un propietario. Desplegar un men� de opciones con los datos que se podr�n modificar.
4.	Ingresar un veh�culo. Se ingresa la patente, la fecha y la hora de entrada junto al propietario del veh�culo.
5.	Egresar un veh�culo. Se ingresa la hora de salida del veh�culo.
6.	Informar:
a.	Todas las personas ordenadas por nombre y a�o de nacimiento.
b.	Todos los veh�culos ordenados por due�o y patente.
c.	Cada auto con el nombre de su due�o.
d.	Por cada due�o los autos que tiene estacionados.
e.	Ingresar un due�o y mostrar todos sus autos.
f.	Mostrar el total de la estad�a de cada auto, sabiendo que el valor hora es $100.
g.	Mostrar cuanto deber� pagar cada due�o por todos sus autos estacionados.
h.	Mostrar el/los due�os con m�s autos estacionados.
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

    //Ordenar por a�o
    return 0;
}
