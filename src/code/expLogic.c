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
#include <string.h>

/**
 * @brief Verifica se dois elementos da stack são iguais, retornando 1 caso sejam e 0 caso contrário (True ou False).
 * 
 * - __Nota:__ Caso o primeiro operando do input seja um ARRAY, a função `equal()` retira do mesmo o elemento que se encontra no
 * indíce fornecido pelo segundo operando e coloca-o na stack. 
 * 
 * @param s Stack.
 */
void equal(STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    if (y.tipo == ARRAY && x.tipo == LONG)
    {
        double *i = x.dados;
        long ind = *i;
        STACK *array = y.dados;

        push(s, array->stack[ind+1]);
        free(x.dados);
    }
    else if (y.tipo == STRING && x.tipo == LONG)
    {
        double *i = x.dados;
        long ind = *i;
        char* str = y.dados;

        push_char(s, *(str+ind));
        free(x.dados);
    }
    else
    {
        double *a = x.dados;
        double *b = y.dados;

        if (*b == *a)
            push_long(s, 1);
        else
            push_long(s, 0);

        free(x.dados);
        free(y.dados);
    }
}

/**
 * @brief Verifica se o elemento do topo da stack é maior que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void is_smaller(STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);
    
    char cx = type_to_char(x);
    char cy = type_to_char(y);

    switch (cx)
    {
        case 'S':
        {
            char *a = x.dados;
            char *b = y.dados;

            if (strcmp (b, a) > 0)
                push_long(s, 0);
            else
                push_long(s, 1);

            return;
        }
        case 'L':
        {
            switch (cy)
            {
                case 'A':
                {
                    double *ii = x.dados;
                    int i = *ii;
                    STACK *array = y.dados;

                    STACK *r = new_stack();
                    
                    for (int j = 1; j <= i; j++)
                        push(r, array->stack[j]);

                    push_array(s, *r);

                    return;
                }
                case 'S':
                {
                    double *ii = x.dados;
                    int i = *ii;
                    char *str = y.dados;

                    char *r = malloc(sizeof(str) + BUFSIZ);

                    int j;
                    for (j = 0; j < i; j++)
                        r[j] = str[j];
                    r[j] = '\0';

                    push_string(s, r);

                    return;
                }
                default:
                {
                    double a_int = *(double*)x.dados;
                    double b_int = *(double*)y.dados;

                    if (b_int < a_int)
                        push_long(s, 1);
                    else
                        push_long(s, 0);

                    return;
                }
            }
            return;
        }
        default:
        {
            double a_int = *(double*)x.dados;
            double b_int = *(double*)y.dados;

            if (b_int < a_int)
                push_long(s, 1);
            else
                push_long(s, 0);

            return;
        }
    }
}

/**
 * @brief Verifica se o elemento do topo da stack é menor que o elemento abaixo deste, retornando 1 caso seja e 0 caso contrário (True ou False).
 * 
 * @param s Stack.
 */
void is_bigger(STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);

    char cx = type_to_char(x);
    char cy = type_to_char(y);

    switch (cx)
    {
        case 'S':
        {
            char *a = x.dados;
            char *b = y.dados;

            if (strcmp (b, a) > 0)
                push_long(s, 1);
            else
                push_long(s, 0);

            return;
        }
        case 'L':
        {
            switch (cy)
            {
                case 'A':
                {
                    double *ii = x.dados;
                    int i = *ii;
                    STACK *array = y.dados;

                    STACK *r = new_stack();

                    for (int j = array->sp - i + 1; j <= array->sp; j++)
                        push(r, array->stack[j]);

                    push_array(s, *r);

                    return;
                }
                case 'S':
                {
                    double *ii = x.dados;
                    int i = *ii;
                    char *str = y.dados;

                    char *r = malloc(sizeof(str) + BUFSIZ);

                    int j, k, tam = strlen(str);
                    for (j = tam - i, k = 0; j < tam; j++, k++)
                        r[k] = str[j];
                    r[k] = '\0';

                    push_string(s, r);

                    return;
                }
                default:
                {
                    double a_int = *(double*)x.dados;
                    double b_int = *(double*)y.dados;

                    if (b_int > a_int)
                        push_long(s, 1);
                    else
                        push_long(s, 0);

                    return;
                }
            }
            return;
        }
        default:
        {
            double a_int = *(double*)x.dados;
            double b_int = *(double*)y.dados;

            if (b_int > a_int)
                push_long(s, 1);
            else
                push_long(s, 0);

            return;
        }
    }
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
    DADOS a = pop(s);
    DADOS b = pop(s);
    
    if (a.tipo == STRING && b.tipo == STRING)
    {
        int tam_a = 0;
        int tam_b = 0;
        char* str1 = a.dados;
        char* str2 = b.dados;

        for (int i = 0; *(str2+i); ++i)
            tam_b += *(str2+i);
        for (int i = 0; *(str2 + i); ++i)
            tam_a += *(str1 + i);
        
        if (tam_b > tam_a)
            push_string(s, str2);
        else
            push_string(s, str1);
    }
    else 
    {
        double x = *(double*)a.dados;
        double y = *(double*)b.dados;

        if (y > x)
            push(s, b);
        else
            push(s, a);
    }

    free(a.dados);
    free(b.dados);
}

/**
 * @brief Compara os 2 valores do topo da stack, deixando nesta somente o de menor grandeza;
 * 
 * @param s Stack.
 */
void smaller (STACK *s)
{
    DADOS a = pop(s);
    DADOS b = pop(s);
    
    if (a.tipo == STRING && b.tipo == STRING)
    {
        int tam_a = 0;
        int tam_b = 0;
        char* str1 = a.dados;
        char* str2 = b.dados;

        for (int i = 0; *(str2+i); ++i)
            tam_b += *(str2+i);
        for (int i = 0; *(str2 + i); ++i)
            tam_a += *(str1 + i);
        
        if (tam_b < tam_a)
            push_string(s, str2);
        else
            push_string(s, str1);
    }
    else 
    {
        double x = *(double*)a.dados;
        double y = *(double*)b.dados;

        if (y < x)
            push(s, b);
        else
            push(s, a);
    }

    free(a.dados);
    free(b.dados);
}

/**
 * @brief Faz a disjunção lógica de dois elementos do topo da stack, ou seja, se ambos os elementos forem 0 dá push a 0, caso contrário
 * se um dos elementos for 0 dá push ao outro elemento, caso contrário dá push ao 2º elemento.
 * 
 * @param s Stack.
 */
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

/**
 * @brief Realiza a operação if-then-else (se, então, senão), recebendo 3 elementos, onde o primeiro é condicional (0 - Falso, != 0 - Verdadeiro) e
 * os restantes correspondem ás consequências da condição. Por exemplo, um input `$ 1 2 3` daria como output `2`, uma vez que a condição é verdadeira,
 * e `3` caso o valor da condição fosse 0.
 * 
 * @param s Stack.
 */
void if_else (STACK* s)
{
    DADOS else_this = pop(s);
    DADOS then_this = pop(s);
    DADOS if_this = pop(s);
    
    if (if_this.tipo == ARRAY)
    {
        STACK* arr = if_this.dados; 
        if(arr->sp > 1)
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
    else
    {
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
}

