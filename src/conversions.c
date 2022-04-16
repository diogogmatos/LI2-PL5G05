/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"

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
}
