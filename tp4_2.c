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
        tareasrealizadas[i] = NULL;
    }

    for (int i = 0; i < cantidad; i++)
    {
        tareaspendientes[i] = (struct Tarea *)malloc(sizeof(struct Tarea) * cantidad); //reserve memoria para la estructura
        tareaspendientes[i]->tareaID = i; 
        fflush(stdin);
        printf("\ningrese una descripcion de la tarea: ");
        char buff[50];
        gets(buff);
        tareaspendientes[i]->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tareaspendientes[i]->descripcion, buff);
        fflush(stdin);
        printf("\ningrese la duracion de la tarea: ");
        scanf("%d",&tareaspendientes[i]->duracion);
    }
    
    int realizada, j = 0;

    for (int i = 0; i < cantidad; i++)
    {
        printf("\nTarea %d", tareaspendientes[i]->tareaID);
        printf("\nDescripcion: %s", tareaspendientes[i]->descripcion);
        printf("\nDuracion: %d", tareaspendientes[i]->duracion);

        printf("\nSe realizo la tarea? 1-si, 0-no: ");
        scanf("%d",&realizada);

        if (realizada == 1)
        {
            tareasrealizadas[j] = tareaspendientes[i];
            tareaspendientes[i] = NULL;
            j++;
        }
        
    }
    
    printf("\ntareas realizadas");

    for (int k = 0; k < j; k++)
    {
        if (tareasrealizadas[k] != NULL){
            printf("\nTarea %d", tareasrealizadas[k]->tareaID);
            printf("\nDescripcion: %s", tareasrealizadas[k]->descripcion);
            printf("\nDuracion: %d", tareasrealizadas[k]->duracion);
        }
        else
        {
            break;
        }
    }
    
    return 0;
}

