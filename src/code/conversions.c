/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Converte um elemento para DOUBLE.
 * 
 * @param s Stack.
 */
void conv_double(STACK *s)
{
    DADOS d = pop(s);

    if (d.tipo == LONG || d.tipo == DOUBLE)
    {
        double *a = d.dados;

        push_double(s, *a);
    }
    else if (d.tipo == CHAR)
    {
        char *a = d.dados;

        double r = *a;
        push_double(s, r);
    }
    else if (d.tipo == STRING)
    {
        char *a = d.dados;

        double r;
        sscanf(a, "%lf", &r);
        push_double(s, r);
    }

    free(d.dados);
}

/**
 * @brief Converte um elemento para inteiro (LONG).
 * 
 * @param s Stack.
 */
void conv_int(STACK *s)
{
    DADOS d = pop(s);
    
    if (d.tipo == LONG)
    {
        double *a = d.dados;

        push_long(s, *a);
    }
    else if (d.tipo == CHAR)
    {
        char *a = d.dados;
        long ri = *a;

        double r = ri;
        push_long(s, r);
    }
    else if (d.tipo == DOUBLE)
    {
        double *a = d.dados;
        long ri = *a;

        double r = ri;
        push_long(s, r);
    }
    else if (d.tipo == STRING)
    {
        char *a = d.dados;
        long ri;
        sscanf(a, "%ld", &ri);

        double r = ri;
        push_long(s, r);
    }
    
    free(d.dados);
}

/**
 * @brief Converte um elemento para CHAR.
 * 
 * @param s Stack.
 */
void conv_char(STACK *s)
{
    DADOS d = pop(s);

    if (d.tipo == LONG)
    {
        double *ai = d.dados;
        long a = *ai;
        
        char r = a;
        push_char(s, r);
    }
    else if (d.tipo == DOUBLE)
    {
        double *a = d.dados;

        char r = *a;
        push_char(s, r);
    }
    else if (d.tipo == CHAR)
    {
        push(s, d);
    }

    free(d.dados);
}

/**
 * @brief Converte um elemento para STRING.
 * 
 * @param s Stack.
 */
void conv_string(STACK *s)
{
    DADOS d = pop(s);

    if (d.tipo == LONG)
    {
        char result[BUFSIZ];
        double *ai = (double*)d.dados;

        long a = *ai;
        sprintf(result, "%ld", a);
        push_string(s, result);
    }
    else if (d.tipo == DOUBLE)
    {
        char result[BUFSIZ];
        double *a = (double*)d.dados;

        sprintf(result, "%lf", *a);
        push_string(s, result);
    }
    else if (d.tipo == CHAR)
    {
        char result[BUFSIZ];
        char *l = (char*)d.dados;
        
        result[0] = *l;
        result[1] = '\0';
        push_string(s, result);
    }
    else if (d.tipo == STRING)
    {
        char *str = (char*)d.dados;
        push_string(s, str);
    }

    free(d.dados);
}
