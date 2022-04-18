/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"
#include <stdio.h>

void conv_double(STACK *s) // ! - Falta adicionar caso em que d.tipo é STRING e DOUBLE
{
    DADOS d = pop(s);

    if (d.tipo == LONG)
    {
        long *a = d.dados;
        double n = *a;
        
        push_double(s, n);
    }
    else if (d.tipo == CHAR)
    {
        char *b = d.dados;
        double n = *b;
        push_double(s, n);
    }
}

void conv_int(STACK *s) // ! - Falta adicionar caso em que d.tipo é STRING
{
    DADOS d = pop(s);
    
    if (d.tipo == LONG)
    {
        long *a = d.dados;
        long n = *a;
        push_long(s, n);
    }
    else if (d.tipo == CHAR)
    {
        char *b = d.dados;
        long n = *b;
        push_long(s, n);
    }
    else if (d.tipo == DOUBLE)
    {
        double *b = d.dados;
        long n = *b;
        push_long(s, n);
    }
    else if (d.tipo == STRING)
    {
        char *b = d.dados;
        long r = 0;
        for (int i=0; b[i] != '\0'; i++)
        {
            if (b[i] >= 48 && b[i] <= 57)
            {
                r = r * 10 + (b[i] - 48);
            }
            else if (b[i] > 57 && b[i] <= 99)
            {
                r = r * 100 + b[i];
            }
            else if (b[i] > 99 && b[i] <= 122)
            {
                r = r * 1000 + b[i];
            }
        }
        push_long(s, r);
    }
}
