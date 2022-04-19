/**
 * @file stack.c
 * @brief Neste ficheiro estão incluídas as funções básicas para o funcionamento da stack.
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
void push(STACK* s, int elem)
{
    s->sp++;
    s->stack[s->sp] = elem;
}

/**
 * @brief Retorna o elemento que está na posição atual do stack pointer (__s->sp__) e decrementa o stack pointer.
 * 
 * @param s Stack
 * @return __d.dados__ - Elemento que se encontra na posição atual do stack pointer
 */
int pop(STACK* s)
{
    int ret = s->stack[s->sp];
    s->sp--;
    return ret;
}
