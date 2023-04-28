#include "validaciones.h"

void borrarEspacios(char string[])
{ // borra todos los espacios del string
    int contadorSinEspacio = 0;
    for (int i = 0; string[i]; i++)
    {
        if (string[i] != ' ' && string[i] != '\n')
        {
            string[contadorSinEspacio++] = string[i];
        }
    }
    if (contadorSinEspacio != 0)
    {
        string[contadorSinEspacio] = '\0';
    }
    else
        return;
}

bool validacion(char string[])
{ // comprueba si el string es un número válido
    for (int i = 0; i < strlen(string); i++)
    {
        if ((isdigit(string[i]) == 0))
        {
            if ((string[i] == '-' && i != 0) || (string[i] != '-'))
            {
                return false;
            }
        }
    }
    return true;
}

bool validacion_enteros_decimales(char string[])
{ // comprueba si el string es un entero,decimal,negativo. Sino invalida
    int contador_puntos = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if ((isdigit(string[i]) == 0))
        {
            if ((string[i] == '-' && (i != 0 || strlen(string) == 1)) || ((string[i] != '-') && (string[i] != '.')) || (string[i] == '.' && i == 0))
            {
                return false;
            }
            if (string[i] == '.')
            {
                contador_puntos++;
            }
            if (contador_puntos > 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool validacion_enterosNegativos(char numero[])
{
    bool val = true;
    if (strlen(numero) > 100)
    {
        val = false;
        return val;
    }

    for (unsigned int i = 0; i < strlen(numero) - 1; i++)
    {
        if (i == 0 && numero[0] == '-')
        {
            continue;
        }

        if (isdigit(numero[i]) == false)
        {
            val = false;
            return val;
        }
    }
    if (val == true && (atoi(numero) > 999999999 || atoi(numero) < -999999999))
    {
        return false;
    }

    return true;
}