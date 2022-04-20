/**
 * @file stack.c
 * @brief Funções básicas para o funcionamento da stack.
 */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Declaração de nova stack

/**
 * @brief Aloca espaço na memória *heap* atribuindo um endereço ao pointer __s__ e iniciando o stack pointer (__s->sp__) a 0.
 */
STACK *new_stack()
{
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    return s;
}

// Funções de push

/**
 * @brief Introduz um elemento do tipo LONG na stack, incrementando um valor ao stack pointer (__s->sp__).
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_long(STACK* s, long elem)
{
    long *elemP = malloc(sizeof(long));
    *elemP = elem;
    
    DADOS d = {LONG, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo DOUBLE na stack, incrementando um valor ao stack pointer (__s->sp__).
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_double(STACK *s, double elem)
{
    double *elemP = malloc(sizeof(double));
    *elemP = elem;

    DADOS d = {DOUBLE, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo CHAR na stack, incrementando um valor ao stack pointer (__s->sp__).
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_char(STACK* s, char elem)
{

    char *elemP = malloc(sizeof(char));
    *elemP = elem;
    
    DADOS d = {CHAR, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento do tipo STRING na stack, incrementando um valor ao stack pointer (__s->sp__).
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push_string(STACK *s, char elem[])
{   int i;
    char *str = malloc(sizeof(char) * 50);
    for (i = 0; *(elem + i) != 0; ++i)
    {
        *(str+i) = *(elem + i);
    }
    *(str+i) = '\0';
    
    DADOS d = {STRING, str}; // Seria 'DADOS d = {STRING, elemP};' com o código acima.
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Introduz um elemento na stack, direcionando para a função push correspondente de acordo com o tipo.
 * 
 * @param s Stack.
 * @param elem Elemento a introduzir na stack.
 */
void push(STACK* s, DADOS elem)
{
    if (elem.tipo == LONG)
    {
        long *n = elem.dados;
        push_long(s, *n);
    }
    else if (elem.tipo == DOUBLE)
    {
        double *n = elem.dados;
        push_double(s, *n);
    }
    else if (elem.tipo == CHAR)
    {
        char *n = elem.dados;
        push_char(s, *n);
    }
    else if (elem.tipo == STRING)
    {
        char *n = elem.dados;
        push_string(s, n);
    }
}

// Função pop()

/**
 * @brief Retorna o elemento que está na posição atual do stack pointer (__s->sp__) e decrementa o stack pointer.
 * 
 * @param s Stack.
 * @return __d.dados__ - Elemento que se encontra na posição atual do stack pointer.
 */
DADOS pop(STACK* s)
{
    DADOS d = s->stack[s->sp];
    s->sp--;

    return d;
}
