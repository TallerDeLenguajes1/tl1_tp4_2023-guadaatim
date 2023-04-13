#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tarea{
    int tareaID; //numerado ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 - 100
}typedef tarea;

void cargar();

int main(){

    int cantidad;

    printf("\ningrese cuantas tareas debe realizar: ");
    scang("%d",&cantidad);

    tarea **puntero = (struct Tarea **) malloc(sizeof(struct Tarea *) * cantidad); //vector grande de punteros

    for (int i = 0; i < cantidad; i++)
    {
        puntero[i] = NULL;
    }
    
    
    



    return 0;
}

void cargar()
{

}