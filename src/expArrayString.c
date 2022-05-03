/**
 * @file expArrayString.c
 * @brief Operações com Arrays e Strings.
 */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void div_newline(STACK *s)
{
    char *a = pop(s).dados;
    char *token;
    STACK *r;
    
    token = strtok(a, "\n");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, "\n");
    }

    //push_array(s, r);

    free(a);
}

void range(STACK *s)
{
    DADOS x = pop(s);
    
    if (x.tipo == LONG)
    {
        double *a = x.dados;
        STACK *r;

        while (*a > 0)
        {
            push_long(r, (*a)-1);
            (*a)--;
        }

        //push_array(s, r);
    }
    else if (x.tipo == ARRAY)
    {
        STACK *a = x.dados;
        double r = a->sp;

        push_long(s, r);
    }

    free(x.dados);
}
