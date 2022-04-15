/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"

/*
void convDouble(STACK *s)
{
    double n = s->stack[s->sp]; 
    s->stack[s->sp] = n;
}
*/

void conv_int(STACK *s)
{
    DADOS d = pop(s);
    
    if (d.tipo == LONG)
    {
        long *a = d.dados;
        long n = *a;
        push(s, n);
    }
    
    if (d.tipo == CHAR)
    {
        char *b = d.dados;
        long n = *b;
        push(s, n);
    }
}
