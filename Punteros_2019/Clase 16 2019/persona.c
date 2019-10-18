#include "persona.h"

ePersona* new_Persona()
{
    ePersona* miPersona;

    miPersona=calloc(sizeof(ePersona),1);//Devuelve un puntero del sizeof de la Estructura
/*
    miPersona->legajo=100;
    miPersona->edad=40;
    miPersona->altura=1.87;
*/
    return miPersona;
}

int mostrarPersona(ePersona* pPersona)
{
    int ret=-1;
    if(pPersona!=NULL)//Verifico siempre que no sea NULL
    {
        printf("Persona:\n");
        printf("%d--%d--%.2f",
               pPersona->legajo,
               pPersona->edad,
               pPersona->altura);
        ret=1;
    }
    return ret;
}

int delete_Persona(ePersona* pPersona)
{
    int ret=-1;
    if(pPersona!=NULL)//Verifico siempre que no sea NULL
    {
        free(pPersona);
        ret=1;
    }
    return ret;
}

ePersona* new_Persona_Parametros(int legajo,int edad,float altura)
{
    ePersona* miPersona;

    //miPersona=(int*)malloc(sizeof(ePersona));
    miPersona=new_Persona();

    if(miPersona!=NULL)
    {
        miPersona->legajo=legajo;
        miPersona->edad=edad;
        miPersona->altura=altura;
    }

    return miPersona;
}
