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

nodo * pendientes;
nodo * realizadas;

nodo * crearListaVacia();
nodo * crearTarea(tarea *l);
void insertarTarea(nodo ** start, tarea *tarea);
void mostrarTareas(nodo ** start);
nodo * quitarNodo(nodo ** start, int id);
tarea * buscarTareaPalabra(nodo * start, char palabra[]);
tarea * buscarTareaID(nodo * start, int id);
void eliminarNodo(nodo * start, int id);

int main(){

    int a = 1, b, opcion;
    tarea *tareas;

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
        printf("\ningrese 1 para agregar otra tarea o 0 para terminar: ");
        scanf("%d",&a);
    }

    nodo *aux1;
    aux1 = pendientes;

    //mostrar pendientes y mover a realizadas
    while (aux1 != NULL)
    {
        printf("\nTarea %d", aux1->t->tareaID);
        printf("\nDescripcion: %s", aux1->t->descripcion);
        printf("\nDuracion: %d", aux1->t->duracion);

        printf("\nrealizo la tarea? 1si, 0no: ");
        scanf("%d",&opcion);

        if (opcion == 1)
        {   
            nodo *nodonuevo;
            nodonuevo = quitarNodo(&aux1, aux1->t->tareaID);
            insertarTarea(&realizadas, nodonuevo->t);
            eliminarNodo(pendientes, aux1->t->tareaID);
        }

        aux1 = aux1->siguiente;
    }
    
    if (realizadas != NULL)
    {
        printf("\nrealizadas!!!");
        mostrarTareas(&realizadas);
    } else
    {
        printf("\nno se realizo ninguna tarea");
    }
    
    printf("\npendientes!!!");
    mostrarTareas(&pendientes);

    printf("\n desea buscar una tarea por id o palabra? 1-id, 2-palabra: ");
    scanf("%d",&b);

    tarea *buscada;

    if (b == 1)
    {   
        int id;
        printf("\ningrese el id: ");
        scanf("%d",&id);
        buscada = buscarTareaID(pendientes, id);
        if (buscada != NULL)
        {
            printf("\ntarea %d", buscada->tareaID);
            printf("\ndescripcion: %s", buscada->descripcion);
            printf("\nduracion: %d", buscada->duracion);
        } else
        {
            printf("\nno se encontro la tarea");
        }

    } else
    {
        char palabra[10];
        printf("\ningrese la palabra: ");
        gets(palabra);
        buscada = buscarTareaPalabra(pendientes, palabra);
        if (buscada != NULL)
        {
            printf("\ntarea %d", buscada->tareaID);
            printf("\ndescripcion: %s", buscada->descripcion);
            printf("\nduracion: %d", buscada->duracion);
        } else
        {
            printf("\nno se encontro la tarea");
        }
    }
    
    return 0;
    
}

//creo la lista vacia
nodo * crearListaVacia()
{
    return NULL;
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
nodo * quitarNodo(nodo ** start, int id)
{
    nodo * aux = *start;
    nodo * auxanterior = *start;

    while (aux != NULL && aux->t->tareaID != id)
    {
        auxanterior = aux;
        aux = aux->siguiente;
    }

    if (aux)
    {
        if (aux == *start)
        {
            *start = aux->siguiente;
        } else
        {
            auxanterior->siguiente = aux->siguiente;
        }
        
        aux->siguiente = NULL;
        
    }
    

    return auxanterior;
}

//eliminar nodo
void eliminarNodo(nodo * start, int id)
{
    nodo * aux;
    nodo * auxanterior;

    aux = start;

    while (aux && aux->t->tareaID != id)
    {
        auxanterior = aux;
        aux = aux->siguiente;
    }
    
    if (aux != NULL)
    {
        auxanterior->siguiente = aux->siguiente;
        free(aux);
    }

}

//busco con id
tarea * buscarTareaID(nodo * start, int id)
{
    nodo *ayuda = start;
    tarea *buscado = NULL;
    
    while (ayuda != NULL)
    {
        if (ayuda->t->tareaID == id)
        {
            buscado = ayuda->t;
            break;
        }
        ayuda = ayuda->siguiente;
    }
    
    return buscado;
}

//busco con palabra
tarea * buscarTareaPalabra(nodo * start, char palabra[])
{
    nodo *aux = start;
    tarea *buscado = NULL;

    while (aux != NULL)
    {
        if (strstr(aux->t->descripcion, palabra) != NULL)
        {
            buscado = aux->t;
            break;
        }
    
        aux = aux->siguiente;
    }
}