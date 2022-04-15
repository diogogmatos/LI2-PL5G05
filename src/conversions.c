/**
 * @file conversions.c
 * @brief Funções de conversão de tipos.
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void convLong(STACK *s)
{
    DADOS d = s->stack[s->sp];
    long item = *((long*)d.dados); //Casting do conteudo
    free(d.dados); //Limpa o endereço onde o pointer apontava 
    
    long* itemP = malloc(sizeof(long));
    *itemP = item;

    d.tipo = LONG;
    d.dados = itemP;
}

void convDouble(STACK *s)
{
    DADOS d = s->stack[s->sp];
    
    double item = *((double*)d.dados); //Casting do conteudo
    printf("%lf\n", item);
    free(d.dados); //Limpa o endereço onde o pointer apontava 
    
    double* itemP = malloc(sizeof(double));
    *itemP = item;

    d.tipo = DOUBLE;
    d.dados = itemP;
}

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
