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
    char *token = malloc(sizeof(char) * strlen(a));
    STACK *r = new_stack();
    
    token = strtok(a, "\n");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, "\n");
    }
    
    push_array(s, *r);

    free(a);
    free(token);
}

/**
 * @brief Separa uma string em substrings de acordo com o caracter ' ' (espaço), adicionando cada substring a um array que é
 * posteriormente colocado na stack com a função `push_array()`. Como o tipo ARRAY é definido por uma stack, é utilizada a função `new_stack()`
 * para inicializar o "array".
 * 
 * @param s Stack.
 */
void div_whitespace(STACK *s)
{
    char *a = pop(s).dados;
    char *token = malloc(sizeof(char) * strlen(a));
    STACK *r = new_stack();
    
    token = strtok(a, " \n");

    while (token != NULL)
    {
        push_string(r, token);
        token = strtok(NULL, " \n");
    }
    
    push_array(s, *r);

    free(a);
    free(token);
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
    else if (x.tipo == STRING)
    {
        char* str = x.dados;
        int i;
        for (i = 0; *(str + i); ++i);
        push_long(s, i);
    }

    free(x.dados);
}

int substrings(STACK *s, DADOS b, DADOS a)
{
    char* word = b.dados;
    char* sen = a.dados;

    int word_len = strlen(word);
    /* int sen_len = strlen(sen); */

    int f, i , j;
    for (i = 0; *(sen + i); ++i)
    {
        if (*word == *(sen + i))
        {
            for (f = 0, j = i; *(sen + j) && *(word + f); ++f, ++j);

            if (f == word_len)
            {
                push_long(s, i);
                return i;
            }
        }
    }
    push_long(s, -1);
    return -1;
}

void create_string(STACK *s, char* token)
{
    ++token;
    char* str = malloc(sizeof(char) * BUFSIZ);
    int i;

    for (i = 0; *(token + i) != '"'; ++i)
    {
        *(str+i) = *(token+i); 
    }
    *(str+i) = '\0';

    push_string(s, str);
}

void slash_str(STACK* s, DADOS a, DADOS b)
{
    char* pat = a.dados;
    char* str = b.dados;
    
    STACK* arr = new_stack();
        
    int tam = strlen(pat);
    int i, f, j;
    int index = 0;
    char* acc = malloc(sizeof(char) * BUFSIZ);

    for (i = 0; *(str + i); ++i)
    {
        if (*(str + i) == *pat)
        {
            
            for (j = i, f = 0; *(str + j) && *(pat + f); ++j, ++f);

            if (f == tam)
            {
                *(acc + index) = '\0';
                push_string(arr, acc);
                index = 0;
                i += f-1;
            }
            else 
            {
                *(acc + index) = *(str + i);
                ++index;
            }
        }
        else 
        {
            *(acc + index) = *(str + i);
            ++index;
        }
    }
    *(acc + index) = '\0';
    push_string(arr, acc);

    free(acc);
    push_array(s, *arr);
}
