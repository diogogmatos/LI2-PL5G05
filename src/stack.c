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

// Funções push()

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

    char *elemP = malloc(sizeof(long));
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
