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


nodo * crearListaVacia();
nodo * crearTarea(tarea *l);
tarea * cargarTarea(tarea *t);
void menu(nodo ** pendientes, nodo ** realizadas, nodo ** enproceso);
void insertarTarea(nodo ** start, tarea *tarea);
void mostrarTareas(nodo ** start);
nodo * quitarTarea(nodo ** start, int id);
tarea * buscarTareaPalabra(nodo * start, char palabra[]);
tarea * buscarTareaID(nodo * start, int id);
void * eliminarTareas(nodo * nodoeliminar);

int main(){

    int a = 1, b, opcion, i = 0;
    tarea *tareas;
    nodo * pendientes;
    nodo * realizadas;
    nodo * tareasenproceso;

    //creo "cabecera"
    pendientes = crearListaVacia();
    realizadas = crearListaVacia();
    tareasenproceso = crearListaVacia();

    while (a != 0)
    {
        insertarTarea(&pendientes, cargarTarea(tareas));
        printf("\ningrese 1 para seguir o 0 para terminar");
        scanf("%d",&a);
    }

    nodo *aux1 = pendientes;
    nodo **aux2 = &pendientes;

    //mostrar pendientes y mover a realizadas

    /*while (aux1 != NULL)
    {
        printf("\nTarea %d", aux1->t->tareaID);
        printf("\nDescripcion: %s", aux1->t->descripcion);
        printf("\nDuracion: %d", aux1->t->duracion);

        printf("\nrealizo la tarea? 1si, 0no: ");
        scanf("%d",&opcion);

        if (opcion == 1)
        {   
            nodo *nodonuevo;
            nodonuevo = quitarTarea(aux2, aux1->t->tareaID);
            insertarTarea(&realizadas, nodonuevo->t);
            eliminarTareas(nodonuevo);
        }

        aux1 = aux1->siguiente;

    }*/

    pendientes = *aux2;

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

tarea * cargarTarea(tarea *t)
{
    int i = 0;

    t = (struct Tarea *)malloc(sizeof(struct Tarea)); //reserva memoria para la estructura
    t->tareaID = i; 
    fflush(stdin);
    printf("\ningrese una descripcion de la tarea: ");
    char buff[50];
    gets(buff);
    t->descripcion = malloc(sizeof(char) * strlen(buff + 1));
    strcpy(t->descripcion, buff);
    fflush(stdin);
    t->duracion = 10 + rand() % 90;
    i++;

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

void menu(nodo ** pendientes, nodo ** realizadas, nodo ** enproceso)
{
    int opcion;
    int mostrar;
    int eliminar, ideliminar;
    nodo * tareaseliminadas;
    nodo * nodoquitado;
    
    tareaseliminadas = crearListaVacia();

    printf("\n-------MENU-------\n");
    printf("\ningrese una opcion: ");
    printf("\n1 - Mostrar Tareas");
    printf("\n2 - Eliminar Tareas");
    printf("\n3 - Mover tareas");
    printf("\n4 - Salir");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        printf("\ningrese que tareas desea mostrar: ");
        printf("\n1 - Tareas Pendientes");
        printf("\n2 - Tareas En Proceso");
        printf("\n3 - Tareas Realizadas");
        scanf("%d",&mostrar);

        switch (mostrar)
        {
        case 1:
            mostrarTareas(pendientes);
            break;
        case 2:
            mostrarTareas(enproceso);
            break;
        case 3:
            mostrarTareas(realizadas);
            break;
        default:
            break;
        }

        break;
    case 2:
        printf("\ningrese que tarea desea eliminar y su id: ");
        printf("\n1 - Tareas Pendientes");
        printf("\n2 - Tareas En Proceso");
        printf("\n3 - Tareas Realizadas");
        scanf("%d",&eliminar);
        printf("\nid: ");
        scanf("%d",&ideliminar);
        switch (eliminar)
        {
        case 1:
            nodoquitado = quitarTarea(&pendientes, ideliminar);
            insertarTarea(&tareaseliminadas, nodoquitado->t);
            break;
        case 2:
            nodoquitado = quitarTarea(&realizadas, ideliminar);
            insertarTarea(&tareaseliminadas, nodoquitado->t);
            break;
        case 3:
            nodoquitado = quitarTarea(&enproceso, ideliminar);
            insertarTarea(&tareaseliminadas, nodoquitado->t);
            break;
        
        default:
            break;
        }
    
    default:
        break;
    }



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

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            printf("\nTarea %d", aux->t->tareaID);
            printf("\nDescripcion: %s", aux->t->descripcion);
            printf("\nDuracion: %d", aux->t->duracion);
            printf("\n");

            aux = aux->siguiente;
        }
    } else
    {
        printf("\nLa lista de tareas esta vacia");
    }
    
}

void mostrarDatos(nodo ** start)
{
    nodo *aux;
    aux = *start;
    int totalduracion = 0;
    int totaltareas = 0;

    while (aux != NULL)
    {
        totaltareas++;
        totalduracion += aux->t->duracion;

        aux = aux->siguiente;   
    }

    printf("\nTotal de tareas: %d", totaltareas);
    printf("\nDuracion total de tareas: %d", totalduracion);
}

//quitar nodo
nodo * quitarTarea(nodo ** start, int id)
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
    }
    
    return aux;
}


//eliminar nodo
/*void * eliminarTarea(nodo ** start, int id)
{
    //free(nodoeliminar->t->descripcion);
    nodo * nodoeliminar = (nodo*)malloc(sizeof(nodo)); 
    nodoeliminar = quitarTarea(start, id);
    free(nodoeliminar->t);
    free(nodoeliminar);
    
}*/


//busco con id
tarea * buscarTareaID(nodo * start, int id)
{
    nodo *aux = start;
    tarea *buscado = NULL;
    
    while (aux->siguiente != NULL)
    {
        if (aux->t->tareaID == id)
        {
            buscado = aux->t;
            break;
        }
        aux = aux->siguiente;
    }
    
    return buscado;
}

//busco con palabra
tarea * buscarTareaPalabra(nodo * start, char palabra[])
{
    nodo *aux = start;
    tarea *buscado = NULL;

    while (aux->siguiente != NULL)
    {
        if (strstr(aux->t->descripcion, palabra) != NULL)
        {
            buscado = aux->t;
            break;
        }
    
        aux = aux->siguiente;
    }
}
