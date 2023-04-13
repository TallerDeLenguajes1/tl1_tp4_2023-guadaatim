#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea{
    int tareaID; //numerado ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 - 100
}typedef tarea;

int main(){

    int cantidad;

    printf("\ningrese cuantas tareas debe realizar: ");
    scanf("%d",&cantidad);

    tarea **tareaspendientes = (struct Tarea **) malloc(sizeof(struct Tarea *) * cantidad); //vector grande de punteros
    tarea **tareasrealizadas = (struct Tarea **) malloc(sizeof(struct Tarea*) * cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        tareaspendientes[i] = NULL; //puntero a estructura
    }

    for (int i = 0; i < cantidad; i++)
    {
        tareaspendientes[i] = (struct Tarea *)malloc(sizeof(struct Tarea) * cantidad); //reserve memoria para la estructura
        tareaspendientes[i]->tareaID = i; 
        //tareaspendientes[i]->descripcion = (char *) malloc(sizeof);
        printf("\ningrese una descripcion de la tarea: ");
        char buff[50];
        gets(buff);
        tareaspendientes[i]->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tareaspendientes[i]->descripcion, buff);
        printf("\ningrese la duracion de la tarea: ");
        scanf("%d",&tareaspendientes[i]->duracion);
    }
    



    return 0;
}

