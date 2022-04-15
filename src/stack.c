/**
 * @file stack.c
 * @brief Funções básicas para o funcionamento da stack.
 */

#include <stdlib.h>
#include "stack.h"

/**
 * @brief Aloca espaço na memória *heap* atribuindo um endereço ao pointer __s__ e iniciando o stack pointer (__s->sp__) a 0.
 */
STACK *new_stack()
{
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    return s;
}

/**
 * @brief Introduz um novo elemento na stack incrementando um valor ao stack pointer (__s->sp__) e introduz na stack o elemento (__elem__).
 * 
 * @param s Stack
 * @param elem Elemento a introduzir na stack
 */
void push(STACK* s, long elem)
{
    long *elemP = malloc(sizeof(long));
    *elemP = elem;
    
    DADOS d = {LONG, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

void push_char(STACK* s, char elem)
{
    char *elemP = malloc(sizeof(long));
    *elemP = elem;
    
    DADOS d = {CHAR, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

/**
 * @brief Retorna o elemento que está na posição atual do stack pointer (__s->sp__) e decrementa o stack pointer.
 * 
 * @param s Stack
 * @return __d.dados__ - Elemento que se encontra na posição atual do stack pointer
 */
DADOS pop(STACK* s)
{
    DADOS d = s->stack[s->sp];
    s->sp--;

    return d;
}
