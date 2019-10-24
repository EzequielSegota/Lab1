#include "persona.h"


void inicializarPersonas(ePersona *personas,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        //(*(personas+i)).estado=-1
        (personas+i)->estado=-1;
    }
}

void hardcodearPersonas(ePersona* personas,int tam)
{
    char apellidoAux[][32]={"Medina","Lopez","Martinez","Ramirez"};
    int orden[]={88,33,55,99};
    int i;
    for(i=0;i<4;i++)
    {
        strcpy((personas+i)->apellido,apellidoAux[i]);
        (personas+i)->orden=orden[i];
        (personas+i)->id=i+1;
        (personas+i)->estado=1;
    }
}

void mostrarPersonas(ePersona* personas,int tam)
{
    int i;
    printf("\nID\tOrden\tApellido");
    for(i=0;i<tam;i++)
    {
        if((personas+i)->estado==1)
        {
            printf("\n%3d\t%3d\t%s",(personas+i)->id,(personas+i)->orden,(personas+i)->apellido);
        }
    }
}

void ordenarPersonas(ePersona* personas,int tam)
{
    int i,j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if((personas+i)->orden>(personas+j)->orden)
            {
                swapPunteros((personas+i),(personas+j));
            }
        }
    }
}

int siguienteIDPersonas(ePersona* miPersona,int tam)
{
    int i,posAux=-1;
    for(i=0;i<tam;i++)
    {
        if((miPersona+i)->estado!=1)
        {
            posAux=i+1;
            break;
        }
    }

    return posAux;
}

int buscarPersonasLibre(ePersona* miPersonas,int tam)
{
    int i,posAux=-1;
    for(i=0;i<tam;i++)
    {
        if((miPersonas+i)->estado==-1)
        {
            posAux=i;
            break;
        }
    }
    return posAux;
}

void pedirDatos(ePersona* miPersonas, int id)
{
    printf("\nIngrese un apellido:");
    gets(miPersonas->apellido);
    fflush(stdin);

    printf("\nIngrese un orden:");
    scanf("%d",&(miPersonas->orden));

    miPersonas->id=id;
    miPersonas->estado=1;
}

void altaPersonas(ePersona* miPersonas,int tam)
{
    int pos;
    pos=buscarPersonasLibre(miPersonas,tam);

    int idAux;
    idAux=siguienteIDPersonas(miPersonas,tam);
    if(pos!=-1 && idAux!=-1)
    {
        pedirDatos((miPersonas+pos),idAux);
    }
    else
    {
        printf("\nNo hay lugar");
    }
}

void swapPunteros(ePersona* primerPuntero,ePersona* segundoPuntero)
{
    ePersona temp;
    temp=*primerPuntero;
    *primerPuntero=*segundoPuntero;
    *segundoPuntero=temp;
}
