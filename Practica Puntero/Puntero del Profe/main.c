#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int id;
    float orden;
    char apellido[50];
} ePersona;


void inicializar(ePersona*, int);
void mostrar(ePersona*, int);
void ordenar(ePersona*, int);
void swap(ePersona*, ePersona*);
int buscarLibre(ePersona* array, int tam);
int buscarProximoId(ePersona* array, int tam);
void pedirDatos(ePersona* persona,int id);

int main()
{
    ePersona personas[10];

    int i;



ePersona* per;
per= personas;

// per[0].id
// per->id
//(per+0)->id
// (*per).id
// (*(per+0)).id
// per[1].id
//(per+1)->id
// (*(per+1)).id




    for(i=0;i<10;i++){
        personas[i].id = i;
    }

    mostrar(personas,10);


    return 0;
}

void inicializar(ePersona* array, int tam){

        int i;
        for(i=0;i<tam;i++){
            (array+i)->id=-1;
        }
}

void mostrar(ePersona* array, int tam){

        int i=0;
        for(i=0;i<tam;i++){
                if((array+i)->id !=-1){
                    printf("%d-%d \n ",i, (array+i)->id);
                }

        }
}
int buscarProximoId(ePersona* array, int tam){
    int i=0;
    int id=-1;
    for(i= 0; i< tam ;i++){
            if((array + i)->id > id)
                id =(array + i)->id;
    }
    return id+1;
}
int buscarLibre(ePersona* array, int tam){
    int i=0;
    for(i= 0; i< tam ;i++){
            if((array + i)->id == -1)
                return i;
    }
}

void ordenar(ePersona* array, int tam){
    int i=0;
    int j=0;
    for(i= 0; i< tam -1;i++){
        for(j=i+1;j<tam;j++){
            if((array+i)->orden > (array+j)->orden)
            {
                swap(array + i, array + j);
            }
        }
    }

}
void swap(ePersona* a, ePersona* b){
    ePersona c;
    c = *a;
    *a = *b;
    *b = c;
}
















void pedirDatos(ePersona* per,int id){
    system("cls");
    printf("Ingrese el Apellido");
    fflush(stdin);
    gets(per->apellido);
    printf("Ingrese el Orden");
    scanf("%f", &(per->orden) );
    (*(per)).id= id;   }
void pedirDato(float* orden, char* apellido,
                int* id){
    system("cls");
    printf("Ingrese el Apellido");
    fflush(stdin);
    gets(*apellido);
    printf("Ingrese el Orden");
    scanf("%f", orden );
    *id = 25;
}




