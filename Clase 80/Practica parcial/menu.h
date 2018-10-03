#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct
{
    int idMenu;
    char descripcion[51];
    float importe;
    int isEmpty;
}eMenu;

void opcionMenu(void);
#endif // MENU_H_INCLUDED
