/**
 * @file expLogic.c
 * @brief Operações de lógica.
 * 
 * - __Nota:__ Todas as funções em expLogic.c incluem uma libertação de memória (ex: `free(x.dados)`) uma vez que acedemos a um elemento da stack com
 * a função `pop()` para o qual foi alocada memória dinâmica que já não será usada.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Verifica se dois elementos da stack são iguais, retornando 1 caso sejam e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void equal(STACK *s)
{
    double *a = pop(s).dados;
    double *b = pop(s).dados;

    if (*b == *a)
        push_long(s, 1);
    else
        push_long(s, 0);

    free(a);
    free(b);
}

/**
 * @brief Verifica se o elemento do topo da stack é maior que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void is_smaller(STACK *s)
{
    double *a = pop(s).dados;
    double *b = pop(s).dados;

    if (*b < *a)
        push_long(s, 1);
    else
        push_long(s, 0);

    free(a);
    free(b);
}

/**
 * @brief Verifica se o elemento do topo da stack é menor que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void is_bigger(STACK *s)
{
    double *a = pop(s).dados;
    double *b = pop(s).dados;

    if (*b > *a)
        push_long(s, 1);
    else
        push_long(s, 0);

    free(a);
    free(b);
}

/**
 * @brief Inverte o valor lógico do elemento no topo da stack, ou seja, se este for igual a 0 passa a ser 1 e caso contrário passa a ser 0.
 * 
 * @param s Stack.
 */
void lnot(STACK *s)
{
    double *a = pop(s).dados;

    if (*a == 0)
        push_long(s, 1);
    else
        push_long(s, 0);

    free(a);
}

/**
 * @brief Faz a conjunção lógica dos 2 valores no topo da stack, ou seja, se um ou mais destes elementos for 0 dá push a 0 caso contrário dá push ao elemento do topo.
 * 
 * @param s Stack.
 */
void and(STACK *s)
{
    DADOS x = pop(s);

    double *a = x.dados;
    double *b = pop(s).dados;

    if (*a != 0 && *b != 0)
        push(s, x);
    else
        push_long(s, 0);

    free(a);
    free(b);
}

/**
 * @brief Compara os 2 valores do topo da stack, deixando nesta somente o de maior grandeza;
 * 
 * @param s Stack.
 */
void bigger (STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    double *a = x.dados;
    double *b = y.dados;

    if (*b > *a)
        push(s, y);
    else
        push(s, x);
    
    free (x.dados);
    free (y.dados);
}

/**
 * @brief Compara os 2 valores do topo da stack, deixando nesta somente o de menor grandeza;
 * 
 * @param s Stack.
 */
void smaller (STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    double *a = x.dados;
    double *b = y.dados;

    if (*b < *a)
        push(s, y);
    else
        push(s, x);
    
    free (x.dados);
    free (y.dados);
}

void or (STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    double *a = x.dados;
    double *b = y.dados;

    if (*a == 0 && *b == 0)
        push_long(s, 0);
    else if (*b == 0)
        push(s, x);
    else
        push(s, y);
    
    free(a);
    free(b);
}

void if_else (STACK* s)
{
    DADOS else_this = pop(s);
    DADOS then_this = pop(s);
    DADOS if_this = pop(s);

    double *a = if_this.dados;
    if (*a != 0)
    {
        push(s, then_this);
        free(if_this.dados);
        free(else_this.dados);
    }
    else
    {
        push(s, else_this);
        free(if_this.dados);
        free(then_this.dados);
    }
}
