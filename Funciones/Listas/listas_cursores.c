#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

static const int TAMANIO_MAXIMO = 100;
static const int NULO = -1;

struct Nodo
{
    TipoElemento datos;
    int siguiente; // Cambia el apuntador por un “int”
};

struct ListaRep
{
    struct Nodo *cursor; // Apuntador al Arreglo de Nodos
    int inicio;
    int libre; // Contendrá los nodos libres o disponibles
    int cantidad;
};

struct IteradorRep
{
    Lista lista;
    int posicionActual;
};

Lista l_crear()
{
    Lista nueva_lista = (Lista)malloc(sizeof(struct ListaRep));
    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;
    // Encadeno todos los libres
    for (int i = 0; i < TAMANIO_MAXIMO - 2; i++)
    {
        nueva_lista->cursor[i].siguiente = i + 1;
    }
    nueva_lista->libre = 0; // Toma todos los nodos como libres
    nueva_lista->inicio = NULO;
    nueva_lista->cursor[TAMANIO_MAXIMO - 1].siguiente = NULO;
    // retorno la lista creada
    return nueva_lista;
}

bool l_es_vacia(Lista lista)
{
    return lista->inicio == NULO;
}

bool l_es_llena(Lista lista)
{
    return lista->libre == NULO;
}

int l_longitud(Lista lista)
{
    return lista->cantidad;
}

void l_agregar(Lista lista, TipoElemento elemento)
{
    if (l_es_llena(lista))
    {
        return;
    } // Controlo la lista llena
    int p;
    p = lista->libre; // Tomo el primer libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento; // Asigno el dato
    lista->cursor[p].siguiente = NULO;
    // Controlo que no sea el primero de la lista
    if (lista->inicio == NULO)
    {
        lista->inicio = p;
    }
    else
    {
        // lo ubico al final
        int q = lista->inicio;
        while (lista->cursor[q].siguiente != NULO)
        {
            q = lista->cursor[q].siguiente;
        }
        lista->cursor[q].siguiente = p; // Lo conecto con el ultimo
    }
    lista->cantidad++;
}

void l_borrar(Lista lista, int clave)
{
    if (l_es_vacia(lista))
    {
        return;
    } // Controlo la lista vacia
    int q;
    int p = lista->inicio;
    // borro las claves que coinciden con el inicio
    while ((p != NULO) && (lista->cursor[p].datos->clave == clave))
    {
        q = p;
        lista->inicio = lista->cursor[p].siguiente;
        // recupero el nodo en el libre para no perderlo
        lista->cursor[q].siguiente = lista->libre;
        lista->libre = q;
        // Descuento 1 y arranco de nuevo desde el inicio
        lista->cantidad--;
        p = lista->inicio; // Vuelvo a intentar desde el inicio
    }
    // Borro las claves en el resto de la lista
    p = lista->inicio;
    while ((p != NULO) && (lista->cursor[p].siguiente != NULO))
    {
        // Si la clave del siguiente nodo es igual, lo borro
        if (lista->cursor[lista->cursor[p].siguiente].datos->clave == clave)
        {
            q = lista->cursor[p].siguiente;
            lista->cursor[p].siguiente = lista->cursor[q].siguiente;
            // recupero el nodo en el libre para no perderlo
            lista->cursor[q].siguiente = lista->libre;
            lista->libre = q;
            // Descuento 1
            lista->cantidad--;
        }
        else
        {
            p = lista->cursor[p].siguiente;
        }
    }
}

TipoElemento l_buscar(Lista lista, int clave)
{
    Lista lr = lista;
    int i = lr->inicio;
    while (i != NULO)
    {
        TipoElemento elemento = lr->cursor[i].datos;
        if (elemento->clave == clave)
        {
            return elemento;
        }
        i = lr->cursor[i].siguiente;
    }
    return NULL;
}

void l_insertar(Lista lista, TipoElemento elemento, int pos)
{
    if (l_es_llena(lista))
    {
        return;
    }                     // Control de lista llena
    int p = lista->libre; // Toma la primer posición libre
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;
    // Controla si cambia el INICIO
    if (pos == 1)
    {
        lista->cursor[p].siguiente = lista->inicio;
        lista->inicio = p;
    }
    else
    {
        int temp = lista->inicio; // Busca la posición del resto de la lista
        for (int i = 0; i < pos - 2; i++)
        {
            temp = lista->cursor[temp].siguiente;
        }
        lista->cursor[p].siguiente = lista->cursor[temp].siguiente;
        lista->cursor[temp].siguiente = p;
    }
    lista->cantidad++;
}

void l_eliminar(Lista lista, int pos)
{
    if (l_es_vacia(lista))
    {
        return;
    }
    int p;
    int actual = lista->inicio;
    if (1 <= pos && pos <= l_longitud(lista))
    {
        if (pos == 1)
        { // borra la primer posicion hay que cambiar el Inicio
            p = actual;
            lista->inicio = lista->cursor[actual].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        else
        {
            for (int i = 0; i < pos - 2; i++)
            {
                actual = lista->cursor[actual].siguiente;
            }                                                             // actual apunta al nodo en posición (pos - 1)
            p = lista->cursor[actual].siguiente;                          // nodo en pos
            lista->cursor[actual].siguiente = lista->cursor[p].siguiente; // nodo en pos + 1
            lista->cursor[lista->libre].siguiente = p;
            lista->libre = p; // Devuelvo al libre el nodo que elimine (saque de la lista)
        }
        lista->cantidad--;
    }
}

TipoElemento l_recuperar(Lista lista, int pos)
{
    Lista lr = lista;
    if (pos < 1 || pos > lr->cantidad)
    {
        printf("Error: posición inválida\n");
        return NULL;
    }

    int i = lr->inicio;
    int j = 1;
    while (j < pos)
    {
        i = lr->cursor[i].siguiente;
        j++;
    }

    return lr->cursor[i].datos;
}

void l_mostrarLista(Lista lista)
{
    Lista lr = lista;
    int i = lr->inicio;
    printf("[ ");
    while (i != NULO)
    {
        TipoElemento elemento = lr->cursor[i].datos;
        printf("%d", elemento->clave);
        if (lr->cursor[i].siguiente != NULO)
        {
            printf(", ");
        }
        i = lr->cursor[i].siguiente;
    }
    printf(" ]\n");
}

// Funciones de iterador de la lista

Iterador iterador(Lista lista){
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista=lista;
    iter->posicionActual = lista->inicio;
    return iter;
}

bool hay_siguiente(Iterador iter){
    return (iter->posicionActual != NULO);
}

TipoElemento siguiente(Iterador iter){
    TipoElemento elemento = iter->lista->cursor[iter->posicionActual].datos;
    iter->posicionActual = iter->lista->cursor[iter->posicionActual].siguiente;
    return elemento;
}
