#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H
#include <stdio.h>
#include <stdlib.h>

struct TipoElementoRep {
    int clave;
    void* valor;
};
typedef struct TipoElementoRep *TipoElemento;

TipoElemento te_crear(int clave);
TipoElemento te_crear_con_valor(int clave, void* valor);

#endif // TIPO_ELEMENTO_H


