#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea{
    int tareaID; // numerado en ciclo iterativo
    char *descripcion; 
    int duracion; // entre 10 - 100
}typedef tarea;


struct Nodo{
    tarea t;
    nodo *siguiente;
} typedef nodo;

nodo crearListaVacia();


int main(){

    nodo *pendientes;
    nodo *realizadas;
    nodo *tareas;
    
        

    return 0;
}