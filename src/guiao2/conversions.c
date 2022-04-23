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
    else if (d.tipo == DOUBLE) 
    {
        double *b = d.dados;
        double n = *b;
        push_double(s, n);
    }
    else if (d.tipo == STRING)
    {
        char *b = d.dados;
        double n;
        sscanf(b, "%lf", &n);
        push_double(s, n);
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
        long n;
        sscanf(b, "%ld", &n);
        push_long(s, n);
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
        long *a = d.dados;
        char n = *a;
        
        push_char(s, n);
    }
    else if (d.tipo == DOUBLE)
    {
        double *b = d.dados;
        char n = *b;
        push_char(s, n);
    }
    else if (d.tipo == CHAR)
    {
        char *a = d.dados;
        char n = *a;
        
        push_char(s, n);
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
        long *num = (long*)d.dados;
        sprintf(result, "%ld", *num);
        push_string(s, result);
    }
    else if (d.tipo == DOUBLE)
    {
        char result[BUFSIZ];
        double *num = (double*)d.dados;
        sprintf(result, "%lf", *num);
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
