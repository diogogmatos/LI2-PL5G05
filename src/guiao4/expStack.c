/**
 * @file expStack.c
 * @brief Operações de manipulação da stack.
 * 
 * - __Nota:__ Todas as funções em expStack.c incluem uma libertação de memória (`free(d.dados)`) uma vez que acedemos a um elemento da stack com
 * a função `pop()` para o qual foi alocada memória dinâmica que já não será usada.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Duplica um elemento na stack, introduzindo-o na mesma duas vezes com função `push()`.
 * 
 * @param s Stack.
 */
void dup (STACK *s)
{
    DADOS d = pop(s);

    push(s, d);
    push(s, d);
}

/**
 * @brief Roda os primeiros três elementos da stack, introduzindo-os na mesma pela ordem pretendida com função `push()`.
 * 
 * @param s Stack.
 */
void spin (STACK *s)
{
    DADOS x = pop(s);
    DADOS y = pop(s);
    DADOS z = pop(s);

    push(s, y);
    push(s, x);
    push(s, z);
}

/**
 * @brief Troca os dois primeiros elementos da stack, introduzindo-os na mesma por ordem oposta com função `push()`.
 * 
 * @param s Stack.
 */
void swap(STACK *s) 
{
    DADOS x = pop (s);
    DADOS y = pop (s);

    push(s, x);
    push(s, y);
}

/**
 * @brief Copia o n-ésimo elemento da stack para o topo da stack.
 * 
 * Para isso, acede ao n-ésimo elemento da stack e introduz o mesmo novamente com função `push()`.
 * 
 * @param s Stack.
 */
void ncopy(STACK *s)
{
    DADOS t = pop(s);

    double *ii = (double*)t.dados;
    long i = *ii;
    
    DADOS y = s->stack[(s->sp) - i];

    push(s, y);

    free(t.dados);
}
