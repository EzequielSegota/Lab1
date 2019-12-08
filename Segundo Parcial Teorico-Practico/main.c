#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    float coordX;
    float coordY;
    char raza[20];
    char galaxia[20];
}eAlien;

eAlien* contructorAlien();

eAlien* contructorAlienParametros(int id,float coordX,float coodY,char*,char*);

void setIDAlien(eAlien* this,int id);

void getIDAlien(eAlien* this,int id);

void setCoordX(eAlien* this,float coordX);

void setCoordX(eAlien* this,float coordX);

void getCoordX(eAlien* this,float coordX);

void getCoordY(eAlien* this,float coordY);

void setRaza(eAlien* this,char*);

void setGalaxia(eAlien* this,char*);

//FALTAN GET


int escribirAliensBin(eAlien* Lista,int tam, char* path);

int main()
{
    eAlien* alienUno;
    eAlien* alienDos;
    FILE* pFile;

    alienUno=contructorAlien();


    alienDos=contructorAlienParametros(4,5.2,1.3,"Lalala","Lelele");

    if(alienDos!=NULL)
        printf("\n%d\t%f\t%f\t%s\t%s",alienDos->id,alienDos->coordX,alienDos->coordY,alienDos->raza,alienDos->galaxia);



    return 0;
}

eAlien* contructorAlien()
{
    eAlien* returnAux;
    returnAux = (eAlien*) malloc(sizeof(eAlien));
    return returnAux;
}

eAlien* contructorAlienParametros(int id,float coordX,float coorY,char* raza,char* galaxia)
{
    eAlien* returnAux;
    returnAux = (eAlien*) malloc(sizeof(eAlien));

    if(returnAux!=NULL)
    {
          returnAux->id=id;
          returnAux->coordX=coordX;
          returnAux->coordY=coorY;
          strcpy(returnAux->galaxia,galaxia);
          strcpy(returnAux->raza,raza);
    }
    return returnAux;
}

int escribirAliensBin(eAlien* Lista,int tam, char* path)
{
    FILE* expedienteX;
    eAlien* auxAlien;
    int i,flag=0;
    if(path!=NULL)
    {
        path=fopen(expedienteX,"wb");

        for( i=0;i<tam;i++)
        {
            //auxAlien=(eAlien*)getAlienByID(Lista,i);
            auxAlien=Lista[i];
           fwrite(auxAlien,sizeOf(eAlien),1,expedienteX);
        }
        flag=1;
        fclose(path);
    }
    return flag;
}
