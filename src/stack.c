/**
 * @file stack.c
 * @brief Funções básicas para o funcionamento da stack.
 */

#include <stdlib.h>
#include "stack.h"

<<<<<<< HEAD
///aloca espaço na memória heap atribuindo um endereço ao pointer s e iniciando o stack pointer a 0
=======
/**
 * @brief Aloca espaço na memória *heap* atribuindo um endereço ao pointer __s__ e iniciando o stack pointer (__s->sp__) a 0.
 */
>>>>>>> main
STACK *new_stack()
{
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    return s;
}

<<<<<<< HEAD
///introduz um novo elemento na stack incrementando um valor ao stack pointer e introduz na stack o elem
=======
/**
 * @brief Introduz um novo elemento na stack incrementando um valor ao stack pointer (__s->sp__) e introduz na stack o elemento (__elem__).
 * 
 * @param s Stack
 * @param elem Elemento a introduzir na stack
 */
>>>>>>> main
void push(STACK* s, long elem)
{
    long *elemP = malloc(sizeof(long));
    *elemP = elem;
    
    DADOS d = {LONG, elemP};
    s->sp++;
    s->stack[s->sp] = d;
}

<<<<<<< HEAD

///dá return do elemento que está na posição atual do stack pointer e decrementa o stack pointer
=======
/**
 * @brief Retorna o elemento que está na posição atual do stack pointer (__s->sp__) e decrementa o stack pointer.
 * 
 * @param s Stack
 * @return __d.dados__ - Elemento que se encontra na posição atual do stack pointer
 */
>>>>>>> main
void* pop(STACK* s)
{
    DADOS d = s->stack[s->sp];
    s->sp--;

    return (d.dados);
}
