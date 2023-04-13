#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tarea{
    int tareaID; //numerado ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 - 100
}typedef tarea;

int main(){

    int cantidad;

    printf("\ningrese cuantas tareas debe realizar: ");
    scang("%d",&cantidad);

    tarea **tareaspendientes = (struct Tarea **) malloc(sizeof(struct Tarea *) * cantidad); //vector grande de punteros
    tarea **tareasrealizadas = (struct Tarea **) malloc(sizeof(struct Tarea*) * cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        tareaspendientes[i] = NULL;
        tareaspendientes[i]->tareaID = i;
        printf("\ningrese una descripcion de la tarea: ");
        scanf("%d",&tareaspendientes[i]->descripcion);
        printf("\ningrese la duracion de la tarea: ");
        scanf("%d",&tareaspendientes[i]->duracion);
    }
    
    

    



    return 0;
}

