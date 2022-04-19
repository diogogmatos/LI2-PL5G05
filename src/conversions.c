/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

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
    else if (d.tipo == DOUBLE) 
    {
        double *b = d.dados;
        double n = *b;
        push_double(s, n);
    }
    else if (d.tipo == STRING)
    {
        char *b = d.dados;
        double r = 0;
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
    free(d.dados);
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
    free(d.dados);
}

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

void conv_string(STACK *s)
{
    DADOS d = pop(s);

    if (d.tipo == LONG)
    {
        char result[100];
        long *num = (long*)d.dados;
        sprintf(result, "%ld", *num);
        push_string(s, result);
        free(d.dados);
    }
    else if (d.tipo == DOUBLE)
    {
        char result[100];
        double *num = (double*)d.dados;
        sprintf(result, "%lf", *num);
        push_string(s, result);
        free(d.dados);
    }
    else if (d.tipo == CHAR)
    {
        char result[100];
        char *l = (char*)d.dados;
        result[0] = *l;
        result[1] = '\0';
        push_string(s, result);
        free(d.dados);
    }
    else if (d.tipo == STRING)
    {
        char *str = (char*)d.dados;
        push_string(s, str);
    }
}

