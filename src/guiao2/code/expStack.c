#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Duplica um elemento na stack.
 * 
 * @param s Stack.
 */
void dup (STACK *s)
{
    DADOS d = pop (s);

    push(s, d);
    push(s, d);

    free(d.dados);
}

/**
 * @brief Roda os primeiros três elementos da stack.
 * 
 * @param s Stack.
 */
void spin (STACK *s)
{
    DADOS x = pop (s);
    DADOS y = pop (s);
    DADOS z = pop (s);

    push(s, y);
    push(s, x);
    push(s, z);
    
    free(x.dados);
    free(y.dados);
    free(z.dados);
}

/**
 * @brief Permite que o utilizador realize um pop.
 * 
 * @param s Stack.
 */
void popS(STACK *s)
{
    pop(s);
}

/**
 * @brief Troca os dois primeiros elementos da stack.
 * 
 * @param s Stack.
 */
void swap(STACK *s) 
{
    DADOS x = pop (s);
    DADOS y = pop (s);

    push(s, x);
    push(s, y);
      
    free(x.dados);
    free(y.dados);
}

/**
 * @brief Copia o n-ésimo elemento da stack para o topo da stack.
 * 
 * @param s Stack.
 */
void ncopy(STACK *s)
{
    DADOS t = pop(s);
    int * ind = (int *) t.dados;
    DADOS y = s->stack[(s->sp) - *ind];
    
    if (y.tipo == LONG)
    {
        int * res = s->stack[(s->sp) - *ind].dados;
        push_long(s, *res);
    }
    else if (y.tipo == CHAR)
    {
        char * res = s->stack[(s->sp) - *ind].dados;
        push_char(s, *res);
    }
    else if (y.tipo == DOUBLE)
    {
        int * res = s->stack[(s->sp) - *ind].dados;
        push_double(s, *res);
    }
    else if (y.tipo == STRING)
    {
        char  * res = s->stack[(s->sp) - *ind].dados;
        push_string(s, res);
    }

    free(t.dados);
}
