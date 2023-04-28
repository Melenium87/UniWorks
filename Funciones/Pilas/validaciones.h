#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void borrarEspacios(char string[]);

bool validacion(char string[]);

bool validacion_enteros_decimales(char string[]); // comprueba si el string es un entero,decimal,negativo. Sino invalida

/*
Permite unicamente numeros enteros sean o no negativos
(El signo "-" debe estar al INICIO del string y RETORNA un booleano)
*/

bool validacion_enterosNegativos(char numero[]);