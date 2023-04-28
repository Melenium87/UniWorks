#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Numero_y_bombax.h"
#define MAX 80

int main()
{
    int *je;
    je = Numero_y_bomba();
}

// FUNCIONES
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

void Num_y_bom(int numero, int bomba, int *indice, int arr[], int *flag)
{

    if ((numero / bomba) <= bomba)
    {
        arr[*indice] = (numero / bomba);

        if (*indice + 1 == 80)
            *flag = 1;

        else
            *indice = *indice + 1;
    }
    else
    {
        Num_y_bom(numero / bomba, bomba, indice, arr, flag);
    }

    if ((numero - (numero / bomba)) <= bomba)
    {
        arr[*indice] = (numero - (numero / bomba));
        if (*indice + 1 == 80)
            *flag = 1;

        else
            *indice = *indice + 1;
    }
    else
    {
        Num_y_bom((numero - (numero / bomba)), bomba, indice, arr, flag);
    }
}

int *Numero_y_bomba()
{
    char num[100];
    char bomb[100];
    int i = 0;
    static int array[80];
    int verificacion;
    int verificacion2;
    int bandera;

    printf("\t--Secuencia de la bomba--\nLos requisitos son:\n\t El numero debe ser MAYOR a 2\n\t La bomba debe ser MAYOR a 1\n\t Solo se permiten numeros NATURALES\n\t NO se permiten espacios ni signos\n\t El numero tiene que ser mayor a la Bomba\n\n");
    fflush(stdin);
    printf("Elija un numero: \n");
    fgets(num, 100, stdin);
    verificacion = validarnumero(num);
    while (atoi(num) < 3 || verificacion == -1)
    {
        system("cls");
        printf("\tVALORES INCORRECTOS\n\tVuelva a intentarlo\n\nLos requisitos son:\n\t El numero debe ser MAYOR a 2\n\t La bomba debe ser MAYOR a 1\n\t Solo se permiten numeros NATURALES\n\t NO se permiten espacios ni signos\n\t El numero tiene que ser mayor a la Bomba\n\n");
        fflush(stdin);
        printf("Elija un numero: \n");
        fgets(num, 100, stdin);
        verificacion = validarnumero(num);
        fflush(stdin);
    }

    fflush(stdin);
    printf("Elija una bomba: \n");
    fgets(bomb, 100, stdin);
    verificacion2 = validarnumero(bomb);

    while (atoi(num) < atoi(bomb) || atoi(bomb) < 2 || verificacion2 == -1)
    {
        system("cls");
        printf("\tVALORES INCORRECTOS\n\tVuelva a intentarlo\n\nLos requisitos son:\n\t El numero debe ser MAYOR a 2\n\t La bomba debe ser MAYOR a 1\n\t Solo se permiten numeros NATURALES\n\t NO se permiten espacios ni signos\n\t El numero tiene que ser mayor a la Bomba\n\n");
        fflush(stdin);
        printf("Elija una bomba: \n");
        fgets(bomb, 100, stdin);
        verificacion2 = validarnumero(bomb);
        fflush(stdin);
    }

    Num_y_bom(atoi(num), atoi(bomb), &i, array, &bandera);
    i--;
    if (bandera == 1)
    {
        printf("El array no tiene capacidad para almacenar tantos numeros");
    }
    else
    {
        printf("\n {");
        for (int x = 0; x < i; x++)
        {
            printf("%i;", array[x]);
        }
        printf("%i", array[i]);
        printf("}");
    }
    return array;
}
