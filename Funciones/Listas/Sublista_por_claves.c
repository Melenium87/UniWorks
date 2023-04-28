#include <stdio.h>
#include "listas.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool verificacion(char numero[])
{

    for (unsigned int i = 0; i < strlen(numero) - 1; i++)
    {
        if (i == 0 && numero[0] == '-')
        {
            continue;
        }

        if (isdigit(numero[i]) == false)
        {

            return false;
        }
    }

    return true;
}
Lista crear_lista()
{
    Lista lista;
    printf("Crea una lista con las claves\n\n");
    char clave[50];
    char respuesta[40];
    lista = l_crear();
    TipoElemento elemento = te_crear(0);
    bool seguir = true;
    bool valorRepetido;
    bool val;

    printf("\nDesea algun valor?\n\n\t1. Si\n\t2. No\n");
    fflush(stdin);
    fgets(respuesta, 40, stdin);
    val = verificacion(respuesta);
    fflush(stdin);

    while (val == false || (atoi(respuesta) == 1 || atoi(respuesta) == 2) == false)
    {
        fflush(stdin);
        system("cls");
        printf("Valor invalido\n\n");
        printf("Desea agregar mas valores?\n\n\t1. Si\n\t2. No\n");
        fgets(respuesta, 40, stdin);
        printf("\n");

        val = verificacion(respuesta);
    }

    if (atoi(respuesta) == 1)
    {
        while (seguir == true)
        {

            printf("Ingresar clave para el valor que deseas agregar\n");
            printf("\n\tLas claves debe ser un numero ENTERO\n\tLas claves de la lista no pueden ser repetidas\n");
            fflush(stdin);
            fgets(clave, 50, stdin);

            val = verificacion(clave);

            if (l_buscar(lista, atoi(clave)) != NULL)
            {
                valorRepetido = true;
            }

            else
            {
                valorRepetido = false;
            }
            if (clave[0] == '\n')
            {
                val = false;
            }
            while (val == false || valorRepetido == true)
            {
                fflush(stdin);
                system("cls");
                printf("Valor incorrecto\n");
                printf("Ingresar clave para el valor que deseas agregar\n");
                printf("\n\tLas claves debe ser un numero ENTERO\n\tLas claves de la lista no pueden ser repetidas\n");
                fgets(clave, 50, stdin);
                val = verificacion(clave);
                if (l_buscar(lista, atoi(clave)) != NULL)
                {
                    valorRepetido = true;
                }

                else
                {
                    valorRepetido = false;
                }
                if (clave[0] == '\n')
                {
                    val = false;
                }
            }
            elemento = te_crear(atoi(clave));

            l_agregar(lista, elemento);
            system("cls");
            printf("Agregado correctamente\n");
            l_mostrarLista(lista);
            printf("\nDesea agregar mas valores?\n\n\t1. Si\n\t2. No\n");
            fflush(stdin);
            fgets(respuesta, 40, stdin);
            val = verificacion(respuesta);

            while (val == false || (atoi(respuesta) == 1 || atoi(respuesta) == 2) == false)
            {
                fflush(stdin);
                system("cls");
                printf("Valor invalido\n\n");
                printf("Desea agregar mas valores?\n\n\t1. Si\n\t2. No\n");
                fgets(respuesta, 40, stdin);
                printf("\n");

                val = verificacion(respuesta);
            }

            if (atoi(respuesta) == 1)
            {
                seguir = true;
            }
            else
            {
                seguir = false;
            }
        }
    }
    return lista;
}
void Sublistas(Lista lista, Lista listasub)
{
    TipoElemento elemento;
    TipoElemento encontrado;
    Iterador iter = iterador(listasub);
    bool bien = true;

    while (hay_siguiente(iter) && encontrado != NULL && l_es_vacia(listasub) == false)
    {
        if (l_es_vacia(lista) == true)
        {
            bien = false;
            break;
        }
        elemento = (siguiente(iter));
        encontrado = l_buscar(lista, elemento->clave);
        if (encontrado == NULL)
        {
            bien = false;
            break;
        }
    }
    system("cls");
    printf("--------------------------------\n\n");
    if (bien == false)
    {

        l_mostrarLista(listasub);
        printf("\nNO ES UNA SUBLISTA DEL :\n\n\t");
        l_mostrarLista(lista);
    }
    else
    {
        l_mostrarLista(listasub);
        printf("\nES UNA SUBLISTA DEL :\n\n\t");
        l_mostrarLista(lista);
    }
    printf("\n\n");
    printf("--------------------------------\n\n\n");

    iter = iterador(lista);
    bien = true;
    while (hay_siguiente(iter) && encontrado != NULL || l_es_vacia(lista) == false)
    {
        if (l_es_vacia(listasub) == true)
        {
            bien = false;
            break;
        }

        elemento = (siguiente(iter));
        encontrado = l_buscar(listasub, elemento->clave);
        if (encontrado == NULL)
        {
            bien = false;
            break;
        }
    }

    if (bien == false)
    {

        l_mostrarLista(lista);
        printf("\nNO ES UNA SUBLISTA DEL :\n\n\t");
        l_mostrarLista(listasub);
    }
    else
    {
        l_mostrarLista(lista);
        printf("\nES UNA SUBLISTA DEL :\n\n\t");
        l_mostrarLista(listasub);
    }
    printf("--------------------------------");
}

int main()
{
    fflush(stdin);
    Lista l1, l2;
    printf("\t----- Cree la primera lista -----\n\n");
    l1 = crear_lista();
    system("pause");
    system("cls");
    printf("\t----- Cree la segunda lista -----\n\n");
    l2 = crear_lista();
    system("pause");
    system("cls");

    Sublistas(l1, l2);

    printf("La complejidad algoritmica es de O(n^2)");
    /*
    n es el tamaño de la lista y m el tamaño de la sublista, 
    por lo que normalmente la complejidad seria O(n*m) pero el 
    peor caso es en el que ambas listas sean iguales
    y del tamaño maximo, por lo tanto O(n^2)
    */
    return 0;
}
