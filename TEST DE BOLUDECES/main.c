#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


///Realizar un programa que permita manejar una entidad definida por ud, con por lo menos
///2 campos (uno numérico y otro alfanumérico). Dicho programa deberá trabajar la entidad de manera dinámica,
///de acuerdo a las reglas establecidas en la cátedra, permitiendo guardar en un archivo binario por lo menos dos
///datos de la entidad en cuestión. Por ultimo leer del archivo dichos datos y mostrarlos.


typedef struct
{
    int id;
    char email[32];
}ePersona;

ePersona* nuevaPersonaConstructor(void);

int setID(int id, ePersona* persona);

int setEmail(char* email, ePersona* persona);

int getEmail(char* email,ePersona* persona);

int getID(int* id,ePersona* persona);

bool crearArchivoBin(char* path,ePersona** lista);

bool loadBinary(const char *path, ePersona ***lista);
int main()
{
    ePersona** listaPersonas;
    ePersona* miPersonaUno;
    ePersona* miPersonaDos;
    int i,opcion,flagBin=0;

    do{
        system("cls");
        printf("\n1.Crear archivo binario");
        printf("\n2.Leer archivo binario");
        printf("\n3.Salir");
        printf("\nIngrese opcion:");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://Importante
                listaPersonas=malloc(sizeof *listaPersonas * 2);

                miPersonaUno=nuevaPersonaConstructor();
                miPersonaDos=nuevaPersonaConstructor();

                listaPersonas[0]=miPersonaUno;

                listaPersonas[1]=miPersonaDos;

                setID(5,miPersonaUno);
                setID(12,miPersonaDos);

                setEmail("alalal@gmail.com",miPersonaUno);
                setEmail("lalala@hotmail.com",miPersonaDos);

                bool exito=crearArchivoBin("lista.bin",listaPersonas);
                if(exito)
                {
                    printf("\nArchivo generado exitosamente.\n");
                    flagBin=1;
                }
                system("pause");
                break;
            case 2:
                if(flagBin==0)
                {
                    printf("\nPrimero debe generar un archivo.");
                }
                else
                {
                    bool exitoDos=loadBinary("lista.bin",&listaPersonas);
                    if(exitoDos)
                    {
                        int idAux;
                        char emailAux[32];
                        for(i=0;i<2;i++)
                        {
                            getID(&idAux,listaPersonas[i]);
                            getEmail(emailAux,listaPersonas[i]);
                            printf("\nID:%d\nEmail:%s\n",idAux,emailAux);
                        }
                    }
                }//Hasta acá
                system("pause");
                break;
            case 3:
                printf("\nAdios!");
                break;
            default:
                printf("\nOpcion no valida!");
        }

    }while(opcion!=3);






    return 0;
}

ePersona* nuevaPersonaConstructor()
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

int setEmail(char* email, ePersona* persona)
{
    int flag=1;
    if(persona!=NULL)
    {
        strcpy(persona->email,email);
        flag=0;
    }
    return flag;
}

int getEmail(char* email,ePersona* persona)
{
    if(email!=NULL && persona!=NULL)
    {
        strcpy(email,persona->email);
    }
    return persona;
}

int getID(int* id,ePersona* persona)
{
    if(persona!=NULL && id!=NULL)
    {
        *id=persona->id;
    }
    return persona;
}

bool crearArchivoBin(char* path,ePersona** lista)
{
    FILE* pFile;
    int i;
    bool retorno=false;
    ePersona* personaAux;
    if(path!=NULL && lista!=NULL)
    {
        pFile=fopen(path,"wb");

        for(i=0;i<2;i++)
        {
            if(fwrite(lista[i],sizeof **lista,1,pFile)>=1)
            retorno=true;
        }
    }

    fclose(pFile);

    return retorno;
}

bool loadBinary(const char *path, ePersona ***lista)
{
    FILE* pArchivo;
    bool ret=false;
    int i;

    ePersona **listaAux = malloc(sizeof *listaAux * 2);

    if(lista!=NULL)
    {
        pArchivo=fopen(path,"rb");
        ePersona newPersonaAux;

        for(i=0;i<2;i++)
        {
            if(fread(&newPersonaAux,sizeof newPersonaAux,1,pArchivo)>=1)
            {
                ePersona* newPersona=nuevaPersonaConstructor();
                getID(&newPersona->id,&newPersonaAux);
                getEmail(newPersona->email,&newPersonaAux);

                listaAux[i]=newPersona;
                ret=true;
            }
        }

    }

    *lista = listaAux;
    fclose(pArchivo);


    return ret;
}

/*void* getPersona(ePersona** lista,int index)
{
    if(lista!=NULL)
    {
        return lista[index];
    }
}
int crearArchivo(char* pFile, ePersona** this)
{
    int i, length;
    int retorno=-1;
    FILE* fp;
    ePersona* auxPersona;
    int idAux;
    char emailAux[32];

    fp = fopen(pFile, "w");

    if(pFile!=NULL)
    {
        retorno=0;

        for(i=0;i<2;i++)
        {
            auxPersona=getPersona(this,i);

            getEmail(emailAux,auxPersona);
            getID(&idAux,auxPersona);

            printf("%d",idAux);

            fprintf(fp, "%d,%s\n", idAux,emailAux);
        }

        printf("Archivo generado con exito.\n");
    }

    fclose(fp);

    return retorno;
}*/

