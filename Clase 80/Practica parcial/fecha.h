#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

eFecha ingresarFecha(void);
#endif // FECHA_H_INCLUDED
