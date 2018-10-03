#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "fecha.h"
typedef struct
{
    int idAlmuerzo;
    int legajoEmp;
    int idMenu;
    eFecha fechaAlmuerzo;
    int isEmpty;

}eAlmuerzo;

void opcionAlmuerzo(void);

#endif // ALMUERZO_H_INCLUDED
