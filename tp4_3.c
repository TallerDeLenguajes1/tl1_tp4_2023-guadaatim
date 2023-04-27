#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Tarea{
    int tareaID; //numerado ciclo iterativo
    char *descripcion;
    int duracion; // entre 10 - 100
}typedef tarea;

struct nodo{
    tarea *t;
    struct nodo *siguiente;
}typedef nodo;

nodo * start;

nodo * crearListaVacia();
nodo * crearTarea(tarea *l);
void insertarTarea(nodo ** start, tarea *tarea);
void mostrarTareas(nodo ** start);


int main(){

    int cantidad;

    printf("\ningrese cuantas tareas debe realizar: ");
    scanf("%d",&cantidad);

    //asigno memoria a las tareas
    tarea **tareas = (tarea **)malloc(sizeof(tarea *) * cantidad);

    //creo "cabecera"
    start = crearListaVacia();

    //cargo las tareas
    for (int i = 0; i < cantidad; i++)
    {
        tareas[i] = (struct Tarea *)malloc(sizeof(struct Tarea) * cantidad); //reserva memoria para la estructura
        tareas[i]->tareaID = i; 
        fflush(stdin);
        printf("\ningrese una descripcion de la tarea: ");
        char buff[50];
        gets(buff);
        tareas[i]->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tareas[i]->descripcion, buff);
        fflush(stdin);
        tareas[i]->duracion = 10 + rand() % 90;
        //inserto nodos
        insertarTarea(&start, tareas[i]);
    }
    
    mostrarTareas(&start);

    

    
    return 0;
    
}

//creo la lista vacia
nodo * crearListaVacia()
{
    return NULL;
}

int esListaVacia(nodo * lista)
{
    if (lista->siguiente == NULL)
    {
        return 1;
    } else
    {
        return 0;
    }
}

//creo una tarea
nodo * crearTarea(tarea *l)
{
    nodo *aux;
    aux = (nodo *)malloc(sizeof(nodo));
    aux->t = l;
    aux->siguiente = NULL;
    
    return aux;
}

//agrego tareas
void insertarTarea(nodo ** start, tarea *tarea)
{
    nodo *nuevatarea = crearTarea(tarea);
    nuevatarea->siguiente = *start;
    *start = nuevatarea;
}

//muestro
void mostrarTareas(nodo ** start)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux = *start;

    while (aux != NULL)
    {
        printf("\nTarea %d", aux->t->tareaID);
        printf("\nDescripcion: %s", aux->t->descripcion);
        printf("\nDuracion: %d", aux->t->duracion);

        aux = aux->siguiente;

    }
    
}
