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
nodo * pendientes;
nodo * realizadas;

nodo * crearListaVacia();
nodo * crearTarea(tarea *l);
void insertarTarea(nodo ** start, tarea *tarea);
void mostrarTareas(nodo ** start);
nodo * quitarNodo(nodo * start, int id);



int main(){

    int a, opcion, i = 0;

    //asigno memoria a las tareas
    tarea *tareas = (tarea *)malloc(sizeof(tarea));

    //creo "cabecera"
    pendientes = crearListaVacia();
    realizadas = crearListaVacia();

    while (a != 0)
    {
        tareas = (struct Tarea *)malloc(sizeof(struct Tarea)); //reserva memoria para la estructura
        tareas->tareaID = i; 
        fflush(stdin);
        printf("\ningrese una descripcion de la tarea: ");
        char buff[50];
        gets(buff);
        tareas->descripcion = malloc(sizeof(char) * strlen(buff + 1));
        strcpy(tareas->descripcion, buff);
        fflush(stdin);
        tareas->duracion = 10 + rand() % 90;
        //inserto nodos
        insertarTarea(&pendientes, tareas);
        i++;

        printf("\ningrese 1 para agregar otra tarea o 0 para terminar: ");
        scanf("%d",&a);
    }

    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux = pendientes;

    //mostrar pendientes
    while (aux != NULL)
    {
        printf("\nTarea %d", aux->t->tareaID);
        printf("\nDescripcion: %s", aux->t->descripcion);
        printf("\nDuracion: %d", aux->t->duracion);

        printf("\nrealizo la tarea? 1si, 0no: ");
        scanf("%d",&opcion);

        if (opcion == 1)
        {   
            nodo *nodonuevo;
            nodonuevo = quitarNodo(aux, aux->t->tareaID);
            insertarTarea(&realizadas, nodonuevo->t);
        }

        aux = aux->siguiente;

    }

    mostrarTareas(&realizadas);

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

//quitar nodo
nodo * quitarNodo(nodo * start, int id)
{
    nodo * aux = start;
    nodo * auxanterior = start;

    while (aux != NULL && aux->t->tareaID != id)
    {
        auxanterior = aux;
        aux = aux->siguiente;
    }
    
    return auxanterior;
}