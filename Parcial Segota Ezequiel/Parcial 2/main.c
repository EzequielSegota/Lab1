#include <stdio.h>
#include <stdlib.h>


///Realizar un programa que permita manejar una entidad definida por ud, con por lo menos 2 campos (uno numérico y otro alfanumérico). Dicho programa deberá trabajar la entidad de manera dinámica, de acuerdo a las reglas establecidas en la cátedra, permitiendo guardar en un archivo binario por lo menos dos datos de la entidad en cuestión. Por ultimo leer del archivo dichos datos y mostrarlos.


typedef struct
{
    int id;
    char nombre[32];
}ePersona;

ePersona* nuevaPersonaConstructor(void);

int setID(int id, ePersona* persona);

int setNombre(char* nombre, ePersona* persona);

int getNombre(char* nombre,ePersona* persona);

int getID(int* id,ePersona* persona);

ePersona* getPersona(ePersona* lista,int index);

void crearArchivo(FILE* path,ePersona* lista);

int main()
{
    ePersona* listaPersonas[2];
    ePersona* miPersonaUno;
    ePersona* miPersonaDos;
    FILE* newFile;

    miPersonaUno=nuevaPersonaConstructor();
    miPersonaDos=nuevaPersonaConstructor();

    setID(5,miPersonaUno);
    setID(12,miPersonaDos);

    setNombre("Pepe",miPersonaUno);
    setNombre("Juan",miPersonaDos);

    listaPersonas[1]=miPersonaUno;
    listaPersonas[2]=miPersonaDos;

    crearArchivo(newFile,listaPersonas);

    return 0;
}

ePersona* nuevaPersonaConstructor(void)
{
    ePersona* newPersona;
    newPersona = (ePersona*) malloc(sizeof(ePersona));

    return newPersona;
}

int setID(int id, ePersona* persona)
{
    int flag=1;
    if(persona!=NULL)
    {
        persona->id=id;
        flag=0;
    }
    return flag;
}

int setNombre(char* nombre, ePersona* persona)
{
    int flag=1;
    if(persona!=NULL)
    {
        strcpy(persona->nombre,nombre);
        flag=0;
    }
    return flag;
}

void crearArchivo(FILE* path,ePersona* lista)
{
    FILE* pFile;
    ePersona* unaPersona;
    int i;
    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path,"wb");

        for(i=0;i<2;i++)
        {
            unaPersona=getPersona(lista,i);
            fwrite(unaPersona,sizeof(ePersona),1,pFile);
        }
    }
}

ePersona* getPersona(ePersona* lista,int index)
{
    ePersona* newPersona=NULL;

    if(lista!=NULL)
    {
        newPersona*=lista[index];

    }
    return newPersona;
}
