/**
 * @file expArrayString.c
 * @brief Operações com Arrays e Strings.
 * 
 * - __Nota:__ Todas as funções em expArrayString.c incluem uma libertação de memória (ex: `free(x.dados)`) uma vez que acedemos a um elemento da stack com
 * a função `pop()` para o qual foi alocada memória dinâmica que já não será usada.
 */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Separa uma string em substrings de acordo com o caracter '\n' (parágrafo), adicionando cada substring a um array que é
 * posteriormente colocado na stack com a função `push_array()`. Como o tipo ARRAY é definido por uma stack, é utilizada a função `new_stack()`
 * para inicializar o "array".
 * 
 * @param s Stack.
 */
void div_newline(STACK *s)
{
    char *a = pop(s).dados;
    char *token;
    STACK *r = new_stack();
    
    token = strtok(a, "\n");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, "\n");
    }

    push_array(s, *r);

    free(a);
}

/**
 * @brief Quando o input é um inteiro N, cria um ARRAY de inteiros com os elementos no intervalo de 0 até N-1, e coloca-o na stack com a função `push_array()`
 * Caso o input seja um ARRAY, devolve à stack o tamanho do mesmo na forma de inteiro (LONG), utilizando `push_long()`.
 * 
 * @param s Stack.
 */
void range(STACK *s)
{
    DADOS x = pop(s);
    
    if (x.tipo == LONG)
    {
        double *a = x.dados;
        STACK *r = new_stack();

        for (int i=0; i < *a; i++)
            push_long(r, i);

        push_array(s, *r);
    }
    else if (x.tipo == ARRAY)
    {
        STACK *a = x.dados;
        double r = a->sp;

        push_long(s, r);
    }

    free(x.dados);
}

