#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea{
    int tareaID; //numerado ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 - 100
}typedef tarea;

tarea * buscarTarea(tarea **listatareas, int identificador);

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
        tareaspendientes[i] = (struct Tarea *)malloc(sizeof(struct Tarea) * cantidad); //reserva memoria para la estructura
        tareaspendientes[i]->tareaID = i; 
        fflush(stdin);
        printf("\ningrese una descripcion de la tarea: ");
        char buff[50];
        gets(buff);
        tareaspendientes[i]->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tareaspendientes[i]->descripcion, buff);
        fflush(stdin);
        tareaspendientes[i]->duracion = 10 + rand() % 90;
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

    int identificador = 1;
    tarea *buscada;

    buscada = buscarTarea(tareaspendientes, identificador);

    if (buscada != NULL)
    {
        printf("\ntarea encontrada!!");
        printf("\nid: %d", buscada->tareaID);
        printf("\ndescripcion: %s", buscada->descripcion);
        printf("\nduracion: %d", buscada->duracion);
    } else
    {
        printf("\nno se encontro la tarea");
    }
    
    
    
    return 0;
}

tarea * buscarTarea(tarea **listatareas, int identificador)
{
    tarea **aux ;
    tarea *encontrada = NULL;
    int i = 0;

    aux = listatareas;

    while (aux[i] != NULL)
    {
        if (aux[i]->tareaID == identificador)
        {
            encontrada = aux[i];
            break;
        }
        
        i++;
    }
    
    return encontrada;
}
