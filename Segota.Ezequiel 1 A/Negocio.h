#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuegos;

typedef struct
{
    int id;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    float importe;
    int isEmpty;
}eCliente;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idJuego;
    int idCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

void inicializarEstado(eJuegos juegos[],eCliente clientes[],eAlquiler alquiler[],int tamJuego,int tamCliente,int tamAlquiler);
int menu();
int menuJuegos(eJuegos juegos[],int tamJuego);
int menuClientes(eCliente cliente[],int tamJuego);
int menuAlquiler(eAlquiler alquiler[],int tamAlquiler);
int buscarLugarJuego(eJuegos juego[],int tamJuegos);
int buscarLugarCliente(eCliente clientes[],int tamClientes);
int altaJuego(eJuegos juego[],int tamJuego);
int bajaJuego(eJuegos juego[],int tamJuego);
int modificarJuego(eJuegos juego[],int tamJuego);
int buscarJuego(eJuegos juego[],int tamJuego,int codigo);
int siguienteIDJuego(eJuegos juego[],int tamJuego);
void mostrarJuegos(eJuegos juegos[], int tamJuego);
void mostrarJuego(eJuegos juego);



#endif // NEGOCIO_H_INCLUDED
