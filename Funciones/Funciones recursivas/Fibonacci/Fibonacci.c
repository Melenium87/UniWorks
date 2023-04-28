#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fibo.h"

int validarnumero(char *numero_captado)
{
    if (isdigit(numero_captado[0]) == 0)
    {
        return -1;
    }
    for (unsigned int i = 0; i < strlen(numero_captado) - 1; i++)
    {
        if (isdigit(numero_captado[i]) == 0)
        {
            return -1;
        }
    }
    return 0;
}
int Fibonacci_sequence(int numero)
{
    if (numero == 1)
    {
        return 1;
    }
    else
    {
        if (numero == 0)
        {
            return 0;
        }

        return (Fibonacci_sequence(numero - 1) + Fibonacci_sequence(numero - 2));
    }
}

int Fibonacci()
{
    int resultado;
    int numero;
    char numero_captado[100];
    printf("Ingrese el valor que desea reemplazar en la sucesion de Fibonacci\n El valor debe ser:\n\t - Un numero NATURAL\n\t - Estar entre [1,40] \n\t - NO debe contener espacios\n\t - NO debe estar vacio\n");
    fflush(stdin);
    fgets(numero_captado, 100, stdin);
    numero = validarnumero(numero_captado);
    while (numero == -1 || atoi(numero_captado) < 1 || atoi(numero_captado) > 40)
    {
        printf("Dato invalido\n");
        fflush(stdin);
        printf("Ingrese el valor que desea reemplazar en la sucesion de Fibonacci\n El valor debe ser:\n\t - Un numero NATURAL\n\t - Estar entre [1,40] \n\t - NO debe contener espacios\n\t - NO debe estar vacio\n");
        fgets(numero_captado, 100, stdin);
        numero = validarnumero(numero_captado);
    }
    resultado = Fibonacci_sequence(atoi(numero_captado));
    return resultado;
}

int main()
{
    int result = Fibonacci();
    printf("%i", result);
    return 0;
}
