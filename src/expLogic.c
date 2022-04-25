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
    DADOS x = pop(s);
    DADOS y = pop(s);

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long *a = x.dados;
        long *b = y.dados;

        if (*b == *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long *ai = x.dados;
        double a = *ai;
        double *b = y.dados;
        
        if (*b == a)
            push_long(s, 1);
        else
            push_long(s, 0);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double *a = x.dados;
        long *bi = y.dados;
        double b = *bi;
        
        if (b == *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double *a = x.dados;
        double *b = y.dados;
        
        if (*b == *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }

    free(x.dados);
    free(y.dados);
}

/**
 * @brief Verifica se o elemento do topo da stack é maior que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void smaller(STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    if (x.tipo == LONG && y.tipo == LONG)
    {
        long *a = x.dados;
        long *b = y.dados;

        if (*b < *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }
    else if (x.tipo == LONG && y.tipo == DOUBLE)
    {
        long *ai = x.dados;
        double a = *ai;
        double *b = y.dados;
        
        if (*b < a)
            push_long(s, 1);
        else
            push_long(s, 0);        
    }
    else if (x.tipo == DOUBLE && y.tipo == LONG)
    {
        double *a = x.dados;
        long *bi = y.dados;
        double b = *bi;
        
        if (b < *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }
    else if (x.tipo == DOUBLE && y.tipo == DOUBLE)
    {
        double *a = x.dados;
        double *b = y.dados;
        
        if (*b < *a)
            push_long(s, 1);
        else
            push_long(s, 0);
    }

    free(x.dados);
    free(y.dados);
}

/**
 * @brief Verifica se o elemento do topo da stack é menor que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void bigger(STACK *s)
{
    DADOS x = pop(s);
    long *a = x.dados;

    DADOS y = pop(s);
    long *b = y.dados;

    if (*b > *a)
        push_long(s,1);
    else
        push_long(s,0);

    free (x.dados);
    free (y.dados);
}

/**
 * @brief Inverte o valor lógico do elemento no topo da stack, ou seja, se este for igual a 0 passa a ser 1 e caso contrário passa a ser 0.
 * 
 * @param s Stack.
 */
void lnot(STACK *s)
{
    DADOS x = pop(s);
    long *a = x.dados;

    if (*a == 0)
        push_long(s,1);
    else
        push_long(s,0);

    free(x.dados);
}

/**
 * @brief Faz a conjunção lógica dos 2 valores no topo da stack, ou seja, se um ou mais destes elementos for 0 dá push a 0 caso contrário dá push ao elemento do topo.
 * 
 * @param s Stack.
 */
void and(STACK *s)
{
    DADOS x = pop(s);
    long *a = x.dados;

    DADOS y = pop(s);
    long *b = y.dados;

    if (*a != 0 && *b != 0)
        push(s,x);
    else
        push_long(s,0);
}

/**
 * @brief Compara os 2 valores do topo da stack, deixando nesta somente o de maior grandeza;
 * 
 * @param s Stack.
 */
void maior2 (STACK *s)
{
    DADOS x = pop(s);
    long *a = x.dados;

    DADOS y = pop(s);
    long *b = y.dados;

    if (*b > *a)
        push(s,y);
    else
        push(s,x);

    free (x.dados);
    free (y.dados);
}

/**
 * @brief Compara os 2 valores do topo da stack, deixando nesta somente o de menor grandeza;
 * 
 * @param s Stack.
 */
void menor2 (STACK *s)
{
    DADOS x = pop(s);
    long *a = x.dados;

    DADOS y = pop(s);
    long *b = y.dados;

    if (*b > *a)
        push(s,x);
    else
        push(s,y);

    free (x.dados);
    free (y.dados);
}

void or (STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);
    long *a = x.dados;
    long *b = y.dados;

    if (*a == 0 && *b == 0)
        push_long(s, 0);
    else
        push_long(s, 1);
    
    free(x.dados);
    free(y.dados);
}

void if_else (STACK* s)
{
    DADOS else_this = pop(s);
    DADOS then_this = pop(s);
    DADOS if_this = pop(s);

    long *a = if_this.dados;
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
