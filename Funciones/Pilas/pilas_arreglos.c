#include "pilas_arreglos.h"

#define MAX 100

struct PilaRep{
    TipoElemento*valores;
    int tope;
};

Pila p_crear(){
    Pila nueva_pila=(Pila)malloc(sizeof(struct PilaRep));
    nueva_pila->valores=calloc(MAX, sizeof(TipoElemento));
    nueva_pila->tope=0;
    return nueva_pila;
}

bool p_es_llena(Pila pila){
    return pila->tope==MAX;
} 

bool p_es_vacia(Pila pila){
    return pila->tope==0;
}

void p_apilar(Pila pila, TipoElemento elemento){
    if (p_es_llena(pila)==false){
        pila->valores[pila->tope]=elemento;
        pila->tope++;
    }
}

TipoElemento p_desapilar(Pila pila){
    if (p_es_vacia(pila)==false){
        pila->tope--;
        return pila->valores[pila->tope];
    }
}

TipoElemento p_tope(Pila pila){
    if (p_es_vacia(pila)){
        return NULL;
    }
    return pila->valores[pila->tope-1];
}

void p_mostrar(Pila pila){
    TipoElemento t1=te_crear(0);
    Pila paux=p_crear();

    if (p_es_vacia(pila)){
        printf("Pila vacia.\n");
        return;
    }
    
    printf("Contenido de la pila:\n");

    while (!p_es_vacia(pila)){
        t1=p_desapilar(pila);
        p_apilar(paux, t1);
        printf("%d ", t1->clave);
    }

    while (!p_es_vacia(paux)){
        t1=p_desapilar(paux);
        p_apilar(pila, t1);
    }
    printf("\n");
}
